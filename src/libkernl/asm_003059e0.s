# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_003059e0, "ax", @progbits
.globl sceSifSetDma
.type sceSifSetDma, @function
.globl func_003059e0
.type func_003059e0, @function
.ent func_003059e0
func_003059e0:
sceSifSetDma:
    addiu $3, $0, 119
    syscall
    jr $31
     nop
.end func_003059e0

.section .text.func_003059f0, "ax", @progbits
.globl isceSifSetDma
.type isceSifSetDma, @function
.globl func_003059f0
.type func_003059f0, @function
.ent func_003059f0
func_003059f0:
isceSifSetDma:
    addiu $3, $0, -119
    syscall
    jr $31
     nop
.end func_003059f0

.section .text.func_00305a00, "ax", @progbits
.globl sceSifSetDChain
.type sceSifSetDChain, @function
.globl func_00305a00
.type func_00305a00, @function
.ent func_00305a00
func_00305a00:
sceSifSetDChain:
    addiu $3, $0, 120
    syscall
    jr $31
     nop
.end func_00305a00

.section .text.func_00305a10, "ax", @progbits
.globl isceSifSetDChain
.type isceSifSetDChain, @function
.globl func_00305a10
.type func_00305a10, @function
.ent func_00305a10
func_00305a10:
isceSifSetDChain:
    addiu $3, $0, -120
    syscall
    jr $31
     nop
.end func_00305a10

.section .text.func_00305a20, "ax", @progbits
.globl sceSifSetReg
.type sceSifSetReg, @function
.globl func_00305a20
.type func_00305a20, @function
.ent func_00305a20
func_00305a20:
sceSifSetReg:
    addiu $3, $0, 121
    syscall
    jr $31
     nop
.end func_00305a20

.section .text.func_00305a30, "ax", @progbits
.globl sceSifGetReg
.type sceSifGetReg, @function
.globl func_00305a30
.type func_00305a30, @function
.ent func_00305a30
func_00305a30:
sceSifGetReg:
    addiu $3, $0, 122
    syscall
    jr $31
     nop
.end func_00305a30

.section .text.func_00305a40, "ax", @progbits
.globl _ExecOSD
.type _ExecOSD, @function
.globl func_00305a40
.type func_00305a40, @function
.ent func_00305a40
func_00305a40:
_ExecOSD:
    addiu $3, $0, 123
    syscall
    jr $31
     nop
.end func_00305a40

.section .text.func_00305a50, "ax", @progbits
.globl Deci2Call
.type Deci2Call, @function
.globl func_00305a50
.type func_00305a50, @function
.ent func_00305a50
func_00305a50:
Deci2Call:
    addiu $3, $0, 124
    syscall
    jr $31
     nop
.end func_00305a50
