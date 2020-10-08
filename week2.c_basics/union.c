#include <stdint.h>
#include <stdio.h>

static double a = 3.14159;

typedef union {
    double     real_value;
    uint64_t   uint_value;
} real_or_uint;

int main() {
    uint64_t b;

    real_or_uint u;
    u.real_value = a;
    b = u.uint_value;

    printf("%f\n", u.uint_value); // 0.000
    printf("%f\n", u.real_value); // 3.141590

    // ------------------ BUT ---------------------- 

    printf("%f\n", u.real_value); // 3.141590
    printf("%f\n", u.uint_value); // 3.141590

    return 0;
}
