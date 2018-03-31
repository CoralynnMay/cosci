#include "tokenize.h"
#include "linked_list.h"
#include "string_buffer.h"

linkedList* tokenize_string(char* str) {
  linkedList* list = linkedList_new();
  stringBuffer* buffer = stringBuffer_new(20);
  char c;

  while((c = *str++)) {
    switch(c) {
      case '(':
      case ')':
        if(!stringBuffer_empty(buffer)) linkedList_add(list, stringBuffer_get_finished_string(buffer));
        stringBuffer_flush(buffer);
        stringBuffer_add_char(buffer, c);
      case ' ':
        if(!stringBuffer_empty(buffer)) linkedList_add(list, stringBuffer_get_finished_string(buffer));
        stringBuffer_flush(buffer);
        break;
      default:
        stringBuffer_add_char(buffer, c);
    }
  }
  if(!stringBuffer_empty(buffer)) linkedList_add(list, stringBuffer_get_finished_string(buffer));

  return list;
}
