# libkernl syscall stubs (Sony PS2 Runtime Library 3.0.0, hand-written assembly in the original), 0x3055b0-0x305600.
# Never written before (no caller in the game); the listed stubs around them are their own units.
# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
.set noreorder
.text

.section .text.func_003055b0, "ax", @progbits
.globl func_003055b0
.type func_003055b0, @function
.ent func_003055b0
func_003055b0:
    addiu $3, $0, 57
    syscall
    jr $31
     nop
.end func_003055b0

.section .text.func_003055c0, "ax", @progbits
.globl func_003055c0
.type func_003055c0, @function
.ent func_003055c0
func_003055c0:
    addiu $3, $0, -58
    syscall
    jr $31
     nop
.end func_003055c0

.section .text.func_003055d0, "ax", @progbits
.globl func_003055d0
.type func_003055d0, @function
.ent func_003055d0
func_003055d0:
    addiu $3, $0, 59
    syscall
    jr $31
     nop
.end func_003055d0

.section .text.func_003055e0, "ax", @progbits
.globl func_003055e0
.type func_003055e0, @function
.ent func_003055e0
func_003055e0:
    addiu $3, $0, 60
    syscall
    jr $31
     nop
.end func_003055e0

.section .text.func_003055f0, "ax", @progbits
.globl func_003055f0
.type func_003055f0, @function
.ent func_003055f0
func_003055f0:
    addiu $3, $0, 61
    syscall
    jr $31
     nop
.end func_003055f0
