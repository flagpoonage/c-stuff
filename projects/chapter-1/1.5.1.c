#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
  int c;

  c = getchar();
  while (c != EOF)
  {
    putchar(c);
    c = getchar();
  }
}
