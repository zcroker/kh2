# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305400-0x305420.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305400, "ax", @progbits
.globl func_00305400
.type func_00305400, @function
.ent func_00305400
func_00305400:
    addiu $3, $0, -254
    syscall
    jr $31
     nop
.end func_00305400

.section .text.func_00305410, "ax", @progbits
.globl func_00305410
.type func_00305410, @function
.ent func_00305410
func_00305410:
    addiu $3, $0, -255
    syscall
    jr $31
     nop
.end func_00305410
