.globl main

main:
    push %rbp        # keep stack aligned
    movq $0, %rax    # clear rax
    movq $f, %rdi    # load format string
    movq $x, %rsi    # set storage to address of x
    call scanf
    movq $f, %rdi    # load format string
    movq x, %rsi
    call printf
    pop %rbp
    ret

.data

f:  .string "%d"
x:  .long 0
