    section .data
sin db "Please input a lowercase character: "
lower db "x"
newline db 0xa
sout db "In uppercase: "

    section .text
    global _start
_start:
    mov rdx, 36
    mov rsi, dword sin
    mov rax, 0x1
    mov rdi, 0x1
    syscall

    mov rdx, 1
    mov rsi, dword lower
    mov rax, 0x0
    mov rdi, 0x0
    syscall

    mov rdx, 14
    mov rsi, dword sout
    mov rax, 0x1
    mov rdi, 0x1
    syscall
        
    mov r8 , 32
    sub [lower],r8

    mov rdx, 1
    mov rsi, dword lower
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