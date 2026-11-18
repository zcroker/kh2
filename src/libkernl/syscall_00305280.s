# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305280-0x3052d0.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305280, "ax", @progbits
.globl func_00305280
.type func_00305280, @function
.ent func_00305280
func_00305280:
    addiu $3, $0, 8
    syscall
    jr $31
     nop
.end func_00305280

.section .text.func_00305290, "ax", @progbits
.globl func_00305290
.type func_00305290, @function
.ent func_00305290
func_00305290:
    addiu $3, $0, 9
    syscall
    jr $31
     nop
.end func_00305290

.section .text.func_003052a0, "ax", @progbits
.globl func_003052a0
.type func_003052a0, @function
.ent func_003052a0
func_003052a0:
    addiu $3, $0, 10
    syscall
    jr $31
     nop
.end func_003052a0

.section .text.func_003052b0, "ax", @progbits
.globl func_003052b0
.type func_003052b0, @function
.ent func_003052b0
func_003052b0:
    addiu $3, $0, 11
    syscall
    jr $31
     nop
.end func_003052b0

.section .text.func_003052c0, "ax", @progbits
.globl func_003052c0
.type func_003052c0, @function
.ent func_003052c0
func_003052c0:
    addiu $3, $0, 12
    syscall
    jr $31
     nop
.end func_003052c0
