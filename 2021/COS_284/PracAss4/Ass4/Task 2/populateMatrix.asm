extern malloc

    section .data
    
    section .bss
    
    section .text
global populateMatrix

populateMatrix:
    push rbp                                                    ;
    mov rbp, rsp                                                ; Creating stack frame.
    sub rsp, 16                                                 ;

var         equ 0                                               ; Reserving space for local variables.
stackMatrix equ 8                                               ;

    mov rdi, 208                                                ;
    call malloc                                                 ; Allocating the block of mem to hold the pointers.
    mov [rsp + stackMatrix], rax                                ; Saving the adress onto the stack.

    mov r14, 65                                                 ; Storing letter 'A' in ascii.
    xor r15, r15                                                ; r15 = 0

createStruct:
    cmp r15, 26                                                 ; Compare r15 to length of the array.
    je init                                                     ;   If equal, goto init.

    mov rdi, 26                                                 ;
    call malloc                                                 ; Allocating the block of mem for the chars.
    mov [rsp + var], rax                                        ;

    mov rax, 8                                                  ; Multiply 8 by the index of the array we are at to get the offset in the block of mem (208b).
    mul r15                                                     ;

    mov rdi, [rsp + var]                                        ;
    mov r9, [rsp + stackMatrix]                                 ; Insert the block of mem (26b) into the correct position.
    mov [r9 + rax], rdi                                         ;

    inc r15                                                     ; Index increase.
    jmp createStruct                                            ;   Goto createStruct.

init:
    xor r9, r9                                                  ; Row counter.
    xor r10, r10                                                ; Col counter.

indexRow:
    cmp r9, 26                                                  ; Compare r9 to the size of array.
    je _end                                                     ;   If greater than, goto _end.

    mov rax, 8                                                  ; Offset calc.
    mul r9                                                      ;
    
    mov r11, [rsp + stackMatrix]                                ;
    mov r11, [r11 + rax]                                        ; Which row to work on.

    xor r10, r10                                                ; r10 = 0.

insertLetters:
    cmp r10, 26                                                 ; Compare r10 to the size of the array.
    je endRow                                                   ;

    mov r13, r14                                                ; Choosing the correct letter.
    add r13, r9                                                 ;

    cmp r13, 90                                                 ; Compare letter to 90 (end of uppercase alphabet).
    jg wraparound                                               ;   If greater then, goto wraparound.

    jmp inBounds                                                ;   Goto inBounds.

wraparound:
    mov r8, 90                                                  ; Subtract 90 to get what position in the alphabet it should be.
    sub r13, r8                                                 ;
    mov r8, 64                                                  ; Add 64 to get back to ascii.
    add r13, r8                                                 ;

inBounds:
    mov r15, r11                                                ;
    add r15, r10                                                ; The correct index in the block.
    mov [r15], r13                                              ;

    inc r10                                                     ; Col count increase.
    inc r14                                                     ; Letter increase.
    jmp insertLetters                                           ;   Goto insertLetter

endRow:
    inc r9                                                      ; Row count increase.
    xor r10, r10                                                ; Column count set to 0.
    mov r14, 65                                                 ; Storing letter 'A' in ascii.
    
    jmp indexRow                                                ;   Goto indexRow.

_end:
    mov rax, [rsp + stackMatrix]                                ;

    leave                                                       ; Destroying stack frame.
    ret                                                         ; Returning.