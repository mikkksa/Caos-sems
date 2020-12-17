#include <stdio.h>
#include <pthread.h>

#define atomic_xadd(P, V) __sync_fetch_and_add((P), (V))
#define cmpxchg(P, O, N) __sync_val_compare_and_swap((P), (O), (N))
#define atomic_inc(P) __sync_add_and_fetch((P), 1)
#define atomic_dec(P) __sync_add_and_fetch((P), -1)
//#define atomic_add(P, V) __sync_add_and_fetch((P), (V))
#define atomic_set_bit(P, V) __sync_or_and_fetch((P), 1<<(V))
#define atomic_clear_bit(P, V) __sync_and_and_fetch((P), ~(1<<(V)))


/* Compile read-write barrier */
#define barrier() asm volatile("": : :"memory")

/* Pause instruction to prevent excess processor bus usage */
#define cpu_relax() asm volatile("pause\n": : :"memory")

static inline void atomic_add(long* atomic, long value)
{
    asm volatile("lock add %1, %0":"=m"(*atomic):"r"(value));
}

static inline void atomic_sub(long* atomic, long value)
{
    asm volatile("lock sub %1, %0":"=m"(*atomic):"r"(value));
}

static inline unsigned atomic_xchg(void *ptr, unsigned x)
{
  asm volatile ("xchgl %0,%1"
        :"=r" ((unsigned) x)
        :"m" (*(volatile unsigned *)ptr), "0" (x)
        :"memory");

  return x;
}

static inline int atomic_cmpxchg(long *atomic, long *expected, long value)
{
    char ret;

    asm volatile(
        " lock cmpxchgq %4,%5 \n"
        "setz %2 \n"
:       "=a" (*expected), "=m"(*atomic), "=q" (ret)
:       "a" (*expected), "r" (value), "m"(*atomic));
    return (int)ret;
}

long shared = 0;
long shared_locked = 0;

void *sum(void *arg) {
  int i = 0;

  for(; i < 200000; i++) {
    shared++;
    atomic_add(&shared_locked, 1);
  }
}

int main() {
  long atomic = 4;
  atomic_sub(&atomic, 3);
  printf("%d\n", atomic);

  long x = 3;
  //long val = atomic_xchg(&x, atomic);
  //printf("%d %d %d\n", x, val, atomic);

  pthread_t t1, t2;
  pthread_create(&t1, NULL, sum, NULL);
  pthread_create(&t2, NULL, sum, NULL);

  // Q: How to write without join?
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("%d\n", shared);
  printf("%d\n", shared_locked);
}
