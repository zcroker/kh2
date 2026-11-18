# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001d7418,"ax",@progbits
	.align 3
	.globl func_001d7418
	.type func_001d7418, @function
	.ent func_001d7418
func_001d7418:
	addiu	$29,$29,-16
	li	$6,256
	sd	$16,0($29)
	li	$7,96
	sd	$31,8($29)
	jal	func_001a4db0
	move	$16,$4
	lui	$15,%hi(D_003527f0)
	ld	$31,8($29)
	addiu	$15,$15,%lo(D_003527f0)
	lui	$14,%hi(D_003527e4)
	sw	$15,0($16)
	sw	$16,%lo(D_003527e4)($14)
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,16
	.end func_001d7418
	.size func_001d7418, 64
