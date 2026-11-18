.set noreorder
.text

.section .text.func_00311450, "ax", @progbits
.globl _SetTLBEntry
.type _SetTLBEntry, @function
.globl func_00311450
.type func_00311450, @function
.ent func_00311450
func_00311450:
_SetTLBEntry:
    addiu $3, $0, 86
    syscall
    jr $31
     nop
.end func_00311450

