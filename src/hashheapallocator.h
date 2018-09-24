#ifndef HASHHEAPALLOCATOR_HH
#define HASHHEAPALLOCATOR_HH

#include <stdlib.h>
#include <stdio.h>

class HeapAllocator {
public:
  static void* allocate(size_t sz) {
    void* ptr = malloc(sz);
    if(!ptr) {
      return NULL;
    }
    return ptr;
  }

  static void deallocate(void* ptr) {
    free(ptr);
    ptr = NULL;
  }
};
#endif
