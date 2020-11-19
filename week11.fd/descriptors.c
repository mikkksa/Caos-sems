#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main() {
    int fd = open("hello.txt", O_RDWR);
    pid_t f = fork();
    char buf[255];

    if (!f) {
        write(fd, "hello\n", 6);
        close(fd);
        return 0;
    }
    wait(NULL);
   
    lseek(fd, 0, SEEK_SET); 
    printf("%d\n", read(fd, buf, 6));
    printf(buf);

    close(fd);
    return 0;
}
