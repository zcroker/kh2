# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3880).
# Both functions were 6-difference near misses in C/C++ after many sessions; see attempts.tsv
# and the best/ADDR_w3880.cpp drafts. Replace with C/C++ after 100%.
#   func_002a8330: list setup (lui/ori 0x110a0 schedule at the loop head; %hi(D_00374c18) in a1 instead of t6)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002a8330,"ax",@progbits
	.align 2
	.globl func_002a8330
	.type func_002a8330, @function
	.ent func_002a8330
func_002a8330:
	addiu	$29,$29,-112
	sd	$31,104($29)
	sd	$16,32($29)
	sd	$17,40($29)
	sd	$18,48($29)
	lui	$16,0x36
	sd	$19,56($29)
	sd	$20,64($29)
	move	$18,$0
	sd	$21,72($29)
	move	$19,$16
	sd	$22,80($29)
	sd	$23,88($29)
	sd	$30,96($29)
	jal	0x2766d0
	li	$21,9
	lui	$15,0x36
	sw	$2,16($29)
	jal	0x28b038
	lw	$4,-3584($15)
	lui	$15,0x36
	move	$5,$2
	lw	$4,-3564($15)
	jal	0x28be78
	move	$20,$2
	lw	$4,-2556($16)
	move	$5,$0
	li	$6,320
	jal	0x2fde18
	addiu	$4,$4,8720
	lw	$14,16($29)
	lui	$4,0x1
	ori	$4,$4,0x10a0
	move	$5,$0
	addu	$4,$14,$4
	jal	0x2fde18
	li	$6,640
	lw	$14,16($29)
	li	$15,0xa998
	addu	$17,$14,$15
	lw	$16,-2556($19)
.L002a83d4:
	li	$5,2
	addiu	$21,$21,-1
	addu	$16,$16,$18
	move	$4,$16
	jal	0x138c10
	addiu	$18,$18,872
	move	$4,$17
	sw	$0,408($16)
	li	$5,2
	jal	0x138c10
	addiu	$17,$17,408
	bgezl	$21,.L002a83d4
	lw	$16,-2556($19)
	lui	$15,0x36
	li	$21,10
	lw	$14,-2560($15)
	lw	$23,0($14)
	slti	$15,$23,11
	movz	$23,$21,$15
	blez	$23,.L002a84b4
	move	$21,$0
	lw	$30,16($29)
	sll	$22,$20,0x2
.L002a8430:
	lui	$15,0x36
	li	$13,872
	lw	$14,-2560($15)
	mult	$13,$21,$13
	lui	$15,0x36
	addu	$14,$22,$14
	lw	$12,-2556($15)
	lh	$4,6($14)
	lui	$15,0x1
	lh	$18,4($14)
	ori	$15,$15,0x10a0
	addu	$17,$12,$13
	bgez	$4,.L002a84f8
	addu	$20,$30,$15
	li	$5,102
	jal	0x138c10
	move	$4,$17
	move	$4,$18
	jal	0x295430
	li	$5,1
	move	$16,$2
	jal	0x2954e0
	move	$4,$18
	beqz	$2,.L002a84e4
	move	$4,$16
	jal	0x192048
	move	$4,$16
	sw	$2,408($17)
.L002a84a0:
	addiu	$21,$21,1
.L002a84a4:
	addiu	$30,$30,64
	slt	$15,$21,$23
	bnez	$15,.L002a8430
	addiu	$22,$22,4
.L002a84b4:
	ld	$16,32($29)
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
.L002a84e4:
	move	$5,$20
	jal	0x28de08
	li	$6,64
	b	.L002a84a0
	sw	$2,408($17)
.L002a84f8:
	jal	0x2a7f20
	nop
	lhu	$4,6($2)
	jal	0x1d56c8
	move	$18,$2
	move	$4,$17
	move	$19,$2
	jal	0x138c10
	li	$5,108
	lhu	$4,6($18)
	jal	0x2a8920
	lhu	$16,2($18)
	bnez	$2,.L002a8734
	move	$4,$16
	move	$5,$20
	jal	0x28de08
	li	$6,64
	sw	$2,408($17)
