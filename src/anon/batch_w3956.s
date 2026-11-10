# Whole-function assembly (last step of the README match ladder, w3956 2026-11-11).
# Transcribed from the retail disassembly; calls with a func_ symbol are referenced through it.
# Replace with C/C++ after 100%.
#   func_00221348: trail (ribbon) emitter update: advances the ring of trail points behind a moving source,
#     bends the direction towards the current target point with random jitter (rotation callbacks from the
#     table at 0x0035da20), and spawns child trails.
#     Closest C: ~/re/kh2/tmp.w3956/best_00221348.c (_nsa, = coord best/00221348_w3819_nsa.c, ~490 lines off):
#     &dir (sp+80) is CSE'd into a long-lived pseudo in s7 (the original rematerialises addiu a0,sp,80
#     14 times), so i and one more value spill and the frame is 384 instead of 368.
#     No symbol, written as literal lui/addiu values: 0x0035da20 (rotation callback table),
#     0x00370ba4, 0x00370ba8, 0x00370bac, 0x00370bb0 (float literal pool).
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00221348,"ax",@progbits
	.align 2
	.globl func_00221348
	.type func_00221348, @function
	.ent func_00221348
func_00221348:
	addiu	$29,$29,-368
	sd	$16,272($29)
	sd	$17,280($29)
	sd	$18,288($29)
	sd	$19,296($29)
	sd	$20,304($29)
	sd	$21,312($29)
	sd	$22,320($29)
	sd	$23,328($29)
	sd	$30,336($29)
	sd	$31,344($29)
	swc1	$f21,356($29)
	swc1	$f20,352($29)
	sw	$4,224($29)
	lw	$10,64($4)
	sw	$10,228($29)
	lhu	$11,62($10)
	andi	$12,$11,0xffff
	andi	$15,$12,0x800
	beqz	$15,.L002213a8
	sw	$12,232($29)
	ori	$12,$12,0x40
	andi	$12,$12,0xf7ff
	sw	$12,232($29)
.L002213a8:
	lw	$13,232($29)
	andi	$15,$13,0x8
	beqz	$15,.L00221414
	andi	$15,$13,0x20
	bnez	$15,.L00221404
	lw	$10,232($29)
	lw	$14,228($29)
	ori	$13,$13,0x10
	sh	$13,62($14)
.L002213cc:
	ld	$16,272($29)
	ld	$17,280($29)
	ld	$18,288($29)
	ld	$19,296($29)
	ld	$20,304($29)
	ld	$21,312($29)
	ld	$22,320($29)
	ld	$23,328($29)
	ld	$30,336($29)
	ld	$31,344($29)
	lwc1	$f21,356($29)
	lwc1	$f20,352($29)
	jr	$31
	addiu	$29,$29,368
.L00221404:
	li	$15,-9
	and	$10,$10,$15
	ori	$10,$10,0x100
	sw	$10,232($29)
.L00221414:
	lw	$12,228($29)
	lw	$14,224($29)
	lwc1	$f21,24($12)
	addiu	$13,$12,64
	cvt.w.s	$f0,$f21
	sw	$13,236($29)
	lw	$13,76($14)
	mfc1	$15,$f0
	sw	$0,264($29)
	sw	$15,244($29)
	lhu	$10,28($12)
	li	$15,255
	sw	$10,240($29)
	lbu	$12,55($12)
	sw	$12,256($29)
	lbu	$14,65($13)
	beq	$14,$15,.L00221470
	sw	$14,260($29)
	lw	$15,228($29)
	lbu	$14,30($15)
	lbu	$15,64($13)
	sltu	$14,$14,$15
	sw	$14,264($29)
