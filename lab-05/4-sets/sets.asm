%include "../io.mac"

section .text
    global main
    extern printf

main:
    ;cele doua multimi se gasesc in eax si ebx
    mov eax, 139
    mov ebx, 169
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime
    PRINTF32 `%u\n\x0`, ebx ; afiseaza cea de-a doua multime
    ;139 - 10001011
    ;169 - 10101001
    ; TODO1: reuniunea a doua multimi
    or eax, ebx
    PRINTF32 `%u\n\x0`, eax

    ; TODO2: adaugarea unui element in multime
    mov eax, 139

    mov edx, 1
    shl edx, 2
    or eax, edx

    mov edx, 1
    shl edx, 4
    or eax, edx
    PRINTF32 `%u\n\x0`, eax
    ; TODO3: intersectia a doua multimi
    mov eax, 139
    and eax, ebx
    PRINTF32 `%u\n\x0`, eax

    ; TODO4: complementul unei multimi
    mov eax, 139
    not eax
    PRINTF32 `%u\n\x0`, eax

    ; TODO5: eliminarea unui element
    mov eax, 139
    mov edx, 1
    shl edx, 1
    not edx
    and eax, edx
    PRINTF32 `%u\n\x0`, eax

    ; TODO6: diferenta de multimi EAX-EBX
    mov eax, 139
    mov ebx, 169
    xor eax, ebx
    PRINTF32 `%u\n\x0`, eax

    xor eax, eax
    ret
