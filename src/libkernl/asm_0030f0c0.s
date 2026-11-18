# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_0030f0c0, "ax", @progbits
.globl SetSyscall_0030f0c0
.type SetSyscall_0030f0c0, @function
.globl func_0030f0c0
.type func_0030f0c0, @function
.ent func_0030f0c0
func_0030f0c0:
SetSyscall_0030f0c0:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_0030f0c0

.section .text.func_0030f0d0, "ax", @progbits
.globl Copy_0030f0d0
.type Copy_0030f0d0, @function
.globl func_0030f0d0
.type func_0030f0d0, @function
.ent func_0030f0d0
func_0030f0d0:
Copy_0030f0d0:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_0030f0d0
