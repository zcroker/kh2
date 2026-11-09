# Kept as assembly (last step of the match ladder): func_001ab260 (slanted-glyph GS packet, _nsa C draft 5 lines off on t1/t2) and
# func_002f74c8 (SDK sceCdInit, ee-gcc 2.9 C draft 5-10 lines off on register ties). C drafts: coord/best/001ab260_w3879.cpp, 002f74c8_w3879.c.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_001ab260,"ax",@progbits
	.align 3
	.globl func_001ab260
	.type func_001ab260, @function
	.ent func_001ab260
func_001ab260:
	addiu	$29,$29,-96
	lui	$15,0x35
	sd	$16,16($29)
	sd	$17,24($29)
	sd	$18,32($29)
	move	$16,$9
	sd	$19,40($29)
	sd	$20,48($29)
	move	$18,$5
	sd	$21,56($29)
	move	$5,$6
	sd	$22,64($29)
	move	$19,$4
	sd	$23,72($29)
	move	$21,$6
	sd	$30,80($29)
	move	$22,$8
	sd	$31,88($29)
	move	$20,$10
	lbu	$14,18($4)
	lbu	$13,19($4)
	sll	$14,$14,0x4
	lw	$12,2608($15)
	sll	$13,$13,0x4
	mtc1	$14,$f1
	mtc1	$13,$f0
	addu	$23,$7,$12
	cvt.s.w	$f1,$f1
	move	$6,$23
	cvt.s.w	$f0,$f0
	mul.s	$f1,$f1,$f12
	mul.s	$f0,$f0,$f12
	mul.s	$f1,$f1,$f13
	cvt.w.s	$f2,$f0
	cvt.w.s	$f0,$f1
	mfc1	$17,$f2
	move	$8,$17
	mfc1	$30,$f0
	jal	0x1aaf98
	addu	$7,$30,$10
	bnez	$2,.L001ab564
	move	$3,$0
	lw	$14,8($19)
	li	$15,1
	lbu	$12,18($19)
	move	$5,$16
	sllv	$14,$15,$14
	move	$4,$19
	div	$0,$14,$12
	beqzl	$12,.L001ab32c
	break	0x7
