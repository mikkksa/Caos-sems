#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

int
main(int argc, char *argv[])
{
    int exit_code = 0;
    int in = open(argv[1], O_RDONLY);
    if (-1==in) {
        exit_code = 1;
        goto finally;
    }
    // TODO: move all declarations at the start
    int out_digits = open(argv[2], O_WRONLY | O_CREAT, 0640);
    int out_other = open(argv[3], O_WRONLY | O_CREAT, 0640);
    if (-1==out_digits || -1==out_other) {
        exit_code = 2;
        goto finally;
    }

    ssize_t in_read, out_d_read, out_o_read;
    char in_byte;
    int out;
    while ((in_read=read(in, &in_byte, sizeof(in_byte)))>0) {
        out = '0' <= in_byte && in_byte <= '9'
            ? out_digits
            : out_other;
        if (-1==write(out, &in_byte, sizeof(in_byte))) {
            exit_code = 3;
            goto finally;
        }        
    }
    if (-1==in_read) {
        exit_code = 3;
        goto finally;
    }
 finally:
    close(in);
    close(out_digits);
    close(out_other);
    return exit_code;
}
