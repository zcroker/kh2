# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305200-0x305220.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305200, "ax", @progbits
.globl func_00305200
.type func_00305200, @function
.ent func_00305200
func_00305200:
    addiu $3, $0, 0
    syscall
    jr $31
     nop
.end func_00305200

.section .text.func_00305210, "ax", @progbits
.globl func_00305210
.type func_00305210, @function
.ent func_00305210
func_00305210:
    addiu $3, $0, 1
    syscall
    jr $31
     nop
.end func_00305210
