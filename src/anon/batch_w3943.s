# Whole-function assembly (last step of the README match ladder, w3943 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_002b5c30: fills the 4 x 5 list rows (func_002b60e8), then one row per entry from
#     func_00241f10's 32-byte records: title, flag-0x10 details (func_0014ca80 date, online check
#     func_00105c30 == 1/8) and three func_00138c10 icon/colour calls per row.
#     Closest C: ~/re/kh2/tmp.w3943/best_002b5c30.cpp (= coord best/002b5c30_w3864.cpp, 246 of 301 lines off):
#     s-register numbering (i in s3 not s4), stack giv slots 32/36 swapped, record pointer scheduled before the call.
#     No symbol, written as literal lui/addiu values: 0x00374cf0, 0x00374cf8, 0x00374d00, 0x00374d08 (format strings),
#     0x00374da8 (s16 table), 0x00374db8 (s32 table), 0x10000000 (flag mask).
#   func_0027a208: resets the list rows, then fills one row per entry of the D_0035f230 table (8-byte entries
#     from +8): group header when the group byte changes, icon, name, optional count/item text and a colour from
#     func_00286d28/func_00287028 or func_00286ec8/func_00287218.
#     Closest C: ~/re/kh2/tmp.w3943/best_0027a208.cpp (= coord best/0027a208_w3936.cpp, ~181-195 lines off):
#     global register allocation (base/cur/k rotate one s-register) and strength-reduced stack givs.
#     No symbol, written as literal lui/addiu values: 0x00373e20 and 0x00373e18 (s16 tables), plus one
#     lui 0x37 in a branch delay slot (hi of 0x00373e00).
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002b5c30,"ax",@progbits
	.globl func_002b5c30
	.type func_002b5c30, @function
	.ent func_002b5c30
func_002b5c30:
	addiu	$29,$29,-128
	sd	$20,80($29)
	sd	$16,48($29)
	sd	$17,56($29)
	move	$20,$0
	sd	$18,64($29)
	sd	$19,72($29)
	sd	$21,88($29)
	sd	$22,96($29)
	sd	$23,104($29)
	sd	$30,112($29)
	sd	$31,120($29)
	jal	func_00241f10
	sw	$4,16($29)
	sw	$2,24($29)
	move	$16,$20
.L002b5c70:
	move	$18,$0
	move	$5,$18
.L002b5c78:
	move	$4,$16
	li	$6,-1
	jal	func_002b60e8
	move	$7,$0
	addiu	$18,$18,1
	slti	$15,$18,5
	bnez	$15,.L002b5c78
	move	$5,$18
	addiu	$20,$16,1
	slti	$15,$20,4
	bnez	$15,.L002b5c70
	move	$16,$20
	lui	$16,%hi(D_0035f64c)
	move	$20,$0
	lw	$4,%lo(D_0035f64c)($16)
	jal	func_0028b038
	sw	$0,36($29)
	lw	$4,%lo(D_0035f64c)($16)
	jal	func_0028afa8
	sw	$2,20($29)
	lui	$15,%hi(D_0035f678)
	lw	$5,20($29)
	lw	$4,%lo(D_0035f678)($15)
	jal	func_0028be78
	move	$30,$2
	lui	$13,%hi(D_0035f690)
	addiu	$13,$13,%lo(D_0035f690)
	sw	$13,32($29)
.L002b5ce8:
	lui	$13,%hi(D_0035f64c)
	jal	func_002892f8
	lw	$4,%lo(D_0035f64c)($13)
	slt	$2,$20,$2
	bnez	$2,.L002b5d30
	lw	$14,20($29)
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
.L002b5d30:
	lui	$13,%hi(D_0035f64c)
	beqzl	$30,.L002b5d3c
	break	0x7
.L002b5d3c:
	addu	$15,$14,$20
	lw	$4,%lo(D_0035f64c)($13)
	div	$0,$15,$30
	li	$14,56
	lui	$21,%hi(D_0035f65c)
	move	$5,$20
	lw	$16,%lo(D_0035f65c)($21)
	mfhi	$17
	mult	$19,$20,$14
	sll	$22,$17,0x5
	jal	func_002891b8
	addiu	$17,$17,1
	addu	$16,$16,$19
	lui	$14,0x37
	move	$18,$2
	move	$4,$16
	addiu	$5,$14,19696
	jal	func_00192cc0
	move	$6,$17
	lw	$15,24($29)
	sw	$2,408($18)
	addu	$16,$15,$22
	lw	$14,8($16)
	bnez	$14,.L002b5ebc
	addiu	$23,$16,8
	lw	$13,16($29)
	li	$4,0x8a9d
	li	$15,0x8a9f
	movn	$4,$15,$13
.L002b5db0:
	jal	func_00192048
	nop
	move	$7,$2
	move	$4,$20
	move	$5,$0
	li	$6,5
.L002b5dc8:
	jal	func_002b60e8
	nop
	lw	$15,0($23)
	andi	$15,$15,0x10
	beqz	$15,.L002b5e8c
	lw	$14,32($29)
	lb	$14,18($23)
	bltz	$14,.L002b5df8
	move	$2,$0
	lb	$5,20($23)
	jal	func_002b5b10
	move	$4,$14
.L002b5df8:
	lw	$15,36($29)
	lui	$13,%hi(D_0035f690)
	addiu	$13,$13,%lo(D_0035f690)
	lw	$17,36($29)
	addu	$16,$15,$13
	move	$5,$2
	jal	func_00138c10
	lw	$4,0($16)
	lb	$14,19($23)
	lw	$4,16($16)
	sll	$15,$14,0x1
	lui	$14,0x37
	addiu	$14,$14,19880
	addu	$15,$15,$14
	jal	func_00138c10
	lh	$5,0($15)
	lw	$15,0($23)
	lui	$14,0x1000
	and	$15,$15,$14
	bnez	$15,.L002b5e54
	li	$14,20
	lui	$15,%hi(D_0035f648)
	lw	$14,%lo(D_0035f648)($15)
