# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002de028_perm2995.c
#     No symbol, written as literal lui/lo values: 0x00375e00, 0x00375e04, 0x00375e08, 0x00375e0c
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002de028,"ax",@progbits
	.align 3
	.globl func_002de028
	.type func_002de028, @function
	.ent func_002de028
func_002de028:
	addiu	$29,$29,-112
	sd	$17,56($29)
	sd	$16,48($29)
	sd	$18,64($29)
	sd	$19,72($29)
	sd	$20,80($29)
	sd	$21,88($29)
	sd	$31,96($29)
	swc1	$f21,108($29)
	swc1	$f20,104($29)
	jal	func_0016a9a0
	move	$17,$4
	lui	$15,%hi(D_00361f60)
	lw	$16,%lo(D_00361f60)($15)
	beqz	$16,.L002de0f0
	addiu	$18,$17,1344
	lq	$8,0($18)
	sq	$8,0($29)
	lw	$15,2808($17)
	beqz	$15,.L002de0f0
	addiu	$19,$17,2800
	li	$5,4
	jal	func_002cf270
	move	$4,$19
	bnezl	$2,.L002de0f4
	ld	$16,48($29)
	move	$4,$19
	jal	func_002cf270
	li	$5,8
	beqzl	$2,.L002de11c
	lbu	$15,2844($17)
	jal	func_002dc7c8
	move	$4,$16
	lui	$15,%hi(D_00349e10)
	lwc1	$f1,176($2)
	lwc1	$f2,%lo(D_00349e10)($15)
	lwc1	$f0,3060($17)
	mul.s	$f1,$f1,$f2
	sub.s	$f0,$f0,$f1
	mtc1	$0,$f2
	c.lt.s	$f0,$f2
	bc1f	.L002de0d8
	swc1	$f0,3060($17)
	swc1	$f2,3060($17)
.L002de0d8:
	lwc1	$f0,%lo(D_00349e10)($15)
	lwc1	$f1,3060($17)
	lwc1	$f2,1348($17)
	mul.s	$f1,$f1,$f0
	add.s	$f2,$f2,$f1
	swc1	$f2,1348($17)
.L002de0f0:
	ld	$16,48($29)
.L002de0f4:
	ld	$17,56($29)
	ld	$18,64($29)
	ld	$19,72($29)
	ld	$20,80($29)
	ld	$21,88($29)
	ld	$31,96($29)
	lwc1	$f21,108($29)
	lwc1	$f20,104($29)
	jr	$31
	addiu	$29,$29,112
.L002de11c:
	beqz	$15,.L002de364
	addiu	$20,$29,16
	lwc1	$f2,3056($17)
	lwc1	$f1,2896($17)
	c.lt.s	$f2,$f1
	bc1f	.L002de280
	addiu	$15,$17,2864
	lq	$8,0($15)
	sq	$8,0($20)
	lwc1	$f0,2848($17)
	mul.s	$f0,$f0,$f2
	lqc2	$vf1,0($20)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($20)
	addiu	$16,$17,2960
	addiu	$15,$17,2880
.L002de164:
	addiu	$14,$29,32
	lqc2	$vf1,0($15)
	lqc2	$vf2,0($20)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($14)
	beq	$16,$14,.L002de18c
	lui	$21,0x35
	lq	$8,0($14)
	sq	$8,0($16)
.L002de188:
	lui	$21,%hi(D_00349e10)
.L002de18c:
	lwc1	$f0,2848($17)
	lwc1	$f1,%lo(D_00349e10)($21)
	lui	$15,0x37
	addiu	$15,$15,24072
	mul.s	$f0,$f0,$f1
	lwc1	$f2,0($15)
