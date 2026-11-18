# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003058f0, "ax", @progbits
.globl sceSifStopDma
.type sceSifStopDma, @function
.globl func_003058f0
.type func_003058f0, @function
.ent func_003058f0
func_003058f0:
sceSifStopDma:
    addiu $3, $0, 107
    syscall
    jr $31
     nop
.end func_003058f0
