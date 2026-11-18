# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305440, "ax", @progbits
.globl _StartThread
.type _StartThread, @function
.globl func_00305440
.type func_00305440, @function
.ent func_00305440
func_00305440:
_StartThread:
    addiu $3, $0, 34
    syscall
    jr $31
     nop
.end func_00305440
