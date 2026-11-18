# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
# libvu0 (Sony PS2 Runtime Library 3.0.0), 0x2f3cd8-0x2f4298: the VU0 macro-mode functions. Sony's libvu0.c writes
# each of these as a C function whose whole body is one __asm__ block, so this transcription is the closest form the
# build rules allow (no whole-body inline asm in a unit). Linked as its own unit; the C functions between them are
# src/sdk/libvu0_002f4298.c and libvu0_002f4310.c. Gap functions (never written before): 0x2f3eb0, 0x2f3fe0, 0x2f3ff0.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.sceVu0ApplyMatrix,"ax",@progbits
	.align 2
	.globl func_002f3cd8
	.type func_002f3cd8, @function
	.globl sceVu0ApplyMatrix
	.type sceVu0ApplyMatrix, @function
	.ent func_002f3cd8
func_002f3cd8:
sceVu0ApplyMatrix:
	lqc2	$vf4,0($5)
	lqc2	$vf5,16($5)
	lqc2	$vf6,32($5)
	lqc2	$vf7,48($5)
	lqc2	$vf8,0($6)
	vmulax.wxyz	ACC,$vf4,$vf8x
	vmadday.wxyz	ACC,$vf5,$vf8y
	vmaddaz.wxyz	ACC,$vf6,$vf8z
	vmaddw.wxyz	$vf9,$vf7,$vf8w
	jr	$31
	sqc2	$vf9,0($4)
	nop
	.end func_002f3cd8
	.size func_002f3cd8, 44
	.size sceVu0ApplyMatrix, 44

	.section .text.sceVu0MulMatrix,"ax",@progbits
	.align 2
	.globl func_002f3d08
	.type func_002f3d08, @function
	.globl sceVu0MulMatrix
	.type sceVu0MulMatrix, @function
	.ent func_002f3d08
func_002f3d08:
sceVu0MulMatrix:
	lqc2	$vf4,0($5)
	lqc2	$vf5,16($5)
	lqc2	$vf6,32($5)
	lqc2	$vf7,48($5)
	li	$7,4
.L002f3d1c:
	lqc2	$vf8,0($6)
	vmulax.wxyz	ACC,$vf4,$vf8x
	vmadday.wxyz	ACC,$vf5,$vf8y
	vmaddaz.wxyz	ACC,$vf6,$vf8z
	vmaddw.wxyz	$vf9,$vf7,$vf8w
	sqc2	$vf9,0($4)
	addi	$7,$7,-1
	addi	$6,$6,16
	bne	$0,$7,.L002f3d1c
	addi	$4,$4,16
	jr	$31
	nop
	nop
	.end func_002f3d08
	.size func_002f3d08, 68
	.size sceVu0MulMatrix, 68

	.section .text.sceVu0OuterProduct,"ax",@progbits
	.align 2
	.globl func_002f3d50
	.type func_002f3d50, @function
	.globl sceVu0OuterProduct
	.type sceVu0OuterProduct, @function
	.ent func_002f3d50
func_002f3d50:
sceVu0OuterProduct:
	lqc2	$vf4,0($5)
	lqc2	$vf5,0($6)
	vopmula.xyz	ACC,$vf4,$vf5
	vopmsub.xyz	$vf6,$vf5,$vf4
	vsub.w	$vf6,$vf6,$vf6
	jr	$31
	sqc2	$vf6,0($4)
	nop
	.end func_002f3d50
	.size func_002f3d50, 28
	.size sceVu0OuterProduct, 28

	.section .text.sceVu0InnerProduct,"ax",@progbits
	.align 2
	.globl func_002f3d70
	.type func_002f3d70, @function
	.globl sceVu0InnerProduct
	.type sceVu0InnerProduct, @function
	.ent func_002f3d70
func_002f3d70:
sceVu0InnerProduct:
	lqc2	$vf4,0($4)
	lqc2	$vf5,0($5)
	vmul.xyz	$vf5,$vf4,$vf5
	vaddy.x	$vf5,$vf5,$vf5y
	vaddz.x	$vf5,$vf5,$vf5z
	qmfc2	$2,$vf5
	mtc1	$2,$f0
	jr	$31
	nop
	nop
	.end func_002f3d70
	.size func_002f3d70, 36
	.size sceVu0InnerProduct, 36

	.section .text.sceVu0Normalize,"ax",@progbits
	.align 2
	.globl func_002f3d98
	.type func_002f3d98, @function
	.globl sceVu0Normalize
	.type sceVu0Normalize, @function
	.ent func_002f3d98
