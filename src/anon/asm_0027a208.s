# Whole-function assembly (last step of the README match ladder, w3943 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_0027a208: resets the list rows, then fills one row per entry of the D_0035f230 table (8-byte entries
#     from +8): group header when the group byte changes, icon, name, optional count/item text and a colour from
#     func_00286d28/func_00287028 or func_00286ec8/func_00287218.
#     Closest C: ~/re/kh2/tmp.w3943/best_0027a208.cpp (= best/0027a208_w3936.cpp, ~181-195 lines off):
#     global register allocation (base/cur/k rotate one s-register) and strength-reduced stack givs.
#     No symbol, written as literal lui/addiu values: 0x00373e20 and 0x00373e18 (s16 tables), plus one
#     lui 0x37 in a branch delay slot (hi of 0x00373e00).
# Split out of batch_w3943.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0027a208,"ax",@progbits
	.globl func_0027a208
	.type func_0027a208, @function
	.ent func_0027a208
func_0027a208:
	addiu	$29,$29,-112
	sd	$16,32($29)
	sd	$21,72($29)
	sd	$22,80($29)
	lui	$16,%hi(D_0035f01c)
	sd	$23,88($29)
	sd	$31,104($29)
	sd	$17,40($29)
	sd	$18,48($29)
	sd	$19,56($29)
	sd	$20,64($29)
	sd	$30,96($29)
	jal	func_00257770
	move	$21,$0
	lw	$4,%lo(D_0035f01c)($16)
	jal	func_002892f8
	move	$23,$2
	blez	$2,.L0027a2e4
	move	$22,$2
	move	$20,$21
	li	$15,0x87d0
	move	$21,$16
	addu	$18,$23,$15
	lui	$19,%hi(D_0035ef6c)
	move	$16,$23
	lw	$4,-4068($21)
.L0027a270:
	move	$5,$20
	addiu	$17,$16,24304
	jal	func_002891b8
	addiu	$20,$20,1
	lw	$5,%lo(D_0035ef6c)($19)
	jal	func_00138c10
	move	$4,$2
	lw	$5,%lo(D_0035ef6c)($19)
	jal	func_00138c10
	move	$4,$17
	sw	$0,408($17)
	addiu	$17,$16,3376
	lw	$5,%lo(D_0035ef6c)($19)
	jal	func_00138c10
	move	$4,$17
	sw	$0,408($17)
	addiu	$17,$16,13840
	lw	$5,%lo(D_0035ef6c)($19)
	move	$4,$17
	jal	func_00138c10
	addiu	$16,$16,436
	sw	$0,408($17)
	move	$4,$18
	addiu	$18,$18,408
	jal	func_00138c10
	lw	$5,%lo(D_0035ef6c)($19)
	slt	$15,$20,$22
	bnez	$15,.L0027a270
	lw	$4,-4068($21)
.L0027a2e4:
	lui	$17,%hi(D_0035f230)
	lw	$15,%lo(D_0035f230)($17)
	lb	$14,7($15)
	bnez	$14,.L0027a36c
	lui	$15,%hi(D_0035f01c)
	move	$5,$0
	lw	$4,%lo(D_0035f01c)($15)
	jal	func_002891b8
	addiu	$17,$23,24304
	move	$4,$2
	jal	func_00138c10
	li	$5,236
	jal	func_00257140
	move	$4,$0
	move	$5,$2
	jal	func_00138c10
	move	$4,$17
	li	$15,2
	li	$4,0xb372
	jal	func_00192048
	sw	$15,432($17)
	sw	$2,408($17)
.L0027a33c:
	ld	$16,32($29)
.L0027a340:
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
.L0027a36c:
	jal	func_0028b038
	lw	$4,-4068($15)
	lui	$15,%hi(D_0035f04c)
	move	$20,$2
	lw	$4,%lo(D_0035f04c)($15)
	jal	func_0028be78
	move	$5,$2
	jal	func_002570a0
	li	$4,15
	move	$4,$2
	move	$5,$29
	jal	func_0027aed8
	addiu	$6,$29,4
	beqz	$20,.L0027a3c0
	lw	$14,-3536($17)
	sll	$15,$20,0x3
	addu	$15,$15,$14
	lb	$13,8($15)
	lb	$14,16($15)
	beq	$13,$14,.L0027a3c4
	move	$30,$13
.L0027a3c0:
	li	$30,-1
.L0027a3c4:
	blez	$22,.L0027a33c
	move	$21,$0
	sw	$23,12($29)
	sw	$23,8($29)
	sw	$23,16($29)
.L0027a3d8:
	lui	$15,%hi(D_0035f230)
	lw	$14,%lo(D_0035f230)($15)
	lb	$15,7($14)
	slt	$15,$20,$15
	beqz	$15,.L0027a33c
	sll	$18,$20,0x3
	addu	$15,$18,$14
	lb	$17,16($15)
	beq	$30,$17,.L0027a44c
	li	$16,436
	lui	$14,0x37
	mult	$16,$21,$16
	addiu	$14,$14,15904
	sll	$17,$17,0x1
	addu	$15,$17,$14
	lh	$5,0($15)
	addu	$16,$23,$16
	addiu	$16,$16,3376
	jal	func_00138c10
	move	$4,$16
	lui	$15,%hi(D_00373e28)
	addiu	$15,$15,%lo(D_00373e28)
	addu	$17,$17,$15
	jal	func_00192048
	lhu	$4,0($17)
	sw	$2,408($16)
	lui	$15,%hi(D_0035f230)
	lw	$14,%lo(D_0035f230)($15)
	addu	$15,$18,$14
