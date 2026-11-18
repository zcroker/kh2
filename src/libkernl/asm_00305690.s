# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305690, "ax", @progbits
.globl ReferSemaStatus
.type ReferSemaStatus, @function
.globl func_00305690
.type func_00305690, @function
.ent func_00305690
func_00305690:
ReferSemaStatus:
    addiu $3, $0, 71
    syscall
    jr $31
     nop
.end func_00305690

.section .text.func_003056a0, "ax", @progbits
.globl iReferSemaStatus
.type iReferSemaStatus, @function
.globl func_003056a0
.type func_003056a0, @function
.ent func_003056a0
func_003056a0:
iReferSemaStatus:
    addiu $3, $0, -72
    syscall
    jr $31
     nop
.end func_003056a0
