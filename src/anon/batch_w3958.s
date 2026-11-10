# Whole-function assembly (last step of the README match ladder, w3958 2026-11-11).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_001f1978: partMng trail/ribbon strip draw (GS packet setup on scratchpad 0x70000000/0x70002000,
#     blend jump table, per-segment VU0 lerp of vertex pairs, func_001f4640 projection, z fade, u/v scroll).
#     Closest C: ~/re/kh2/tmp.w3958/best_001f1978.c (= coord best/001f1978_w3851_nsa.c, _nsa, ~235 lines off):
#     step/ucur/fade values kept in stack slots via mfc1/sw (ours keeps them in FPRs), 2.0f hoisted, scheduling.
#     No symbol, written as literal lui/addiu values: 0x00370158/0x0037015c/0x00370160 (float pool 1.0f, 2.0f,
#     1000000.0f) and 0x00370164 (5-entry jump table for the blend switch, targets inside this function;
#     the table stays original rodata), scratchpad 0x70000000.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_001f1978,"ax",@progbits
	.align 2
	.globl func_001f1978
	.type func_001f1978, @function
	.ent func_001f1978
func_001f1978:
	addiu	$29,$29,-304
	lui	$13,0x3f80
	sd	$16,176($29)
	sd	$22,224($29)
	swc1	$f31,300($29)
	move	$16,$4
	swc1	$f29,292($29)
	move	$22,$5
	sw	$0,128($29)
	sd	$17,184($29)
	sd	$18,192($29)
	sd	$19,200($29)
	sd	$20,208($29)
	sd	$21,216($29)
	sd	$23,232($29)
	sd	$30,240($29)
	sd	$31,248($29)
	swc1	$f30,296($29)
	swc1	$f28,288($29)
	swc1	$f27,284($29)
	swc1	$f26,280($29)
	swc1	$f25,276($29)
	swc1	$f24,272($29)
	swc1	$f23,268($29)
	swc1	$f22,264($29)
	swc1	$f21,260($29)
	swc1	$f20,256($29)
	sw	$6,112($29)
	lwc1	$f29,128($29)
	lhu	$15,6($6)
	lbu	$10,18($5)
	mov.s	$f31,$f29
	sltiu	$15,$15,3
	sw	$10,124($29)
	swc1	$f29,140($29)
	sw	$13,136($29)
	swc1	$f29,144($29)
	sw	$7,116($29)
	sw	$8,120($29)
	bnez	$15,.L001f1e74
	sw	$0,148($29)
	beqz	$4,.L001f25c4
	move	$18,$0
	lw	$15,28($4)
	lw	$14,4($15)
	addu	$15,$15,$14
	lwu	$18,12($15)
	lwu	$17,8($15)
.L001f1a38:
	sw	$0,132($29)
	move	$4,$22
	addiu	$5,$29,96
	addiu	$6,$29,100
	addiu	$7,$29,104
	jal	func_001f1870
	addiu	$8,$29,108
	lbu	$15,161($22)
	bnez	$15,.L001f24e4
	lbu	$14,160($22)
	li	$15,1
	beq	$14,$15,.L001f24bc
	slti	$15,$14,2
	beqz	$15,.L001f24ac
	li	$15,2
	beqz	$14,.L001f2478
	lwc1	$f0,96($29)
.L001f1a7c:
	lbu	$15,23($22)
.L001f1a80:
	beqz	$15,.L001f1b0c
	lui	$10,0x3f80
	lwc1	$f1,124($29)
	lwc1	$f0,24($22)
	cvt.s.w	$f1,$f1
	mtc1	$0,$f3
	sw	$10,136($29)
	mul.s	$f2,$f1,$f0
	cvt.w.s	$f4,$f2
	mfc1	$15,$f4
	mtc1	$15,$f2
	cvt.s.w	$f2,$f2
	c.le.s	$f2,$f3
	bc1t	.L001f1ac4
	sub.s	$f1,$f1,$f2
	swc1	$f3,136($29)
	mtc1	$0,$f3
.L001f1ac4:
	c.lt.s	$f3,$f2
	bc1f	.L001f1ae8
	lui	$10,0x37
	addiu	$10,$10,344
	lwc1	$f0,0($10)
	nop
	nop
	div.s	$f4,$f0,$f2
	swc1	$f4,144($29)
