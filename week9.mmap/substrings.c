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
    char *pattern = argv[2];
    int fd = open(file_name, O_RDONLY);
    struct stat st;
    fstat(fd, &st);
    if (0==st.st_size) {
        close(fd);
        exit(0);
    }
    char *contents = mmap(NULL,
                          st.st_size,
                          PROT_READ,
                          MAP_PRIVATE,
                          fd,
                          0);
    char *entry = contents;    
    while (NULL!=(entry=strstr(entry, pattern))) {
        size_t diff = entry - contents;
        printf("%lu ", diff);
        entry++;
    }
    printf("\n");
    munmap(contents, st.st_size);
    close(fd);
}
