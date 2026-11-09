# Whole-function assembly (last step of the README ladder, 2026-11-10, zl90 w3913).
# Both functions were long-standing near misses in C/C++ after several sessions; see coord attempts.tsv
# and the best/ADDR_w3913.* drafts. Replace with C/C++ after 100%.
#   func_0011f7a8: model part draw (single texture); scattered s-reg swaps, operand order and mask/shift forms
#   func_002a6e50: menu setup; reload-register choice for spilled row/hi(D_0035f5f4) temps in the loop body
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0011f7a8,"ax",@progbits
	.globl func_0011f7a8
	.type func_0011f7a8, @function
	.ent func_0011f7a8
func_0011f7a8:
	addiu	$29,$29,-208
	andi	$9,$9,0xff
	sd	$16,128($29)
	sd	$17,136($29)
	sd	$18,144($29)
	move	$16,$10
	sd	$19,152($29)
	move	$17,$5
	sd	$20,160($29)
	sd	$21,168($29)
	sd	$22,176($29)
	sd	$23,184($29)
	sd	$30,192($29)
	sd	$31,200($29)
	sw	$4,48($29)
	sw	$6,52($29)
	sw	$7,56($29)
	sw	$8,60($29)
	jal	0x10ae90
	sw	$9,64($29)
	sw	$2,68($29)
	lui	$15,0x1
	sw	$0,80($29)
	move	$13,$0
	lw	$10,52($29)
	lw	$12,48($29)
	lw	$14,0($10)
	lw	$12,4($12)
	and	$14,$14,$15
	movn	$13,$16,$14
	sw	$12,72($29)
	sw	$0,84($29)
	bnez	$13,.L0011f844
	sw	$13,88($29)
	lw	$14,48($29)
	lw	$15,12($14)
	andi	$15,$15,0x2
	bnez	$15,.L0011f848
	sw	$16,92($29)
.L0011f844:
	sw	$0,92($29)
.L0011f848:
	lw	$10,72($29)
	lhu	$15,16($10)
	beqz	$15,.L0011f8e4
	sw	$0,76($29)
	lw	$13,72($29)
	move	$12,$15
	li	$11,0xffff
.L0011f864:
	lw	$15,56($29)
	lw	$10,76($29)
	addu	$14,$15,$10
	lbu	$15,0($14)
	andi	$15,$15,0xf
	beqz	$15,.L0011f8cc
	lw	$10,84($29)
	move	$14,$13
	lw	$15,40($13)
	addiu	$10,$10,1
	sltu	$15,$11,$15
	bnez	$15,.L0012050c
	sw	$10,84($29)
	lw	$15,64($29)
	bnezl	$15,.L0011f8d0
	lw	$14,76($29)
	lw	$15,88($29)
.L0011f8a8:
	beqzl	$15,.L0011f8c4
	lw	$10,80($29)
	lw	$15,44($14)
	andi	$15,$15,0x1
	bnez	$15,.L0011f8d0
	lw	$14,76($29)
	lw	$10,80($29)
.L0011f8c4:
	addiu	$10,$10,1
	sw	$10,80($29)
.L0011f8cc:
	lw	$14,76($29)
.L0011f8d0:
	addiu	$13,$13,16
	addiu	$14,$14,1
	slt	$15,$14,$12
	bnez	$15,.L0011f864
	sw	$14,76($29)
.L0011f8e4:
	lw	$15,84($29)
	lw	$10,80($29)
	beqz	$10,.L001202f8
	sltiu	$2,$15,1
	jal	0x1344f8
	nop
	sw	$2,96($29)
	li	$5,1
	lw	$12,52($29)
	lw	$4,96($29)
	lw	$12,36($12)
	jal	0x109360
	sw	$12,100($29)
	lw	$4,52($29)
	jal	0x108730
	lw	$5,96($29)
	addiu	$15,$2,80
	beq	$15,$17,.L0011f950
	move	$16,$2
	lq	$8,0($17)
	lq	$9,16($17)
	lq	$10,32($17)
	lq	$11,48($17)
	sq	$8,0($15)
	sq	$9,16($15)
	sq	$10,32($15)
	sq	$11,48($15)
.L0011f950:
	lw	$13,88($29)
	beqz	$13,.L0011f9dc
	lui	$6,0x100
	lw	$4,96($29)
	lui	$7,0x6c04
	li	$5,4
	ori	$6,$6,0x101
	jal	0x133bb8
	ori	$7,$7,0x400a
	lw	$14,88($29)
	beql	$2,$14,.L0011f9a4
	ld	$13,0($16)
	lq	$8,0($14)
	lq	$9,16($14)
	lq	$10,32($14)
	lq	$11,48($14)
	sq	$8,0($2)
	sq	$9,16($2)
	sq	$10,32($2)
	sq	$11,48($2)
	ld	$13,0($16)
