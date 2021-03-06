#include "linked_list.h"
#include <stdlib.h>

linkedList* linkedList_new() {
  return calloc(1, sizeof(linkedList));
}

void linkedList_free(linkedList* list) {
  linkedList* intermediate = NULL;

  for(;list != NULL; list = intermediate) {
    intermediate = list->next;
    free(list);
  }
}

void linkedList_add(linkedList* list, void* item) {
  linkedList* iter = NULL;

  for(iter = list; iter != NULL; iter = iter->next) {
    if(iter->item == NULL) {
      iter->item = item;
      break;
    } else if(iter->next == NULL) {
      iter->next = linkedList_new();
    }
  }
}

linkedList* linkedList_by_index(linkedList* list, size_t index) {
  linkedList* iter = NULL;
  size_t i;

  for(iter = list, i = 0; i < index && iter != NULL; i++, iter = iter->next) {}

  return iter;
}
