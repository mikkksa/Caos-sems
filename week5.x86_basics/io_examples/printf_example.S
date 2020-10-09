.global main
.extern printf

.section .data
hello:
    .string "Hello %d %d!\n"

.section .text

main:
    push %rbp
    movq $hello, %rdi
    movq $1, %rsi
    movq $2, %rdx
    
    call printf
    pop %rbp
    ret
