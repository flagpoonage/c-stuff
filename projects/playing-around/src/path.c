#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int is_absolutepath(char *path)
{
  if (path == NULL)
  {
    return 0;
  }

  return path[0] == '/' ? 1 : 0;
}

int is_relativepath(char *path)
{
  if (path == NULL)
  {
    return 0;
  }

  return path[0] == '.' ? 1 : 0;
}

char *resolve(char *dest_buffer, char *path)
{
  if (is_absolutepath(path))
  {
    return path;
  }

  // char *dest_buffer;
  dest_buffer = getcwd(dest_buffer, 4096);

  if (dest_buffer == NULL)
  {
    perror("Unable to get cwd()\n");
    return path;
  }

  if (is_relativepath(path))
  {
    dest_buffer = strcat(strcat(dest_buffer, "/"), path + 2);
  }

  return dest_buffer;
}