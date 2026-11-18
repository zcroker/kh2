# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305590, "ax", @progbits
.globl SuspendThread
.type SuspendThread, @function
.globl func_00305590
.type func_00305590, @function
.ent func_00305590
func_00305590:
SuspendThread:
    addiu $3, $0, 55
    syscall
    jr $31
     nop
.end func_00305590

.section .text.func_003055a0, "ax", @progbits
.globl _iSuspendThread
.type _iSuspendThread, @function
.globl func_003055a0
.type func_003055a0, @function
.ent func_003055a0
func_003055a0:
_iSuspendThread:
    addiu $3, $0, -56
    syscall
    jr $31
     nop
.end func_003055a0
