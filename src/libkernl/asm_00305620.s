# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305620, "ax", @progbits
.globl CreateSema
.type CreateSema, @function
.globl func_00305620
.type func_00305620, @function
.ent func_00305620
func_00305620:
CreateSema:
    addiu $3, $0, 64
    syscall
    jr $31
     nop
.end func_00305620

.section .text.func_00305630, "ax", @progbits
.globl DeleteSema
.type DeleteSema, @function
.globl func_00305630
.type func_00305630, @function
.ent func_00305630
func_00305630:
DeleteSema:
    addiu $3, $0, 65
    syscall
    jr $31
     nop
.end func_00305630

.section .text.func_00305640, "ax", @progbits
.globl SignalSema
.type SignalSema, @function
.globl func_00305640
.type func_00305640, @function
.ent func_00305640
func_00305640:
SignalSema:
    addiu $3, $0, 66
    syscall
    jr $31
     nop
.end func_00305640

.section .text.func_00305650, "ax", @progbits
.globl iSignalSema
.type iSignalSema, @function
.globl func_00305650
.type func_00305650, @function
.ent func_00305650
func_00305650:
iSignalSema:
    addiu $3, $0, -67
    syscall
    jr $31
     nop
.end func_00305650

.section .text.func_00305660, "ax", @progbits
.globl WaitSema
.type WaitSema, @function
.globl func_00305660
.type func_00305660, @function
.ent func_00305660
func_00305660:
WaitSema:
    addiu $3, $0, 68
    syscall
    jr $31
     nop
.end func_00305660

.section .text.func_00305670, "ax", @progbits
.globl PollSema
.type PollSema, @function
.globl func_00305670
.type func_00305670, @function
.ent func_00305670
func_00305670:
PollSema:
    addiu $3, $0, 69
    syscall
    jr $31
     nop
.end func_00305670