.L00221470:
	lwc1	$f0,52($13)
	andi	$15,$11,0x400
	lw	$10,232($29)
	andi	$15,$15,0xffff
	add.s	$f0,$f21,$f0
	sw	$15,268($29)
	andi	$14,$10,0x2
	lw	$10,244($29)
	cvt.w.s	$f1,$f0
	mfc1	$12,$f1
	subu	$23,$12,$10
	bnez	$14,.L00221e14
	move	$16,$23
	lw	$14,232($29)
	andi	$15,$14,0x4
	bnez	$15,.L00221e08
	mov.s	$f21,$f0
	lbu	$13,66($13)
	slt	$15,$12,$13
	bnez	$15,.L00221e00
	lw	$10,232($29)
	andi	$14,$14,0x80
	ori	$15,$10,0x20
	movn	$10,$15,$14
	andi	$5,$10,0x20
	bnez	$5,.L00221de0
	sw	$10,232($29)
	mtc1	$13,$f21
	subu	$16,$12,$13
	subu	$23,$23,$16
	cvt.s.w	$f21,$f21
.L002214ec:
	move	$22,$23
.L002214f0:
	bnez	$5,.L00221da4
	lw	$12,228($29)
	lw	$13,232($29)
	andi	$15,$13,0x100
	beqz	$15,.L00221d98
	move	$16,$0
	lw	$14,224($29)
	lw	$15,228($29)
	lw	$20,68($14)
	sw	$20,20($15)
.L00221518:
	lw	$13,228($29)
.L0022151c:
	li	$15,48
	lw	$14,236($29)
	move	$23,$16
	lhu	$30,52($13)
	mult	$15,$30,$15
	blez	$16,.L00221578
	addu	$19,$14,$15
	lw	$18,256($29)
	move	$17,$5
	lw	$21,236($29)
	move	$4,$19
.L00221548:
	jal	func_00220088
	move	$5,$17
	addiu	$30,$30,1
	bne	$30,$18,.L00221564
	addiu	$19,$19,48
	move	$30,$0
	move	$19,$21
.L00221564:
	addiu	$23,$23,-1
	bgtz	$23,.L00221548
	move	$4,$19
	sw	$21,236($29)
	sw	$18,256($29)
.L00221578:
	mtc1	$16,$f1
	addiu	$4,$29,112
	lw	$15,228($29)
	move	$5,$20
	cvt.s.w	$f1,$f1
	addiu	$17,$19,32
	sh	$30,52($15)
	move	$23,$0
	lwc1	$f0,48($15)
	lw	$12,240($29)
	lw	$10,244($29)
	add.s	$f0,$f0,$f1
	subu	$10,$10,$12
	sw	$10,248($29)
	addu	$22,$10,$22
	swc1	$f0,48($15)
	sw	$22,252($29)
	lw	$13,224($29)
	lw	$15,76($13)
	lwc1	$f0,32($15)
	swc1	$f0,128($29)
	lwc1	$f1,44($15)
	swc1	$f1,140($29)
	lwc1	$f0,16($20)
	swc1	$f0,144($29)
	lwc1	$f1,24($20)
	swc1	$f1,148($29)
	lwc1	$f0,20($20)
	swc1	$f0,152($29)
	lwc1	$f1,12($20)
	jal	func_002f3f88
	swc1	$f1,156($29)
	addiu	$4,$29,80
	jal	func_002226b8
	move	$5,$17
	sw	$0,92($29)
	addiu	$4,$29,96
	jal	func_002f3f88
	move	$5,$19
	lw	$15,232($29)
	andi	$14,$15,0x120
	li	$15,256
	bne	$14,$15,.L0022177c
	mtc1	$0,$f20
	addiu	$5,$29,112
	addiu	$6,$29,96
	jal	func_002f3f10
	addiu	$4,$29,64
	jal	func_002229a0
	addiu	$4,$29,64
	lwc1	$f3,144($29)
	lwc1	$f4,140($29)
	mov.s	$f1,$f0
	c.lt.s	$f0,$f3
	swc1	$f0,132($29)
	bc1f	.L00221688
	swc1	$f4,136($29)
	lwc1	$f0,148($29)
	lwc1	$f2,152($29)
	sub.s	$f1,$f1,$f0
	sub.s	$f0,$f3,$f0
	mul.s	$f1,$f2,$f1
	nop
	nop
	div.s	$f1,$f1,$f0
	sub.s	$f2,$f2,$f1
	add.s	$f2,$f4,$f2
	swc1	$f2,136($29)
