# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305460, "ax", @progbits
.globl ExitDeleteThread
.type ExitDeleteThread, @function
.globl func_00305460
.type func_00305460, @function
.ent func_00305460
func_00305460:
ExitDeleteThread:
    addiu $3, $0, 36
    syscall
    jr $31
     nop
.end func_00305460
