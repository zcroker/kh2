# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f1da0,"ax",@progbits
	.align 2
	.globl func_002f1da0
	.type func_002f1da0, @function
	.ent func_002f1da0
func_002f1da0:
	addiu	$29,$29,-16
	beqz	$4,.L002f1dc0
	sd	$31,0($29)
	li	$2,1
	beq	$4,$2,.L002f1dd8
	li	$2,-1
	b	.L002f1df4
	ld	$31,0($29)
.L002f1dc0:
	jal	0x305660
	lw	$4,-7456($28)
	jal	0x305640
	lw	$4,-7456($28)
	b	.L002f1df0
	move	$2,$0
.L002f1dd8:
	lui	$4,0x1e3
	ld	$31,0($29)
	addiu	$4,$4,-9984
	j	0x3096b8
	addiu	$29,$29,16
	nop
.L002f1df0:
	ld	$31,0($29)
.L002f1df4:
	jr	$31
	addiu	$29,$29,16
	.end func_002f1da0
	.size func_002f1da0, 92
