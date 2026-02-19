
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
        cmp     DWORD PTR [ebp-12], 0
        jne     .L2
        mov     eax, 0
        jmp     .L3
.L2:
        mov     eax, DWORD PTR [ebp-12]
        mov     DWORD PTR [eax], 0
        mov     eax, DWORD PTR [ebp-12]
        mov     DWORD PTR [eax+4], -1
        mov     eax, DWORD PTR [ebp-12]
        mov     DWORD PTR [eax+8], 0
        mov     eax, DWORD PTR [ebp-12]
.L3:
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
        cmp     DWORD PTR [ebp-12], 0
        jne     .L5
        mov     eax, DWORD PTR [ebp+8]
        jmp     .L6
.L5:
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
        jne     .L7
        sub     esp, 12
        push    DWORD PTR [ebp-12]
        call    free
        add     esp, 16
        mov     eax, DWORD PTR [ebp+8]
        jmp     .L6
.L7:
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
        jne     .L8
        sub     esp, 12
        push    DWORD PTR [ebp-12]
        call    free
        add     esp, 16
        mov     eax, DWORD PTR [ebp+8]
        jmp     .L6
.L8:
        mov     eax, DWORD PTR [ebp-12]
        mov     edx, DWORD PTR [ebp+16]
        mov     DWORD PTR [eax+4], edx
        mov     eax, DWORD PTR [ebp-12]
        mov     edx, DWORD PTR [ebp+8]
        mov     DWORD PTR [eax+8], edx
        mov     eax, DWORD PTR [ebp-12]
.L6:
        leave
        ret
addCoda:
        push    ebp
        mov     ebp, esp
        sub     esp, 24
        cmp     DWORD PTR [ebp+8], 0
        je      .L16
        mov     eax, DWORD PTR [ebp+8]
        mov     DWORD PTR [ebp-12], eax
        mov     DWORD PTR [ebp-16], 0
        jmp     .L12
.L13:
        mov     eax, DWORD PTR [ebp-12]
        mov     DWORD PTR [ebp-16], eax
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax+8]
        mov     DWORD PTR [ebp-12], eax
.L12:
        cmp     DWORD PTR [ebp-12], 0
        jne     .L13
        sub     esp, 12
        push    12
        call    malloc
        add     esp, 16
        mov     DWORD PTR [ebp-20], eax
        cmp     DWORD PTR [ebp-20], 0
        je      .L17
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
        mov     eax, DWORD PTR [ebp-20]
        mov     DWORD PTR [eax], edx
        mov     eax, DWORD PTR [ebp-20]
        mov     eax, DWORD PTR [eax]
        test    eax, eax
        jne     .L15
        sub     esp, 12
        push    DWORD PTR [ebp-20]
        call    free
        add     esp, 16
        jmp     .L9
.L15:
        sub     esp, 12
        push    DWORD PTR [ebp+12]
        call    strlen
        add     esp, 16
        lea     edx, [eax+1]
        mov     eax, DWORD PTR [ebp-20]
        mov     eax, DWORD PTR [eax]
        sub     esp, 4
        push    edx
        push    DWORD PTR [ebp+12]
        push    eax
        call    memcpy
        add     esp, 16
        mov     eax, DWORD PTR [ebp-20]
        mov     edx, DWORD PTR [ebp+16]
        mov     DWORD PTR [eax+4], edx
        mov     eax, DWORD PTR [ebp-20]
        mov     DWORD PTR [eax+8], 0
        mov     eax, DWORD PTR [ebp-16]
        mov     edx, DWORD PTR [ebp-20]
        mov     DWORD PTR [eax+8], edx
        jmp     .L9
.L16:
        nop
        jmp     .L9
.L17:
        nop
.L9:
        leave
        ret
.LC0:
        .string "%s --- %d\n"
stampaLista:
        push    ebp
        mov     ebp, esp
        sub     esp, 24
        cmp     DWORD PTR [ebp+8], 0
        je      .L24
        mov     eax, DWORD PTR [ebp+8]
        mov     DWORD PTR [ebp-12], eax
        jmp     .L21
.L23:
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax]
        test    eax, eax
        je      .L22
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
.L22:
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax+8]
        mov     DWORD PTR [ebp-12], eax
.L21:
        cmp     DWORD PTR [ebp-12], 0
        jne     .L23
        jmp     .L18
.L24:
        nop
.L18:
        leave
        ret
freeLista:
        push    ebp
        mov     ebp, esp
        sub     esp, 24
        cmp     DWORD PTR [ebp+8], 0
        je      .L31
        mov     eax, DWORD PTR [ebp+8]
        mov     DWORD PTR [ebp-12], eax
        jmp     .L28
.L30:
        mov     eax, DWORD PTR [ebp-12]
        mov     DWORD PTR [ebp-16], eax
        mov     eax, DWORD PTR [ebp-12]
        mov     eax, DWORD PTR [eax+8]
        mov     DWORD PTR [ebp-12], eax
        mov     eax, DWORD PTR [ebp-16]
        mov     eax, DWORD PTR [eax]
        test    eax, eax
        je      .L29
        mov     eax, DWORD PTR [ebp-16]
        mov     eax, DWORD PTR [eax]
        sub     esp, 12
        push    eax
        call    free
        add     esp, 16
.L29:
        sub     esp, 12
        push    DWORD PTR [ebp-16]
        call    free
        add     esp, 16
.L28:
        cmp     DWORD PTR [ebp-12], 0
        jne     .L30
        jmp     .L25
.L31:
        nop
.L25:
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
        jne     .L33
        mov     eax, -1
        jmp     .L37
.L33:
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
        jne     .L35
        mov     eax, -1
        jmp     .L37
.L35:
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
        jne     .L36
        mov     eax, -1
        jmp     .L37
.L36:
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
.L37:
        mov     ecx, DWORD PTR [ebp-4]
        leave
        lea     esp, [ecx-4]
        ret
