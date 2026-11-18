# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/00284088_unit.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00284088,"ax",@progbits
	.align 3
	.globl func_00284088
	.type func_00284088, @function
	.ent func_00284088
func_00284088:
	addiu	$29,$29,-32
	li	$4,4
	sd	$31,16($29)
	sd	$16,0($29)
	sd	$17,8($29)
	jal	func_00287b18
	li	$5,3
	jal	func_002887c8
	nop
	bnez	$2,.L002840d8
	li	$4,960
	jal	func_002ba848
	nop
	jal	func_00136a18
	nop
	lui	$15,0x36
	jal	_ZN2YS13TEST_PROGRESS8set_flagEi
	sw	$0,-3392($15)
	jal	func_00102ff0
	li	$4,1
.L002840d8:
	jal	func_00103570
	lui	$17,%hi(D_00347F80)
	move	$5,$2
	jal	func_001063c0
	li	$4,28
	move	$16,$2
	jal	func_0023f800
	move	$4,$2
	lui	$15,%hi(D_0035f2c4)
	lui	$14,0x36
	sw	$16,%lo(D_0035f2c4)($15)
	jal	func_00103570
	sw	$0,-3384($14)
	move	$5,$2
	jal	func_001063c0
	li	$4,8360
	move	$16,$2
	jal	func_00323978
	move	$4,$2
	lui	$15,%hi(D_0035f2cc)
	lui	$14,%hi(D_0035f2d0)
	sw	$16,%lo(D_0035f2cc)($15)
	li	$5,436
	sb	$0,%lo(D_0035f2d0)($14)
	lw	$15,%lo(D_00347F80)($17)
	lw	$4,20($15)
	lw	$14,0($4)
	lw	$2,0($14)
	jalr	$2
	move	$6,$0
	lui	$15,%hi(D_00347E60)
	sw	$0,12($2)
	addiu	$15,$15,%lo(D_00347E60)
	move	$16,$2
	sw	$15,0($2)
	jal	func_00239700
	addiu	$4,$2,24
	lui	$15,%hi(D_00347e40)
	sw	$0,408($16)
	addiu	$15,$15,%lo(D_00347e40)
	lui	$14,0x36
	sw	$15,0($16)
	li	$4,56
	jal	func_00288be8
	sw	$16,-3368($14)
	move	$16,$2
	move	$4,$2
	li	$5,2
	jal	func_002889f0
	move	$6,$0
	lui	$15,%hi(D_0035f2dc)
	move	$6,$0
	sw	$16,%lo(D_0035f2dc)($15)
	lw	$15,%lo(D_00347F80)($17)
	lw	$4,20($15)
	lw	$14,0($4)
	lw	$2,0($14)
	jalr	$2
	li	$5,444
	move	$16,$2
	jal	func_0028d140
	move	$4,$2
	lui	$15,%hi(D_0035f2e0)
	lui	$14,%hi(D_0035f2d4)
	sw	$16,%lo(D_0035f2e0)($15)
	move	$4,$0
	sw	$0,%lo(D_0035f2d4)($14)
	jal	func_00287bd0
	move	$5,$0
	jal	func_00103eb0
	nop
	lw	$4,4($2)
	lui	$7,%hi(func_00284738)
	ld	$16,0($29)
	move	$5,$0
	ld	$17,8($29)
	addiu	$7,$7,%lo(func_00284738)
	ld	$31,16($29)
	li	$6,2000
	li	$8,4096
	j	func_00102818
	addiu	$29,$29,32
	.end func_00284088
	.size func_00284088, 408
