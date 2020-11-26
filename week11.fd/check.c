       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
        close(stdout);
}
