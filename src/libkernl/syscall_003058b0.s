# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x3058b0-0x3058d0.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_003058b0, "ax", @progbits
.globl func_003058b0
.type func_003058b0, @function
.ent func_003058b0
func_003058b0:
    addiu $3, $0, 102
    syscall
    jr $31
     nop
.end func_003058b0

.section .text.func_003058c0, "ax", @progbits
.globl func_003058c0
.type func_003058c0, @function
.ent func_003058c0
func_003058c0:
    addiu $3, $0, -103
    syscall
    jr $31
     nop
.end func_003058c0
