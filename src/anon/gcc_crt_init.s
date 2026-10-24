# Third-party code notice: this file contains code rebuilt to match the GNU Compiler
# Collection's runtime startup files (crti.asm / crtstuff.c / crtn.asm, GCC 3.2) that the game
# links. Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
# Public License, version 2 or later, with the GCC runtime library exception. It is not
# covered by this project's MIT License.
#
# _init (00319788), the .init section: crti's prologue, one jal per crtstuff contribution
# (crtbegin then crtend), and crtn's epilogue. It is hand-written assembly in GCC.
	.section .text.func_00319788,"ax",@progbits
	.align 2
	.set	reorder
	.globl	func_00319788
	.type	func_00319788, @function
	.ent	func_00319788
func_00319788:
	daddu	$sp,$sp,-48		# crti.asm
	sd	$31,40($sp)
	jal	func_00100350		# crtbegin
	jal	func_00101ce0		# crtend
	ld	$31,40($sp)		# crtn.asm
	daddu	$sp,$sp,48
	j	$31
	.end	func_00319788
