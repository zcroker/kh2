# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
# libvu0 (Sony PS2 Runtime Library 3.0.0), 0x2f4840-0x2f49c0: VU0 macro-mode functions (whole-body __asm__ in Sony's
# C source). Gap functions (never written before): 0x2f4840, 0x2f48d0, 0x2f4930.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002f4840,"ax",@progbits
	.align 2
	.globl func_002f4840
	.type func_002f4840, @function
	.ent func_002f4840
func_002f4840:
	lqc2	$vf4,0($5)
	lqc2	$vf5,0($6)
	mfc1	$8,$f12
	qmtc2	$8,$vf6
	vmove.w	$vf9,$vf4
	vaddw.x	$vf7,$vf0,$vf0w
	vsub.x	$vf8,$vf7,$vf6
	vmulax.xyz	ACC,$vf4,$vf6x
	vmaddx.xyz	$vf9,$vf5,$vf8x
	jr	$31
	sqc2	$vf9,0($4)
	nop
	.end func_002f4840
	.size func_002f4840, 48

	.section .text.func_002f4870,"ax",@progbits
	.align 2
	.globl func_002f4870
	.type func_002f4870, @function
	.ent func_002f4870
func_002f4870:
	lqc2	$vf4,0($5)
	mfc1	$8,$f12
	qmtc2	$8,$vf5
	vmulx.xyz	$vf4,$vf4,$vf5x
	jr	$31
	sqc2	$vf4,0($4)
	.end func_002f4870
	.size func_002f4870, 24

	.section .text.func_002f4888,"ax",@progbits
	.align 2
	.globl func_002f4888
	.type func_002f4888, @function
	.ent func_002f4888
func_002f4888:
	vsub.wxyz	$vf4,$vf0,$vf0
	lui	$2,0x4580
	dsll	$2,$2,0x10
	ori	$2,$2,0x4580
	dsll	$2,$2,0x10
	lqc2	$vf7,0($4)
	qmtc2	$2,$vf6
	ctc2.ni	$0,$16
	vsub.wxy	$vf5,$vf7,$vf4
	vsub.xy	$vf5,$vf6,$vf7
	vnop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$2,$16
	jr	$31
	andi	$2,$2,0xc0
	.end func_002f4888
	.size func_002f4888, 72

	.section .text.func_002f48d0,"ax",@progbits
	.align 2
	.globl func_002f48d0
	.type func_002f48d0, @function
	.ent func_002f48d0
func_002f48d0:
	vsub.wxyz	$vf4,$vf0,$vf0
	lui	$2,0x4580
	dsll	$2,$2,0x10
	ori	$2,$2,0x4580
	dsll	$2,$2,0x10
	lqc2	$vf6,0($4)
	lqc2	$vf8,0($5)
	lqc2	$vf9,0($6)
	qmtc2	$2,$vf7
	ctc2.ni	$0,$16
	vsub.wxy	$vf5,$vf6,$vf4
	vsub.xy	$vf5,$vf7,$vf6
	vsub.wxy	$vf5,$vf8,$vf4
	vsub.xy	$vf5,$vf7,$vf8
	vsub.wxy	$vf5,$vf9,$vf4
	vsub.xy	$vf5,$vf7,$vf9
	vnop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$2,$16
	jr	$31
	andi	$2,$2,0xc0
	.end func_002f48d0
	.size func_002f48d0, 96

	.section .text.func_002f4930,"ax",@progbits
	.align 2
	.globl func_002f4930
	.type func_002f4930, @function
	.ent func_002f4930
func_002f4930:
	lqc2	$vf8,0($7)
	lqc2	$vf4,0($6)
	lqc2	$vf5,16($6)
	lqc2	$vf6,32($6)
	lqc2	$vf7,48($6)
	lqc2	$vf9,0($4)
	lqc2	$vf10,0($5)
	lqc2	$vf11,0($4)
	lqc2	$vf12,0($5)
.L002f4954:
	vmulax.wxyz	ACC,$vf4,$vf8x
	vmadday.wxyz	ACC,$vf5,$vf8y
	vmaddaz.wxyz	ACC,$vf6,$vf8z
	vmaddw.wxyz	$vf8,$vf7,$vf8w
	vmulw.xyz	$vf11,$vf9,$vf8w
	vmulw.xyz	$vf12,$vf10,$vf8w
	vnop
	vnop
	ctc2.ni	$0,$16
	vsub.wxy	$vf11,$vf8,$vf11
	vsub.wxy	$vf12,$vf12,$vf8
	vmove.w	$vf11,$vf9
	vmove.w	$vf12,$vf10
	vnop
	addi	$7,$7,16
	lqc2	$vf8,0($7)
	addi	$8,$8,-1
	cfc2.ni	$2,$16
	andi	$2,$2,0xc0
	beqz	$2,.L002f49b4
	nop
	bne	$0,$8,.L002f4954
	nop
	addi	$2,$0,1
.L002f49b4:
	jr	$31
	nop
	nop
	.end func_002f4930
	.size func_002f4930, 144
