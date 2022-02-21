    section .data
sin1 dq "Please input the first number: "           ; First msg prompt.
sin2 dq "Please input the second number: "          ; Second msg prompt.
div1 dq "a"                                         ; First input number.
div2 dq "a"                                         ; Second input number.
quot dq "a"                                         ; Quotient storage.
rem  dq "a"                                         ; Remainder storage.
r db "r"                                            ; Remainder output char

    section .text
    global _start
_start:
    mov rdx, 31                                     ;
    mov rsi, qword sin1                             ;
    mov rax, 0x1                                    ; Displaying the first msg.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 2                                      ;
    mov rsi, qword div1                             ;
    mov rax, 0x0                                    ; Storing the first input.
    mov rdi, 0x0                                    ;
    syscall                                         ;

    mov rdx, 32                                     ;
    mov rsi, qword sin2                             ;
    mov rax, 0x1                                    ; Displaying the second msg.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 2                                      ;
    mov rsi, qword div2                             ;
    mov rax, 0x0                                    ; Storing the second input.
    mov rdi, 0x0                                    ;
    syscall                                         ;

    mov r10 , 48                                    ;
    sub [div1] , r10                                ; Converting to ASCII val.
    sub [div2] , r10                                ;

    movsx r8 , byte [div1]                          ; Sign extending the value.
    movsx r9 , byte [div2]

    ;idiv r8 ,[div2]                                 ; Signed divide the values.

    mov rax , r8                                    ;
    mov rdx , 0                                     ; Preparing to divide the value in rax by 10 to split the 2 digit
    ;mov r13 , 10                                    ; number in to 2 speparate 1 digit numbers.
    idiv r9                                        ; Signed divide the values.

    add rax, r10                                    ;
    add rdx, r10                                    ; Converting back to decimal values and storing the quotient and
    mov [quot] , rax                                ; remainder separatley.
    mov [rem] , rdx                                 ;

    mov rdx, 1                                      ;
    mov rsi, qword quot                             ;
    mov rax, 0x1                                    ; Displaying the quotient. i.e. The first number.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 1                                      ;
    mov rsi, qword r                                ;
    mov rax, 0x1                                    ; Displaying the remainder char.
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