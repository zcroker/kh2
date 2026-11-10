# Whole-function assembly (last step of the README ladder, 2026-11-10, w3932).
# Both functions were near misses in C/C++ after several sessions; see coord attempts.tsv
# and best/0027d008_w3808.cpp, best/002f20d0_w3918.c. Replace with C/C++ after 100%.
#   func_0027d008: menu cell/label setup (loop.c will not hoist the inner D[r].n load into s8 nor reduce the store giv separately from c)
#   sceGsSetDefDispEnv: sceGsSetDefDispEnv (Sony libgraph, ee-gcc 2.9): MAGH<<23 temp register and non-interlace OR/load order
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0027d008,"ax",@progbits
	.align 2
	.globl func_0027d008
	.type func_0027d008, @function
	.ent func_0027d008
func_0027d008:
	addiu	$29,$29,-112
	sd	$17,40($29)
	sd	$18,48($29)
	sd	$23,88($29)
	sd	$31,104($29)
	lui	$18,%hi(D_0035ef6c)
	sd	$16,32($29)
	sd	$19,56($29)
	sd	$20,64($29)
	sd	$21,72($29)
	sd	$22,80($29)
	sd	$30,96($29)
	jal	func_00257770
	move	$23,$0
	sw	$2,8($29)
	lui	$15,%hi(D_0035f01c)
	lw	$4,%lo(D_0035f01c)($15)
	jal	func_0028b038
	lw	$17,8($29)
	sw	$2,16($29)
	lui	$15,%hi(D_0035f04c)
	lw	$4,%lo(D_0035f04c)($15)
	jal	func_0028be78
	lw	$5,16($29)
.L0027d068:
	addiu	$16,$17,13840
	li	$20,3
.L0027d070:
	lw	$5,%lo(D_0035ef6c)($18)
	move	$4,$16
	jal	func_00138c10
	addiu	$20,$20,-1
	sw	$0,408($16)
	bgez	$20,.L0027d070
	addiu	$16,$16,436
	addiu	$23,$23,1
	slti	$15,$23,9
	bnez	$15,.L0027d068
	addiu	$17,$17,1744
	lw	$14,16($29)
	li	$15,20
	li	$18,8
	mult	$15,$14,$15
	lw	$14,8($29)
	addiu	$17,$14,3784
	lui	$14,%hi(D_00373f10)
	addiu	$14,$14,%lo(D_00373f10)
	addu	$15,$15,$14
	addiu	$16,$15,2
.L0027d0c4:
	lhu	$4,0($16)
	jal	func_00192048
	addiu	$18,$18,-1
	addiu	$16,$16,20
	sw	$2,0($17)
	bgez	$18,.L0027d0c4
	addiu	$17,$17,436
	move	$23,$0
	lw	$15,16($29)
.L0027d0e8:
	lui	$14,%hi(D_00373f10)
	addiu	$14,$14,%lo(D_00373f10)
	addu	$22,$15,$23
	li	$15,20
	mult	$15,$22,$15
	addu	$15,$15,$14
	lh	$13,0($15)
	li	$14,1
	bne	$13,$14,.L0027d2c8
	li	$15,2
	lui	$15,%hi(D_00373ef8)
	addiu	$15,$15,%lo(D_00373ef8)
.L0027d118:
	sw	$15,12($29)
	li	$15,20
	mult	$12,$22,$15
	lui	$15,%hi(D_00373f10)
	addiu	$15,$15,%lo(D_00373f10)
	addu	$14,$12,$15
	lh	$15,0($14)
	blez	$15,.L0027d210
	move	$20,$0
	li	$15,436
	sll	$14,$23,0x2
	mult	$14,$14,$15
	lui	$15,%hi(D_00373f10)
	addiu	$15,$15,%lo(D_00373f10)
	addu	$13,$12,$15
	lw	$15,8($29)
	addiu	$21,$13,4
	lh	$30,0($13)
	addu	$14,$14,$15
	addiu	$19,$14,13840
.L0027d168:
	li	$14,9
	beq	$22,$14,.L0027d18c
	move	$18,$19
	lui	$14,%hi(D_0035f234)
	lw	$15,%lo(D_0035f234)($14)
	addu	$15,$15,$22
	lb	$14,0($15)
	bne	$14,$20,.L0027d2c0
	lw	$14,12($29)
.L0027d18c:
	lw	$15,12($29)
	lh	$5,0($15)
.L0027d194:
	move	$4,$18
	jal	func_00138c10
	addiu	$16,$18,24
	jal	func_0023aa78
	move	$4,$16
	move	$4,$16
	jal	func_0023aa98
	move	$17,$2
	mult	$17,$17,$20
	move	$16,$2
	move	$4,$18
	move	$5,$29
	jal	func_00138c78
	addiu	$6,$29,4
	lw	$6,4($29)
	move	$4,$18
	jal	func_00138c68
	move	$5,$17
	li	$15,9
	beq	$22,$15,.L0027d29c
	lui	$15,%hi(D_0035f234)
	lhu	$4,0($21)
.L0027d1ec:
	jal	func_00192048
	addiu	$20,$20,1
	sw	$2,408($19)
	addiu	$21,$21,2
	sw	$16,412($19)
	slt	$15,$20,$30
	sw	$0,416($19)
	bnez	$15,.L0027d168
	addiu	$19,$19,436
.L0027d210:
	addiu	$23,$23,1
	slti	$15,$23,9
	bnez	$15,.L0027d0e8
	lw	$15,16($29)
	lw	$19,16($29)
	move	$17,$0
	lui	$18,%hi(D_0035f01c)
	move	$4,$17
.L0027d230:
	jal	func_0027d488
	move	$5,$19
	lw	$4,%lo(D_0035f01c)($18)
	move	$5,$17
	move	$16,$2
	jal	func_002891b8
	addiu	$17,$17,1
	move	$4,$2
	jal	func_0028dcc0
	move	$5,$16
	slti	$15,$17,9
	bnez	$15,.L0027d230
	move	$4,$17
	jal	func_0027d5d8
	nop
	ld	$16,32($29)
	ld	$17,40($29)
	ld	$18,48($29)
	ld	$19,56($29)
	ld	$20,64($29)
	ld	$21,72($29)
	ld	$22,80($29)
	ld	$23,88($29)
	ld	$30,96($29)
	ld	$31,104($29)
	jr	$31
	addiu	$29,$29,112
.L0027d29c:
	lw	$14,%lo(D_0035f234)($15)
	lb	$15,9($14)
	lui	$14,%hi(D_00373f10)
	addiu	$15,$15,90
	sll	$15,$15,0x1
	addiu	$14,$14,%lo(D_00373f10)
	addu	$15,$15,$14
	b	.L0027d1ec
	lhu	$4,4($15)
.L0027d2c0:
	b	.L0027d194
	lh	$5,2($14)
.L0027d2c8:
	bnel	$13,$15,.L0027d2dc
	lui	$15,%hi(D_00373f08)
	lui	$15,%hi(D_00373f00)
	b	.L0027d118
	addiu	$15,$15,%lo(D_00373f00)
.L0027d2dc:
	b	.L0027d118
	addiu	$15,$15,%lo(D_00373f08)
	.end func_0027d008
	.size func_0027d008, 732


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
