# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/001d0a88_unit.cpp, ledger best/001d0a88_unit_sp.cpp
#   001d0a88 (L60, 2026-11-18): near-miss 2 gap fn; local f32 sp = 8.0f for the push(6) call fixes that call (a0 first, move a2 in the delay slot), but push(53) before it then puts li a1 before move a0; mo locals, z locals, chk forms, QV forms no gain; permuter 
#     No symbol, written as literal lui/lo values: 0x0036e388, 0x0036e38c
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001d0a88,"ax",@progbits
	.align 3
	.globl func_001d0a88
	.type func_001d0a88, @function
	.ent func_001d0a88
func_001d0a88:
	addiu	$29,$29,-64
	sd	$17,40($29)
	sd	$16,32($29)
	sd	$31,48($29)
	swc1	$f20,56($29)
	jal	func_001780d8
	move	$17,$4
	lw	$13,2924($17)
	beqz	$13,.L001d0c24
	li	$15,3
	beq	$13,$15,.L001d0c14
	nop
	lw	$15,2896($17)
	bnez	$15,.L001d0b60
	mtc1	$0,$f20
	lw	$15,264($17)
	lui	$14,0x10
	or	$15,$15,$14
	li	$14,1
	bne	$13,$14,.L001d0b50
	sw	$15,264($17)
	mtc1	$0,$f20
	addiu	$16,$17,320
	move	$4,$16
	move	$5,$0
	mov.s	$f12,$f20
	jal	func_0017f488
	mov.s	$f13,$f20
	mov.s	$f12,$f20
	move	$4,$16
	move	$5,$0
.L001d0b04:
	mov.s	$f13,$f12
	jal	func_0017f488
	li	$16,15
	move	$5,$16
.L001d0b14:
	move	$4,$17
	li	$6,1
	move	$7,$0
	move	$8,$0
	jal	func_0016ac38
	addiu	$16,$16,1
	slti	$15,$16,28
	bnez	$15,.L001d0b14
	move	$5,$16
.L001d0b38:
	ld	$16,32($29)
.L001d0b3c:
	ld	$17,40($29)
	ld	$31,48($29)
	lwc1	$f20,56($29)
	jr	$31
	addiu	$29,$29,64
.L001d0b50:
	mtc1	$0,$f12
	addiu	$4,$17,320
	b	.L001d0b04
	li	$5,4
.L001d0b60:
	addiu	$16,$17,320
	move	$4,$16
	li	$5,53
	mov.s	$f12,$f20
	jal	func_0017f488
	mov.s	$f13,$f20
	lw	$14,2924($17)
	li	$15,1
	bne	$14,$15,.L001d0bc8
	lui	$15,0x37
	mov.s	$f13,$f20
	addiu	$15,$15,-7288
	move	$4,$16
	lwc1	$f12,0($15)
	li	$5,6
	jal	func_0017f5e0
	move	$6,$0
	mov.s	$f12,$f20
	move	$4,$16
	mov.s	$f13,$f20
	move	$5,$0
	move	$6,$0
.L001d0bb8:
	jal	func_0017f5e0
	nop
	b	.L001d0b3c
	ld	$16,32($29)
.L001d0bc8:
	vsub.wxyz	$vf1,$vf0,$vf0
	sqc2	$vf1,0($29)
	addiu	$5,$29,16
	lq	$8,0($29)
	sq	$8,0($5)
	lui	$15,0x37
	move	$4,$17
	addiu	$15,$15,-7284
	jal	func_0019fdc0
	lwc1	$f12,0($15)
	lui	$15,0x37
	mov.s	$f13,$f20
	addiu	$15,$15,-7288
	lui	$6,%hi(func_001d0cb8)
	lwc1	$f12,0($15)
	move	$4,$16
	addiu	$6,$6,%lo(func_001d0cb8)
	b	.L001d0bb8
	li	$5,4
.L001d0c14:
	jal	func_00187818
	move	$4,$17
	b	.L001d0b3c
	ld	$16,32($29)
.L001d0c24:
	lw	$15,2896($17)
	xori	$14,$15,0x0
	slti	$15,$15,7
	movz	$15,$0,$14
	andi	$15,$15,0xff
	beqz	$15,.L001d0b38
	mtc1	$0,$f20
	addiu	$16,$17,320
	move	$4,$16
	li	$5,53
	mov.s	$f12,$f20
	jal	func_0017f488
	mov.s	$f13,$f20
	mov.s	$f13,$f20
	lui	$15,0x37
	addiu	$15,$15,-7288
	move	$4,$16
	lwc1	$f12,0($15)
	li	$5,6
	jal	func_0017f5e0
	move	$6,$0
	mov.s	$f12,$f20
	move	$4,$16
	mov.s	$f13,$f20
	move	$5,$0
	jal	func_0017f5e0
	move	$6,$0
	lw	$14,1164($17)
	li	$15,2
	lui	$4,0x35
	move	$5,$0
	sb	$15,431($14)
	jal	func_001c8d80
	addiu	$4,$4,7864
	b	.L001d0b3c
	ld	$16,32($29)
	nop
	.end func_001d0a88
	.size func_001d0a88, 560
