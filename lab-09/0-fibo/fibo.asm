%include "../utils/printf32.asm"

%define NUM_FIBO 10

section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO - replace below instruction with the algorithm for the Fibonacci sequence
    ;sub esp, NUM_FIBO * 4
    mov ecx, NUM_FIBO
    mov eax, 1
    mov ebx, 1
    mov edx, 0
fibo:
    ;mov eax, 
    ;push 0
    mov edx, eax
    push eax
    mov eax, ebx
    add edx, ebx
    mov ebx, edx

    loop fibo




    mov ecx, NUM_FIBO
print:
    mov eax, dword [esp + (ecx - 1) * 4]
    PRINTF32 `%d \x0`, eax
    dec ecx
    cmp ecx, 0
    ja print

    PRINTF32 `\n\x0`
    mov esp, ebp
    xor eax, eax
    ret
