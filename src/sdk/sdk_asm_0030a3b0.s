# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0030a3b0,"ax",@progbits
	.align 2
	.globl func_0030a3b0
	.type func_0030a3b0, @function
	.ent func_0030a3b0
func_0030a3b0:
	addiu	$29,$29,-32
	lw	$3,0($5)
	sd	$31,16($29)
	beqz	$3,.L0030a3dc
	sd	$16,0($29)
	lui	$2,0x1e4
	move	$16,$28
	lw	$28,-30144($2)
	jalr	$3
	lw	$4,4($5)
	move	$28,$16
.L0030a3dc:
	sync
	ei
	ld	$31,16($29)
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,32
	.end func_0030a3b0
	.size func_0030a3b0, 68
