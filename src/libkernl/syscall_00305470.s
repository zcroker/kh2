# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305470-0x3054b0.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305470, "ax", @progbits
.globl func_00305470
.type func_00305470, @function
.ent func_00305470
func_00305470:
    addiu $3, $0, 37
    syscall
    jr $31
     nop
.end func_00305470

.section .text.func_00305480, "ax", @progbits
.globl func_00305480
.type func_00305480, @function
.ent func_00305480
func_00305480:
    addiu $3, $0, -38
    syscall
    jr $31
     nop
.end func_00305480

.section .text.func_00305490, "ax", @progbits
.globl func_00305490
.type func_00305490, @function
.ent func_00305490
func_00305490:
    addiu $3, $0, 39
    syscall
    jr $31
     nop
.end func_00305490

.section .text.func_003054a0, "ax", @progbits
.globl func_003054a0
.type func_003054a0, @function
.ent func_003054a0
func_003054a0:
    addiu $3, $0, 40
    syscall
    jr $31
     nop
.end func_003054a0
