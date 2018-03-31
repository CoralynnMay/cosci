#include "tinytest.h"
#include "tokenize.h"
#include "linked_list.h"

void test_simple_string() {
  char* given = "foo bar baz";

  linkedList* iter = NULL;
  linkedList* result = tokenize_string(given);

  ASSERT_STRING_EQUALS("foo", linkedList_by_index(result,0)->item);
  ASSERT_STRING_EQUALS("bar", linkedList_by_index(result,1)->item);
  ASSERT_STRING_EQUALS("baz", linkedList_by_index(result,2)->item);

  for(iter = result; iter != NULL; iter = iter->next) {
    free(iter->item);
  }

  linkedList_free(result);
}

void test_lisp_string() {
  char* given = "(foo)";

  linkedList* iter = NULL;
  linkedList* result = tokenize_string(given);

  ASSERT_STRING_EQUALS("(", linkedList_by_index(result,0)->item);
  ASSERT_STRING_EQUALS("foo", linkedList_by_index(result,1)->item);
  ASSERT_STRING_EQUALS(")", linkedList_by_index(result,2)->item);

  for(iter = result; iter != NULL; iter = iter->next) {
    free(iter->item);
  }

  linkedList_free(result);
}

int main() {
  RUN(test_simple_string);
  RUN(test_lisp_string);
  return TEST_REPORT();
}
