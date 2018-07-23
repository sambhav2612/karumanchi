section .data   ;this is a data section
    msg db      "hello, world!"     ;this is a constant

section .start  ;entry point of the program
    global _start
_start:         ;actual execution starts here
    mov     rax, 1
    mov     edi, 1
    mov     rsi, msg
    mov     rdx, 13
    syscall
    mov     rax, 60
    mov     rdi, 0
    syscall