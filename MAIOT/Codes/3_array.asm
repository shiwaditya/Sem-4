section .data
;ARRAY ADDTION WITHOUT USING USER INPUT
Narray db 11h,12h,13h,14h,15h

msg db "Result of array addition is:",10
msglen equ $-msg
newline db 10

section .bss
result resw 1
temp resw 2
temp1 resb 1

%macro rw 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .text
global _start
_start:
mov rsi,Narray
mov ax,00h
mov bx,0h
mov cx,5
    up2:mov bl,byte[rsi]
add ax,bx
jnc skip
inc ah
    skip:
inc rsi
dec cx
jnz up2
mov word[result],ax
rw 1,1,msg,msglen
rw 1,1,newline,1

call disp

mov rax,60
mov rdi,0
   syscall
disp:
mov bp,4
mov ax,word[result]
up1:
rol ax,4
mov[temp],ax
and ax,0fh
cmp al,09
jbe down1
add al,07

down1:
add al,30h
mov[temp1],al
rw 1,1,temp1,1
mov ax,word[temp]
dec bp
jnz up1
ret

			
/* section .text
	global _start
	_start:
These lines define the start of the code section and the global "_start" label, which is the entry point for the program.


		mov rsi,num_Array
		mov ax,00h
		mov bx,0h
		mov cx,5
These lines initialize the "rsi" register with the address of the "num_Array" variable, "ax" and "bx" with zero, and "cx" with the value 5. These registers will be used in the loop to iterate through the array and perform the addition operation.



		up:
			mov bl,byte[rsi]
			add ax,bx
			jnc skip
			inc ah
		skip:
			inc rsi
			dec cx
			jnz up
This block of code defines a loop that iterates through the "num_Array" byte array and adds each value to the "ax" register. If the addition operation produces a carry, the "ah" register is incremented. This loop will run 5 times, decrementing "cx" each time, until "cx" becomes zero.



		mov word[result],ax
This line stores the result of the addition operation in the "result" word variable.




		disp 1,1,msg,msglen
This line calls the "disp" macro to display a message on the console. The "1,1" arguments specify the system call number and the destination file descriptor (stdout), and "msg" and "msglen" are the message string and its length, respectively.



		mov dx,word[result]
		mov bp,4
		up1:
			rol dx,4
			mov bx,dx
			and dx,0Fh
			cmp dx,09h
			jbe down
			add dx,07h
		down:
			add dx,30h
			mov byte[temp1],dl
			disp 1,1,temp1,1
			mov dx,bx
			dec bp
			jnz up1
This block of code converts the result in "result" from hexadecimal to decimal format and displays it on the console. The "dx" register holds the current value being processed, and the loop uses bit rotation and masking operations to extract each digit and convert it to its corresponding ASCII code. The converted digits are stored in the "temp1" byte variable, and the "disp" macro is called to display each digit on the console.



		disp 1,1,newline,1
		disp 60,0,0,0
These two lines call the "disp" macro to display a newline character and exit the program by calling the "exit" system call with a code of 0.*/