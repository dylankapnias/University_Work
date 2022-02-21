    section .data
sin1 db "Please input the first number: "           ; First msg prompt.
sin2 db "Please input the second number: "          ; Second msg prompt.
sub1 db "1"                                         ; First input number.
sub2 db "2"                                         ; Second input number.
quot dq "x"                                         ; Quotient storage.
rem dq "x"                                          ; Remainder storage.

    section .text
    global _start
_start: 
    mov rdx, 31                                     ;
    mov rsi, dword sin1                             ;
    mov rax, 0x1                                    ; Displaying the first msg.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 2                                      ;
    mov rsi, dword sub1                             ;
    mov rax, 0x0                                    ; Storing the first input.
    mov rdi, 0x0                                    ;
    syscall                                         ;

    mov rdx, 32                                     ;
    mov rsi, dword sin2                             ;
    mov rax, 0x1                                    ; Displaying the second msg.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 2                                      ;
    mov rsi, dword sub2                             ; 
    mov rax, 0x0                                    ; Storing the second input.
    mov rdi, 0x0                                    ;
    syscall                                         ;

    mov r10, 48                                     ;
    sub [sub1], r10                                 ; Converting to ASCII val.
    sub [sub2], r10                                 ;

    movsx r8, byte [sub1]                           ; Sign extending the first value.
    movsx r9, byte [sub2]                           ; Sign extending the second value.

    sub r8, r9                                      ; Subtracting the values. Signed and unsigned add are the same.

    mov rax, r8                                     ;
    mov rdx, 0                                      ; Preparing to divide the value in rax by 10 to split the 2 digit
    mov r11, 10                                     ; number in to 2 speparate 1 digit numbers.
    idiv r11                                        ; Signed divide the values.

    add rax, r10                                    ;
    add rdx, r10                                    ; Converting back to decimal values and storing the quotient and
    mov [quot], rax                                 ; remainder separatley.
    mov [rem], rdx                                  ;

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