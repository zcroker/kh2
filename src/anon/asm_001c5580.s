# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
#     No symbol, written as literal lui/lo values: 0x00351690, 0x00351cc0, 0x0036deb4, 0x0036deb8, 0x0036debc, 0x01d49830, 0x01d49890, 0x01d498a8, 0x01d498ac, 0x01d50000, 0x01d50010, 0x01d50020, 0x01d50030
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001c5580,"ax",@progbits
	.align 3
	.globl func_001c5580
	.type func_001c5580, @function
	.ent func_001c5580
func_001c5580:
	addiu	$29,$29,-144
	sd	$16,48($29)
	sd	$19,72($29)
	sd	$20,80($29)
	lui	$16,%hi(D_0034e948)
	swc1	$f21,132($29)
	move	$19,$0
	sd	$17,56($29)
	move	$20,$0
	sd	$18,64($29)
	sd	$21,88($29)
	sd	$22,96($29)
	sd	$23,104($29)
	sd	$30,112($29)
	sd	$31,120($29)
	swc1	$f23,140($29)
	swc1	$f22,136($29)
	swc1	$f20,128($29)
	sw	$4,32($29)
	mtc1	$0,$f21
	lw	$4,%lo(D_0034e948)($16)
	jal	func_0019ba60
	sw	$0,36($29)
	beqz	$2,.L001c5b88
	lw	$4,%lo(D_0034e948)($16)
	jal	func_0016c028
	lui	$17,%hi(D_00352a60)
	addiu	$15,$17,%lo(D_00352a60)
	beql	$2,$15,.L001c5604
	move	$2,$0
	lq	$8,0($2)
	sq	$8,0($15)
.L001c5600:
	move	$2,$0
.L001c5604:
	li	$16,1
.L001c5608:
	jal	func_0018ee10
	move	$4,$2
	bnezl	$2,.L001c5b7c
	lw	$15,20($2)
	jal	func_00106a60
	li	$4,1
	addiu	$15,$2,16
	lui	$14,%hi(D_01d497f0)
	movz	$15,$0,$2
	addiu	$6,$14,%lo(D_01d497f0)
	beql	$15,$6,.L001c565c
	lui	$15,0x1d5
	lq	$8,0($15)
	lq	$9,16($15)
	lq	$10,32($15)
	lq	$11,48($15)
	sq	$8,0($6)
	sq	$9,16($6)
	sq	$10,32($6)
	sq	$11,48($6)
	lui	$15,0x1d5
.L001c565c:
	addiu	$7,$15,-26576
	beq	$6,$7,.L001c5688
	nop
	lq	$8,0($6)
	lq	$9,16($6)
	lq	$10,32($6)
	lq	$11,48($6)
	sq	$8,0($7)
	sq	$9,16($7)
	sq	$10,32($7)
	sq	$11,48($7)
.L001c5688:
	lq	$8,0($7)
	lq	$9,16($7)
	lq	$10,32($7)
	qmfc2	$11,$vf0
	lqc2	$vf4,48($7)
	pextlw	$12,$9,$8
	pextuw	$13,$9,$8
	pextlw	$14,$11,$10
	pextuw	$15,$11,$10
	pcpyld	$8,$14,$12
	pcpyud	$9,$12,$14
	pcpyld	$10,$15,$13
	qmtc2	$8,$vf1
	qmtc2	$9,$vf2
	qmtc2	$10,$vf3
	vmulax.xyz	ACC,$vf1,vf4x
	vmadday.xyz	ACC,$vf2,vf4y
	vmaddz.xyz	$vf4,$vf3,vf4z
	vsub.xyz	$vf4,$vf0,$vf4
	sq	$8,0($7)
	sq	$9,16($7)
	sq	$10,32($7)
	sqc2	$vf4,48($7)
	lui	$12,0x37
	mtc1	$0,$f1
	addiu	$12,$12,-8524
	addiu	$18,$29,16
	lwc1	$f2,0($12)
	swc1	$f1,4($29)
	swc1	$f2,0($29)
	swc1	$f1,8($29)
	swc1	$f1,12($29)
	lqc2	$vf5,0($29)
	lqc2	$vf1,0($7)
	lqc2	$vf2,16($7)
	lqc2	$vf3,32($7)
	lqc2	$vf4,48($7)
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	sqc2	$vf5,0($18)
	lui	$15,%hi(D_01d49880)
	addiu	$15,$15,%lo(D_01d49880)
	beq	$18,$15,.L001c574c
	lui	$13,0x37
	lq	$8,0($18)
	sq	$8,0($15)
	lui	$13,0x37
