
# x86-64 gcc 15.2 with option -m32

makeList:
        push    ebp
        mov     ebp, esp
        sub     esp, 24
        sub     esp, 12
        push    12
        call    malloc
        add     esp, 16
        mov     DWORD PTR [ebp-12], eax
        mov     eax, DWORD PTR [ebp-12]
        leave
        ret
addNode:
        push    ebp
        mov     ebp, esp
        sub     esp, 24
        sub     esp, 12
        push    12
        call    malloc
        add     esp, 16
        mov     DWORD PTR [ebp-12], eax
        sub     esp, 12
        push    DWORD PTR [ebp+12]
        call    strlen
        add     esp, 16
        add     eax, 1
        sub     esp, 12
        push    eax
        call    malloc
        add     esp, 16
        mov     edx, eax
        mov     eax, DWORD PTR [ebp-12]
        mov     DWORD PTR [eax], edx
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax]
        test    eax, eax
        jne     .L4
        mov     eax, DWORD PTR [ebp+8]
        jmp     .L5
.L4:
        sub     esp, 12
        push    DWORD PTR [ebp+12]
        call    strlen
        add     esp, 16
        lea     edx, [eax+1]
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax]
        sub     esp, 4
        push    edx
        push    DWORD PTR [ebp+12]
        push    eax
        call    strncpy
        add     esp, 16
        test    eax, eax
        jne     .L6
        mov     eax, DWORD PTR [ebp+8]
        jmp     .L5
.L6:
        mov     eax, DWORD PTR [ebp-12]
        mov     edx, DWORD PTR [ebp+16]
        mov     DWORD PTR [eax+4], edx
        mov     eax, DWORD PTR [ebp-12]
        mov     edx, DWORD PTR [ebp+8]
        mov     DWORD PTR [eax+8], edx
        mov     eax, DWORD PTR [ebp-12]
.L5:
        leave
        ret
.LC0:
        .string "%s --- %d\n"
stampaLista:
        push    ebp
        mov     ebp, esp
        sub     esp, 24
        cmp     DWORD PTR [ebp+8], 0
        je      .L13
        mov     eax, DWORD PTR [ebp+8]
        mov     DWORD PTR [ebp-12], eax
        jmp     .L10
.L12:
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax]
        test    eax, eax
        je      .L11
        mov     eax, DWORD PTR [ebp-12]
        mov     edx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax]
        sub     esp, 4
        push    edx
        push    eax
        push    OFFSET FLAT:.LC0
        call    printf
        add     esp, 16
.L11:
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax+8]
        mov     DWORD PTR [ebp-12], eax
.L10:
        cmp     DWORD PTR [ebp-12], 0
        jne     .L12
        jmp     .L7
.L13:
        nop
.L7:
        leave
        ret
freeLista:
        push    ebp
        mov     ebp, esp
        sub     esp, 24
        cmp     DWORD PTR [ebp+8], 0
        je      .L19
        mov     eax, DWORD PTR [ebp+8]
        mov     DWORD PTR [ebp-12], eax
        jmp     .L17
.L18:
        mov     eax, DWORD PTR [ebp-12]
        mov     DWORD PTR [ebp-16], eax
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax+8]
        mov     DWORD PTR [ebp-12], eax
        mov     eax, DWORD PTR [ebp-16]
        mov     eax, DWORD PTR [eax]
        sub     esp, 12
        push    eax
        call    free
        add     esp, 16
        sub     esp, 12
        push    DWORD PTR [ebp-16]
        call    free
        add     esp, 16
.L17:
        cmp     DWORD PTR [ebp-12], 0
        jne     .L18
        jmp     .L14
.L19:
        nop
.L14:
        leave
        ret
.LC1:
        .string "ciaone"
main:
        lea     ecx, [esp+4]
        and     esp, -16
        push    DWORD PTR [ecx-4]
        push    ebp
        mov     ebp, esp
        push    ecx
        sub     esp, 20
        mov     DWORD PTR [ebp-24], 1868654947
        mov     DWORD PTR [ebp-20], 25966
        mov     DWORD PTR [ebp-12], 0
        sub     esp, 12
        lea     eax, [ebp-24]
        push    eax
        call    strlen
        add     esp, 16
        add     eax, 1
        sub     esp, 12
        push    eax
        call    malloc
        add     esp, 16
        mov     DWORD PTR [ebp-12], eax
        cmp     DWORD PTR [ebp-12], 0
        jne     .L21
        mov     eax, -1
        jmp     .L25
.L21:
        sub     esp, 12
        lea     eax, [ebp-24]
        push    eax
        call    strlen
        add     esp, 16
        add     eax, 1
        sub     esp, 4
        push    eax
        lea     eax, [ebp-24]
        push    eax
        push    DWORD PTR [ebp-12]
        call    strncpy
        add     esp, 16
        test    eax, eax
        jne     .L23
        mov     eax, -1
        jmp     .L25
.L23:
        sub     esp, 12
        push    DWORD PTR [ebp-12]
        call    free
        add     esp, 16
        mov     DWORD PTR [ebp-12], 0
        call    makeList
        mov     DWORD PTR [ebp-16], eax
        sub     esp, 4
        push    0
        push    OFFSET FLAT:.LC1
        push    DWORD PTR [ebp-16]
        call    addNode
        add     esp, 16
        mov     DWORD PTR [ebp-16], eax
        cmp     DWORD PTR [ebp-16], 0
        jne     .L24
        mov     eax, -1
        jmp     .L25
.L24:
        sub     esp, 12
        push    DWORD PTR [ebp-16]
        call    stampaLista
        add     esp, 16
        sub     esp, 12
        push    DWORD PTR [ebp-16]
        call    freeLista
        add     esp, 16
        mov     DWORD PTR [ebp-16], 0
        mov     eax, 0
.L25:
        mov     ecx, DWORD PTR [ebp-4]
        leave
        lea     esp, [ecx-4]
        ret
