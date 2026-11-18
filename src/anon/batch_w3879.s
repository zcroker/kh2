# Kept as assembly (last step of the match ladder): func_001ab260 (slanted-glyph GS packet, _nsa C draft 5 lines off on t1/t2) and
# sceCdInit (SDK sceCdInit, ee-gcc 2.9 C draft 5-10 lines off on register ties). C drafts: best/001ab260_w3879.cpp, 002f74c8_w3879.c.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f74c8,"ax",@progbits
	.align 3
	.globl sceCdInit
	.type sceCdInit, @function
	.ent sceCdInit
sceCdInit:
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
	.end sceCdInit
	.size sceCdInit, .-sceCdInit

