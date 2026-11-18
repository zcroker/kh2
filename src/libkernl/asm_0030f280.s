# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_0030f280, "ax", @progbits
.globl SetSyscall_0030f280
.type SetSyscall_0030f280, @function
.globl func_0030f280
.type func_0030f280, @function
.ent func_0030f280
func_0030f280:
SetSyscall_0030f280:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_0030f280
