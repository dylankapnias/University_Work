extern malloc
extern encryptChar

    section .data

    section .bss

    section .text
global encryptString

encryptString:
    push rbp                                                    ;
    mov rbp, rsp                                                ; Creating stack frame.
    sub rsp, 64                                                 ;

matrixPtr   equ 0                                               ;
stringPtr   equ 8                                               ;
keyPtr      equ 16                                              ;  
strLength   equ 24                                              ;  Reserving space for local variables.
keyLength   equ 32                                              ;
currKeyChar equ 40                                              ;
returnVal   equ 48                                              ;

    mov [rsp + matrixPtr],  rdi                                 ;
    mov [rsp + stringPtr],  rsi                                 ; Storing passed in arguments on the stack.
    mov [rsp + keyPtr],     rdx                                 ;

keyLenGenInit:
    mov r10, [rsp + keyPtr]                                     ; r10 now holds the key string.
    xor rcx, rcx                                                ; rcx = 0. (Will be used as counter)

keyLenGen:
    cmp byte[r10], 0                                            ; Compare the current char in the key to 0 (i.e. null char)
    je keyLenGenFin                                             ;   If equal, goto keyLenGenFin.

    inc rcx                                                     ; Increase rcx.
    inc r10                                                     ; Increase r10.
    jmp keyLenGen                                               ;   Goto keyLenGen.

keyLenGenFin:
    mov [rsp + keyLength], rcx                                  ; Save key length to stack.

strLenGenInit:
    mov r10, [rsp + stringPtr]                                  ; r10 now holds the input string.
    xor rcx, rcx                                                ; rcx = 0. (Will be used as counter)

strLenGen:
    cmp byte[r10], 0                                            ; Compare the current char in the key to 0 (i.e. null char)
    je strLenGenFin                                             ;   If equal, goto keyLenGenFin.

    cmp byte[r10], 32                                           ; Compare char of the string to 43 (i.e. space char)
    je space                                                    ;   If equal, goto space.

    inc rcx                                                     ; Increase rcx.
    inc r10                                                     ; Increase r10.
    jmp strLenGen                                               ;   Goto keyLenGen.

strLenGenFin:
    mov [rsp + strLength], rcx                                  ; Save key length to stack.

encInit:
    mov rdi, [rsp + strLength]                                  ; rdi now has the length of string with no spaces.
    call malloc                                                 ; Allocate a block of mem with the size of the length of string with no spaces.
    mov [rsp + returnVal], rax                                  ; Store the mem block in returnVal variable.

    mov r10, [rsp + strLength]                                  ; r10 now holds the length of the input string (no spaces)
    mov r11, [rsp + keyLength]                                  ; r11 now holds the length of the key.
    mov r12, [rsp + stringPtr]                                  ; r12 now holds the input string.
    mov r13, [rsp + keyPtr]                                     ; r13 now holds the key string.

    xor rcx, rcx                                                ; rcx = 0.
    xor r14, r14                                                ; r14 = 0. (will use as the key counter)

encStart:
    cmp rcx, r10                                                ; Comapre rcx to the length of the string with no spaces.
    je _end                                                     ;   If equal, goto _end.

    cmp r14, r11                                                ; Comparing r14 (key counter) to r11 (key length)
    je wraparound                                              ;   If not less than, goto wraparound.

    mov r13, [rsp + keyPtr]                                     ; r13 now holds the original key string.
    add r13, r14                                                ; Add the key counter to the original string to get the correctly indexed char.

    cmp byte[r12], 32                                           ; Compare the current char with 32 (i.e. space char)
    je encSpace                                                 ;   If equal, goto encSpace.

    mov rdi, [rsp + matrixPtr]                                  ;
    movsx rsi, byte[r12]                                        ; Storing values in correct registers, so that encryptChar can be called.
    movsx rdx, byte[r13]                                        ;

    push r10                                                    ;
    push r11                                                    ;
    push r12                                                    ; Saving important non-saved registers.
    push r13                                                    ;
    push rcx                                                    ;

    call encryptChar                                            ; Calling encryptChar

    pop rcx                                                     ;
    pop r13                                                     ; Restoring important non-saved registers.
    pop r12                                                     ;
    pop r11                                                     ;
    pop r10                                                     ;

    mov r15, [rsp + returnVal]                                  ;
    mov [r15 + rcx], rax                                        ; Saving the encrypted char to the appropriate place in the return string.

    inc rcx                                                     ; Increase counters.
    inc r14                                                     ;

encSpace:
    inc r12                                                     ; Increase r12.
    jmp encStart                                                ;   Goto encStart.

space:
    inc r10                                                     ; Increase r10.
    jmp strLenGen                                               ;   Goto start.

wraparound:
    sub r14, r11                                                ;
    jmp encStart                                                ;

_end:
    mov rax, [rsp + returnVal]                                  ; Move the returnVal into rax to return to the caller of the function.

    leave                                                       ; Destroying stack frame.
    ret                                                         ;