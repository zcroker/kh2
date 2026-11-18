# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/001ca060.cpp
#     No symbol, written as literal lui/lo values: 0x0036e0cc
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001ca060,"ax",@progbits
	.align 3
	.globl func_001ca060
	.type func_001ca060, @function
	.ent func_001ca060
func_001ca060:
	addiu	$29,$29,-64
	lw	$15,1416($6)
	sd	$17,40($29)
	sd	$16,32($29)
	andi	$15,$15,0x80
	sd	$18,48($29)
	sd	$31,56($29)
	beqz	$15,.L001ca134
	move	$17,$4
	lui	$15,%hi(D_00351f34)
	lw	$14,%lo(D_00351f34)($15)
	lwc1	$f2,40($14)
.L001ca090:
	lwc1	$f0,28($6)
	addiu	$16,$29,16
	addiu	$15,$6,16
	lqc2	$vf1,0($15)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($16)
	beq	$29,$16,.L001ca0c4
	lwc1	$f0,8($29)
	lq	$8,0($16)
	sq	$8,0($29)
	lwc1	$f0,8($29)
.L001ca0c4:
	move	$4,$16
	lwc1	$f1,40($6)
	move	$5,$29
	lwc1	$f12,1644($6)
	sub.s	$f1,$f1,$f0
	mul.s	$f1,$f1,$f2
	add.s	$f0,$f0,$f1
	swc1	$f0,40($6)
	jal	func_0017d538
	swc1	$f0,8($29)
	beq	$29,$16,.L001ca100
	lui	$15,0x35
	lq	$8,0($16)
	sq	$8,0($29)
	lui	$15,%hi(D_00349e10)
.L001ca100:
	lwc1	$f0,%lo(D_00349e10)($15)
	lqc2	$vf1,0($29)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($17)
	move	$2,$17
	ld	$16,32($29)
	ld	$17,40($29)
	ld	$18,48($29)
	ld	$31,56($29)
	jr	$31
	addiu	$29,$29,64
.L001ca134:
	lui	$15,0x37
	addiu	$15,$15,-7988
	b	.L001ca090
	lwc1	$f2,0($15)
	nop
	.end func_001ca060
	.size func_001ca060, 232