.L001ab32c:
	lw	$11,12($19)
	lbu	$13,19($19)
	sllv	$15,$15,$11
	mflo	$14
	div	$0,$15,$13
	mflo	$15
	div	$0,$16,$14
	mfhi	$10
	mult	$15,$14,$15
	div	$0,$16,$15
	mfhi	$16
	mult	$15,$10,$12
	div	$0,$16,$14
	sll	$12,$15,0x4
	addiu	$12,$12,8
	sw	$12,0($29)
	mflo	$16
	jal	0x1aaea8
	mult	$16,$16,$13
	sll	$16,$16,0x4
	lw	$15,8($18)
	andi	$10,$22,0xff
	srl	$13,$22,0x8
	srl	$12,$22,0x10
	sd	$2,0($15)
	andi	$13,$13,0xff
	andi	$12,$12,0xff
	srl	$9,$22,0x18
	lw	$14,8($18)
	li	$15,6
	addiu	$16,$16,8
	addu	$8,$21,$20
	sd	$15,8($14)
	subu	$7,$23,$17
	li	$6,0x8000
	addu	$11,$21,$30
	lw	$14,8($18)
	addu	$5,$11,$20
	subu	$4,$21,$20
	subu	$11,$11,$20
	addiu	$15,$14,16
	li	$3,1
	sw	$15,8($18)
	sw	$10,16($14)
	lw	$15,8($18)
	sw	$13,4($15)
	lw	$14,8($18)
	sw	$12,8($14)
	lw	$15,8($18)
	sw	$9,12($15)
	lw	$14,8($18)
	addiu	$15,$14,16
	sw	$15,8($18)
	lw	$13,0($29)
	lbu	$12,19($19)
	lbu	$15,18($19)
	sll	$12,$12,0x4
	sw	$13,16($14)
	addiu	$15,$15,-1
	sll	$9,$15,0x4
	addu	$12,$16,$12
	lw	$14,8($18)
	addu	$10,$13,$9
	sw	$16,4($14)
	lw	$15,8($18)
	sw	$0,8($15)
	lw	$14,8($18)
	sw	$0,12($14)
	lw	$13,8($18)
	addiu	$15,$13,16
	sw	$15,8($18)
	sw	$8,16($13)
	lw	$15,8($18)
	sw	$7,4($15)
	lw	$14,8($18)
	sw	$0,8($14)
	lw	$15,8($18)
	sw	$6,12($15)
	lw	$14,8($18)
	addiu	$15,$14,16
	sw	$15,8($18)
	sw	$10,16($14)
	lw	$15,8($18)
	sw	$16,4($15)
	lw	$14,8($18)
	sw	$0,8($14)
	lw	$15,8($18)
	sw	$0,12($15)
	lw	$14,8($18)
	addiu	$15,$14,16
	sw	$15,8($18)
	sw	$5,16($14)
	lw	$15,8($18)
	sw	$7,4($15)
	lw	$14,8($18)
	sw	$0,8($14)
	lw	$15,8($18)
	sw	$6,12($15)
	lw	$14,8($18)
	addiu	$15,$14,16
	sw	$15,8($18)
	lw	$15,0($29)
	sw	$15,16($14)
	lw	$15,8($18)
	sw	$12,4($15)
	lw	$14,8($18)
	sw	$0,8($14)
	lw	$15,8($18)
	sw	$0,12($15)
	lw	$14,8($18)
	addiu	$15,$14,16
	sw	$15,8($18)
	sw	$4,16($14)
	lw	$15,8($18)
	sw	$23,4($15)
	lw	$14,8($18)
	sw	$0,8($14)
	lw	$15,8($18)
	sw	$0,12($15)
	lw	$14,8($18)
	addiu	$15,$14,16
	sw	$15,8($18)
	sw	$10,16($14)
	lw	$15,8($18)
	sw	$12,4($15)
	lw	$14,8($18)
	sw	$0,8($14)
	lw	$15,8($18)
	sw	$0,12($15)
	lw	$14,8($18)
	addiu	$15,$14,16
	sw	$15,8($18)
	sw	$11,16($14)
	lw	$15,8($18)
	sw	$23,4($15)
	lw	$14,8($18)
	sw	$0,8($14)
	lw	$13,8($18)
	sw	$0,12($13)
	lw	$15,8($18)
	addiu	$15,$15,16
	sw	$15,8($18)
.L001ab564:
	ld	$16,16($29)
	move	$2,$3
	ld	$17,24($29)
	ld	$18,32($29)
	ld	$19,40($29)
	ld	$20,48($29)
	ld	$21,56($29)
	ld	$22,64($29)
	ld	$23,72($29)
	ld	$30,80($29)
	ld	$31,88($29)
	jr	$31
	addiu	$29,$29,96
	.end func_001ab260
	.size func_001ab260, .-func_001ab260

	.section .text.func_002f74c8,"ax",@progbits
	.align 3
	.globl func_002f74c8
	.type func_002f74c8, @function
	.ent func_002f74c8
func_002f74c8:
	addiu	$29,$29,-176
	sd	$19,64($29)
	move	$19,$4
	sd	$31,160($29)
	sd	$30,144($29)
	li	$4,1
	sd	$23,128($29)
	sd	$22,112($29)
	sd	$21,96($29)
	sd	$20,80($29)
	sd	$18,48($29)
	sd	$17,32($29)
	jal	0x2f7250
	sd	$16,16($29)
	bnez	$2,.L002f7780
	move	$2,$0
	move	$4,$0
	jal	0x308b30
	lui	$21,0x36
	lui	$20,0x36
	li	$2,1
	lui	$3,0x36
	sw	$2,15780($3)
	lui	$5,0x36
	lw	$4,15836($21)
	li	$3,-1
	lui	$2,0x36
	lui	$6,0x36
	addiu	$4,$4,1
	lui	$7,0x36
	lui	$9,0x36
	lui	$8,0x36
	sw	$3,15816($2)
	lui	$16,0x1e3
	lui	$2,0x1e3
	sw	$3,15820($5)
	sw	$3,15804($6)
	addiu	$17,$2,13288
	sw	$3,15828($7)
	addiu	$18,$16,13376
	sw	$3,15824($9)
	lui	$30,0x36
	sw	$0,15800($8)
	lui	$23,0x36
	sw	$4,15836($21)
	lui	$22,0x37
	sw	$3,15832($20)
	nop
