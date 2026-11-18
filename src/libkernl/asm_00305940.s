# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305940, "ax", @progbits
.globl GsGetIMR
.type GsGetIMR, @function
.globl func_00305940
.type func_00305940, @function
.ent func_00305940
func_00305940:
GsGetIMR:
    addiu $3, $0, 112
    syscall
    jr $31
     nop
.end func_00305940