func_002f3d98:
sceVu0Normalize:
	lqc2	$vf4,0($5)
	vmul.xyz	$vf5,$vf4,$vf4
	vaddy.x	$vf5,$vf5,$vf5y
	vaddz.x	$vf5,$vf5,$vf5z
	vsqrt	Q,$vf5x
	vwaitq
	vaddq.x	$vf5,$vf0,Q
	vnop
	vnop
	vdiv	Q,$vf0w,$vf5x
	vsub.wxyz	$vf6,$vf0,$vf0
	vwaitq
	vmulq.xyz	$vf6,$vf4,Q
	jr	$31
	sqc2	$vf6,0($4)
	nop
	.end func_002f3d98
	.size func_002f3d98, 60
	.size sceVu0Normalize, 60

	.section .text.sceVu0TransposeMatrix,"ax",@progbits
	.align 2
	.globl func_002f3dd8
	.type func_002f3dd8, @function
	.globl sceVu0TransposeMatrix
	.type sceVu0TransposeMatrix, @function
	.ent func_002f3dd8
func_002f3dd8:
sceVu0TransposeMatrix:
	lq	$8,0($5)
	lq	$9,16($5)
	lq	$10,32($5)
	lq	$11,48($5)
	pextlw	$12,$9,$8
	pextuw	$13,$9,$8
	pextlw	$14,$11,$10
	pextuw	$15,$11,$10
	pcpyld	$8,$14,$12
	pcpyud	$9,$12,$14
	pcpyld	$10,$15,$13
	pcpyud	$11,$13,$15
	sq	$8,0($4)
	sq	$9,16($4)
	sq	$10,32($4)
	jr	$31
	sq	$11,48($4)
	nop
	.end func_002f3dd8
	.size func_002f3dd8, 68
	.size sceVu0TransposeMatrix, 68

	.section .text.sceVu0InversMatrix,"ax",@progbits
	.align 2
	.globl func_002f3e20
	.type func_002f3e20, @function
	.globl sceVu0InversMatrix
	.type sceVu0InversMatrix, @function
	.ent func_002f3e20
func_002f3e20:
sceVu0InversMatrix:
	lq	$8,0($5)
	lq	$9,16($5)
	lq	$10,32($5)
	lqc2	$vf4,48($5)
	vmove.wxyz	$vf5,$vf4
	vsub.xyz	$vf4,$vf4,$vf4
	vmove.wxyz	$vf9,$vf4
	qmfc2	$11,$vf4
	pextlw	$12,$9,$8
	pextuw	$13,$9,$8
	pextlw	$14,$11,$10
	pextuw	$15,$11,$10
	pcpyld	$8,$14,$12
	pcpyud	$9,$12,$14
	pcpyld	$10,$15,$13
	qmtc2	$8,$vf6
	qmtc2	$9,$vf7
	qmtc2	$10,$vf8
	vmulax.xyz	ACC,$vf6,$vf5x
	vmadday.xyz	ACC,$vf7,$vf5y
	vmaddz.xyz	$vf4,$vf8,$vf5z
	vsub.xyz	$vf4,$vf9,$vf4
	sq	$8,0($4)
	sq	$9,16($4)
	sq	$10,32($4)
	jr	$31
	sqc2	$vf4,48($4)
	nop
	.end func_002f3e20
	.size func_002f3e20, 108
	.size sceVu0InversMatrix, 108

	.section .text.sceVu0DivVector,"ax",@progbits
	.align 2
	.globl func_002f3e90
	.type func_002f3e90, @function
	.globl sceVu0DivVector
	.type sceVu0DivVector, @function
	.ent func_002f3e90
func_002f3e90:
sceVu0DivVector:
	lqc2	$vf4,0($5)
	mfc1	$8,$f12
	qmtc2	$8,$vf5
	vdiv	Q,$vf0w,$vf5x
	vwaitq
	vmulq.wxyz	$vf4,$vf4,Q
	jr	$31
	sqc2	$vf4,0($4)
	.end func_002f3e90
	.size func_002f3e90, 32
	.size sceVu0DivVector, 32

	.section .text.func_002f3eb0,"ax",@progbits
	.align 2
	.globl func_002f3eb0
	.type func_002f3eb0, @function
	.ent func_002f3eb0