.L0027a44c:
	move	$5,$21
	lui	$14,%hi(D_0035f01c)
	lb	$30,16($15)
	jal	func_002891b8
	lw	$4,%lo(D_0035f01c)($14)
	lui	$14,0x37
	sll	$15,$30,0x1
	addiu	$14,$14,15896
	move	$4,$2
	addu	$15,$15,$14
	lh	$16,0($15)
	jal	func_00138c10
	move	$5,$16
	lui	$15,%hi(D_0035f01c)
	move	$6,$16
	lw	$4,%lo(D_0035f01c)($15)
	move	$7,$16
	jal	func_00288fd8
	move	$5,$21
	lui	$14,%hi(D_0035f230)
	move	$4,$20
	lw	$15,%lo(D_0035f230)($14)
	li	$14,436
	addu	$15,$18,$15
	mult	$14,$21,$14
	lhu	$16,12($15)
	jal	func_0027bf20
	addu	$19,$23,$14
	addiu	$17,$19,24304
	jal	func_00257140
	sltiu	$4,$2,1
	move	$5,$2
	jal	func_00138c10
	move	$4,$17
	lui	$14,%hi(D_0035f230)
	li	$5,0xae10
	lw	$15,%lo(D_0035f230)($14)
	move	$4,$16
	addu	$15,$18,$15
	lw	$14,16($29)
	lb	$6,14($15)
	addu	$5,$14,$5
	jal	func_00259618
	sltu	$6,$0,$6
	sw	$2,408($17)
	lw	$15,0($29)
	bnez	$15,.L0027a560
	lui	$17,%hi(D_0035f230)
	lui	$14,%hi(D_0035f230)
	lw	$15,%lo(D_0035f230)($14)
	addu	$15,$18,$15
	lb	$14,17($15)
	beqz	$14,.L0027a55c
	addiu	$17,$19,13840
	li	$5,251
	jal	func_00138c10
	move	$4,$17
	lui	$14,%hi(D_0035f230)
	li	$4,0xb170
	lw	$15,%lo(D_0035f230)($14)
	lw	$14,12($29)
	addu	$15,$18,$15
	lb	$6,17($15)
	addu	$4,$14,$4
	lui	$14,%hi(D_00373de0)
	jal	func_00192cc0
	addiu	$5,$14,%lo(D_00373de0)
	sw	$2,408($17)
.L0027a55c:
	lui	$17,%hi(D_0035f230)
.L0027a560:
	lw	$14,%lo(D_0035f230)($17)
	addu	$15,$18,$14
	lb	$5,18($15)
	bltzl	$5,.L0027a5a4
	lbu	$5,19($15)
	jal	func_00273180
	li	$4,4
	lbu	$16,4($2)
	li	$5,0xb110
	lw	$15,8($29)
	li	$6,1
	move	$4,$16
	jal	func_002595b8
	addu	$5,$15,$5
	lw	$14,%lo(D_0035f230)($17)
	addu	$15,$18,$14
	lbu	$5,19($15)
.L0027a5a4:
	li	$15,255
	andi	$14,$5,0xff
	beq	$14,$15,.L0027a610
	lw	$15,0($29)
	bnez	$15,.L0027a658
	sll	$15,$5,0x18
	sll	$5,$5,0x18
	lw	$4,4($29)
	jal	func_00286d28
	sra	$5,$5,0x18
	beqz	$2,.L0027a610
	lw	$15,%lo(D_0035f230)($17)
	lw	$4,4($29)
	addu	$15,$18,$15
	jal	func_00287028
	lb	$5,19($15)
.L0027a5e4:
	bnez	$2,.L0027a650
	lui	$15,0x37
.L0027a5ec:
	lui	$15,%hi(D_00373dfc)
	lw	$16,%lo(D_00373dfc)($15)
.L0027a5f4:
	li	$4,408
	li	$15,0x87d0
	mult	$4,$21,$4
	move	$5,$16
	addu	$4,$23,$4
	jal	func_00138c10
	addu	$4,$4,$15
.L0027a610:
	lw	$14,8($29)
.L0027a614:
	addiu	$21,$21,1
	lw	$15,12($29)
	addiu	$20,$20,1
	addiu	$14,$14,4
	sw	$14,8($29)
	addiu	$15,$15,4
	sw	$15,12($29)
	lw	$14,16($29)
	slt	$15,$21,$22
	addiu	$14,$14,32
	bnez	$15,.L0027a3d8
	sw	$14,16($29)
	b	.L0027a340
	ld	$16,32($29)
	nop
.L0027a650:
	b	.L0027a5f4
	lw	$16,15872($15)
.L0027a658:
	andi	$14,$5,0x7f
	sra	$15,$15,0x18
	sll	$16,$14,0x18
	andi	$15,$15,0x80
	beqz	$15,.L0027a6a8
	sra	$16,$16,0x18
	jal	func_0027ae78
	lw	$4,4($29)
	move	$4,$2
	jal	func_00286ec8
	move	$5,$16
	beqz	$2,.L0027a614
	lw	$14,8($29)
	jal	func_0027ae78
	lw	$4,4($29)
	move	$4,$2
	jal	func_00287218
	move	$5,$16
	b	.L0027a5e4
	nop
.L0027a6a8:
	move	$4,$0
	jal	func_00286d28
	move	$5,$16
	beqz	$2,.L0027a610
	move	$5,$16
	jal	func_00287028
	move	$4,$0
	beqz	$2,.L0027a5ec
	lui	$15,%hi(D_00373e00)
	b	.L0027a5f4
	lw	$16,%lo(D_00373e00)($15)
	.end func_0027a208
	.size func_0027a208, 1228
