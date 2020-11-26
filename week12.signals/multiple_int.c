#include <signal.h>
#include <unistd.h>

static void handler(int signum) {
    static const char Message[] = "Got Ctrl+C\n";
    static const char Message2[] = "I'm still here\n";

    write(1, Message, sizeof(Message)-1);
    raise(SIGTERM);
    write(1, Message2, sizeof(Message2)-1);
    sleep(2);
}

static void term_handler(int signum) {
    static const char Message[] = "Got SIGTERM\n";
    write(1, Message, sizeof(Message)-1);
    sleep(2);
}

int main() {
    sigaction(SIGINT,
              &(struct sigaction)
              {.sa_handler=handler, .sa_flags=SA_RESTART},
              NULL);
    sigaction(SIGTERM,
              &(struct sigaction)
              {.sa_handler=term_handler, .sa_flags=SA_RESTART},
              NULL);
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGTERM);

    while (1) {
        sigprocmask(SIG_BLOCK, &mask, NULL);
        sleep(10);
        sigprocmask(SIG_UNBLOCK, &mask, NULL);
    }

  return 0;
}
