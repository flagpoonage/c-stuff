/**
 * This file is trimmed down version of drw.c from
 * suckless tools -> dmenu
 * https://git.suckless.org/dmenu/file/drw.c.html
 */

#include "xfactor_draw.h"
#include "utils.h"

Fnt *create_font(Drw *drw, char *fontname)
{
  if (!drw || !fontname)
  {
    return NULL;
  }

  Fnt *font;
  XftFont *xfont;

  if (!(xfont = XftFontOpenName(drw->dpy, drw->screen, fontname)))
  {
    fprintf(stderr, "error, cannot load font from name: '%s'\n", fontname);
    return NULL;
  }

  font = xalloc(1, sizeof(Fnt));
  font->xfont = xfont;
  font->h = xfont->ascent + xfont->descent;
  font->dpy = drw->dpy;

  return (drw->font = font);
}
