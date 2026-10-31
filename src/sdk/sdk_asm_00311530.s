# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00311530,"ax",@progbits
	.align 2
	.globl func_00311530
	.type func_00311530, @function
	.ent func_00311530
func_00311530:
	addiu	$29,$29,-64
	lui	$4,0x38
	sd	$18,32($29)
	addiu	$4,$4,-31720
	sd	$17,16($29)
	lui	$18,0x36
	sd	$16,0($29)
	sd	$31,48($29)
	addiu	$16,$18,30576
	lw	$5,30576($18)
	lw	$7,4($16)
	lw	$9,8($16)
	move	$6,$5
	addu	$7,$5,$7
	addu	$9,$7,$9
	move	$8,$7
	addiu	$5,$5,-1
	addiu	$9,$9,-1
	jal	0x308150
	addiu	$7,$7,-1
	mtc0	$0,$6
	sync.p
	lw	$17,30576($18)
	slti	$2,$17,49
	bnez	$2,.L003115ac
	move	$25,$0
	lui	$4,0x38
	jal	0x308150
	addiu	$4,$4,-31664
	jal	0x30f468
	li	$4,1
.L003115ac:
	slt	$2,$25,$17
	beqz	$2,.L003115e8
	lw	$16,16($16)
	lw	$5,0($16)
	nop
.L003115c0:
	move	$4,$25
	lw	$6,4($16)
	lw	$7,8($16)
	lw	$8,12($16)
	jal	0x311450
	addiu	$16,$16,16
	addiu	$25,$25,1
	slt	$2,$25,$17
	bnezl	$2,.L003115c0
	lw	$5,0($16)
.L003115e8:
	addiu	$16,$18,30576
	lw	$2,4($16)
	addu	$17,$25,$2
	slti	$3,$17,49
	bnez	$3,.L00311618
	slt	$2,$25,$17
	lui	$4,0x38
	jal	0x308150
	addiu	$4,$4,-31640
	jal	0x30f468
	li	$4,1
	slt	$2,$25,$17
.L00311618:
	beqz	$2,.L00311650
	lw	$16,20($16)
	lw	$5,0($16)
	nop
.L00311628:
	move	$4,$25
	lw	$6,4($16)
	lw	$7,8($16)
	lw	$8,12($16)
	jal	0x311450
	addiu	$16,$16,16
	addiu	$25,$25,1
	slt	$2,$25,$17
	bnezl	$2,.L00311628
	lw	$5,0($16)
.L00311650:
	addiu	$16,$18,30576
	sw	$25,12($16)
	mtc0	$25,$6
	sync.p
	lw	$2,8($16)
	blezl	$2,.L003116cc
	move	$16,$25
	addu	$17,$25,$2
	slti	$2,$17,49
	bnez	$2,.L00311694
	slt	$2,$25,$17
	lui	$4,0x38
	jal	0x308150
	addiu	$4,$4,-31616
	jal	0x30f468
	li	$4,1
	slt	$2,$25,$17
.L00311694:
	beqz	$2,.L003116c8
	lw	$16,24($16)
	lw	$5,0($16)
.L003116a0:
	move	$4,$25
	lw	$6,4($16)
	lw	$7,8($16)
	lw	$8,12($16)
	jal	0x311450
	addiu	$16,$16,16
	addiu	$25,$25,1
	slt	$2,$25,$17
	bnezl	$2,.L003116a0
	lw	$5,0($16)
.L003116c8:
	move	$16,$25
.L003116cc:
	slti	$2,$16,48
	beqz	$2,.L00311708
	sll	$25,$25,0xd
	lui	$2,0xe000
	addu	$17,$25,$2
.L003116e0:
	move	$4,$16
	move	$6,$17
	move	$5,$0
	move	$7,$0
	move	$8,$0
	jal	0x311450
	addiu	$16,$16,1
	slti	$2,$16,48
	bnez	$2,.L003116e0
	addiu	$17,$17,8192
.L00311708:
	ld	$31,48($29)
	move	$2,$25
	ld	$18,32($29)
	ld	$17,16($29)
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,64
	.end func_00311530
	.size func_00311530, 500
