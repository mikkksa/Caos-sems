#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    in_addr_t addr = inet_addr(argv[1]);
    in_port_t port = htons(strtol(argv[2], NULL, 10));

    struct sockaddr_in full_addr;
    full_addr.sin_family = AF_INET;
    full_addr.sin_addr.s_addr = addr;
    full_addr.sin_port = port;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (0!=connect(sock, (struct sockaddr*) &full_addr, sizeof(full_addr))) {
        perror("connect");
        close(sock);
        exit(1);
    }

    signal(SIGPIPE, SIG_IGN);

    int to_send, to_recv;
    while (scanf("%d", &to_send) > 0) {
        if (write(sock, &to_send, sizeof(to_send)) <= 0) {
            break;  // server closed connection
        }
        if (read(sock, &to_recv, sizeof(to_recv)) <= 0) {
            break;  // server closed connection
        }
        printf("%d ", to_recv);
        fflush(stdout);
    }
    close(sock);
}

