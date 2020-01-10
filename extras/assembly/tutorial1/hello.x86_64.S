extern printf

	section .data
hello:	db "Hello world!", 0
fmt: 	db "%s", 0xa, 0

	section .text
global main

main:
	push rbp
	mov rdi, fmt
	mov rsi, hello
	mov rax, 0
	call printf
	pop rbp

	mov rax, 0
	ret