.L001f1ae8:
	c.lt.s	$f3,$f1
	bc1f	.L001f1b0c
	lui	$10,0x37
	addiu	$10,$10,344
	lwc1	$f0,0($10)
	nop
	nop
	div.s	$f2,$f0,$f1
	swc1	$f2,140($29)
.L001f1b0c:
	lui	$14,0x7000
	lui	$15,0x7000
	ori	$14,$14,0x2000
	sw	$15,32($29)
	sw	$14,36($29)
	lui	$19,0x7000
	por	$10,$0,$0
	sq	$10,0($19)
	ori	$15,$15,0x7
	li	$14,3
	lui	$13,0x7000
	sw	$15,0($19)
	dsll32	$14,$14,0x1d
	ori	$13,$13,0x10
	ori	$14,$14,0x8001
	lui	$15,0xee
	sd	$14,0($13)
	ori	$15,$15,0xeeee
	sd	$15,8($13)
	lbu	$15,20($22)
	bnez	$15,.L001f2464
	lui	$15,0x7000
	li	$14,71
	ori	$15,$15,0x20
	lui	$13,0x7
.L001f1b70:
	sd	$14,8($15)
	ori	$13,$13,0xd
	li	$14,1
	sd	$13,0($15)
	lui	$12,0x7000
	dsll32	$14,$14,0x0
	ori	$12,$12,0x30
	lui	$15,%hi(D_00352bf4)
	lw	$13,%lo(D_00352bf4)($15)
	lui	$15,0x3100
	or	$13,$13,$15
	or	$14,$13,$14
	li	$15,78
	sd	$15,8($12)
	lui	$13,0x7000
	sd	$14,0($12)
	ori	$13,$13,0x40
	li	$15,6
	dsll32	$14,$17,0x0
	sd	$15,8($13)
	dsll32	$12,$18,0x0
	dsra32	$14,$14,0x0
	dsra32	$12,$12,0x0
	sw	$14,0($13)
	sw	$12,4($13)
	lbu	$14,21($22)
	sltiu	$15,$14,5
	beqz	$15,.L001f245c
	li	$17,5
	sll	$15,$14,0x2
	lui	$14,0x37
	addiu	$14,$14,356
	addu	$15,$15,$14
	lw	$13,0($15)
	jr	$13
	nop
	li	$15,1
	sll	$13,$17,0x4
	dsll32	$15,$15,0x7
	addu	$14,$13,$19
	ori	$15,$15,0x44
.L001f1c14:
	sd	$15,0($14)
.L001f1c18:
	addu	$14,$13,$19
	li	$15,66
	sd	$15,8($14)
	addiu	$17,$17,1
	sll	$13,$17,0x4
	lui	$4,0x7000
	addu	$13,$13,$19
	li	$15,20
	sd	$15,8($13)
	li	$14,96
	sd	$14,0($13)
	addiu	$17,$17,1
	sll	$15,$17,0x4
	addu	$15,$15,$19
	li	$14,8
	sd	$14,8($15)
	jal	func_001e7470
	sd	$0,0($15)
	jal	func_001e7440
	nop
	lbu	$14,19($22)
	por	$11,$0,$0
	lw	$12,32($29)
	sll	$14,$14,0x1
	lw	$13,36($29)
	addiu	$14,$14,2
	sw	$14,152($29)
	sll	$15,$14,0x1
	addu	$15,$15,$14
	sq	$11,0($13)
	addiu	$15,$15,1
	lui	$14,0x7000
	sq	$11,0($12)
	or	$15,$15,$14
	sw	$15,0($13)
	beqz	$16,.L001f23e4
	sw	$15,0($12)
	lw	$14,152($29)
	ori	$15,$14,0x8000
	li	$14,0xc0b9
	move	$15,$15
	dsll32	$14,$14,0xe
	or	$15,$15,$14
