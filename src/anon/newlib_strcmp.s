# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/strcmp.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.section .text.func_002ff1a4,"ax",@progbits
	.align 2
	.globl func_002ff1a4
	.type func_002ff1a4, @function
	.ent func_002ff1a4
func_002ff1a4:
	or	$8,$4,$5
	andi	$2,$8,0x7
	bnezl	$2,.Ls130
	lb	$2,0($4)
	andi	$9,$8,0xf
	lui	$7,0x101
	ori	$7,$7,0x101
	dsll	$7,$7,0x10
	ori	$7,$7,0x101
	dsll	$7,$7,0x10
	ori	$7,$7,0x101
	lui	$6,0x8080
	ori	$6,$6,0x8080
	dsll	$6,$6,0x10
	ori	$6,$6,0x8080
	dsll	$6,$6,0x10
	ori	$6,$6,0x8080
	bnez	$9,.Lsc4
	ld	$2,0($5)
	lq	$3,0($4)
	pcpyld	$8,$7,$7
	lq	$2,0($5)
	pcpyld	$10,$6,$6
	psubw	$7,$2,$3
	pcpyud	$6,$7,$4
	or	$3,$6,$7
	bnezl	$3,.Ls130
	lb	$2,0($4)
	lq	$2,0($4)
	pnor	$3,$0,$2
.Ls78:
	psubb	$2,$2,$8
	pand	$2,$2,$3
	pand	$2,$2,$10
	pcpyud	$3,$2,$4
	or	$6,$3,$2
	beqz	$6,.Ls9c
	addiu	$4,$4,16
	jr	$31
	move	$2,$0
.Ls9c:
	addiu	$5,$5,16
	lq	$2,0($4)
	lq	$3,0($5)
	psubw	$7,$2,$3
	pcpyud	$6,$7,$4
	or	$9,$6,$7
	beqzl	$9,.Ls78
	pnor	$3,$0,$2
	b	.Ls130
	lb	$2,0($4)
.Lsc4:
	ld	$3,0($4)
	bnel	$3,$2,.Ls130
	lb	$2,0($4)
	ld	$2,0($4)
	nor	$8,$0,$2
.Lsd8:
	dsubu	$2,$2,$7
	and	$2,$2,$8
	and	$2,$2,$6
	beqz	$2,.Lsf4
	addiu	$4,$4,8
	jr	$31
	move	$2,$0
.Lsf4:
	addiu	$5,$5,8
	ld	$2,0($4)
	ld	$3,0($5)
	beql	$3,$2,.Lsd8
	nor	$8,$0,$2
	b	.Ls130
	lb	$2,0($4)
.Ls110:
	sll	$2,$3,0x18
	lb	$3,0($5)
	sra	$2,$2,0x18
	bnel	$2,$3,.Ls138
	lbu	$3,0($4)
	addiu	$4,$4,1
	addiu	$5,$5,1
	lb	$2,0($4)
.Ls130:
	bnez	$2,.Ls110
	lbu	$3,0($4)
.Ls138:
	lbu	$2,0($5)
	jr	$31
	subu	$2,$3,$2
	.end func_002ff1a4
	.set reorder
	.set at
