# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/00208cb0_unit.cpp
#     No symbol, written as literal lui/lo values: 0x00370664
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00208cb0,"ax",@progbits
	.align 3
	.globl func_00208cb0
	.type func_00208cb0, @function
	.ent func_00208cb0
func_00208cb0:
	addiu	$29,$29,-416
	sd	$16,320($29)
	sd	$19,344($29)
	sd	$21,360($29)
	sd	$17,328($29)
	move	$19,$5
	sd	$18,336($29)
	sd	$20,352($29)
	sd	$22,368($29)
	sd	$23,376($29)
	sd	$30,384($29)
	sd	$31,392($29)
	swc1	$f20,400($29)
	lw	$14,12($6)
	lw	$15,8($14)
	lw	$13,4($14)
	addu	$15,$4,$15
	addiu	$16,$15,160
	addu	$4,$4,$13
	addiu	$21,$4,160
	lw	$17,16($16)
	lw	$20,20($16)
	move	$4,$16
	lw	$18,24($16)
	jal	func_00207308
	lw	$23,28($16)
	beqz	$2,.L00209020
	li	$15,0xffff
	lw	$14,4($19)
	beq	$14,$15,.L00209020
	move	$4,$29
	move	$6,$16
	jal	func_00208978
	move	$5,$19
	lw	$13,4($19)
	lui	$15,%hi(D_01d9e6e4)
	li	$14,36
	lw	$12,%lo(D_01d9e6e4)($15)
	mult	$13,$13,$14
	lbu	$11,13($19)
	lw	$15,16($12)
	addu	$15,$15,$13
	sw	$15,304($29)
	beqz	$11,.L002090b4
	lw	$22,28($15)
	lwc1	$f0,16($19)
	addiu	$15,$29,128
	lwc1	$f1,20($19)
	lwc1	$f2,24($19)
	sw	$15,276($29)
	swc1	$f0,192($29)
	swc1	$f1,196($29)
	swc1	$f2,200($29)
	sw	$0,204($29)
.L00208d88:
	sw	$0,236($29)
	lui	$15,%hi(D_01d9e6e8)
	sw	$0,252($29)
	lw	$14,%lo(D_01d9e6e8)($15)
	sw	$0,248($29)
	sw	$0,244($29)
	sb	$0,218($29)
	lbu	$11,8($19)
	lw	$15,144($14)
	andi	$12,$11,0x2
	sw	$15,264($29)
	lui	$15,%hi(D_01d9eac0)
	lw	$13,148($14)
	addiu	$15,$15,%lo(D_01d9eac0)
	sw	$15,212($29)
	sw	$13,268($29)
	li	$15,32
	sw	$0,220($29)
	addiu	$13,$29,64
	sw	$15,208($29)
	sw	$13,240($29)
	sd	$0,224($29)
	beqz	$12,.L00209084
	sw	$0,272($29)
	li	$15,36
	sw	$15,208($29)
	lw	$14,0($22)
	andi	$15,$14,0x1
	bnez	$15,.L00208e10
	andi	$15,$14,0x2
	li	$15,44
.L00208e04:
	sw	$15,208($29)
	lw	$14,0($22)
	andi	$15,$14,0x2
.L00208e10:
	bnezl	$15,.L00208e28
	lbu	$15,9($19)
	lw	$15,208($29)
	ori	$15,$15,0x10
	sw	$15,208($29)
	lbu	$15,9($19)
.L00208e28:
	beqz	$15,.L00208e38
	lw	$15,208($29)
	ori	$15,$15,0x200
	sw	$15,208($29)
.L00208e38:
	lbu	$15,11($19)
	beqz	$15,.L00208e4c
	lw	$15,208($29)
	ori	$15,$15,0x100
	sw	$15,208($29)
.L00208e4c:
	lhu	$15,22($22)
	lbu	$14,12($19)
	lbu	$13,266($19)
	sh	$15,216($29)
	sb	$14,284($29)
	sb	$13,285($29)
	lbu	$14,11($21)
	sw	$14,316($29)
	lbu	$15,8($21)
	sw	$15,308($29)
	lbu	$12,9($21)
	sw	$12,312($29)
	blez	$23,.L00209020
	lbu	$30,10($21)
	lui	$13,0x37
	move	$16,$23
	addiu	$13,$13,1636
	lui	$23,%hi(D_01d9eaa4)
	lwc1	$f20,0($13)
