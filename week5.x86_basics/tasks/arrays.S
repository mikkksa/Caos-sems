.global summ

summ:
    xor %rax, %rax
loop:
    mov (%rsi, %rax), %rbx
    add (%rdx, %rax), %rbx
    mov %rbx, (%rcx, %rax)
    sub $1, %rdi
    add $8, %rax
    cmp $0, %rdi
    jne loop

    ret
