# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/001c6a28_unit.cpp
#     No symbol, written as literal lui/lo values: 0x0036df4c, 0x0036df50, 0x0036df54, 0x0036df58, 0x0036df5c, 0x0036df60, 0x0036df64, 0x0036df68, 0x01d49830, 0x01d498a8
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001c6a28,"ax",@progbits
	.align 3
	.globl func_001c6a28
	.type func_001c6a28, @function
	.ent func_001c6a28
func_001c6a28:
	addiu	$29,$29,-112
	lui	$13,%hi(D_003638d0)
	sd	$17,88($29)
	lui	$15,0x1
	sd	$16,80($29)
	ori	$15,$15,0xdcd
	sd	$31,96($29)
	move	$17,$4
	move	$12,$29
	lw	$14,%lo(D_003638d0)($13)
	mult	$15,$14,$15
	bltz	$15,.L001c6c40
	sw	$15,%lo(D_003638d0)($13)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
.L001c6a64:
	lui	$13,%hi(D_003638d0)
	lui	$15,0x1
	lw	$14,%lo(D_003638d0)($13)
	lui	$11,0x37
	addiu	$11,$11,-8372
	ori	$15,$15,0xdcd
	lwc1	$f1,0($11)
	mult	$15,$14,$15
	mul.s	$f1,$f0,$f1
	lui	$11,0x37
	addiu	$11,$11,-8364
	lui	$14,0x37
	sw	$15,%lo(D_003638d0)($13)
	addiu	$14,$14,-8368
	lwc1	$f0,0($14)
	mul.s	$f1,$f1,$f0
	lwc1	$f0,0($11)
	bltz	$15,.L001c6c24
	add.s	$f0,$f0,$f1
	mtc1	$15,$f2
	cvt.s.w	$f2,$f2
.L001c6ab8:
	swc1	$f0,0($12)
	lui	$14,0x37
	lui	$11,0x37
	sw	$0,4($12)
	addiu	$14,$14,-8372
	addiu	$11,$11,-8360
	lwc1	$f0,0($11)
	lui	$15,0x1d5
	lwc1	$f1,0($14)
	addiu	$15,$15,-26576
	swc1	$f0,12($12)
	lui	$11,0x37
	mul.s	$f1,$f2,$f1
	addiu	$11,$11,-8356
	lwc1	$f0,0($11)
	addiu	$6,$29,16
	addiu	$16,$29,32
	addiu	$14,$29,64
	mul.s	$f1,$f1,$f0
	neg.s	$f1,$f1
	swc1	$f1,8($12)
	lqc2	$vf5,0($29)
	lqc2	$vf1,0($15)
	lqc2	$vf2,16($15)
	lqc2	$vf3,32($15)
	lqc2	$vf4,48($15)
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	sqc2	$vf5,0($14)
	beq	$29,$14,.L001c6b44
	nop
	lq	$8,0($14)
	sq	$8,0($29)
.L001c6b44:
	beq	$6,$29,.L001c6b58
	lui	$14,0x37
	lq	$8,0($29)
	sq	$8,0($6)
	lui	$14,0x37
.L001c6b58:
	lui	$15,0x37
	addiu	$14,$14,-8352
	addiu	$15,$15,-8348
	lwc1	$f0,0($14)
	move	$4,$16
	move	$5,$29
	li	$7,1
	swc1	$f0,4($29)
	lwc1	$f0,0($15)
	jal	func_001d35e0
	swc1	$f0,20($29)
	beqzl	$2,.L001c6c14
	ld	$16,80($29)
	jal	func_001d36e8
	move	$4,$16
	li	$15,1
	bnel	$2,$15,.L001c6c14
	ld	$16,80($29)
	beq	$29,$16,.L001c6bb4
	lui	$11,0x37
	lq	$8,0($16)
	sq	$8,0($29)
	lui	$11,0x37
.L001c6bb4:
	lwc1	$f0,4($29)
	addiu	$11,$11,-8344
	lwc1	$f1,0($11)
	sub.s	$f0,$f0,$f1
	beq	$17,$29,.L001c6bd4
	swc1	$f0,4($29)
	lq	$8,0($29)
	sq	$8,0($17)
.L001c6bd4:
	lui	$15,%hi(D_01d498b0)
	lui	$16,0x1d5
	lw	$13,%lo(D_01d498b0)($15)
	lw	$14,-26456($16)
	li	$15,1000
	subu	$15,$15,$13
	slt	$14,$14,$15
	beqzl	$14,.L001c6c14
	ld	$16,80($29)
	jal	func_001c5f90
	move	$4,$17
	beqz	$2,.L001c6c10
	lw	$15,-26456($16)
	addiu	$15,$15,1
	sw	$15,-26456($16)
.L001c6c10:
	ld	$16,80($29)
.L001c6c14:
	ld	$17,88($29)
	ld	$31,96($29)
	jr	$31
	addiu	$29,$29,112
.L001c6c24:
	srl	$14,$15,0x1
	andi	$15,$15,0x1
	or	$15,$15,$14
	mtc1	$15,$f2
	cvt.s.w	$f2,$f2
	b	.L001c6ab8
	add.s	$f2,$f2,$f2
.L001c6c40:
	srl	$14,$15,0x1
	andi	$15,$15,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L001c6a64
	add.s	$f0,$f0,$f0
	nop
	.end func_001c6a28
	.size func_001c6a28, 568
