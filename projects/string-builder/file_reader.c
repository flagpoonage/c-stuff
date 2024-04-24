#include <stdio.h>
#include "file_reader.h"

static int readfile_tosb(char *filename, StringBuilder *sb)
{

  char c;
  char bytes[128];
  FILE *file;

  // Clean any data
  sb_clear(sb);

  file = fopen(filename, "r");

  if (file == NULL)
  {
    return -1;
  }

  while ((c = fgetc(file)) != EOF)
  {
    sb_push(sb, c);
  }

  if (fclose(file) == EOF)
  {
    printf("Failed to close file");
    return -1;
  }

  return 0;
}

FileReader fr_initfile(char *filename)
{
  FileReader fr;
  fr_readfile(filename, &fr);
  return fr;
}

void fr_readfile(char *filename, FileReader *reader)
{
  StringBuilder sb;

  sb_init(&sb, 1024, BUFFER_EXPAND_DOUBLE);
  readfile_tosb(filename, &sb);

  printf("The output is\n\n%s", sb.data);

  reader->contents = sb.data;
  reader->length = strlen(reader->contents);
}

void fr_free(FileReader *reader)
{
  free(reader->contents);
}
