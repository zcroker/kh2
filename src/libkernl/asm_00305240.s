# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305240, "ax", @progbits
.globl _Exit
.type _Exit, @function
.globl func_00305240
.type func_00305240, @function
.ent func_00305240
func_00305240:
_Exit:
    addiu $3, $0, 4
    syscall
    jr $31
     nop
.end func_00305240
