# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305990, "ax", @progbits
.globl SetVSyncFlag
.type SetVSyncFlag, @function
.globl func_00305990
.type func_00305990, @function
.ent func_00305990
func_00305990:
SetVSyncFlag:
    addiu $3, $0, 115
    syscall
    jr $31
     nop
.end func_00305990
