# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x3054e0-0x305510.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_003054e0, "ax", @progbits
.globl func_003054e0
.type func_003054e0, @function
.ent func_003054e0
func_003054e0:
    addiu $3, $0, -44
    syscall
    jr $31
     nop
.end func_003054e0

.section .text.func_003054f0, "ax", @progbits
.globl func_003054f0
.type func_003054f0, @function
.ent func_003054f0
func_003054f0:
    addiu $3, $0, 45
    syscall
    jr $31
     nop
.end func_003054f0

.section .text.func_00305500, "ax", @progbits
.globl func_00305500
.type func_00305500, @function
.ent func_00305500
func_00305500:
    addiu $3, $0, -46
    syscall
    jr $31
     nop
.end func_00305500
