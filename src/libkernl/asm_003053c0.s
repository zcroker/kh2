# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003053c0, "ax", @progbits
.globl _iEnableIntc
.type _iEnableIntc, @function
.globl func_003053c0
.type func_003053c0, @function
.ent func_003053c0
func_003053c0:
_iEnableIntc:
    addiu $3, $0, -26
    syscall
    jr $31
     nop
.end func_003053c0

.section .text.func_003053d0, "ax", @progbits
.globl _iDisableIntc
.type _iDisableIntc, @function
.globl func_003053d0
.type func_003053d0, @function
.ent func_003053d0
func_003053d0:
_iDisableIntc:
    addiu $3, $0, -27
    syscall
    jr $31
     nop
.end func_003053d0

.section .text.func_003053e0, "ax", @progbits
.globl _iEnableDmac
.type _iEnableDmac, @function
.globl func_003053e0
.type func_003053e0, @function
.ent func_003053e0
func_003053e0:
_iEnableDmac:
    addiu $3, $0, -28
    syscall
    jr $31
     nop
.end func_003053e0

.section .text.func_003053f0, "ax", @progbits
.globl _iDisableDmac
.type _iDisableDmac, @function
.globl func_003053f0
.type func_003053f0, @function
.ent func_003053f0
func_003053f0:
_iDisableDmac:
    addiu $3, $0, -29
    syscall
    jr $31
     nop
.end func_003053f0
