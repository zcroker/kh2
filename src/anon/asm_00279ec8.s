# Whole-function assembly (last step of the README ladder, 2026-11-10, helper w3914).
# Both functions were near misses in C++ after several sessions; see attempts.tsv
# and best/00279ec8_w3914.cpp, best/0027ccf8_w3914.cpp. Replace with C/C++ after 100%.
#   func_00279ec8: menu list setup (sched tie: movz before the cnt = 0 move; draft also needs two v0 pins)
# Split out of batch_w3914.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00279ec8,"ax",@progbits
	.align 2
	.globl func_00279ec8
	.type func_00279ec8, @function
	.ent func_00279ec8
func_00279ec8:
	addiu	$29,$29,-80
	sd	$20,32($29)
	sd	$31,72($29)
	sd	$16,0($29)
	sd	$17,8($29)
	sd	$18,16($29)
	sd	$19,24($29)
	sd	$21,40($29)
	sd	$22,48($29)
	sd	$23,56($29)
	sd	$30,64($29)
	jal	0x257770
	nop
	jal	0x279040
	move	$20,$2
	lui	$15,0x36
	lw	$14,-3536($15)
	lb	$13,7($14)
	bnez	$13,.L0027a0f4
	nop
	jal	0x1398d0
	li	$4,100
	lui	$19,0x36
.L00279f24:
	move	$16,$20
	addiu	$18,$20,8720
.L00279f2c:
	addiu	$17,$16,13840
	lw	$5,-4244($19)
	jal	0x138c10
	move	$4,$17
	sw	$0,408($17)
	addiu	$17,$16,3376
	lw	$5,-4244($19)
	move	$4,$17
	jal	0x138c10
	addiu	$16,$16,436
	slt	$15,$16,$18
	bnez	$15,.L00279f2c
	sw	$0,408($17)
	lui	$22,0x36
	lw	$13,-3536($22)
	lb	$14,7($13)
	beqz	$14,.L0027a0c4
	li	$18,20
	move	$19,$14
	slti	$15,$14,21
	movz	$19,$18,$15
	move	$23,$0
	blez	$14,.L0027a08c
	move	$18,$0
	blez	$19,.L0027a08c
	li	$14,0xb110
	li	$15,0xae10
	addu	$30,$20,$14
	addu	$21,$20,$15
	sll	$16,$18,0x3
.L00279fa4:
	addu	$14,$16,$13
	lb	$15,14($14)
	beqz	$15,.L0027a06c
	addiu	$18,$18,1
	lb	$15,16($14)
	addiu	$17,$20,13840
	move	$4,$17
	lui	$14,0x37
	sll	$15,$15,0x1
	addiu	$14,$14,15888
	addu	$15,$15,$14
	lh	$2,0($15)
	jal	0x138c10
	move	$5,$2
	lw	$15,-3536($22)
	move	$5,$21
	li	$6,1
	addiu	$21,$21,32
	addu	$15,$16,$15
	jal	0x259618
	lhu	$4,12($15)
	sw	$2,408($17)
	lw	$15,-3536($22)
	addu	$15,$16,$15
	lb	$14,18($15)
	bltzl	$14,.L0027a064
	addiu	$30,$30,4
	lb	$15,14($15)
	beqzl	$15,.L0027a064
	addiu	$30,$30,4
	move	$4,$0
	jal	0x257140
	addiu	$17,$20,3376
	move	$5,$2
	jal	0x138c10
	move	$4,$17
	lw	$15,-3536($22)
	li	$4,4
	addu	$15,$16,$15
	jal	0x273180
	lb	$5,18($15)
	lbu	$2,4($2)
	move	$5,$30
	li	$6,1
	jal	0x2595b8
	move	$4,$2
	sw	$2,408($17)
	addiu	$30,$30,4
.L0027a064:
	addiu	$20,$20,436
	addiu	$23,$23,1
.L0027a06c:
	lui	$22,0x36
	lw	$13,-3536($22)
	lb	$15,7($13)
	slt	$15,$18,$15
	beqz	$15,.L0027a08c
	slt	$15,$23,$19
	bnez	$15,.L00279fa4
	sll	$16,$18,0x3
.L0027a08c:
	bnez	$23,.L0027a0c8
	ld	$16,0($29)
	li	$4,100
	ld	$17,8($29)
	ld	$18,16($29)
	ld	$19,24($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	ld	$23,56($29)
	ld	$30,64($29)
	ld	$31,72($29)
	j	0x1398d0
	addiu	$29,$29,80
.L0027a0c4:
	ld	$16,0($29)
.L0027a0c8:
	ld	$17,8($29)
	ld	$18,16($29)
	ld	$19,24($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	ld	$23,56($29)
	ld	$30,64($29)
	ld	$31,72($29)
	jr	$31
	addiu	$29,$29,80
.L0027a0f4:
	jal	0x139858
	li	$4,100
	b	.L00279f24
	lui	$19,0x36
	.end func_00279ec8
	.size func_00279ec8, .-func_00279ec8
