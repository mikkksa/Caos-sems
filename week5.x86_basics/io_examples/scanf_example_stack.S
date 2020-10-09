.globl main

main:
    subq $8, %rsp      # allocate 8 bytes from stack
    movq $0, %rax      # clear rax
    movabsq $f, %rdi   # load format string
    movq %rsp, %rsi    # set storage to local variable
    call scanf
    addq $8, %rsp      # restore stack
    ret
.data

f:  .string "%d"
x:  .long 0
