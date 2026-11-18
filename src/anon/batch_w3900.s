# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3890, carried to w3900).
# Both functions were 29-line near misses in C/C++ after many sessions; see attempts.tsv
# and the best/ADDR_w3890.cpp drafts. Replace with C/C++ after 100%.
#   func_00297e68: album menu setup (global allocation gives oy s3 and n+1 s4, swapped)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00297e68,"ax",@progbits
	.align 2
	.globl func_00297e68
	.type func_00297e68, @function
	.ent func_00297e68
func_00297e68:
	addiu	$29,$29,-128
	sd	$31,120($29)
	sd	$21,88($29)
	sd	$22,96($29)
	sd	$16,48($29)
	sd	$17,56($29)
	sd	$18,64($29)
	sd	$19,72($29)
	sd	$20,80($29)
	sd	$23,104($29)
	sd	$30,112($29)
	jal	0x276348
	nop
	jal	0x2766d0
	daddu	$22,$2,$0
	addiu	$13,$0,-1
	lui	$15,0x36
	sb	$13,-2655($15)
	lui	$14,0x36
	sb	$13,-2656($14)
	daddu	$21,$2,$0
	lui	$15,0x36
	sb	$0,-2653($15)
	lui	$14,0x36
	sb	$0,-2654($14)
	lui	$15,0x36
	jal	0x288e88
	lw	$4,-3584($15)
	jal	0x28f930
	daddu	$4,$0,$0
	bnez	$2,.L00297efc
	daddu	$17,$0,$0
	daddu	$4,$0,$0
	addiu	$5,$0,-1
	jal	0x28f4d8
	daddu	$6,$0,$0
	daddu	$17,$0,$0
.L00297efc:
	addiu	$13,$0,2
	sll	$15,$17,0x3
.L00297f04:
	addiu	$14,$0,3
	addu	$15,$15,$29
.L00297f0c:
	sh	$13,0($15)
	addiu	$14,$14,-1
	nop
	nop
	nop
	bgez	$14,.L00297f0c
	addiu	$15,$15,2
	addiu	$17,$17,1
	slti	$15,$17,2
	bnez	$15,.L00297f04
	sll	$15,$17,0x3
	lui	$20,0x36
	lui	$19,0x36
	lw	$15,-3116($20)
	lui	$17,0x36
	lui	$18,0x36
	lui	$23,0x6000
	addiu	$16,$15,-1
	jal	0x276e78
	daddu	$30,$19,$0
	ori	$23,$23,0x8
	lw	$6,-3764($17)
	daddu	$5,$16,$0
	lw	$7,-3768($18)
	addiu	$9,$0,90
	lw	$8,-3568($19)
	addiu	$10,$0,-1
	daddu	$11,$0,$0
	jal	0x28d8c0
	daddu	$4,$21,$0
	daddu	$17,$0,$0
	jal	0x139620
	daddu	$4,$21,$0
	daddu	$5,$22,$0
	jal	0x28dcc0
	daddu	$4,$21,$0
	lui	$22,0x36
	jal	0x23aa78
	addiu	$4,$21,24
	lw	$16,-3116($20)
	ori	$15,$0,0xa998
	sw	$2,20($29)
	addu	$18,$21,$15
	daddu	$20,$0,$0
	addiu	$19,$16,1
.L00297fc0:
	lui	$14,0x36
	lw	$8,-3568($30)
	lui	$15,0x36
	lw	$7,-3768($14)
	lw	$6,-3764($15)
	addiu	$9,$0,-1
	lw	$4,-3584($22)
	daddu	$10,$29,$0
	addiu	$11,$29,8
	jal	0x288d80
	daddu	$5,$17,$0
	lw	$4,-3584($22)
	daddu	$5,$17,$0
	jal	0x2891b8
	addiu	$17,$17,1
	daddu	$16,$2,$0
	jal	0x139620
	daddu	$4,$2,$0
	daddu	$4,$16,$0
	jal	0x28dcc0
	daddu	$5,$21,$0
	daddu	$6,$20,$0
	daddu	$5,$0,$0
	jal	0x138c68
	daddu	$4,$16,$0
	lw	$14,20($29)
	addiu	$15,$0,3
	daddu	$4,$16,$0
	sw	$15,428($16)
	addu	$20,$20,$14
	jal	0x1395f8
	sw	$23,420($16)
	lui	$15,0x36
	lw	$8,-3568($30)
	lui	$14,0x36
	lw	$7,-3768($15)
	lw	$6,-3764($14)
	daddu	$4,$18,$0
	daddu	$5,$19,$0
	addiu	$9,$0,2
	addiu	$10,$0,-1
	jal	0x28d8c0
	daddu	$11,$0,$0
	daddu	$4,$18,$0
	jal	0x28dcc0
	daddu	$5,$16,$0
	slti	$15,$17,8
	bnez	$15,.L00297fc0
	addiu	$18,$18,408
	jal	0x2982f0
	lui	$16,0x36
	lui	$4,0x1
	daddu	$5,$0,$0
	ori	$4,$4,0x10a0
	addiu	$6,$0,640
	jal	0x2fde18
	addu	$4,$21,$4
	lw	$15,-2664($16)
	lw	$20,0($15)
	bnezl	$20,.L0029819c
	sw	$20,16($29)
	addiu	$4,$0,1
	jal	0x276690
	sw	$4,16($29)
	lui	$15,0x36
	daddu	$5,$0,$0
	jal	0x2891b8
	lw	$4,-3584($15)
	daddu	$16,$2,$0
	jal	0x192048
	addiu	$4,$0,13021
	sw	$2,408($16)
