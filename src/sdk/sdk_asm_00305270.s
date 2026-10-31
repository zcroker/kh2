# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00305270,"ax",@progbits
	.align 2
	.globl func_00305270
	.type func_00305270, @function
	.ent func_00305270
func_00305270:
	li	$3,7
	syscall
	jr	$31
	nop
	.end func_00305270
	.size func_00305270, 16
