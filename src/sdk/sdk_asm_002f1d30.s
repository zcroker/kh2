# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f1d30,"ax",@progbits
	.align 2
	.globl func_002f1d30
	.type func_002f1d30, @function
	.ent func_002f1d30
func_002f1d30:
	addiu	$29,$29,-48
	sd	$17,24($29)
	move	$17,$4
	lw	$4,-7456($28)
	sd	$16,16($29)
	sd	$31,32($29)
	jal	0x305660
	move	$16,$5
	lui	$3,0x1e3
	lui	$4,0x1e3
	addiu	$3,$3,-9920
	lui	$11,0x2f
	sw	$17,0($3)
	move	$9,$16
	addiu	$4,$4,-9984
	move	$7,$3
	addiu	$11,$11,7680
	li	$5,3
	li	$6,1
	li	$8,32
	li	$10,32
	jal	0x3094b8
	sw	$0,0($29)
	ld	$16,16($29)
	ld	$17,24($29)
	ld	$31,32($29)
	jr	$31
	addiu	$29,$29,48
	.end func_002f1d30
	.size func_002f1d30, 112
