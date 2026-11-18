# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305a60-0x305a80.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305a60, "ax", @progbits
.globl func_00305a60
.type func_00305a60, @function
.ent func_00305a60
func_00305a60:
    addiu $3, $0, 125
    syscall
    jr $31
     nop
.end func_00305a60

.section .text.func_00305a70, "ax", @progbits
.globl func_00305a70
.type func_00305a70, @function
.ent func_00305a70
func_00305a70:
    addiu $3, $0, 126
    syscall
    jr $31
     nop
.end func_00305a70
