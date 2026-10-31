# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/strlen.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002ff3fc,"ax",@progbits
	.align 2
	.globl func_002ff3fc
	.type func_002ff3fc, @function
	.ent func_002ff3fc
func_002ff3fc:
	andi	$2,$4,0x7
	bnez	$2,.L002ff510
	move	$7,$4
	andi	$3,$4,0xf
	lui	$2,0x101
	ori	$2,$2,0x101
	dsll	$2,$2,0x10
	ori	$2,$2,0x101
	dsll	$2,$2,0x10
	ori	$2,$2,0x101
	bnez	$3,.L002ff4a0
	move	$5,$4
	lq	$3,0($5)
	pcpyld	$8,$2,$2
	lui	$4,0x8080
	ori	$4,$4,0x8080
	dsll	$4,$4,0x10
	ori	$4,$4,0x8080
	dsll	$4,$4,0x10
	ori	$4,$4,0x8080
	psubb	$2,$3,$8
	pnor	$3,$0,$3
	pcpyld	$9,$4,$4
	pand	$2,$2,$3
	pand	$2,$2,$9
	pcpyud	$3,$2,$8
	or	$6,$3,$2
	bnezl	$6,.L002ff510
	move	$4,$5
	addiu	$5,$5,16
.L002ff474:
	lq	$2,0($5)
	pnor	$3,$0,$2
	psubb	$2,$2,$8
	pand	$2,$2,$3
	pand	$4,$2,$9
	pcpyud	$3,$4,$6
	or	$3,$3,$4
	beqzl	$3,.L002ff474
	addiu	$5,$5,16
	b	.L002ff510
	move	$4,$5
.L002ff4a0:
	ld	$3,0($5)
	lui	$4,0x8080
	ori	$4,$4,0x8080
	dsll	$4,$4,0x10
	ori	$4,$4,0x8080
	dsll	$4,$4,0x10
	ori	$4,$4,0x8080
	dsubu	$2,$3,$2
	nor	$3,$0,$3
	and	$2,$2,$3
	and	$2,$2,$4
	bnezl	$2,.L002ff510
	move	$4,$5
	lui	$6,0x101
	ori	$6,$6,0x101
	dsll	$6,$6,0x10
	ori	$6,$6,0x101
	dsll	$6,$6,0x10
	ori	$6,$6,0x101
	addiu	$5,$5,8
.L002ff4f0:
	ld	$2,0($5)
	nor	$3,$0,$2
	dsubu	$2,$2,$6
	and	$2,$2,$3
	and	$2,$2,$4
	beqzl	$2,.L002ff4f0
	addiu	$5,$5,8
	move	$4,$5
.L002ff510:
	lb	$2,0($4)
	nop
	nop
	nop
	nop
	bnezl	$2,.L002ff510
	addiu	$4,$4,1
	jr	$31
	subu	$2,$4,$7
	.end func_002ff3fc
	.size func_002ff3fc, 312