.L002b5e54:
	lui	$13,%hi(D_0035f690)
	move	$5,$14
	addiu	$13,$13,%lo(D_0035f690)
	addu	$15,$17,$13
	lw	$4,32($15)
.L002b5e68:
	jal	func_00138c10
	addiu	$20,$20,1
	lw	$14,32($29)
	lw	$15,36($29)
	addiu	$14,$14,4
	addiu	$15,$15,4
	sw	$14,32($29)
	b	.L002b5ce8
	sw	$15,36($29)
.L002b5e8c:
	move	$5,$0
	jal	func_00138c10
	lw	$4,0($14)
	lw	$15,32($29)
	move	$5,$0
	jal	func_00138c10
	lw	$4,16($15)
	lw	$13,32($29)
	lui	$15,%hi(D_0035f648)
	lw	$5,%lo(D_0035f648)($15)
	b	.L002b5e68
	lw	$4,32($13)
.L002b5ebc:
	andi	$15,$14,0x10
	beqz	$15,.L002b60c0
	li	$4,0xcd96
	jal	func_00192048
	li	$18,2
	lw	$5,%lo(D_0035f65c)($21)
	move	$4,$2
	sw	$0,28($29)
	addu	$5,$5,$19
	jal	func_00192c40
	addiu	$5,$5,8
	lw	$4,%lo(D_0035f65c)($21)
	lui	$14,0x37
	lb	$6,25($16)
	addiu	$5,$14,19704
	addu	$4,$4,$19
	addu	$4,$4,$2
	jal	func_00192cc0
	addiu	$4,$4,8
	lw	$7,%lo(D_0035f65c)($21)
	move	$4,$20
	move	$5,$0
	move	$6,$0
	addu	$7,$7,$19
	jal	func_002b60e8
	addiu	$7,$7,8
	lw	$4,%lo(D_0035f65c)($21)
	lui	$5,0x37
	lw	$6,20($16)
	addiu	$5,$5,19712
	addu	$4,$4,$19
	jal	func_00192cc0
	addiu	$4,$4,24
	jal	func_00192b30
	move	$4,$2
	move	$17,$2
	jal	func_00192048
	li	$4,0xb7db
	lw	$4,%lo(D_0035f65c)($21)
	move	$5,$2
	addu	$4,$4,$19
	addu	$4,$4,$17
	jal	func_002595e8
	addiu	$4,$4,24
	lw	$7,%lo(D_0035f65c)($21)
	move	$4,$20
	li	$5,1
	li	$6,1
	addu	$7,$7,$19
	jal	func_002b60e8
	addiu	$7,$7,24
	jal	func_00105c30
	nop
	li	$15,1
	beq	$2,$15,.L002b5fb4
	li	$13,1
	jal	func_00105c30
	nop
	li	$15,8
	bne	$2,$15,.L002b5fbc
	lw	$14,28($29)
	li	$13,1
.L002b5fb4:
	sw	$13,28($29)
	lw	$14,28($29)
.L002b5fbc:
	andi	$15,$14,0xff
	beqz	$15,.L002b6008
	lw	$15,24($29)
	lui	$13,0x37
	addiu	$13,$13,19896
	addu	$14,$22,$15
	lb	$15,24($14)
	sll	$15,$15,0x2
	addu	$15,$15,$13
	lw	$14,0($15)
	blez	$14,.L002b6008
	move	$4,$14
	jal	func_00192048
	li	$18,3
	move	$7,$2
	move	$4,$20
	li	$5,2
	jal	func_002b60e8
	li	$6,2
.L002b6008:
	lw	$14,24($29)
	addu	$17,$22,$14
	lw	$7,12($17)
	beqz	$7,.L002b602c
	move	$5,$18
	move	$4,$20
	addiu	$18,$18,1
	jal	func_002b60e8
	li	$6,3
.L002b602c:
	lw	$4,16($17)
	move	$5,$29
	addiu	$6,$29,4
	addiu	$7,$29,8
	addiu	$8,$29,12
	jal	func_0014ca80
	move	$17,$0
	jal	func_00105c30
	nop
	li	$15,1
	beql	$2,$15,.L002b6074
	li	$17,1
	jal	func_00105c30
	nop
	li	$15,8
	bne	$2,$15,.L002b6078
	li	$14,56
	li	$17,1
.L002b6074:
	li	$14,56
.L002b6078:
	lw	$6,0($29)
	mult	$14,$20,$14
	lw	$7,4($29)
	lui	$15,%hi(D_0035f65c)
	lui	$13,0x37
	lw	$4,%lo(D_0035f65c)($15)
	li	$16,4
	addiu	$5,$13,19720
	li	$15,2
	addu	$4,$4,$14
	movz	$16,$15,$17
	jal	func_00192cc0
	addiu	$4,$4,16
	move	$7,$2
	move	$5,$18
	move	$6,$16
	b	.L002b5dc8
	move	$4,$20
.L002b60c0:
	andi	$15,$14,0x40
	beqz	$15,.L002b60dc
	lw	$14,16($29)
	li	$4,0x8a9e
	li	$15,0x8a9f
	b	.L002b5db0
	movn	$4,$15,$14
.L002b60dc:
	b	.L002b5db0
	li	$4,0x8a9a
	.end func_002b5c30
	.size func_002b5c30, 1204

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
