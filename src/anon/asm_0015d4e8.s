# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0015d4e8,"ax",@progbits
	.align 3
	.globl func_0015d4e8
	.type func_0015d4e8, @function
	.ent func_0015d4e8
func_0015d4e8:
	addiu	$29,$29,-16
	sd	$16,0($29)
	sd	$31,8($29)
	jal	func_0015d440
	move	$16,$4
	bnezl	$2,.L0015d534
	ld	$16,0($29)
	move	$4,$16
	move	$5,$0
.L0015d50c:
	jal	func_00102448
	nop
	jal	func_0014e098
	li	$4,216
	jal	func_0015d440
	nop
	move	$4,$16
	beqz	$2,.L0015d50c
	move	$5,$0
	ld	$16,0($29)
.L0015d534:
	ld	$31,8($29)
	jr	$31
	addiu	$29,$29,16
	.end func_0015d4e8
	.size func_0015d4e8, 88
