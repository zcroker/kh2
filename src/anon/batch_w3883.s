# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3883).
# Both functions were long-standing C/C++ near misses (many sessions and permuter runs); see coord
# attempts.tsv and the best/ADDR_w3883.* drafts. Replace with C/C++ after 100%.
#   func_001c4918: ambient wave update and random ground-effect spawn (sched1 order of the pool load
#                  against the D_003638d0 reload in the inlined random generator; v.w zero in an FP reg)
#   func_001f0600: model render request setup (sched1/sched2 order of the D_01d9e6e8/D_01d9eaa4 loads
#                  and the set*36 mult among the request stores in the final block)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001c4918,"ax",@progbits
	.align 2
	.globl func_001c4918
	.type func_001c4918, @function
	.ent func_001c4918
func_001c4918:
	addiu	$29,$29,-240
	sd	$22,192($29)
	sd	$16,144($29)
	sd	$17,152($29)
	sd	$18,160($29)
	sd	$19,168($29)
	sd	$20,176($29)
	sd	$21,184($29)
	sd	$31,200($29)
	swc1	$f26,232($29)
	swc1	$f25,228($29)
	swc1	$f24,224($29)
	swc1	$f23,220($29)
	swc1	$f22,216($29)
	swc1	$f21,212($29)
	swc1	$f20,208($29)
	jal	0x1c4160
	move	$22,$4
	beqz	$2,.L001c4974
	lui	$15,0x1d5
	jal	0x1c42a0
	nop
	lui	$15,0x1d5
.L001c4974:
	mtc1	$0,$f24
	addiu	$21,$15,-27248
	lui	$11,0x37
	lui	$14,0x37
	mov.s	$f25,$f24
	lui	$15,0x37
	addiu	$11,$11,-8608
	addiu	$14,$14,-8604
	lwc1	$f26,0($11)
	addiu	$15,$15,-8600
	lwc1	$f22,0($14)
	lwc1	$f23,0($15)
	move	$19,$21
	move	$18,$0
	move	$20,$21
.L001c49b0:
	sll	$17,$18,0x4
	addu	$16,$17,$21
	jal	0x2f8960
	lwc1	$f12,12($16)
	mov.s	$f20,$f0
	jal	0x2f8960
	lwc1	$f12,12($16)
	mul.s	$f21,$f0,$f26
	jal	0x2f87c0
	lwc1	$f12,12($16)
	c.lt.s	$f24,$f20
	bc1f	.L001c4dbc
	mov.s	$f1,$f0
	mul.s	$f0,$f20,$f20
.L001c49e8:
	mul.s	$f0,$f0,$f22
	addu	$15,$17,$19
	c.lt.s	$f25,$f1
	swc1	$f21,4($15)
	bc1f	.L001c4db0
	swc1	$f0,0($16)
	mul.s	$f0,$f1,$f1
.L001c4a04:
	addu	$16,$17,$20
	mul.s	$f0,$f0,$f22
	lwc1	$f12,12($16)
	addiu	$18,$18,1
	add.s	$f12,$f12,$f23
	jal	0x17ce10
	swc1	$f0,8($15)
	slti	$15,$18,8
	bnez	$15,.L001c49b0
	swc1	$f0,12($16)
	jal	0x106a60
	li	$4,1
	addiu	$15,$2,16
	lui	$14,0x1d5
	movz	$15,$0,$2
	addiu	$14,$14,-27120
	beq	$15,$14,.L001c4a6c
	nop
	lq	$8,0($15)
	lq	$9,16($15)
	lq	$10,32($15)
	lq	$11,48($15)
	sq	$8,0($14)
	sq	$9,16($14)
	sq	$10,32($14)
	sq	$11,48($14)
