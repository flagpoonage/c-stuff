#include <stdio.h>

/**
 *  Can be just main without return type, but throws a warning:
 * hello-world.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
    3 | main()
      | ^~~~
*/
int main()
{
  printf("hello, world\n");
}