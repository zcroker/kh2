# Whole-function assembly (last step of the README ladder, 2026-11-10, helper w3908).
# Both functions stayed near misses in C/C++ after many sessions and permuter runs; see ledger
# attempts.tsv and the best/ADDR_w3908.cpp drafts. Replace with C/C++ after 100%.
#   func_001fd368: draw-parameter block fill (sched1 order of the 96-byte stack block, e in v1)
# Split out of batch_w3908.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001fd368,"ax",@progbits
	.align 2
	.globl func_001fd368
	.type func_001fd368, @function
	.ent func_001fd368
func_001fd368:
	addiu	$29,$29,-112
	ori	$14,$0,0xffff
	sd	$16,96($29)
	sd	$31,104($29)
	lw	$13,12($6)
	lw	$12,4($5)
	lw	$15,8($13)
	addu	$15,$4,$15
	beq	$12,$14,.L001fd4ec
	addiu	$10,$15,160
	lw	$15,0($13)
	addu	$15,$4,$15
	addiu	$6,$15,160
	lbu	$14,11($6)
	beq	$14,$0,.L001fd4ec
	sb	$14,27($29)
	lui	$15,0x1da
	lbu	$11,32($5)
	addiu	$14,$0,36
	lw	$13,-6428($15)
	mult	$14,$12,$14
	lw	$15,16($13)
	addu	$3,$15,$14
	andi	$12,$11,0x2
	lw	$4,28($3)
	beq	$12,$0,.L001fd4fc
	sw	$0,0($29)
	addiu	$15,$0,4
	sw	$15,0($29)
	lw	$14,0($4)
	andi	$15,$14,0x1
	bne	$15,$0,.L001fd3fc
	andi	$15,$14,0x2
	addiu	$15,$0,12
.L001fd3f0:
	sw	$15,0($29)
	lw	$14,0($4)
	andi	$15,$14,0x2
.L001fd3fc:
	bne	$15,$0,.L001fd414
	lui	$15,0x1da
	lw	$15,0($29)
	ori	$15,$15,0x10
	sw	$15,0($29)
	lui	$15,0x1da
.L001fd414:
	lhu	$13,22($4)
	lw	$14,-6424($15)
	lui	$16,0x1da
	sb	$0,10($29)
	sh	$13,8($29)
	addiu	$9,$14,80
	sw	$0,28($29)
	addiu	$7,$14,16
	lui	$13,0x37
	lw	$11,-5468($16)
	addiu	$13,$13,636
	lwc1	$f0,12($10)
	lwc1	$f1,0($10)
	lwc1	$f2,0($13)
	lw	$15,144($14)
	mul.s	$f1,$f1,$f2
	mul.s	$f0,$f0,$f2
	sw	$15,56($29)
	lbu	$10,10($6)
	lw	$13,148($14)
	cvt.w.s	$f2,$f0
	lbu	$8,33($5)
	lbu	$12,8($6)
	daddu	$5,$29,$0
	mfc1	$15,$f2
	cvt.w.s	$f0,$f1
	sw	$15,20($29)
	lbu	$14,9($6)
	mfc1	$15,$f0
	sb	$14,25($29)
	sw	$15,16($29)
	lui	$14,0x1da
	sw	$13,60($29)
	lui	$15,0x1da
	sb	$12,24($29)
	addiu	$15,$15,-5440
	sb	$10,26($29)
	sw	$15,4($29)
	addiu	$14,$14,-5760
	sw	$9,32($29)
	lui	$15,0x1da
	sw	$14,40($29)
	addiu	$15,$15,-5696
	sw	$7,44($29)
	sw	$15,36($29)
	sw	$11,52($29)
	sb	$8,77($29)
	sw	$0,12($29)
	sw	$0,64($29)
	sw	$9,68($29)
	sb	$0,76($29)
	jal	0x20f1e0
	lw	$6,32($3)
	sw	$2,-5468($16)
.L001fd4ec:
	ld	$16,96($29)
	ld	$31,104($29)
	jr	$31
	addiu	$29,$29,112
.L001fd4fc:
	andi	$15,$11,0x1
	andi	$15,$15,0xff
	beq	$15,$0,.L001fd510
	addiu	$15,$0,128
	sw	$15,0($29)
.L001fd510:
	lw	$14,0($4)
	andi	$15,$14,0x1
	bnel	$15,$0,.L001fd3fc
	andi	$15,$14,0x2
	lw	$15,0($29)
	beq	$0,$0,.L001fd3f0
	ori	$15,$15,0x8
	.end func_001fd368
	.size func_001fd368, .-func_001fd368
