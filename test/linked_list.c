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

void test_by_index() {
  char* given1 = "string";
  int given2 = 42;

  linkedList* list = NULL;
  list = linkedList_new();

  linkedList_add(list, given1);
  linkedList_add(list, &given2);

  ASSERT_STRING_EQUALS("string", (char*)linkedList_by_index(list, 0)->item);
  ASSERT_EQUALS(42, *((int*)linkedList_by_index(list, 1)->item));
  ASSERT_EQUALS(NULL, linkedList_by_index(list, 2));

  linkedList_free(list);
}

int main() {
  RUN(test_add);
  RUN(test_by_index);
  return TEST_REPORT();
}
