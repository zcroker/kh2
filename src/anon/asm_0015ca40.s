# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3874).
# Each function was a 2-difference near miss in C/C++ after many sessions; see attempts.tsv
# and the best/ADDR_w3874.cpp drafts. Replace with C/C++ after 100%.
#   func_0015ca40: fog parameter setter (store order of the r byte and lui s1 against sched1)
# Split out of batch_w3874.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0015ca40,"ax",@progbits
	.align 2
	.globl func_0015ca40
	.type func_0015ca40, @function
	.ent func_0015ca40
func_0015ca40:
	addiu	$29,$29,-32
	lui	$15,0x4f
	addiu	$15,$15,13992
	sd	$16,0($29)
	andi	$4,$4,0xff
	swc1	$f13,76($15)
	swc1	$f12,72($15)
	addiu	$16,$15,68
	swc1	$f14,80($15)
	andi	$5,$5,0xff
	swc1	$f15,84($15)
	andi	$6,$6,0xff
	sb	$4,68($15)
	sd	$17,8($29)
	li	$15,128
	sd	$31,16($29)
	sb	$5,1($16)
	move	$4,$16
	sb	$6,2($16)
	lui	$17,0x4f
	jal	0x15cc80
	sb	$15,3($16)
	bnezl	$2,.L0015cacc
	lwc1	$f0,12($16)
	lwc1	$f12,12($16)
	jal	0x10a8a8
	lwc1	$f13,16($16)
	lwc1	$f12,4($16)
	jal	0x10a828
	lwc1	$f13,8($16)
	lbu	$4,14060($17)
	lbu	$5,1($16)
	jal	0x10a7d8
	lbu	$6,2($16)
	lwc1	$f0,12($16)
.L0015cacc:
	lwc1	$f1,16($16)
	cvt.w.s	$f2,$f0
	cvt.w.s	$f0,$f1
	mfc1	$4,$f2
	andi	$4,$4,0xff
	mfc1	$5,$f0
	jal	0x1dd1e8
	andi	$5,$5,0xff
	lwc1	$f12,4($16)
	jal	0x1dd1b0
	lwc1	$f13,8($16)
	lbu	$4,14060($17)
	lbu	$6,2($16)
	lbu	$5,1($16)
	ld	$17,8($29)
	ld	$16,0($29)
	ld	$31,16($29)
	j	0x1dd1c8
	addiu	$29,$29,32
	.end func_0015ca40
	.size func_0015ca40, .-func_0015ca40
