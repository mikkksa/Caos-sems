#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t f = fork();

    if (f == 0) {
        printf("Hello, I'm child\n");
        fflush(stdout);
    }
    if (f > 0) {
        printf("Hello, I'm parent\n");
        fflush(stdout);
        while(waitpid(f, NULL, WNOHANG) < 0) {
            usleep(100);
        }
    }
    if (f < 0) {
        return -1;
    }
}
