#include "tinytest.h"
#include "linked_list.h"

void test_add() {
  char* given1 = "string";
  int given2 = 42;

  linkedList* list = NULL;
  list = linkedList_new();

  linkedList_add(list, given1);
  linkedList_add(list, &given2);

  ASSERT_STRING_EQUALS("string", (char*)list->item);
  ASSERT_EQUALS(42, *((int*)list->next->item));

  linkedList_free(list);
}

int main() {
  RUN(test_add);
  return TEST_REPORT();
}
