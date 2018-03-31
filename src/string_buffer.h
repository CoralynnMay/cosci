#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H

#include <stdlib.h>

typedef struct string_buffer stringBuffer;
stringBuffer* stringBuffer_new(size_t);
void stringBuffer_free(stringBuffer*);
void stringBuffer_add_char(stringBuffer*, char);
void stringBuffer_add_string(stringBuffer*, char*);
char* stringBuffer_get_finished_string(stringBuffer*);
void stringBuffer_flush(stringBuffer*);
int stringBuffer_empty(stringBuffer*);

#endif /* end of include guard: STRING_BUFFER_H */
