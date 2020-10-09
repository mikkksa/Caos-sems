#include <stdio.h>

extern double sum(double sum_array[], int count);

int main() {
    double test[] = {
        12.3, 4.0, 1.8, 34.9, 17, 15.5
    };
    printf("%f\n", sum(test, 0));
    printf("%f\n", sum(test, 1));
    printf("%f\n", sum(test, 3));
    printf("%f\n", sum(test, 6));
    return 0;
}
