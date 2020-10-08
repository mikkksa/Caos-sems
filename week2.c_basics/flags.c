#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define NO_WRITE (O_WRONLY ^ 0b11111111)

int main() {
  int fd = open("flags.c", NO_WRITE & O_RDONLY);
  
  printf("Opened file descriptor: %d\n", fd);

  close(fd);
  return 0;
}