.L0011f9a4:
	li	$14,2047
	dsll32	$14,$14,0xf
	lui	$12,0x303e
	dsrl32	$15,$13,0xf
	sw	$0,100($29)
	andi	$15,$15,0x7ff
	nor	$14,$0,$14
	ori	$15,$15,0x50
	and	$13,$13,$14
	dsll32	$15,$15,0xf
	ori	$12,$12,0xc000
	or	$13,$13,$15
	sd	$13,0($16)
	sw	$12,0($16)
.L0011f9dc:
	lw	$15,92($29)
	beqz	$15,.L0011fa7c
	lui	$6,0x100
	lw	$4,96($29)
	lui	$7,0x6c04
	li	$5,4
	ori	$6,$6,0x101
	jal	0x133bb8
	ori	$7,$7,0x400a
	lui	$10,0x37
	addiu	$15,$29,16
	addiu	$10,$10,-22192
	lwc1	$f0,0($10)
	swc1	$f0,28($29)
	swc1	$f0,16($29)
	swc1	$f0,20($29)
	beq	$2,$15,.L0011fa2c
	swc1	$f0,24($29)
	lq	$8,0($15)
	sq	$8,0($2)
.L0011fa2c:
	lw	$12,92($29)
	addiu	$15,$2,16
	beq	$15,$12,.L0011fa48
	lw	$13,92($29)
	lq	$8,0($12)
	sq	$8,0($15)
	lw	$13,92($29)
.L0011fa48:
	addiu	$14,$2,32
	addiu	$15,$13,16
	beql	$14,$15,.L0011fa64
	lw	$14,92($29)
	lq	$8,0($15)
	sq	$8,0($14)
	lw	$14,92($29)
.L0011fa64:
	addiu	$2,$2,48
	addiu	$15,$14,32
	beql	$2,$15,.L0011fa80
	lw	$15,100($29)
	lq	$8,0($15)
	sq	$8,0($2)
.L0011fa7c:
	lw	$15,100($29)
.L0011fa80:
	beqz	$15,.L0011fc7c
	lw	$10,100($29)
	lw	$15,20($15)
	lw	$4,96($29)
	addu	$15,$10,$15
	sw	$15,104($29)
	jal	0x109788
	lw	$5,104($29)
	beqz	$2,.L0011fab4
	lw	$4,100($29)
	jal	0x109708
	lw	$4,96($29)
	lw	$4,100($29)
.L0011fab4:
	jal	0x132018
	sw	$0,76($29)
	lw	$12,72($29)
	lui	$15,0x3b
	addiu	$16,$15,-26128
	lw	$4,60($29)
	lhu	$7,20($12)
	move	$8,$2
	move	$5,$16
	jal	0x133078
	li	$6,0xf000
	lw	$13,100($29)
	lw	$10,12($13)
	blez	$10,.L0011fc80
	lw	$14,48($29)
.L0011faf0:
	lw	$15,100($29)
	lw	$12,76($29)
	lw	$14,16($15)
	lw	$13,20($15)
	sll	$11,$12,0x3
	lui	$15,0x3b
	addiu	$15,$15,-26128
	addu	$12,$11,$15
	lw	$15,100($29)
	lw	$30,0($12)
	addu	$14,$15,$14
	lw	$15,76($29)
	addu	$14,$14,$15
	lbu	$15,0($14)
	li	$14,144
	mult	$15,$15,$14
	addiu	$15,$15,144
	addu	$13,$13,$15
	lw	$15,100($29)
	addu	$13,$15,$13
	beqz	$30,.L00120504
	sw	$13,104($29)
	lw	$15,4($12)
	lui	$12,0x3b
	addiu	$12,$12,-26128
	addu	$23,$15,$12
.L0011fb58:
	beqz	$23,.L0011fc6c
	lw	$13,76($29)
	blez	$30,.L0011fc6c
	lw	$14,76($29)
	li	$15,160
	lui	$13,0x3b
	mult	$14,$14,$15
	addiu	$13,$13,-26128
	addu	$11,$11,$13
	sw	$11,112($29)
	sw	$14,108($29)
