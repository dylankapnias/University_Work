    segment .data
hello dq "The quick brown fox jumps over the lazy dog.",0x0a

	segment .text
	global _start
_start:
	mov rdx, 50
	mov rsi, qword hello
	mov rax, 0x1
	mov rdi, 0x1
	syscall
	mov rax,60
	xor rdi, rdi
	syscall