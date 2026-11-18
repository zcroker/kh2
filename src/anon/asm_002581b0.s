# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002581b0_unit.cpp
#   002581b0 (L60, 2026-11-18): near-miss 3 gap fn; cause: update_equiv_regs moves the one-use lui of D_0035f078 next to its store, li a1,408 sits between the two stores in sched1 order so local-alloc reuses t7; hoisting n2=D_00347e60 above the alloc call gives 
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002581b0,"ax",@progbits
	.align 3
	.globl func_002581b0
	.type func_002581b0, @function
	.ent func_002581b0
func_002581b0:
	addiu	$29,$29,-32
	li	$14,1
	lui	$15,%hi(D_0035f068)
	sd	$31,24($29)
	sb	$14,%lo(D_0035f068)($15)
	li	$4,1
	sd	$16,0($29)
	sd	$17,8($29)
	sd	$18,16($29)
	jal	func_002ef7f0
	lui	$17,%hi(D_00347E60)
	jal	func_00103570
	lui	$18,%hi(D_00347F80)
	addiu	$17,$17,%lo(D_00347E60)
	move	$5,$2
	jal	func_001063c0
	li	$4,28
	move	$16,$2
	jal	func_0023f800
	move	$4,$2
	lui	$15,%hi(D_0035f074)
	lui	$14,%hi(D_0035f078)
	sw	$16,%lo(D_0035f074)($15)
	li	$5,408
	sw	$0,%lo(D_0035f078)($14)
	lw	$15,%lo(D_00347F80)($18)
	lw	$4,20($15)
	lw	$14,0($4)
	lw	$2,0($14)
	jalr	$2
	move	$6,$0
	sw	$17,0($2)
	move	$16,$2
	sw	$0,12($2)
	jal	func_00239700
	addiu	$4,$2,24
	lui	$15,%hi(D_0035f07c)
	li	$14,9
	sw	$16,%lo(D_0035f07c)($15)
	li	$5,408
	lui	$15,%hi(D_0035f06c)
	sh	$14,%lo(D_0035f06c)($15)
	lw	$15,%lo(D_00347F80)($18)
	lw	$4,20($15)
	lw	$14,0($4)
	lw	$2,0($14)
	jalr	$2
	move	$6,$0
	sw	$17,0($2)
	move	$16,$2
	sw	$0,12($2)
	jal	func_00239700
	addiu	$4,$2,24
	lui	$15,%hi(D_0035f088)
	li	$14,-1
	sw	$16,%lo(D_0035f088)($15)
	move	$4,$0
	move	$5,$0
	li	$6,-1
	lui	$15,0x36
	jal	func_0026dd18
	sh	$14,-3986($15)
	lui	$15,%hi(D_0035f069)
	lui	$14,%hi(D_0035f06a)
	sb	$0,%lo(D_0035f069)($15)
	sb	$0,%lo(D_0035f06a)($14)
	lui	$15,0x36
	jal	func_00103eb0
	sb	$0,-3989($15)
	lw	$4,4($2)
	lui	$7,%hi(func_00258468)
	ld	$16,0($29)
	move	$5,$0
	ld	$17,8($29)
	addiu	$7,$7,%lo(func_00258468)
	ld	$18,16($29)
	li	$6,1998
	ld	$31,24($29)
	li	$8,4096
	j	func_00102818
	addiu	$29,$29,32
	nop
	.end func_002581b0
	.size func_002581b0, 328
