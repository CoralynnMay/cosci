#include "tinytest.h"
#include "hash_map.h"

void test_set_get() {
  char* given_key = "key";
  int given_value = 10;

  hashMap* map = NULL;
  map = hashMap_new(10);

  hashMap_set(map, given_key, &given_value);

  ASSERT_EQUALS(10, *((int*)hashMap_get(map, "key")));

  hashMap_free(map);
}

void test_add_key_list() {
  const char* given_keys[3] = {"foo", "bar", "baz"};

  hashMap* map = NULL;
  map = hashMap_new(10);

  hashMap_add_key_list(map, 3, given_keys[0], given_keys[1], given_keys[2]);

  ASSERT_EQUALS(1, *((int*)hashMap_get(map, "foo")));
  ASSERT_EQUALS(1, *((int*)hashMap_get(map, "bar")));
  ASSERT_EQUALS(1, *((int*)hashMap_get(map, "baz")));

  hashMap_free(map);
}

int main() {
  RUN(test_set_get);
  RUN(test_add_key_list);
  return TEST_REPORT();
}
