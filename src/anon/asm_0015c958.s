# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3884).
# Both functions were long-standing near misses in C/C++ after many sessions; see attempts.tsv
# and the best/ADDR_w3884.cpp drafts. Replace with C/C++ after 100%.
#   func_0015c958: colour/position setter (sched2 order of the flag sb, sd s1/ra and lui s1 in the prologue)
# Split out of batch_w3884.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0015c958,"ax",@progbits
	.align 2
	.globl func_0015c958
	.type func_0015c958, @function
	.ent func_0015c958
func_0015c958:
	mtc1	$9,$f0
	lui	$14,0x4f
	addiu	$14,$14,13904
	mtc1	$8,$f1
	cvt.s.w	$f0,$f0
	li	$13,1
	cvt.s.w	$f1,$f1
	lui	$15,0x34
	sb	$13,3760($15)
	addiu	$29,$29,-32
	sd	$16,0($29)
	andi	$5,$5,0xff
	swc1	$f0,84($14)
	andi	$7,$7,0xff
	swc1	$f1,80($14)
	addiu	$16,$14,68
	mtc1	$4,$f0
	li	$15,128
	sd	$31,16($29)
	andi	$6,$6,0xff
	cvt.s.w	$f0,$f0
	sb	$5,68($14)
	sd	$17,8($29)
	lwc1	$f12,12($16)
	lui	$17,0x4f
	swc1	$f0,72($14)
	lwc1	$f13,16($16)
	sb	$7,2($16)
	sb	$15,3($16)
	jal	0x10a8a8
	sb	$6,1($16)
	lwc1	$f12,4($16)
	jal	0x10a828
	lwc1	$f13,8($16)
	lbu	$6,2($16)
	lbu	$4,13972($17)
	jal	0x10a7d8
	lbu	$5,1($16)
	lwc1	$f0,12($16)
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
	lbu	$4,13972($17)
	lbu	$6,2($16)
	lbu	$5,1($16)
	ld	$17,8($29)
	ld	$16,0($29)
	ld	$31,16($29)
	j	0x1dd1c8
	addiu	$29,$29,32
	.end func_0015c958
	.size func_0015c958, .-func_0015c958