.L0011fb84:
	lw	$22,0($23)
	move	$5,$0
	jal	0x132d90
	move	$4,$22
	move	$4,$22
	beqz	$2,.L001204d8
	slti	$14,$30,2
	lw	$15,100($29)
	lw	$10,108($29)
	lw	$16,24($15)
	addu	$16,$16,$10
	jal	0x132c98
	addu	$16,$15,$16
	move	$18,$2
	jal	0x132cd0
	move	$4,$22
	move	$17,$2
	jal	0x132d00
	move	$4,$22
	move	$21,$2
	jal	0x132d30
	move	$4,$22
	move	$20,$2
	jal	0x132d60
	move	$4,$22
	move	$19,$2
	move	$4,$22
	jal	0x132d90
	move	$5,$0
	ld	$6,112($16)
	lui	$13,0x3f0
	lw	$12,104($29)
	lui	$14,0xf
	and	$11,$6,$13
	ori	$14,$14,0xc000
	ld	$5,32($12)
	li	$15,16383
	and	$6,$6,$14
	dsll32	$15,$15,0x0
	and	$5,$5,$15
	sw	$2,0($29)
	dsll	$6,$6,0x12
	dsll	$11,$11,0xc
	move	$4,$18
	move	$7,$17
	dsra32	$5,$5,0x0
	dsra32	$6,$6,0x0
	dsra32	$11,$11,0x0
	move	$8,$21
	move	$9,$20
	jal	0x1097e8
	move	$10,$19
.L0011fc54:
	addiu	$30,$30,-1
	bgtz	$30,.L0011fb84
	addiu	$23,$23,4
	lw	$12,100($29)
	lw	$10,12($12)
	lw	$13,76($29)
.L0011fc6c:
	addiu	$13,$13,1
	slt	$15,$13,$10
	bnez	$15,.L0011faf0
	sw	$13,76($29)
.L0011fc7c:
	lw	$14,48($29)
.L0011fc80:
	li	$21,-1
	lw	$15,4($14)
	sw	$0,76($29)
	jal	0x10aba8
	lw	$16,4($15)
	lw	$15,52($29)
	move	$4,$2
	move	$5,$16
	jal	0x109f58
	lbu	$6,7($15)
	sw	$21,32($29)
	lw	$10,72($29)
	lhu	$13,16($10)
	andi	$15,$13,0xffff
	beqz	$15,.L001202e8
	move	$30,$2
.L0011fcc0:
	lw	$15,76($29)
	lw	$12,56($29)
	addu	$14,$12,$15
	lbu	$15,0($14)
	andi	$15,$15,0xf
	andi	$16,$15,0xff
	beqz	$16,.L001202d0
	li	$15,0xffff
	lw	$10,76($29)
	lw	$12,72($29)
	sll	$19,$10,0x4
	addu	$17,$19,$12
	lw	$14,40($17)
	sltu	$15,$15,$14
	bnezl	$15,.L001204c8
	lw	$15,64($29)
	lw	$14,64($29)
	bnezl	$14,.L001202d4
	lw	$14,76($29)
	lw	$10,88($29)
.L0011fd10:
	beqzl	$10,.L0011fd2c
	lw	$4,96($29)
	lw	$15,44($17)
	andi	$15,$15,0x1
	bnez	$15,.L001202d4
	lw	$14,76($29)
	lw	$4,96($29)
.L0011fd2c:
	move	$5,$0
	lui	$6,0x1100
	jal	0x133bb8
	lui	$7,0x1300
	xori	$15,$16,0x1
	sw	$0,28($29)
	sltu	$15,$0,$15
	sw	$0,24($29)
	sw	$0,20($29)
	sw	$15,16($29)
	lw	$12,88($29)
	beqz	$12,.L0011fd64
	ori	$15,$15,0x4000
	sw	$15,16($29)
.L0011fd64:
	lw	$13,92($29)
	beqz	$13,.L0011fd90
	lw	$15,16($29)
	lhu	$15,38($17)
	andi	$15,$15,0x1
	andi	$15,$15,0xffff
	beqz	$15,.L0011fd8c
	lw	$15,16($29)
	ori	$15,$15,0x20
	sw	$15,16($29)
.L0011fd8c:
	lw	$15,16($29)
.L0011fd90:
	andi	$15,$15,0x4000
	bnez	$15,.L0011feac
	ld	$14,16($29)
	lw	$15,72($29)
	addu	$14,$19,$15
	addiu	$16,$14,32
	lw	$15,12($16)
	srl	$15,$15,0x1
	andi	$8,$15,0x1f
	beqz	$8,.L0011feac
	ld	$14,16($29)
	lw	$10,100($29)
	beqz	$10,.L0011feb0
	ld	$15,32($29)
	lw	$4,60($29)
	addiu	$8,$8,-1
	move	$5,$0
	li	$6,2
	jal	0x132390
	li	$7,-1
	beqz	$2,.L0011fea8
	move	$17,$2
	lhu	$15,4($16)
	li	$13,160
	lw	$12,100($29)
	mult	$15,$15,$13
	lw	$14,24($12)
	addu	$14,$14,$15
	addu	$16,$12,$14
	ld	$15,128($16)
	andi	$14,$15,0x3
	beqz	$14,.L0011fe1c
	li	$15,3
	bne	$14,$15,.L0011feac
	ld	$14,16($29)
