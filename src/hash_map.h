#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct hash_map hashMap;
hashMap* hashMap_new(size_t);
size_t hashMap_free(hashMap*);
void hashMap_set(hashMap*, char*, void*);
void* hashMap_get(hashMap*, char*);
void hashMap_add_key_list(hashMap*, size_t, ...); /* take a list of keys and set the values equal to 1 */

#endif /* end of include guard: HASH_MAP_H */
