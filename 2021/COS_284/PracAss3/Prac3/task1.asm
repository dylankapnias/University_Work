    section .data
sin dq "Please enter a string: "                    ; First msg prompt. 23 char long.
sout: dq "The length of the string is: "            ; Output msg. 29 char long.
string dq "x"                                       ; First input number.
quot dq "x"                                         ; Quotient storage.
rem dq "x"                                          ; Remainder storage.

    section .text
    global _start
_start:
    mov rdx, 23                                     ;
    mov rsi, qword sin                              ;
    mov rax, 0x1                                    ; Displaying the first msg.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 100                                    ;
    mov rsi, qword string                           ;
    mov rax, 0x0                                    ; Storing the first input.
    mov rdi, 0x0                                    ;
    syscall                                         ;

    xor rdx, rdx                                    ;
    mov rbx, 10                                     ; Length is stored in rax after the syscall.
    idiv rbx                                        ;

    mov [quot], rax                                 ;
    mov [rem], rdx                                  ;

    mov r8, 48                                      ;

    add [quot], r8                                  ;
    add [rem], r8                                   ;

    mov rdx, 29                                     ;
    mov rsi, qword sout                             ;
    mov rax, 0x1                                    ; Displaying the second msg..
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 1                                      ;
    mov rsi, qword quot                             ;
    mov rax, 0x1                                    ; Displaying the quotient. i.e. The first number.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 1                                      ;
    mov rsi, qword rem                              ;
    mov rax, 0x1                                    ; Displaying the remainder. i.e. The second number.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rax, 60                                     ;
    xor rdi ,rdi                                    ; Exit system call.
    syscall                                         ;