    .text
    .global f        
f:
    // r0 = A, r1 = B, r2 = C, r3 = x
    // y = A*x*x + B*x + C

    // Calculate A*x*x
    mul     r0, r0, r3  // r0 = A*x
    mul     r0, r0, r3  // r0 = A*x*x
    // Calculate B*x
    mul     r1, r1, r3  // r1 = B*x
    // Summ everything to r0
    add     r0, r0, r1  // r0 = A*x*x + B*x
    add     r0, r0, r2  // r0 = A*x*x + B*x + C

    // Return value should be stored in r1
    mov     r1, r0

    // return from function (ret address stored in lr)
    bx      lr



