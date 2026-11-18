# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003058d0, "ax", @progbits
.globl iFlushCache
.type iFlushCache, @function
.globl func_003058d0
.type func_003058d0, @function
.ent func_003058d0
func_003058d0:
iFlushCache:
    addiu $3, $0, -104
    syscall
    jr $31
     nop
.end func_003058d0
