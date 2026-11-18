# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/0020cfd8_perm1900.c, ledger best/0020cfd8_unit.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0020cfd8,"ax",@progbits
	.align 3
	.globl func_0020cfd8
	.type func_0020cfd8, @function
	.ent func_0020cfd8
func_0020cfd8:
	lui	$15,%hi(D_01d9ea9c)
	lw	$14,%lo(D_01d9ea9c)($15)
	bnez	$14,.L0020d16c
	lui	$14,%hi(D_01d9e6e0)
	lw	$13,%lo(D_01d9e6e0)($14)
	li	$14,255
	ld	$15,168($13)
	dsll32	$14,$14,0x0
	ori	$14,$14,0xff00
	and	$15,$15,$14
	bnez	$15,.L0020d16c
	nop
	lw	$14,12($6)
	lw	$12,12($4)
	lw	$15,0($14)
	lw	$13,0($5)
	addu	$4,$4,$15
	bne	$13,$12,.L0020d0e4
	addiu	$15,$4,160
	lwc1	$f1,28($5)
	lwc1	$f0,24($15)
	lwc1	$f3,32($5)
	add.s	$f0,$f0,$f1
	lwc1	$f4,36($5)
	lwc1	$f2,28($15)
	lwc1	$f5,12($15)
	lwc1	$f1,32($15)
	add.s	$f2,$f2,$f3
	add.s	$f1,$f1,$f4
	swc1	$f0,24($15)
	lwc1	$f6,36($15)
	swc1	$f2,28($15)
	swc1	$f1,32($15)
	lwc1	$f0,16($5)
	lwc1	$f2,20($5)
	lwc1	$f1,24($5)
	lwc1	$f3,16($15)
	lwc1	$f4,20($15)
	add.s	$f3,$f3,$f2
	add.s	$f5,$f5,$f0
	add.s	$f4,$f4,$f1
	lwc1	$f7,40($15)
	swc1	$f3,16($15)
	swc1	$f5,12($15)
	swc1	$f4,20($15)
	lwc1	$f0,4($5)
	lwc1	$f2,8($5)
	lwc1	$f1,12($5)
	lwc1	$f8,44($15)
	add.s	$f6,$f6,$f0
	add.s	$f7,$f7,$f2
	add.s	$f8,$f8,$f1
	lwc1	$f3,56($15)
	swc1	$f6,36($15)
	swc1	$f7,40($15)
	swc1	$f8,44($15)
	lwc1	$f0,48($15)
	lwc1	$f1,40($5)
	lwc1	$f2,52($15)
	add.s	$f0,$f0,$f1
	swc1	$f0,48($15)
	lwc1	$f1,44($5)
	add.s	$f2,$f2,$f1
	swc1	$f2,52($15)
	lwc1	$f0,48($5)
	add.s	$f3,$f3,$f0
	swc1	$f3,56($15)
.L0020d0e4:
	lwc1	$f5,12($15)
	lwc1	$f6,16($15)
	lwc1	$f0,24($15)
	lwc1	$f1,28($15)
	add.s	$f5,$f5,$f0
	add.s	$f6,$f6,$f1
	lwc1	$f7,20($15)
	lwc1	$f2,32($15)
	lwc1	$f0,56($15)
	add.s	$f7,$f7,$f2
	lwc1	$f1,52($15)
	lwc1	$f4,36($15)
	add.s	$f1,$f1,$f0
	lwc1	$f3,40($15)
	lwc1	$f2,44($15)
	add.s	$f4,$f4,$f5
	add.s	$f3,$f3,$f6
	add.s	$f2,$f2,$f7
	lwc1	$f0,48($15)
	swc1	$f4,36($15)
	add.s	$f0,$f0,$f1
	swc1	$f3,40($15)
	swc1	$f2,44($15)
	swc1	$f5,12($15)
	mul.s	$f2,$f2,$f0
	mul.s	$f4,$f4,$f0
	mul.s	$f3,$f3,$f0
	swc1	$f6,16($15)
	swc1	$f7,20($15)
	swc1	$f1,52($15)
	swc1	$f0,48($15)
	swc1	$f2,8($15)
	swc1	$f4,160($4)
	swc1	$f3,4($15)
.L0020d16c:
	jr	$31
	nop
	nop
	.end func_0020cfd8
	.size func_0020cfd8, 416
