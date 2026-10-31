# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f1c60,"ax",@progbits
	.align 2
	.globl func_002f1c60
	.type func_002f1c60, @function
	.ent func_002f1c60
func_002f1c60:
	addiu	$29,$29,-32
	sd	$16,16($29)
	move	$16,$4
	lw	$4,-7456($28)
	sd	$31,24($29)
	jal	0x305660
	nop
	lui	$4,0x1e3
	lui	$7,0x1e3
	lui	$11,0x2f
	move	$9,$16
	addiu	$4,$4,-9984
	addiu	$7,$7,-9920
	addiu	$11,$11,7680
	li	$5,1
	li	$6,1
	li	$8,32
	li	$10,32
	jal	0x3094b8
	sw	$0,0($29)
	ld	$16,16($29)
	ld	$31,24($29)
	jr	$31
	addiu	$29,$29,32
	.end func_002f1c60
	.size func_002f1c60, 96
