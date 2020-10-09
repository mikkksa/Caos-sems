#include <asm/unistd_64.h>
        
        .intel_syntax noprefix
        .text
        .global _start
_start:
        // Print Hello
        //mov     eax, __NR_write
        //mov     ebx, 1
        //mov     ecx, hello_world_ptr
        //mov     edx, 14
        //int     0x80

        mov rax, __NR_write             // ; the (syscall) system call number of "write".
        mov rdi, 1                      // ; first parameter: 1, the stdout file descriptor
        mov rsi, hello_world_ptr        // ; data to write
        mov rdx, 14                     // ; bytes to write
        syscall                         // ; Issue the system call

        // Do exit
        mov     rax, __NR_exit
        mov     rbx, 0
        syscall
        .data
hello_world:
        .string "Hello, World!\n"
hello_world_ptr:
        .long   hello_world
