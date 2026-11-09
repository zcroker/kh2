# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3877).
# Both functions were near misses in C/C++ after many sessions; see coord attempts.tsv
# and the best/ADDR_w3877.cpp drafts. Replace with C/C++ after 100%.
#   func_00109708: GIF tag + one A+D register packet (sched2 places lui %hi(D_0036a288) after ori 0xe; 3 lines)
#   func_002ce2a0: path nearest point, segment scan + 33-step bisection (outIdx spill/reload order vs p->count and best loads; 4 lines)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00109708,"ax",@progbits
	.globl func_00109708
	.type func_00109708, @function
	.ent func_00109708
func_00109708:
	addiu	$29,$29,-16
	li	$5,2
	sd	$31,0($29)
	jal	0x133ba0
	lui	$6,0x1300
	por	$15,$0,$0
	ld	$31,0($29)
	sq	$15,0($2)
	li	$14,-32768
	li	$13,-16
	ld	$15,0($2)
	dsrl	$13,$13,0x4
	ld	$12,8($2)
	and	$15,$15,$14
	li	$14,-16
	ori	$15,$15,0x8001
	and	$12,$12,$14
	and	$15,$15,$13
	li	$14,1
	lui	$13,0x37
	dsll32	$14,$14,0x1c
	ori	$12,$12,0xe
	or	$15,$15,$14
	sd	$12,8($2)
	sd	$15,0($2)
	ld	$14,-23928($13)
	li	$15,22
	sd	$14,16($2)
	sd	$15,24($2)
	jr	$31
	addiu	$29,$29,16
	.end func_00109708
	.size func_00109708, .-func_00109708

	.section .text.func_002ce2a0,"ax",@progbits
	.globl func_002ce2a0
	.type func_002ce2a0, @function
	.ent func_002ce2a0
func_002ce2a0:
	addiu	$29,$29,-176
	mtc1	$0,$f0
	sd	$19,104($29)
	li	$15,2
	sd	$21,120($29)
	sd	$23,136($29)
	move	$19,$4
	sd	$30,144($29)
	move	$21,$7
	swc1	$f20,160($29)
	move	$23,$0
	sd	$16,80($29)
	move	$30,$6
	sd	$17,88($29)
	mov.s	$f20,$f0
	sd	$18,96($29)
	sd	$20,112($29)
	sd	$22,128($29)
	sd	$31,152($29)
	swc1	$f23,172($29)
	swc1	$f22,168($29)
	swc1	$f21,164($29)
	sw	$5,64($29)
	lw	$14,8($4)
	bne	$14,$15,.L002ce38c
	swc1	$f0,48($29)
	jal	0x2cb890
	move	$5,$0
	move	$16,$2
	move	$4,$19
	jal	0x2cb890
	li	$5,1
	move	$8,$2
	move	$4,$19
	move	$6,$21
	move	$7,$16
	jal	0x2cd518
	addiu	$5,$29,48
	swc1	$f0,0($30)
	lw	$13,64($29)
	lwc1	$f2,48($29)
	sw	$0,0($13)
.L002ce348:
	mov.s	$f0,$f2
	ld	$16,80($29)
	ld	$17,88($29)
	ld	$18,96($29)
	ld	$19,104($29)
	ld	$20,112($29)
	ld	$21,120($29)
	ld	$22,128($29)
	ld	$23,136($29)
	ld	$30,144($29)
	ld	$31,152($29)
	lwc1	$f23,172($29)
	lwc1	$f22,168($29)
	lwc1	$f21,164($29)
	lwc1	$f20,160($29)
	jr	$31
	addiu	$29,$29,176
.L002ce38c:
	lbu	$15,16($4)
	mov.s	$f21,$f0
	sltiu	$15,$15,1
	subu	$22,$14,$15
	bgtz	$22,.L002ce500
	move	$20,$0
