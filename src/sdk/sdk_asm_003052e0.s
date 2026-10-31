# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_003052e0,"ax",@progbits
	.align 2
	.globl func_003052e0
	.type func_003052e0, @function
	.ent func_003052e0
func_003052e0:
	li	$3,14
	syscall
	jr	$31
	nop
	.end func_003052e0
	.size func_003052e0, 16
