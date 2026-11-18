# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003054b0, "ax", @progbits
.globl ChangeThreadPriority
.type ChangeThreadPriority, @function
.globl func_003054b0
.type func_003054b0, @function
.ent func_003054b0
func_003054b0:
ChangeThreadPriority:
    addiu $3, $0, 41
    syscall
    jr $31
     nop
.end func_003054b0
