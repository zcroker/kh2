# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002d9f10_perm105.c, ledger best/002d9f10_unit.cpp
#   002d9f10 (L47, 2026-11-18): near-miss 2 permuter 40 min (VU helpers in header), 220->105; literal load scheduled before the vector stores; best/002d9f10_perm105.c
#     No symbol, written as literal lui/lo values: 0x00375ce0, 0x00375ce4, 0x00375ce8
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002d9f10,"ax",@progbits
	.align 3
	.globl func_002d9f10
	.type func_002d9f10, @function
	.ent func_002d9f10
func_002d9f10:
	addiu	$29,$29,-64
	sd	$16,16($29)
	sd	$17,24($29)
	sd	$18,32($29)
	move	$16,$4
	sd	$31,40($29)
	addiu	$17,$4,16
	swc1	$f20,48($29)
	vsub.wxyz	$vf1,$vf0,$vf0
	sqc2	$vf1,0($17)
	lui	$15,%hi(D_00361f60)
	lw	$18,%lo(D_00361f60)($15)
	beqzl	$18,.L002da018
	ld	$16,16($29)
	lbu	$15,3068($4)
	bnezl	$15,.L002da018
	ld	$16,16($29)
	jal	func_002d8898
	move	$4,$18
	beqz	$2,.L002da014
	lui	$15,0x37
	lw	$14,2884($16)
	mtc1	$0,$f0
	addiu	$15,$15,23776
	lwc1	$f1,2608($14)
	swc1	$f0,12($29)
	swc1	$f1,0($29)
	swc1	$f0,4($29)
	swc1	$f0,8($29)
	lwc1	$f20,0($15)
	lw	$15,8($14)
	andi	$15,$15,0x4
	beqz	$15,.L002da030
	nop
	jal	func_002d73f0
	move	$4,$18
	lwc1	$f0,8($2)
.L002d9fa4:
	mul.s	$f20,$f0,$f20
	lui	$15,%hi(D_00349e10)
	lwc1	$f0,%lo(D_00349e10)($15)
	lui	$15,0x37
	mul.s	$f0,$f20,$f0
	addiu	$15,$15,23780
	lwc1	$f1,0($15)
	mul.s	$f0,$f0,$f1
	lqc2	$vf1,0($29)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($29)
	jal	func_002d8900
	move	$4,$18
	bnez	$2,.L002da004
	lui	$15,0x37
	addiu	$15,$15,23784
	lwc1	$f0,0($15)
	lqc2	$vf1,0($29)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($29)
.L002da004:
	beq	$17,$29,.L002da018
	ld	$16,16($29)
	lq	$8,0($29)
	sq	$8,0($17)
.L002da014:
	ld	$16,16($29)
.L002da018:
	ld	$17,24($29)
	ld	$18,32($29)
	ld	$31,40($29)
	lwc1	$f20,48($29)
	jr	$31
	addiu	$29,$29,64
.L002da030:
	jal	func_002d73f0
	move	$4,$18
	b	.L002d9fa4
	lwc1	$f0,4($2)
	.end func_002d9f10
	.size func_002d9f10, 304
