extern malloc
    
    section .data
    struc Trie
.children    resq    26                                         ; Size for 26 pointers.
.isWord      resb    26                                         ; Size for 26 char.
align 8                                                         ; Aligned to 8 for pointer padding.
    endstruc

triePtr     equ 0                                               ;
trieWord    equ 8                                               ; Local variable indexes.

    section .bss
    
    section .text
global trieContains

trieContains:
    push rbp                                                    ;
    mov rbp, rsp                                                ;
    push rbx                                                    ;
    push r12                                                    ;  Creating stack frame, and storing preserved registers.
    push r13                                                    ;
    push r14                                                    ;
    push r15                                                    ;

    sub rsp, 32                                                 ; Reserving space for local variables

trieContainsInit:
    mov [rsp + triePtr], rdi                                    ; Save Trie Pointer on the stack.
    mov [rsp + trieWord], rsi                                   ; Save word to insert Pointer on the stack.

    xor rcx, rcx                                                ; rcx = 0. (Will be used as counter)
    mov r12, [rsp + triePtr]                                    ; r12 now holds the pointer to the trie.
    add r12, Trie.children                                      ; r12 will now be offset appropriately such that the children array can be indexed.
    mov r13, [rsp + trieWord]                                   ; r13 no holds the word to insert.

wordLoop:
    movsx r15, byte[r13 + rcx]                                  ; r15 now holds the correctly indexed letter from the passed in word.
    cmp r15, 0                                                  ; Compare the currently indexed char with '0', null char.
    je trieContainsFin                                          ;   If equal, goto trieInsertFin.

    mov r14, r15                                                ; r14 now holds the current letter.
    sub r14, 97                                                 ; r14 now holds the letterIndex.

    inc rcx                                                     ; rcx + 1
    movsx r15, byte[r13 + rcx]                                  ; r15 now holds the next indexed letter from the passed in word.
    cmp r15, 0                                                  ; Compare the next letter to 0.
    je trieContainsFin                                          ;   If equal, goto trieInsertFin.
    dec rcx                                                     ; rcx - 1

    mov r15, [r12 + 8*r14]                                      ; r15 now holds the correctly indexed child of the trie.
    cmp r15, 0                                                  ; Compare the pointer at letterIndex in children array.
    je trieNotContains                                          ;   If equal, goto createChild.

nextNode:
    mov r12, [r12 + 8*r14]                                      ; Set the current working node to the correctly indexed one.
    add r12, Trie.children                                      ; r12 will now be offset appropriately such that the children array can be indexed. 
    inc rcx                                                     ; Increase rcx.

    jmp wordLoop                                                ;   Goto wordLoop.

trieContainsFin:
    sub r12, Trie.children                                      ; r12 will now point to the trie.
    add r12, Trie.isWord                                        ; r12 will no be offset such that the isWord array can be indexed.

    movsx rax, byte[r12 + r14]                                  ; Moving isWord at the correct index into rax for return. 

    add rsp, 32                                                 ; Removing reserved space.
    jmp _end                                                    ;   Goto end.

trieNotContains:
    mov rax, 0                                                  ; Return 0 for not containing the word.

    add rsp, 32                                                 ; Removing reserved space.
    jmp _end                                                    ;   Goto end.

_end:
    pop r15                                                     ;
    pop r14                                                     ;
    pop r13                                                     ; Restoring the preserved registers.
    pop r12                                                     ;
    pop rbx                                                     ;

    leave                                                       ; Destroying stack frame.
    ret                                                         ; Returning.