# Whole-function assembly (last step of the README ladder, 2026-11-10, zl90 w3899, carried over from w3889).
#   func_001f0a38: model render request setup, sibling of func_001f0600 (also whole asm, w3883).
#   Closest C: coord/best/001f0a38_w3851_nsa.c (21 lines under _nsa). The blocker is the sched1/sched2
#   order of the D_01d9e6e8/D_01d9eaa4 loads and the set*36 mult among the request stores in the
#   final block. Replace with C after 100%.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001f0a38,"ax",@progbits
	.align 2
	.globl func_001f0a38
	.type func_001f0a38, @function
	.ent func_001f0a38
func_001f0a38:
	addiu	$29,$29,-224
	li	$14,0xffff
	sd	$16,160($29)
	sd	$17,168($29)
	sd	$19,184($29)
	move	$16,$5
	sd	$20,192($29)
	move	$17,$4
	sd	$18,176($29)
	move	$19,$6
	sd	$21,200($29)
	sd	$31,208($29)
	lw	$13,12($6)
	lw	$9,4($5)
	lw	$15,8($13)
	addu	$15,$4,$15
	beq	$9,$14,.L001f0c80
	addiu	$20,$15,160
	lui	$15,0x1da
	li	$14,36
	lw	$12,-6428($15)
	mult	$14,$9,$14
	lw	$15,0($13)
	lw	$13,16($12)
	addu	$15,$4,$15
	addiu	$15,$15,160
	addu	$14,$14,$13
	lbu	$10,10($15)
	lw	$18,28($14)
	lbu	$12,11($15)
	lbu	$14,8($15)
	lbu	$13,9($15)
	sb	$14,24($29)
	sb	$13,25($29)
	sb	$10,26($29)
	beqz	$12,.L001f0c80
	sb	$12,27($29)
	lbu	$14,34($5)
	andi	$15,$14,0x2
	beqz	$15,.L001f0cc0
	sw	$0,0($29)
	li	$15,4
	sw	$15,0($29)
.L001f0ae4:
	lw	$14,0($18)
	andi	$15,$14,0x1
	bnez	$15,.L001f0b08
	andi	$15,$14,0x2
	lw	$15,0($29)
	ori	$15,$15,0x8
	sw	$15,0($29)
	lw	$14,0($18)
	andi	$15,$14,0x2
.L001f0b08:
	bnezl	$15,.L001f0b20
	lbu	$15,35($16)
	lw	$15,0($29)
	ori	$15,$15,0x10
	sw	$15,0($29)
	lbu	$15,35($16)
.L001f0b20:
	beqz	$15,.L001f0b30
	lw	$15,0($29)
	ori	$15,$15,0x200
	sw	$15,0($29)
.L001f0b30:
	lbu	$15,36($16)
	beqz	$15,.L001f0b44
	lw	$15,0($29)
	ori	$15,$15,0x100
	sw	$15,0($29)
.L001f0b44:
	lbu	$15,37($16)
	beqz	$15,.L001f0cb4
	lw	$15,0($29)
	li	$14,-17
	lui	$21,0x1da
	addiu	$4,$29,96
	and	$15,$15,$14
	lw	$6,-6424($21)
	ori	$15,$15,0x2000
	sw	$4,48($29)
	sw	$15,0($29)
	lui	$5,0x1da
	addiu	$6,$6,16
	jal	0x2f3d08
	addiu	$5,$5,-6080
	lw	$9,4($16)
.L001f0b84:
	lbu	$15,32($16)
	lui	$14,0x1da
	addiu	$14,$14,-5440
	li	$13,255
	bne	$15,$13,.L001f0cac
	sw	$14,4($29)
	lhu	$15,22($18)
.L001f0ba0:
	sh	$15,8($29)
	lui	$14,0x37
	addiu	$14,$14,312
	lwc1	$f1,16($20)
	lwc1	$f0,4($20)
	lwc1	$f2,0($14)
	sb	$0,10($29)
	mul.s	$f1,$f1,$f2
	sw	$0,12($29)
	mul.s	$f0,$f0,$f2
	lbu	$15,38($16)
	cvt.w.s	$f2,$f1
	cvt.w.s	$f1,$f0
	mfc1	$14,$f2
	sw	$14,20($29)
	mfc1	$14,$f1
	beqz	$15,.L001f0ca4
	sw	$14,16($29)
	lw	$14,12($19)
	lw	$15,12($14)
	addu	$15,$17,$15
	addiu	$15,$15,160
	sw	$15,68($29)
.L001f0bfc:
	sw	$0,28($29)
	lui	$16,0x1da
	lui	$15,0x1da
	li	$13,36
	lw	$12,-6424($21)
	addiu	$15,$15,-5696
	lw	$10,-5468($16)
	mult	$13,$9,$13
	addiu	$14,$12,80
	sw	$15,36($29)
	sw	$14,32($29)
	addiu	$11,$12,16
	sw	$11,44($29)
	lui	$15,0x1da
	lui	$14,0x1da
	sw	$10,52($29)
	addiu	$14,$14,-5760
	lw	$11,-6428($15)
	sw	$14,40($29)
	move	$4,$18
	move	$5,$29
	lw	$14,144($12)
	sw	$14,56($29)
	lw	$15,148($12)
	sw	$0,64($29)
	sw	$15,60($29)
	sb	$0,76($29)
	sb	$0,77($29)
	lw	$15,16($11)
	addu	$13,$13,$15
	jal	0x20f1e0
	lw	$6,32($13)
	sw	$2,-5468($16)
.L001f0c80:
	ld	$16,160($29)
	ld	$17,168($29)
	ld	$18,176($29)
	ld	$19,184($29)
	ld	$20,192($29)
	ld	$21,200($29)
	ld	$31,208($29)
	jr	$31
	addiu	$29,$29,224
.L001f0ca4:
	b	.L001f0bfc
	sw	$0,68($29)
.L001f0cac:
	b	.L001f0ba0
	lhu	$15,32($16)
.L001f0cb4:
	sw	$0,48($29)
	b	.L001f0b84
	lui	$21,0x1da
.L001f0cc0:
	andi	$15,$14,0x1
	andi	$15,$15,0xff
	beqz	$15,.L001f0ae4
	li	$15,128
	b	.L001f0ae4
	sw	$15,0($29)
	.end func_001f0a38
	.size func_001f0a38, .-func_001f0a38
