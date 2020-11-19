#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *file_name = argv[1], *contents;
    int fd = open(file_name, O_RDWR | O_CREAT, 0666);
    struct stat st;
    const char *text = "hello\n";
    size_t size = strlen(text);

    lseek(fd, size, SEEK_SET);
    write(fd, "\n", 1);
    contents = mmap(NULL,
                          size,
                          PROT_READ | PROT_WRITE,
                          MAP_PRIVATE,
                          fd,
                          0);
    memcpy(contents, text, size);
    msync(contents, size, MS_SYNC);
    munmap(contents, size);
    close(fd);
}
