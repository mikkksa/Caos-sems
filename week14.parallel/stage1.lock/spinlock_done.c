#include "spinlock.h"

void spinlock_init(struct spinlock *lock) {
  lock->locked = 0;
}

void spinlock_lock(struct spinlock *lock) {
  while (1) {
    if (!atomic_xchg(&lock->locked, EBUSY)) {
      return;
    }

    while (lock->locked) {
      cpu_relax();
    }
  }
}

void spinlock_unlock(struct spinlock *lock) {
  barrier();
  lock->locked = 0;
}

int spinlock_trylock(struct spinlock *lock) {
  return atomic_xchg(&lock->locked, EBUSY);
}
