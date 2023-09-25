#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void add_node(linked_list_t *list, char *value)
{
  linked_list_node_t node;
  linked_list_node_t *ptr_node = malloc(sizeof(linked_list_node_t));

  ptr_node->ptr_value = value;
  ptr_node->ptr_next = NULL;

  if (list->length == 0)
  {
    list->ptr_head = ptr_node;
    list->ptr_tail = ptr_node;
  }
  else
  {
    linked_list_node_t *ptr_current_tail = list->ptr_tail;
    ptr_current_tail->ptr_next = ptr_node;
    list->ptr_tail = ptr_node;
  }

  list->length += 1;
}

void free_list(linked_list_t *ptr_list)
{
  linked_list_node_t *ptr_current = ptr_list->ptr_head;
  while (ptr_current != NULL)
  {
    linked_list_node_t *ptr_freeable = ptr_current;
    ptr_current = ptr_freeable->ptr_next;

    free(ptr_freeable);
  }

  free(ptr_list);
}