.L002de1a4:
	mul.s	$f21,$f0,$f2
	lqc2	$vf1,0($16)
	lqc2	$vf2,0($18)
	vsub.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($20)
	lqc2	$vf1,0($20)
	vmul.xyz	$vf2,$vf1,$vf1
	vaddy.x	$vf2,$vf2,vf2y
	vaddz.x	$vf2,$vf2,vf2z
	vsqrt	Q,vf2x
	vwaitq
	cfc2.ni	$8,$22
	vaddq.x	$vf2,$vf0,Q
	mtc1	$8,$f20
	vnop
	vdiv	Q,vf0w,vf2x
	vwaitq
	vmulq.xyz	$vf1,$vf1,Q
	sqc2	$vf1,0($20)
	lui	$15,0x37
	addiu	$15,$15,24076
	lwc1	$f0,0($15)
	c.lt.s	$f0,$f20
	bc1f	.L002de23c
	move	$5,$0
	li	$6,1
	move	$7,$0
	move	$8,$0
	jal	func_0016ac38
	move	$4,$17
	move	$4,$19
	li	$5,4
	jal	func_002cf280
	move	$6,$0
	move	$4,$19
	li	$5,16384
	jal	func_002cf280
	move	$6,$0
.L002de23c:
	c.lt.s	$f21,$f20
	bc1tl	.L002de248
	mov.s	$f20,$f21
.L002de248:
	lqc2	$vf1,0($20)
	mfc1	$8,$f20
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($20)
	lqc2	$vf1,0($18)
	lqc2	$vf2,0($20)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($18)
	lwc1	$f1,%lo(D_00349e10)($21)
	lwc1	$f0,3056($17)
	add.s	$f0,$f0,$f1
	b	.L002de0f0
	swc1	$f0,3056($17)
.L002de280:
	lwc1	$f3,2928($17)
	add.s	$f0,$f1,$f3
	c.lt.s	$f2,$f0
	bc1f	.L002de324
	mov.s	$f4,$f3
	addiu	$16,$17,2960
	addiu	$15,$17,2912
	beq	$16,$15,.L002de2b0
	sub.s	$f0,$f2,$f1
	lq	$8,0($15)
	sq	$8,0($16)
	lwc1	$f4,2928($17)
.L002de2b0:
	nop
	nop
	div.s	$f0,$f0,$f4
	lui	$14,0x37
	addiu	$14,$14,24064
	lwc1	$f2,2900($17)
	lwc1	$f1,0($14)
	add.s	$f0,$f0,$f0
	mul.s	$f0,$f0,$f1
	mul.s	$f0,$f0,$f2
	jal	func_002de968
	mov.s	$f12,$f0
	jal	sinf
	mov.s	$f12,$f0
	lwc1	$f1,2852($17)
	lui	$14,0x37
	addiu	$14,$14,24068
	lwc1	$f2,2960($17)
	mul.s	$f0,$f0,$f1
	lbu	$15,2932($17)
	lwc1	$f1,0($14)
	beqz	$15,.L002de31c
	mul.s	$f0,$f0,$f1
	add.s	$f0,$f2,$f0
.L002de310:
	swc1	$f0,2960($17)
	b	.L002de188
	addiu	$20,$29,16
.L002de31c:
	b	.L002de310
	sub.s	$f0,$f2,$f0
.L002de324:
	sub.s	$f1,$f2,$f1
	addiu	$20,$29,16
	addiu	$15,$17,2944
	sub.s	$f1,$f1,$f3
	lq	$8,0($15)
	sq	$8,0($20)
	lwc1	$f0,2848($17)
	mul.s	$f0,$f0,$f1
	lqc2	$vf1,0($20)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($20)
	addiu	$16,$17,2960
	b	.L002de164
	addiu	$15,$17,2912
.L002de364:
	addiu	$15,$17,2976
	lq	$8,0($15)
	sq	$8,0($20)
	lui	$21,%hi(D_00349e10)
	lwc1	$f0,28($29)
	lwc1	$f1,%lo(D_00349e10)($21)
	mul.s	$f0,$f0,$f1
	lqc2	$vf1,0($20)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($20)
	addiu	$16,$17,2960
	lqc2	$vf1,0($16)
	lqc2	$vf2,0($20)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($16)
	sw	$0,2968($17)
	lui	$14,0x37
	lwc1	$f0,2988($17)
	addiu	$14,$14,24072
	lwc1	$f1,%lo(D_00349e10)($21)
	lwc1	$f2,0($14)
	b	.L002de1a4
	mul.s	$f0,$f0,$f1
	.end func_002de028
	.size func_002de028, 928