.L00221688:
	addiu	$4,$29,64
	jal	func_002f3d98
	move	$5,$4
	addiu	$4,$29,80
	lwc1	$f12,136($29)
	addiu	$5,$29,64
	jal	func_002f3ed0
	move	$6,$4
	lw	$10,268($29)
	beqz	$10,.L002216bc
	addiu	$4,$29,80
	jal	func_002f3d98
	move	$5,$4
.L002216bc:
	jal	func_00222568
	nop
	li	$14,1001
	li	$15,3
	div	$0,$2,$14
	move	$4,$29
	beqzl	$15,.L002216dc
	break	0x7
.L002216dc:
	lw	$10,224($29)
	lw	$11,76($10)
	lwc1	$f12,40($11)
	mfhi	$12
	div	$0,$2,$15
	addiu	$12,$12,-500
	mtc1	$12,$f0
	cvt.s.w	$f0,$f0
	lui	$12,0x37
	addiu	$12,$12,2980
	mul.s	$f12,$f12,$f0
	lwc1	$f0,0($12)
	nop
	nop
	div.s	$f12,$f12,$f0
	mfhi	$13
	lui	$15,0x36
	addiu	$15,$15,-9696
	sll	$13,$13,0x2
	addu	$13,$13,$15
	lw	$15,0($13)
	jalr	$15
	lw	$5,224($29)
	addiu	$4,$29,80
	move	$5,$29
	jal	func_002f3cd8
	move	$6,$4
	lw	$13,224($29)
	addiu	$4,$29,80
	move	$6,$17
	move	$5,$4
	lw	$15,76($13)
	jal	func_002f3ed0
	lwc1	$f12,36($15)
	lw	$14,268($29)
	beqz	$14,.L00221778
	addiu	$4,$29,80
	jal	func_002f3d98
	move	$5,$4
.L00221778:
	mtc1	$0,$f20
.L0022177c:
	addiu	$5,$29,112
.L00221780:
	addiu	$6,$29,96
	jal	func_002f3f10
	addiu	$4,$29,64
	jal	func_002229a0
	addiu	$4,$29,64
	lwc1	$f2,156($29)
	mov.s	$f1,$f0
	c.eq.s	$f2,$f20
	bc1t	.L002217c4
	swc1	$f0,132($29)
	lwc1	$f0,24($20)
	c.lt.s	$f0,$f1
	bc1tl	.L002217d8
	lw	$5,28($20)
	c.eq.s	$f2,$f20
	bc1f	.L00221918
	lw	$13,252($29)
.L002217c4:
	lwc1	$f0,24($20)
	c.lt.s	$f1,$f0
	bc1f	.L00221918
	lw	$13,252($29)
	lw	$5,28($20)
.L002217d8:
	bnez	$5,.L002218dc
	move	$20,$5
	lw	$10,240($29)
	lw	$12,228($29)
	addu	$15,$10,$23
	sb	$30,54($12)
	addiu	$23,$23,1
	mtc1	$15,$f21
	lw	$13,232($29)
	cvt.s.w	$f21,$f21
	lw	$14,248($29)
	ori	$13,$13,0x800
	slt	$15,$14,$23
	bnez	$15,.L00221854
	sw	$13,232($29)
	lw	$17,248($29)
	andi	$16,$13,0x20
	lw	$21,236($29)
	lw	$15,256($29)
.L00221824:
	addiu	$30,$30,1
	bne	$30,$15,.L00221838
	addiu	$19,$19,48
	move	$30,$0
	move	$19,$21
.L00221838:
	move	$4,$19
	move	$5,$16
	jal	func_00220088
	addiu	$23,$23,1
	slt	$15,$17,$23
	beqz	$15,.L00221824
	lw	$15,256($29)
.L00221854:
	lw	$10,232($29)
	andi	$15,$10,0x80
	beqz	$15,.L00221868
	ori	$10,$10,0x20
	sw	$10,232($29)
.L00221868:
	lw	$14,228($29)
	lhu	$23,52($14)
	lbu	$30,54($14)
	slt	$15,$23,$30
	beqz	$15,.L002218a8
	subu	$15,$30,$23
	sh	$0,60($14)
	addiu	$15,$15,1
	sh	$15,56($14)
