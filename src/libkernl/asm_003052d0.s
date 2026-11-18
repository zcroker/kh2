# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003052d0, "ax", @progbits
.globl SetVTLBRefillHandler
.type SetVTLBRefillHandler, @function
.globl func_003052d0
.type func_003052d0, @function
.ent func_003052d0
func_003052d0:
SetVTLBRefillHandler:
    addiu $3, $0, 13
    syscall
    jr $31
     nop
.end func_003052d0
