    section .bss
deg resb 2
string resb 8
    section .data
sin1: dq "Please input the shift degree: "                      ; First msg prompt. 31 char long.
sin2: dq "Please input the string to decode: "                  ; Second msg prompt. 35 char long.
sout: dq "Decoded text: "                                       ; Output msg. 14 char long.
    

    section .text
    global _start
_start:
    mov rdx, 31                                                 ;
    mov rsi, qword sin1                                         ;
    mov rax, 0x1                                                ; Displaying the first msg.
    mov rdi, 0x1                                                ;
    syscall                                                     ;

    mov rdx, 3                                                  ;
    mov rsi, qword deg                                          ;
    mov rax, 0x0                                                ; Storing the first input.
    mov rdi, 0x0                                                ;
    syscall                                                     ;

    push rax                                                    ; Storing the length of the degree.

    mov rdx, 35                                                 ;
    mov rsi, qword sin2                                         ;
    mov rax, 0x1                                                ; Displaying the second msg.
    mov rdi, 0x1                                                ;
    syscall                                                     ;

    mov rdx, 132                                                ;
    mov rsi, qword string                                       ;
    mov rax, 0x0                                                ; Storing the second input.
    mov rdi, 0x0                                                ;
    syscall                                                     ;

    pop r8                                                      ; Restoring the length of the degree.
    mov r10, rax                                                ; Moving the length of the string.
    xor rcx, rcx                                                ; rcx = 0.
    mov r11, rsi                                                ; mov rsi (i.e string) into r11

    cmp r8, 2                                                   ; Comparing length to 2. (Counting \n)
    jg twoDigits                                                ;   Goto twoDigits if greater than.

    jmp singleDigit                                             ;   Else goto singleDigit.
    
singleDigit:
    xor r8, r8                                                  ; r8 = 0.
    movsx r8, byte [deg]                                        ; Sign extending the single digit into r8.
    sub r8, 48                                                  ; Converting to decimal value from ascii.
    jmp while                                                   ;   Goto while.

twoDigits:
    xor r8, r8                                                  ; r8 = 0.
    movsx r8, byte[deg]                                         ; Sign extending the ten's digit into r8.
    movsx r9, byte[deg + 1]                                     ; Sign extending the ones's digit into r9.
    sub r9, 48                                                  ; Converting to decimal value from ascii.
    sub r8, 48                                                  ; Converting to decimal value from ascii.
    imul r8, 10                                                 ; Multiply by to to correct the decimal val.
    add r8, r9                                                  ; Add together to get correct decimal for double digit input.
    jmp while                                                   ;   Goto while.

while:
    cmp rcx, r10                                                ; Comparing rcx to string length
    je done                                                     ;   Goto done if equal to.

    cmp byte[rsi + rcx], 32                                     ; Comparing the current char to 32 (i.e space).
    je whitespace                                               ;   Goto whitespace if equal to.

    jmp islower                                                 ;   Else goto islower.

whitespace:
    inc rcx                                                     ; Increase rcx to skip whitespace.
    jmp while                                                   ;   Goto while.

islower:
    movsx r12, byte[rsi + rcx]                                  ; Sign extend ascii value of current char into r12
    sub r12b, r8b                                               ; Subtract the degree of shift to the ascii val of char.

    cmp r12, 97                                                 ; Compare the ascii value to 97 (i.e start of bounds for lowercase alphabet).
    jl wraparound                                               ;   Goto wraparound if less than.

    sub byte[r11 + rcx], r8b                                    ; If no wraparound, shift the current char.
    inc rcx                                                     ; Increase rcx.
    jmp while                                                   ;   Goto while.

wraparound:
    xor r12, r12                                                ; r12 = 0.
    mov r12, 26                                                 ; Move 26 (length of alphabet) into r12.
    sub byte[r11 + rcx], r8b                                    ; Subtract the shift degree from the current char.
    add byte[r11 + rcx], r12b                                   ; Add the length of the alphabet to get the correct char.
    inc rcx                                                     ; Increase rcx.
    jmp while                                                   ;   Goto while.

done:
    push r11                                                     ; Storing r11 (i.e the changed string).

    mov rdx, 14                                                 ;
    mov rsi, qword sout                                         ;
    mov rax, 0x1                                                ; Displaying the first msg.
    mov rdi, 0x1                                                ;
    syscall                                                     ;

    pop r11                                                     ; Restoring r11.

    ;sub r10, 1                                                  ; Subtract 1 from length for \n.
    mov rdx, r10                                                ;
    mov rsi, r11                                                ;
    mov rax, 0x1                                                ; Displaying the changed word.
    mov rdi, 0x1                                                ;
    syscall                                                     ;

    mov rax, 60                                                 ;
    xor rdi ,rdi                                                ; Exit system call.
    syscall                                                     ;


