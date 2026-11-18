# Whole-function assembly (last step of the README ladder, 2026-11-10, w3932).
# Both functions were near misses in C/C++ after several sessions; see attempts.tsv
# and best/0027d008_w3808.cpp, best/002f20d0_w3918.c. Replace with C/C++ after 100%.
#   sceGsSetDefDispEnv: sceGsSetDefDispEnv (Sony libgraph, ee-gcc 2.9): MAGH<<23 temp register and non-interlace OR/load order
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f20d0,"ax",@progbits
	.align 2
	.globl sceGsSetDefDispEnv
	.type sceGsSetDefDispEnv, @function
	.ent sceGsSetDefDispEnv
sceGsSetDefDispEnv:
	addiu	$29,$29,-144
	sll	$5,$5,0x10
	sd	$22,112($29)
	sll	$6,$6,0x10
	sd	$21,96($29)
	sll	$7,$7,0x10
	sd	$20,80($29)
	sll	$8,$8,0x10
	sd	$19,64($29)
	sll	$9,$9,0x10
	sd	$18,48($29)
	sra	$22,$5,0x10
	sd	$16,16($29)
	sra	$18,$7,0x10
	sd	$17,32($29)
	sra	$16,$6,0x10
	sd	$31,128($29)
	sra	$21,$8,0x10
	sra	$20,$9,0x10
	jal	sceGsGetGParam
	move	$19,$4
	move	$17,$2
	lhu	$4,2($17)
	addiu	$2,$4,-2
	sltiu	$2,$2,2
	bnezl	$2,.L002f2170
	sw	$0,12($29)
	jal	func_002f2020
	nop
	beqz	$2,.L002f2168
	move	$5,$29
	lh	$4,2($17)
	ori	$6,$29,0x4
	ori	$7,$29,0x8
	jal	_GetGsDxDyOffset
	ori	$8,$29,0xc
	b	.L002f217c
	lhu	$4,2($17)
.L002f2168:
	lhu	$4,2($17)
	sw	$0,12($29)
.L002f2170:
	sw	$0,8($29)
	sw	$0,4($29)
	sw	$0,0($29)
.L002f217c:
	li	$3,102
	lhu	$6,0($17)
	sd	$3,0($19)
	lh	$2,0($17)
	beqz	$2,.L002f21a4
	li	$2,2
	lh	$2,4($17)
	bnez	$2,.L002f21a4
	li	$2,3
	li	$2,1
.L002f21a4:
	sd	$2,8($19)
	addiu	$2,$16,63
	andi	$3,$22,0xf
	sra	$2,$2,0x6
	sll	$4,$4,0x10
	andi	$2,$2,0x3f
	dsll	$3,$3,0xf
	dsll	$2,$2,0x9
	sra	$5,$4,0x10
	or	$3,$3,$2
	li	$4,2
	bne	$5,$4,.L002f2280
	sd	$3,16($19)
	sll	$2,$6,0x10
	li	$3,1
	sra	$2,$2,0x10
	bne	$2,$3,.L002f2254
	addiu	$2,$16,2559
	addiu	$3,$16,2559
	beqzl	$16,.L002f21f8
	break	0x7
.L002f21f8:
	div	$0,$3,$16
	lw	$2,4($29)
	lw	$5,0($29)
	addu	$2,$20,$2
	lh	$6,4($17)
	addiu	$2,$2,50
	daddiu	$5,$5,636
	andi	$2,$2,0xfff
	dsll	$7,$2,0xc
	mflo	$3
	mult	$4,$3,$16
	mult1	$2,$21,$3
	addiu	$3,$3,-1
	dsll	$10,$3,0x17
	addiu	$4,$4,-1
	dsll32	$3,$4,0x0
	daddu	$5,$2,$5
	beqz	$6,.L002f2308
	andi	$5,$5,0xfff
	sll	$2,$18,0x1
	or	$3,$10,$3
	b	.L002f2310
	addiu	$2,$2,-1
.L002f2254:
	beqzl	$16,.L002f225c
	break	0x7
