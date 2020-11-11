int main() {
    void *mem = malloc(4);
    printf("%p\n", mem);
    mem = realloc(mem, 8);
    printf("%p\n", mem);
    free(mem);
    return 0;
}