.L0022188c:
	lw	$14,232($29)
	lw	$13,228($29)
	sh	$14,62($13)
	swc1	$f21,24($13)
	lw	$15,240($29)
	b	.L002213cc
	sh	$15,28($13)
.L002218a8:
	slt	$15,$30,$23
	beqz	$15,.L002218cc
	lw	$10,228($29)
	addiu	$14,$30,1
	lbu	$15,55($10)
	sh	$14,60($10)
	subu	$15,$15,$23
	b	.L0022188c
	sh	$15,56($10)
.L002218cc:
	lw	$12,228($29)
	sh	$0,56($12)
	b	.L0022188c
	sh	$0,60($12)
.L002218dc:
	jal	func_002f3f88
	addiu	$4,$29,112
	bnezl	$23,.L002218f8
	lwc1	$f0,16($20)
	lw	$12,228($29)
	sw	$20,20($12)
	lwc1	$f0,16($20)
.L002218f8:
	swc1	$f0,144($29)
	lwc1	$f1,24($20)
	swc1	$f1,148($29)
	lwc1	$f0,20($20)
	swc1	$f0,152($29)
	lwc1	$f1,12($20)
	swc1	$f1,156($29)
	lw	$13,252($29)
.L00221918:
	addiu	$23,$23,1
	slt	$15,$13,$23
	bnez	$15,.L00221d8c
	lw	$14,256($29)
	addiu	$30,$30,1
	bne	$30,$14,.L00221d84
	move	$17,$19
	lw	$19,236($29)
	move	$30,$0
.L0022193c:
	addiu	$5,$29,96
	jal	func_002f3f88
	addiu	$4,$29,176
	addiu	$4,$29,160
	jal	func_002226b8
	addiu	$5,$29,80
	lwc1	$f12,128($29)
	addiu	$4,$29,192
	jal	func_002f3f40
	addiu	$5,$29,80
	addiu	$4,$29,96
	addiu	$6,$29,192
	jal	func_002f3ef8
	move	$5,$4
	move	$4,$19
	jal	func_002226b8
	addiu	$5,$29,96
	lwc1	$f1,132($29)
	lwc1	$f3,144($29)
	lwc1	$f4,140($29)
	c.lt.s	$f1,$f3
	bc1f	.L002219c4
	swc1	$f4,136($29)
	lwc1	$f0,148($29)
	lwc1	$f2,152($29)
	sub.s	$f1,$f1,$f0
	sub.s	$f0,$f3,$f0
	mul.s	$f1,$f2,$f1
	nop
	nop
	div.s	$f1,$f1,$f0
	sub.s	$f2,$f2,$f1
	add.s	$f2,$f4,$f2
	swc1	$f2,136($29)
.L002219c4:
	addiu	$4,$29,64
	jal	func_002f3d98
	move	$5,$4
	addiu	$4,$29,80
	lwc1	$f12,136($29)
	addiu	$5,$29,64
	jal	func_002f3ed0
	move	$6,$4
	lw	$15,268($29)
	beqz	$15,.L002219f8
	addiu	$4,$29,80
	jal	func_002f3d98
	move	$5,$4
.L002219f8:
	jal	func_00222568
	nop
	li	$14,1001
	li	$15,3
	div	$0,$2,$14
	move	$16,$2
	beqzl	$15,.L00221a18
	break	0x7
.L00221a18:
	lw	$10,224($29)
	move	$4,$29
	lw	$11,76($10)
	lwc1	$f12,40($11)
	mfhi	$12
	div	$0,$2,$15
	addiu	$12,$12,-500
	mtc1	$12,$f0
	cvt.s.w	$f0,$f0
	lui	$12,0x36
	addiu	$12,$12,-9696
	mul.s	$f12,$f12,$f0
	mfhi	$13
	sll	$13,$13,0x2
	addu	$13,$13,$12
	lw	$15,0($13)
	lui	$13,0x37
	addiu	$13,$13,2980
	lwc1	$f0,0($13)
	nop
	nop
	div.s	$f12,$f12,$f0
	jalr	$15
	lw	$5,224($29)
	addiu	$4,$29,80
	move	$5,$29
	jal	func_002f3cd8
	move	$6,$4
	lw	$14,248($29)
	slt	$15,$14,$23
	bnezl	$15,.L00221bc4
	mtc1	$16,$f0
	lw	$10,224($29)
	addiu	$4,$29,80
	addiu	$22,$19,32
	move	$5,$4
	lw	$15,76($10)
	move	$6,$22
	jal	func_002f3ed0
	lwc1	$f12,36($15)
	lw	$12,268($29)
	beqz	$12,.L00221acc
	addiu	$4,$29,80
	jal	func_002f3d98
	move	$5,$4
