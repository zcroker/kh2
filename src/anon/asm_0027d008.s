# Whole-function assembly (last step of the README ladder, 2026-11-10, w3932).
# Both functions were near misses in C/C++ after several sessions; see attempts.tsv
# and best/0027d008_w3808.cpp, best/002f20d0_w3918.c. Replace with C/C++ after 100%.
#   sceGsSetDefDispEnv: sceGsSetDefDispEnv (Sony libgraph, ee-gcc 2.9): MAGH<<23 temp register and non-interlace OR/load order
#   func_0027d008: menu cell/label setup (loop.c will not hoist the inner D[r].n load into s8 nor reduce the store giv separately from c)
# Split out of batch_w3932.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0027d008,"ax",@progbits
	.align 2
	.globl func_0027d008
	.type func_0027d008, @function
	.ent func_0027d008
func_0027d008:
	addiu	$29,$29,-112
	sd	$17,40($29)
	sd	$18,48($29)
	sd	$23,88($29)
	sd	$31,104($29)
	lui	$18,%hi(D_0035ef6c)
	sd	$16,32($29)
	sd	$19,56($29)
	sd	$20,64($29)
	sd	$21,72($29)
	sd	$22,80($29)
	sd	$30,96($29)
	jal	func_00257770
	move	$23,$0
	sw	$2,8($29)
	lui	$15,%hi(D_0035f01c)
	lw	$4,%lo(D_0035f01c)($15)
	jal	func_0028b038
	lw	$17,8($29)
	sw	$2,16($29)
	lui	$15,%hi(D_0035f04c)
	lw	$4,%lo(D_0035f04c)($15)
	jal	Tz__ScrollBar__SetPos
	lw	$5,16($29)
.L0027d068:
	addiu	$16,$17,13840
	li	$20,3
.L0027d070:
	lw	$5,%lo(D_0035ef6c)($18)
	move	$4,$16
	jal	func_00138c10
	addiu	$20,$20,-1
	sw	$0,408($16)
	bgez	$20,.L0027d070
	addiu	$16,$16,436
	addiu	$23,$23,1
	slti	$15,$23,9
	bnez	$15,.L0027d068
	addiu	$17,$17,1744
	lw	$14,16($29)
	li	$15,20
	li	$18,8
	mult	$15,$14,$15
	lw	$14,8($29)
	addiu	$17,$14,3784
	lui	$14,%hi(D_00373f10)
	addiu	$14,$14,%lo(D_00373f10)
	addu	$15,$15,$14
	addiu	$16,$15,2
.L0027d0c4:
	lhu	$4,0($16)
	jal	func_00192048
	addiu	$18,$18,-1
	addiu	$16,$16,20
	sw	$2,0($17)
	bgez	$18,.L0027d0c4
	addiu	$17,$17,436
	move	$23,$0
	lw	$15,16($29)
.L0027d0e8:
	lui	$14,%hi(D_00373f10)
	addiu	$14,$14,%lo(D_00373f10)
	addu	$22,$15,$23
	li	$15,20
	mult	$15,$22,$15
	addu	$15,$15,$14
	lh	$13,0($15)
	li	$14,1
	bne	$13,$14,.L0027d2c8
	li	$15,2
	lui	$15,%hi(D_00373ef8)
	addiu	$15,$15,%lo(D_00373ef8)
.L0027d118:
	sw	$15,12($29)
	li	$15,20
	mult	$12,$22,$15
	lui	$15,%hi(D_00373f10)
	addiu	$15,$15,%lo(D_00373f10)
	addu	$14,$12,$15
	lh	$15,0($14)
	blez	$15,.L0027d210
	move	$20,$0
	li	$15,436
	sll	$14,$23,0x2
	mult	$14,$14,$15
	lui	$15,%hi(D_00373f10)
	addiu	$15,$15,%lo(D_00373f10)
	addu	$13,$12,$15
	lw	$15,8($29)
	addiu	$21,$13,4
	lh	$30,0($13)
	addu	$14,$14,$15
	addiu	$19,$14,13840
.L0027d168:
	li	$14,9
	beq	$22,$14,.L0027d18c
	move	$18,$19
	lui	$14,%hi(D_0035f234)
	lw	$15,%lo(D_0035f234)($14)
	addu	$15,$15,$22
	lb	$14,0($15)
	bne	$14,$20,.L0027d2c0
	lw	$14,12($29)
.L0027d18c:
	lw	$15,12($29)
	lh	$5,0($15)
.L0027d194:
	move	$4,$18
	jal	func_00138c10
	addiu	$16,$18,24
	jal	func_0023aa78
	move	$4,$16
	move	$4,$16
	jal	func_0023aa98
	move	$17,$2
	mult	$17,$17,$20
	move	$16,$2
	move	$4,$18
	move	$5,$29
	jal	func_00138c78
	addiu	$6,$29,4
	lw	$6,4($29)
	move	$4,$18
	jal	func_00138c68
	move	$5,$17
	li	$15,9
	beq	$22,$15,.L0027d29c
	lui	$15,%hi(D_0035f234)
	lhu	$4,0($21)
.L0027d1ec:
	jal	func_00192048
	addiu	$20,$20,1
	sw	$2,408($19)
	addiu	$21,$21,2
	sw	$16,412($19)
	slt	$15,$20,$30
	sw	$0,416($19)
	bnez	$15,.L0027d168
	addiu	$19,$19,436
.L0027d210:
	addiu	$23,$23,1
	slti	$15,$23,9
	bnez	$15,.L0027d0e8
	lw	$15,16($29)
	lw	$19,16($29)
	move	$17,$0
	lui	$18,%hi(D_0035f01c)
	move	$4,$17
.L0027d230:
	jal	func_0027d488
	move	$5,$19
	lw	$4,%lo(D_0035f01c)($18)
	move	$5,$17
	move	$16,$2
	jal	func_002891b8
	addiu	$17,$17,1
	move	$4,$2
	jal	func_0028dcc0
	move	$5,$16
	slti	$15,$17,9
	bnez	$15,.L0027d230
	move	$4,$17
	jal	func_0027d5d8
	nop
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
.L0027d29c:
	lw	$14,%lo(D_0035f234)($15)
	lb	$15,9($14)
	lui	$14,%hi(D_00373f10)
	addiu	$15,$15,90
	sll	$15,$15,0x1
	addiu	$14,$14,%lo(D_00373f10)
	addu	$15,$15,$14
	b	.L0027d1ec
	lhu	$4,4($15)
.L0027d2c0:
	b	.L0027d194
	lh	$5,2($14)
.L0027d2c8:
	bnel	$13,$15,.L0027d2dc
	lui	$15,%hi(D_00373f08)
	lui	$15,%hi(D_00373f00)
	b	.L0027d118
	addiu	$15,$15,%lo(D_00373f00)
.L0027d2dc:
	b	.L0027d118
	addiu	$15,$15,%lo(D_00373f08)
	.end func_0027d008
	.size func_0027d008, 732