.L0011fe1c:
	lw	$15,16($29)
	ori	$15,$15,0x2
	sw	$15,16($29)
	ld	$4,112($16)
	dsrl	$4,$4,0x1a
	andi	$4,$4,0xf
	dsll32	$4,$4,0x0
	jal	0x10aed8
	dsra32	$4,$4,0x0
	ld	$5,128($16)
	move	$6,$2
	move	$4,$17
	dsrl	$5,$5,0x4
	andi	$5,$5,0x3ff
	dsll32	$5,$5,0x0
	dsra32	$5,$5,0x0
	jal	0x1333f8
	addiu	$5,$5,1
	sw	$2,24($29)
	ld	$4,112($16)
	dsrl	$4,$4,0x1e
	andi	$4,$4,0xf
	dsll32	$4,$4,0x0
	jal	0x10aed8
	dsra32	$4,$4,0x0
	ld	$5,128($16)
	move	$6,$2
	move	$4,$17
	dsrl	$5,$5,0x18
	andi	$5,$5,0x3ff
	dsll32	$5,$5,0x0
	dsra32	$5,$5,0x0
	jal	0x1334a8
	addiu	$5,$5,1
	sw	$2,28($29)
.L0011fea8:
	ld	$14,16($29)
.L0011feac:
	ld	$15,32($29)
.L0011feb0:
	bne	$14,$15,.L0011fec8
	move	$13,$0
	ld	$14,24($29)
	ld	$15,40($29)
	beq	$14,$15,.L0011fed0
	andi	$15,$13,0xff
.L0011fec8:
	li	$13,1
	andi	$15,$13,0xff
.L0011fed0:
	bnezl	$15,.L0011ff08
	lw	$5,16($29)
	lw	$15,16($29)
	andi	$15,$15,0x20
	beqz	$15,.L0012014c
	lw	$14,100($29)
	lw	$13,100($29)
	beqz	$13,.L00120264
	lw	$14,72($29)
	addu	$15,$19,$14
	lhu	$14,36($15)
	beq	$14,$21,.L0012014c
	lw	$14,100($29)
	lw	$5,16($29)
.L0011ff08:
	move	$6,$0
	lw	$4,96($29)
	lw	$7,20($29)
	lw	$8,24($29)
	jal	0x1093c8
	lw	$9,28($29)
	lw	$15,16($29)
	andi	$15,$15,0x20
	beqz	$15,.L00120130
	lw	$15,100($29)
	beqz	$15,.L00120134
	addiu	$14,$29,32
	lw	$10,72($29)
	lw	$12,100($29)
	addu	$15,$19,$10
	lhu	$14,36($15)
	lw	$16,24($12)
	li	$15,160
	mult	$14,$14,$15
	addu	$16,$16,$14
	addu	$16,$12,$16
	ld	$4,112($16)
	dsrl	$4,$4,0x1a
	andi	$4,$4,0xf
	dsll32	$4,$4,0x0
	jal	0x10aed8
	dsra32	$4,$4,0x0
	ld	$4,112($16)
	move	$18,$2
	dsrl	$4,$4,0x1e
	andi	$4,$4,0xf
	dsll32	$4,$4,0x0
	jal	0x10aed8
	dsra32	$4,$4,0x0
	ld	$13,128($16)
	andi	$14,$13,0x3
	beqz	$14,.L0011ffac
	move	$20,$2
	li	$15,3
	bne	$14,$15,.L00120484
	dsrl32	$12,$13,0x2
.L0011ffac:
	dsrl	$14,$13,0x18
	dsrl	$15,$13,0x4
	andi	$15,$15,0x3ff
	andi	$14,$14,0x3ff
	dsll32	$13,$15,0x0
	dsll32	$12,$14,0x0
	dsra32	$13,$13,0x0
	dsra32	$12,$12,0x0
	move	$22,$0
	move	$23,$0
.L0011ffd4:
	subu	$15,$13,$22
	lw	$4,96($29)
	subu	$14,$12,$23
	lui	$6,0x100
	lui	$7,0x6c01
	addiu	$16,$15,1
	addiu	$17,$14,1
	li	$5,1
	ori	$6,$6,0x101
	jal	0x133bb8
	ori	$7,$7,0x400a
	bltzl	$16,.L0012046c
	andi	$15,$16,0x1
	mtc1	$16,$f1
	cvt.s.w	$f1,$f1
.L00120010:
	lui	$13,0x37
	addiu	$13,$13,-22192
	lwc1	$f0,0($13)
	bltz	$18,.L00120450
	mul.s	$f1,$f1,$f0
	mtc1	$18,$f0
	cvt.s.w	$f0,$f0
.L0012002c:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$13,$2,4
	bltz	$17,.L00120434
	swc1	$f0,0($2)
	mtc1	$17,$f1
	cvt.s.w	$f1,$f1