.L001c4a6c:
	jal	0x1dbad0
	move	$4,$22
	jal	0x197920
	nop
	bnez	$2,.L001c4d18
	ld	$16,144($29)
	jal	0x19ba60
	move	$4,$22
	beqz	$2,.L001c4d18
	ld	$16,144($29)
	jal	0x1c4170
	nop
	move	$16,$2
	jal	0x16c6e8
	li	$4,1368
	slt	$2,$2,$16
	beqz	$2,.L001c4d14
	lui	$13,0x36
	lui	$15,0x1
	lw	$14,14544($13)
	ori	$15,$15,0xdcd
	move	$12,$29
	mult	$15,$14,$15
	bltz	$15,.L001c4d94
	sw	$15,14544($13)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
.L001c4ad8:
	lui	$13,0x36
	lui	$15,0x1
	lw	$14,14544($13)
	lui	$11,0x37
	addiu	$11,$11,-8596
	ori	$15,$15,0xdcd
	lwc1	$f1,0($11)
	mult	$15,$14,$15
	mul.s	$f1,$f0,$f1
	lui	$11,0x37
	addiu	$11,$11,-8592
	lui	$14,0x37
	lwc1	$f20,0($11)
	addiu	$14,$14,-8588
	sw	$15,14544($13)
	lwc1	$f0,0($14)
	lui	$11,0x37
	addiu	$11,$11,-8584
	mul.s	$f1,$f1,$f0
	lwc1	$f0,0($11)
	bltz	$15,.L001c4d78
	add.s	$f0,$f0,$f1
	mtc1	$15,$f3
	cvt.s.w	$f3,$f3
.L001c4b38:
	lui	$14,0x37
	swc1	$f0,0($12)
	addiu	$14,$14,-8596
	mtc1	$0,$f13
	lwc1	$f2,0($14)
	lui	$11,0x37
	addiu	$11,$11,-8580
	swc1	$f13,12($12)
	mul.s	$f2,$f3,$f2
	lui	$14,0x37
	lwc1	$f1,0($11)
	addiu	$14,$14,-8576
	lwc1	$f0,0($14)
	lui	$15,0x1d5
	swc1	$f20,4($12)
	addiu	$15,$15,-27120
	mul.s	$f2,$f2,$f1
	addiu	$6,$29,48
	add.s	$f0,$f0,$f2
	beq	$6,$15,.L001c4bac
	swc1	$f0,8($12)
	lq	$8,0($15)
	lq	$9,16($15)
	lq	$10,32($15)
	lq	$11,48($15)
	sq	$8,0($6)
	sq	$9,16($6)
	sq	$10,32($6)
	sq	$11,48($6)
.L001c4bac:
	lq	$8,0($6)
	lq	$9,16($6)
	lq	$10,32($6)
	qmfc2	$11,$vf0
	lqc2	$vf4,48($6)
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
	vmulax.xyz	ACC,$vf1,$vf4x
	vmadday.xyz	ACC,$vf2,$vf4y
	vmaddz.xyz	$vf4,$vf3,$vf4z
	vsub.xyz	$vf4,$vf0,$vf4
	sq	$8,0($6)
	sq	$9,16($6)
	sq	$10,32($6)
	sqc2	$vf4,48($6)
	addiu	$7,$29,128
	lqc2	$vf5,0($29)
	lqc2	$vf1,0($6)
	lqc2	$vf2,16($6)
	lqc2	$vf3,32($6)
	lqc2	$vf4,48($6)
	vmulax.wxyz	ACC,$vf1,$vf5x
	vmadday.wxyz	ACC,$vf2,$vf5y
	vmaddaz.wxyz	ACC,$vf3,$vf5z
	vmaddw.wxyz	$vf5,$vf4,$vf5w
	sqc2	$vf5,0($7)
	lui	$15,0x35
	addiu	$4,$29,112
	addiu	$16,$15,10848
	lqc2	$vf1,0($7)
	lqc2	$vf2,0($16)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($4)
	lui	$15,0x37
	move	$5,$29
	addiu	$15,$15,-8572
	li	$6,2
	jal	0x1a7610
	lwc1	$f12,0($15)
	beqz	$2,.L001c4d14
	addiu	$4,$29,16
	beq	$4,$16,.L001c4c84
	lui	$11,0x37
	lq	$8,0($16)
	sq	$8,0($4)
	lui	$11,0x37
