# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_003094b8,"ax",@progbits
	.align 2
	.globl func_003094b8
	.type func_003094b8, @function
	.ent func_003094b8
func_003094b8:
	addiu	$29,$29,-192
	sd	$17,48($29)
	move	$17,$4
	sd	$30,160($29)
	sd	$23,144($29)
	lui	$4,0x1e3
	sd	$22,128($29)
	move	$30,$6
	sd	$21,112($29)
	move	$22,$5
	sd	$20,96($29)
	move	$21,$7
	sd	$19,80($29)
	move	$20,$9
	sd	$18,64($29)
	move	$19,$10
	sd	$16,32($29)
	move	$18,$8
	sd	$31,176($29)
	move	$23,$11
	jal	0x308cf8
	addiu	$4,$4,29184
	move	$16,$2
	beqz	$16,.L00309688
	li	$2,-1
	lw	$2,192($29)
	lw	$3,24($16)
	sw	$2,32($17)
	sw	$3,4($17)
	sw	$16,0($17)
	sw	$23,28($17)
	move	$2,$28
	sw	$2,24($17)
	andi	$3,$30,0x2
	sw	$22,32($16)
	sw	$18,36($16)
	sw	$20,40($16)
	sw	$19,44($16)
	sw	$16,20($16)
	lw	$2,36($17)
	sw	$17,28($16)
	bnez	$3,.L003095a4
	sw	$2,52($16)
	bne	$21,$20,.L00309584
	slt	$2,$18,$19
	move	$5,$19
	move	$4,$21
	jal	0x308a80
	movz	$5,$18,$2
	b	.L003095a8
	andi	$2,$30,0x1
.L00309584:
	blez	$18,.L00309594
	move	$4,$21
	jal	0x308a80
	move	$5,$18
.L00309594:
	blez	$19,.L003095a4
	move	$4,$20
	jal	0x308a80
	move	$5,$19
.L003095a4:
	andi	$2,$30,0x1
.L003095a8:
	beqz	$2,.L003095fc
	lui	$2,0x38
	bnez	$23,.L003095c0
	li	$2,1
	b	.L003095c4
	sw	$0,48($16)
.L003095c0:
	sw	$2,48($16)
.L003095c4:
	li	$2,-1
	lui	$4,0x8000
	lw	$8,20($17)
	move	$7,$21
	sw	$2,8($17)
	move	$9,$18
	ori	$4,$4,0xa
	move	$5,$16
	jal	0x3088b8
	li	$6,64
	bnez	$2,.L00309688
	move	$2,$0
	b	.L00309664
	nop
.L003095fc:
	li	$19,1
	addiu	$2,$2,-32528
	sw	$0,8($29)
	sw	$2,20($29)
	move	$4,$29
	jal	0x305620
	sw	$19,4($29)
	bgez	$2,.L00309630
	sw	$2,8($17)
	jal	0x308da0
	move	$4,$16
	b	.L00309688
	li	$2,-3
.L00309630:
	sw	$19,48($16)
	lui	$4,0x8000
	move	$7,$21
	move	$9,$18
	lw	$8,20($17)
	ori	$4,$4,0xa
	move	$5,$16
	jal	0x3088b8
	li	$6,64
	bnez	$2,.L00309674
	nop
	jal	0x305630
	lw	$4,8($17)
.L00309664:
	jal	0x308da0
	move	$4,$16
	b	.L00309688
	li	$2,-2
.L00309674:
	jal	0x305660
	lw	$4,8($17)
	jal	0x305630
	lw	$4,8($17)
	move	$2,$0
.L00309688:
	ld	$31,176($29)
	ld	$30,160($29)
	ld	$23,144($29)
	ld	$22,128($29)
	ld	$21,112($29)
	ld	$20,96($29)
	ld	$19,80($29)
	ld	$18,64($29)
	ld	$17,48($29)
	ld	$16,32($29)
	jr	$31
	addiu	$29,$29,192
	.end func_003094b8
	.size func_003094b8, 512
