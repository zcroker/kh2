# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00308e30,"ax",@progbits
	.align 2
	.globl func_00308e30
	.type func_00308e30, @function
	.ent func_00308e30
func_00308e30:
	addiu	$29,$29,-64
	lui	$2,0x8000
	sd	$18,32($29)
	ori	$2,$2,0xa
	sd	$31,48($29)
	move	$18,$4
	sd	$17,16($29)
	sd	$16,0($29)
	lw	$3,32($18)
	beq	$3,$2,.L00308e7c
	sltu	$2,$2,$3
	bnez	$2,.L00308ec4
	lw	$17,28($18)
	lui	$2,0x8000
	ori	$2,$2,0x9
	beq	$3,$2,.L00308eb4
	nop
	b	.L00308ec8
	lw	$4,8($17)
.L00308e7c:
	lw	$17,28($18)
	lw	$2,28($17)
	beqzl	$2,.L00308ec8
	lw	$4,8($17)
	lw	$2,24($17)
	move	$16,$28
	move	$28,$2
	lw	$2,28($17)
	jalr	$2
	lw	$4,32($17)
	move	$3,$28
	move	$28,$16
	b	.L00308ec4
	lw	$17,28($18)
.L00308eb4:
	lw	$2,36($18)
	sw	$2,36($17)
	lw	$3,40($18)
	sw	$3,20($17)
.L00308ec4:
	lw	$4,8($17)
.L00308ec8:
	bltz	$4,.L00308ed8
	nop
	jal	0x305650
	nop
.L00308ed8:
	jal	0x308da0
	lw	$4,0($17)
	sw	$0,0($17)
	ld	$31,48($29)
	ld	$18,32($29)
	ld	$17,16($29)
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,64
	.end func_00308e30
	.size func_00308e30, 204
