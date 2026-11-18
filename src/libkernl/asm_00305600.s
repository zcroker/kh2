# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_00305600, "ax", @progbits
.globl EndOfHeap
.type EndOfHeap, @function
.globl func_00305600
.type func_00305600, @function
.ent func_00305600
func_00305600:
EndOfHeap:
    addiu $3, $0, 62
    syscall
    jr $31
     nop
.end func_00305600
