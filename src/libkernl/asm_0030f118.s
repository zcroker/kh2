# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_0030f118, "ax", @progbits
.globl GetEntryAddress
.type GetEntryAddress, @function
.globl func_0030f118
.type func_0030f118, @function
.ent func_0030f118
func_0030f118:
GetEntryAddress:
    addiu $3, $0, 91
    syscall
    jr $31
     nop
.end func_0030f118
