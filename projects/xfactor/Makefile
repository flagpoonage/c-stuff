all: xfactor

xfactor: 
	cc -c -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os -I/usr/X11R6/include -I/usr/include/freetype2 xfactor.c 
	cc -c -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os -I/usr/X11R6/include -I/usr/include/freetype2 xfactor_draw.c 
	cc -c -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os -I/usr/X11R6/include -I/usr/include/freetype2 utils.c
	cc -o xfactor xfactor.o xfactor_draw.o utils.o -L/usr/X11R6/lib -lX11 -lfontconfig -lXft

clean:
	rm -f xfactor *.o

.PHONY: all xfactor clean