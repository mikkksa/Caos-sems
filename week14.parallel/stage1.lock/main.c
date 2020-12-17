#include <pthread.h>
#include <stdio.h>

#include "spinlock.h"

long shared;
struct spinlock lock;

void *sum(void *arg) {
  int i = 0;

  for(; i < 200000; i++) {
    spinlock_lock(&lock);

    {
      shared++;
    }

    spinlock_unlock(&lock);
  }
}

int main() {
  shared = 0;
  spinlock_init(&lock);

  pthread_t t1, t2;

  pthread_create(&t1, NULL, sum, NULL);
  pthread_create(&t2, NULL, sum, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("%d\n", shared);

  return 0;
}
