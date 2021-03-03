#include <stdio.h>

int f(int *p) {
  printf("%d\n", *p);
}

int main() {
  // In this way we can declare a function anywhere, because its signature is
  // ret_type (*name)(arg_types...)
  int (*g)(int*) = f;
  int a;
  g(&a);
}
