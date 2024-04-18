#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
  int c, n1;

  n1 = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      ++n1;
    }
  }

  printf("%d\n", n1);
}
