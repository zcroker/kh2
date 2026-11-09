# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3875).
# func_00236d98: VRAM slot allocator over D_0035e440[64]. Best C (coord best/00236d98_w3835.cpp,
# best/00236d98_w3875.cpp) is 2 differences: the latch increments of the test pointer (t1) and the
# found-path pointer (a1) are swapped (loop.c reduces the found-path giv in pass 1; the original
# reduces it in the rerun pass). Replace with C/C++ after 100%.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00236d98,"ax",@progbits
	.align 3
	.globl func_00236d98
	.type func_00236d98, @function
	.ent func_00236d98
func_00236d98:
	addiu	$29,$29,-16
	lui	$15,0x36
	sd	$16,0($29)
	addiu	$9,$15,-7104
	sd	$31,8($29)
	move	$12,$0
	move	$16,$4
	li	$11,24
	lw	$10,404($4)
	mult	$15,$12,$11
.L00236dc0:
	addu	$13,$15,$9
	lbu	$14,0($13)
	beqzl	$14,.L00236de4
	addiu	$12,$12,1
	lw	$15,4($13)
	beql	$15,$10,.L0023705c
	ld	$16,0($29)
	lw	$15,8($13)
	addu	$12,$12,$15
.L00236de4:
	slti	$15,$12,64
	bnez	$15,.L00236dc0
	mult	$15,$12,$11
	jal	0x236490
	move	$4,$16
	sll	$2,$2,0x6
	addiu	$14,$2,8191
	slti	$15,$14,0
	addiu	$2,$2,16382
	movn	$14,$2,$15
	sra	$11,$14,0xd
	li	$15,65
	subu	$15,$15,$11
	blez	$15,.L00236f08
	move	$12,$0
	move	$6,$15
	lui	$3,0x36
	lui	$15,0x36
	move	$7,$0
	addiu	$9,$15,-7104
	move	$5,$9
	move	$4,$9
	move	$8,$9
.L00236e40:
	lbu	$15,0($9)
	bnezl	$15,.L00236ef0
	addiu	$12,$12,1
	li	$13,1
	slt	$15,$13,$11
	beqz	$15,.L00236e7c
	addiu	$14,$8,24
	li	$10,1
	lbu	$15,0($14)
.L00236e64:
	beq	$15,$10,.L00236eec
	addiu	$14,$14,24
	addiu	$13,$13,1
	slt	$15,$13,$11
	bnezl	$15,.L00236e64
	lbu	$15,0($14)
.L00236e7c:
	blez	$11,.L00236eb0
	move	$14,$11
	addu	$15,$7,$4
	li	$11,1
	li	$12,-1
	move	$13,$14
.L00236e94:
	sb	$11,0($15)
	addiu	$13,$13,-1
	sw	$12,4($15)
	sw	$14,8($15)
	nop
	bnez	$13,.L00236e94
	addiu	$15,$15,24
.L00236eb0:
	lw	$15,-5568($3)
	move	$4,$16
	sw	$15,4($5)
	addiu	$14,$15,1
	sw	$14,-5568($3)
	sw	$15,404($16)
	lw	$6,20($5)
	lw	$5,16($5)
.L00236ed0:
	jal	0x236440
	nop
	move	$4,$16
	ld	$31,8($29)
	ld	$16,0($29)
	j	0x2368b0
	addiu	$29,$29,16
.L00236eec:
	addiu	$12,$12,1
.L00236ef0:
	addiu	$9,$9,24
	addiu	$5,$5,24
	addiu	$7,$7,24
	slt	$15,$12,$6
	bnez	$15,.L00236e40
	addiu	$8,$8,24
.L00236f08:
	li	$15,65
	subu	$15,$15,$11
	blez	$15,.L00236f4c
	move	$12,$0
	move	$13,$15
	li	$10,24
	lui	$15,0x36
	addiu	$9,$15,-7104
	mult	$15,$12,$10
.L00236f2c:
	addu	$15,$15,$9
	lbu	$14,0($15)
	beqzl	$14,.L00237048
	addiu	$12,$12,1
	lw	$15,8($15)
	slt	$14,$15,$11
	bnez	$14,.L00237048
	addu	$12,$12,$15
.L00236f4c:
	addiu	$12,$11,-1
.L00236f50:
	li	$14,24
	mult	$14,$12,$14
	lui	$15,0x36
	addiu	$15,$15,-7104
	addu	$14,$14,$15
	lw	$13,4($14)
	li	$15,-1
	bne	$13,$15,.L00236f9c
	li	$15,24
	addiu	$14,$14,4
	li	$13,-1
.L00236f7c:
	addiu	$14,$14,-24
	lw	$15,0($14)
	nop
	nop
	nop
	beq	$15,$13,.L00236f7c
	addiu	$12,$12,-1
	li	$15,24
.L00236f9c:
	lui	$14,0x36
	mult	$15,$12,$15
	addiu	$10,$14,-7104
	addu	$15,$15,$10
	lw	$14,8($15)
	addu	$13,$12,$14
	addiu	$15,$13,-1
	bltz	$15,.L00236fe0
	move	$14,$10
	move	$15,$13
.L00236fc4:
	sb	$0,0($14)
	addiu	$15,$15,-1
	sw	$0,4($14)
	nop
	nop
	bnez	$15,.L00236fc4
	addiu	$14,$14,24
.L00236fe0:
	blez	$11,.L00237018
	move	$14,$11
	lui	$15,0x36
	li	$11,1
	addiu	$15,$15,-7104
	li	$12,-1
	move	$13,$14
.L00236ffc:
	sb	$11,0($15)
	addiu	$13,$13,-1
	sw	$12,4($15)
	sw	$14,8($15)
	nop
	bnez	$13,.L00236ffc
	addiu	$15,$15,24
.L00237018:
	lui	$12,0x36
	lui	$15,0x36
	lw	$14,-5568($12)
	addiu	$15,$15,-7104
	move	$4,$16
	sw	$14,4($15)
	addiu	$13,$14,1
	sw	$13,-5568($12)
	sw	$14,404($16)
	lw	$6,20($15)
	b	.L00236ed0
	lw	$5,16($15)
.L00237048:
	slt	$15,$12,$13
	bnez	$15,.L00236f2c
	mult	$15,$12,$10
	b	.L00236f50
	addiu	$12,$11,-1
.L0023705c:
	ld	$31,8($29)
	jr	$31
	addiu	$29,$29,16
	.end func_00236d98
	.size func_00236d98, .-func_00236d98
