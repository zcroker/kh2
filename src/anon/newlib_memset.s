# Third-party code notice: this file is newlib's hand-written R5900 assembly routine
# libc/machine/r5900/memset.S, which the game links from the toolchain's libc.a (the bytes are identical).
# It keeps newlib's own license and copyright (its original authors); it is not covered by this
# project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text._Z16wtarget_002fde18jjjj,"ax",@progbits
	.align 2
	.globl func_002fde18
	.type func_002fde18, @function
	.globl _Z16wtarget_002fde18jjjj
	.type _Z16wtarget_002fde18jjjj, @function
	.ent func_002fde18
func_002fde18:
_Z16wtarget_002fde18jjjj:
	sltiu	$2,$6,8
	bnez	$2,.L002fde98
	move	$3,$4
	andi	$2,$4,0xf
	bnez	$2,.L002fde98
	move	$7,$4
	andi	$9,$5,0xff
	sltiu	$10,$6,32
	move	$8,$9
	dsll	$3,$8,0x8
	or	$8,$3,$9
	pcpyh	$3,$8
	bnez	$10,.L002fde84
	sltiu	$2,$6,8
	pcpyld	$8,$3,$3
.L002fde54:
	sq	$8,0($7)
	addiu	$6,$6,-32
	addiu	$7,$7,16
	sltiu	$2,$6,32
	sq	$8,0($7)
	beqz	$2,.L002fde54
	addiu	$7,$7,16
	b	.L002fde84
	sltiu	$2,$6,8
.L002fde78:
	addiu	$6,$6,-8
	addiu	$7,$7,8
	sltiu	$2,$6,8
.L002fde84:
	nop
	nop
	beqzl	$2,.L002fde78
	sd	$3,0($7)
	move	$3,$7
.L002fde98:
	lui	$2,0xffff
	addiu	$6,$6,-1
	ori	$2,$2,0xffff
	beq	$6,$2,.L002fded0
	nop
	lui	$2,0xffff
	ori	$2,$2,0xffff
.L002fdeb4:
	sb	$5,0($3)
	addiu	$6,$6,-1
	addiu	$3,$3,1
	nop
	nop
	bne	$6,$2,.L002fdeb4
	nop
.L002fded0:
	jr	$31
	move	$2,$4
	.end func_002fde18
	.size func_002fde18, 192
	.size _Z16wtarget_002fde18jjjj, 192
