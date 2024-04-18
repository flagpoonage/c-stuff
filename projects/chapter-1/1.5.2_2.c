#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
  double nc;

  for (nc = 0; getchar() != EOF; ++nc)
  {
    ;
  }

  printf("%.0f\n", nc);
}
