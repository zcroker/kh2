# Split out of syscall_wrappers.s on 2026-11-18 to link it as its own unit.
.set noreorder
.text

.section .text.func_0030ee88, "ax", @progbits
.globl Copy
.type Copy, @function
.globl func_0030ee88
.type func_0030ee88, @function
.ent func_0030ee88
func_0030ee88:
Copy:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_0030ee88