.L002ce3a4:
	lui	$15,0x37
	lw	$13,64($29)
	addiu	$15,$15,22852
	lwc1	$f0,0($15)
	c.le.s	$f20,$f0
	bc1t	.L002ce3d8
	sw	$23,0($13)
	lui	$13,0x37
	addiu	$13,$13,22856
	lwc1	$f0,0($13)
	c.le.s	$f0,$f20
	bc1f	.L002ce3e4
	move	$4,$19
.L002ce3d8:
	swc1	$f20,0($30)
	b	.L002ce348
	lwc1	$f2,48($29)
.L002ce3e4:
	mtc1	$0,$f22
	jal	0x2cb890
	move	$5,$23
	lw	$14,8($19)
	addiu	$15,$23,1
	lui	$13,0x37
	move	$16,$2
	div	$0,$15,$14
	addiu	$13,$13,22860
	lwc1	$f21,0($13)
	move	$4,$19
	beqzl	$14,.L002ce418
	break	0x7
.L002ce418:
	jal	0x2cb890
	mfhi	$5
	lq	$8,0($16)
	sq	$8,0($29)
	addiu	$20,$29,16
	lq	$8,0($2)
	sq	$8,0($20)
	lui	$13,0x37
	move	$22,$2
	addiu	$13,$13,22864
	addiu	$17,$29,32
	lwc1	$f23,0($13)
	li	$18,32
	add.s	$f0,$f22,$f21
.L002ce450:
	move	$5,$19
	move	$6,$16
	move	$7,$22
	move	$4,$17
	mul.s	$f20,$f0,$f23
	jal	0x2cd770
	mov.s	$f12,$f20
	move	$4,$19
	addiu	$5,$29,56
	move	$6,$21
	move	$7,$29
	jal	0x2cd518
	move	$8,$17
	move	$4,$19
	move	$7,$17
	move	$8,$20
	addiu	$5,$29,60
	jal	0x2cd518
	move	$6,$21
	lwc1	$f1,56($29)
	lwc1	$f0,60($29)
	c.lt.s	$f1,$f0
	bc1f	.L002ce4e8
	nop
	beq	$20,$17,.L002ce4c0
	mov.s	$f21,$f20
	lq	$8,0($17)
	sq	$8,0($20)
.L002ce4c0:
	addiu	$18,$18,-1
.L002ce4c4:
	bgez	$18,.L002ce450
	add.s	$f0,$f22,$f21
	lui	$15,0x37
	addiu	$15,$15,22864
	lwc1	$f2,48($29)
	lwc1	$f1,0($15)
	mul.s	$f0,$f0,$f1
	b	.L002ce348
	swc1	$f0,0($30)
.L002ce4e8:
	beq	$29,$17,.L002ce4c0
	mov.s	$f22,$f20
	lq	$8,0($17)
	sq	$8,0($29)
	b	.L002ce4c4
	addiu	$18,$18,-1
.L002ce500:
	addiu	$18,$20,1
	move	$5,$20
	div	$0,$18,$14
	move	$4,$19
	beqzl	$14,.L002ce518
	break	0x7
.L002ce518:
	jal	0x2cb890
	mfhi	$16
	move	$17,$2
	move	$4,$19
	jal	0x2cb890
	move	$5,$16
	move	$8,$2
	move	$4,$19
	move	$7,$17
	addiu	$5,$29,52
	jal	0x2cd518
	move	$6,$21
	beqz	$20,.L002ce58c
	mov.s	$f2,$f0
	lwc1	$f1,52($29)
	c.le.s	$f21,$f1
	bc1f	.L002ce578
	lwc1	$f0,48($29)
	c.lt.s	$f1,$f0
	bc1f	.L002ce57c
	slt	$15,$18,$22
.L002ce56c:
	mov.s	$f20,$f2
	move	$23,$20
	swc1	$f1,48($29)
.L002ce578:
	slt	$15,$18,$22
.L002ce57c:
	beqz	$15,.L002ce3a4
	move	$20,$18
	b	.L002ce500
	lw	$14,8($19)
.L002ce58c:
	b	.L002ce56c
	lwc1	$f1,52($29)
	.end func_002ce2a0
	.size func_002ce2a0, .-func_002ce2a0