.L001f1cc4:
	sd	$15,16($13)
	li	$14,1042
	lui	$11,0x37
	sd	$15,16($12)
	addiu	$11,$11,344
	lwc1	$f30,0($11)
	lw	$10,152($29)
	srl	$15,$10,0x1f
	sd	$14,24($13)
	addu	$15,$10,$15
	sra	$15,$15,0x1
	sw	$15,152($29)
	sd	$14,24($12)
	sw	$0,160($29)
	sw	$0,156($29)
	lw	$13,116($29)
	lw	$10,116($29)
	lbu	$11,11($13)
	lbu	$14,8($13)
	lbu	$15,10($10)
	andi	$12,$11,0xff
	lbu	$13,9($13)
	sw	$14,16($29)
	sw	$13,20($29)
	sw	$15,24($29)
	sw	$12,28($29)
	lw	$13,124($29)
	lq	$15,16($29)
	bnez	$13,.L001f1ed4
	sq	$15,0($29)
.L001f1d3c:
	jal	func_001e7440
	nop
	lui	$15,%hi(D_01d9ea9c)
	lw	$14,%lo(D_01d9ea9c)($15)
	bnez	$14,.L001f1e78
	ld	$16,176($29)
	lui	$14,%hi(D_01d9e6e0)
	lw	$13,%lo(D_01d9e6e0)($14)
	li	$14,255
	ld	$15,168($13)
	dsll32	$14,$14,0x0
	ori	$14,$14,0xff00
	and	$15,$15,$14
	bnez	$15,.L001f1e7c
	ld	$17,184($29)
	lw	$11,112($29)
	lui	$13,0x37
	lwc1	$f2,152($22)
	addiu	$13,$13,344
	lwc1	$f0,40($11)
	lwc1	$f1,36($11)
	add.s	$f3,$f0,$f2
	swc1	$f3,40($11)
	lwc1	$f2,0($13)
	lwc1	$f0,148($22)
	c.lt.s	$f2,$f3
	add.s	$f1,$f1,$f0
	bc1f	.L001f1dcc
	swc1	$f1,36($11)
	mov.s	$f0,$f3
	sub.s	$f0,$f0,$f2
.L001f1db8:
	c.lt.s	$f2,$f0
	bc1tl	.L001f1db8
	sub.s	$f0,$f0,$f2
	lw	$14,112($29)
	swc1	$f0,40($14)
.L001f1dcc:
	lw	$15,112($29)
	mtc1	$0,$f3
	lwc1	$f1,40($15)
	c.lt.s	$f1,$f3
	bc1f	.L001f1e04
	lui	$10,0x37
	addiu	$10,$10,344
	lwc1	$f2,0($10)
.L001f1dec:
	add.s	$f0,$f1,$f2
	c.lt.s	$f0,$f3
	bc1t	.L001f1dec
	mov.s	$f1,$f0
	lw	$11,112($29)
	swc1	$f0,40($11)
.L001f1e04:
	lw	$13,112($29)
	lui	$14,0x37
	addiu	$14,$14,344
	lwc1	$f3,36($13)
	lwc1	$f2,0($14)
	c.lt.s	$f2,$f3
	bc1f	.L001f1e40
	mov.s	$f1,$f3
.L001f1e24:
	sub.s	$f0,$f1,$f2
	c.lt.s	$f2,$f0
	bc1t	.L001f1e24
	mov.s	$f1,$f0
	lw	$15,112($29)
	mov.s	$f3,$f0
	swc1	$f0,36($15)
.L001f1e40:
	mov.s	$f1,$f3
	mtc1	$0,$f3
	c.lt.s	$f1,$f3
	bc1f	.L001f1e74
	lui	$10,0x37
	addiu	$10,$10,344
	lwc1	$f2,0($10)
.L001f1e5c:
	add.s	$f0,$f1,$f2
	c.lt.s	$f0,$f3
	bc1t	.L001f1e5c
	mov.s	$f1,$f0
	lw	$11,112($29)
	swc1	$f0,36($11)
.L001f1e74:
	ld	$16,176($29)
.L001f1e78:
	ld	$17,184($29)
