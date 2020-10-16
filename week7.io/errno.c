#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int a = open("not_found.txt", O_WRONLY);
    if (a == -1) {
        printf("%d %d\n", a, errno);
    }
    return 0;
}
