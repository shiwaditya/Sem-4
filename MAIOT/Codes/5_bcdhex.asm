%macro operat 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro


section .data
;BCD TO HEXADECIMAL

digit db 0
temp dw 0
mult dw 0ah
product dw 0
msg1 db "Enter decimal number: ",10
msg1len equ $-msg1

msg2 db "The hexadecimal equivalent is: ",10
msg2len equ $-msg2


section .bss
	num resb 6 

section .text
	global _start
	_start:

	operat 1,1,msg1,msg1len
	operat 0,0,num,6
	mov rsi,num
	mov bp,0ah
	mov dx,0

up:	mov bx,0
	mov ax,word[product]
	mov bl,byte[rsi]
	cmp bl,0ah
	jz skip

	sub bl,30h
	mul bp
	add ax,bx
	mov word[product],ax
	inc rsi
	jmp up
skip:	
	call disp

	operat 0,60,0,0
disp:
	operat 1,1, msg2,msg2len		
	mov ax,word[product]
	mov bp,4

up1: 	rol ax,4
	mov word[temp],ax
	and ax,0fh
	cmp al,09h
	jbe down
	add al,07h
down: 	add al, 30h
	mov byte[digit],al
	operat 1,1,digit,1		
	mov ax,word[temp]
	dec bp
	jnz up1
	ret
