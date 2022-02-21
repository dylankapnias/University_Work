	section .data
digits: db "XXXXX"
newline db 0xa                                      ; Newline hex val.  
sin: db "Please input a 5 digit number: "
sout: db "This is the number you are looking for: "

	section .text
    global _start
_start:
    mov rdx, 31
    mov rsi, dword sin
    mov rax, 0x01
    mov rdi, 0x01
    syscall

    mov rdx, 6
    mov rsi, dword digits
    mov rax, 0x00
    mov rdi, 0x00
    syscall

    mov rdx, 40
    mov rsi, dword sout
    mov rax, 0x01
    mov rdi, 0x01
    syscall

    mov rdx, 5
    mov rsi, dword digits
    mov rax, 0x01
    mov rdi, 0x01
    syscall

    mov rdx, 1
    mov rsi, dword newline
    mov rax, 0x01
    mov rdi, 0x01
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall