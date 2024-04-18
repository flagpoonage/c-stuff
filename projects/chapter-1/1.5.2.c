#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF)
  {
    ++nc;
  }

  printf("%1d\n", nc);
}
