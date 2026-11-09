# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3885).
# Both functions were long-standing near misses in C/C++ after many sessions and permuter runs;
# see coord attempts.tsv and the best/ADDR_w3885.* drafts. Replace with C/C++ after 100%.
#   func_0019e848: VLA function; sched2 puts the a0 spill store sw a0,32(s8) before the VLA sp save
#   func_001fded0: partMng render request; FP registers and store order in the request-fill tail
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0019e848,"ax",@progbits
	.align 2
	.globl func_0019e848
	.type func_0019e848, @function
	.ent func_0019e848
func_0019e848:
	addiu	$29,$29,-160
	sd	$30,144($29)
	sd	$16,80($29)
	sd	$20,112($29)
	move	$30,$29
	sd	$21,120($29)
	move	$16,$6
	sd	$22,128($29)
	move	$20,$0
	sd	$23,136($29)
	move	$21,$7
	sd	$31,152($29)
	move	$22,$0
	sd	$17,88($29)
	move	$23,$5
	sd	$18,96($29)
	sd	$19,104($29)
	sw	$29,36($30)
	sw	$4,32($30)
	jal	0x190128
	move	$4,$30
	move	$4,$30
	move	$5,$23
	jal	0x190878
	move	$6,$0
	sll	$15,$21,0x2
	addiu	$15,$15,15
	srl	$15,$15,0x4
	sll	$15,$15,0x4
	subu	$29,$29,$15
	blez	$21,.L0019e930
	sw	$29,40($30)
	move	$18,$16
	move	$19,$29
.L0019e8d0:
	jal	0x1a80c8
	lhu	$4,0($18)
	addiu	$18,$18,2
	lhu	$4,16($2)
	jal	0x1b8e88
	move	$16,$2
	move	$17,$2
	move	$4,$23
	move	$5,$16
	jal	0x19ea10
	move	$6,$2
	beqz	$2,.L0019e920
	lw	$14,32($30)
	lhu	$13,0($17)
	lw	$15,0($14)
	lhu	$14,38($15)
	beq	$14,$13,.L0019e9f8
	addiu	$22,$22,1
	sw	$17,0($19)
	addiu	$19,$19,4
.L0019e920:
	addiu	$20,$20,1
	slt	$15,$20,$21
	bnez	$15,.L0019e8d0
	nop
.L0019e930:
	blez	$22,.L0019e9ec
	lui	$14,0x36
	lui	$15,0x1
	lw	$16,14544($14)
	ori	$15,$15,0xdcd
	addiu	$4,$22,-1
	dsll32	$5,$22,0x0
	mult	$16,$16,$15
	dsll32	$4,$4,0x0
	dsrl32	$4,$4,0x0
	dsrl32	$5,$5,0x0
	sw	$16,14544($14)
	li	$15,1
	dsll32	$15,$15,0x0
	daddu	$4,$4,$15
	jal	0x312db8
	dsll32	$16,$16,0x0
	dsrl32	$16,$16,0x0
	move	$5,$2
	jal	0x312db8
	move	$4,$16
	dsll32	$2,$2,0x0
	lw	$15,40($30)
	dsra32	$2,$2,0x0
	lw	$4,32($30)
	sll	$2,$2,0x2
	move	$6,$30
	addu	$2,$2,$15
	move	$7,$0
	lw	$5,0($2)
.L0019e9a8:
	jal	0x19da68
	move	$8,$0
	lw	$29,36($30)
	li	$2,1
.L0019e9b8:
	move	$29,$30
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
	jr	$31
	addiu	$29,$29,160
.L0019e9ec:
	lw	$29,36($30)
	b	.L0019e9b8
	move	$2,$0
.L0019e9f8:
	lw	$4,32($30)
	move	$5,$17
	move	$6,$30
	b	.L0019e9a8
	move	$7,$0
	.end func_0019e848
	.size func_0019e848, .-func_0019e848

	.section .text.func_001fded0,"ax",@progbits
	.align 2
	.globl func_001fded0
	.type func_001fded0, @function
	.ent func_001fded0
func_001fded0:
	addiu	$29,$29,-240
	li	$14,0xffff
	sd	$16,160($29)
	sd	$17,168($29)
	sd	$20,192($29)
	move	$16,$4
	sd	$21,200($29)
	move	$17,$5
	sd	$18,176($29)
	move	$20,$6
	sd	$19,184($29)
	sd	$22,208($29)
	sd	$23,216($29)
	sd	$31,224($29)
	lw	$13,12($6)
	lw	$12,4($5)
	lw	$15,8($13)
	addu	$15,$4,$15
	beq	$12,$14,.L001fe0f4
	addiu	$21,$15,160
	lw	$15,0($13)
	addu	$15,$4,$15
	addiu	$18,$15,160
	lbu	$14,11($18)
	beqz	$14,.L001fe0f4
	sb	$14,27($29)
	lui	$15,0x1da
	lbu	$11,32($5)
	li	$14,36
	lw	$13,-6428($15)
	mult	$14,$12,$14
	lw	$15,16($13)
	addu	$23,$15,$14
	andi	$12,$11,0x2
	lw	$19,28($23)
	beqz	$12,.L001fe128
	sw	$0,0($29)
	li	$15,4
	sw	$15,0($29)
	lw	$14,0($19)
	andi	$15,$14,0x1
	bnez	$15,.L001fdf8c
	andi	$15,$14,0x2
	li	$15,12
