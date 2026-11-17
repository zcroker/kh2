# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3877).
# Both functions were near misses in C/C++ after many sessions; see attempts.tsv
# and the best/ADDR_w3877.cpp drafts. Replace with C/C++ after 100%.
#   func_00109708: GIF tag + one A+D register packet (sched2 places lui %hi(D_0036a288) after ori 0xe; 3 lines)
#   func_002ce2a0: path nearest point, segment scan + 33-step bisection (outIdx spill/reload order vs p->count and best loads; 4 lines)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00109708,"ax",@progbits
	.globl func_00109708
	.type func_00109708, @function
	.ent func_00109708
func_00109708:
	addiu	$29,$29,-16
	li	$5,2
	sd	$31,0($29)
	jal	0x133ba0
	lui	$6,0x1300
	por	$15,$0,$0
	ld	$31,0($29)
	sq	$15,0($2)
	li	$14,-32768
	li	$13,-16
	ld	$15,0($2)
	dsrl	$13,$13,0x4
	ld	$12,8($2)
	and	$15,$15,$14
	li	$14,-16
	ori	$15,$15,0x8001
	and	$12,$12,$14
	and	$15,$15,$13
	li	$14,1
	lui	$13,0x37
	dsll32	$14,$14,0x1c
	ori	$12,$12,0xe
	or	$15,$15,$14
	sd	$12,8($2)
	sd	$15,0($2)
	ld	$14,-23928($13)
	li	$15,22
	sd	$14,16($2)
	sd	$15,24($2)
	jr	$31
	addiu	$29,$29,16
	.end func_00109708
	.size func_00109708, .-func_00109708
