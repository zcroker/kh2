# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3886).
# Replace with C/C++ after 100%. The closest C draft is coord best/00128040_w3886.cpp:
# built as _nsa with register pins (base in $f2, the two hoisted 0.0f in $f21/$f22),
# it differs from this function only by sltiu for slti in the soft-limit loop test.
# A signed loop counter there makes loop.c reverse the loop (li s0,2 / bgez).
#   func_00128040: clamps *io (relative to *org) into a joint limit (sphere or box, hard or soft edge)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00128040,"ax",@progbits
	.align 2
	.globl func_00128040
	.type func_00128040, @function
	.ent func_00128040
func_00128040:
	addiu	$29,$29,-160
	move	$2,$0
	sd	$17,72($29)
	sd	$19,88($29)
	sd	$16,64($29)
	move	$17,$5
	sd	$18,80($29)
	sd	$20,96($29)
	sd	$21,104($29)
	sd	$22,112($29)
	sd	$23,120($29)
	sd	$30,128($29)
	sd	$31,136($29)
	swc1	$f23,156($29)
	swc1	$f22,152($29)
	swc1	$f21,148($29)
	swc1	$f20,144($29)
	ld	$14,0($5)
	andi	$15,$14,0x7
	beqz	$15,.L00128474
	move	$19,$7
	andi	$15,$14,0x8
	bnez	$15,.L00128474
	nop
	beq	$29,$6,.L001280b4
	addiu	$18,$29,16
	lq	$8,0($6)
	sq	$8,0($29)
	addiu	$18,$29,16
.L001280b4:
	addiu	$16,$29,32
	lqc2	$vf1,0($19)
	lqc2	$vf2,0($29)
	vsub.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($16)
	beql	$18,$16,.L001280dc
	ld	$11,0($17)
	lq	$8,0($16)
	sq	$8,0($18)
	ld	$11,0($17)
.L001280dc:
	li	$15,1
	andi	$14,$11,0x7
	bnel	$14,$15,.L00128240
	lwc1	$f1,12($17)
	lwc1	$f21,16($17)
	lqc2	$vf1,0($18)
	vmul.xyz	$vf1,$vf1,$vf1
	vaddy.x	$vf1,$vf1,$vf1y
	vaddz.x	$vf1,$vf1,$vf1z
	vsqrt	Q,$vf1x
	vwaitq
	cfc2.ni	$8,$vi22
	mtc1	$8,$f2
	lwc1	$f12,12($17)
	mtc1	$0,$f3
	c.eq.s	$f12,$f3
	bc1f	.L001281f0
	mov.s	$f1,$f2
	c.lt.s	$f21,$f2
	bc1f	.L001281a4
	lui	$15,0x37
.L00128130:
	lqc2	$vf1,0($18)
	vmul.xyz	$vf2,$vf1,$vf1
	vaddy.x	$vf2,$vf2,$vf2y
	vaddz.x	$vf2,$vf2,$vf2z
	vsqrt	Q,$vf2x
	vwaitq
	cfc2.ni	$8,$vi22
	vaddq.x	$vf2,$vf0,Q
	mtc1	$8,$f0
	vnop
	vdiv	Q,$vf0w,$vf2x
	vwaitq
	vmulq.xyz	$vf1,$vf1,Q
	sqc2	$vf1,0($18)
	lqc2	$vf1,0($18)
	mfc1	$8,$f1
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,$vf2x
	sqc2	$vf1,0($18)
	lqc2	$vf1,0($29)
	lqc2	$vf2,0($18)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($16)
	beq	$19,$16,.L001281a0
	li	$2,1
	lq	$8,0($16)
	sq	$8,0($19)
	li	$2,1
.L001281a0:
	lui	$15,0x37
.L001281a4:
	ld	$16,64($29)
	addiu	$15,$15,-22036
	ld	$17,72($29)
	lwc1	$f0,0($15)
	ld	$18,80($29)
	swc1	$f0,12($19)
	ld	$20,96($29)
	ld	$19,88($29)
	ld	$21,104($29)
	ld	$22,112($29)
	ld	$23,120($29)
	ld	$30,128($29)
	ld	$31,136($29)
	lwc1	$f23,156($29)
	lwc1	$f22,152($29)
	lwc1	$f21,148($29)
	lwc1	$f20,144($29)
	jr	$31
	addiu	$29,$29,160
.L001281f0:
	lwc1	$f1,8($17)
	sub.s	$f0,$f21,$f1
	sub.s	$f0,$f2,$f0
	c.lt.s	$f3,$f0
	bc1f	.L001281a0
	lui	$15,0x37
	nop
	nop
	div.s	$f0,$f0,$f1
	addiu	$15,$15,-22036
	lwc1	$f20,0($15)
	sub.s	$f12,$f12,$f20
	jal	0x2f8ae8
	mul.s	$f12,$f12,$f0
	sub.s	$f20,$f20,$f0
	lwc1	$f0,8($17)
	sub.s	$f1,$f21,$f0
	mul.s	$f0,$f0,$f20
	b	.L00128130
	add.s	$f1,$f1,$f0
