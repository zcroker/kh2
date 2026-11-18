# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3888, finished by w3898).
# Both functions stayed near misses in C/C++ after many sessions; see attempts.tsv and
# best/ADDR_w3888.cpp. Replace with C/C++ after 100%.
#   u_call0_002398d0 (func_002398d0): GIF packet setup, 25 sd stores. Registers and store order match
#     in C; only the sched2 interleave of the first 28 insns differs (li 66 must outrank lui of D_01dae590).
# Split out of batch_w3898.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002398d0,"ax",@progbits
	.align 2
	.globl _Z16u_call0_002398d0v
	.type _Z16u_call0_002398d0v, @function
	.globl func_002398d0
	.type func_002398d0, @function
	.ent func_002398d0
_Z16u_call0_002398d0v:
func_002398d0:
	lui	$7,0x1db
	li	$8,66
	addiu	$13,$7,-6672
	lui	$14,0x1db
	addiu	$12,$14,-6768
	sd	$8,136($13)
	li	$6,20
	li	$15,96
	lui	$11,0x7000
	sd	$15,32($12)
	ori	$11,$11,0x2
	sd	$6,88($12)
	sd	$11,-6768($14)
	addiu	$29,$29,-16
	li	$10,1
	sd	$11,-6672($7)
	sd	$31,0($29)
	dsll32	$10,$10,0x1c
	ori	$10,$10,0x8001
	sd	$11,96($13)
	li	$9,14
	sd	$10,112($13)
	li	$15,68
	sd	$9,120($13)
	li	$14,72
	sd	$15,32($13)
	sd	$14,80($13)
	move	$4,$0
	sd	$10,16($12)
	sd	$9,24($12)
	sd	$6,40($12)
	sd	$11,48($12)
	sd	$10,64($12)
	sd	$9,72($12)
	sd	$0,80($12)
	sd	$10,16($13)
	sd	$9,24($13)
	sd	$8,40($13)
	sd	$11,48($13)
	sd	$10,64($13)
	sd	$9,72($13)
	sd	$8,88($13)
	sd	$8,128($13)
	ld	$31,0($29)
	j	0x3058a0
	addiu	$29,$29,16
	.end func_002398d0
	.size func_002398d0, .-func_002398d0
