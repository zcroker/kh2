# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002e18f8,"ax",@progbits
	.align 3
	.globl func_002e18f8
	.type func_002e18f8, @function
	.ent func_002e18f8
func_002e18f8:
	lw	$15,2748($5)
	ori	$15,$15,0x40
	jr	$31
	sw	$15,2748($5)
	.end func_002e18f8
	.size func_002e18f8, 16