func_002f3eb0:
	lqc2	$vf4,0($5)
	mfc1	$8,$f12
	qmtc2	$8,$vf5
	vdiv	Q,$vf0w,$vf5x
	vwaitq
	vmulq.xyz	$vf4,$vf4,Q
	jr	$31
	sqc2	$vf4,0($4)
	.end func_002f3eb0
	.size func_002f3eb0, 32

	.section .text.sceVu0InterVector,"ax",@progbits
	.align 2
	.globl func_002f3ed0
	.type func_002f3ed0, @function
	.globl sceVu0InterVector
	.type sceVu0InterVector, @function
	.ent func_002f3ed0
func_002f3ed0:
sceVu0InterVector:
	lqc2	$vf4,0($5)
	lqc2	$vf5,0($6)
	mfc1	$8,$f12
	qmtc2	$8,$vf6
	vaddw.x	$vf7,$vf0,$vf0w
	vsub.x	$vf8,$vf7,$vf6
	vmulax.wxyz	ACC,$vf4,$vf6x
	vmaddx.wxyz	$vf9,$vf5,$vf8x
	jr	$31
	sqc2	$vf9,0($4)
	.end func_002f3ed0
	.size func_002f3ed0, 40
	.size sceVu0InterVector, 40

	.section .text.sceVu0AddVector,"ax",@progbits
	.align 2
	.globl func_002f3ef8
	.type func_002f3ef8, @function
	.globl sceVu0AddVector
	.type sceVu0AddVector, @function
	.ent func_002f3ef8
func_002f3ef8:
sceVu0AddVector:
	lqc2	$vf4,0($5)
	lqc2	$vf5,0($6)
	vadd.wxyz	$vf6,$vf4,$vf5
	jr	$31
	sqc2	$vf6,0($4)
	nop
	.end func_002f3ef8
	.size func_002f3ef8, 20
	.size sceVu0AddVector, 20

	.section .text.sceVu0SubVector,"ax",@progbits
	.align 2
	.globl func_002f3f10
	.type func_002f3f10, @function
	.globl sceVu0SubVector
	.type sceVu0SubVector, @function
	.ent func_002f3f10
func_002f3f10:
sceVu0SubVector:
	lqc2	$vf4,0($5)
	lqc2	$vf5,0($6)
	vsub.wxyz	$vf6,$vf4,$vf5
	jr	$31
	sqc2	$vf6,0($4)
	nop
	.end func_002f3f10
	.size func_002f3f10, 20
	.size sceVu0SubVector, 20

	.section .text.sceVu0MulVector,"ax",@progbits
	.align 2
	.globl func_002f3f28
	.type func_002f3f28, @function
	.globl sceVu0MulVector
	.type sceVu0MulVector, @function
	.ent func_002f3f28
func_002f3f28:
sceVu0MulVector:
	lqc2	$vf4,0($5)
	lqc2	$vf5,0($6)
	vmul.wxyz	$vf6,$vf4,$vf5
	jr	$31
	sqc2	$vf6,0($4)
	nop
	.end func_002f3f28
	.size func_002f3f28, 20
	.size sceVu0MulVector, 20

	.section .text.sceVu0ScaleVector,"ax",@progbits
	.align 2
	.globl func_002f3f40
	.type func_002f3f40, @function
	.globl sceVu0ScaleVector
	.type sceVu0ScaleVector, @function
	.ent func_002f3f40
func_002f3f40:
sceVu0ScaleVector:
	lqc2	$vf4,0($5)
	mfc1	$8,$f12
	qmtc2	$8,$vf5
	vmulx.wxyz	$vf6,$vf4,$vf5x
	jr	$31
	sqc2	$vf6,0($4)
	.end func_002f3f40
	.size func_002f3f40, 24
	.size sceVu0ScaleVector, 24

	.section .text.sceVu0TransMatrix,"ax",@progbits
	.align 2
	.globl func_002f3f58
	.type func_002f3f58, @function
	.globl sceVu0TransMatrix
	.type sceVu0TransMatrix, @function
	.ent func_002f3f58
