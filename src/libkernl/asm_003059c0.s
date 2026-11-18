# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003059c0, "ax", @progbits
.globl sceSifDmaStat
.type sceSifDmaStat, @function
.globl func_003059c0
.type func_003059c0, @function
.ent func_003059c0
func_003059c0:
sceSifDmaStat:
    addiu $3, $0, 118
    syscall
    jr $31
     nop
.end func_003059c0
