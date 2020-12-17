struct Base {
  int type;
  void *internal;
};

struct Something {
  int data;
};

int main() {
  struct Something something = {.data = 13};
  struct Base base = {.type = 0, .internal = &something};
  printf("%d\n", ((struct Something *)(base.internal))->data);
  return 0;
}
