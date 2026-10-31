# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/memcpy.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.section .text.func_002fdd68,"ax",@progbits
	.align 2
	.globl func_002fdd68
	.type func_002fdd68, @function
	.ent func_002fdd68
func_002fdd68:
	daddu	$8,$4,$0
	sltiu	$2,$6,32
	bnez	$2,.Lm7c
	daddu	$3,$8,$0
	or	$2,$5,$8
	andi	$2,$2,0xf
	bnezl	$2,.Lm80
	addiu	$6,$6,-1
	daddu	$7,$8,$0
.Lm24:
	lq	$3,0($5)
	addiu	$6,$6,-32
	addiu	$5,$5,16
	sltiu	$4,$6,32
	sq	$3,0($7)
	addiu	$7,$7,16
	lq	$2,0($5)
	addiu	$5,$5,16
	sq	$2,0($7)
	beqz	$4,.Lm24
	addiu	$7,$7,16
	sltiu	$2,$6,8
	bnez	$2,.Lm7c
	daddu	$3,$7,$0
.Lm5c:
	ld	$3,0($5)
	addiu	$6,$6,-8
	addiu	$5,$5,8
	sltiu	$2,$6,8
	sd	$3,0($7)
	beqz	$2,.Lm5c
	addiu	$7,$7,8
	daddu	$3,$7,$0
.Lm7c:
	addiu	$6,$6,-1
.Lm80:
	li	$2,-1
	beq	$6,$2,.Lma8
	daddu	$4,$2,$0
.Lm8c:
	lbu	$2,0($5)
	addiu	$6,$6,-1
	addiu	$5,$5,1
	sb	$2,0($3)
	addiu	$3,$3,1
	bne	$6,$4,.Lm8c
	nop
.Lma8:
	jr	$31
	daddu	$2,$8,$0
	.end func_002fdd68
	.size func_002fdd68, .-func_002fdd68
	.set reorder
	.set at
