#include <stdio.h>

int check(char *buf) {
    if (buf == NULL) {
        return 0;
    }
    if (buf[0] == 'd') {
        return 1;
    }
    return 0;
}

int main()
{
    char buf[24];
    fgets(buf, sizeof(buf)-1, stdin);
    if (check(buf)) {
        printf("OK\n");
        return 0;
    } else {
        printf("NOT OK\n");
        return 1;
    }
}
