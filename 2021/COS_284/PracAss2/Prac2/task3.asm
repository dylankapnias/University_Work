    section .data
sin1 db "Please input the first number: "
sin2 db "Please input the second number: "
newline db 0xa
add1 db "1"
add2 db "2"

    section .text
    global _start
_start: 
    mov rdx, 31
    mov rsi, dword sin1
    mov rax, 0x1
    mov rdi, 0x1
    syscall

    mov rdx, 2
    mov rsi, dword add1
    mov rax, 0x0
    mov rdi, 0x0
    syscall

    mov rdx, 32
    mov rsi, dword sin2
    mov rax, 0x1
    mov rdi, 0x1
    syscall

    mov rdx, 2
    mov rsi, dword add2
    mov rax, 0x0
    mov rdi, 0x0
    syscall

    mov r8, [add1]
    mov r9, [add2]
    mov r10, 48
    sub r8, r10
    sub r9, r10
    add r8, r9
    add r8, r10
    mov [add1], r8

    mov rdx, 1
    mov rsi, dword add1
    mov rax, 0x1
    mov rdi, 0x1
    syscall

    mov rdx, 1
    mov rsi, dword newline
    mov rax, 0x1
    mov rdi, 0x1
    syscall

    mov rax, 60
    xor rdi, rdi 
    syscall


        


