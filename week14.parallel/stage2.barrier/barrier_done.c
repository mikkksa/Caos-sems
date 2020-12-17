#include <unistd.h>

#include "barrier.h"
#include "profile.h"

static int waiters = 0;

void barrier_before(struct spinlock *lock, int pipefds[][2], int id) {
  char byte = 'b';
  spinlock_lock(lock);

  {
    waiters++;
    
    if (waiters == THREAD_COUNT) {
      int i;
      for (i = 0; i < THREAD_COUNT; i++) {
        write(pipefds[i][1], &byte, 1);
      }
    }
  }

  spinlock_unlock(lock);

  read(pipefds[id][0], &byte, 1);
}

void barrier_after(struct spinlock *lock, int pipefds[][2], int id) {
  char byte = 'b';
  spinlock_lock(lock);

  {
    waiters--;
    
    if (waiters == 0) {
      int i;
      for (i = 0; i < THREAD_COUNT; i++) {
        write(pipefds[i][1], &byte, 1);
      }
    }
  }

  spinlock_unlock(lock);

  read(pipefds[id][0], &byte, 1);
}
