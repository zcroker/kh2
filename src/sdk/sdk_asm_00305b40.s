# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00305b40,"ax",@progbits
	.align 2
	.globl func_00305b40
	.type func_00305b40, @function
	.ent func_00305b40
func_00305b40:
	addiu	$29,$29,-32
	sd	$31,16($29)
	move	$4,$29
	sw	$0,0($29)
	jal	0x305990
	ori	$5,$29,0x8
	jal	0x30edb0
	nop
	lui	$3,0x1000
	li	$4,4
	ori	$3,$3,0xf000
	sw	$4,0($3)
	sync
	beqz	$2,.L00305b88
	lui	$3,0x1000
	jal	0x30ee00
	nop
	lui	$3,0x1000
.L00305b88:
	ori	$3,$3,0xf000
	nop
.L00305b90:
	lw	$2,0($3)
	andi	$2,$2,0x4
	bnez	$2,.L00305bac
	nop
	lw	$2,0($29)
	beqz	$2,.L00305b90
	nop
.L00305bac:
	jal	0x30edb0
	nop
	li	$3,4
	lui	$1,0x1001
	sw	$3,-4096($1)
	sync
	beqz	$2,.L00305bd4
	nop
	jal	0x30ee00
	nop
.L00305bd4:
	ld	$2,8($29)
	ld	$31,16($29)
	jr	$31
	addiu	$29,$29,32
	.end func_00305b40
	.size func_00305b40, 164
