# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/001cefb0_unit.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001cefb0,"ax",@progbits
	.align 3
	.globl func_001cefb0
	.type func_001cefb0, @function
	.ent func_001cefb0
func_001cefb0:
	addiu	$29,$29,-32
	li	$15,402
	sd	$16,0($29)
	sd	$31,8($29)
	swc1	$f20,16($29)
	lhu	$14,2($5)
	beq	$14,$15,.L001cf090
	move	$16,$4
	slti	$15,$14,403
	beqz	$15,.L001cf058
	li	$15,401
	beq	$14,$15,.L001cf000
	nop
.L001cefe4:
	jal	func_00178bf0
	move	$4,$16
	ld	$16,0($29)
	ld	$31,8($29)
	lwc1	$f20,16($29)
	jr	$31
	addiu	$29,$29,32
.L001cf000:
	jal	func_001cf0b0
	nop
	beqz	$2,.L001cf050
	addiu	$16,$16,320
	li	$5,181
	nop
.L001cf018:
	move	$4,$16
	mtc1	$0,$f12
.L001cf020:
	jal	func_0017f488
	mtc1	$0,$f13
	mtc1	$0,$f12
	move	$4,$16
	move	$5,$0
	move	$6,$0
	mov.s	$f13,$f12
	ld	$16,0($29)
	ld	$31,8($29)
	lwc1	$f20,16($29)
	j	func_0017f5e0
	addiu	$29,$29,32
.L001cf050:
	b	.L001cf018
	li	$5,184
.L001cf058:
	li	$15,403
	beq	$14,$15,.L001cf080
	li	$15,410
	bne	$14,$15,.L001cefe4
	mtc1	$0,$f20
	addiu	$16,$4,320
	li	$5,190
.L001cf074:
	mov.s	$f12,$f20
	b	.L001cf020
	move	$4,$16
.L001cf080:
	mtc1	$0,$f20
	addiu	$16,$4,320
	b	.L001cf074
	li	$5,189
.L001cf090:
	jal	func_001cf0b0
	nop
	beqz	$2,.L001cf0a8
	addiu	$16,$16,320
	b	.L001cf018
	li	$5,187
.L001cf0a8:
	b	.L001cf018
	li	$5,188
	.end func_001cefb0
	.size func_001cefb0, 256
