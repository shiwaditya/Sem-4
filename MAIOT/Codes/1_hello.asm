%macro disp 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro




section .data
	msg1 db "Hello:-",10
	msglen1 equ $-msg1
	newline db 10
	msg2 db "Good Morning:-",10
	msglen2 equ $-msg2
	
section .text
	global _start

_start:
	disp 1,1,msg1,msglen1
	disp 1,1,newline,1
	disp 1,1,msg2,msglen2
	disp 60,0,0,0
	
