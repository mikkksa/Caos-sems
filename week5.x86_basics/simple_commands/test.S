        .global main
        .data

test_struct:
        .quad 7
        .quad 8
        .quad 0

test_array:
        .quad 10
        .quad 20
        .quad 30
        .quad 40
        .quad 50
        .quad 60

        
////////////////////////////////////////////////////////////////////////////////
        .text

test_sum:
        mov $10, %rdi
        mov $20, %rsi
        call sum

        ret

test_sum_struct:
        mov $test_struct, %rdi
        call sum_struct
        mov $test_struct, %rdi

        ret

test_sum_array:
        mov $test_array, %rdi
        add $0x10, %rdi
        mov $4, %rsi
        call sum_array

        ret

test_sum_va_arg:
        sub $0x80, %rsp

        movq $1, (%rsp)
        movq $2, 0x8(%rsp)
        movq $100, 0x10(%rsp)
        mov $3, %rdi
        call sum_va_arg

        add $0x80, %rsp
        ret

        
main:
        call test_sum
        call test_sum_struct
        call test_sum_array
        call test_sum_va_arg
        ret
