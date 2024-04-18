#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void *
xalloc(size_t member_count, size_t size)
{
  void *p;

  if (!(p = malloc(member_count * size)))
  {
    printf("Failed to allocate memory");
    exit(1);
  }

  return p;
}