.L0012004c:
	lui	$14,0x37
	addiu	$14,$14,-22192
	lwc1	$f0,0($14)
	bltz	$20,.L00120418
	mul.s	$f1,$f1,$f0
	mtc1	$20,$f0
	cvt.s.w	$f0,$f0
.L00120068:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$12,$2,8
	bltz	$22,.L001203fc
	swc1	$f0,0($13)
	mtc1	$22,$f1
	cvt.s.w	$f1,$f1
.L00120088:
	lui	$15,0x37
	addiu	$15,$15,-22188
	lwc1	$f0,0($15)
	bltz	$16,.L001203e0
	mul.s	$f2,$f1,$f0
	mtc1	$16,$f1
	cvt.s.w	$f1,$f1
.L001200a4:
	lui	$10,0x37
	addiu	$10,$10,-22192
	lwc1	$f0,0($10)
	mul.s	$f0,$f1,$f0
	bltz	$18,.L001203c4
	add.s	$f1,$f2,$f0
	mtc1	$18,$f0
	cvt.s.w	$f0,$f0
.L001200c4:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$2,$2,12
	bltz	$23,.L001203a8
	swc1	$f0,0($12)
	mtc1	$23,$f1
	cvt.s.w	$f1,$f1
.L001200e4:
	lui	$12,0x37
	addiu	$12,$12,-22188
	lwc1	$f0,0($12)
	bltz	$17,.L0012038c
	mul.s	$f2,$f1,$f0
	mtc1	$17,$f1
	cvt.s.w	$f1,$f1
.L00120100:
	lui	$13,0x37
	addiu	$13,$13,-22192
	lwc1	$f0,0($13)
	mul.s	$f0,$f1,$f0
	bltz	$20,.L00120370
	add.s	$f1,$f2,$f0
	mtc1	$20,$f0
	cvt.s.w	$f0,$f0
.L00120120:
	nop
	nop
	div.s	$f0,$f1,$f0
	swc1	$f0,0($2)
.L00120130:
	addiu	$14,$29,32
.L00120134:
	addiu	$15,$29,16
	beql	$14,$15,.L0012014c
	lw	$14,100($29)
	lq	$8,0($15)
	sq	$8,0($14)
	lw	$14,100($29)
.L0012014c:
	beqz	$14,.L00120264
	lw	$15,72($29)
	lw	$13,16($14)
	addu	$16,$19,$15
	lw	$10,100($29)
	addiu	$16,$16,32
	lw	$4,96($29)
	lhu	$14,4($16)
	addu	$13,$10,$13
	lw	$12,20($10)
	addu	$13,$13,$14
	lbu	$15,0($13)
	li	$14,144
	mult	$15,$15,$14
	addiu	$15,$15,144
	addu	$12,$12,$15
	addu	$18,$10,$12
	jal	0x109788
	move	$5,$18
	lhu	$14,4($16)
	lui	$15,0x3b
	addiu	$4,$15,-26128
	sltu	$2,$0,$2
	sll	$14,$14,0x3
	dsll32	$20,$2,0x0
	addu	$14,$14,$4
	lw	$17,0($14)
	beqz	$17,.L00120368
	dsra32	$20,$20,0x0
	lw	$15,4($14)
	addu	$16,$15,$4
.L001201c8:
	beqz	$16,.L00120224
	lw	$12,72($29)
	blez	$17,.L00120228
	addu	$15,$19,$12
	li	$20,1
	lw	$4,0($16)
.L001201e0:
	jal	0x132c98
	addiu	$17,$17,-1
	lw	$4,96($29)
	move	$5,$2
	move	$6,$0
	move	$7,$0
	jal	0x133c60
	move	$8,$0
	jal	0x132c98
	lw	$4,0($16)
	addiu	$16,$16,4
	move	$5,$2
	jal	0x1094e0
	move	$4,$18
	bgtzl	$17,.L001201e0
	lw	$4,0($16)
	lw	$12,72($29)
.L00120224:
	addu	$15,$19,$12
.L00120228:
	addiu	$16,$15,32
	lhu	$14,4($16)
	beq	$14,$21,.L00120350
	li	$15,160
	lw	$13,100($29)
	mult	$15,$14,$15
	lw	$4,96($29)
	lw	$5,24($13)
	move	$6,$0
	move	$7,$0
	move	$8,$0
	addu	$5,$5,$15
	jal	0x133c60
	addu	$5,$13,$5
	lhu	$21,4($16)
.L00120264:
	lw	$14,64($29)
.L00120268:
	beqz	$14,.L001202a4
	lw	$15,72($29)
	addu	$14,$19,$15
	lw	$14,44($14)
	srl	$15,$14,0x6
	andi	$15,$15,0x1
	beqz	$15,.L00120328
	li	$5,1
	lw	$4,68($29)
	dsll32	$5,$5,0x7
	ori	$5,$5,0x48
