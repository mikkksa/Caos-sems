#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define GNU_SOURCE
#include <sys/syscall.h>

static pid_t main_pid;

static void term_handler(int signum) {
  static const char Message[] = "Got SIGINT\n";
  write(1, Message, sizeof(Message)-1);
  printf("My tid=%d\n", syscall(SYS_gettid));
  printf("My pid=%d\n", syscall(SYS_getpid));
  fflush(stdout);
  sleep(2);
}

void *func(void *arg) {
  pid_t p = getpid();
  pid_t t = syscall(SYS_gettid);
  int x = 0;

  while (1) {
    x += 1;
    printf("I'm here: pid=%d; tid=%d x=%d\n", p, t, x);
    fflush(stdout);
    sleep(2);

    if (t == main_pid+1) {
      //raise(SIGTERM);
    }
  }
  return NULL;
}

int main() {
  pthread_t t[10];
  int i;

  main_pid = getpid();

  printf("Main pid=%d\n", main_pid);

  // Init handler
  sigaction(SIGINT,
            &(struct sigaction)
            {.sa_handler=term_handler, .sa_flags=SA_RESTART},
            NULL);

  for (i = 0; i < 10; i++) {
    if (pthread_create(&t[i], NULL, func, NULL)) {
      printf("Error creating thread\n");
      return -1;
    }
  }

  for (i = 0; i < 10; i++) {
    if (pthread_join(t[i], NULL)) {
      printf("Error joining thread\n");
      return -2;
    }
  }

  return 0;
}
