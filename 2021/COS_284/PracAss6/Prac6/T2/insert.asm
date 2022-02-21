extern trieAlloc, trieInit, malloc
    
    section .data
    struc Trie
.children    resq    26                                         ; Size for 26 pointers.
.isWord      resb    26                                         ; Size for 26 char.
align 8                                                         ; Aligned to 8 for pointer padding.
    endstruc

triePtr     equ 0                                               ;
trieWord    equ 8                                               ; Local variable indexes.
counter     equ 16                                              ;

    section .bss
    
    section .text
global trieInsert

trieInsert:
    push rbp                                                    ;
    mov rbp, rsp                                                ;
    push rbx                                                    ;
    push r12                                                    ;  Creating stack frame, and storing preserved registers.
    push r13                                                    ;
    push r14                                                    ;
    push r15                                                    ;

    sub rsp, 32                                                 ; Reserving space for local variables

    mov [rsp + triePtr], rdi                                    ; Save Trie Pointer on the stack.
    mov [rsp + trieWord], rsi                                   ; Save word to insert Pointer on the stack.

    xor rcx, rcx                                                ; rcx = 0. (Will be used as counter)
    mov r12, [rsp + triePtr]                                    ; r12 now holds the pointer to the trie.
    add r12, Trie.children                                      ; r12 will now be offset appropriately such that the children array can be indexed.
    mov r13, [rsp + trieWord]                                   ; r13 no holds the word to insert.

wordLoop:
    movsx r15, byte[r13 + rcx]                                  ; r15 now holds the correctly indexed letter from the passed in word.
    cmp r15, 0                                                  ; Compare the currently indexed char with '0', null char.
    je trieInsertFin                                            ;   If equal, goto trieInsertFin.

    mov r14, r15                                                ; r14 now holds the current letter.
    sub r14, 97                                                 ; r14 now holds the letterIndex.

    inc rcx                                                     ;
    movsx r15, byte[r13 + rcx]                                  ; r15 now holds the next indexed letter from the passed in word.
    cmp r15, 0                                                  ;
    je trieInsertFin                                            ;

    dec rcx                                                     ;

    mov r15, [r12 + 8*r14]                                      ; r15 now holds the correctly indexed child of the trie.
    cmp r15, 0                                                  ; Compare the pointer at letterIndex in children array.
    je createChild                                              ;   If equal, goto createChild.

nextNode:
    mov r12, [r12 + 8*r14]                                      ; Set the current working node to the correctly indexed one.
    add r12, Trie.children                                      ; r12 will now be offset appropriately such that the children array can be indexed. 
    inc rcx                                                     ; Increase rcx.

    jmp wordLoop                                                ;   Goto wordLoop.

createChild:
    mov [rsp + counter], rcx                                    ; Saving counter to stack as it is a non savee register.

    call trieAlloc                                              ; Call trieAlloc function, to get a pointer to a trie.

    mov rdi, rax                                                ; Move the pointer into rdi so that you can call trieInit.
    call trieInit                                               ; Initialise the above created trie.

    mov rcx, [rsp + counter]                                    ; Restoring counter from stack.

insertChild:
    mov [r12 + 8*r14], rdi                                      ; Insert the newly allocated and initialised trie into the correct index in the children array.

    jmp nextNode                                                ;   Goto nextNode.

trieInsertFin:
    sub r12, Trie.children                                      ; r12 will now point to the trie.
    add r12, Trie.isWord                                        ; r12 will no be offset such that the isWord array can be indexed.

    mov r13, 1                                                  ;
    mov [r12 + r14], r13                                        ; Inserting 1 into the isWord array at the correct index.

    add rsp, 32                                                 ; Removing reserved space.
    jmp _end                                                    ;   Goto _end.

_end:
    pop r15                                                     ;
    pop r14                                                     ;
    pop r13                                                     ; Restoring the preserved registers.
    pop r12                                                     ;
    pop rbx                                                     ;

    leave                                                       ; Destroying stack frame.
    ret                                                         ; Returning.