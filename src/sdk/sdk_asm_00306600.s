# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00306600,"ax",@progbits
	.align 2
	.globl func_00306600
	.type func_00306600, @function
	.ent func_00306600
func_00306600:
	addiu	$29,$29,-32
	sd	$31,16($29)
	sd	$16,0($29)
	li	$3,-47
	syscall
	move	$16,$2
	beq	$16,$4,.L00306630
	sltiu	$2,$16,256
	jal	0x3055a0
	nop
	b	.L0030668c
	ld	$31,16($29)
.L00306630:
	beqz	$2,.L00306644
	lui	$2,0x36
	lw	$3,24784($2)
	bnez	$3,.L0030664c
	lui	$3,0x1e3
.L00306644:
	b	.L00306688
	li	$2,-1
.L0030664c:
	lui	$5,0x1e3
	addiu	$3,$3,20104
	lw	$4,20096($5)
	lw	$2,4($3)
	li	$7,2
	andi	$2,$2,0x1ff
	sll	$6,$2,0x1
	addiu	$2,$2,1
	addu	$5,$3,$6
	sw	$2,4($3)
	sb	$7,8($5)
	move	$3,$5
	jal	0x305650
	sb	$16,9($3)
	move	$2,$16
.L00306688:
	ld	$31,16($29)
.L0030668c:
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,32
	.end func_00306600
	.size func_00306600, 152
