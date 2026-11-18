# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305540, "ax", @progbits
.globl SleepThread
.type SleepThread, @function
.globl func_00305540
.type func_00305540, @function
.ent func_00305540
func_00305540:
SleepThread:
    addiu $3, $0, 50
    syscall
    jr $31
     nop
.end func_00305540

.section .text.func_00305550, "ax", @progbits
.globl WakeupThread
.type WakeupThread, @function
.globl func_00305550
.type func_00305550, @function
.ent func_00305550
func_00305550:
WakeupThread:
    addiu $3, $0, 51
    syscall
    jr $31
     nop
.end func_00305550

.section .text.func_00305560, "ax", @progbits
.globl _iWakeupThread
.type _iWakeupThread, @function
.globl func_00305560
.type func_00305560, @function
.ent func_00305560
func_00305560:
_iWakeupThread:
    addiu $3, $0, -52
    syscall
    jr $31
     nop
.end func_00305560