.L002980e0:
	lui	$16,0x36
.L002980e4:
	lw	$5,16($29)
	jal	0x28af90
	lw	$4,-3584($16)
	jal	0x287bc0
	nop
	jal	0x276608
	daddu	$4,$2,$0
	lw	$4,-3584($16)
	daddu	$5,$2,$0
	daddu	$6,$0,$0
	addiu	$7,$0,-1
	jal	0x2891f0
	addiu	$8,$0,-1
	jal	0x287bc0
	nop
	daddu	$4,$2,$0
	daddu	$5,$0,$0
	jal	0x2765e8
	daddu	$6,$0,$0
	lui	$15,0x36
	lw	$14,-2664($15)
	lw	$13,0($14)
	bnez	$13,.L0029814c
	lw	$4,-3584($16)
	jal	0x28af28
	addiu	$5,$0,16
.L0029814c:
	jal	0x299260
	nop
	jal	0x299290
	nop
	jal	0x2766b0
	addiu	$4,$0,1
	jal	0x287cc0
	daddu	$4,$0,$0
	ld	$16,48($29)
	ld	$17,56($29)
	ld	$18,64($29)
	ld	$19,72($29)
	ld	$20,80($29)
	ld	$21,88($29)
	ld	$22,96($29)
	ld	$23,104($29)
	ld	$30,112($29)
	ld	$31,120($29)
	jr	$31
	addiu	$29,$29,128
.L0029819c:
	addiu	$4,$0,2
	jal	0x294000
	daddu	$17,$0,$0
	addiu	$2,$2,16
	lw	$20,16($29)
	blez	$20,.L002980e0
	sw	$2,24($29)
	lui	$14,0x1
	ori	$15,$0,0xa998
	sw	$14,28($29)
	addu	$22,$21,$15
	lui	$15,0x1
	daddu	$23,$16,$0
	ori	$14,$14,0x10a0
	ori	$15,$15,0x10a0
	sw	$15,28($29)
	daddu	$30,$14,$0
	sw	$14,32($29)
.L002981e4:
	lw	$15,-2664($23)
	sll	$16,$17,0x1
	addu	$15,$16,$15
	jal	0x2983d8
	lh	$4,4($15)
	jal	0x294348
	daddu	$4,$2,$0
	lw	$15,-2664($23)
	addiu	$14,$0,12
	daddu	$19,$2,$0
	addiu	$6,$0,64
	addu	$16,$16,$15
	lh	$18,4($16)
	mult	$15,$18,$14
	lw	$14,24($29)
	addu	$15,$15,$14
	lhu	$15,8($15)
	bnez	$2,.L002982c8
	daddu	$4,$15,$0
	sll	$16,$17,0x6
	lw	$15,28($29)
	addu	$5,$21,$16
	jal	0x28de08
	addu	$5,$5,$15
	lui	$15,0x36
.L00298248:
	daddu	$5,$17,$0
	lw	$4,-3584($15)
	jal	0x2891b8
	addiu	$17,$17,1
	addu	$15,$21,$16
	addu	$15,$15,$30
	beqz	$19,.L002982b4
	sw	$15,408($2)
	jal	0x276568
	nop
	lb	$4,0($2)
	jal	0x2aa668
	daddu	$5,$18,$0
	beqz	$2,.L002982b8
	slt	$15,$17,$20
	jal	0x276568
	nop
	lb	$4,0($2)
	jal	0x2aa788
	daddu	$5,$18,$0
	lui	$14,0x37
	daddu	$4,$22,$0
	lw	$15,18368($14)
	lui	$14,0x37
	lw	$5,18364($14)
	jal	0x138c10
	movn	$5,$15,$2
.L002982b4:
	slt	$15,$17,$20
.L002982b8:
	bnez	$15,.L002981e4
	addiu	$22,$22,408
	b	.L002980e4
	lui	$16,0x36
.L002982c8:
	jal	0x192048
	sll	$16,$17,0x6
	lw	$14,32($29)
	addu	$5,$21,$16
	daddu	$4,$2,$0
	jal	0x192c90
	addu	$5,$5,$14
	b	.L00298248
	lui	$15,0x36
	.end func_00297e68
	.size func_00297e68, .-func_00297e68