.L00221acc:
	mtc1	$16,$f0
	lui	$13,0x37
	addiu	$13,$13,2984
	lw	$14,224($29)
	cvt.s.w	$f0,$f0
	lui	$12,0x37
	lwc1	$f1,0($13)
	addiu	$12,$12,2992
	lw	$15,76($14)
	lui	$10,0x37
	lwc1	$f3,28($17)
	addiu	$10,$10,2988
	nop
	nop
	div.s	$f0,$f0,$f1
	lwc1	$f2,60($15)
	lwc1	$f4,0($10)
	add.s	$f0,$f0,$f0
	lwc1	$f1,0($12)
	add.s	$f0,$f0,$f1
	mul.s	$f1,$f0,$f2
	add.s	$f1,$f1,$f3
	c.lt.s	$f4,$f1
	bc1f	.L00221bb0
	mtc1	$0,$f0
	mov.s	$f1,$f4
.L00221b34:
	lwc1	$f0,28($19)
.L00221b38:
	lwc1	$f2,36($15)
	sub.s	$f1,$f1,$f0
	lw	$18,24($19)
	mul.s	$f1,$f1,$f2
	add.s	$f0,$f0,$f1
	beqz	$18,.L00221b9c
	swc1	$f0,28($19)
	li	$21,48
	lhu	$16,52($18)
.L00221b5c:
	addiu	$5,$29,176
	mult	$16,$16,$21
	addu	$16,$18,$16
	addiu	$17,$16,64
	move	$4,$17
	jal	func_002226b8
	addiu	$16,$16,96
	addiu	$5,$29,160
	jal	func_002226b8
	move	$4,$16
	lwc1	$f0,28($19)
	swc1	$f0,28($17)
	sw	$20,20($18)
	lw	$18,8($18)
	bnezl	$18,.L00221b5c
	lhu	$16,52($18)
.L00221b9c:
	move	$4,$22
	jal	func_002226b8
	addiu	$5,$29,80
	b	.L00221780
	addiu	$5,$29,112
.L00221bb0:
	c.lt.s	$f1,$f0
	bc1tl	.L00221b34
	mov.s	$f1,$f0
	b	.L00221b38
	lwc1	$f0,28($19)
.L00221bc4:
	lui	$14,0x37
	addiu	$14,$14,2984
	sw	$0,24($19)
	cvt.s.w	$f0,$f0
	lui	$13,0x37
	lwc1	$f1,0($14)
	addiu	$13,$13,2988
	lwc1	$f4,0($13)
	lui	$12,0x37
	addiu	$12,$12,2992
	lwc1	$f3,28($17)
	nop
	nop
	div.s	$f0,$f0,$f1
	swc1	$f4,12($19)
	lw	$10,224($29)
	lw	$15,76($10)
	lwc1	$f2,60($15)
	add.s	$f0,$f0,$f0
	lwc1	$f1,0($12)
	add.s	$f0,$f0,$f1
	mul.s	$f1,$f0,$f2
	add.s	$f1,$f1,$f3
	c.lt.s	$f4,$f1
	bc1f	.L00221d70
	mtc1	$0,$f0
	mov.s	$f1,$f4
.L00221c30:
	swc1	$f1,28($19)
