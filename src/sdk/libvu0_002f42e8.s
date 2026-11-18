# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
# libvu0 (Sony PS2 Runtime Library 3.0.0), 0x2f42e8: a VU0 macro-mode function (whole-body __asm__ in Sony's C source).
	.set noreorder
	.set noat
	.set nomacro

	.section .text.sceVu0ClampVector,"ax",@progbits
	.align 2
	.globl func_002f42e8
	.type func_002f42e8, @function
	.globl sceVu0ClampVector
	.type sceVu0ClampVector, @function
	.ent func_002f42e8
func_002f42e8:
sceVu0ClampVector:
	mfc1	$8,$f12
	mfc1	$9,$f13
	lqc2	$vf6,0($5)
	qmtc2	$8,$vf4
	qmtc2	$9,$vf5
	vmaxx.wxyz	$vf6,$vf6,$vf4x
	vminix.wxyz	$vf6,$vf6,$vf5x
	jr	$31
	sqc2	$vf6,0($4)
	nop
	.end func_002f42e8
	.size func_002f42e8, 36
	.size sceVu0ClampVector, 36
