# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002b3908_unit.cpp
#   002b3908 (L31, 2026-11-17): near-miss best/002b3908_unit.cpp: 16 words (prologue save order, move s5,v0 and inner-loop init scheduling); permuter 850->215 then segfault
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002b3908,"ax",@progbits
	.align 3
	.globl func_002b3908
	.type func_002b3908, @function
	.ent func_002b3908
func_002b3908:
	addiu	$29,$29,-288
	sd	$30,272($29)
	sd	$20,240($29)
	sd	$22,256($29)
	move	$30,$4
	sd	$31,280($29)
	li	$4,9
	sd	$16,208($29)
	sd	$17,216($29)
	sd	$18,224($29)
	sd	$19,232($29)
	sd	$21,248($29)
	sd	$23,264($29)
	jal	func_00294000
	move	$22,$0
	jal	func_002a9d68
	sw	$2,192($29)
	lw	$14,192($29)
	lw	$15,8($14)
	blez	$15,.L002b3a94
	addiu	$20,$14,16
	move	$21,$2
.L002b3960:
	lbu	$15,1($20)
	andi	$15,$15,0xf
	sll	$4,$15,0x18
	bltz	$30,.L002b3980
	sra	$4,$4,0x18
	lb	$15,0($20)
	bne	$15,$30,.L002b3a7c
	lw	$14,192($29)
.L002b3980:
	jal	func_002b3ac8
	nop
	blez	$2,.L002b39b8
	move	$16,$2
	move	$14,$29
	addiu	$15,$2,-1
	move	$17,$2
.L002b399c:
	sw	$15,0($14)
	addiu	$17,$17,-1
	addiu	$14,$14,4
	nop
	nop
	bnez	$17,.L002b399c
	addiu	$15,$15,-1
.L002b39b8:
	move	$17,$0
.L002b39bc:
	jal	func_001064a8
	li	$4,-1
	divu	$0,$2,$16
	beqzl	$16,.L002b39d0
	break	0x7
.L002b39d0:
	mfhi	$15
	div	$0,$17,$16
	sll	$15,$15,0x2
	addu	$15,$15,$29
	lw	$11,0($15)
	mfhi	$14
	addiu	$17,$17,1
	sll	$14,$14,0x2
	slti	$12,$17,256
	addu	$14,$14,$29
	lw	$13,0($14)
	sw	$13,0($15)
	bnez	$12,.L002b39bc
	sw	$11,0($14)
	blez	$16,.L002b3a78
	move	$17,$0
	li	$23,3
	move	$19,$29
	addiu	$18,$21,480
.L002b3a1c:
	lbu	$15,0($19)
	li	$4,8
	sb	$15,8($18)
	jal	func_001064a8
	addiu	$19,$19,4
	andi	$2,$2,0x3
	lb	$15,8($18)
	bne	$15,$17,.L002b3a68
	sb	$2,9($18)
	bnezl	$2,.L002b3a6c
	addiu	$17,$17,1
	jal	func_001064a8
	li	$4,8
	divu	$0,$2,$23
	beqzl	$23,.L002b3a5c
	break	0x7
.L002b3a5c:
	mfhi	$15
	addiu	$15,$15,1
	sb	$15,9($18)
.L002b3a68:
	addiu	$17,$17,1
.L002b3a6c:
	slt	$15,$17,$16
	bnez	$15,.L002b3a1c
	addiu	$18,$18,4
.L002b3a78:
	lw	$14,192($29)
.L002b3a7c:
	addiu	$22,$22,1
	addiu	$21,$21,192
	lw	$15,8($14)
	slt	$15,$22,$15
	bnez	$15,.L002b3960
	addiu	$20,$20,16
.L002b3a94:
	ld	$16,208($29)
	ld	$17,216($29)
	ld	$18,224($29)
	ld	$19,232($29)
	ld	$20,240($29)
	ld	$21,248($29)
	ld	$22,256($29)
	ld	$23,264($29)
	ld	$30,272($29)
	ld	$31,280($29)
	jr	$31
	addiu	$29,$29,288
	nop
	.end func_002b3908
	.size func_002b3908, 448