.L001f1e7c:
	ld	$18,192($29)
	ld	$19,200($29)
	ld	$20,208($29)
	ld	$21,216($29)
	ld	$22,224($29)
	ld	$23,232($29)
	ld	$30,240($29)
	ld	$31,248($29)
	lwc1	$f31,300($29)
	lwc1	$f30,296($29)
	lwc1	$f29,292($29)
	lwc1	$f28,288($29)
	lwc1	$f27,284($29)
	lwc1	$f26,280($29)
	lwc1	$f25,276($29)
	lwc1	$f24,272($29)
	lwc1	$f23,268($29)
	lwc1	$f22,264($29)
	lwc1	$f21,260($29)
	lwc1	$f20,256($29)
	jr	$31
	addiu	$29,$29,304
.L001f1ed4:
	lbu	$15,23($22)
	li	$10,1
	beqz	$15,.L001f23d0
	sw	$10,164($29)
	andi	$15,$11,0xff
	lw	$13,136($29)
	mtc1	$15,$f0
	lui	$10,0x37
	mtc1	$13,$f1
	addiu	$10,$10,344
	cvt.s.w	$f0,$f0
	mul.s	$f28,$f0,$f1
	lwc1	$f1,0($10)
	mtc1	$13,$f0
	c.le.s	$f1,$f0
	bc1f	.L001f1f28
	lw	$10,148($29)
	bnez	$10,.L001f23bc
	lw	$10,136($29)
	li	$13,1
	sw	$13,148($29)
.L001f1f28:
	lw	$14,148($29)
	bnez	$14,.L001f23bc
	lw	$10,136($29)
	lw	$15,136($29)
	mtc1	$15,$f0
	lw	$15,144($29)
	mtc1	$15,$f1
	add.s	$f0,$f0,$f1
.L001f1f48:
	swc1	$f0,136($29)
	lw	$10,136($29)
	mtc1	$0,$f0
	mtc1	$10,$f1
	c.lt.s	$f1,$f0
	bc1tl	.L001f1f88
	swc1	$f0,136($29)
	lui	$10,0x37
	lw	$13,136($29)
	addiu	$10,$10,344
	lwc1	$f0,0($10)
	mtc1	$13,$f1
	c.le.s	$f0,$f1
	bc1f	.L001f1f8c
	andi	$15,$11,0xff
	swc1	$f0,136($29)
.L001f1f88:
	andi	$15,$11,0xff
.L001f1f8c:
	lw	$10,136($29)
	mtc1	$15,$f0
	mtc1	$10,$f1
	cvt.s.w	$f0,$f0
	mul.s	$f27,$f0,$f1
.L001f1fa0:
	lwc1	$f3,144($22)
	mtc1	$0,$f0
	c.le.s	$f3,$f0
	bc1f	.L001f2368
	lw	$10,128($29)
	lwc1	$f26,132($29)
	mtc1	$10,$f1
	lwc1	$f0,100($29)
	add.s	$f25,$f26,$f1
	c.lt.s	$f0,$f25
	bc1f	.L001f1fd4
	swc1	$f25,132($29)
	swc1	$f0,132($29)
.L001f1fd4:
	lw	$10,112($29)
	lwc1	$f0,36($10)
	add.s	$f25,$f25,$f0
	lbu	$10,22($22)
	andi	$15,$10,0xff
	beqz	$15,.L001f201c
	add.s	$f26,$f26,$f0
	lw	$11,152($29)
	lui	$13,0x37
	addiu	$13,$13,348
	mtc1	$0,$f29
	addiu	$23,$11,-1
	lwc1	$f0,0($13)
	mtc1	$23,$f1
	cvt.s.w	$f1,$f1
	nop
	nop
	div.s	$f31,$f0,$f1
.L001f201c:
	lw	$14,160($29)
	li	$17,2
	sll	$15,$14,0x2
	xori	$14,$14,0x1
	addu	$15,$15,$29
	sw	$14,160($29)
	lw	$19,32($15)
	lw	$15,152($29)
	blez	$15,.L001f22f4
	move	$21,$0
	lw	$11,156($29)
	addiu	$23,$15,-1
	addiu	$20,$29,48
	sll	$30,$11,0x4
