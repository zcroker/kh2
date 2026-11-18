# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305960, "ax", @progbits
.globl GsPutIMR
.type GsPutIMR, @function
.globl func_00305960
.type func_00305960, @function
.ent func_00305960
func_00305960:
GsPutIMR:
    addiu $3, $0, 113
    syscall
    jr $31
     nop
.end func_00305960