func_002f3f58:
sceVu0TransMatrix:
	lqc2	$vf4,0($6)
	lqc2	$vf5,48($5)
	lq	$7,0($5)
	lq	$8,16($5)
	lq	$9,32($5)
	vadd.xyz	$vf5,$vf5,$vf4
	sq	$7,0($4)
	sq	$8,16($4)
	sq	$9,32($4)
	jr	$31
	sqc2	$vf5,48($4)
	nop
	.end func_002f3f58
	.size func_002f3f58, 44
	.size sceVu0TransMatrix, 44

	.section .text.sceVu0CopyVector,"ax",@progbits
	.align 2
	.globl func_002f3f88
	.type func_002f3f88, @function
	.globl sceVu0CopyVector
	.type sceVu0CopyVector, @function
	.ent func_002f3f88
func_002f3f88:
sceVu0CopyVector:
	lq	$6,0($5)
	jr	$31
	sq	$6,0($4)
	nop
	.end func_002f3f88
	.size func_002f3f88, 12
	.size sceVu0CopyVector, 12

	.section .text.sceVu0CopyMatrix,"ax",@progbits
	.align 2
	.globl func_002f3f98
	.type func_002f3f98, @function
	.globl sceVu0CopyMatrix
	.type sceVu0CopyMatrix, @function
	.ent func_002f3f98
func_002f3f98:
sceVu0CopyMatrix:
	lq	$6,0($5)
	lq	$7,16($5)
	lq	$8,32($5)
	lq	$9,48($5)
	sq	$6,0($4)
	sq	$7,16($4)
	sq	$8,32($4)
	jr	$31
	sq	$9,48($4)
	nop
	.end func_002f3f98
	.size func_002f3f98, 36
	.size sceVu0CopyMatrix, 36

	.section .text.sceVu0FTOI4Vector,"ax",@progbits
	.align 2
	.globl func_002f3fc0
	.type func_002f3fc0, @function
	.globl sceVu0FTOI4Vector
	.type sceVu0FTOI4Vector, @function
	.ent func_002f3fc0
func_002f3fc0:
sceVu0FTOI4Vector:
	lqc2	$vf4,0($5)
	vftoi4.wxyz	$vf5,$vf4
	jr	$31
	sqc2	$vf5,0($4)
	.end func_002f3fc0
	.size func_002f3fc0, 16
	.size sceVu0FTOI4Vector, 16

	.section .text.sceVu0FTOI0Vector,"ax",@progbits
	.align 2
	.globl func_002f3fd0
	.type func_002f3fd0, @function
	.globl sceVu0FTOI0Vector
	.type sceVu0FTOI0Vector, @function
	.ent func_002f3fd0
func_002f3fd0:
sceVu0FTOI0Vector:
	lqc2	$vf4,0($5)
	vftoi0.wxyz	$vf5,$vf4
	jr	$31
	sqc2	$vf5,0($4)
	.end func_002f3fd0
	.size func_002f3fd0, 16
	.size sceVu0FTOI0Vector, 16

	.section .text.func_002f3fe0,"ax",@progbits
	.align 2
	.globl func_002f3fe0
	.type func_002f3fe0, @function
	.ent func_002f3fe0
func_002f3fe0:
	lqc2	$vf4,0($5)
	vitof4.wxyz	$vf5,$vf4
	jr	$31
	sqc2	$vf5,0($4)
	.end func_002f3fe0
	.size func_002f3fe0, 16

	.section .text.func_002f3ff0,"ax",@progbits
	.align 2
	.globl func_002f3ff0
	.type func_002f3ff0, @function
	.ent func_002f3ff0
func_002f3ff0:
	lqc2	$vf4,0($5)
	vitof0.wxyz	$vf5,$vf4
	jr	$31
	sqc2	$vf5,0($4)
	.end func_002f3ff0
	.size func_002f3ff0, 16

	.section .text.sceVu0UnitMatrix,"ax",@progbits
	.align 2
	.globl func_002f4000
	.type func_002f4000, @function
	.globl sceVu0UnitMatrix
	.type sceVu0UnitMatrix, @function
	.ent func_002f4000
