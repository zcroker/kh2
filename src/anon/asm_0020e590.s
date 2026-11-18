# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/0020e590_unit.c
#     No symbol, written as literal lui/lo values: 0x00370770
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0020e590,"ax",@progbits
	.align 3
	.globl func_0020e590
	.type func_0020e590, @function
	.ent func_0020e590
func_0020e590:
	addiu	$29,$29,-64
	move	$15,$4
	sd	$17,8($29)
	li	$4,3072
	sd	$19,24($29)
	sd	$16,0($29)
	andi	$17,$15,0xffff
	sd	$18,16($29)
	sd	$31,48($29)
	sd	$20,32($29)
	sd	$21,40($29)
	jal	func_0020eaf8
	move	$19,$5
	sll	$5,$17,0x10
	move	$16,$2
	sra	$5,$5,0x10
	move	$4,$2
	li	$6,1
	move	$7,$0
	move	$8,$0
	move	$9,$0
	li	$10,16
	jal	sceGsSetDefLoadImage
	li	$11,16
	addiu	$14,$16,2048
	lui	$15,0x8000
	lui	$12,0x3000
	addiu	$13,$16,256
	ori	$12,$12,0x5
	addu	$18,$14,$15
	sw	$12,0($13)
	addu	$15,$16,$15
	sw	$15,4($13)
	lui	$14,0x7fff
	lui	$15,0x37
	ori	$14,$14,0xffff
	lq	$13,1904($15)
	and	$14,$18,$14
	move	$11,$0
	addu	$15,$14,$11
.L0020e630:
	sq	$13,0($15)
	addiu	$11,$11,16
	slti	$15,$11,1024
	nop
	nop
	bnez	$15,.L0020e630
	addu	$15,$14,$11
	addiu	$13,$19,31
	slti	$14,$19,0
	movn	$19,$13,$14
	lui	$15,0x8000
	ori	$15,$15,0x100
	sra	$21,$19,0x5
	addu	$20,$16,$15
	move	$19,$0
.L0020e66c:
	slt	$15,$19,$21
	bnez	$15,.L0020e6a8
	move	$4,$0
	jal	sceGsSyncPath
	move	$5,$0
	ld	$16,0($29)
	li	$4,3072
	ld	$17,8($29)
	ld	$18,16($29)
	ld	$19,24($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$31,48($29)
	j	func_0020ebd8
	addiu	$29,$29,64
.L0020e6a8:
	jal	sceGsSyncPath
	move	$5,$0
	li	$9,1
	addiu	$13,$16,272
	dsll32	$9,$9,0x1d
	li	$10,0xeeee
	ori	$9,$9,0x1
	li	$11,7
.L0020e6c8:
	sq	$0,0($13)
	lui	$12,0x1000
	ori	$12,$12,0x4
	sw	$12,0($13)
	sd	$9,16($13)
	sd	$10,24($13)
	lq	$15,16($16)
	sq	$15,32($13)
	lq	$14,64($16)
	sq	$14,48($13)
	sh	$17,36($13)
	lq	$15,80($16)
	sq	$15,64($13)
	sq	$0,80($13)
	lui	$12,0x3000
	ori	$12,$12,0x40
	sw	$12,80($13)
	sw	$18,84($13)
	addiu	$15,$17,4
	addiu	$13,$13,96
	addiu	$11,$11,-1
	bgez	$11,.L0020e6c8
	andi	$17,$15,0xffff
	sq	$0,0($13)
	lui	$12,0x7000
	sw	$12,0($13)
	lui	$2,0x1000
	ori	$2,$2,0x8000
	li	$3,4
	li	$4,261
	sw	$0,8224($2)
	sw	$20,8240($2)
	sw	$4,8192($2)
	b	.L0020e66c
	addiu	$19,$19,1
	nop
	.end func_0020e590
	.size func_0020e590, 456
