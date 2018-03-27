#include "hash_map.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

struct hash_map {
  size_t size;
  size_t fill;
  char** keys;
  void** values;
};

void hashMap_resize(hashMap*, size_t);
char** hashMap_keys(hashMap*);
size_t hashMap_key_index(hashMap*, char*);
size_t hashMap_hash_string(char*);

hashMap* hashMap_new(size_t size) {
  hashMap* new_map = NULL;

  //prevents some weird issue
  if(size < 10) size = 10;

  new_map = (hashMap*) calloc(1, sizeof(hashMap));
  new_map->size = size;
  new_map->fill = 0;
  new_map->keys = (char**) calloc(size, sizeof(char*));
  new_map->values = (void**) calloc(size, sizeof(void*));

  return new_map;
}

size_t hashMap_free(hashMap* map) {
  size_t i;

  for (i = 0; i < map->size; i++) {
    if(map->keys[i] != NULL) free(map->keys[i]);
    //if(map->values[i] != NULL) free(map->values[i]);
  }

  free(map->keys);
  free(map->values);

  free(map);

  return 0;
}

void hashMap_resize(hashMap* map, size_t size) {
  char** keys = NULL;
  hashMap* new_map = NULL;
  size_t i;

  keys = hashMap_keys(map);
  new_map = hashMap_new(size);

  for(i = 0; keys[i] != 0; i++) {

    hashMap_set(new_map, keys[i], hashMap_get(map, keys[i]));
  }

  free(map->keys);
  free(map->values);

  map->size = new_map->size;
  map->keys = new_map->keys;
  map->values = new_map->values;

  free(new_map);
}

char** hashMap_keys(hashMap* map) {
  char** keys = NULL;
  size_t count = 0;
  size_t i;

  keys = calloc(map->size + 1, sizeof(char));

  for(i = 0; i < map->size; i++) {
    if(map->keys[i] != NULL) {
      keys[count] = calloc(1, strlen(map->keys[i]) + 1);
      strcpy(keys[count], map->keys[i]);
      count += 1;
    }
  }
  return keys;
}

size_t hashMap_hash_string(char* str) {
  size_t hash = 5381;
  size_t c;

  while((c = *str++)) hash = ((hash << 5) + hash) + c;

  return hash;
}

size_t hashMap_key_index(hashMap* map, char* key) {
  size_t index;
  size_t key_length;

  index = (hashMap_hash_string(key) % map->size);
  key_length = strlen(key);

  while (index < map->size &&
    map->keys[index] != NULL &&
    strcmp(map->keys[index], key) != 0)
    {
    index++;
  }

  if(index >= map->size) return -1;

  if(map->keys[index] == NULL) {
    map->keys[index] = calloc(key_length + 1, sizeof(char));
    strcpy(map->keys[index], key);
    map->fill += 1;
  }

  return index;
}

void hashMap_set(hashMap* map, char* key, void* value) {
  size_t index;

  index = hashMap_key_index(map, key);

  map->values[index] = value;

  if ((map->fill) > (map->size * 0.7)) hashMap_resize(map, (map->size * 1.5));
}

void* hashMap_get(hashMap* map, char* key) {
  return map->values[hashMap_key_index(map, key)];
}

void hashMap_add_key_list(hashMap* map, size_t count, ...) {
  va_list ap;
  size_t i;
  int* setVal;

  setVal = calloc(1, sizeof(size_t));
  *setVal = 1;

  va_start(ap, count);
  for(i = 0; i < count; i++) {
    hashMap_set(map, va_arg(ap, char*), setVal);
  }
  va_end(ap);
}
