#include <stdio.h>

#define SIZE 5

int main() {
  // Remember that array is just a pointer, but access to memory is
  // devided in blocks
  int a[] = {1, 2, 3};

  // array size must be const value
  int b[SIZE];
  int i;

  b[2] = 5;

  for (i = 0; i < SIZE; i++) {
    // Be carefull - len(a) = 3 and all b's values are empty except one
    printf("%d %d\n", a[i], b[i]);
  }
  return 0;
}
