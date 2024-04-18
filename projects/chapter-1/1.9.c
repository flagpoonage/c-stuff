#include <stdio.h>

#define MAXLINE 1000

/**
 *
 * INCOMPATIBILITY WITH BOOK
 *
 * Calling the function `getline` as specified in the book seems
 * to conflict with a `getline` function defined in the stdio header
 * file. Not sure if this is just my setup or the book being outdated.
 */

int custom_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;

  while ((len = custom_getline(line, MAXLINE)) > 0)
  {
    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0)
  {
    printf("%s", longest);
  }

  return 0;
}

int custom_getline(char line[], int maxlength)
{
  int c, i;

  for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
  {
    i++;
  }
}