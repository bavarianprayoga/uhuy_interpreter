#ifndef uhuy_memory_h
#define uhuy_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \ 
    ((capacity)) < 8 ? 8 : (capacity) * 2
// '\' buat bikin macro baca next line sebagai lanjutan dari line dia

#define GROW_ARRAY(type, pointer, oldCount, newCount) \ 
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

void *reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif