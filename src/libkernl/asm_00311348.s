# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00311348, "ax", @progbits
.globl GetEntryAddress_00311348
.type GetEntryAddress_00311348, @function
.globl func_00311348
.type func_00311348, @function
.ent func_00311348
func_00311348:
GetEntryAddress_00311348:
    addiu $3, $0, 91
    syscall
    jr $31
     nop
.end func_00311348

.section .text.func_00311358, "ax", @progbits
.globl SetSyscall_00311358
.type SetSyscall_00311358, @function
.globl func_00311358
.type func_00311358, @function
.ent func_00311358
func_00311358:
SetSyscall_00311358:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_00311358
