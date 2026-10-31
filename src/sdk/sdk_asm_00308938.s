# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00308938,"ax",@progbits
	.align 2
	.globl func_00308938
	.type func_00308938, @function
	.ent func_00308938
func_00308938:
	addiu	$29,$29,-160
	lui	$3,0x1e3
	sd	$17,128($29)
	sd	$31,144($29)
	addiu	$17,$3,22488
	sd	$16,112($29)
	lw	$7,22488($3)
	lbu	$2,0($7)
	andi	$5,$2,0xff
	beqz	$5,.L00308a6c
	move	$2,$0
	addiu	$2,$5,15
	li	$3,-1
	addiu	$4,$5,30
	slt	$3,$3,$2
	movn	$4,$2,$3
	move	$6,$7
	sra	$5,$4,0x4
	sb	$0,0($7)
	blez	$5,.L003089ac
	move	$4,$5
	move	$3,$29
.L00308990:
	lq	$2,0($6)
	addiu	$4,$4,-1
	addiu	$6,$6,16
	sq	$2,0($3)
	addiu	$3,$3,16
	bnez	$4,.L00308990
	nop
.L003089ac:
	jal	0x305a10
	nop
	lw	$3,8($29)
	bgez	$3,.L00308a0c
	nop
	lw	$2,8($29)
	lui	$3,0x7fff
	ori	$3,$3,0xffff
	lw	$4,16($17)
	and	$5,$2,$3
	slt	$4,$5,$4
	beqz	$4,.L00308a60
	li	$2,12
	lw	$3,12($17)
	mult	$5,$5,$2
	addu	$2,$5,$3
	lw	$6,0($2)
	beqz	$6,.L00308a60
	nop
	lw	$3,8($2)
	move	$16,$28
	move	$28,$3
	b	.L00308a48
	lw	$2,12($17)
.L00308a0c:
	lw	$5,8($29)
	lw	$2,24($17)
	slt	$2,$5,$2
	beqz	$2,.L00308a60
	li	$2,12
	lw	$3,20($17)
	mult	$5,$5,$2
	addu	$2,$5,$3
	lw	$6,0($2)
	beqz	$6,.L00308a60
	nop
	lw	$3,8($2)
	move	$16,$28
	move	$28,$3
	lw	$2,20($17)
.L00308a48:
	move	$4,$29
	addu	$2,$5,$2
	jalr	$6
	lw	$5,4($2)
	move	$2,$28
	move	$28,$16
.L00308a60:
	sync
	ei
	move	$2,$0
.L00308a6c:
	ld	$31,144($29)
	ld	$17,128($29)
	ld	$16,112($29)
	jr	$31
	addiu	$29,$29,160
	.end func_00308938
	.size func_00308938, 328
