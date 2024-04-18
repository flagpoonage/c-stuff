#include <unistd.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>

#include "xfactor_draw.h"
#include "utils.h"

/**
 * SHORTHAND
 * init = initialize
 * prog = program
 * win = window
 *
 */

static Display *display;
static Fnt *font;
static Window root_window, prog_window;

static int screen;

#define FREEFONT(fnt)                   \
  XftFontClose(font->dpy, font->xfont); \
  free(font);

static void cleanup()
{
  FREEFONT(font);
  XCloseDisplay(display);
}

/**
 * initialize_program_window
 */
static void
init_prog_win(const XWindowAttributes *root_attriubtes)
{
  XSetWindowAttributes win_attributes;
  XftColor *clr = xalloc(1, sizeof(XftColor));

  if (!XftColorAllocName(
          display,
          DefaultVisual(display, screen),
          DefaultColormap(display, screen),
          "#ffffff",
          clr))
  {
    printf("Failed to create colour");
    exit(1);
  }

  // if (!drw || !dest || !clrname)
  //   return;

  // if (!XftColorAllocName(drw->dpy, DefaultVisual(drw->dpy, drw->screen),
  //                        DefaultColormap(drw->dpy, drw->screen),
  //                        clrname, dest))
  //   die("error, cannot allocate color '%s'", clrname);

  win_attributes.background_pixel = clr->pixel;
  win_attributes.event_mask = KeyPressMask;
  // win_attributes.override_redirect = True;

  prog_window = XCreateWindow(
      display, root_window,
      0, 0, 50, root_attriubtes->width, 0,
      CopyFromParent, CopyFromParent, CopyFromParent,
      CWOverrideRedirect | CWBackPixel | CWEventMask,
      &win_attributes);

  XMapRaised(display, prog_window);

  free(clr);
}

static void
run(void)
{
  XEvent ev;

  while (!XNextEvent(display, &ev))
  {
    if (XFilterEvent(&ev, prog_window))
      continue;
    switch (ev.type)
    {
    case DestroyNotify:
      if (ev.xdestroywindow.window != prog_window)
        break;
      cleanup();
      exit(1);
    // case Expose:
    //   if (ev.xexpose.count == 0)
    //     drw_map(drw, win, 0, 0, mw, mh);
    //   break;
    // case FocusIn:
    //   /* regrab focus from parent window */
    //   if (ev.xfocus.window != root_window)
    //     grabfocus();
    //   break;
    case KeyPress:
      cleanup();
      exit(0);
      // keypress(&ev.xkey);
      break;
    // case SelectionNotify:
    //   if (ev.xselection.property == utf8)
    //     paste();
    //   break;
    case VisibilityNotify:
      if (ev.xvisibility.state != VisibilityUnobscured)
        XRaiseWindow(display, prog_window);
      break;
    }
  }
}

/**
 * initialize_keyboard
 */
// static void
// init_kb()
// {
// }

int main()
{
  if (!(display = XOpenDisplay(NULL)))
  {
    printf("Failed to open display with XOpenDisplay");
    return 1;
  }

  screen = DefaultScreen(display);
  root_window = RootWindow(display, screen);

  XWindowAttributes attributes;

  if (!XGetWindowAttributes(display, root_window, &attributes))
  {
    printf("Failed to get window attributes with XGetWindowAttributes");
    return 1;
  }

  Drw drw;

  drw.dpy = display;
  drw.screen = screen;
  drw.root = root_window;
  drw.w = attributes.width;
  drw.h = attributes.height;

  if (!(font = create_font(&drw, "\"JetBrains Mono\":size=15")))
  {
    printf("Failed to create font");
    return 1;
  }

  printf("Resolution: %d x %d, font height: %d",
         attributes.width,
         attributes.height,
         font->xfont->height);

  init_prog_win(&attributes);
  run();

  cleanup();
  return 0;
}