.L00208e98:
	lhu	$15,64($17)
	beqz	$15,.L00209004
	move	$4,$29
	lbu	$10,13($19)
	addiu	$21,$29,128
	addiu	$5,$29,64
	move	$6,$19
	move	$7,$17
	move	$8,$20
	jal	func_00208a30
	move	$9,$21
	lbu	$15,13($19)
	beqz	$15,.L00208ef0
	addiu	$5,$29,176
	addiu	$6,$29,192
	jal	sceVu0AddVector
	move	$4,$5
	lui	$14,%hi(D_01d9e8c0)
	move	$4,$21
	addiu	$5,$14,%lo(D_01d9e8c0)
	jal	sceVu0MulMatrix
	move	$6,$21
.L00208ef0:
	lb	$15,69($17)
	lwc1	$f0,316($29)
	mtc1	$15,$f1
	cvt.s.w	$f0,$f0
	lb	$13,66($17)
	cvt.s.w	$f1,$f1
	lw	$12,308($29)
	lwc1	$f2,168($17)
	addu	$11,$12,$13
	lb	$15,67($17)
	lb	$14,68($17)
	add.s	$f0,$f0,$f1
	lw	$13,312($29)
	addu	$8,$30,$14
	addu	$10,$13,$15
	sub.s	$f0,$f0,$f2
	cvt.w.s	$f1,$f0
	beqz	$18,.L00208f7c
	mfc1	$9,$f1
	lwc1	$f0,0($18)
	lwc1	$f2,4($18)
	cvt.w.s	$f1,$f0
	lwc1	$f3,8($18)
	cvt.w.s	$f0,$f2
	mfc1	$12,$f1
	lwc1	$f1,12($18)
	addu	$11,$11,$12
	mfc1	$15,$f0
	cvt.w.s	$f0,$f3
	addu	$10,$10,$15
	mfc1	$14,$f0
	cvt.w.s	$f0,$f1
	addu	$8,$8,$14
	mfc1	$13,$f0
	addu	$9,$9,$13
.L00208f7c:
	bgez	$11,.L00209078
	slti	$14,$11,256
	move	$11,$0
.L00208f88:
	bgez	$10,.L0020906c
	slti	$14,$10,256
	move	$10,$0
.L00208f94:
	bgez	$8,.L00209060
	slti	$14,$8,256
	move	$8,$0
.L00208fa0:
	bgez	$9,.L00209054
	slti	$14,$9,128
	move	$9,$0
.L00208fac:
	sb	$11,232($29)
	move	$4,$22
	sb	$10,233($29)
	addiu	$5,$29,208
	sb	$8,234($29)
	sb	$9,235($29)
	lw	$15,%lo(D_01d9eaa4)($23)
	lwc1	$f0,152($17)
	mul.s	$f0,$f0,$f20
	cvt.w.s	$f1,$f0
	mfc1	$12,$f1
	sw	$12,224($29)
	lwc1	$f1,156($17)
	mul.s	$f1,$f1,$f20
	sw	$15,260($29)
	cvt.w.s	$f0,$f1
	mfc1	$12,$f0
	sw	$12,228($29)
	lw	$12,304($29)
	jal	func_0020f1e0
	lw	$6,32($12)
	sw	$2,%lo(D_01d9eaa4)($23)
.L00209004:
	addiu	$15,$20,64
	addiu	$14,$18,32
	movn	$20,$15,$20
	movn	$18,$14,$18
	addiu	$16,$16,-1
	bnez	$16,.L00208e98
	addiu	$17,$17,176
.L00209020:
	ld	$16,320($29)
	ld	$17,328($29)
	ld	$18,336($29)
	ld	$19,344($29)
	ld	$20,352($29)
	ld	$21,360($29)
	ld	$22,368($29)
	ld	$23,376($29)
	ld	$30,384($29)
	ld	$31,392($29)
	lwc1	$f20,400($29)
	jr	$31
	addiu	$29,$29,416
.L00209054:
	li	$15,127
	b	.L00208fac
	movz	$9,$15,$14
.L00209060:
	li	$15,255
	b	.L00208fa0
	movz	$8,$15,$14
.L0020906c:
	li	$15,255
	b	.L00208f94
	movz	$10,$15,$14
.L00209078:
	li	$15,255
	b	.L00208f88
	movz	$11,$15,$14
.L00209084:
	andi	$15,$11,0x1
	andi	$15,$15,0xff
	beqz	$15,.L00209098
	li	$15,160
	sw	$15,208($29)
.L00209098:
	lw	$14,0($22)
	andi	$15,$14,0x1
	bnezl	$15,.L00208e10
	andi	$15,$14,0x2
	lw	$15,208($29)
	b	.L00208e04
	ori	$15,$15,0x8
.L002090b4:
	b	.L00208d88
	sw	$0,276($29)
	nop
	.end func_00208cb0
	.size func_00208cb0, 1040
