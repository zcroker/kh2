# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
#     No symbol, written as literal lui/lo values: 0x0036c508
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0017c290,"ax",@progbits
	.align 3
	.globl func_0017c290
	.type func_0017c290, @function
	.ent func_0017c290
func_0017c290:
	addiu	$29,$29,-48
	move	$5,$6
	sd	$16,32($29)
	sd	$31,40($29)
	lw	$15,352($6)
	andi	$15,$15,0x40
	beqz	$15,.L0017c2d4
	move	$16,$4
	lwc1	$f12,240($6)
	mov.s	$f13,$f12
.L0017c2b8:
	jal	func_00184540
	nop
	move	$2,$16
.L0017c2c4:
	ld	$31,40($29)
	ld	$16,32($29)
	jr	$31
	addiu	$29,$29,48
.L0017c2d4:
	lw	$15,356($6)
	andi	$15,$15,0x1
	andi	$15,$15,0xff
	beqz	$15,.L0017c30c
	addiu	$15,$6,16
	lw	$15,2064($6)
	beqz	$15,.L0017c304
	lw	$15,300($6)
	lwc1	$f13,40($15)
.L0017c2f8:
	lwc1	$f12,40($15)
	b	.L0017c2b8
	move	$4,$16
.L0017c304:
	b	.L0017c2f8
	lwc1	$f13,44($15)
.L0017c30c:
	beq	$29,$15,.L0017c320
	lwc1	$f1,12($29)
	lq	$8,0($15)
	sq	$8,0($29)
	lwc1	$f1,12($29)
.L0017c320:
	mtc1	$0,$f0
	c.lt.s	$f0,$f1
	bc1f	.L0017c3e4
	nop
	lqc2	$vf1,0($29)
	vmul.xyz	$vf2,$vf1,$vf1
	vaddy.x	$vf2,$vf2,vf2y
	vaddz.x	$vf2,$vf2,vf2z
	vsqrt	Q,vf2x
	vwaitq
	cfc2.ni	$8,$22
	vaddq.x	$vf2,$vf0,Q
	mtc1	$8,$f0
	vnop
	vdiv	Q,vf0w,vf2x
	vwaitq
	vmulq.xyz	$vf1,$vf1,Q
	sqc2	$vf1,0($29)
	lui	$15,%hi(D_00349e10)
	lwc1	$f0,%lo(D_00349e10)($15)
	mul.s	$f0,$f1,$f0
	addiu	$15,$29,16
	lqc2	$vf1,0($29)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($15)
	beql	$29,$15,.L0017c3a0
	addiu	$5,$5,32
	lq	$8,0($15)
	sq	$8,0($29)
	addiu	$5,$5,32
.L0017c3a0:
	lqc2	$vf1,0($29)
	mfc1	$8,$f1
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($15)
	beql	$5,$15,.L0017c3c8
	lui	$15,%hi(D_00370000)
	lq	$8,%lo(D_00370000)($15)
	sq	$8,0($5)
	lui	$15,0x37
.L0017c3c8:
	addiu	$15,$15,-15096
	lwc1	$f0,0($15)
	swc1	$f0,12($29)
	lq	$8,0($29)
	sq	$8,0($16)
	b	.L0017c2c4
	move	$2,$16
.L0017c3e4:
	vsub.wxyz	$vf1,$vf0,$vf0
	sqc2	$vf1,0($29)
	addiu	$15,$5,32
	vsub.wxyz	$vf1,$vf0,$vf0
	sqc2	$vf1,0($15)
	b	.L0017c3c8
	lui	$15,0x37
	.end func_0017c290
	.size func_0017c290, 368
