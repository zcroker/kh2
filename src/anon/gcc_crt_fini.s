# Third-party code notice: this file contains code rebuilt to match the GNU Compiler
# Collection's runtime startup files (crti.asm / crtstuff.c / crtn.asm, GCC 3.2) that the game
# links. Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
# Public License, version 2 or later, with the GCC runtime library exception. It is not
# covered by this project's MIT License.
# 
# _fini (003197ac), the .fini section: crti's prologue, one jal for crtstuff's contribution (0x1002b0) and crtn's epilogue (hand-written assembly in GCC), then an empty function at 0x3197c8 (jr ra; nop)
# that ends the section run before the game's template copies at 0x3197d0. Never written before.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_003197ac,"ax",@progbits
	.align 2
	.globl func_003197ac
	.type func_003197ac, @function
	.ent func_003197ac
func_003197ac:
	daddiu	$29,$29,-48
	sd	$31,40($29)
	jal	0x1002b0
	nop
	ld	$31,40($29)
	jr	$31
	daddiu	$29,$29,48
	.end func_003197ac
	.size func_003197ac, 28

	.section .text.func_003197c8,"ax",@progbits
	.align 2
	.globl func_003197c8
	.type func_003197c8, @function
	.ent func_003197c8
func_003197c8:
	jr	$31
	nop
	.end func_003197c8
	.size func_003197c8, 8
