# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305260, "ax", @progbits
.globl _LoadExecPS2
.type _LoadExecPS2, @function
.globl func_00305260
.type func_00305260, @function
.ent func_00305260
func_00305260:
_LoadExecPS2:
    addiu $3, $0, 6
    syscall
    jr $31
     nop
.end func_00305260
