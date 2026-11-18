# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x311490-0x3114f0.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00311490, "ax", @progbits
.globl func_00311490
.type func_00311490, @function
.ent func_00311490
func_00311490:
    addiu $3, $0, -86
    syscall
    jr $31
     nop
.end func_00311490

.section .text.func_003114a0, "ax", @progbits
.globl func_003114a0
.type func_003114a0, @function
.ent func_003114a0
func_003114a0:
    addiu $3, $0, 87
    syscall
    jr $31
     nop
.end func_003114a0

.section .text.func_003114b0, "ax", @progbits
.globl func_003114b0
.type func_003114b0, @function
.ent func_003114b0
func_003114b0:
    addiu $3, $0, -87
    syscall
    jr $31
     nop
.end func_003114b0

.section .text.func_003114c0, "ax", @progbits
.globl func_003114c0
.type func_003114c0, @function
.ent func_003114c0
func_003114c0:
    addiu $3, $0, 88
    syscall
    jr $31
     nop
.end func_003114c0

.section .text.func_003114d0, "ax", @progbits
.globl func_003114d0
.type func_003114d0, @function
.ent func_003114d0
func_003114d0:
    addiu $3, $0, -88
    syscall
    jr $31
     nop
.end func_003114d0

.section .text.func_003114e0, "ax", @progbits
.globl func_003114e0
.type func_003114e0, @function
.ent func_003114e0
func_003114e0:
    addiu $3, $0, 89
    syscall
    jr $31
     nop
.end func_003114e0
