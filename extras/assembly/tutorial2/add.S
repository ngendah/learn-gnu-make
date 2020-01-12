	section .text
    global add
add:
	push ebp
	mov ebp, esp

	mov eax, [ebp+8] ; first argument
	add eax, [ebp+12] ; second argument

	mov esp, ebp
	pop ebp
	ret
