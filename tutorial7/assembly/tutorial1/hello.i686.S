extern printf

	section .data
hello:	db "Hello world!", 0
fmt: 	db "%s", 0xa, 0

	section .text
global main

main:
	push ebp
	mov ebp, esp

	push hello
	push fmt
	call printf
	add esp, 8

	mov esp, ebp
	pop ebp
	mov eax, 0
	ret
