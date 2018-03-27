#include "tinytest.h"
#include "string_buffer.h"

void test_add_char() {
  char given = 'h';

  stringBuffer* buffer;
  buffer = stringBuffer_new(10);
  stringBuffer_add_char(buffer, given);

  ASSERT_EQUALS('h', *stringBuffer_get_finished_string(buffer));

  stringBuffer_free(buffer);
}

void test_add_string() {
  char* given = "string";

  stringBuffer* buffer;
  buffer = stringBuffer_new(10);
  stringBuffer_add_string(buffer, given);

  ASSERT_STRING_EQUALS("string", stringBuffer_get_finished_string(buffer));

  stringBuffer_free(buffer);
}

int main() {
  RUN(test_add_char);
  RUN(test_add_string);
  return TEST_REPORT();
}