.L00120294:
	jal	0x108eb8
	nop
	jal	0x109008
	lw	$4,68($29)
.L001202a4:
	lw	$10,72($29)
	move	$6,$0
	lw	$4,96($29)
	move	$7,$0
	addu	$15,$19,$10
	move	$8,$0
	lw	$5,32($15)
	jal	0x133c60
	addu	$5,$10,$5
	lw	$12,72($29)
	lhu	$13,16($12)
.L001202d0:
	lw	$14,76($29)
.L001202d4:
	andi	$15,$13,0xffff
	addiu	$14,$14,1
	slt	$15,$14,$15
	bnez	$15,.L0011fcc0
	sw	$14,76($29)
.L001202e8:
	lw	$10,80($29)
	lw	$12,84($29)
	slt	$15,$10,$12
	sltiu	$2,$15,1
.L001202f8:
	ld	$16,128($29)
	ld	$17,136($29)
	ld	$18,144($29)
	ld	$19,152($29)
	ld	$20,160($29)
	ld	$21,168($29)
	ld	$22,176($29)
	ld	$23,184($29)
	ld	$30,192($29)
	ld	$31,200($29)
	jr	$31
	addiu	$29,$29,208
.L00120328:
	srl	$15,$14,0x7
	andi	$15,$15,0x1
	beqz	$15,.L00120348
	lw	$4,68($29)
	li	$5,1
	dsll32	$5,$5,0x7
	b	.L00120294
	ori	$5,$5,0x42
.L00120348:
	b	.L00120294
	move	$5,$30
.L00120350:
	beqzl	$20,.L00120268
	lw	$14,64($29)
	jal	0x109690
	lw	$4,96($29)
	b	.L00120268
	lw	$14,64($29)
.L00120368:
	b	.L001201c8
	move	$16,$0
.L00120370:
	srl	$14,$20,0x1
	andi	$15,$20,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L00120120
	add.s	$f0,$f0,$f0
.L0012038c:
	srl	$14,$17,0x1
	andi	$15,$17,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00120100
	add.s	$f1,$f1,$f1
.L001203a8:
	srl	$14,$23,0x1
	andi	$15,$23,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L001200e4
	add.s	$f1,$f1,$f1
.L001203c4:
	srl	$14,$18,0x1
	andi	$15,$18,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L001200c4
	add.s	$f0,$f0,$f0
.L001203e0:
	srl	$14,$16,0x1
	andi	$15,$16,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L001200a4
	add.s	$f1,$f1,$f1
.L001203fc:
	srl	$14,$22,0x1
	andi	$15,$22,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00120088
	add.s	$f1,$f1,$f1
.L00120418:
	andi	$15,$20,0x1
	srl	$14,$20,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L00120068
	add.s	$f0,$f0,$f0
.L00120434:
	andi	$15,$17,0x1
	srl	$14,$17,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L0012004c
	add.s	$f1,$f1,$f1
.L00120450:
	andi	$15,$18,0x1
	srl	$14,$18,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L0012002c
	add.s	$f0,$f0,$f0
.L0012046c:
	srl	$14,$16,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00120010
	add.s	$f1,$f1,$f1
.L00120484:
	dsrl	$15,$13,0x4
	dsrl	$14,$13,0x18
	andi	$15,$15,0x3ff
	dsrl	$13,$13,0xe
	andi	$14,$14,0x3ff
	andi	$13,$13,0x3ff
	andi	$12,$12,0x3ff
	dsll32	$22,$15,0x0
	dsll32	$23,$14,0x0
	dsll32	$13,$13,0x0
	dsll32	$12,$12,0x0
	dsra32	$22,$22,0x0
	dsra32	$23,$23,0x0
	dsra32	$13,$13,0x0
	b	.L0011ffd4
	dsra32	$12,$12,0x0
	nop
.L001204c8:
	beqzl	$15,.L001202d4
	lw	$14,76($29)
	b	.L0011fd10
	lw	$10,88($29)
.L001204d8:
	lw	$10,112($29)
	lw	$15,0($10)
	addiu	$15,$15,-1
	bnez	$14,.L0011fc54
	sw	$15,0($10)
	sll	$15,$30,0x2
	addu	$15,$23,$15
	lw	$14,-4($15)
	sw	$14,0($23)
	b	.L0011fc54
	addiu	$23,$23,-4
.L00120504:
	b	.L0011fb58
	move	$23,$0
.L0012050c:
	lw	$10,64($29)
	beqz	$10,.L0011f8cc
	lw	$15,88($29)
	b	.L0011f8a8
	nop
	.end func_0011f7a8
	.size func_0011f7a8, .-func_0011f7a8


	.section .text.func_002a6e50,"ax",@progbits
	.globl func_002a6e50
	.type func_002a6e50, @function
	.ent func_002a6e50
