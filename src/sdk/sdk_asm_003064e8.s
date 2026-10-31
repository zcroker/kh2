# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_003064e8,"ax",@progbits
	.align 2
	.globl func_003064e8
	.type func_003064e8, @function
	.ent func_003064e8
func_003064e8:
	addiu	$29,$29,-32
	sd	$31,16($29)
	sd	$16,0($29)
	li	$3,-47
	syscall
	move	$16,$2
	beq	$16,$4,.L00306518
	sltiu	$2,$16,256
	jal	0x305560
	nop
	b	.L00306570
	ld	$31,16($29)
.L00306518:
	beqz	$2,.L0030652c
	lui	$2,0x36
	lw	$3,24784($2)
	bnez	$3,.L00306534
	lui	$3,0x1e3
.L0030652c:
	b	.L0030656c
	li	$2,-1
.L00306534:
	lui	$5,0x1e3
	addiu	$3,$3,20104
	lw	$4,20096($5)
	lw	$2,4($3)
	andi	$2,$2,0x1ff
	sll	$6,$2,0x1
	addiu	$2,$2,1
	addu	$5,$3,$6
	sw	$2,4($3)
	move	$3,$5
	sb	$0,8($5)
	jal	0x305650
	sb	$16,9($3)
	move	$2,$16
.L0030656c:
	ld	$31,16($29)
.L00306570:
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,32
	.end func_003064e8
	.size func_003064e8, 148
