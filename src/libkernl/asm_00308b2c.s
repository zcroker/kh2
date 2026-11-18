# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
# libkernl (Sony PS2 Runtime Library 3.0.0), 0x308b2c: a one-instruction empty function (jr ra) whose delay slot is the
# first instruction of the next function (0x308b30). Never written before; cannot be written in C (gcc adds its own nop).
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00308b2c,"ax",@progbits
	.align 2
	.globl func_00308b2c
	.type func_00308b2c, @function
	.ent func_00308b2c
func_00308b2c:
	jr	$31
	.end func_00308b2c
	.size func_00308b2c, 4
