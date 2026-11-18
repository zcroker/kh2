# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003058a0, "ax", @progbits
.globl FlushCache
.type FlushCache, @function
.globl func_003058a0
.type func_003058a0, @function
.ent func_003058a0
func_003058a0:
FlushCache:
    addiu $3, $0, 100
    syscall
    jr $31
     nop
.end func_003058a0
