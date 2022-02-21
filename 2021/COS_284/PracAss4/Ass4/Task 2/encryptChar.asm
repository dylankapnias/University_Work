    section .data

    section .bss

    section .text
global encryptChar

encryptChar:
    push rbp                                                    ;
    mov rbp, rsp                                                ; Creating stack frame.
    sub rsp, 32                                                 ;

matrixPtr   equ 0                                               ;
inChar      equ 8                                               ; Reserving space for local variables.
keyChar     equ 16                                              ;

    mov [rsp + matrixPtr],  rdi                                 ;
    mov [rsp + inChar],     rsi                                 ; Storing passed in arguments on the stack.
    mov [rsp + keyChar],    rdx                                 ;

indexRow:
    mov r13, [rsp + matrixPtr]                                  ; r13 now holds the pointer to the matrix.

    mov r10, [rsp + keyChar]                                    ;
    sub r10, 65                                                 ; r10 now holds the index of the row to use.

    mov rax, 8                                                  ;
    mul r10                                                     ; Calculate offset, and store the correct adress in rax.
    mov r10, [r13 + rax]                                        ;

indexCol:
    mov r12, [rsp + inChar]                                     ;
    sub r12, 65                                                 ; r12 now holds the index of the col to use.

chooseChar:
    add r10, r12                                                ; r10 now holds the correctly indexed char.

    movsx rax, byte[r10]                                        ; Store the char to return to the caller of the function.

_end:
    leave                                                       ; Destroying stack frame.
    ret   