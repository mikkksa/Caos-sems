struct Item {
  int value;
  uint32_t next_pointer;
};

int main() {
    int fd = open(file);
    uint32_t last_np = -1;
    while (last_np != 0) {
        Item item;
        read(fd, &item, sizeof(item));
        // TODO: make offset
    }
}
