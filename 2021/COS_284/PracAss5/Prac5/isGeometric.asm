    section .data
    
    section .bss
    
    section .text
global isGeometric

isGeometric:
    push rbp                                                    ;
    mov rbp, rsp                                                ;
    push rbx                                                    ;
    push r12                                                    ;  Creating stack frame, and storing preserved registers.
    push r13                                                    ;
    push r14                                                    ;
    push r15                                                    ;

    sub rsp, 32                                                 ; Reserving space for local variables

list        equ 0                                               ; Local variable indexes.   
listSize    equ 8                                               ;

    mov [rsp + list], rdi                                       ; Store the pointer to the sequence on the stack.
    mov [rsp + listSize], rsi                                   ; Store the size of the sequence on the stack.

    xor ecx, ecx                                                ; rcx = 0 (i.e. zero out the counter)
    mov rax, 1                                                  ; Set the return value to 1.

init:
    mov r14, [rsp + listSize]                                   ;
    cmp r14, 2                                                  ; Compare the size of the list with 2.
    jl notGeo                                                   ;   If less than, goto notGeo (i.e. There are not enough elements to calculate)

    mov r15, [rsp + list]                                       ; r15 now holds the pointer to the sequence.
    movsd xmm1, [r15]                                           ; xmm1 now holds list[0].
    movsd xmm3, [r15 + 8]                                       ; xmm3 now holds list[1].

    divsd xmm3, xmm1                                            ; xmm3 now holds the ratio.

    dec r14                                                     ; Size - 1.

check:
    cmp rcx, r14                                                ; Compare the counter to the size of the list.
    jge _end                                                    ;   If greater than or equal to, goto _end

    movsd xmm1, [r15 + 8 * rcx]                                 ; xmm1 now holds list[i].
    inc rcx                                                     ; counter + 1.
    movsd xmm2, [r15 + 8 * rcx]                                 ; xmm2 now holds list[i + 1].

    divsd xmm2, xmm1                                            ; list[i + 1] / list[i]

    ucomisd xmm2, xmm3                                          ; Compare list[i + 1] / list[i] to the ratio.
    jne notGeo                                                  ;   If not equal, got to notGeo (i.e. Is not a geometric sequence).

    jmp check                                                   ;   Goto check.

notGeo:
    mov rax, 0                                                  ;

_end:
    add rsp, 32                                                 ; Removing reserved space.

    pop r15                                                     ;
    pop r14                                                     ;
    pop r13                                                     ; Restoring the preserved registers.
    pop r12                                                     ;
    pop rbx                                                     ;

    leave                                                       ; Destroying stack frame.
    ret                                                         ; Returning.