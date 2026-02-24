.LC0:
        .string "[debug logger.logger] Connessione sulla socket %d\n"
.LC1:
        .string "Ricevuta connessione da IP: %s\n"
.LC2:
        .string "Il contenuto ricevuto finora e': %s di dimensione %zu\n"
main:
        lea     ecx, [esp+4]
        and     esp, -16
        push    DWORD PTR [ecx-4]
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
        sub     esp, 1088
        sub     esp, 4
        push    1024
        push    0
        lea     eax, [ebp-1056]
        push    eax
        call    memset
        add     esp, 16
        test    eax, eax
        sete    al
        test    al, al
        je      .L2
        sub     esp, 12
        push    1
        call    exit
.L2:
        mov     DWORD PTR [ebp-1076], 16
        mov     DWORD PTR [ebp-16], -1
        mov     DWORD PTR [ebp-20], 0
        mov     DWORD PTR [ebp-24], 8883
        sub     esp, 4
        push    0
        push    1
        push    2
        call    socket
        add     esp, 16
        mov     DWORD PTR [ebp-28], eax
        cmp     DWORD PTR [ebp-28], 0
        jns     .L3
        mov     eax, 1
        jmp     .L17
.L3:
        sub     esp, 4
        push    16
        push    0
        lea     eax, [ebp-1092]
        push    eax
        call    memset
        add     esp, 16
        test    eax, eax
        sete    al
        test    al, al
        je      .L5
        sub     esp, 12
        push    1
        call    exit
.L5:
        mov     WORD PTR [ebp-1092], 2
        sub     esp, 12
        push    0
        call    htonl
        add     esp, 16
        mov     DWORD PTR [ebp-1088], eax
        mov     eax, DWORD PTR [ebp-24]
        movzx   eax, ax
        sub     esp, 12
        push    eax
        call    htons
        add     esp, 16
        mov     WORD PTR [ebp-1090], ax
        sub     esp, 4
        push    16
        lea     eax, [ebp-1092]
        push    eax
        push    DWORD PTR [ebp-28]
        call    bind
        add     esp, 16
        shr     eax, 31
        test    al, al
        je      .L6
        mov     eax, 1
        jmp     .L17
.L6:
        sub     esp, 8
        push    256
        push    DWORD PTR [ebp-28]
        call    listen
        add     esp, 16
        test    eax, eax
        setne   al
        test    al, al
        je      .L7
        mov     eax, 1
        jmp     .L17
.L7:
        sub     esp, 4
        lea     eax, [ebp-1076]
        push    eax
        lea     eax, [ebp-1072]
        push    eax
        push    DWORD PTR [ebp-28]
        call    accept
        add     esp, 16
        mov     DWORD PTR [ebp-16], eax
        sub     esp, 12
        push    DWORD PTR [ebp-1068]
        call    inet_ntoa
        add     esp, 16
        sub     esp, 12
        push    eax
        call    strlen
        add     esp, 16
        add     eax, 1
        sub     esp, 12
        push    eax
        call    malloc
        add     esp, 16
        mov     DWORD PTR [ebp-20], eax
        cmp     DWORD PTR [ebp-20], 0
        jne     .L8
        mov     eax, 1
        jmp     .L17
.L8:
        sub     esp, 12
        push    DWORD PTR [ebp-1068]
        call    inet_ntoa
        add     esp, 16
        sub     esp, 8
        push    eax
        push    DWORD PTR [ebp-20]
        call    strcpy
        add     esp, 16
        test    eax, eax
        sete    al
        test    al, al
        je      .L9
        mov     eax, 1
        jmp     .L17
.L9:
        sub     esp, 8
        push    DWORD PTR [ebp-16]
        push    OFFSET FLAT:.LC0
        call    printf
        add     esp, 16
        sub     esp, 8
        push    DWORD PTR [ebp-20]
        push    OFFSET FLAT:.LC1
        call    printf
        add     esp, 16
        sub     esp, 12
        push    DWORD PTR [ebp-28]
        call    close
        add     esp, 16
        test    eax, eax
        setne   al
        test    al, al
        je      .L10
        mov     eax, 1
        jmp     .L17
.L10:
        mov     DWORD PTR [ebp-32], 0
        sub     esp, 12
        push    1
        call    malloc
        add     esp, 16
        mov     DWORD PTR [ebp-12], eax
        cmp     DWORD PTR [ebp-12], 0
        jne     .L11
        sub     esp, 12
        push    1
        call    exit
.L11:
        mov     eax, DWORD PTR [ebp-12]
        mov     BYTE PTR [eax], 0
        jmp     .L12
.L15:
        lea     edx, [ebp-1056]
        mov     eax, DWORD PTR [ebp-32]
        add     eax, edx
        mov     BYTE PTR [eax], 0
        sub     esp, 12
        push    DWORD PTR [ebp-12]
        call    strlen
        add     esp, 16
        mov     ebx, eax
        sub     esp, 12
        lea     eax, [ebp-1056]
        push    eax
        call    strlen
        add     esp, 16
        add     eax, ebx
        add     eax, 2
        sub     esp, 8
        push    eax
        push    DWORD PTR [ebp-12]
        call    realloc
        add     esp, 16
        mov     DWORD PTR [ebp-12], eax
        cmp     DWORD PTR [ebp-12], 0
        jne     .L13
        sub     esp, 12
        push    1
        call    exit
.L13:
        sub     esp, 8
        lea     eax, [ebp-1056]
        push    eax
        push    DWORD PTR [ebp-12]
        call    strcat
        add     esp, 16
        test    eax, eax
        sete    al
        test    al, al
        je      .L14
        sub     esp, 12
        push    1
        call    exit
.L14:
        sub     esp, 12
        push    DWORD PTR [ebp-12]
        call    strlen
        add     esp, 16
        sub     esp, 4
        push    eax
        push    DWORD PTR [ebp-12]
        push    OFFSET FLAT:.LC2
        call    printf
        add     esp, 16
        sub     esp, 4
        push    1024
        push    0
        lea     eax, [ebp-1056]
        push    eax
        call    memset
        add     esp, 16
        test    eax, eax
        sete    al
        test    al, al
        je      .L12
        sub     esp, 12
        push    1
        call    exit
.L12:
        push    0
        push    1023
        lea     eax, [ebp-1056]
        push    eax
        push    DWORD PTR [ebp-16]
        call    recv
        add     esp, 16
        mov     DWORD PTR [ebp-32], eax
        cmp     DWORD PTR [ebp-32], 0
        setne   al
        test    al, al
        jne     .L15
        sub     esp, 12
        push    DWORD PTR [ebp-16]
        call    close
        add     esp, 16
        test    eax, eax
        setne   al
        test    al, al
        je      .L16
        mov     eax, 1
        jmp     .L17
.L16:
        mov     eax, 0
.L17:
        lea     esp, [ebp-8]
        pop     ecx
        pop     ebx
        pop     ebp
        lea     esp, [ecx-4]
        ret