.L001c4c84:
	lwc1	$f0,20($29)
	addiu	$11,$11,-8604
	addiu	$6,$29,32
	lwc1	$f1,0($11)
	move	$5,$29
	li	$7,2
	sub.s	$f0,$f0,$f1
	jal	0x1a7588
	swc1	$f0,20($29)
	bgez	$2,.L001c4d18
	ld	$16,144($29)
	jal	0x1c4170
	nop
	lwc1	$f0,4($29)
	li	$4,1368
	mtc1	$0,$f12
	move	$5,$29
	add.s	$f0,$f0,$f20
	jal	0x16f000
	swc1	$f0,4($29)
	beqz	$2,.L001c4d14
	move	$16,$2
	lui	$15,0x1d5
	move	$4,$2
	lw	$6,-27056($15)
	jal	0x16c018
	li	$5,1
	jal	0x1c4170
	nop
	slti	$2,$2,50
	beqz	$2,.L001c4d58
	move	$4,$16
	li	$5,2
	li	$6,500
.L001c4d0c:
	jal	0x16c018
	nop
.L001c4d14:
	ld	$16,144($29)
.L001c4d18:
	ld	$17,152($29)
	ld	$18,160($29)
	ld	$19,168($29)
	ld	$20,176($29)
	ld	$21,184($29)
	ld	$22,192($29)
	ld	$31,200($29)
	lwc1	$f26,232($29)
	lwc1	$f25,228($29)
	lwc1	$f24,224($29)
	lwc1	$f23,220($29)
	lwc1	$f22,216($29)
	lwc1	$f21,212($29)
	lwc1	$f20,208($29)
	jr	$31
	addiu	$29,$29,240
.L001c4d58:
	jal	0x1c4170
	nop
	slti	$2,$2,100
	beqz	$2,.L001c4d14
	move	$4,$16
	li	$5,2
	b	.L001c4d0c
	li	$6,1000
.L001c4d78:
	srl	$14,$15,0x1
	andi	$15,$15,0x1
	or	$15,$15,$14
	mtc1	$15,$f3
	cvt.s.w	$f3,$f3
	b	.L001c4b38
	add.s	$f3,$f3,$f3
.L001c4d94:
	srl	$14,$15,0x1
	andi	$15,$15,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L001c4ad8
	add.s	$f0,$f0,$f0
.L001c4db0:
	mul.s	$f0,$f1,$f1
	b	.L001c4a04
	neg.s	$f0,$f0
.L001c4dbc:
	mul.s	$f0,$f20,$f20
	b	.L001c49e8
	neg.s	$f0,$f0
	.end func_001c4918
	.size func_001c4918, .-func_001c4918

	.section .text.func_001f0600,"ax",@progbits
	.align 2
	.globl func_001f0600
	.type func_001f0600, @function
	.ent func_001f0600
func_001f0600:
	addiu	$29,$29,-208
	li	$14,0xffff
	sd	$16,160($29)
	sd	$18,176($29)
	sd	$17,168($29)
	move	$16,$5
	sd	$19,184($29)
	sd	$31,192($29)
	lw	$13,12($6)
	lw	$9,4($5)
	lw	$15,8($13)
	addu	$15,$4,$15
	beq	$9,$14,.L001f0820
	addiu	$18,$15,160
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
	lw	$17,28($14)
	lbu	$12,11($15)
	lbu	$14,8($15)
	lbu	$13,9($15)
	sb	$14,24($29)
	sb	$13,25($29)
	sb	$10,26($29)
	beqz	$12,.L001f0820
	sb	$12,27($29)
	lbu	$14,34($5)
	andi	$15,$14,0x2
	beqz	$15,.L001f0850
	sw	$0,0($29)
	li	$15,4
	sw	$15,0($29)
