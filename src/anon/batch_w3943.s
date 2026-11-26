# Whole-function assembly (last step of the README match ladder, w3943 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   Tz__CmSLBase__UpdateListMess: fills the 4 x 5 list rows (func_002b60e8), then one row per entry from
#     func_00241f10's 32-byte records: title, flag-0x10 details (dk__Clock__vCountToHMSMS date, online check
#     func_00105c30 == 1/8) and three func_00138c10 icon/colour calls per row.
#     Closest C: ~/re/kh2/tmp.w3943/best_002b5c30.cpp (= best/002b5c30_w3864.cpp, 246 of 301 lines off):
#     s-register numbering (i in s3 not s4), stack giv slots 32/36 swapped, record pointer scheduled before the call.
#     No symbol, written as literal lui/addiu values: 0x00374cf0, 0x00374cf8, 0x00374d00, 0x00374d08 (format strings),
#     0x00374da8 (s16 table), 0x00374db8 (s32 table), 0x10000000 (flag mask).
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002b5c30,"ax",@progbits
	.globl Tz__CmSLBase__UpdateListMess
	.type Tz__CmSLBase__UpdateListMess, @function
	.ent Tz__CmSLBase__UpdateListMess
Tz__CmSLBase__UpdateListMess:
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
	jal	Tz__ScrollBar__SetPos
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
	jal	dk__Clock__vCountToHMSMS
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
	.end Tz__CmSLBase__UpdateListMess
	.size Tz__CmSLBase__UpdateListMess, 1204