.L001c574c:
	swc1	$f1,4($29)
	addiu	$13,$13,-8520
	swc1	$f1,8($29)
	lwc1	$f0,0($13)
	swc1	$f1,12($29)
	swc1	$f0,0($29)
	lqc2	$vf5,0($29)
	lqc2	$vf1,0($7)
	lqc2	$vf2,16($7)
	lqc2	$vf3,32($7)
	lqc2	$vf4,48($7)
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	sqc2	$vf5,0($18)
	lui	$15,0x1d5
	addiu	$15,$15,-26480
	beq	$18,$15,.L001c57a8
	addiu	$13,$17,%lo(D_00352a60)
	lq	$8,0($18)
	sq	$8,0($15)
	addiu	$13,$17,%lo(D_00352a60)
.L001c57a8:
	lqc2	$vf5,0($13)
	lqc2	$vf1,0($6)
	lqc2	$vf2,16($6)
	lqc2	$vf3,32($6)
	lqc2	$vf4,48($6)
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	sqc2	$vf5,0($18)
	lui	$15,%hi(D_01d49870)
	addiu	$14,$15,%lo(D_01d49870)
	beq	$18,$14,.L001c57e8
	nop
	lq	$8,0($18)
	sq	$8,0($14)
.L001c57e8:
	lqc2	$vf1,0($14)
	vmul.xyz	$vf1,$vf1,$vf1
	vaddy.x	$vf1,$vf1,vf1y
	vaddz.x	$vf1,$vf1,vf1z
	qmfc2	$8,$vf1
	mtc1	$8,$f0
	lui	$15,%hi(D_01d498a0)
	swc1	$f1,4($14)
	swc1	$f0,%lo(D_01d498a0)($15)
	lqc2	$vf1,0($14)
	vmul.xyz	$vf2,$vf1,$vf1
	vaddy.x	$vf2,$vf2,vf2y
	vaddz.x	$vf2,$vf2,vf2z
	vsqrt	Q,vf2x
	vwaitq
	cfc2.ni	$8,$22
	vaddq.x	$vf2,$vf0,Q
	mtc1	$8,$f0
	vnop
	vdiv	Q,vf0w,vf2x
	vwaitq
	vmulq.xyz	$vf1,$vf1,Q
	sqc2	$vf1,0($14)
	swc1	$f0,12($14)
	lui	$12,0x35
	lui	$15,0x1d5
	swc1	$f2,-26452($15)
	lw	$14,7360($12)
	blez	$14,.L001c59ac
	move	$16,$0
	lui	$15,%hi(D_0035169c)
	mov.s	$f23,$f1
	addiu	$21,$15,%lo(D_0035169c)
	move	$23,$13
	lui	$15,0x37
	move	$22,$12
	addiu	$15,$15,-8516
	move	$30,$0
	lwc1	$f22,0($15)
	sll	$17,$16,0x5
.L001c5888:
	addu	$14,$17,$21
	lw	$15,0($14)
	andi	$15,$15,0x4
	bnez	$15,.L001c599c
	lw	$15,7360($22)
	lui	$12,%hi(D_00351680)
	addiu	$12,$12,%lo(D_00351680)
	addu	$15,$17,$12
	lqc2	$vf1,0($15)
	lqc2	$vf2,0($23)
	vsub.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($18)
	beql	$29,$18,.L001c58cc
	sw	$0,4($29)
	lq	$8,0($18)
	sq	$8,0($29)
	sw	$0,4($29)
.L001c58cc:
	lqc2	$vf1,0($29)
	vmul.xyz	$vf1,$vf1,$vf1
	vaddy.x	$vf1,$vf1,vf1y
	vaddz.x	$vf1,$vf1,vf1z
	qmfc2	$8,$vf1
	mtc1	$8,$f20
	c.lt.s	$f22,$f20
	bc1f	.L001c5b70
	swc1	$f20,24($15)
	lw	$15,0($14)
	li	$13,-2
	and	$15,$15,$13
.L001c58fc:
	beqz	$19,.L001c5b54
	sw	$15,0($14)
	lui	$15,0x35
	move	$4,$18
	jal	func_0016af58
	lw	$5,-5816($15)
	lqc2	$vf1,0($29)
	lqc2	$vf2,0($18)
	vmul.xyz	$vf1,$vf1,$vf2
	vaddy.x	$vf1,$vf1,vf1y
	vaddz.x	$vf1,$vf1,vf1z
	qmfc2	$8,$vf1
	mtc1	$8,$f0
	lui	$12,%hi(D_01d497c0)
	addiu	$12,$12,%lo(D_01d497c0)
	lwc1	$f1,8($12)
	add.s	$f0,$f0,$f1
	c.lt.s	$f23,$f0
	bc1f	.L001c5b54
	lui	$13,%hi(D_0035169c)
	addiu	$13,$13,%lo(D_0035169c)
	addu	$14,$17,$13
	lw	$15,0($14)
	ori	$15,$15,0x2
	nop
.L001c5960:
	sw	$15,0($14)
	lui	$17,0x1d5
	jal	func_00313b80
	lwc1	$f12,-26452($17)
	move	$4,$2
	jal	func_003142e0
	move	$5,$30
	bltz	$2,.L001c5990
	lwc1	$f0,-26452($17)
	c.lt.s	$f20,$f0
	bc1f	.L001c599c
	lw	$15,7360($22)