.L001f2054:
	mtc1	$21,$f1
	andi	$15,$10,0xff
	mtc1	$23,$f0
	cvt.s.w	$f1,$f1
	lw	$13,112($29)
	cvt.s.w	$f0,$f0
	lwc1	$f2,104($29)
	mov.s	$f21,$f28
	mov.s	$f22,$f27
	nop
	nop
	div.s	$f20,$f1,$f0
	lwc1	$f0,108($29)
	lwc1	$f1,40($13)
	sub.s	$f0,$f0,$f2
	mul.s	$f0,$f0,$f20
	add.s	$f23,$f0,$f2
	beqz	$15,.L001f20cc
	add.s	$f23,$f23,$f1
	mul.s	$f21,$f28,$f29
	lui	$14,0x37
	mul.s	$f22,$f27,$f29
	addiu	$14,$14,344
	lwc1	$f0,0($14)
	add.s	$f29,$f29,$f31
	c.le.s	$f0,$f29
	bc1fl	.L001f2354
	mtc1	$0,$f0
	mov.s	$f29,$f0
	neg.s	$f31,$f31
.L001f20cc:
	lw	$15,120($29)
.L001f20d0:
	mfc1	$10,$f20
	addu	$16,$15,$30
	addiu	$15,$16,4096
	lqc2	$vf4,0($15)
	lqc2	$vf5,0($16)
	qmtc2	$10,$vf6
	vaddw.x	$vf7,$vf0,vf0w
	vsub.x	$vf8,$vf7,$vf6
	vmulax.wxyz	ACC,$vf4,vf6x
	vmaddx.wxyz	$vf9,$vf5,vf8x
	sqc2	$vf9,0($20)
	lui	$11,0x37
	lui	$15,%hi(D_01d9e8c0)
	addiu	$11,$11,344
	addiu	$18,$15,%lo(D_01d9e8c0)
	lwc1	$f24,0($11)
	move	$4,$20
	addiu	$5,$29,64
	move	$6,$18
	jal	func_001f4640
	swc1	$f24,60($29)
	beqz	$2,.L001f234c
	addiu	$15,$16,16
	mfc1	$13,$f20
	addiu	$14,$16,4112
	lqc2	$vf4,0($14)
	lqc2	$vf5,0($15)
	qmtc2	$13,$vf6
	vaddw.x	$vf7,$vf0,vf0w
	vsub.x	$vf8,$vf7,$vf6
	vmulax.wxyz	ACC,$vf4,vf6x
	vmaddx.wxyz	$vf9,$vf5,vf8x
	sqc2	$vf9,0($20)
	swc1	$f24,60($29)
	move	$6,$18
	move	$4,$20
	jal	func_001f4640
	addiu	$5,$29,80
	beqz	$2,.L001f234c
	lw	$14,72($29)
	cvt.w.s	$f0,$f21
	lui	$12,0x1e
	ori	$12,$12,0x8480
	slt	$15,$12,$14
	mfc1	$11,$f0
	cvt.w.s	$f0,$f22
	sw	$11,28($29)
	mfc1	$10,$f0
	bnez	$15,.L001f234c
	sw	$10,12($29)
	lui	$13,0xf
	ori	$13,$13,0x4240
	slt	$15,$13,$14
	beqz	$15,.L001f21e8
	lui	$10,0x37
	mtc1	$14,$f1
	addiu	$10,$10,352
	mtc1	$11,$f2
	cvt.s.w	$f1,$f1
	lwc1	$f0,0($10)
	cvt.s.w	$f2,$f2
	sub.s	$f1,$f1,$f0
	nop
	nop
	div.s	$f1,$f1,$f0
	sub.s	$f1,$f24,$f1
	mul.s	$f2,$f2,$f1
	cvt.w.s	$f0,$f2
	mfc1	$11,$f0
	sw	$11,28($29)
.L001f21e8:
	lw	$14,88($29)
	slt	$15,$12,$14
	bnez	$15,.L001f234c
	slt	$15,$13,$14
	beqz	$15,.L001f223c
	lui	$10,0x37
	mtc1	$14,$f1
	addiu	$10,$10,352
	lwc1	$f2,12($29)
	cvt.s.w	$f1,$f1
	lwc1	$f0,0($10)
	cvt.s.w	$f2,$f2
	sub.s	$f1,$f1,$f0
	nop
	nop
	div.s	$f1,$f1,$f0
	sub.s	$f1,$f24,$f1
	mul.s	$f2,$f2,$f1
	cvt.w.s	$f0,$f2
	mfc1	$11,$f0
	sw	$11,12($29)