func_002f4000:
sceVu0UnitMatrix:
	vsub.wxyz	$vf4,$vf0,$vf0
	vadd.w	$vf4,$vf4,$vf0
	vmr32.wxyz	$vf5,$vf4
	vmr32.wxyz	$vf6,$vf5
	vmr32.wxyz	$vf7,$vf6
	sqc2	$vf4,48($4)
	sqc2	$vf5,32($4)
	sqc2	$vf6,16($4)
	jr	$31
	sqc2	$vf7,0($4)
	.end func_002f4000
	.size func_002f4000, 40
	.size sceVu0UnitMatrix, 40

	.section .text.func_002f4028,"ax",@progbits
	.align 2
	.globl func_002f4028
	.type func_002f4028, @function
	.ent func_002f4028
func_002f4028:
	lui	$8,0x36
	addiu	$8,$8,15568
	lqc2	$vf5,0($8)
	vmr32.w	$vf6,$vf6
	vaddx.x	$vf4,$vf0,$vf6x
	vmul.x	$vf6,$vf6,$vf6
	vmulx.wyz	$vf4,$vf4,$vf0x
	vmulw.wxyz	$vf8,$vf5,$vf6w
	vsub.wxyz	$vf5,$vf0,$vf0
	vmulx.wxyz	$vf8,$vf8,$vf6x
	vmulx.xyz	$vf8,$vf8,$vf6x
	vaddw.x	$vf4,$vf4,$vf8w
	vmulx.xy	$vf8,$vf8,$vf6x
	vaddz.x	$vf4,$vf4,$vf8z
	vmulx.x	$vf8,$vf8,$vf6x
	vaddy.x	$vf4,$vf4,$vf8y
	vaddx.x	$vf4,$vf4,$vf8x
	vaddx.xy	$vf4,$vf5,$vf4x
	vmul.x	$vf7,$vf4,$vf4
	vsubx.w	$vf7,$vf0,$vf7x
	vsqrt	Q,$vf7w
	vwaitq
	bnez	$7,.L002f4090
	vaddq.x	$vf7,$vf0,Q
	b	.L002f4094
	vaddx.x	$vf4,$vf5,$vf7x
.L002f4090:
	vsubx.x	$vf4,$vf5,$vf7x
.L002f4094:
	jr	$31
	nop
	nop
	.end func_002f4028
	.size func_002f4028, 116

	.section .text.sceVu0RotMatrixZ,"ax",@progbits
	.align 2
	.globl func_002f40a0
	.type func_002f40a0, @function
	.globl sceVu0RotMatrixZ
	.type sceVu0RotMatrixZ, @function
	.ent func_002f40a0
func_002f40a0:
sceVu0RotMatrixZ:
	mtc1	$0,$f0
	c.lt.s	$f12,$f0
	lui	$1,0x3fc9
	ori	$1,$1,0xfdb
	mtc1	$1,$f0
	bc1f	.L002f40c8
	nop
	add.s	$f12,$f0,$f12
	j	0x2f40d0
	li	$7,1
.L002f40c8:
	sub.s	$f12,$f0,$f12
	move	$7,$0
	mfc1	$8,$f12
	qmtc2	$8,$vf6
	move	$6,$31
	jal	0x2f4028
	nop
	move	$31,$6
	vmove.wxyz	$vf6,$vf5
	vmove.wxyz	$vf7,$vf5
	vmove.wxyz	$vf9,$vf0
	vsub.xyz	$vf9,$vf9,$vf9
	vmr32.wxyz	$vf8,$vf9
	vsub.wz	$vf4,$vf4,$vf4
	vaddx.y	$vf6,$vf5,$vf4x
	vaddy.x	$vf6,$vf5,$vf4y
	vsubx.x	$vf7,$vf5,$vf4x
	vaddy.y	$vf7,$vf5,$vf4y
	li	$7,4
.L002f4114:
	lqc2	$vf4,0($5)
	vmulax.wxyz	ACC,$vf6,$vf4x
	vmadday.wxyz	ACC,$vf7,$vf4y
	vmaddaz.wxyz	ACC,$vf8,$vf4z
	vmaddw.wxyz	$vf5,$vf9,$vf4w
	sqc2	$vf5,0($4)
	addi	$7,$7,-1
	addi	$5,$5,16
	bne	$0,$7,.L002f4114
	addi	$4,$4,16
	jr	$31
	nop
	nop
	.end func_002f40a0
	.size func_002f40a0, 164
	.size sceVu0RotMatrixZ, 164

	.section .text.sceVu0RotMatrixX,"ax",@progbits
	.align 2
	.globl func_002f4148
	.type func_002f4148, @function
	.globl sceVu0RotMatrixX
	.type sceVu0RotMatrixX, @function
	.ent func_002f4148
