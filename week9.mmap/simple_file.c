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
    char *file_name = argv[1];
    int fd = open(file_name, O_RDWR);
    struct stat st;
    fstat(fd, &st);
    if (0==st.st_size) {
        close(fd);
        exit(0);
    }
    lseek(fd, 4, SEEK_SET);
    write(fd, "", 1);
    char *contents = mmap(NULL,
                          st.st_size,
                          PROT_READ | PROT_WRITE,
                          MAP_PRIVATE,
                          fd,
                          0);
    char *str = "preceq";
    memcpy(contents, str, 5);
    msync(contents, 5, MS_SYNC);
    munmap(contents, st.st_size);
    close(fd);
}
