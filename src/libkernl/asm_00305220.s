# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305220, "ax", @progbits
.globl SetGsCrt
.type SetGsCrt, @function
.globl func_00305220
.type func_00305220, @function
.ent func_00305220
func_00305220:
SetGsCrt:
    addiu $3, $0, 2
    syscall
    jr $31
     nop
.end func_00305220
