%include "../utils/printf32.asm"

%define NUM 5
   
section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO 1: replace every push by an equivalent sequence of commands (use direct addressing of memory. Hint: esp)
    mov ecx, NUM
push_nums:
    ;push ecx
    sub esp, 4
    mov [esp], ecx
    loop push_nums

    mov ebx, esp
    ;push 0
    sub esp, 4
    xor eax, eax
    mov [esp], eax

    ;push "mere"
    sub esp, 4
    mov edx, esp

    mov eax, "mere"
    mov [esp], eax
    ;push "are "
    sub esp, 4
    mov eax, "are "
    mov [esp], eax
    ;push "Ana "
    sub esp, 4
    mov eax, "Ana "
    mov [esp], eax

    lea esi, [esp]
    PRINTF32 `%s\n\x0`, esi

    ; TODO 2: print the stack in "address: value" format in the range of [ESP:EBP]
    ; use PRINTF32 macro - see format above
    mov eax, esp

address:
    PRINTF32 `%x: %hhu\n\x0`, esp, [esp]
    add esp, 4
    cmp esp, ebp
    jbe address

    ; TODO 3: print the string
    mov esp, eax

print_string:
    PRINTF32 `%x: %hhu\n\x0`, esp, [esp]
    add esp, 4
    cmp esp, edx
    jbe print_string

    ; TODO 4: print the array on the stack, element by element.
    mov esp, ebx
print_array:
    PRINTF32 `%x: %hhu\n\x0`, esp, [esp]
    add esp, 4
    cmp esp, ebp
    jbe print_array
    ; restore the previous value of the EBP (Base Pointer)
    mov esp, ebp

    ; exit without errors
    xor eax, eax
    ret
