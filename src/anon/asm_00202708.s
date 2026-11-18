# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/00202708_unit.c
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00202708,"ax",@progbits
	.align 3
	.globl func_00202708
	.type func_00202708, @function
	.ent func_00202708
func_00202708:
	addiu	$29,$29,-224
	li	$15,0xffff
	sd	$17,168($29)
	sd	$16,160($29)
	sd	$18,176($29)
	sd	$19,184($29)
	sd	$20,192($29)
	sd	$21,200($29)
	sd	$31,208($29)
	lw	$13,4($5)
	beq	$13,$15,.L0020290c
	move	$17,$5
	lw	$15,12($6)
	lw	$14,4($15)
	addu	$14,$4,$14
	addiu	$18,$14,160
	lbu	$15,11($18)
	beqz	$15,.L0020290c
	sb	$15,27($29)
	li	$14,36
	lbu	$11,8($5)
	mult	$14,$13,$14
	lui	$15,%hi(D_01d9e6e4)
	andi	$12,$11,0x2
	lw	$13,%lo(D_01d9e6e4)($15)
	lw	$15,16($13)
	addu	$21,$15,$14
	lw	$19,28($21)
	beqz	$12,.L00202944
	sw	$0,0($29)
	li	$15,4
	sw	$15,0($29)
	lw	$14,0($19)
	andi	$15,$14,0x1
	bnez	$15,.L002027a8
	andi	$15,$14,0x2
	li	$15,12
.L0020279c:
	sw	$15,0($29)
	lw	$14,0($19)
	andi	$15,$14,0x2
.L002027a8:
	bnezl	$15,.L002027c0
	lbu	$15,9($17)
	lw	$15,0($29)
	ori	$15,$15,0x10
	sw	$15,0($29)
	lbu	$15,9($17)
.L002027c0:
	beqz	$15,.L002027d0
	lw	$15,0($29)
	ori	$15,$15,0x200
	sw	$15,0($29)
.L002027d0:
	lbu	$15,11($17)
	beqz	$15,.L002027e4
	lw	$15,0($29)
	ori	$15,$15,0x100
	sw	$15,0($29)
.L002027e4:
	lbu	$15,10($17)
	beqz	$15,.L0020293c
	lw	$15,0($29)
	lui	$20,%hi(D_01d9e6e8)
	lw	$6,%lo(D_01d9e6e8)($20)
	addiu	$4,$29,96
	ori	$15,$15,0x2000
	sw	$4,48($29)
	sw	$15,0($29)
	lui	$5,0x1da
	addiu	$6,$6,16
	jal	sceVu0MulMatrix
	addiu	$5,$5,-6080
.L00202818:
	sw	$0,68($29)
	lhu	$15,22($19)
	lbu	$13,21($17)
	sh	$15,8($29)
	sw	$0,28($29)
	sb	$0,10($29)
	lw	$4,%lo(D_01d9e6e8)($20)
	lw	$15,144($4)
	sw	$15,56($29)
	lui	$15,%hi(D_01d9eac0)
	lw	$14,148($4)
	addiu	$15,$15,%lo(D_01d9eac0)
	sw	$15,4($29)
	beqz	$13,.L00202930
	sw	$14,60($29)
	jal	sceVu0UnitMatrix
	addiu	$4,$4,80
	lw	$4,%lo(D_01d9e6e8)($20)
	lui	$5,%hi(D_00354bc0)
	addiu	$5,$5,%lo(D_00354bc0)
	jal	func_002f4820
	addiu	$4,$4,128
	lw	$4,%lo(D_01d9e6e8)($20)
	lui	$5,%hi(D_01d9ea00)
	addiu	$5,$5,%lo(D_01d9ea00)
	addiu	$4,$4,80
	jal	sceVu0MulMatrix
	move	$6,$4
	lw	$15,%lo(D_01d9e6e8)($20)
	addiu	$15,$15,80
.L00202890:
	sw	$0,12($29)
	lui	$16,%hi(D_01d9eaa4)
	sd	$0,16($29)
	move	$4,$19
	sw	$0,64($29)
	move	$5,$29
	sw	$15,32($29)
	lw	$13,%lo(D_01d9e6e8)($20)
	lbu	$14,8($18)
	lbu	$15,9($18)
	addiu	$13,$13,16
	lbu	$12,10($18)
	lbu	$9,25($17)
	lbu	$10,12($17)
	lw	$11,%lo(D_01d9eaa4)($16)
	sb	$14,24($29)
	sb	$15,25($29)
	lui	$14,%hi(D_01d9e980)
	sb	$12,26($29)
	lui	$15,%hi(D_01d9e9c0)
	sw	$13,44($29)
	addiu	$15,$15,%lo(D_01d9e9c0)
	sw	$11,52($29)
	addiu	$14,$14,%lo(D_01d9e980)
	sw	$15,36($29)
	sw	$14,40($29)
	sb	$10,76($29)
	sb	$9,77($29)
	jal	func_0020f1e0
	lw	$6,32($21)
	sw	$2,%lo(D_01d9eaa4)($16)
.L0020290c:
	ld	$16,160($29)
	ld	$17,168($29)
	ld	$18,176($29)
	ld	$19,184($29)
	ld	$20,192($29)
	ld	$21,200($29)
	ld	$31,208($29)
	jr	$31
	addiu	$29,$29,224
.L00202930:
	lui	$15,%hi(D_01d9e900)
	b	.L00202890
	addiu	$15,$15,%lo(D_01d9e900)
.L0020293c:
	b	.L00202818
	lui	$20,0x1da
.L00202944:
	andi	$15,$11,0x1
	andi	$15,$15,0xff
	beqz	$15,.L00202958
	li	$15,128
	sw	$15,0($29)
.L00202958:
	lw	$14,0($19)
	andi	$15,$14,0x1
	bnezl	$15,.L002027a8
	andi	$15,$14,0x2
	lw	$15,0($29)
	b	.L0020279c
	ori	$15,$15,0x8
	nop
	.end func_00202708
	.size func_00202708, 624
