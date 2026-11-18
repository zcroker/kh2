# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
# crt0 tail (Sony PS2 Runtime Library): a tail jump to 0x30f468 and a syscall stub (li v1,35).
# Assembly in the original crt0.s too; transcribed from the retail disassembly and linked as its own unit (L77 2026-11-18).
# The C copy of func_001002a0 (src/sdk/sdk_w2215.c) was removed when this row was added.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001002a0,"ax",@progbits
	.align 3
	.globl func_001002a0
	.type func_001002a0, @function
	.ent func_001002a0
func_001002a0:
	j	func_0030f468
	nop
	.end func_001002a0
	.size func_001002a0, 8

	.section .text.func_001002a8,"ax",@progbits
	.align 3
	.globl func_001002a8
	.type func_001002a8, @function
	.ent func_001002a8
func_001002a8:
	li	$3,35
	syscall
	.end func_001002a8
	.size func_001002a8, 8