.L001c5990:
	swc1	$f20,-26452($17)
	sw	$16,36($29)
	lw	$15,7360($22)
.L001c599c:
	addiu	$16,$16,1
	slt	$15,$16,$15
	bnez	$15,.L001c5888
	sll	$17,$16,0x5
.L001c59ac:
	lw	$13,36($29)
	lui	$15,%hi(D_0035169c)
	addiu	$15,$15,%lo(D_0035169c)
	sll	$14,$13,0x5
	lui	$13,0x1d5
	addu	$14,$14,$15
	sw	$0,-26456($13)
	move	$16,$13
	lw	$15,0($14)
	ori	$15,$15,0x1
	sw	$15,0($14)
.L001c59d8:
	jal	func_00185da8
	move	$4,$20
	bnez	$2,.L001c5b44
	move	$20,$2
	lui	$15,%hi(D_01d498b0)
	lui	$14,0x1d5
	lw	$13,%lo(D_01d498b0)($15)
	lw	$12,-26456($14)
	negu	$13,$13
	lui	$15,%hi(D_01d498a4)
	lw	$14,%lo(D_01d498a4)($15)
	subu	$13,$13,$12
	addiu	$7,$13,1000
	slt	$14,$7,$14
	beqz	$14,.L001c5afc
	lui	$15,0x35
	lui	$14,0x35
	lw	$5,7360($15)
	addiu	$6,$14,5776
	addiu	$17,$6,12
	lui	$2,%hi(D_0035169c)
	addiu	$3,$6,-16
	move	$4,$5
	li	$11,-1
.L001c5a38:
	blez	$5,.L001c5a98
	move	$16,$0
	addiu	$12,$2,%lo(D_0035169c)
	move	$10,$4
	sll	$13,$16,0x5
.L001c5a4c:
	addu	$14,$13,$12
	lw	$15,0($14)
	andi	$15,$15,0x4
	bnezl	$15,.L001c5a8c
	addiu	$16,$16,1
	bltz	$11,.L001c5a7c
	addiu	$14,$12,-28
	addu	$15,$13,$14
	lwc1	$f0,24($15)
	c.lt.s	$f21,$f0
	bc1fl	.L001c5a8c
	addiu	$16,$16,1
.L001c5a7c:
	addu	$15,$13,$14
	move	$11,$16
	lwc1	$f21,24($15)
	addiu	$16,$16,1
.L001c5a8c:
	slt	$15,$16,$10
	bnez	$15,.L001c5a4c
	sll	$13,$16,0x5
.L001c5a98:
	bltz	$11,.L001c5afc
	sll	$9,$11,0x5
	lui	$8,%hi(D_01d498a4)
	lw	$12,%lo(D_01d498a4)($8)
	addu	$15,$9,$6
	lw	$10,0($15)
	addu	$11,$9,$3
	subu	$14,$12,$7
	lw	$13,16($11)
	slt	$15,$10,$14
	movn	$14,$10,$15
	subu	$12,$12,$14
	subu	$13,$13,$14
	sw	$12,%lo(D_01d498a4)($8)
	sw	$13,16($11)
	bnez	$13,.L001c5aec
	sw	$14,20($11)
	addu	$14,$9,$17
	lw	$15,0($14)
	ori	$15,$15,0x4
	sw	$15,0($14)
.L001c5aec:
	lw	$15,%lo(D_01d498a4)($8)
	slt	$15,$7,$15
	bnez	$15,.L001c5a38
	li	$11,-1
.L001c5afc:
	jal	func_001dbad0
	lw	$4,32($29)
	ld	$16,48($29)
	ld	$17,56($29)
	ld	$18,64($29)
	ld	$19,72($29)
	ld	$20,80($29)
	ld	$21,88($29)
	ld	$22,96($29)
	ld	$23,104($29)
	ld	$30,112($29)
	ld	$31,120($29)
	lwc1	$f23,140($29)
	lwc1	$f22,136($29)
	lwc1	$f21,132($29)
	lwc1	$f20,128($29)
	jr	$31
	addiu	$29,$29,144
.L001c5b44:
	lw	$15,-26456($16)
	addiu	$15,$15,1
	b	.L001c59d8
	sw	$15,-26456($16)
.L001c5b54:
	lui	$15,%hi(D_0035169c)
	li	$12,-3
	addiu	$15,$15,%lo(D_0035169c)
	addu	$14,$17,$15
	lw	$15,0($14)
	b	.L001c5960
	and	$15,$15,$12
.L001c5b70:
	lw	$15,0($14)
	b	.L001c58fc
	ori	$15,$15,0x1
.L001c5b7c:
	xori	$15,$15,0x44
	b	.L001c5608
	movz	$19,$16,$15
.L001c5b88:
	b	.L001c5600
	lui	$17,0x35
	.end func_001c5580
	.size func_001c5580, 1552
