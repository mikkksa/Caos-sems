#ifndef _BARRIER_H
#define _BARRIER_H

#include "spinlock.h"

void barrier_before(struct spinlock *lock, int pipefds[][2], int id);
void barrier_after(struct spinlock *lock, int pipefds[][2], int id);

#endif
