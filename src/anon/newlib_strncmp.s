# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/strncmp.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002ff538,"ax",@progbits
	.align 2
	.globl func_002ff538
	.type func_002ff538, @function
	.ent func_002ff538
func_002ff538:
	bnez	$6,.L002ff548
	or	$3,$4,$5
.L002ff540:
	jr	$31
	move	$2,$0
.L002ff548:
	andi	$2,$3,0x7
	bnez	$2,.L002ff6a4
	move	$2,$6
	andi	$2,$3,0xf
	sltiu	$7,$6,16
	lui	$9,0x101
	ori	$9,$9,0x101
	dsll	$9,$9,0x10
	ori	$9,$9,0x101
	dsll	$9,$9,0x10
	ori	$9,$9,0x101
	or	$2,$2,$7
	bnez	$2,.L002ff620
	move	$7,$4
	lq	$3,0($4)
	pcpyld	$10,$9,$9
	lq	$2,0($5)
	lui	$8,0x8080
	ori	$8,$8,0x8080
	dsll	$8,$8,0x10
	ori	$8,$8,0x8080
	dsll	$8,$8,0x10
	ori	$8,$8,0x8080
	psubw	$3,$3,$2
	pcpyld	$9,$8,$8
	pcpyud	$2,$3,$4
	move	$8,$5
	or	$3,$2,$3
	bnez	$3,.L002ff6a4
	move	$2,$6
	addiu	$6,$6,-16
.L002ff5c4:
	beqz	$6,.L002ff540
	nop
	lq	$2,0($7)
	pnor	$3,$0,$2
	psubb	$2,$2,$10
	pand	$2,$2,$3
	pand	$3,$2,$9
	pcpyud	$2,$3,$4
	or	$2,$2,$3
	bnez	$2,.L002ff540
	addiu	$7,$7,16
	sltiu	$2,$6,16
	lq	$3,0($7)
	bnez	$2,.L002ff698
	addiu	$8,$8,16
	lq	$2,0($8)
	psubw	$3,$3,$2
	pcpyud	$2,$3,$4
	or	$2,$2,$3
	beqzl	$2,.L002ff5c4
	addiu	$6,$6,-16
	b	.L002ff69c
	move	$4,$7
.L002ff620:
	sltiu	$2,$6,8
	bnez	$2,.L002ff698
	move	$8,$5
	ld	$3,0($4)
	ld	$2,0($5)
	bne	$3,$2,.L002ff6a4
	move	$2,$6
	addiu	$6,$6,-8
	lui	$10,0x8080
	ori	$10,$10,0x8080
	dsll	$10,$10,0x10
	ori	$10,$10,0x8080
	dsll	$10,$10,0x10
	ori	$10,$10,0x8080
.L002ff658:
	beqz	$6,.L002ff540
	nop
	ld	$2,0($7)
	nor	$3,$0,$2
	dsubu	$2,$2,$9
	and	$2,$2,$3
	and	$2,$2,$10
	bnez	$2,.L002ff540
	addiu	$7,$7,8
	sltiu	$2,$6,8
	bnez	$2,.L002ff698
	addiu	$8,$8,8
	ld	$3,0($7)
	ld	$2,0($8)
	beql	$3,$2,.L002ff658
	addiu	$6,$6,-8
.L002ff698:
	move	$4,$7
.L002ff69c:
	move	$5,$8
	move	$2,$6
.L002ff6a4:
	beqz	$2,.L002ff6e0
	addiu	$6,$6,-1
	b	.L002ff6d4
	lb	$3,0($4)
	nop
.L002ff6b8:
	beqz	$6,.L002ff540
	nop
	beqz	$7,.L002ff540
	addiu	$4,$4,1
	addiu	$5,$5,1
	lb	$3,0($4)
	addiu	$6,$6,-1
.L002ff6d4:
	lb	$2,0($5)
	beq	$3,$2,.L002ff6b8
	lbu	$7,0($4)
.L002ff6e0:
	lbu	$2,0($5)
	lbu	$3,0($4)
	jr	$31
	subu	$2,$3,$2
	.end func_002ff538
	.size func_002ff538, 440