.L001f223c:
	lbu	$15,160($22)
	sltiu	$15,$15,2
	beqz	$15,.L001f233c
	mov.s	$f0,$f23
	mov.s	$f3,$f23
	mov.s	$f1,$f26
	mov.s	$f0,$f25
	mov.s	$f2,$f23
.L001f225c:
	sll	$15,$17,0x4
	addiu	$21,$21,1
	addu	$15,$15,$19
	addiu	$17,$17,1
	swc1	$f1,0($15)
	sll	$13,$17,0x4
	swc1	$f2,4($15)
	addu	$13,$13,$19
	sw	$0,12($15)
	addiu	$17,$17,1
	swc1	$f30,8($15)
	sll	$11,$17,0x4
	addu	$11,$11,$19
	addiu	$17,$17,1
	lq	$15,16($29)
	sll	$14,$17,0x4
	addu	$14,$14,$19
	addiu	$17,$17,1
	sq	$15,0($13)
	sll	$12,$17,0x4
	addu	$12,$12,$19
	addiu	$17,$17,1
	lq	$15,64($29)
	sll	$13,$17,0x4
	addu	$13,$13,$19
	addiu	$17,$17,1
	sq	$15,0($11)
	lw	$11,152($29)
	swc1	$f0,0($14)
	slt	$10,$21,$11
	swc1	$f3,4($14)
	sw	$0,12($14)
	swc1	$f30,8($14)
	lq	$15,0($29)
	sq	$15,0($12)
	lq	$14,80($29)
	bnez	$10,.L001f2334
	sq	$14,0($13)
.L001f22f4:
	jal	func_001e7440
	nop
	lw	$13,164($29)
	beqz	$13,.L001f2314
	lw	$14,156($29)
	jal	func_001e7470
	move	$4,$19
	lw	$14,156($29)
.L001f2314:
	lw	$10,124($29)
	addiu	$14,$14,1
	slt	$15,$14,$10
	beqz	$15,.L001f1d3c
	sw	$14,156($29)
	lw	$14,116($29)
	b	.L001f1ed4
	lbu	$11,11($14)
.L001f2334:
	b	.L001f2054
	lbu	$10,22($22)
.L001f233c:
	mov.s	$f2,$f26
	mov.s	$f3,$f25
	b	.L001f225c
	mov.s	$f1,$f23
.L001f234c:
	b	.L001f22f4
	sw	$0,164($29)
.L001f2354:
	c.le.s	$f29,$f0
	bc1tl	.L001f20cc
	mov.s	$f29,$f0
	b	.L001f20d0
	lw	$15,120($29)
.L001f2368:
	lw	$11,156($29)
	lw	$13,120($29)
	sll	$30,$11,0x4
	lwc1	$f2,100($29)
	addu	$15,$30,$13
	lwc1	$f4,96($29)
	lwc1	$f1,12($15)
	sub.s	$f0,$f2,$f4
	nop
	nop
	div.s	$f1,$f1,$f3
	lwc1	$f26,132($29)
	mul.s	$f0,$f0,$f1
	add.s	$f25,$f26,$f0
	c.lt.s	$f2,$f25
	bc1f	.L001f1fd4
	swc1	$f25,132($29)
	sub.s	$f0,$f25,$f2
	add.s	$f1,$f0,$f4
	b	.L001f1fd4
	swc1	$f1,132($29)
.L001f23bc:
	mtc1	$10,$f0
	lw	$10,140($29)
	mtc1	$10,$f1
	b	.L001f1f48
	sub.s	$f0,$f0,$f1
.L001f23d0:
	andi	$15,$11,0xff
	mtc1	$15,$f27
	cvt.s.w	$f27,$f27
	b	.L001f1fa0
	mov.s	$f28,$f27
