# Whole-function assembly (last step of the README match ladder, w3933 2026-11-10).
# Transcribed from the retail disassembly; calls, globals, the jump table and the float
# literal pool are referenced through symbols. Replace with C/C++ after 100%.
#   func_00166148: texture upload via sceGsSetDefLoadImage/FlushCache/sceGsExecLoadImage (two halves when
#     size > 32767), CLUT upload for psm 19/20, returns the TEX0 register. Closest C: best/00166148.cpp
#     (~139 lines off): register numbering s1-s6 in the big path, prologue schedule, xpsm kept in s5.
# Split out of batch_w3933.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00166148,"ax",@progbits
	.globl func_00166148
	.type func_00166148, @function
	.ent func_00166148
func_00166148:
	addiu	$29,$29,-112
	li	$9,1
	sd	$23,88($29)
	sd	$20,64($29)
	sd	$21,72($29)
	addiu	$23,$4,16
	sd	$30,96($29)
	sd	$31,104($29)
	move	$21,$0
	sw	$5,0($29)
	sw	$6,4($29)
	sd	$16,32($29)
	sd	$17,40($29)
	sd	$18,48($29)
	sd	$19,56($29)
	sd	$22,80($29)
	lhu	$13,12($23)
	sw	$9,12($29)
	addu	$30,$23,$13
	lhu	$15,20($23)
	lw	$14,8($23)
	move	$4,$15
	srl	$15,$15,0x6
	sw	$0,16($29)
	addu	$14,$30,$14
	sw	$15,20($29)
	jal	func_001667d0
	sw	$14,8($29)
	sw	$2,24($29)
	lw	$20,20($29)
	jal	func_001667d0
	lhu	$4,22($23)
	sw	$2,28($29)
	lhu	$12,20($23)
	lhu	$9,22($23)
	lbu	$14,19($23)
	andi	$10,$12,0xffff
	sltiu	$15,$14,8
	beqz	$15,.L00166210
	andi	$11,$9,0xffff
	sll	$15,$14,0x2
	lui	$14,%hi(D_0036b3c0+0x130)
	addiu	$14,$14,%lo(D_0036b3c0+0x130)
	addu	$15,$15,$14
	lw	$13,0($15)
	jr	$13
	nop
	li	$21,2
.L00166208:
	sw	$21,16($29)
	sw	$0,12($29)
.L00166210:
	lw	$14,8($23)
	li	$15,32767
	sltu	$15,$15,$14
	beqz	$15,.L00166400
	lw	$9,0($29)
	sll	$22,$10,0x10
	lui	$16,%hi(D_0034c7b0+0x60)
	sll	$20,$20,0x10
	sll	$17,$9,0x10
	sll	$21,$21,0x10
	addiu	$16,$16,%lo(D_0034c7b0+0x60)
	srl	$18,$11,0x1
	sra	$22,$22,0x10
	sra	$20,$20,0x10
	sra	$21,$21,0x10
	sra	$17,$17,0x10
	move	$6,$20
	move	$7,$21
	move	$10,$22
	move	$11,$18
	move	$8,$0
	move	$9,$0
	move	$5,$17
	jal	sceGsSetDefLoadImage
	move	$4,$16
	addiu	$19,$16,-96
	jal	func_003058a0
	move	$4,$0
	move	$4,$16
	jal	sceGsExecLoadImage
	move	$5,$30
	move	$5,$17
	move	$9,$18
	move	$6,$20
	move	$7,$21
	move	$10,$22
	move	$4,$19
	move	$8,$0
	jal	sceGsSetDefLoadImage
	move	$11,$18
	jal	func_003058a0
	move	$4,$0
	lw	$5,8($23)
	move	$4,$19
	srl	$5,$5,0x1
	addu	$5,$30,$5
.L001662c8:
	jal	sceGsExecLoadImage
	nop
	lw	$14,16($29)
	addiu	$15,$14,-19
	sltiu	$15,$15,2
	beqz	$15,.L00166370
	li	$14,1
	lbu	$15,18($23)
	andi	$15,$15,0x1f
	andi	$4,$15,0xff
	beq	$4,$14,.L00166308
	slti	$15,$4,2
	beqz	$15,.L0016630c
	lw	$9,16($29)
	beqz	$4,.L001663c8
	move	$2,$0
.L00166308:
	lw	$9,16($29)
.L0016630c:
	li	$15,20
	bne	$9,$15,.L001663f8
	li	$10,16
	li	$10,8
	li	$11,2
.L00166320:
	lw	$12,4($29)
	lui	$16,%hi(D_0034c7b0+0x60)
	addiu	$16,$16,%lo(D_0034c7b0+0x60)
	sll	$10,$10,0x10
	sll	$5,$12,0x10
	sll	$11,$11,0x10
	sra	$5,$5,0x10
	sra	$10,$10,0x10
	sra	$11,$11,0x10
	move	$4,$16
	move	$6,$0
	move	$7,$0
	move	$8,$0
	jal	sceGsSetDefLoadImage
	move	$9,$0
	jal	func_003058a0
	move	$4,$0
	lw	$5,8($29)
	jal	sceGsExecLoadImage
	move	$4,$16
.L00166370:
	lw	$15,24($29)
	lw	$9,28($29)
	dsll	$13,$15,0x1a
	lw	$14,20($29)
	dsll	$15,$9,0x1e
	lw	$12,16($29)
	lw	$9,4($29)
	dsll	$14,$14,0xe
	lw	$11,12($29)
	dsll	$12,$12,0x14
	dsll32	$10,$9,0x5
	or	$14,$14,$12
	or	$15,$15,$10
	dsll32	$11,$11,0x2
	lw	$10,0($29)
	or	$14,$14,$15
	or	$13,$13,$11
	li	$15,1
	or	$13,$10,$13
	dsll32	$15,$15,0x1d
	or	$13,$13,$14
	or	$2,$13,$15
.L001663c8:
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
.L001663f8:
	b	.L00166320
	li	$11,16
.L00166400:
	lw	$12,0($29)
	lui	$16,%hi(D_0034c7b0)
	addiu	$16,$16,%lo(D_0034c7b0)
	sll	$10,$10,0x10
	sll	$5,$12,0x10
	sll	$11,$11,0x10
	sll	$6,$20,0x10
	sll	$7,$21,0x10
	sra	$5,$5,0x10
	sra	$10,$10,0x10
	sra	$11,$11,0x10
	sra	$6,$6,0x10
	sra	$7,$7,0x10
	move	$4,$16
	move	$8,$0
	jal	sceGsSetDefLoadImage
	move	$9,$0
	jal	func_003058a0
	move	$4,$0
	move	$4,$16
	b	.L001662c8
	move	$5,$30
	b	.L00166208
	li	$21,1
	sw	$0,16($29)
	b	.L00166210
	move	$21,$0
	li	$21,20
.L00166470:
	b	.L00166210
	sw	$21,16($29)
	b	.L00166470
	li	$21,19
	andi	$14,$12,0xffff
	andi	$15,$9,0xffff
	li	$12,20
	srl	$10,$14,0x1
	sw	$12,16($29)
	srl	$11,$15,0x2
.L00166498:
	move	$21,$0
	b	.L00166210
	srl	$20,$14,0x7
	andi	$15,$9,0xffff
	andi	$14,$12,0xffff
	srl	$11,$15,0x1
	srl	$10,$14,0x1
	li	$15,19
	b	.L00166498
	sw	$15,16($29)
	.end func_00166148
	.size func_00166148, .-func_00166148