.L002a8540:
	lui	$14,0x36
	sll	$13,$21,0x5
	lw	$15,-2556($14)
	lbu	$12,0($19)
	addu	$15,$15,$13
	sltiu	$14,$12,2
	beqz	$14,.L002a85e8
	addiu	$20,$15,8720
	jal	0x192048
	li	$4,19313
	move	$4,$2
	jal	0x192c90
	move	$5,$20
	lbu	$15,0($19)
	beqzl	$15,.L002a84a4
	addiu	$21,$21,1
	lui	$16,0x36
.L002a8584:
	lw	$15,-2560($16)
.L002a8588:
	addu	$15,$22,$15
	jal	0x2ab100
	lh	$4,6($15)
	beqz	$2,.L002a84a0
	lw	$15,-2560($16)
	addu	$15,$22,$15
	jal	0x2ab180
	lh	$4,6($15)
	beqz	$2,.L002a85dc
	lui	$15,0x37
	lw	$16,19504($15)
.L002a85b4:
	li	$4,408
	lw	$15,16($29)
	mult	$4,$21,$4
	move	$5,$16
	addu	$4,$15,$4
	li	$15,0xa998
	jal	0x138c10
	addu	$4,$4,$15
	b	.L002a84a4
	addiu	$21,$21,1
.L002a85dc:
	lui	$15,0x37
	b	.L002a85b4
	lw	$16,19500($15)
.L002a85e8:
	li	$15,4
	bne	$12,$15,.L002a8648
	nop
	jal	0x192048
	lhu	$4,4($18)
	move	$5,$20
	jal	0x192c40
	move	$4,$2
	lw	$4,4($19)
	move	$17,$2
	move	$5,$29
	addiu	$6,$29,4
	addiu	$7,$29,8
	jal	0x14ca80
	addiu	$8,$29,12
	lui	$14,0x37
	lw	$6,4($29)
	lw	$7,8($29)
	addu	$4,$20,$17
	lw	$8,12($29)
	jal	0x192cc0
	addiu	$5,$14,19480
	b	.L002a8584
	lui	$16,0x36
.L002a8648:
	jal	0x105c30
	move	$16,$0
	li	$15,1
	beql	$2,$15,.L002a8674
	li	$16,1
	jal	0x105c30
	nop
	li	$15,8
	bne	$2,$15,.L002a8678
	andi	$15,$16,0xff
	li	$16,1
.L002a8674:
	andi	$15,$16,0xff
.L002a8678:
	beqz	$15,.L002a86d0
	lui	$5,0x37
	lw	$6,4($19)
	addiu	$5,$5,19496
	jal	0x192cc0
	move	$4,$20
	li	$16,19328
	jal	0x192b30
	move	$4,$2
	lbu	$14,0($19)
	li	$15,2
	beq	$14,$15,.L002a86b0
	move	$17,$2
	lhu	$16,4($18)
.L002a86b0:
	move	$4,$16
.L002a86b4:
	jal	0x192048
	lui	$16,0x36
	move	$4,$2
	jal	0x192c90
	addu	$5,$20,$17
	b	.L002a8588
	lw	$15,-2560($16)
.L002a86d0:
	lbu	$14,0($19)
	li	$15,2
	bnel	$14,$15,.L002a8710
	lw	$6,4($19)
	jal	0x192048
	li	$4,19328
	move	$5,$20
	jal	0x192c40
	move	$4,$2
	lw	$6,4($19)
	lui	$5,0x37
	addu	$4,$20,$2
	jal	0x192cc0
	addiu	$5,$5,19496
	b	.L002a8584
	lui	$16,0x36
.L002a8710:
	lui	$5,0x37
	addiu	$5,$5,19496
	jal	0x192cc0
	move	$4,$20
	jal	0x192b30
	move	$4,$2
	lhu	$4,4($18)
	b	.L002a86b4
	move	$17,$2
.L002a8734:
	jal	0x192048
	move	$4,$16
	b	.L002a8540
	sw	$2,408($17)
	.end func_002a8330
	.size func_002a8330, .-func_002a8330
