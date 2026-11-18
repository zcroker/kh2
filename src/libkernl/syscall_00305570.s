# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305570-0x305590.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305570, "ax", @progbits
.globl func_00305570
.type func_00305570, @function
.ent func_00305570
func_00305570:
    addiu $3, $0, 53
    syscall
    jr $31
     nop
.end func_00305570

.section .text.func_00305580, "ax", @progbits
.globl func_00305580
.type func_00305580, @function
.ent func_00305580
func_00305580:
    addiu $3, $0, -54
    syscall
    jr $31
     nop
.end func_00305580
