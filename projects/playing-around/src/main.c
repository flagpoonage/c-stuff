#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "path.h"

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Expected file path argument but received none");
    return 1;
  }

  char *arg_file_path = argv[1];

  printf("Read file path: %s\n", arg_file_path);

  char *resolved_file_path;
  resolved_file_path = resolve(resolved_file_path, arg_file_path);

  printf("Resolved path: %s\n", resolved_file_path);

  FILE *ptr_file = fopen(resolved_file_path, "r");

  if (ptr_file == NULL)
  {
    perror("Error opening file");
    return 1; // Return an error code
  }

  // fread()

  printf("File is opened!");

  fclose(ptr_file);

  printf("File is closed!");

  return 0;

  return 0;
}

// int main(int argc, char **argv)
// {
//   FILE *ptr_file = fopen("/home/james/test.txt", "r");

//   if (argc > 0)
//   {
//     char ptr_cwd[4096];
//     getcwd(ptr_cwd, sizeof(ptr_cwd));

//     char *first_arg = argv[0];

//     printf("Arg is %s, path is %s\n", first_arg, ptr_cwd);
//   }

//   if (ptr_file == NULL)
//   {
//     perror("Error opening file");
//     return 1; // Return an error code
//   }

//   printf("File is opened!");

//   fclose(ptr_file);

//   printf("File is closed!");

//   return 0;
// }

// #include "linked_list.h"
// int main()
// {
//   linked_list_t ll;
//   linked_list_t *ptr_ll = malloc(sizeof(linked_list_t));

//   add_node(ptr_ll, "Something");
//   add_node(ptr_ll, "Something else");
//   add_node(ptr_ll, "Another one");

//   free_list(ptr_ll);
// }