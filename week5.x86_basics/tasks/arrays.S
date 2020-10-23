.global summ

summ:
    push %rbx
    xor %rax, %rax
loop:
    mov (%rsi, %rax), %rbx
    add (%rdx, %rax), %rbx
    mov %rbx, (%rcx, %rax)
    sub $1, %rdi
    add $4, %rax
    cmp $0, %rdi
    jne loop

    pop %rbx
    ret
