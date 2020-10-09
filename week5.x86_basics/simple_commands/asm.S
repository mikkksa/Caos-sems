        .global sum
        .global sum_struct
        .global sum_array
        .global sum_va_arg

sum:
        add %rsi, %rdi
        mov %rdi, %rax
        ret

        // struct {
        //     int64_t a;
        //     int64_t b;
        //     int64_t c;
        // };
        // c <= a + b
sum_struct:
        mov 8(%rdi), %rax    
        add (%rdi), %rax
        mov %rax, 16(%rdi)
        ret


        // %rdi - int64_t *
        // %rsi - elements count
        // %rsi <= sum
sum_array:
        xor %rax, %rax
        xor %rbx, %rbx
sum_loop:
        cmp $0, %rsi
        jz exit_mark
        add (%rdi, %rbx), %rax
        add $0x8, %rbx
        sub $1, %rsi
        jmp sum_loop
exit_mark:
        ret


        // %rdi - amount of int64_t elements on stack
        // elements are after ret address
sum_va_arg:
        xor %rax, %rax
        mov $0x8, %rbx
sum_loop_ar:
        cmp $0, %rdi
        jz exit_mark_ar
        add (%rsp, %rbx), %rax
        add $0x8, %rbx
        sub $1, %rdi
        jmp sum_loop_ar
exit_mark_ar:
        ret
