# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0030f620,"ax",@progbits
	.align 2
	.globl func_0030f620
	.type func_0030f620, @function
	.ent func_0030f620
func_0030f620:
	mfc0	$3,$12
	lui	$2,0x1
	and	$3,$3,$2
	beqz	$3,.L0030f65c
	lui	$6,0x1
	nop
.L0030f638:
	di
	sync.p
	mfc0	$2,$12
	and	$2,$2,$6
	nop
	nop
	nop
	bnez	$2,.L0030f638
	nop
.L0030f65c:
	mfc0	$2,$12
	sync.p
	ori	$2,$2,0x6
	xori	$2,$2,0x2
	or	$2,$2,$3
	mtc0	$2,$12
	sync.p
	sw	$5,0($4)
	mtc0	$31,$30
	sync.p
	eret
	.end func_0030f620
	.size func_0030f620, 104
