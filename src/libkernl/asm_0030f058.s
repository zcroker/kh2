# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_0030f058, "ax", @progbits
.globl SetSyscall
.type SetSyscall, @function
.globl func_0030f058
.type func_0030f058, @function
.ent func_0030f058
func_0030f058:
SetSyscall:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_0030f058
