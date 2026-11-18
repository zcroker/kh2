# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002586e0_unit.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002586e0,"ax",@progbits
	.align 3
	.globl func_002586e0
	.type func_002586e0, @function
	.ent func_002586e0
func_002586e0:
	addiu	$29,$29,-64
	li	$14,1
	lui	$15,%hi(D_0035f06a)
	sd	$17,8($29)
	sb	$14,%lo(D_0035f06a)($15)
	sd	$31,48($29)
	sd	$16,0($29)
	sd	$18,16($29)
	sd	$19,24($29)
	sd	$20,32($29)
	sd	$21,40($29)
	jal	func_002585a0
	move	$17,$4
	move	$4,$17
	jal	func_00102448
	li	$5,1
	lui	$15,%hi(D_0035f06c)
	li	$14,4
	lh	$13,%lo(D_0035f06c)($15)
	bne	$13,$14,.L002588d0
	li	$14,1
	jal	func_002be750
	nop
	beqz	$2,.L002588c8
	lui	$15,0x36
.L00258744:
	jal	func_00170cd0
	nop
	move	$4,$17
	bnez	$2,.L002588b8
	move	$5,$0
	jal	func_001050c8
	nop
	jal	func_00274ee8
	move	$4,$2
	jal	func_002535b0
	move	$4,$0
	lui	$15,%hi(D_0035f06c)
.L00258774:
	lui	$16,%hi(D_0035f070)
	lh	$4,%lo(D_0035f06c)($15)
	move	$19,$15
	lui	$21,0x36
	jal	func_00253330
	move	$18,$16
	lw	$15,4($2)
	jalr	$15
	move	$20,$21
	sb	$0,%lo(D_0035f070)($16)
	lui	$4,0x26
	jal	func_00103ea0
	addiu	$4,$4,-30032
	move	$16,$21
.L002587ac:
	jal	func_00258c80
	nop
	lbu	$15,-3984($18)
	move	$4,$17
	beqz	$15,.L002588a8
	li	$5,1
	lh	$14,-3988($19)
	li	$15,3
	bne	$14,$15,.L00258880
	li	$13,1
	jal	func_0025f568
	nop
	beqz	$2,.L00258868
	li	$4,1
	jal	func_00258b28
	lui	$18,%hi(D_0035f06e)
	li	$15,-1
.L002587f0:
	sh	$15,%lo(D_0035f06e)($18)
.L002587f4:
	lh	$15,%lo(D_0035f06e)($18)
	bgez	$15,.L0025880c
	li	$5,1
	jal	func_002589b0
	nop
	li	$5,1
.L0025880c:
	jal	func_00102448
	move	$4,$17
	lui	$16,%hi(D_0035f06c)
	jal	func_00253330
	lh	$4,%lo(D_0035f06c)($16)
	lw	$15,8($2)
	jalr	$15
	nop
	lhu	$14,%lo(D_0035f06e)($18)
	li	$15,-1
	ld	$17,8($29)
	sh	$14,%lo(D_0035f06c)($16)
	sh	$15,%lo(D_0035f06e)($18)
	lui	$14,%hi(D_0035f06a)
	ld	$16,0($29)
	sb	$0,%lo(D_0035f06a)($14)
	ld	$18,16($29)
	ld	$19,24($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$31,48($29)
	jr	$31
	addiu	$29,$29,64
.L00258868:
	lui	$18,%hi(D_0035f06e)
	li	$15,1
	li	$14,9
	sb	$15,-3991($21)
	b	.L002587f4
	sh	$14,%lo(D_0035f06e)($18)
.L00258880:
	bnel	$14,$13,.L00258898
	li	$15,4
	sb	$13,-3991($20)
.L0025888c:
	lui	$18,0x36
	b	.L002587f0
	li	$15,9
.L00258898:
	bnel	$14,$15,.L002587f4
	lui	$18,0x36
	b	.L0025888c
	sb	$13,-3991($16)
.L002588a8:
	jal	func_00102448
	nop
	b	.L002587ac
	nop
.L002588b8:
	jal	func_00102448
	nop
	b	.L00258744
	nop
.L002588c8:
	li	$14,1
	lh	$13,-3988($15)
.L002588d0:
	bnel	$13,$14,.L00258774
	lui	$15,0x36
	jal	func_00253568
	li	$4,2
	b	.L00258774
	lui	$15,0x36
	.end func_002586e0
	.size func_002586e0, 520
