# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_0030f240, "ax", @progbits
.globl Copy_0030f240
.type Copy_0030f240, @function
.globl func_0030f240
.type func_0030f240, @function
.ent func_0030f240
func_0030f240:
Copy_0030f240:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_0030f240
