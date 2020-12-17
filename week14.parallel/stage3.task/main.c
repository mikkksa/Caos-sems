#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "barrier.h"
#include "spinlock.h"
#include "profile.h"
#include "task.h"

#define ELEM_COUNT 10000000

// TODO: move to barrier
struct spinlock lock;
int pipefds[THREAD_COUNT][2];
int list[ELEM_COUNT];
int results[THREAD_COUNT];
int result;
clock_t begin;

//TODO: rename
void *sum(void *arg) {
  int id = (unsigned long long)arg;
  begin = clock();
  barrier_before(&lock, pipefds, id);
  printf("Thread with id %d is executing the task\n", id);

  execute_task(list, results, ELEM_COUNT, id);

  barrier_after(&lock, pipefds, id);
  printf("Thread with id %d finished the task\n", id);

  if (id == FIRST_THREAD) {
    finish_tasks(results, &result);
    printf("Result=%d\n", result);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("TIME of execution = %f\n", time_spent);
    fflush(stdout);
  }
}

int main() {
  unsigned long long i;
  spinlock_init(&lock);

  for (i = 0; i < ELEM_COUNT; i++) {
    list[i] = i;
  }
  for (i = 0; i < THREAD_COUNT; i++) {
    results[i] = 0;
  }
  result = 0;

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