func_002a6e50:
	addiu	$29,$29,-144
	sd	$31,136($29)
	sd	$18,80($29)
	sd	$21,104($29)
	sd	$23,120($29)
	move	$18,$0
	sd	$16,64($29)
	sd	$17,72($29)
	sd	$19,88($29)
	sd	$20,96($29)
	sd	$22,112($29)
	sd	$30,128($29)
	jal	0x1058e8
	move	$21,$0
	jal	0x2766d0
	addiu	$23,$2,18932
	jal	0x2a7490
	sw	$2,16($29)
	jal	0x2a74c0
	sw	$2,20($29)
	jal	0x276c18
	sw	$2,24($29)
	sw	$2,28($29)
	li	$11,1
.L002a6eb0:
	srl	$15,$18,0x5
	andi	$13,$18,0x1f
	sll	$15,$15,0x2
	sllv	$13,$11,$13
	addu	$15,$15,$23
	addiu	$12,$21,1
	lw	$14,0($15)
	addiu	$18,$18,1
	and	$14,$14,$13
	slti	$15,$18,60
	bnez	$15,.L002a6eb0
	movn	$21,$12,$14
	move	$20,$0
	move	$18,$0
	addiu	$11,$23,8
	li	$10,1
.L002a6ef0:
	srl	$15,$18,0x5
	andi	$13,$18,0x1f
	sll	$15,$15,0x2
	sllv	$13,$10,$13
	addu	$15,$15,$11
	addiu	$12,$20,1
	lw	$14,0($15)
	addiu	$18,$18,1
	and	$14,$14,$13
	slti	$15,$18,64
	bnez	$15,.L002a6ef0
	movn	$20,$12,$14
	move	$19,$0
	move	$18,$0
	addiu	$11,$23,28
	li	$10,1
.L002a6f30:
	srl	$15,$18,0x5
	andi	$13,$18,0x1f
	sll	$15,$15,0x2
	sllv	$13,$10,$13
	addu	$15,$15,$11
	addiu	$12,$19,1
	lw	$14,0($15)
	addiu	$18,$18,1
	and	$14,$14,$13
	slti	$15,$18,59
	bnez	$15,.L002a6f30
	movn	$19,$12,$14
	jal	0x2abdc8
	move	$18,$0
	lui	$15,0x36
	sw	$0,32($29)
	lw	$15,-3116($15)
	sw	$15,36($29)
	lui	$15,0x37
	addiu	$15,$15,19448
	sw	$15,48($29)
.L002a6f84:
	beqz	$18,.L002a6f94
	li	$15,3
	bne	$18,$15,.L002a6f98
	lw	$30,24($29)
.L002a6f94:
	lw	$30,20($29)
.L002a6f98:
	bnez	$30,.L002a6fac
	lw	$12,32($29)
	lw	$12,28($29)
	beqz	$12,.L002a7208
	lw	$12,32($29)
.L002a6fac:
	li	$15,872
	lui	$13,0x36
	move	$4,$18
	mult	$15,$12,$15
	lw	$14,-2572($13)
	jal	0x2adf60
	addu	$22,$14,$15
	beqz	$2,.L002a72f8
	lui	$15,0x37
	lw	$9,19444($15)
.L002a6fd4:
	lui	$14,0x36
	lw	$5,36($29)
	lui	$15,0x36
	lw	$8,-3568($14)
	lui	$13,0x36
	lw	$6,-3764($15)
	lw	$7,-3768($13)
	li	$10,-1
	sw	$0,0($29)
	li	$11,-1
	move	$4,$22
	jal	0x28d980
	addiu	$16,$22,24
	jal	0x23aa78
	move	$4,$16
	move	$17,$2
	jal	0x23aa18
	move	$4,$16
	sw	$2,40($29)
	jal	0x23aa38
	move	$4,$16
	sw	$2,44($29)
	jal	0x139620
	move	$4,$22
	lw	$12,32($29)
	move	$4,$22
	move	$5,$0
	mult	$17,$17,$12
	jal	0x138c68
	move	$6,$17
	lw	$5,16($29)
	jal	0x28dcc0
	move	$4,$22
	lui	$14,0x6000
	li	$15,3
	ori	$14,$14,0x8
	sw	$15,428($22)
	beqz	$30,.L002a72e4
	sw	$14,420($22)
	bnez	$18,.L002a72d4
	lw	$15,48($29)
	lw	$13,32($29)
	lui	$15,0x36
	lw	$14,-2572($15)
	sll	$12,$13,0x5
	addu	$14,$14,$12
	lui	$13,0x37
	addiu	$16,$14,3488
	lhu	$4,19448($13)
	jal	0x192048
	sw	$16,408($22)
	move	$5,$16
	jal	0x192c40
	move	$4,$2
	lbu	$6,576($23)
	lui	$14,0x37
	addu	$4,$16,$2
	addiu	$5,$14,19424
	jal	0x192cc0
	addiu	$6,$6,1
