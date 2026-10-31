# Third-party code notice: this file is newlib's memmove (libc/string/memmove.c) as the game links it from the
# toolchain's libc.a. That object was built by a different compiler than the game, so it is kept as assembly.
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00303a68,"ax",@progbits
	.align 2
	.globl func_00303a68
	.type func_00303a68, @function
	.ent func_00303a68
func_00303a68:
	move	$8,$4
	sltu	$2,$5,$8
	beqz	$2,.L00303ac0
	move	$3,$8
	addu	$7,$5,$6
	sltu	$2,$8,$7
	beqz	$2,.L00303ac0
	li	$2,-1
	addu	$3,$8,$6
	addiu	$6,$6,-1
	beq	$6,$2,.L00303b64
	move	$5,$7
	move	$4,$2
.L00303a9c:
	addiu	$5,$5,-1
	addiu	$3,$3,-1
	lbu	$2,0($5)
	addiu	$6,$6,-1
	sb	$2,0($3)
	bne	$6,$4,.L00303a9c
	nop
	jr	$31
	move	$2,$8
.L00303ac0:
	sltiu	$2,$6,32
	bnezl	$2,.L00303b3c
	addiu	$6,$6,-1
	or	$2,$5,$3
	andi	$2,$2,0xf
	bnezl	$2,.L00303b3c
	addiu	$6,$6,-1
	move	$7,$3
.L00303ae0:
	lq	$3,0($5)
	addiu	$6,$6,-32
	addiu	$5,$5,16
	sltiu	$4,$6,32
	sq	$3,0($7)
	addiu	$7,$7,16
	lq	$2,0($5)
	addiu	$5,$5,16
	sq	$2,0($7)
	beqz	$4,.L00303ae0
	addiu	$7,$7,16
	sltiu	$2,$6,8
	bnez	$2,.L00303b38
	move	$3,$7
.L00303b18:
	ld	$3,0($5)
	addiu	$6,$6,-8
	addiu	$5,$5,8
	sltiu	$2,$6,8
	sd	$3,0($7)
	beqz	$2,.L00303b18
	addiu	$7,$7,8
	move	$3,$7
.L00303b38:
	addiu	$6,$6,-1
.L00303b3c:
	li	$2,-1
	beq	$6,$2,.L00303b64
	move	$4,$2
.L00303b48:
	lbu	$2,0($5)
	addiu	$6,$6,-1
	addiu	$5,$5,1
	sb	$2,0($3)
	addiu	$3,$3,1
	bne	$6,$4,.L00303b48
	nop
.L00303b64:
	jr	$31
	move	$2,$8
	.end func_00303a68
	.size func_00303a68, 260
