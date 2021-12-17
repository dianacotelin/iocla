%include "../utils/printf32.asm"
section .data
    before_format db "before %s", 13, 10, 0
    after_format db "after %s", 13, 10, 0
    mystring db "abcdefghijABD", 0

section .text

extern printf
global main

toupper:
    push ebp
    mov ebp, esp
    mov ecx, 8
    mov eax, [ebp+8]
etti:
    mov bl, byte [eax]
    cmp ebx, 0
    je final
    cmp ebx, 0x61
    inc eax
    jb etti
    
cont:
    dec eax
    sub ebx, 0x20
    mov byte [eax], bl
    inc eax
    jmp etti
final:

    ;add esp, 4
    inc ecx





    ; TODO

    leave
    ret

main:
    push ebp
    mov ebp, esp

    push mystring
    push before_format
    call printf
    add esp, 8

    push mystring
    call toupper
    add esp, 4

    push mystring
    push after_format
    call printf
    add esp, 8

    leave
    ret
