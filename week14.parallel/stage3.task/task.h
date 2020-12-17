#ifndef _TASK_H
#define _TASK_H

struct task {
  // Shared data
};

void execute_task(void *data, void *results, int len, int id);
void finish_tasks(void *results, void *result);

#endif
