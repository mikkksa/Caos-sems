#include "barrier.h"
#include "profile.h"

static int waiters = 0;

void barrier_before(struct spinlock *lock, int pipefds[][2], int id) {
  char byte = 'b';
  spinlock_lock(lock);

  {
    waiters++;
    
    // Your code here
  }

  spinlock_unlock(lock);

  // Your code here
}

void barrier_after(struct spinlock *lock, int pipefds[][2], int id) {
  // Your code here
}
