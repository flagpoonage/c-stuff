#include "sb.h"

typedef struct FileReader
{
  char *contents;
  int length;
} FileReader;

FileReader fr_initfile(char *filename);
void fr_readfile(char *filename, FileReader *reader);
void fr_free(FileReader *reader);