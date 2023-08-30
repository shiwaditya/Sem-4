section .data
;ARRAY ADDITION OF USER INPUT

arr times 54 db 0
msg1 db "Element of array adition is",10
msglen1 equ $-msg1

msg db"Result of array additon is",10
msglen equ $-msg

cnt db 5
temp1 db 0

section .bss
result resw 1
temp resw 2
;temp1 resb 1
num resb 3

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

mov rbp,arr

nextnum:rw 1,1,msg1,msglen1
rw 0,0,num,3
mov rcx,0
mov rax,0
mov rsi,num
up1: mov cl,byte[rsi]
cmp cl,0AH
je packed
cmp cl,39h
jbe down1
sub cl,07h
down1: sub cl,30H
rol al,4
add al,cl
inc rsi
jmp up1

packed: mov byte[rbp],al
inc rbp
dec byte[cnt]
jnz nextnum

mov rsi,arr
mov ax,00h
mov bx,0h
mov cx,5

up2: mov bl,byte[rsi]
add ax,bx
jnc skip
inc ah

skip:
inc rsi
dec cx
jnz up2

mov word[Result],ax
mov ax,word[Result]
mov bp,4
up: rol ax,4
mov bx,ax
and ax,0Fh
cmp al,09
jbe down
add al,07h
down:Add al,30h
mov byte[temp],al
rw 1,1,temp,1
mov ax,bx
dec bp
jnz up
rw 60,0,0,0


