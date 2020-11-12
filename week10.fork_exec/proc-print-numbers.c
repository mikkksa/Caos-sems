#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    uint32_t N = strtoul(argv[1], NULL, 10);
    uint32_t i;
    for (i=1; i<=N; ++i) {
        if (i > 1) {
            putchar(' ');
        }
        printf("%d", i);
        fflush(stdout);
        if (i < N) {
            pid_t pid = fork();
            if (pid > 0) {
                waitpid(pid, NULL, 0);
                break;
            }
        }
    }
    if (1==i || 1==N) {
        putchar('\n');
    }
}

