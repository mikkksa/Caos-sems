#include <stdlib.h>
#include <string.h>

#include "profile.h"
#include "task.h"

void execute_task(void *data, void *results, int len, int id) {
  int i;
  int *parsed = (int *)data;
  int *parsed_results = (int *)results;
  double my_size = 1.0 * len / THREAD_COUNT;
  int *thread_copy = (int *) malloc(my_size * sizeof(int));
  int left = (int)(id * my_size);

  memcpy(thread_copy, &parsed[left], my_size*sizeof(int));
  for (int i = 0; i<my_size; i++) {
    parsed_results[id] += thread_copy[i];
  }
  free(thread_copy);
}

void finish_tasks(void *results, void *result) {
  int i;
  int *parsed  = (int *)results;
  int *parsed_result = (int *)result;

  for (i = 0; i < THREAD_COUNT; i++) {
    *parsed_result += parsed[i];
  }
}
