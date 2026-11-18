# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003054d0, "ax", @progbits
.globl RotateThreadReadyQueue
.type RotateThreadReadyQueue, @function
.globl func_003054d0
.type func_003054d0, @function
.ent func_003054d0
func_003054d0:
RotateThreadReadyQueue:
    addiu $3, $0, 43
    syscall
    jr $31
     nop
.end func_003054d0