.L002f7588:
	lui	$5,0x8000
	move	$4,$17
	ori	$5,$5,0x592
	jal	0x3092d8
	move	$6,$0
	move	$5,$2
	bgezl	$5,.L002f75ec
	lw	$2,36($17)
	lw	$2,15760($23)
	blez	$2,.L002f75bc
	lw	$6,15836($21)
	jal	0x3080d0
	addiu	$4,$22,27872
.L002f75bc:
	lui	$2,0x10
	li	$3,-1
	nop
.L002f75c8:
	addiu	$2,$2,-1
	nop
	nop
	nop
	nop
	bne	$2,$3,.L002f75c8
	nop
	b	.L002f7588
	nop
.L002f75ec:
	beqz	$2,.L002f7644
	move	$4,$18
	sw	$19,13376($16)
	sw	$0,15832($20)
	jal	0x308a80
	li	$5,4
	addiu	$16,$30,20352
	move	$4,$17
	move	$7,$18
	sw	$0,0($29)
	move	$5,$0
	move	$6,$0
	li	$8,4
	move	$9,$16
	li	$10,16
	jal	0x3094b8
	move	$11,$0
	bgez	$2,.L002f7674
	lui	$2,0x36
	sw	$0,15780($2)
	b	.L002f7780
	move	$2,$0
.L002f7644:
	lui	$2,0x10
	li	$3,-1
	nop
.L002f7650:
	addiu	$2,$2,-1
	nop
	nop
	nop
	nop
	bne	$2,$3,.L002f7650
	nop
	b	.L002f7588
	nop
.L002f7674:
	lui	$5,0x2000
	addiu	$2,$16,12
	or	$2,$2,$5
	addiu	$3,$16,4
	addiu	$4,$16,8
	lw	$6,0($2)
	or	$4,$4,$5
	or	$3,$3,$5
	lw	$5,0($3)
	li	$16,1
	li	$2,255
	beq	$6,$2,.L002f76fc
	lw	$4,0($4)
	li	$2,254
	bne	$6,$2,.L002f76c0
	li	$6,-1
	lui	$2,0x36
	b	.L002f76fc
	sw	$16,15760($2)
.L002f76c0:
	addiu	$2,$5,255
	slt	$3,$6,$5
	movn	$2,$5,$3
	sra	$2,$2,0x8
	slti	$2,$2,2
	bnezl	$2,.L002f76fc
	li	$16,2
	slt	$3,$6,$4
	addiu	$2,$4,255
	movn	$2,$4,$3
	sra	$2,$2,0x8
	slti	$2,$2,2
	beqz	$2,.L002f7700
	lui	$3,0x36
	li	$16,2
.L002f76fc:
	lui	$3,0x36
.L002f7700:
	sw	$0,15780($3)
	bltz	$19,.L002f7760
	slti	$2,$19,2
	bnez	$2,.L002f7760
	li	$2,5
	bne	$19,$2,.L002f7760
	lui	$2,0x36
	lw	$3,15760($2)
	blez	$3,.L002f7730
	lui	$4,0x37
	jal	0x3080d0
	addiu	$4,$4,27904
.L002f7730:
	jal	0x2f6ab0
	nop
	li	$4,-1
	lui	$2,0x36
	sw	$4,15784($2)
	lui	$3,0x36
	sw	$4,15788($3)
	lui	$2,0x36
	lui	$3,0x36
	sw	$4,15776($2)
	b	.L002f777c
	sw	$0,15812($3)
.L002f7760:
	jal	0x2f69c8
	nop
	jal	0x2f6c28
	nop
	lui	$3,0x36
	li	$2,1
	sw	$2,15812($3)
.L002f777c:
	move	$2,$16
.L002f7780:
	ld	$31,160($29)
	ld	$30,144($29)
	ld	$23,128($29)
	ld	$22,112($29)
	ld	$21,96($29)
	ld	$20,80($29)
	ld	$19,64($29)
	ld	$18,48($29)
	ld	$17,32($29)
	ld	$16,16($29)
	jr	$31
	addiu	$29,$29,176
	.end func_002f74c8
	.size func_002f74c8, .-func_002f74c8

