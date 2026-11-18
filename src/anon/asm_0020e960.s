# Whole-function assembly (last step of the README ladder, 2026-11-10, helper w3897).
# Both functions were near misses in C/C++ after many sessions; see attempts.tsv and
# best/0020e960_w3897.c, best/0024f710_w3897.cpp. Replace with C/C++ after 100%.
#   _Z16u_call0_0020e960v: 4x4 float table + 3 colour bytes setter (sched2 order of the 3 sb stores, 4 lines)
# Split out of batch_w3897.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0020e960,"ax",@progbits
	.globl _Z16u_call0_0020e960v
	.type _Z16u_call0_0020e960v, @function
	.globl func_0020e960
	.type func_0020e960, @function
	.ent _Z16u_call0_0020e960v
_Z16u_call0_0020e960v:
func_0020e960:
	lui	$14,0x37	# 3c0e0037
	mtc1	$0,$f2	# 44801000
	addiu	$14,$14,1968	# 25ce07b0
	li	$13,-128	# 240dff80
	lwc1	$f3,0($14)	# c5c30000
	lui	$15,0x37	# 3c0f0037
	addiu	$15,$15,1972	# 25ef07b4
	lui	$12,0x36	# 3c0c0036
	lui	$14,0x36	# 3c0e0036
	lwc1	$f4,0($15)	# c5e40000
	sb	$13,-28336($14)	# a1cd9150
	addiu	$11,$14,-28336	# 25cb9150
	addiu	$15,$12,-28400	# 258f9110
	swc1	$f2,-28400($12)	# e5829110
	lui	$14,0x37	# 3c0e0037
	swc1	$f2,60($15)	# e5e2003c
	addiu	$14,$14,1976	# 25ce07b8
	swc1	$f3,28($15)	# e5e3001c
	lwc1	$f0,0($14)	# c5c00000
	swc1	$f4,56($15)	# e5e40038
	lui	$14,0x37	# 3c0e0037
	swc1	$f0,32($15)	# e5e00020
	addiu	$14,$14,1980	# 25ce07bc
	sb	$13,1($11)	# a16d0001
	lwc1	$f1,0($14)	# c5c10000
	swc1	$f2,4($15)	# e5e20004
	swc1	$f1,36($15)	# e5e10024
	swc1	$f3,8($15)	# e5e30008
	swc1	$f2,12($15)	# e5e2000c
	swc1	$f2,20($15)	# e5e20014
	swc1	$f2,16($15)	# e5e20010
	swc1	$f3,24($15)	# e5e30018
	swc1	$f4,40($15)	# e5e40028
	swc1	$f2,44($15)	# e5e2002c
	swc1	$f2,48($15)	# e5e20030
	swc1	$f4,52($15)	# e5e40034
	jr	$31	# 03e00008
	sb	$13,2($11)	# a16d0002
	.end _Z16u_call0_0020e960v
	.size _Z16u_call0_0020e960v, .-_Z16u_call0_0020e960v
