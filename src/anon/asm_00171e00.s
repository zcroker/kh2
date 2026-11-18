# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/00171e00_unit.c
#     No symbol, written as literal lui/lo values: 0x0036c4a0
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00171e00,"ax",@progbits
	.align 3
	.globl func_00171e00
	.type func_00171e00, @function
	.ent func_00171e00
func_00171e00:
	addiu	$29,$29,-16
	sd	$16,0($29)
	sd	$31,8($29)
	lw	$15,0($4)
	lw	$16,4($15)
	lw	$14,2040($16)
	andi	$14,$14,0x10
	bnez	$14,.L00171e3c
	addiu	$4,$16,2092
	mtc1	$0,$f13
	lui	$15,0x37
	addiu	$15,$15,-15200
	mov.s	$f14,$f13
	jal	func_001ad990
	lwc1	$f12,0($15)
.L00171e3c:
	lw	$15,2040($16)
	ld	$31,8($29)
	ori	$15,$15,0x10
	sw	$15,2040($16)
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,16
	.end func_00171e00
	.size func_00171e00, 88
