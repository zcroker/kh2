# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x305970-0x305990.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_00305970, "ax", @progbits
.globl func_00305970
.type func_00305970, @function
.ent func_00305970
func_00305970:
    addiu $3, $0, -113
    syscall
    jr $31
     nop
.end func_00305970

.section .text.func_00305980, "ax", @progbits
.globl func_00305980
.type func_00305980, @function
.ent func_00305980
func_00305980:
    addiu $3, $0, 114
    syscall
    jr $31
     nop
.end func_00305980
