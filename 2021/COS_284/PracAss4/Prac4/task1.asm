    section .text
    global funct

funct:
    push rbp                                                    ;
    mov rbp, rsp                                                ; Creating stack frame.
    sub rsp, 32                                                 ;

N   equ 0                                                       ;
nM1 equ 8                                                       ; Reserving space for local variables.
nM2 equ 16                                                      ;
    
    cmp rdi, 0                                                  ; Comparing first argument to 0.
    je firstBase                                                ;   If equal to, jump to first base condition.

    cmp rdi, 1                                                  ; Comparing first argument to 1.
    je secondBase                                               ;   If equal to, jump to second base condition.

    jmp thirdBase                                               ;   If none of the above jump to third base condition.

firstBase:
    mov rax, 1
    jmp _end

secondBase:
    mov rax, 2
    jmp _end

thirdBase:
    mov [rsp + N], rdi                                          ; Save n.

    dec rdi                                                     ; n - 1.
    call funct                                                  ; Call function passing in n - 1 as first argument.
    mov [rsp + nM1], rax                                        ; Save return of funct(n - 1)

    mov rdi, [rsp + N]                                          ; Load n
    dec rdi                                                     ; n - 1.
    dec rdi                                                     ; n - 2.
    call funct                                                  ; Call function passing in rdi - 2 as first argument.
    mov [rsp + nM2], rax                                        ; Save return of funct(n - 2)

    mov rax, [rsp + nM2]                                        ; Move the value of funct(n - 2) into rax, to prepare for multiplying.
    mov rdi, [rsp + N]                                          ; Load n
    dec rdi                                                     ; n - 1. 
    mul rdi                                                     ; Multiply the value of funct(n - 2) with the number (n - 1).
    
    mov r11, rax                                                ; Move resultant value into r11.        
    mov rax, [rsp + nM1]                                        ; Move the vlaue of funct(n - 1) into rax, preparing to sub and return value.
    sub rax, r11                                                ; Subtract the result of the multiplication from funct(n - 1).
    
_end:
    leave                                                       ; Destroying stack frame.
    ret                                                         ; Returning.