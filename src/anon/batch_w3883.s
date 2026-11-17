# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3883).
# These functions were long-standing C/C++ near misses (many sessions and permuter runs); see ledger
# attempts.tsv and the best/ADDR_w3883.* drafts. Replace with C/C++ after 100%.
#   func_001c4918: ambient wave update and random ground-effect spawn (sched1 order of the pool load
#                  against the D_003638d0 reload in the inlined random generator; v.w zero in an FP reg)
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
