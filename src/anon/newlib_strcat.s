# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/strcat.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text._ZN2Tz17LayFileSetImdDataEjj,"ax",@progbits
	.align 2
	.globl func_002feee8
	.type func_002feee8, @function
	.globl _ZN2Tz17LayFileSetImdDataEjj
	.type _ZN2Tz17LayFileSetImdDataEjj, @function
	.ent func_002feee8
func_002feee8:
_ZN2Tz17LayFileSetImdDataEjj:
	addiu	$29,$29,-32
	sq	$16,0($29)
	move	$16,$4
	andi	$2,$16,0x7
	bnez	$2,.L002fefdc
	sq	$31,16($29)
	andi	$2,$16,0xf
	lui	$3,0x101
	ori	$3,$3,0x101
	dsll	$3,$3,0x10
	ori	$3,$3,0x101
	dsll	$3,$3,0x10
	ori	$3,$3,0x101
	lui	$4,0x8080
	ori	$4,$4,0x8080
	dsll	$4,$4,0x10
	ori	$4,$4,0x8080
	dsll	$4,$4,0x10
	ori	$4,$4,0x8080
	bnez	$2,.L002fef98
	ld	$6,0($16)
	lq	$2,0($16)
	pcpyld	$7,$3,$3
	pcpyld	$8,$4,$4
	psubb	$3,$2,$7
	pnor	$2,$0,$2
	pand	$3,$3,$2
	pand	$3,$3,$8
	pcpyud	$2,$3,$3
	or	$3,$2,$3
	bnez	$3,.L002fefdc
	move	$4,$16
	addiu	$6,$4,16
.L002fef6c:
	lq	$2,0($6)
	pnor	$3,$0,$2
	psubb	$2,$2,$7
	pand	$2,$2,$3
	pand	$2,$2,$8
	pcpyud	$3,$2,$2
	or	$2,$2,$3
	beqzl	$2,.L002fef6c
	addiu	$6,$6,16
	b	.L002fefdc
	move	$4,$6
.L002fef98:
	move	$7,$3
	move	$8,$4
	dsubu	$3,$6,$3
	nor	$2,$0,$6
	and	$3,$3,$2
	and	$3,$3,$4
	bnez	$3,.L002fefdc
	move	$4,$16
	addiu	$6,$16,8
.L002fefbc:
	ld	$2,0($6)
	nor	$3,$0,$2
	dsubu	$2,$2,$7
	and	$2,$2,$3
	and	$2,$2,$8
	beqzl	$2,.L002fefbc
	addiu	$6,$6,8
	move	$4,$6
.L002fefdc:
	lb	$2,0($4)
	nop
	nop
	nop
	nop
	bnezl	$2,.L002fefdc
	addiu	$4,$4,1
	jal	0x2ff2e8
	nop
	move	$2,$16
	lq	$31,16($29)
	lq	$16,0($29)
	jr	$31
	addiu	$29,$29,32
	.end func_002feee8
	.size func_002feee8, 300
	.size _ZN2Tz17LayFileSetImdDataEjj, 300
