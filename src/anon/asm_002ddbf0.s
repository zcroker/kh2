# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002ddbf0_unit.cpp
#     No symbol, written as literal lui/lo values: 0x00375df0, 0x00375df4, 0x00375df8, 0x00375dfc
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002ddbf0,"ax",@progbits
	.align 3
	.globl func_002ddbf0
	.type func_002ddbf0, @function
	.ent func_002ddbf0
func_002ddbf0:
	addiu	$29,$29,-128
	sd	$17,72($29)
	sd	$16,64($29)
	sd	$18,80($29)
	move	$17,$4
	sd	$19,88($29)
	sd	$20,96($29)
	sd	$21,104($29)
	sd	$31,112($29)
	swc1	$f21,124($29)
	swc1	$f20,120($29)
	jal	func_002d00d8
	addiu	$16,$17,2800
	move	$4,$16
	jal	func_002cf270
	li	$5,4
	beqz	$2,.L002ddc7c
	nop
	lw	$15,268($17)
	lw	$14,264($17)
	ori	$15,$15,0x80
	ori	$14,$14,0x400
	sw	$15,268($17)
	sw	$14,264($17)
	ld	$16,64($29)
.L002ddc54:
	ld	$17,72($29)
	ld	$18,80($29)
	ld	$19,88($29)
	ld	$20,96($29)
	ld	$21,104($29)
	ld	$31,112($29)
	lwc1	$f21,124($29)
	lwc1	$f20,120($29)
	jr	$31
	addiu	$29,$29,128
.L002ddc7c:
	jal	func_002cf2d0
	move	$4,$16
	move	$4,$16
	li	$5,1
	jal	func_002cf280
	move	$6,$0
	move	$4,$16
	li	$5,4096
	jal	func_002cf280
	move	$6,$0
	move	$4,$17
	jal	func_0016bd60
	li	$5,3
	lw	$15,264($17)
	lui	$14,%hi(D_00361f60)
	ori	$15,$15,0x1
	sw	$15,264($17)
	lw	$16,%lo(D_00361f60)($14)
	beqzl	$16,.L002ddc54
	ld	$16,64($29)
	sw	$0,3056($17)
	lw	$15,2808($17)
	beqzl	$15,.L002ddc54
	ld	$16,64($29)
	lh	$14,6($15)
	li	$15,32767
	bnel	$14,$15,.L002ddfe8
	mtc1	$14,$f0
	lw	$15,2812($17)
	lwc1	$f21,36($15)
.L002ddcf4:
	jal	cosf
	mov.s	$f12,$f21
	mov.s	$f20,$f0
	jal	sinf
	mov.s	$f12,$f21
	neg.s	$f0,$f0
	mtc1	$0,$f3
	swc1	$f20,0($29)
	swc1	$f3,8($29)
	swc1	$f3,12($29)
	swc1	$f0,4($29)
	sb	$0,2844($17)
	lw	$13,2808($17)
	lhu	$15,12($13)
	addiu	$15,$15,-1
	sltiu	$15,$15,3
	beqz	$15,.L002ddfb8
	addiu	$18,$17,1344
	addiu	$15,$17,2880
	beq	$15,$18,.L002ddd50
	move	$19,$18
	lq	$8,0($18)
	sq	$8,0($15)
.L002ddd50:
	lw	$15,2816($17)
	addiu	$20,$29,16
	lw	$14,2812($17)
	lwc1	$f2,12($15)
	lwc1	$f0,4($15)
	lwc1	$f1,8($15)
	swc1	$f0,16($29)
	swc1	$f1,20($29)
	swc1	$f2,24($29)
	beqz	$14,.L002ddfb0
	swc1	$f3,28($29)
	lwc1	$f2,12($14)
	addiu	$15,$29,48
	lwc1	$f1,4($14)
	addiu	$21,$29,32
	lwc1	$f0,8($14)
	swc1	$f1,48($29)
	swc1	$f0,52($29)
	swc1	$f2,56($29)
	swc1	$f3,60($29)
	lqc2	$vf1,0($18)
	lqc2	$vf2,0($15)
	vsub.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($21)
	lqc2	$vf1,0($20)
	lqc2	$vf2,0($21)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($20)
.L002dddc0:
	li	$15,1
	lw	$13,2808($17)
	sb	$15,2844($17)
	lhu	$14,12($13)
	li	$15,2
	beq	$14,$15,.L002ddfa0
	slti	$15,$14,3
	beqz	$15,.L002ddf6c
	li	$15,1
	beq	$14,$15,.L002ddf54
	nop
