# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
# libvu0 (Sony PS2 Runtime Library 3.0.0), 0x2f45f0-0x2f4820. Gap functions (never written before): 0x2f45f0, 0x2f4780.
	.set noreorder
	.set noat
	.set nomacro

# 0x2f45f0 is plain C in the original (a drop-shadow matrix: mode != 0 parallel, else point light). A C draft
# (kept in the ledger as best/002f45f0_L78.c, ee-gcc 2.9, the matrix written column by column with lp[] in locals) gives every
# instruction but not the nop;nop before div.s: the original was built with a newer ee-gcc (2.96) than our 2.9.
# Convert later together with 0x2f44e8, which has the same nops.
	.section .text.func_002f45f0,"ax",@progbits
	.align 2
	.globl func_002f45f0
	.type func_002f45f0, @function
	.ent func_002f45f0
func_002f45f0:
	mov.s	$f16,$f12
	beqz	$6,.L002f46a0
	mov.s	$f15,$f13
	lwc1	$f1,0($5)
	lwc1	$f2,4($5)
	mul.s	$f9,$f16,$f1
	lwc1	$f3,8($5)
	mul.s	$f10,$f15,$f2
	lui	$1,0x3f80
	mtc1	$1,$f5
	mul.s	$f6,$f14,$f3
	swc1	$f16,12($4)
	neg.s	$f7,$f1
	swc1	$f15,28($4)
	add.s	$f0,$f9,$f10
	swc1	$f14,44($4)
	neg.s	$f4,$f2
	swc1	$f7,48($4)
	neg.s	$f8,$f3
	add.s	$f0,$f0,$f6
	swc1	$f4,52($4)
	mul.s	$f7,$f15,$f1
	mul.s	$f4,$f16,$f2
	swc1	$f8,56($4)
	sub.s	$f0,$f5,$f0
	mul.s	$f1,$f14,$f1
	swc1	$f7,16($4)
	mul.s	$f2,$f14,$f2
	swc1	$f4,4($4)
	sub.s	$f5,$f0,$f5
	add.s	$f9,$f9,$f0
	swc1	$f1,32($4)
	add.s	$f10,$f10,$f0
	swc1	$f2,36($4)
	add.s	$f6,$f6,$f0
	swc1	$f5,60($4)
	mul.s	$f0,$f16,$f3
	swc1	$f9,0($4)
	mul.s	$f3,$f15,$f3
	swc1	$f10,20($4)
	swc1	$f6,40($4)
	swc1	$f0,8($4)
	jr	$31
	swc1	$f3,24($4)
.L002f46a0:
	lwc1	$f2,0($5)
	lwc1	$f4,4($5)
	mul.s	$f5,$f16,$f2
	lwc1	$f7,8($5)
	mul.s	$f6,$f15,$f4
	lui	$1,0xbf80
	mtc1	$1,$f1
	mul.s	$f8,$f14,$f7
	sw	$0,12($4)
	neg.s	$f9,$f2
	sw	$0,28($4)
	add.s	$f0,$f5,$f6
	sw	$0,44($4)
	mul.s	$f10,$f14,$f4
	neg.s	$f11,$f4
	add.s	$f0,$f0,$f8
	mul.s	$f3,$f15,$f2
	mul.s	$f12,$f16,$f7
	nop
	nop
	div.s	$f1,$f1,$f0
	sub.s	$f5,$f5,$f0
	sub.s	$f6,$f6,$f0
	sub.s	$f8,$f8,$f0
	mul.s	$f13,$f15,$f7
	neg.s	$f0,$f0
	mul.s	$f2,$f14,$f2
	mul.s	$f4,$f16,$f4
	neg.s	$f7,$f7
	mul.s	$f0,$f1,$f0
	mul.s	$f5,$f1,$f5
	mul.s	$f3,$f1,$f3
	mul.s	$f2,$f1,$f2
	swc1	$f0,60($4)
	mul.s	$f9,$f1,$f9
	swc1	$f5,0($4)
	mul.s	$f4,$f1,$f4
	swc1	$f3,16($4)
	mul.s	$f6,$f1,$f6
	swc1	$f2,32($4)
	mul.s	$f10,$f1,$f10
	swc1	$f9,48($4)
	mul.s	$f11,$f1,$f11
	swc1	$f4,4($4)
	mul.s	$f12,$f1,$f12
	swc1	$f6,20($4)
	mul.s	$f13,$f1,$f13
	swc1	$f10,36($4)
	mul.s	$f8,$f1,$f8
	swc1	$f11,52($4)
	mul.s	$f1,$f1,$f7
	swc1	$f12,8($4)
	swc1	$f13,24($4)
	swc1	$f8,40($4)
	jr	$31
	swc1	$f1,56($4)
	.end func_002f45f0
	.size func_002f45f0, 400

# 0x2f4780: VU0 macro-mode loop (whole-body __asm__ in Sony's C source).
	.section .text.func_002f4780,"ax",@progbits
	.align 2
	.globl func_002f4780
	.type func_002f4780, @function
	.ent func_002f4780
func_002f4780:
	lqc2	$vf4,0($5)
	lqc2	$vf5,16($5)
	lqc2	$vf6,32($5)
	lqc2	$vf7,48($5)
.L002f4790:
	lqc2	$vf8,0($6)
	vmulax.wxyz	ACC,$vf4,$vf8x
	vmadday.wxyz	ACC,$vf5,$vf8y
	vmaddaz.wxyz	ACC,$vf6,$vf8z
	vmaddw.wxyz	$vf9,$vf7,$vf8w
	vdiv	Q,$vf0w,$vf9w
	vwaitq
	vmulq.xyz	$vf9,$vf9,Q
	beqz	$8,.L002f47bc
	vftoi4.wxyz	$vf10,$vf9
	vftoi0.wz	$vf10,$vf9
.L002f47bc:
	sqc2	$vf10,0($4)
	addi	$7,$7,-1
	addi	$6,$6,16
	bne	$0,$7,.L002f4790
	addi	$4,$4,16
	jr	$31
	nop
	.end func_002f4780
	.size func_002f4780, 88

	.section .text.func_002f47d8,"ax",@progbits
	.align 2
	.globl func_002f47d8
	.type func_002f47d8, @function
	.ent func_002f47d8
func_002f47d8:
	lqc2	$vf4,0($5)
	lqc2	$vf5,16($5)
	lqc2	$vf6,32($5)
	lqc2	$vf7,48($5)
	lqc2	$vf8,0($6)
	vmulax.wxyz	ACC,$vf4,$vf8x
	vmadday.wxyz	ACC,$vf5,$vf8y
	vmaddaz.wxyz	ACC,$vf6,$vf8z
	vmaddw.wxyz	$vf9,$vf7,$vf8w
	vdiv	Q,$vf0w,$vf9w
	vwaitq
	vmulq.xyz	$vf9,$vf9,Q
	beqz	$7,.L002f4814
	vftoi4.wxyz	$vf10,$vf9
	vftoi0.wz	$vf10,$vf9
.L002f4814:
	jr	$31
	sqc2	$vf10,0($4)
	nop
	.end func_002f47d8
	.size func_002f47d8, 68
