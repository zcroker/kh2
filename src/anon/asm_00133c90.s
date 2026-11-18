# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/00133c90_unit.c
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00133c90,"ax",@progbits
	.align 3
	.globl func_00133c90
	.type func_00133c90, @function
	.ent func_00133c90
func_00133c90:
	addiu	$15,$5,15
	lbu	$13,0($4)
	li	$14,-16
	bnez	$13,.L00133ce8
	and	$5,$15,$14
	lw	$14,8($4)
.L00133ca8:
	lw	$15,16($4)
	lw	$13,20($4)
	addu	$12,$14,$15
	li	$15,-16
	lw	$14,24($4)
	and	$12,$12,$15
	addu	$15,$13,$5
	subu	$12,$12,$13
	subu	$5,$12,$5
	sltu	$14,$5,$14
	bnez	$14,.L00133ce0
	move	$2,$0
	sw	$15,20($4)
	move	$2,$5
.L00133ce0:
	jr	$31
	nop
.L00133ce8:
	b	.L00133ca8
	lw	$14,12($4)
	.end func_00133c90
	.size func_00133c90, 96
