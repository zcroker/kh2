# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/001dd268_unit.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001dd268,"ax",@progbits
	.align 3
	.globl func_001dd268
	.type func_001dd268, @function
	.ent func_001dd268
func_001dd268:
	bnez	$4,.L001dd278
	move	$2,$4
	lui	$15,%hi(D_00352ae0)
	lw	$2,%lo(D_00352ae0)($15)
.L001dd278:
	lui	$15,%hi(D_00352ae8)
	lw	$15,%lo(D_00352ae8)($15)
	addiu	$14,$15,-1
	blez	$14,.L001dd2b0
	nop
	lui	$15,%hi(D_00352ae0)
	lw	$15,%lo(D_00352ae0)($15)
.L001dd294:
	lw	$2,40($2)
	addiu	$14,$14,-1
	nop
	nop
	nop
	bnez	$14,.L001dd294
	movz	$2,$15,$2
.L001dd2b0:
	jr	$31
	nop
	.end func_001dd268
	.size func_001dd268, 80
