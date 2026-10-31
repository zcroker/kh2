# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/strcpy.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text._ZN2Tz16LayFileBuildDataEPvj,"ax",@progbits
	.align 2
	.globl func_002ff2e8
	.type func_002ff2e8, @function
	.globl _ZN2Tz16LayFileBuildDataEPvj
	.type _ZN2Tz16LayFileBuildDataEPvj, @function
	.ent func_002ff2e8
func_002ff2e8:
_ZN2Tz16LayFileBuildDataEPvj:
	move	$7,$4
	or	$8,$5,$7
	andi	$2,$8,0x7
	bnez	$2,.L002ff3d8
	move	$3,$7
	andi	$2,$8,0xf
	lui	$9,0x101
	ori	$9,$9,0x101
	dsll	$9,$9,0x10
	ori	$9,$9,0x101
	dsll	$9,$9,0x10
	ori	$9,$9,0x101
	lui	$4,0x8080
	ori	$4,$4,0x8080
	dsll	$4,$4,0x10
	ori	$4,$4,0x8080
	dsll	$4,$4,0x10
	ori	$4,$4,0x8080
	bnezl	$2,.L002ff398
	ld	$10,0($5)
	pcpyld	$10,$9,$9
	lq	$9,0($5)
	pcpyld	$8,$4,$4
	psubb	$2,$9,$10
	pnor	$3,$0,$9
	pand	$2,$2,$3
	pand	$2,$2,$8
	pcpyud	$4,$2,$9
	or	$3,$2,$4
	bnez	$3,.L002ff3d4
	move	$6,$7
.L002ff364:
	sq	$9,0($6)
	addiu	$5,$5,16
	lq	$9,0($5)
	psubb	$2,$9,$10
	pnor	$3,$0,$9
	pand	$2,$2,$3
	pand	$2,$2,$8
	pcpyud	$4,$2,$9
	or	$3,$2,$4
	beqz	$3,.L002ff364
	addiu	$6,$6,16
	b	.L002ff3d8
	move	$3,$6
.L002ff398:
	dsubu	$2,$10,$9
	nor	$3,$0,$10
	and	$2,$2,$3
	and	$2,$2,$4
	bnez	$2,.L002ff3d4
	move	$6,$7
.L002ff3b0:
	sd	$10,0($6)
	addiu	$5,$5,8
	ld	$10,0($5)
	nor	$2,$0,$10
	dsubu	$3,$10,$9
	and	$3,$3,$2
	and	$3,$3,$4
	beqz	$3,.L002ff3b0
	addiu	$6,$6,8
.L002ff3d4:
	move	$3,$6
.L002ff3d8:
	lbu	$2,0($5)
	addiu	$5,$5,1
	sb	$2,0($3)
	sll	$2,$2,0x18
	addiu	$3,$3,1
	bnez	$2,.L002ff3d8
	nop
	jr	$31
	move	$2,$7
	.end func_002ff2e8
	.size func_002ff2e8, 276
	.size _ZN2Tz16LayFileBuildDataEPvj, 276
