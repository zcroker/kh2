# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0030ffd8,"ax",@progbits
	.align 2
	.globl func_0030ffd8
	.type func_0030ffd8, @function
	.ent func_0030ffd8
func_0030ffd8:
	lui	$2,0x36
	addiu	$7,$2,28952
	lw	$6,20($7)
	bnez	$6,.L0030fff8
	nop
	lui	$2,0x8000
	jr	$31
	ori	$2,$2,0x8005
.L0030fff8:
	lw	$2,16($7)
	sll	$5,$6,0x4
	lw	$4,0($6)
	addiu	$2,$2,1
	sw	$0,40($6)
	sw	$2,16($7)
	sw	$0,12($6)
	sw	$4,20($7)
	lw	$3,12($7)
	sd	$0,24($6)
	addiu	$3,$3,1
	sw	$3,12($7)
	lw	$2,12($7)
	sll	$2,$2,0x1
	andi	$2,$2,0x3fe
	ori	$2,$2,0x1
	sw	$2,8($6)
	lw	$2,8($6)
	jr	$31
	or	$2,$5,$2
	.end func_0030ffd8
	.size func_0030ffd8, 112
