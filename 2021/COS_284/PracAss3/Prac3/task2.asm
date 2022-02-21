    section .data
sin: dq "Please input a string: "                   ; First msg prompt. 23 char long.
sout: dq "The new string is: "                      ; Output msg. 19 char long.
string: dq "x"                                      ; First input number.

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

    xor rcx, rcx                                    ; rcx = 0.

while:
    cmp rcx, rax                                    ; Check if count is = to the length.
    jnl done                                        ;   Goto end.

    cmp byte[rsi + rcx],32                          ; Check if the ascii of current byte is space.
    je whitespace                                   ;   Goto whitespace.

    cmp byte[rsi + rcx],90                          ; Check if the ascii of current byte is less than 90 (i.e lowercase).
    jle tolower                                     ;   Goto tolwoer.

                                                    ; Else Goto toupper.

toupper:
    sub byte[rsi + rcx],32                          ; Make the char lowercase.
    inc rcx                                         ; Increase counter.
    jmp while                                       ;   Goto while.

tolower:
    add byte[rsi + rcx],32                          ; Make the char uppercase.
    inc rcx                                         ; Increase counter.
    jmp while                                       ; Goto while.

whitespace:                 
    inc rcx                                         ; Increase counter.
    jmp while                                       ;   Goto while.

done:
    push rcx

    mov rdx, 19                                     ;
    mov rsi, qword sout                             ;
    mov rax, 0x1                                    ; Displaying the first msg.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    pop rcx

    mov rdx, rcx                                    ;
    mov rsi, qword string                           ;
    mov rax, 0x1                                    ; Displaying the changed word.
    mov rdi, 0x1                                    ;
    syscall                                         ;

    mov rax, 60                                     ;
    xor rdi ,rdi                                    ; Exit system call.
    syscall                                         ;