# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x311430-0x311450.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00311430, "ax", @progbits
.globl func_00311430
.type func_00311430, @function
.ent func_00311430
func_00311430:
    addiu $3, $0, 85
    syscall
    jr $31
     nop
.end func_00311430

.section .text.func_00311440, "ax", @progbits
.globl func_00311440
.type func_00311440, @function
.ent func_00311440
func_00311440:
    addiu $3, $0, -85
    syscall
    jr $31
     nop
.end func_00311440