.L00221c34:
	lw	$13,264($29)
	beqz	$13,.L00221b9c
	addiu	$22,$19,32
	lw	$14,260($29)
	and	$15,$16,$14
	bnez	$15,.L00221b9c
	lw	$15,224($29)
	jal	func_00221f98
	lw	$4,72($15)
	beqz	$2,.L00221d68
	move	$16,$2
	lw	$10,228($29)
	addiu	$4,$29,208
	lbu	$15,30($10)
	addiu	$15,$15,1
	sb	$15,30($10)
	sw	$2,208($29)
	lw	$12,224($29)
	lw	$15,72($12)
	lbu	$14,1($15)
	jal	func_00221e28
	sb	$14,212($29)
	lwc1	$f1,244($29)
	addiu	$4,$16,64
	lw	$13,228($29)
	addiu	$5,$29,176
	cvt.s.w	$f1,$f1
	lhu	$14,62($16)
	lwc1	$f0,48($13)
	mtc1	$23,$f2
	lwc1	$f3,248($29)
	cvt.s.w	$f2,$f2
	lhu	$15,62($13)
	add.s	$f0,$f0,$f1
	sw	$20,20($16)
	cvt.s.w	$f3,$f3
	andi	$15,$15,0x1400
	lbu	$13,30($13)
	or	$14,$14,$15
	sh	$14,62($16)
	add.s	$f0,$f0,$f2
	sb	$13,30($16)
	sub.s	$f0,$f0,$f3
	jal	func_002226b8
	swc1	$f0,48($16)
	addiu	$4,$16,96
	jal	func_002226b8
	addiu	$5,$29,160
	lwc1	$f0,28($17)
	swc1	$f0,92($16)
	lw	$14,228($29)
	lw	$15,0($14)
	bnezl	$15,.L00221d0c
	sw	$16,4($15)
.L00221d0c:
	sw	$15,0($16)
	lw	$15,228($29)
	sw	$15,4($16)
	sw	$16,0($15)
	lw	$15,24($19)
	beqz	$15,.L00221d2c
	addiu	$14,$16,8
	sw	$14,12($15)
.L00221d2c:
	sw	$15,8($16)
	addiu	$15,$19,24
	sw	$16,24($19)
	sw	$15,4($14)
.L00221d3c:
	lw	$10,224($29)
	addiu	$22,$19,32
	lw	$12,228($29)
	lw	$15,76($10)
	lbu	$14,30($12)
	lbu	$13,64($15)
	sltu	$14,$14,$13
	lw	$13,264($29)
	movz	$13,$0,$14
	b	.L00221b9c
	sw	$13,264($29)
.L00221d68:
	b	.L00221d3c
	sw	$0,264($29)
.L00221d70:
	c.lt.s	$f1,$f0
	bc1tl	.L00221c30
	mov.s	$f1,$f0
	b	.L00221c34
	swc1	$f1,28($19)
.L00221d84:
	b	.L0022193c
	addiu	$19,$19,48
.L00221d8c:
	lw	$15,228($29)
	b	.L00221868
	sb	$30,54($15)
.L00221d98:
	lw	$10,228($29)
	b	.L00221518
	lw	$20,20($10)
.L00221da4:
	ori	$15,$11,0x10
	lw	$13,240($29)
	lw	$20,20($12)
	addu	$13,$13,$16
	beqz	$20,.L00221dd8
	sw	$13,240($29)
	lw	$14,240($29)
	lw	$10,244($29)
	slt	$15,$14,$10
	bnezl	$15,.L0022151c
	lw	$13,228($29)
	lw	$12,228($29)
	ori	$15,$11,0x10
.L00221dd8:
	b	.L002213cc
	sh	$15,62($12)
.L00221de0:
	lw	$14,232($29)
	li	$15,-513
	subu	$16,$12,$13
	ori	$14,$14,0x4
	and	$14,$14,$15
	sw	$14,232($29)
	b	.L002214ec
	andi	$5,$14,0x20
.L00221e00:
	b	.L002214ec
	andi	$5,$10,0x20
.L00221e08:
	lw	$15,232($29)
	b	.L002214ec
	andi	$5,$15,0x20
.L00221e14:
	lw	$12,232($29)
	move	$22,$0
	b	.L002214f0
	andi	$5,$12,0x20
	.end func_00221348
	.size func_00221348, 2780
