# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_002f20c0, "ax", @progbits
.globl _GetGsDxDyOffset
.type _GetGsDxDyOffset, @function
.globl func_002f20c0
.type func_002f20c0, @function
.ent func_002f20c0
func_002f20c0:
_GetGsDxDyOffset:
    addiu $3, $0, 128
    syscall
    jr $31
     nop
.end func_002f20c0
