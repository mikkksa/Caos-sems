#include <stdlib.h>
#include <stdio.h>

struct S {
  int a;
  char b;
};

typedef long long int my_type;

int main() {
  int a, bin;
  my_type mt;
  struct S s = {1, 49};
  int *heap_allocated = (int *) malloc(sizeof(int));

  //printf("%d\n \t", p);
  //scanf("%d", &a);
  //printf("%d\n", a);

  if (heap_allocated == NULL) {
    goto exit;
  }

  *heap_allocated = 3;
  printf("Heap allocated value: %d\n", *heap_allocated); // value
  printf("Heap allocate memory: %p\n\n", heap_allocated); // pointer

  mt = 10;
  printf("My type value: %lld\n", mt); // value
  printf("My type pointer (on stack): %p\n\n", &mt); // pointer

  bin = (0b1001) << 5;
  printf("Binary presentation value: %d\n", bin); // value
  printf("Binary presentation value (on stack): %p\n", &bin); // pointer

  printf("Structure data: a: %d, b: %c\n", s.a, s.b);

exit:
  free(heap_allocated); // free heap memory

  return 0;
}
