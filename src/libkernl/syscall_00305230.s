# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305230-0x305240.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305230, "ax", @progbits
.globl func_00305230
.type func_00305230, @function
.ent func_00305230
func_00305230:
    addiu $3, $0, 3
    syscall
    jr $31
     nop
.end func_00305230