.L001f23e4:
	lw	$15,152($29)
	ori	$14,$15,0x8000
	li	$15,0xc0b9
	dsll32	$15,$15,0xe
	b	.L001f1cc4
	or	$15,$14,$15
	li	$15,1
	sll	$13,$17,0x4
	dsll32	$15,$15,0x7
	addu	$14,$13,$19
	b	.L001f1c14
	ori	$15,$15,0x48
	li	$15,1
	sll	$13,$17,0x4
	dsll32	$15,$15,0x7
	addu	$14,$13,$19
	b	.L001f1c14
	ori	$15,$15,0x42
	li	$15,1
	sll	$13,$17,0x4
	dsll32	$15,$15,0x7
	addu	$14,$13,$19
	b	.L001f1c14
	ori	$15,$15,0x41
	li	$15,1
	sll	$13,$17,0x4
	dsll32	$15,$15,0x7
	addu	$14,$13,$19
	b	.L001f1c14
	ori	$15,$15,0x46
.L001f245c:
	b	.L001f1c18
	li	$13,80
.L001f2464:
	li	$14,71
	ori	$15,$15,0x20
	b	.L001f1b70
	lui	$13,0x3
.L001f2474:
	lwc1	$f0,96($29)
.L001f2478:
	lwc1	$f1,124($29)
	mfc1	$10,$f0
	swc1	$f0,132($29)
	mtc1	$10,$f2
	lwc1	$f0,100($29)
	cvt.s.w	$f1,$f1
	sub.s	$f0,$f0,$f2
.L001f2494:
	nop
	nop
	div.s	$f2,$f0,$f1
	mfc1	$10,$f2
.L001f24a4:
	b	.L001f1a7c
	sw	$10,128($29)
.L001f24ac:
	beq	$14,$15,.L001f2474
	li	$15,3
	bnel	$14,$15,.L001f1a80
	lbu	$15,23($22)
.L001f24bc:
	lwc1	$f0,100($29)
	lwc1	$f1,124($29)
	mfc1	$10,$f0
	swc1	$f0,132($29)
	mtc1	$10,$f2
	lwc1	$f0,96($29)
	cvt.s.w	$f1,$f1
	sub.s	$f0,$f2,$f0
	b	.L001f2494
	neg.s	$f0,$f0
.L001f24e4:
	li	$15,1
	beq	$14,$15,.L001f2570
	slti	$15,$14,2
	beqz	$15,.L001f2560
	li	$15,2
	bnezl	$14,.L001f1a80
	lbu	$15,23($22)
.L001f2500:
	lw	$10,112($29)
	lwc1	$f0,96($29)
	lhu	$15,6($10)
	lbu	$14,4($10)
	mtc1	$15,$f2
	mtc1	$14,$f1
	cvt.s.w	$f2,$f2
	cvt.s.w	$f1,$f1
	mfc1	$11,$f0
	swc1	$f0,132($29)
	lwc1	$f3,124($29)
	nop
	nop
	div.s	$f2,$f2,$f1
	lwc1	$f0,100($29)
	cvt.s.w	$f3,$f3
	mtc1	$11,$f1
	sub.s	$f0,$f0,$f1
	mul.s	$f0,$f0,$f2
.L001f254c:
	nop
	nop
	div.s	$f1,$f0,$f3
	b	.L001f24a4
	mfc1	$10,$f1
.L001f2560:
	beq	$14,$15,.L001f2500
	li	$15,3
	bnel	$14,$15,.L001f1a80
	lbu	$15,23($22)
.L001f2570:
	lw	$10,112($29)
	lwc1	$f0,100($29)
	lhu	$15,6($10)
	lbu	$14,4($10)
	mtc1	$15,$f2
	mtc1	$14,$f1
	cvt.s.w	$f2,$f2
	cvt.s.w	$f1,$f1
	mfc1	$11,$f0
	swc1	$f0,132($29)
	lwc1	$f3,124($29)
	nop
	nop
	div.s	$f2,$f2,$f1
	lwc1	$f0,96($29)
	cvt.s.w	$f3,$f3
	mtc1	$11,$f1
	sub.s	$f0,$f1,$f0
	mul.s	$f0,$f0,$f2
	b	.L001f254c
	neg.s	$f0,$f0
.L001f25c4:
	b	.L001f1a38
	move	$17,$0
	.end func_001f1978
	.size func_001f1978, 3156
