section .data
    msg db "Sorted array is :", 10
    msglen equ $-msg
    arr db 05h, 0Ah, 75h, 0D3h, 12h

%macro operate 4
    mov rax, %1
    mov rdi, %2
    mov rsi, %3
    mov rdx, %4
    syscall
%endmacro

section .bss
    result resb 15

section .text
    global _start:
    _start:
        ; Sort the array using Bubble Sort
        mov rdi, arr
        mov bl, 5 ; outer loop runs for n times
        loop_outer:
            mov cl, 4 ; inner loop runs n-1 times
            mov rsi, arr
        up:
            mov al, byte[rsi]
            cmp al, byte[rsi + 1]
            jbe only_inc ; no swapping
            xchg al, byte[rsi + 1] ; swap
            mov byte[rsi], al
        only_inc:
            inc rsi
            dec cl ; decrementing inner loop
            jnz up
            dec bl ; decrementing outer loop
            jnz loop_outer
        
        ; Print the sorted array
        operate 1, 1, msg, msglen
        mov rdi, arr
        mov rsi, result
        mov dl, 10 ; for one number there are two digits
        disp_loop1:
            mov cl, 2
            mov al, [rdi]
        againx:
            rol al, 4 ; rotate by 4
            mov bl, al
            and al, 0Fh
            cmp al, 09h
            jbe downx
            add al, 07h
        downx:
            add al, 30h
            mov byte[rsi], al
            mov al, bl
            inc rsi
            dec cl
            jnz againx
            mov byte [rsi], 0Ah ; inserting enter
            inc rsi
            inc rdi ; result
            dec dl
            jnz disp_loop1
        operate 1, 1, result, 15
        operate 60, 0, 0, 0

