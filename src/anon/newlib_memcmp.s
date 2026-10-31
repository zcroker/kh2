# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/memcmp.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00316d68,"ax",@progbits
	.align 2
	.globl func_00316d68
	.type func_00316d68, @function
	.ent func_00316d68
func_00316d68:
	sltiu	$2,$6,16
	bnez	$2,.L00316db4
	or	$2,$4,$5
	andi	$2,$2,0xf
	bnez	$2,.L00316db4
	nop
.L00316d80:
	lq	$3,0($4)
	sltiu	$7,$6,32
	lq	$2,0($5)
	addiu	$4,$4,16
	pxor	$8,$2,$3
	addiu	$2,$5,16
	pcpyud	$10,$8,$7
	or	$9,$10,$8
	movz	$5,$2,$9
	bnezl	$9,.L00316db4
	addiu	$4,$4,-16
	beqz	$7,.L00316d80
	addiu	$6,$6,-16
.L00316db4:
	lui	$2,0xffff
	addiu	$6,$6,-1
	ori	$2,$2,0xffff
	beq	$6,$2,.L00316df4
	nop
	lui	$7,0xffff
	ori	$7,$7,0xffff
.L00316dd0:
	lbu	$3,0($4)
	lbu	$2,0($5)
	beq	$3,$2,.L00316de8
	addiu	$4,$4,1
	jr	$31
	subu	$2,$3,$2
.L00316de8:
	addiu	$6,$6,-1
	bne	$6,$7,.L00316dd0
	addiu	$5,$5,1
.L00316df4:
	jr	$31
	move	$2,$0
	.end func_00316d68
	.size func_00316d68, 148
