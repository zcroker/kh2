# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305a80, "ax", @progbits
.globl GetMemorySize
.type GetMemorySize, @function
.globl func_00305a80
.type func_00305a80, @function
.ent func_00305a80
func_00305a80:
GetMemorySize:
    addiu $3, $0, 127
    syscall
    jr $31
     nop
.end func_00305a80

.section .text.func_00305a90, "ax", @progbits
.globl _InitTLB
.type _InitTLB, @function
.globl func_00305a90
.type func_00305a90, @function
.ent func_00305a90
func_00305a90:
_InitTLB:
    addiu $3, $0, 130
    syscall
    jr $31
     nop
.end func_00305a90
