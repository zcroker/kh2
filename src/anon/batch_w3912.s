# Whole-function assembly (last step of the README ladder, 2026-11-10, zl90 w3912).
# func_0026a5a0 stayed a near miss in C++ after several sessions; see coord attempts.tsv and
# best/0026a5a0_w3912.cpp (35 differing lines with two register pins). Replace with C/C++ after 100%.
#   func_0026a5a0: menu list setup (global allocation of the loop-1 pointers and reload register
#   rotation t5/t6/t7/s0 in the second loop)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0026a5a0,"ax",@progbits
	.align 2
	.globl func_0026a5a0
	.type func_0026a5a0, @function
	.ent func_0026a5a0
func_0026a5a0:
	addiu	$29,$29,-112
	lui	$15,0x36
	sd	$31,104($29)
	sd	$16,32($29)
	sd	$18,48($29)
	sd	$21,72($29)
	lui	$16,0x36
	sd	$30,96($29)
	move	$18,$0
	sd	$17,40($29)
	sd	$19,56($29)
	sd	$20,64($29)
	sd	$22,80($29)
	sd	$23,88($29)
	jal	0x281f18
	lw	$4,-3860($15)
	jal	0x257770
	sw	$2,12($29)
	move	$4,$2
	jal	0x139d78
	move	$30,$2
	jal	0x287bc0
	nop
	lw	$4,-4068($16)
	jal	0x28b038
	sw	$2,0($29)
	lui	$15,0x36
	move	$21,$2
	lw	$4,-4020($15)
	jal	0x28be78
	move	$5,$2
	jal	0x2892f8
	lw	$4,-4068($16)
	blez	$2,.L0026a694
	li	$15,0x87d0
	lui	$19,0x36
	move	$20,$16
	move	$22,$2
	addu	$17,$30,$15
	move	$23,$19
	addiu	$16,$30,3376
	lw	$4,-4068($20)
.L0026a648:
	move	$5,$18
	jal	0x2891b8
	addiu	$18,$18,1
	sw	$0,408($2)
	jal	0x139d78
	move	$4,$16
	beqz	$2,.L0026a674
	move	$4,$16
	jal	0x138c10
	lw	$5,-4244($23)
	sw	$0,408($16)
.L0026a674:
	lw	$5,-4244($19)
	move	$4,$17
	addiu	$17,$17,408
	jal	0x138c10
	addiu	$16,$16,436
	slt	$15,$18,$22
	bnez	$15,.L0026a648
	lw	$4,-4068($20)
.L0026a694:
	lw	$13,0($29)
	lui	$18,0x36
	lw	$4,-3860($18)
	move	$17,$21
	jal	0x281f18
	addiu	$22,$13,-5
	sltiu	$16,$22,2
	slti	$14,$2,9
	li	$15,8
	bnez	$16,.L0026a6c8
	movz	$2,$15,$14
	slt	$15,$0,$21
	subu	$17,$21,$15
.L0026a6c8:
	lw	$4,-3860($18)
	move	$5,$17
	jal	0x2827f0
	move	$6,$2
	beqz	$16,.L0026a8f8
	li	$14,-1
	jal	0x2570a0
	li	$4,2
	jal	0x269508
	move	$4,$2
	lui	$15,0x37
	sll	$2,$2,0x1
	addiu	$15,$15,14336
	addu	$2,$2,$15
	lh	$2,0($2)
	sw	$2,4($29)
.L0026a708:
	sltiu	$15,$22,2
	beqz	$15,.L0026a770
	lw	$15,12($29)
	bnez	$15,.L0026a774
	lui	$16,0x36
	lui	$15,0x36
	move	$5,$0
	jal	0x2891b8
	lw	$4,-4068($15)
	jal	0x282d68
	move	$16,$2
	jal	0x192048
	move	$4,$2
	sw	$2,408($16)
.L0026a740:
	ld	$16,32($29)
.L0026a744:
	ld	$17,40($29)
	ld	$18,48($29)
	ld	$19,56($29)
	ld	$20,64($29)
	ld	$21,72($29)
	ld	$22,80($29)
	ld	$23,88($29)
	ld	$30,96($29)
	ld	$31,104($29)
	jr	$31
	addiu	$29,$29,112
.L0026a770:
	lui	$16,0x36
.L0026a774:
	move	$18,$21
	lw	$4,-3860($16)
	move	$23,$0
	jal	0x281f30
	move	$21,$0
	lw	$14,12($29)
	sltiu	$13,$22,2
	xori	$15,$13,0x1
	addu	$20,$15,$14
	slt	$14,$18,$20
	beqz	$14,.L0026a740
	sw	$2,8($29)
	sw	$13,16($29)
	slti	$15,$21,8
.L0026a7ac:
	beqz	$15,.L0026a740
	lw	$15,16($29)
	bnez	$15,.L0026a808
	move	$19,$18
	bnezl	$18,.L0026a808
	addiu	$19,$18,-1
	lui	$13,0x36
	move	$5,$0
	lw	$4,-4068($13)
	jal	0x2891b8
	addiu	$21,$21,1
	lui	$14,0x36
	move	$16,$2
	jal	0x282d58
	lw	$4,-3860($14)
	sw	$2,408($16)
.L0026a7ec:
	addiu	$18,$18,1
	slt	$15,$18,$20
	bnez	$15,.L0026a7ac
	slti	$15,$21,8
	b	.L0026a744
	ld	$16,32($29)
	nop
.L0026a808:
	lui	$15,0x36
	move	$5,$21
	jal	0x2891b8
	lw	$4,-4068($15)
	li	$15,80
	lw	$13,8($29)
	mult	$15,$23,$15
	sltiu	$14,$22,2
	addu	$15,$13,$15
	addiu	$23,$23,1
	addiu	$15,$15,16
	beqz	$14,.L0026a88c
	sw	$15,408($2)
	li	$5,-1
	jal	0x26a178
	move	$4,$19
	jal	0x1a8190
	move	$4,$2
	lhu	$4,2($2)
	beqzl	$4,.L0026a890
	move	$4,$19
	jal	0x1a80c8
	li	$16,436
	mult	$16,$21,$16
	lhu	$17,8($2)
	lw	$5,4($29)
	addu	$16,$30,$16
	addiu	$16,$16,3376
	jal	0x138c10
	move	$4,$16
	jal	0x192048
	move	$4,$17
	sw	$2,408($16)
.L0026a88c:
	move	$4,$19
.L0026a890:
	jal	0x26a178
	li	$5,-1
	jal	0x285d58
	lhu	$4,0($2)
	beqzl	$2,.L0026a7ec
	addiu	$21,$21,1
	move	$4,$19
	jal	0x26a178
	li	$5,-1
	jal	0x285e30
	lhu	$4,0($2)
	beqz	$2,.L0026a8ec
	lui	$15,0x37
	lw	$17,14132($15)
.L0026a8c8:
	li	$4,408
	li	$15,0x87d0
	mult	$4,$21,$4
	move	$5,$17
	addu	$4,$30,$4
	jal	0x138c10
	addu	$4,$4,$15
	b	.L0026a7ec
	addiu	$21,$21,1
.L0026a8ec:
	lui	$15,0x37
	b	.L0026a8c8
	lw	$17,14128($15)
.L0026a8f8:
	b	.L0026a708
	sw	$14,4($29)
	.end func_0026a5a0
	.size func_0026a5a0, .-func_0026a5a0