.L001fdf80:
	sw	$15,0($29)
	lw	$14,0($19)
	andi	$15,$14,0x2
.L001fdf8c:
	bnezl	$15,.L001fdfa4
	lbu	$15,33($17)
	lw	$15,0($29)
	ori	$15,$15,0x10
	sw	$15,0($29)
	lbu	$15,33($17)
.L001fdfa4:
	beqz	$15,.L001fdfb4
	lw	$15,0($29)
	ori	$15,$15,0x200
	sw	$15,0($29)
.L001fdfb4:
	lbu	$15,35($17)
	beqz	$15,.L001fdfc8
	lw	$15,0($29)
	ori	$15,$15,0x100
	sw	$15,0($29)
.L001fdfc8:
	lbu	$15,34($17)
	beqz	$15,.L001fe120
	lw	$15,0($29)
	lui	$22,0x1da
	lw	$6,-6424($22)
	addiu	$4,$29,96
	ori	$15,$15,0x2000
	sw	$4,48($29)
	sw	$15,0($29)
	lui	$5,0x1da
	addiu	$6,$6,16
	jal	0x2f3d08
	addiu	$5,$5,-6080
.L001fdffc:
	lbu	$15,36($17)
	beqzl	$15,.L001fe01c
	sw	$0,68($29)
	lw	$14,12($20)
	lw	$15,12($14)
	addu	$15,$16,$15
	addiu	$15,$15,160
	sw	$15,68($29)
.L001fe01c:
	lhu	$15,22($19)
	lui	$13,0x37
	lwc1	$f2,12($21)
	addiu	$13,$13,640
	lwc1	$f1,0($13)
	lui	$16,0x1da
	sh	$15,8($29)
	move	$4,$19
	sw	$0,28($29)
	mul.s	$f2,$f2,$f1
	sb	$0,10($29)
	move	$5,$29
	lw	$15,-6424($22)
	lwc1	$f0,0($21)
	lw	$14,144($15)
	addiu	$7,$15,16
	mul.s	$f0,$f0,$f1
	addiu	$9,$15,80
	sw	$14,56($29)
	lw	$10,-5468($16)
	lw	$14,148($15)
	cvt.w.s	$f1,$f2
	lbu	$11,10($18)
	lbu	$8,37($17)
	lbu	$12,8($18)
	mfc1	$15,$f1
	cvt.w.s	$f1,$f0
	sw	$15,20($29)
	lbu	$13,9($18)
	mfc1	$15,$f1
	sw	$14,60($29)
	sw	$15,16($29)
	lui	$14,0x1da
	sb	$12,24($29)
	lui	$15,0x1da
	sb	$13,25($29)
	addiu	$15,$15,-5440
	sb	$11,26($29)
	sw	$15,4($29)
	addiu	$14,$14,-5760
	sw	$9,32($29)
	lui	$15,0x1da
	sw	$14,40($29)
	addiu	$15,$15,-5696
	sw	$7,44($29)
	sw	$15,36($29)
	sw	$10,52($29)
	sb	$8,77($29)
	sw	$0,12($29)
	sw	$0,64($29)
	sb	$0,76($29)
	jal	0x20f1e0
	lw	$6,32($23)
	sw	$2,-5468($16)
.L001fe0f4:
	ld	$16,160($29)
	ld	$17,168($29)
	ld	$18,176($29)
	ld	$19,184($29)
	ld	$20,192($29)
	ld	$21,200($29)
	ld	$22,208($29)
	ld	$23,216($29)
	ld	$31,224($29)
	jr	$31
	addiu	$29,$29,240
.L001fe120:
	b	.L001fdffc
	lui	$22,0x1da
.L001fe128:
	andi	$15,$11,0x1
	andi	$15,$15,0xff
	beqz	$15,.L001fe13c
	li	$15,128
	sw	$15,0($29)
.L001fe13c:
	lw	$14,0($19)
	andi	$15,$14,0x1
	bnezl	$15,.L001fdf8c
	andi	$15,$14,0x2
	lw	$15,0($29)
	b	.L001fdf80
	ori	$15,$15,0x8
	.end func_001fded0
	.size func_001fded0, .-func_001fded0

