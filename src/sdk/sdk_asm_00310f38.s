# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00310f38,"ax",@progbits
	.align 2
	.globl func_00310f38
	.type func_00310f38, @function
	.ent func_00310f38
func_00310f38:
	addiu	$29,$29,-80
	sd	$19,48($29)
	sd	$31,64($29)
	move	$19,$5
	sd	$18,32($29)
	sd	$17,16($29)
	beqz	$4,.L00310f68
	sd	$16,0($29)
	lui	$2,0x1e4
	li	$3,32
	b	.L00310f78
	addiu	$2,$2,-19704
.L00310f68:
	lui	$2,0x36
	lui	$3,0x36
	lw	$2,28984($2)
	lw	$3,28988($3)
.L00310f78:
	move	$18,$28
	blez	$3,.L00310fbc
	move	$16,$2
	move	$17,$3
.L00310f88:
	lw	$2,0($16)
	beqzl	$2,.L00310fb4
	addiu	$17,$17,-1
	lw	$2,8($16)
	move	$3,$28
	move	$28,$2
	lw	$6,0($16)
	move	$4,$19
	jalr	$6
	lw	$5,4($16)
	addiu	$17,$17,-1
.L00310fb4:
	bnez	$17,.L00310f88
	addiu	$16,$16,16
.L00310fbc:
	move	$2,$28
	move	$28,$18
	ld	$31,64($29)
	ld	$19,48($29)
	ld	$18,32($29)
	ld	$17,16($29)
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,80
	.end func_00310f38
	.size func_00310f38, 168
