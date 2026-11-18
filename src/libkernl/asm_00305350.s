# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305350, "ax", @progbits
.globl RemoveDmacHandler
.type RemoveDmacHandler, @function
.globl func_00305350
.type func_00305350, @function
.ent func_00305350
func_00305350:
RemoveDmacHandler:
    addiu $3, $0, 19
    syscall
    jr $31
     nop
.end func_00305350

.section .text.func_00305360, "ax", @progbits
.globl _EnableIntc
.type _EnableIntc, @function
.globl func_00305360
.type func_00305360, @function
.ent func_00305360
func_00305360:
_EnableIntc:
    addiu $3, $0, 20
    syscall
    jr $31
     nop
.end func_00305360

.section .text.func_00305370, "ax", @progbits
.globl _DisableIntc
.type _DisableIntc, @function
.globl func_00305370
.type func_00305370, @function
.ent func_00305370
func_00305370:
_DisableIntc:
    addiu $3, $0, 21
    syscall
    jr $31
     nop
.end func_00305370

.section .text.func_00305380, "ax", @progbits
.globl _EnableDmac
.type _EnableDmac, @function
.globl func_00305380
.type func_00305380, @function
.ent func_00305380
func_00305380:
_EnableDmac:
    addiu $3, $0, 22
    syscall
    jr $31
     nop
.end func_00305380

.section .text.func_00305390, "ax", @progbits
.globl _DisableDmac
.type _DisableDmac, @function
.globl func_00305390
.type func_00305390, @function
.ent func_00305390
func_00305390:
_DisableDmac:
    addiu $3, $0, 23
    syscall
    jr $31
     nop
.end func_00305390
