#include "string_buffer.h"
#include <config.h>
#include <stdlib.h>
#include <string.h>

struct string_buffer {
  size_t size;
  size_t fill;
  char* buffer;
};

void resize(stringBuffer*, size_t);

stringBuffer* stringBuffer_new(size_t size) {
  stringBuffer* new_buffer = NULL;

  new_buffer = calloc(1, sizeof(stringBuffer));
  new_buffer->size = size;
  new_buffer->fill = 0;
  new_buffer->buffer = calloc(size, sizeof(char));

  return new_buffer;
}

void stringBuffer_free(stringBuffer* buffer) {
  free(buffer->buffer);
  free(buffer);
}

void resize(stringBuffer* buffer, size_t size) {
  size_t i;

  buffer->size = size;
  if(buffer->fill > buffer-> size) buffer->fill = size - 1;
  buffer->buffer = realloc(buffer->buffer, (size * sizeof(char)));

  for(i = buffer->fill; i < buffer->size; i++) {
    buffer->buffer[i] = '\0';
  }
}

void stringBuffer_add_char(stringBuffer* buffer, char c) {
  if(buffer->fill > (buffer->size * 0.7)) resize(buffer, (buffer->size * 1.5));
  buffer->buffer[buffer->fill] = c;
  buffer->fill++;
}

void stringBuffer_add_string(stringBuffer* buffer, char* str) {
  char c;
  while((c = *str++)) {
    stringBuffer_add_char(buffer, c);
  }
}

char* stringBuffer_get_finished_string(stringBuffer* buffer) {
  char* str = NULL;
  str = calloc((buffer->fill + 1), sizeof(char));
  strcpy(str, buffer->buffer);
  return str;
}

void stringBuffer_flush(stringBuffer* buffer) {
  size_t i;

  for(i = 0; i < buffer->size; i++) {
    buffer->buffer[i] = '\0';
  }

  buffer->fill = 0;
}

int stringBuffer_empty(stringBuffer* buffer) {
  return !(buffer->fill > 0);
}
