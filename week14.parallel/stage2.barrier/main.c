#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "barrier.h"
#include "spinlock.h"
#include "profile.h"

struct spinlock lock;
int pipefds[THREAD_COUNT][2];

void *sum(void *arg) {
  int id = (unsigned long long)arg;
  barrier_before(&lock, pipefds, id);
  printf("Thread with id %d is executing the task\n", id);

  barrier_after(&lock, pipefds, id);
  printf("Thread with id %d finished the task\n", id);
}

int main() {
  unsigned long long i;
  spinlock_init(&lock);

  pthread_t threads[THREAD_COUNT];

  for (i = 0; i < THREAD_COUNT; i++) {
    pipe(pipefds[i]);
    pthread_create(&threads[i], NULL, sum, (void *)i);
  }

  for (i = 0; i < THREAD_COUNT; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
