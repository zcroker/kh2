# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00305270,"ax",@progbits
	.align 2
	.globl _ExecPS2
	.type _ExecPS2, @function
	.ent _ExecPS2
_ExecPS2:
	li	$3,7
	syscall
	jr	$31
	nop
	.end _ExecPS2
	.size _ExecPS2, 16
