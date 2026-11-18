# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305510, "ax", @progbits
.globl GetThreadId
.type GetThreadId, @function
.globl func_00305510
.type func_00305510, @function
.ent func_00305510
func_00305510:
GetThreadId:
    addiu $3, $0, 47
    syscall
    jr $31
     nop
.end func_00305510

.section .text.func_00305520, "ax", @progbits
.globl ReferThreadStatus
.type ReferThreadStatus, @function
.globl func_00305520
.type func_00305520, @function
.ent func_00305520
func_00305520:
ReferThreadStatus:
    addiu $3, $0, 48
    syscall
    jr $31
     nop
.end func_00305520
