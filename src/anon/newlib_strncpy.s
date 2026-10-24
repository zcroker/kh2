# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/strncpy.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.section .text.func_002ff6f0,"ax",@progbits
	.align 2
	.globl func_002ff6f0
	.type func_002ff6f0, @function
	.ent func_002ff6f0
func_002ff6f0:
	move	$8,$4
	or	$7,$5,$4
	li	$10,16
	andi	$2,$7,0x7
	li	$9,8
	bnez	$2,.L002ff6f0_L9
	andi	$2,$7,0xf
	movz	$9,$10,$2
	bnez	$2,.L002ff6f0_L17
	sltu	$2,$6,$9
	bnez	$2,.L002ff6f0_L9
	nop
	lui	$7,0x101
	ori	$7,$7,0x101
	dsll	$7,$7,0x10
	ori	$7,$7,0x101
	dsll	$7,$7,0x10
	ori	$7,$7,0x101
	lq	$3,0($5)
	pcpyld	$9,$7,$7
	pnor	$3,$0,$3
	lui	$7,0x8080
	ori	$7,$7,0x8080
	dsll	$7,$7,0x10
	ori	$7,$7,0x8080
	dsll	$7,$7,0x10
	ori	$7,$7,0x8080
	psubb	$2,$3,$9
	pcpyld	$10,$7,$7
	pand	$2,$2,$3
	pand	$2,$2,$10
	pcpyud	$3,$2,$4
	or	$3,$2,$3
	bnez	$3,.L002ff6f0_L5
	move	$7,$8
	lq	$3,0($5)
	addiu	$6,$6,-16
	addiu	$5,$5,16
	sltiu	$2,$6,16
	sq	$3,0($7)
	bnez	$2,.L002ff6f0_L5
	addiu	$7,$7,16
	lq	$2,0($5)
	pnor	$3,$0,$2
	psubb	$2,$2,$9
	pand	$2,$2,$3
	pand	$2,$2,$10
	pcpyud	$3,$2,$4
	or	$2,$2,$3
	beqzl	$2,.L002ff6f0_L19
	lq	$3,0($5)
	b	.L002ff6f0_L9
	move	$4,$7
.L002ff6f0_L17:
	bnez	$2,.L002ff6f0_L9
	nop
	ld	$3,0($5)
	lui	$9,0x101
	ori	$9,$9,0x101
	dsll	$9,$9,0x10
	ori	$9,$9,0x101
	dsll	$9,$9,0x10
	ori	$9,$9,0x101
	lui	$10,0x8080
	ori	$10,$10,0x8080
	dsll	$10,$10,0x10
	ori	$10,$10,0x8080
	dsll	$10,$10,0x10
	ori	$10,$10,0x8080
	dsubu	$2,$3,$9
	nor	$3,$0,$3
	and	$2,$2,$3
	and	$2,$2,$10
	bnez	$2,.L002ff6f0_L5
	move	$7,$8
	ld	$3,0($5)
	nop
.L002ff6f0_L19:
	addiu	$6,$6,-8
	addiu	$5,$5,8
	sltiu	$2,$6,8
	sd	$3,0($7)
	bnez	$2,.L002ff6f0_L5
	addiu	$7,$7,8
	ld	$2,0($5)
	nor	$3,$0,$2
	dsubu	$2,$2,$9
	and	$2,$2,$3
	and	$2,$2,$10
	beqzl	$2,.L002ff6f0_L19
	ld	$3,0($5)
.L002ff6f0_L5:
	move	$4,$7
.L002ff6f0_L9:
	beqz	$6,.L002ff6f0_L18
	move	$2,$6
	lbu	$2,0($5)
	addiu	$6,$6,-1
	addiu	$5,$5,1
	sb	$2,0($4)
	sll	$2,$2,0x18
	bnez	$2,.L002ff6f0_L9
	addiu	$4,$4,1
	move	$2,$6
	beqz	$2,.L002ff6f0_L18
	addiu	$6,$6,-1
.L002ff6f0_L16:
	sb	$0,0($4)
	move	$2,$6
	addiu	$4,$4,1
	addiu	$6,$6,-1
	nop
	bnez	$2,.L002ff6f0_L16
	nop
.L002ff6f0_L18:
	jr	$31
	move	$2,$8
	nop
	.end func_002ff6f0