.L001f069c:
	lw	$14,0($17)
	andi	$15,$14,0x1
	bnez	$15,.L001f06c0
	andi	$15,$14,0x2
	lw	$15,0($29)
	ori	$15,$15,0x8
	sw	$15,0($29)
	lw	$14,0($17)
	andi	$15,$14,0x2
.L001f06c0:
	bnezl	$15,.L001f06d8
	lbu	$15,35($16)
	lw	$15,0($29)
	ori	$15,$15,0x10
	sw	$15,0($29)
	lbu	$15,35($16)
.L001f06d8:
	beqz	$15,.L001f06e8
	lw	$15,0($29)
	ori	$15,$15,0x200
	sw	$15,0($29)
.L001f06e8:
	lbu	$15,36($16)
	beqz	$15,.L001f06fc
	lw	$15,0($29)
	ori	$15,$15,0x100
	sw	$15,0($29)
.L001f06fc:
	lbu	$15,37($16)
	beqz	$15,.L001f0844
	lw	$15,0($29)
	li	$14,-17
	lui	$19,0x1da
	addiu	$4,$29,96
	and	$15,$15,$14
	lw	$6,-6424($19)
	ori	$15,$15,0x2000
	sw	$4,48($29)
	sw	$15,0($29)
	lui	$5,0x1da
	addiu	$6,$6,16
	jal	0x2f3d08
	addiu	$5,$5,-6080
	lw	$9,4($16)
.L001f073c:
	lbu	$15,32($16)
	lui	$14,0x1da
	addiu	$14,$14,-5440
	li	$13,255
	bne	$15,$13,.L001f083c
	sw	$14,4($29)
	lhu	$15,22($17)
.L001f0758:
	sh	$15,8($29)
	lui	$16,0x1da
	li	$13,36
	move	$4,$17
	lui	$15,0x37
	lwc1	$f1,16($18)
	addiu	$15,$15,304
	lwc1	$f2,4($18)
	lwc1	$f0,0($15)
	mult	$13,$9,$13
	sw	$0,12($29)
	move	$5,$29
	mul.s	$f2,$f2,$f0
	lui	$15,0x1da
	mul.s	$f1,$f1,$f0
	addiu	$15,$15,-5696
	sw	$15,36($29)
	sw	$0,28($29)
	sb	$0,10($29)
	cvt.w.s	$f0,$f1
	lw	$12,-6424($19)
	lw	$10,-5468($16)
	addiu	$14,$12,80
	sw	$0,68($29)
	addiu	$11,$12,16
	sw	$14,32($29)
	mfc1	$15,$f0
	sw	$11,44($29)
	cvt.w.s	$f0,$f2
	sw	$15,20($29)
	sw	$10,52($29)
	mfc1	$15,$f0
	sw	$15,16($29)
	lui	$15,0x1da
	addiu	$15,$15,-5760
	sw	$15,40($29)
	lw	$14,144($12)
	lui	$15,0x1da
	lw	$11,-6428($15)
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
.L001f0820:
	ld	$16,160($29)
	ld	$17,168($29)
	ld	$18,176($29)
	ld	$19,184($29)
	ld	$31,192($29)
	jr	$31
	addiu	$29,$29,208
.L001f083c:
	b	.L001f0758
	lhu	$15,32($16)
.L001f0844:
	sw	$0,48($29)
	b	.L001f073c
	lui	$19,0x1da
.L001f0850:
	andi	$15,$14,0x1
	andi	$15,$15,0xff
	beqz	$15,.L001f069c
	li	$15,128
	b	.L001f069c
	sw	$15,0($29)
	.end func_001f0600
	.size func_001f0600, .-func_001f0600
