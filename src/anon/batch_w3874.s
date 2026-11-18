# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3874).
# Each function was a 2-difference near miss in C/C++ after many sessions; see attempts.tsv
# and the best/ADDR_w3874.cpp drafts. Replace with C/C++ after 100%.
#   func_002a9100: jump table builder (loop.c hoist order of %hi(D_0035f608) in the loop preheader)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002a9100,"ax",@progbits
	.align 2
	.globl func_002a9100
	.type func_002a9100, @function
	.ent func_002a9100
func_002a9100:
	addiu	$29,$29,-80
	li	$4,8
	sd	$16,0($29)
	sd	$17,8($29)
	sd	$18,16($29)
	sd	$19,24($29)
	move	$17,$0
	sd	$20,32($29)
	move	$18,$0
	sd	$31,64($29)
	sd	$21,40($29)
	sd	$22,48($29)
	sd	$23,56($29)
	jal	0x294000
	lui	$20,0x36
	lw	$4,-2552($20)
	move	$16,$2
	move	$5,$0
	li	$6,772
	jal	0x2fde18
	addiu	$19,$2,16
	lw	$15,8($16)
	blez	$15,.L002a925c
	move	$21,$16
	move	$23,$20
	move	$16,$19
	li	$22,-1
	li	$19,-1
.L002a9170:
	jal	0x2a99c8
	move	$4,$16
	beqzl	$2,.L002a924c
	lw	$15,8($21)
	beqz	$17,.L002a9294
	lw	$15,-2552($23)
	sll	$11,$17,0x2
	lhu	$13,0($16)
	addu	$15,$11,$15
	lb	$14,0($15)
	beq	$14,$13,.L002a91d4
	lui	$10,0x36
.L002a91a0:
	lw	$14,-2552($20)
	addiu	$17,$17,1
	lbu	$13,0($16)
	addu	$14,$11,$14
	sb	$13,4($14)
	lw	$15,-2552($20)
	addu	$15,$11,$15
	sb	$19,5($15)
	lw	$14,-2552($20)
	addu	$14,$11,$14
	sh	$0,6($14)
	sll	$11,$17,0x2
	lui	$10,0x36
.L002a91d4:
	lhu	$14,2($16)
	lw	$12,-2552($10)
	addu	$13,$11,$12
	lhu	$15,2($13)
	beql	$15,$14,.L002a9220
	lbu	$13,0($16)
	lbu	$14,0($16)
	addiu	$17,$17,1
	sb	$14,4($13)
	lw	$15,-2552($10)
	addu	$15,$11,$15
	sb	$22,5($15)
	lw	$14,-2552($10)
	lhu	$15,2($16)
	addu	$14,$11,$14
	sh	$15,6($14)
	sll	$11,$17,0x2
	lw	$12,-2552($10)
	lbu	$13,0($16)
.L002a9220:
	addu	$14,$11,$12
	addiu	$17,$17,1
	sb	$13,4($14)
	lw	$15,-2552($10)
	addu	$15,$11,$15
	sb	$18,5($15)
	lw	$14,-2552($10)
	lhu	$15,2($16)
	addu	$14,$11,$14
	sh	$15,6($14)
	lw	$15,8($21)
.L002a924c:
	addiu	$18,$18,1
	slt	$15,$18,$15
	bnez	$15,.L002a9170
	addiu	$16,$16,16
.L002a925c:
	lui	$15,0x36
	ld	$16,0($29)
	lw	$14,-2552($15)
	ld	$18,16($29)
	sw	$17,0($14)
	ld	$19,24($29)
	ld	$17,8($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	ld	$23,56($29)
	ld	$31,64($29)
	jr	$31
	addiu	$29,$29,80
.L002a9294:
	b	.L002a91a0
	move	$11,$0
	.end func_002a9100
	.size func_002a9100, .-func_002a9100

