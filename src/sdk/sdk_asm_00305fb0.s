# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00305fb0,"ax",@progbits
	.align 2
	.globl func_00305fb0
	.type func_00305fb0, @function
	.ent func_00305fb0
func_00305fb0:
	lui	$7,0xffff
	move	$6,$0
	ori	$7,$7,0xf000
	nop
.L00305fc0:
	sync
	cache	0x10,0($6)
	sync
	mfc0	$2,$28
	and	$2,$2,$7
	addu	$2,$2,$6
	sltu	$3,$5,$2
	sltu	$2,$2,$4
	bnez	$2,.L00305ffc
	nop
	bnez	$3,.L00305ffc
	nop
	sync
	cache	0x16,0($6)
	sync
.L00305ffc:
	sync
	cache	0x10,1($6)
	sync
	mfc0	$2,$28
	and	$2,$2,$7
	addu	$2,$2,$6
	sltu	$3,$5,$2
	sltu	$2,$2,$4
	bnez	$2,.L00306038
	nop
	bnez	$3,.L00306038
	nop
	sync
	cache	0x16,1($6)
	sync
.L00306038:
	sync
	addiu	$6,$6,64
	slti	$2,$6,4096
	bnez	$2,.L00305fc0
	nop
	jr	$31
	nop
	.end func_00305fb0
	.size func_00305fb0, 164
