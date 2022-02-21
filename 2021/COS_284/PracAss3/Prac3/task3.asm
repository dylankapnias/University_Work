    section .bss
user_in resb 4
prog_out resb 8
    
    section .data
sin: dq "Please input an integer: "                 ; First msg prompt. 25 char long.
sout: dq "The total sum is: "                       ; Output msg. 18 char long.
ans: dq "1"                                         ; Answer.
quot: dq "x"                                        ; Quotient storage.
rem: dq "x"                                         ; Remainder storage.

    section .text
    global _start
_start:
    mov rdx, 25                                     ;
    mov rsi, qword sin                              ;
    mov rax, 0x1                                    ; Displaying the first msg.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rdx, 100                                    ;
    mov rsi, user_in                                ;
    mov rax, 0x0                                    ; Storing the first input.
    mov rdi, 0x0                                    ;
    syscall                                         ;

    mov rcx, rax
    push rax

    xor rcx, rcx                                    ; rcx = 0.
    xor r8, r8                                      ; r8 = 0.  
    xor r11, r11 

    mov r10, 48
    sub [user_in], r10
    mov rax, [user_in]
    inc rax
    mov r10, [user_in]
    mul r10
    mov r9, 2
    div r9

;while:
    ;cmp rcx, 0                                      ; Check if count is = to the length.
    ;jne buildNum                                        ;   Goto end.

    ;jmp done                                    ;

;buildNum:
    ;inc r11
    ;xor r9, r9                                      ; r9 = 0.
    ;add r9b, byte[rsi + rcx - 1]                        ;
    ;sub r9b, 48                                     ;
    ;mov rax, r11
    ;mov r10, 10
    ;mul r10
    ;mov r10, rax
    ;mov rax, r9
    ;mul r10
    ;mov r9, rax
    ;add r8b, r9b                                    ;
    
    ;dec rcx                                         ;

    ;jmp while                                       ;

done:
    push rax
    
    mov rdx, 18                                     ;
    mov rsi, qword sout                              ;
    mov rax, 0x1                                    ; Displaying the first msg.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    pop rax
    ;mov rax, r8                                     ;
    mov rdx, 0                                      ; Preparing to divide the value in rax by 10 to split the 2 digit
    mov r11, 10                                     ; number in to 2 speparate 1 digit numbers.
    idiv r11                                        ; Signed divide the values.

    mov r10, 48

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