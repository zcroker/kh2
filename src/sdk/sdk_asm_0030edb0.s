# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0030edb0,"ax",@progbits
	.align 2
	.globl func_0030edb0
	.type func_0030edb0, @function
	.ent func_0030edb0
func_0030edb0:
	mfc0	$3,$12
	lui	$2,0x1
	and	$3,$3,$2
	beqz	$3,.L0030edf4
	sltu	$4,$0,$3
	nop
.L0030edc8:
	di
	sync.p
	mfc0	$2,$12
	lui	$3,0x1
	and	$2,$2,$3
	nop
	nop
	bnez	$2,.L0030edc8
	nop
	jr	$31
	move	$2,$4
.L0030edf4:
	move	$4,$0
	jr	$31
	move	$2,$4
	.end func_0030edb0
	.size func_0030edb0, 80