.L002dddec:
	lh	$15,8($13)
.L002dddf0:
	addiu	$14,$17,2864
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,2848($17)
	lqc2	$vf1,0($20)
	lqc2	$vf2,0($19)
	vsub.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($21)
	beq	$14,$21,.L002dde20
	nop
	lq	$8,0($21)
	sq	$8,0($14)
.L002dde20:
	lqc2	$vf1,0($14)
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
	sqc2	$vf1,0($14)
	lwc1	$f3,2848($17)
	li	$12,1
	lwc1	$f2,2864($17)
	nop
	nop
	div.s	$f0,$f0,$f3
	mtc1	$0,$f4
	c.lt.s	$f4,$f2
	bc1t	.L002dde84
	swc1	$f0,2896($17)
	move	$12,$0
.L002dde84:
	lwc1	$f0,0($29)
	c.lt.s	$f4,$f0
	bc1t	.L002dde98
	li	$13,1
	move	$13,$0
.L002dde98:
	lw	$15,2808($17)
	lh	$14,20($15)
	mtc1	$14,$f1
	cvt.s.w	$f1,$f1
	beq	$12,$13,.L002ddec4
	swc1	$f1,2900($17)
	lui	$14,0x37
	addiu	$14,$14,24056
	lwc1	$f0,0($14)
	add.s	$f0,$f1,$f0
	swc1	$f0,2900($17)
.L002ddec4:
	addiu	$15,$17,2912
	beql	$15,$20,.L002ddee4
	lwc1	$f0,2852($17)
	lq	$8,0($20)
	sq	$8,0($15)
	lwc1	$f3,2848($17)
	lwc1	$f2,2864($17)
	lwc1	$f0,2852($17)
.L002ddee4:
	lui	$14,0x37
	c.lt.s	$f4,$f2
	addiu	$14,$14,24060
	nop
	nop
	div.s	$f0,$f0,$f3
	li	$15,1
	lwc1	$f1,0($14)
	lwc1	$f2,2900($17)
	add.s	$f0,$f0,$f0
	mul.s	$f0,$f0,$f2
	mul.s	$f0,$f0,$f1
	bc1t	.L002ddf20
	swc1	$f0,2928($17)
	move	$15,$0
.L002ddf20:
	sb	$15,2932($17)
	addiu	$15,$17,2944
	beq	$15,$29,.L002ddf3c
	addiu	$4,$17,2960
	lq	$8,0($29)
	sq	$8,0($15)
.L002ddf38:
	addiu	$4,$17,2960
.L002ddf3c:
	beql	$4,$18,.L002ddc54
	ld	$16,64($29)
	lq	$8,0($18)
	sq	$8,0($4)
	b	.L002ddc54
	ld	$16,64($29)
.L002ddf54:
	jal	func_002dc7c8
	move	$4,$16
	lwc1	$f0,124($2)
.L002ddf60:
	lw	$13,2808($17)
	b	.L002dddec
	swc1	$f0,2852($17)
.L002ddf6c:
	li	$15,3
	beq	$14,$15,.L002ddf90
	li	$15,4
	bnel	$14,$15,.L002dddf0
	lh	$15,8($13)
	jal	func_002dc7c8
	move	$4,$16
	b	.L002ddf60
	lwc1	$f0,136($2)
.L002ddf90:
	jal	func_002dc7c8
	move	$4,$16
	b	.L002ddf60
	lwc1	$f0,132($2)
.L002ddfa0:
	jal	func_002dc7c8
	move	$4,$16
	b	.L002ddf60
	lwc1	$f0,128($2)
.L002ddfb0:
	b	.L002dddc0
	addiu	$21,$29,32
.L002ddfb8:
	addiu	$15,$17,2976
	beql	$15,$29,.L002ddfd4
	lh	$15,8($13)
	lq	$8,0($29)
	sq	$8,0($15)
	lw	$13,2808($17)
	lh	$15,8($13)
.L002ddfd4:
	addiu	$18,$17,1344
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L002ddf38
	swc1	$f0,2988($17)
.L002ddfe8:
	lui	$15,0x37
	addiu	$15,$15,24052
	cvt.s.w	$f0,$f0
	lui	$14,0x37
	addiu	$14,$14,24048
	lwc1	$f2,0($15)
	lwc1	$f1,0($14)
	mul.s	$f0,$f0,$f1
	b	.L002ddcf4
	mul.s	$f21,$f0,$f2
	.end func_002ddbf0
	.size func_002ddbf0, 1056
