# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_0030ef10, "ax", @progbits
.globl FindAddress
.type FindAddress, @function
.globl func_0030ef10
.type func_0030ef10, @function
.ent func_0030ef10
func_0030ef10:
FindAddress:
    addiu $3, $0, 131
    syscall
    jr $31
     nop
.end func_0030ef10