.L002a70c4:
	lw	$12,32($29)
	li	$16,872
	lui	$17,0x36
	lw	$5,36($29)
	mult	$16,$12,$16
	lw	$15,-2572($17)
	lui	$13,0x36
	lui	$14,0x36
	lw	$7,-3768($13)
	li	$9,2
	lw	$8,-3568($14)
	li	$10,-1
	addu	$15,$15,$16
	sw	$0,0($29)
	lui	$12,0x36
	addiu	$22,$15,436
	lw	$6,-3764($12)
	li	$11,-1
	jal	0x28d980
	move	$4,$22
	jal	0x139620
	lw	$4,16($29)
	lw	$5,40($29)
	move	$4,$22
	jal	0x138c68
	lw	$6,44($29)
	lw	$5,-2572($17)
	move	$4,$22
	jal	0x28dcc0
	addu	$5,$5,$16
	lui	$14,0x6000
	li	$13,1
	ori	$14,$14,0x8
	sw	$13,432($22)
	li	$15,3
	sw	$14,420($22)
	bnez	$18,.L002a7250
	sw	$15,428($22)
	lbu	$15,576($23)
	lui	$13,0x37
	addiu	$13,$13,19456
	sll	$15,$15,0x1
	addu	$15,$15,$13
	lhu	$4,0($15)
.L002a7174:
	jal	0x192048
	nop
	sw	$2,408($22)
.L002a7180:
	lw	$12,32($29)
.L002a7184:
	lui	$14,0x36
	li	$15,408
	lw	$7,-3768($14)
	mult	$15,$12,$15
	lui	$13,0x36
	lw	$14,16($29)
	li	$9,2
	lw	$6,-3764($13)
	li	$10,-1
	move	$11,$0
	addu	$15,$14,$15
	lw	$12,36($29)
	lui	$13,0x36
	li	$14,0xa998
	addu	$16,$15,$14
	lw	$8,-3568($13)
	addiu	$5,$12,2
	jal	0x28d8c0
	move	$4,$16
	move	$4,$16
	jal	0x28dcc0
	move	$5,$22
	beqz	$30,.L002a7200
	lw	$15,32($29)
	jal	0x2abc60
	move	$4,$18
	beqz	$2,.L002a71fc
	move	$4,$16
	jal	0x138c10
	li	$5,58
.L002a71fc:
	lw	$15,32($29)
.L002a7200:
	addiu	$15,$15,1
	sw	$15,32($29)
.L002a7208:
	lw	$12,48($29)
	addiu	$18,$18,1
	slti	$15,$18,4
	addiu	$12,$12,2
	bnez	$15,.L002a6f84
	sw	$12,48($29)
	ld	$16,64($29)
	ld	$17,72($29)
	ld	$18,80($29)
	ld	$19,88($29)
	ld	$20,96($29)
	ld	$21,104($29)
	ld	$22,112($29)
	ld	$23,120($29)
	ld	$30,128($29)
	ld	$31,136($29)
	jr	$31
	addiu	$29,$29,144
.L002a7250:
	lw	$12,32($29)
	lw	$15,-2572($17)
	sll	$14,$12,0x5
	addu	$15,$15,$14
	addiu	$16,$15,3488
	bne	$18,$13,.L002a72ac
	sw	$16,408($22)
	move	$6,$21
	li	$7,60
.L002a7274:
	lw	$13,28($29)
	beqzl	$13,.L002a7298
	lui	$5,0x37
	lui	$5,0x37
	move	$4,$16
	jal	0x192cc0
	addiu	$5,$5,19432
	b	.L002a7184
	lw	$12,32($29)
.L002a7298:
	move	$4,$16
	jal	0x192cc0
	addiu	$5,$5,19424
	b	.L002a7184
	lw	$12,32($29)
.L002a72ac:
	li	$15,2
	bne	$18,$15,.L002a72c8
	lui	$15,0x36
	lui	$15,0x36
	move	$6,$20
	b	.L002a7274
	lb	$7,-2564($15)
.L002a72c8:
	move	$6,$19
	b	.L002a7274
	lb	$7,-2563($15)
.L002a72d4:
	jal	0x192048
	lhu	$4,0($15)
	b	.L002a70c4
	sw	$2,408($22)
.L002a72e4:
	lw	$14,28($29)
	beqz	$14,.L002a7180
	li	$4,14072
	b	.L002a7174
	nop
.L002a72f8:
	lui	$15,0x37
	b	.L002a6fd4
	lw	$9,19440($15)
	.end func_002a6e50
	.size func_002a6e50, .-func_002a6e50
