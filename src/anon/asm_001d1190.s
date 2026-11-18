# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/001d1190_g8.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001d1190,"ax",@progbits
	.align 3
	.globl func_001d1190
	.type func_001d1190, @function
	.ent func_001d1190
func_001d1190:
	addiu	$29,$29,-32
	move	$2,$5
	sd	$17,8($29)
	li	$15,73
	sd	$16,0($29)
	sd	$31,16($29)
	lhu	$14,2($5)
	beq	$14,$15,.L001d12c8
	move	$17,$4
	slti	$15,$14,74
	beqz	$15,.L001d1274
	li	$15,5
	beq	$14,$15,.L001d125c
	slti	$15,$14,6
	beqz	$15,.L001d123c
	li	$15,4
	beq	$14,$15,.L001d11f8
	nop
	move	$4,$17
.L001d11dc:
	jal	func_00178ae8
	move	$5,$2
.L001d11e4:
	ld	$16,0($29)
	ld	$17,8($29)
	ld	$31,16($29)
	jr	$31
	addiu	$29,$29,32
.L001d11f8:
	jal	func_001d61b8
	lh	$5,4($5)
	move	$16,$2
	jal	func_001b90c8
	move	$4,$2
	lbu	$5,28($2)
	jal	func_001a1b30
	lw	$4,1164($17)
	jal	func_001d97f0
	move	$4,$16
	move	$4,$17
	ld	$31,16($29)
	move	$5,$16
	ld	$17,8($29)
	ld	$16,0($29)
	j	func_001b6b10
	addiu	$29,$29,32
.L001d123c:
	li	$15,72
	bnel	$14,$15,.L001d11dc
	move	$4,$17
	ld	$16,0($29)
	ld	$17,8($29)
	ld	$31,16($29)
	j	func_001d1380
	addiu	$29,$29,32
.L001d125c:
	jal	func_001b6b10
	move	$5,$0
	lw	$15,264($17)
	ori	$15,$15,0x100
	b	.L001d11e4
	sw	$15,264($17)
.L001d1274:
	li	$15,316
	beq	$14,$15,.L001d12b4
	slti	$15,$14,317
	beqz	$15,.L001d128c
	li	$15,707
	li	$15,81
.L001d128c:
	bne	$14,$15,.L001d11dc
	move	$4,$17
	lw	$15,2884($17)
	move	$5,$17
	ld	$16,0($29)
	lhu	$4,6($15)
	ld	$17,8($29)
	ld	$31,16($29)
	j	func_001b4430
	addiu	$29,$29,32
.L001d12b4:
	ld	$16,0($29)
	ld	$17,8($29)
	ld	$31,16($29)
	j	func_001d1408
	addiu	$29,$29,32
.L001d12c8:
	lw	$15,2884($4)
	ld	$16,0($29)
	lw	$5,12($15)
	ld	$17,8($29)
	ld	$31,16($29)
	j	func_001d12e8
	addiu	$29,$29,32
	nop
	.end func_001d1190
	.size func_001d1190, 344
