%macro rw 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data
;HARDCODED INPUT 
	msg db "ENTER THE HEX NUMBER:",10
	msglen equ $-msg
	msg1 db "THE BCD NUMBER IS:",10
	msg1len equ $-msg1
	hexno dw 00FFh

section .bss
	count resb 1
	temp resb 1
	num resw 5

section .text
global _start
_start:

	mov ax,word[hexno]
	mov bx,0AH
up:
	mov dx,0
	div bx
	push dx
	inc byte[count]
	cmp ax,0
	jnz up
	rw 1,1,msg1,msg1len
up1:
	pop dx
	add dl,30h
	mov [temp],dl
	rw 1,1,temp,1
	dec byte[count]
	jnz up1

rw 60,0,0,0
