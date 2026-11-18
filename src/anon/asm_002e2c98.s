# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
#     No symbol, written as literal lui/lo values: 0x00375f4c
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002e2c98,"ax",@progbits
	.align 3
	.globl func_002e2c98
	.type func_002e2c98, @function
	.ent func_002e2c98
func_002e2c98:
	lwc1	$f0,0($6)
	lui	$15,0x37
	mtc1	$0,$f2
	addiu	$15,$15,24396
	swc1	$f0,0($4)
	lwc1	$f1,4($6)
	swc1	$f2,12($4)
	swc1	$f1,4($4)
	swc1	$f2,8($4)
	lwc1	$f0,0($15)
	lqc2	$vf1,0($4)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($4)
	lqc2	$vf1,0($4)
	vmul.xyz	$vf2,$vf1,$vf1
	vaddy.x	$vf2,$vf2,vf2y
	vaddz.x	$vf2,$vf2,vf2z
	vsqrt	Q,vf2x
	vwaitq
	cfc2.ni	$8,$22
	vaddq.x	$vf2,$vf0,Q
	mtc1	$8,$f1
	vnop
	vdiv	Q,vf0w,vf2x
	vwaitq
	vmulq.xyz	$vf1,$vf1,Q
	sqc2	$vf1,0($4)
	swc1	$f1,12($4)
	jr	$31
	move	$2,$4
	.end func_002e2c98
	.size func_002e2c98, 128
