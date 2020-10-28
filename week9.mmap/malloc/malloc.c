#define _GNU_SOURCE         /* See feature_test_macros(7) */

#include <stdio.h>
#include <sys/mman.h>
#include <stddef.h>
#include <unistd.h>

void *mremap(void *old_address, size_t old_size,
                    size_t new_size, int flags, ... /* void *new_address */);

void *malloc(size_t size) {
    void *mem = mmap(NULL, size + sizeof(size_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS |
                    MAP_PRIVATE, -1, 0);
    *((size_t*)(mem)) = size;

    return (void*)(((size_t*)mem)+sizeof(size_t));
}

void free(void *ptr) {
    size_t *size_ptr = ((size_t*)ptr)-sizeof(size_t);

    munmap((void*)size_ptr, *size_ptr+sizeof(size_t));
}

void *realloc(void *ptr, size_t size) {
    size_t *size_ptr = ((size_t*)ptr)-sizeof(size_t);
    size_t old_size = *size_ptr;
    void *new_ptr = mremap((void*)size_ptr, old_size+sizeof(size_t),
                    size+sizeof(size_t), MREMAP_MAYMOVE, NULL);

    *((size_t *)new_ptr) = size;
    return (void*)((size_t *)new_ptr+sizeof(size_t));
}


int main() {
    void *mem = malloc(1024);
    printf("%p\n", mem);
    free(mem);
}
