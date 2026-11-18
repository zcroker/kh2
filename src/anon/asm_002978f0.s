# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002978f0_unit.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002978f0,"ax",@progbits
	.align 3
	.globl func_002978f0
	.type func_002978f0, @function
	.ent func_002978f0
func_002978f0:
	addiu	$29,$29,-192
	sd	$23,168($29)
	sd	$30,176($29)
	sd	$31,184($29)
	move	$23,$5
	sw	$6,104($29)
	move	$30,$4
	sd	$16,112($29)
	sd	$17,120($29)
	sd	$18,128($29)
	sd	$19,136($29)
	lui	$17,%hi(D_0035f594)
	sd	$20,144($29)
	lui	$18,%hi(D_0035f224)
	sd	$21,152($29)
	li	$19,10
	sd	$22,160($29)
	jal	func_002766d0
	move	$20,$0
	move	$22,$23
	lui	$15,%hi(D_0035f200)
	addiu	$16,$2,24
	lw	$4,%lo(D_0035f200)($15)
	li	$15,15
	jal	func_0028b040
	sw	$15,96($29)
	lw	$15,%lo(D_0035f594)($17)
	li	$7,512
	sw	$0,100($29)
	subu	$7,$7,$30
	lw	$4,%lo(D_0035f224)($18)
	sll	$5,$30,0x10
	lh	$8,2($15)
	sll	$6,$23,0x10
	andi	$7,$7,0xffff
	sra	$5,$5,0x10
	mult	$8,$8,$19
	sra	$6,$6,0x10
	move	$21,$2
	addiu	$4,$4,32
	jal	func_0014b950
	andi	$8,$8,0xffff
	lw	$4,%lo(D_0035f224)($18)
	jal	func_0014b9a8
	addiu	$4,$4,32
	lw	$14,%lo(D_0035f594)($17)
	move	$4,$16
	lh	$15,2($14)
	mult	$15,$15,$19
	jal	func_0023aa58
	addu	$19,$23,$15
	move	$18,$2
	jal	func_0023aa78
	move	$4,$16
	lw	$15,96($29)
	move	$16,$2
	lw	$14,%lo(D_0035f594)($17)
	movn	$15,$18,$18
	sw	$15,96($29)
	lh	$15,0($14)
	blez	$15,.L00297a24
	move	$18,$0
	move	$12,$14
	move	$13,$14
.L002979f0:
	beq	$21,$18,.L00297a10
	sll	$15,$20,0x3
	addu	$15,$15,$13
	lh	$14,14($15)
	addu	$14,$18,$14
	slt	$15,$21,$14
	beqzl	$15,.L00297b14
	lh	$15,0($13)
.L00297a10:
	lh	$15,2($12)
	subu	$14,$21,$18
	mult	$14,$14,$15
	sw	$20,100($29)
	subu	$22,$23,$14
.L00297a24:
	li	$4,3
.L00297a28:
	jal	func_001aae68
	lui	$18,%hi(D_0035f594)
	lw	$15,96($29)
	lw	$12,20($2)
	lw	$13,%lo(D_0035f594)($18)
	subu	$14,$16,$15
	subu	$17,$14,$12
	lw	$20,100($29)
	lh	$15,0($13)
	slti	$14,$17,0
	slt	$15,$20,$15
	beqz	$15,.L00297ad8
	movn	$17,$0,$14
	lw	$15,%lo(D_0035f594)($18)
.L00297a60:
	sll	$16,$20,0x3
	addiu	$20,$20,1
	addu	$15,$16,$15
	jal	func_00192048
	lhu	$4,8($15)
	lw	$7,96($29)
	move	$6,$2
	move	$8,$0
	move	$4,$29
	jal	func_001a98e8
	li	$5,3
	move	$4,$29
	jal	func_001aa6d0
	move	$5,$17
	lw	$7,104($29)
	move	$6,$22
	move	$4,$29
	jal	func_001a9ae8
	move	$5,$30
	lw	$13,%lo(D_0035f594)($18)
	addu	$16,$16,$13
	lh	$15,12($16)
	addu	$22,$22,$15
	slt	$14,$22,$19
	beqz	$14,.L00297adc
	lui	$15,0x36
	lh	$15,0($13)
	slt	$15,$20,$15
	bnez	$15,.L00297a60
	lw	$15,%lo(D_0035f594)($18)
.L00297ad8:
	lui	$15,0x36
.L00297adc:
	jal	func_0014b9a8
	lw	$4,-3548($15)
	ld	$16,112($29)
	ld	$17,120($29)
	ld	$18,128($29)
	ld	$19,136($29)
	ld	$20,144($29)
	ld	$21,152($29)
	ld	$22,160($29)
	ld	$23,168($29)
	ld	$30,176($29)
	ld	$31,184($29)
	jr	$31
	addiu	$29,$29,192
.L00297b14:
	addiu	$20,$20,1
	slt	$15,$20,$15
	bnez	$15,.L002979f0
	move	$18,$14
	b	.L00297a28
	li	$4,3
	nop
	.end func_002978f0
	.size func_002978f0, 576
