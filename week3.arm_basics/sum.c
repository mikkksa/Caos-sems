#include <stdio.h>
#include <assert.h>
#include <stdint.h>

extern
int f(int A, int B, int C, int x);


int
main()
{
    int ax[4];
    int y;
    while ( scanf("%d%d%d%d", &ax[0], &ax[1], &ax[2], &ax[3]) > 0 ) {
        y = f(ax[0], ax[1], ax[2], ax[3]);
        printf("%d\n", y);
    }
    return 0;
}
