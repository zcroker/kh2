# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00127ec8,"ax",@progbits
	.align 3
	.globl func_00127ec8
	.type func_00127ec8, @function
	.ent func_00127ec8
func_00127ec8:
	addiu	$29,$29,-16
	sd	$16,0($29)
	sd	$31,8($29)
	jal	func_00124bb8
	move	$16,$4
	lui	$15,%hi(D_00347bb0)
	lw	$4,4($16)
	addiu	$15,$15,%lo(D_00347bb0)
	ld	$31,8($29)
	sw	$15,0($16)
	lui	$13,%hi(D_003a99f0)
	addiu	$13,$13,%lo(D_003a99f0)
	lhu	$15,16($4)
	lhu	$5,18($4)
	sw	$13,8($16)
	subu	$5,$5,$15
	sll	$14,$5,0x6
	lhu	$15,18($4)
	sll	$15,$15,0x6
	addu	$15,$15,$13
	addu	$12,$15,$14
	sw	$15,12($16)
	addu	$14,$12,$14
	sw	$12,16($16)
	sw	$14,20($16)
	lw	$15,24($4)
	ld	$16,0($29)
	addu	$4,$4,$15
	j	func_0011ed90
	addiu	$29,$29,16
	.end func_00127ec8
	.size func_00127ec8, 120
