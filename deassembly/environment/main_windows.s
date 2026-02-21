# (C) Antonio Maulucci 2026

	.file	"main.c"
	.intel_syntax noprefix
	.text
	.globl	_makeList
	.def	_makeList;	.scl	2;	.type	32;	.endef
_makeList:
LFB17:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 40
	mov	DWORD PTR [esp], 12
	call	_malloc
	mov	DWORD PTR [ebp-12], eax
	cmp	DWORD PTR [ebp-12], 0
	jne	L2
	mov	eax, 0
	jmp	L3
L2:
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax], 0
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+4], -1
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+8], 0
	mov	eax, DWORD PTR [ebp-12]
L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.globl	_addNode
	.def	_addNode;	.scl	2;	.type	32;	.endef
_addNode:
LFB18:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 40
	mov	DWORD PTR [esp], 12
	call	_malloc
	mov	DWORD PTR [ebp-12], eax
	cmp	DWORD PTR [ebp-12], 0
	jne	L5
	mov	eax, DWORD PTR [ebp+8]
	jmp	L6
L5:
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [esp], eax
	call	_strlen
	add	eax, 1
	mov	DWORD PTR [esp], eax
	call	_malloc
	mov	edx, eax
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax]
	test	eax, eax
	jne	L7
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [esp], eax
	call	_free
	mov	eax, DWORD PTR [ebp+8]
	jmp	L6
L7:
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [esp], eax
	call	_strlen
	lea	edx, [eax+1]
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [esp+8], edx
	mov	edx, DWORD PTR [ebp+12]
	mov	DWORD PTR [esp+4], edx
	mov	DWORD PTR [esp], eax
	call	_strncpy
	test	eax, eax
	jne	L8
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [esp], eax
	call	_free
	mov	eax, DWORD PTR [ebp+8]
	jmp	L6
L8:
	mov	eax, DWORD PTR [ebp-12]
	mov	edx, DWORD PTR [ebp+16]
	mov	DWORD PTR [eax+4], edx
	mov	eax, DWORD PTR [ebp-12]
	mov	edx, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax+8], edx
	mov	eax, DWORD PTR [ebp-12]
L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.globl	_addCoda
	.def	_addCoda;	.scl	2;	.type	32;	.endef
_addCoda:
LFB19:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 40
	cmp	DWORD PTR [ebp+8], 0
	je	L16
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [ebp-12], eax
	mov	DWORD PTR [ebp-16], 0
	jmp	L12
L13:
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [ebp-16], eax
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax+8]
	mov	DWORD PTR [ebp-12], eax
L12:
	cmp	DWORD PTR [ebp-12], 0
	jne	L13
	mov	DWORD PTR [esp], 12
	call	_malloc
	mov	DWORD PTR [ebp-20], eax
	cmp	DWORD PTR [ebp-20], 0
	je	L17
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [esp], eax
	call	_strlen
	add	eax, 1
	mov	DWORD PTR [esp], eax
	call	_malloc
	mov	edx, eax
	mov	eax, DWORD PTR [ebp-20]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR [ebp-20]
	mov	eax, DWORD PTR [eax]
	test	eax, eax
	jne	L15
	mov	eax, DWORD PTR [ebp-20]
	mov	DWORD PTR [esp], eax
	call	_free
	jmp	L9
L15:
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [esp], eax
	call	_strlen
	lea	edx, [eax+1]
	mov	eax, DWORD PTR [ebp-20]
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [esp+8], edx
	mov	edx, DWORD PTR [ebp+12]
	mov	DWORD PTR [esp+4], edx
	mov	DWORD PTR [esp], eax
	call	_memcpy
	mov	eax, DWORD PTR [ebp-20]
	mov	edx, DWORD PTR [ebp+16]
	mov	DWORD PTR [eax+4], edx
	mov	eax, DWORD PTR [ebp-20]
	mov	DWORD PTR [eax+8], 0
	mov	eax, DWORD PTR [ebp-16]
	mov	edx, DWORD PTR [ebp-20]
	mov	DWORD PTR [eax+8], edx
	nop
	jmp	L9
L16:
	nop
	jmp	L9
L17:
	nop
L9:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.section .rdata,"dr"
LC0:
	.ascii "%s --- %d\12\0"
	.text
	.globl	_stampaLista
	.def	_stampaLista;	.scl	2;	.type	32;	.endef
_stampaLista:
LFB20:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 40
	cmp	DWORD PTR [ebp+8], 0
	je	L24
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [ebp-12], eax
	jmp	L21
L23:
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax]
	test	eax, eax
	je	L22
	mov	eax, DWORD PTR [ebp-12]
	mov	edx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [esp+8], edx
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_printf
L22:
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax+8]
	mov	DWORD PTR [ebp-12], eax
L21:
	cmp	DWORD PTR [ebp-12], 0
	jne	L23
	jmp	L18
L24:
	nop
L18:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.globl	_freeLista
	.def	_freeLista;	.scl	2;	.type	32;	.endef
_freeLista:
LFB21:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 40
	cmp	DWORD PTR [ebp+8], 0
	je	L31
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [ebp-12], eax
	jmp	L28
L30:
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [ebp-16], eax
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax+8]
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-16]
	mov	eax, DWORD PTR [eax]
	test	eax, eax
	je	L29
	mov	eax, DWORD PTR [ebp-16]
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [esp], eax
	call	_free
L29:
	mov	eax, DWORD PTR [ebp-16]
	mov	DWORD PTR [esp], eax
	call	_free
L28:
	cmp	DWORD PTR [ebp-12], 0
	jne	L30
	jmp	L25
L31:
	nop
L25:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Running on Winzozz\0"
LC2:
	.ascii "x86 32-bit\0"
LC3:
	.ascii "Sistema operativo: Windows\0"
LC4:
	.ascii "ciaone\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB22:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	and	esp, -16
	sub	esp, 32
	call	___main
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	_puts
	mov	DWORD PTR [esp], OFFSET FLAT:LC2
	call	_puts
	mov	DWORD PTR [esp], OFFSET FLAT:LC3
	call	_puts
	call	_makeList
	mov	DWORD PTR [esp+28], eax
	mov	DWORD PTR [esp+8], 0
	mov	DWORD PTR [esp+4], OFFSET FLAT:LC4
	mov	eax, DWORD PTR [esp+28]
	mov	DWORD PTR [esp], eax
	call	_addNode
	mov	DWORD PTR [esp+28], eax
	cmp	DWORD PTR [esp+28], 0
	jne	L33
	mov	eax, -1
	jmp	L34
L33:
	mov	eax, DWORD PTR [esp+28]
	mov	DWORD PTR [esp], eax
	call	_stampaLista
	mov	eax, DWORD PTR [esp+28]
	mov	DWORD PTR [esp], eax
	call	_freeLista
	mov	DWORD PTR [esp+28], 0
	mov	eax, 0
L34:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_strncpy;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
