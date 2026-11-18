# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00103100,"ax",@progbits
	.align 3
	.globl func_00103100
	.type func_00103100, @function
	.ent func_00103100
func_00103100:
	addiu	$29,$29,-16
	sd	$31,0($29)
	jal	func_00167ee0
	nop
	lui	$15,%hi(D_0032ba30)
	lbu	$14,%lo(D_0032ba30)($15)
	bnez	$14,.L0010312c
	lui	$15,0x33
	jal	func_00103748
	nop
	lui	$15,%hi(D_0032ba14)
.L0010312c:
	lw	$14,%lo(D_0032ba14)($15)
	bnez	$14,.L00103140
	move	$4,$0
	jal	func_00103590
	move	$5,$0
.L00103140:
	jal	func_001031b0
	nop
	lui	$15,%hi(D_0032b9e8)
	lui	$14,%hi(D_003a6a50)
	addiu	$15,$15,%lo(D_0032b9e8)
	lw	$4,%lo(D_003a6a50)($14)
	sw	$2,4($15)
	addiu	$15,$4,-100
	sltiu	$15,$15,800
	bnez	$15,.L00103194
	nop
	jal	func_001033d8
	nop
	jal	func_00252fe8
	move	$4,$2
.L0010317c:
	jal	func_001ddc08
	nop
	ld	$31,0($29)
	li	$4,3
	j	func_001e0310
	addiu	$29,$29,16
.L00103194:
	jal	func_001033d8
	nop
	jal	func_00242f00
	move	$4,$2
	b	.L0010317c
	nop
	nop
	.end func_00103100
	.size func_00103100, 176
