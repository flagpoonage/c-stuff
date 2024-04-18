#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char *ansi_reset = "\033[0m";
static const char *ansi_rgb_start = "\033[38;2;";

typedef struct Rgb
{
  int blue;
  int red;
  int green;
} Rgb;

typedef struct AnsiString
{
  char *val;
} AnsiString;

Rgb make_rgb(int r, int g, int b);
AnsiString make_ansi_string(char *text, Rgb *color);

char *make_ansi_color(Rgb *color);
char *color_string(char *text, Rgb *color);

Rgb make_rgb(int r, int g, int b)
{
  Rgb x;
  x.red = r;
  x.green = g;
  x.blue = b;
  return x;
}

AnsiString make_ansi_string(char *text, Rgb *color)
{
  // 3 digits, 3 possible characters, seperated by semicolns
  int digits_max_size = (3 * 3) + 2;

  int expected_buffer_length =
      strlen(ansi_rgb_start) +
      1 + // Final 'm' character
      digits_max_size +
      strlen(text) +
      strlen(ansi_reset) + 1; // String terminator \0

  char *buffer[expected_buffer_length];

  AnsiString ansi;
  ansi.val = &buffer;

  // char *buffer = malloc(expected_buffer_length);

  sprintf(ansi.val, "%s%d;%d;%dm",
          ansi_rgb_start,
          color->red,
          color->green,
          color->blue,
          text,
          ansi_reset);

  return ansi;
}

char *make_ansi_color(Rgb *color)
{
  // 3 digits, 3 possible characters, seperated by semicolns
  int digits_max_size = (3 * 3) + 2;

  int expected_buffer_length =
      strlen(ansi_rgb_start) +
      digits_max_size +
      1 + // Final 'm' character
      1;  // String terminator \0

  char *buffer = malloc(expected_buffer_length);

  sprintf(buffer, "%s%d;%d;%dm",
          ansi_rgb_start,
          color->red,
          color->green,
          color->blue);

  return buffer;
}

char *color_string(char *text, Rgb *color)
{
  char *ansi_color = make_ansi_color(color);

  int buffer_length = strlen(ansi_color) + strlen(text) +
                      strlen(ansi_reset) + 1;

  char *bf = malloc(buffer_length);

  sprintf(bf, "%s%s%s", ansi_color, text, ansi_reset);

  free(ansi_color);

  return bf;
}

int main()
{

  Rgb reddish = make_rgb(255, 122, 122);
  Rgb yellow = make_rgb(255, 255, 0);
  Rgb green = make_rgb(0, 255, 0);

  AnsiString rr = make_ansi_string("western", &reddish);

  char *r = color_string("hello", &reddish);
  char *g = color_string("hello", &green);
  char *y = color_string("hello", &yellow);

  printf("The string is:\n%s\n%s\n%s\n", rr.val, y, g);

  free(r);
  free(g);
  free(y);

  return 0;
}