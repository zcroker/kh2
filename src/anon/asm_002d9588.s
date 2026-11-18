# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002d9588_perm780.c, ledger best/002d9588_unit.c
#   002d9588 (L47, 2026-11-18): near-miss 18 permuter 40 min, best 780; best/002d9588_perm780.c
#     No symbol, written as literal lui/lo values: 0x00375cc0, 0x00375cd0
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002d9588,"ax",@progbits
	.align 3
	.globl func_002d9588
	.type func_002d9588, @function
	.ent func_002d9588
func_002d9588:
	addiu	$29,$29,-80
	lui	$12,0x37
	sd	$19,56($29)
	addiu	$9,$12,23744
	sd	$31,72($29)
	sll	$19,$6,0x2
	sd	$16,32($29)
	addu	$14,$19,$4
	sd	$17,40($29)
	sd	$18,48($29)
	addiu	$8,$14,128
	sd	$20,64($29)
	addiu	$14,$14,112
	move	$18,$4
	lw	$13,8($14)
	move	$20,$5
	lw	$15,4($8)
	move	$4,$0
	lw	$11,23744($12)
	addiu	$13,$13,1
	addiu	$15,$15,1
	sw	$13,8($14)
	sw	$15,4($8)
	lw	$10,8($9)
	lw	$12,4($9)
	sw	$11,0($29)
	sw	$12,4($29)
	jal	func_002cf308
	sw	$10,8($29)
	move	$16,$2
	jal	func_002cf308
	li	$4,1
	move	$17,$2
	jal	func_002cf308
	li	$4,2
	addu	$16,$16,$17
	lw	$15,132($18)
	addu	$16,$16,$2
	lw	$13,136($18)
	lw	$14,140($18)
	addu	$15,$15,$13
	addu	$15,$15,$14
	bnel	$16,$15,.L002d9694
	lw	$14,152($18)
	lw	$15,168($18)
	lui	$14,0x37
	addiu	$16,$29,16
	addiu	$13,$14,23760
	ldl	$10,7($13)
	ldr	$10,0($13)
	sdl	$10,23($29)
	sdr	$10,16($29)
	addu	$15,$16,$15
	lbu	$14,0($15)
	beqzl	$14,.L002d9694
	lw	$14,152($18)
	jal	func_0016b740
	li	$4,1630
	lw	$15,168($18)
	move	$4,$2
	lw	$13,0($2)
	li	$6,4
	addu	$15,$16,$15
	lw	$14,84($13)
	jalr	$14
	lbu	$5,0($15)
	lw	$14,152($18)
.L002d9694:
	li	$15,2
	bne	$14,$15,.L002d96b8
	ld	$16,32($29)
	addu	$15,$19,$29
	move	$5,$0
	lw	$4,0($15)
	jal	func_001d86a0
	mult	$4,$4,$20
	ld	$16,32($29)
.L002d96b8:
	ld	$17,40($29)
	ld	$18,48($29)
	ld	$19,56($29)
	ld	$20,64($29)
	ld	$31,72($29)
	jr	$31
	addiu	$29,$29,80
	nop
	.end func_002d9588
	.size func_002d9588, 336
