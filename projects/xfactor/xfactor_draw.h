
#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>

typedef struct Fnt
{
  Display *dpy;
  XftFont *xfont;
  unsigned int h;
} Fnt;

typedef XftColor Clr;

typedef struct
{
  unsigned int w, h;
  Display *dpy;
  int screen;
  Window root;
  Fnt *font;
} Drw;

Fnt *create_font(Drw *drw, char *fontname);