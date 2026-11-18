# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00311300, "ax", @progbits
.globl Copy_00311300
.type Copy_00311300, @function
.globl func_00311300
.type func_00311300, @function
.ent func_00311300
func_00311300:
Copy_00311300:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_00311300
