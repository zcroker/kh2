# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305300, "ax", @progbits
.globl AddIntcHandler
.type AddIntcHandler, @function
.globl func_00305300
.type func_00305300, @function
.ent func_00305300
func_00305300:
AddIntcHandler:
    addiu $3, $0, 16
    syscall
    jr $31
     nop
.end func_00305300

.section .text.func_00305310, "ax", @progbits
.globl AddIntcHandler2
.type AddIntcHandler2, @function
.globl func_00305310
.type func_00305310, @function
.ent func_00305310
func_00305310:
AddIntcHandler2:
    addiu $3, $0, 16
    syscall
    jr $31
     nop
.end func_00305310

.section .text.func_00305320, "ax", @progbits
.globl RemoveIntcHandler
.type RemoveIntcHandler, @function
.globl func_00305320
.type func_00305320, @function
.ent func_00305320
func_00305320:
RemoveIntcHandler:
    addiu $3, $0, 17
    syscall
    jr $31
     nop
.end func_00305320

.section .text.func_00305330, "ax", @progbits
.globl AddDmacHandler
.type AddDmacHandler, @function
.globl func_00305330
.type func_00305330, @function
.ent func_00305330
func_00305330:
AddDmacHandler:
    addiu $3, $0, 18
    syscall
    jr $31
     nop
.end func_00305330
