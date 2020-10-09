#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

// ------------------ TASK ------------------ //
// Calculate R=(A*B)+(C*D) in asm function

uint32_t A = 0;
uint32_t B = 0;
uint32_t C = 0;
uint32_t D = 0;

extern void
calculate();

extern uint32_t R;

int
main()
{
  while (scanf("%"SCNu32"%"SCNu32"%"SCNu32"%"SCNu32, &A, &B, &C, &D)>0)
    {
      calculate();
      printf("%"PRIu32"\n", R);
    }
}
