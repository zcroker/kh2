# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305900-0x305940.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305900, "ax", @progbits
.globl func_00305900
.type func_00305900, @function
.ent func_00305900
func_00305900:
    addiu $3, $0, 108
    syscall
    jr $31
     nop
.end func_00305900

.section .text.func_00305910, "ax", @progbits
.globl func_00305910
.type func_00305910, @function
.ent func_00305910
func_00305910:
    addiu $3, $0, 109
    syscall
    jr $31
     nop
.end func_00305910

.section .text.func_00305920, "ax", @progbits
.globl func_00305920
.type func_00305920, @function
.ent func_00305920
func_00305920:
    addiu $3, $0, 110
    syscall
    jr $31
     nop
.end func_00305920

.section .text.func_00305930, "ax", @progbits
.globl func_00305930
.type func_00305930, @function
.ent func_00305930
func_00305930:
    addiu $3, $0, 111
    syscall
    jr $31
     nop
.end func_00305930