.L00128240:
	dsrl	$10,$11,0x9
	dsrl	$15,$11,0x4
	mtc1	$0,$f0
	dsrl	$14,$11,0x5
	dsrl	$13,$11,0x6
	dsrl	$12,$11,0x7
	c.eq.s	$f1,$f0
	dsrl	$11,$11,0x8
	andi	$15,$15,0xff
	andi	$14,$14,0xff
	andi	$13,$13,0xff
	andi	$12,$12,0xff
	andi	$11,$11,0xff
	andi	$10,$10,0xff
	andi	$15,$15,0x1
	andi	$14,$14,0x1
	sb	$15,32($29)
	andi	$13,$13,0x1
	sb	$14,33($29)
	andi	$12,$12,0x1
	sb	$13,34($29)
	andi	$11,$11,0x1
	sb	$12,35($29)
	andi	$10,$10,0x1
	sb	$11,36($29)
	bc1f	.L00128338
	sb	$10,37($29)
	addiu	$5,$17,32
	move	$11,$18
	move	$16,$0
	move	$12,$0
.L001282bc:
	sll	$15,$16,0x1
	addu	$13,$15,$29
	lbu	$14,32($13)
	beqzl	$14,.L001282e8
	lbu	$15,33($13)
	lwc1	$f1,-16($5)
	lwc1	$f0,0($11)
	c.lt.s	$f0,$f1
	bc1t	.L00128304
	addu	$15,$29,$12
	lbu	$15,33($13)
.L001282e8:
	beqzl	$15,.L0012831c
	addiu	$16,$16,1
	lwc1	$f1,0($5)
	lwc1	$f0,0($11)
	c.lt.s	$f1,$f0
	bc1f	.L00128318
	addu	$15,$29,$12
.L00128304:
	addu	$14,$19,$12
	lwc1	$f0,0($15)
	li	$2,1
	add.s	$f0,$f0,$f1
	swc1	$f0,0($14)
.L00128318:
	addiu	$16,$16,1
.L0012831c:
	addiu	$5,$5,4
	addiu	$11,$11,4
	slti	$15,$16,3
	bnez	$15,.L001282bc
	addiu	$12,$12,4
	b	.L001281a4
	lui	$15,0x37
.L00128338:
	lui	$15,0x37
	mtc1	$0,$f21
	addiu	$15,$15,-22036
	move	$16,$0
	lwc1	$f20,0($15)
	move	$20,$19
	mov.s	$f22,$f21
	move	$30,$29
	addiu	$15,$17,16
	mov.s	$f23,$f20
	sw	$15,48($29)
	move	$23,$0
	addiu	$22,$29,33
	addiu	$15,$17,32
	sw	$15,52($29)
.L00128374:
	lbu	$15,-1($22)
	beqz	$15,.L00128410
	lw	$15,48($29)
	lwc1	$f12,8($17)
	addu	$21,$15,$23
	lwc1	$f1,0($18)
	lwc1	$f0,0($21)
	add.s	$f0,$f0,$f12
	sub.s	$f0,$f0,$f1
	c.lt.s	$f21,$f0
	bc1fl	.L00128414
	lbu	$15,0($22)
	nop
	nop
	div.s	$f0,$f0,$f12
	lwc1	$f12,12($17)
	sub.s	$f12,$f12,$f20
	jal	0x2f8ae8
	mul.s	$f12,$f12,$f0
	lwc1	$f2,0($21)
	li	$2,1
	lwc1	$f3,8($17)
	sub.s	$f0,$f20,$f0
	add.s	$f2,$f2,$f3
.L001283d4:
	lwc1	$f1,0($30)
	mul.s	$f0,$f3,$f0
	add.s	$f1,$f1,$f2
	add.s	$f1,$f1,$f0
	swc1	$f1,0($20)
.L001283e8:
	addiu	$16,$16,1
.L001283ec:
	addiu	$20,$20,4
	addiu	$30,$30,4
	addiu	$18,$18,4
	addiu	$23,$23,4
	slti	$15,$16,3
	bnez	$15,.L00128374
	addiu	$22,$22,2
	b	.L001281a4
	lui	$15,0x37
.L00128410:
	lbu	$15,0($22)
.L00128414:
	beqz	$15,.L001283e8
	lw	$15,52($29)
	lwc1	$f12,8($17)
	addu	$21,$15,$23
	lwc1	$f1,0($18)
	lwc1	$f0,0($21)
	sub.s	$f0,$f0,$f12
	sub.s	$f0,$f1,$f0
	c.lt.s	$f22,$f0
	bc1fl	.L001283ec
	addiu	$16,$16,1
	nop
	nop
	div.s	$f0,$f0,$f12
	lwc1	$f12,12($17)
	sub.s	$f12,$f12,$f23
	jal	0x2f8ae8
	mul.s	$f12,$f12,$f0
	lwc1	$f2,0($21)
	li	$2,1
	lwc1	$f3,8($17)
	sub.s	$f0,$f23,$f0
	b	.L001283d4
	sub.s	$f2,$f2,$f3
.L00128474:
	sqc2	$vf0,0($29)
	b	.L001280b4
	addiu	$18,$29,16
	.end func_00128040
	.size func_00128040, .-func_00128040

