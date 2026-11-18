# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003056c0, "ax", @progbits
.globl SetOsdConfigParam
.type SetOsdConfigParam, @function
.globl func_003056c0
.type func_003056c0, @function
.ent func_003056c0
func_003056c0:
SetOsdConfigParam:
    addiu $3, $0, 74
    syscall
    jr $31
     nop
.end func_003056c0

.section .text.func_003056d0, "ax", @progbits
.globl GetOsdConfigParam
.type GetOsdConfigParam, @function
.globl func_003056d0
.type func_003056d0, @function
.ent func_003056d0
func_003056d0:
GetOsdConfigParam:
    addiu $3, $0, 75
    syscall
    jr $31
     nop
.end func_003056d0