func_002f4148:
sceVu0RotMatrixX:
	mtc1	$0,$f0
	c.lt.s	$f12,$f0
	lui	$1,0x3fc9
	ori	$1,$1,0xfdb
	mtc1	$1,$f0
	bc1f	.L002f4170
	nop
	add.s	$f12,$f0,$f12
	j	0x2f4178
	li	$7,1
.L002f4170:
	sub.s	$f12,$f0,$f12
	move	$7,$0
	mfc1	$8,$f12
	qmtc2	$8,$vf6
	move	$6,$31
	jal	0x2f4028
	nop
	move	$31,$6
	vmove.wxyz	$vf6,$vf5
	vmove.wxyz	$vf7,$vf5
	vmove.wxyz	$vf8,$vf5
	vmove.wxyz	$vf9,$vf5
	vaddw.x	$vf6,$vf5,$vf0w
	vaddw.w	$vf9,$vf5,$vf0w
	vsub.wz	$vf4,$vf4,$vf4
	vaddx.z	$vf7,$vf5,$vf4x
	vaddy.y	$vf7,$vf5,$vf4y
	vsubx.y	$vf8,$vf5,$vf4x
	vaddy.z	$vf8,$vf5,$vf4y
	li	$7,4
.L002f41c0:
	lqc2	$vf4,0($5)
	vmulax.wxyz	ACC,$vf6,$vf4x
	vmadday.wxyz	ACC,$vf7,$vf4y
	vmaddaz.wxyz	ACC,$vf8,$vf4z
	vmaddw.wxyz	$vf5,$vf9,$vf4w
	sqc2	$vf5,0($4)
	addi	$7,$7,-1
	addi	$5,$5,16
	bne	$0,$7,.L002f41c0
	addi	$4,$4,16
	jr	$31
	nop
	.end func_002f4148
	.size func_002f4148, 168
	.size sceVu0RotMatrixX, 168

	.section .text.sceVu0RotMatrixY,"ax",@progbits
	.align 2
	.globl func_002f41f0
	.type func_002f41f0, @function
	.globl sceVu0RotMatrixY
	.type sceVu0RotMatrixY, @function
	.ent func_002f41f0
func_002f41f0:
sceVu0RotMatrixY:
	mtc1	$0,$f0
	c.lt.s	$f12,$f0
	lui	$1,0x3fc9
	ori	$1,$1,0xfdb
	mtc1	$1,$f0
	bc1f	.L002f4218
	nop
	add.s	$f12,$f0,$f12
	j	0x2f4220
	li	$7,1
.L002f4218:
	sub.s	$f12,$f0,$f12
	move	$7,$0
	mfc1	$8,$f12
	qmtc2	$8,$vf6
	move	$6,$31
	jal	0x2f4028
	nop
	move	$31,$6
	vmove.wxyz	$vf6,$vf5
	vmove.wxyz	$vf7,$vf5
	vmove.wxyz	$vf8,$vf5
	vmove.wxyz	$vf9,$vf5
	vaddw.y	$vf7,$vf5,$vf0w
	vaddw.w	$vf9,$vf5,$vf0w
	vsub.wz	$vf4,$vf4,$vf4
	vsubx.z	$vf6,$vf5,$vf4x
	vaddy.x	$vf6,$vf5,$vf4y
	vaddx.x	$vf8,$vf5,$vf4x
	vaddy.z	$vf8,$vf5,$vf4y
	li	$7,4
.L002f4268:
	lqc2	$vf4,0($5)
	vmulax.wxyz	ACC,$vf6,$vf4x
	vmadday.wxyz	ACC,$vf7,$vf4y
	vmaddaz.wxyz	ACC,$vf8,$vf4z
	vmaddw.wxyz	$vf5,$vf9,$vf4w
	sqc2	$vf5,0($4)
	addi	$7,$7,-1
	addi	$5,$5,16
	bne	$0,$7,.L002f4268
	addi	$4,$4,16
	jr	$31
	nop
	.end func_002f41f0
	.size func_002f41f0, 168
	.size sceVu0RotMatrixY, 168
