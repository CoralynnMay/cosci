#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct linked_list linkedList;

struct linked_list {
  void* item;
  linkedList* next;
};

linkedList* linkedList_new();
void linkedList_free(linkedList*);
void linkedList_add(linkedList*, void*);
linkedList* linkedList_by_index(linkedList*, size_t);

#endif /* end of include guard: LINKED_LIST_H */
