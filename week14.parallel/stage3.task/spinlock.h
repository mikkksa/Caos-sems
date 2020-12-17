#ifndef _SPNLOCK_H
#define _SPNLOCK_H

/* Compile read-write barrier */
#define barrier() asm volatile("": : :"memory")

/* Pause instruction to prevent excess processor bus usage */
#define cpu_relax() asm volatile("pause\n": : :"memory")


static inline unsigned atomic_xchg(void *ptr, unsigned x)
{
  asm volatile ("xchgl %0,%1"
        :"=r" ((unsigned) x)
        :"m" (*(volatile unsigned *)ptr), "0" (x)
        :"memory");

  return x;
}

#define EBUSY 1

struct spinlock {
  long locked;
};

void spinlock_init(struct spinlock *lock);
void spinlock_lock(struct spinlock *lock);
void spinlock_unlock(struct spinlock *lock);
int spinlock_trylock(struct spinlock *lock);

#endif
