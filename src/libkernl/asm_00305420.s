# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305420, "ax", @progbits
.globl CreateThread
.type CreateThread, @function
.globl func_00305420
.type func_00305420, @function
.ent func_00305420
func_00305420:
CreateThread:
    addiu $3, $0, 32
    syscall
    jr $31
     nop
.end func_00305420
