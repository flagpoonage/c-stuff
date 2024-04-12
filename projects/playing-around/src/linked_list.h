typedef struct linked_list_node_t linked_list_node_t;

typedef struct linked_list_node_t
{
  char *ptr_value;
  linked_list_node_t *ptr_next;
} linked_list_node_t;

typedef struct
{
  linked_list_node_t *ptr_head;
  linked_list_node_t *ptr_tail;
  int length;
} linked_list_t;

void add_node(linked_list_t *list, char *value);
void free_list(linked_list_t *list);