.L002f225c:
	div	$0,$2,$16
	addiu	$7,$18,-1
	lw	$5,0($29)
	dsll32	$7,$7,0xc
	lw	$3,4($29)
	daddiu	$5,$5,636
	addu	$3,$20,$3
	b	.L002f2350
	addiu	$3,$3,25
.L002f2280:
	li	$2,3
	bne	$5,$2,.L002f2394
	li	$2,80
	sll	$2,$6,0x10
	li	$3,1
	sra	$2,$2,0x10
	bne	$2,$3,.L002f2328
	addiu	$2,$16,2559
	addiu	$3,$16,2559
	beqzl	$16,.L002f22ac
	break	0x7
.L002f22ac:
	div	$0,$3,$16
	lw	$2,4($29)
	lw	$5,0($29)
	addu	$2,$20,$2
	lh	$6,4($17)
	addiu	$2,$2,72
	daddiu	$5,$5,656
	andi	$2,$2,0xfff
	dsll	$7,$2,0xc
	mflo	$3
	mult	$4,$3,$16
	mult1	$2,$21,$3
	addiu	$3,$3,-1
	dsll	$10,$3,0x17
	addiu	$4,$4,-1
	dsll32	$3,$4,0x0
	daddu	$5,$2,$5
	beqz	$6,.L002f2308
	andi	$5,$5,0xfff
	sll	$2,$18,0x1
	or	$3,$10,$3
	b	.L002f2310
	addiu	$2,$2,-1
.L002f2308:
	addiu	$2,$18,-1
	or	$3,$10,$3
.L002f2310:
	dsll32	$2,$2,0xc
	or	$2,$5,$2
	or	$3,$3,$2
	or	$2,$3,$7
	b	.L002f2418
	sd	$2,24($19)
.L002f2328:
	beqzl	$16,.L002f2330
	break	0x7
.L002f2330:
	div	$0,$2,$16
	addiu	$7,$18,-1
	lw	$5,0($29)
	dsll32	$7,$7,0xc
	lw	$3,4($29)
	daddiu	$5,$5,656
	addu	$3,$20,$3
	addiu	$3,$3,36
.L002f2350:
	andi	$3,$3,0xfff
	dsll	$3,$3,0xc
	mflo	$2
	mult	$6,$21,$2
	mult1	$4,$2,$16
	addiu	$2,$2,-1
	daddu	$5,$6,$5
	dsll	$2,$2,0x17
	andi	$5,$5,0xfff
	addiu	$4,$4,-1
	or	$5,$5,$7
	dsll32	$4,$4,0x0
	or	$2,$2,$4
	or	$2,$2,$5
	or	$2,$2,$3
	b	.L002f2418
	sd	$2,24($19)
.L002f2394:
	bne	$5,$2,.L002f2410
	lui	$4,%hi(D_003762c8+16)
	li	$2,720
	lw	$5,0($29)
	subu	$2,$2,$16
	sll	$6,$21,0x1
	srl	$3,$2,0x1f
	lw	$4,4($29)
	addu	$2,$2,$3
	daddiu	$7,$6,232
	sra	$2,$2,0x1
	sll	$6,$16,0x1
	sll	$2,$2,0x1
	addu	$4,$20,$4
	daddu	$5,$2,$5
	addiu	$3,$18,-1
	daddu	$5,$5,$7
	addiu	$6,$6,-1
	dsll32	$3,$3,0xc
	dsll32	$6,$6,0x0
	andi	$5,$5,0xfff
	addiu	$4,$4,35
	lui	$2,0x80
	or	$3,$3,$6
	or	$5,$5,$2
	andi	$4,$4,0xfff
	or	$3,$3,$5
	dsll	$4,$4,0xc
	or	$3,$3,$4
	b	.L002f2418
	sd	$3,24($19)
.L002f2410:
	jal	func_003080d0
	addiu	$4,$4,%lo(D_003762c8+16)
.L002f2418:
	sd	$0,32($19)
	ld	$31,128($29)
	ld	$22,112($29)
	ld	$21,96($29)
	ld	$20,80($29)
	ld	$19,64($29)
	ld	$18,48($29)
	ld	$17,32($29)
	ld	$16,16($29)
	jr	$31
	addiu	$29,$29,144
	.end sceGsSetDefDispEnv
	.size sceGsSetDefDispEnv, 884
