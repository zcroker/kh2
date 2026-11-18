# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3880).
# Both functions were 6-difference near misses in C/C++ after many sessions; see attempts.tsv
# and the best/ADDR_w3880.cpp drafts. Replace with C/C++ after 100%.
#   func_001652c8: ray/box triangle query (sched1 places the spilled t1/t2 parameter copies after the box loads)
# Split out of batch_w3880.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001652c8,"ax",@progbits
	.align 2
	.globl func_001652c8
	.type func_001652c8, @function
	.ent func_001652c8
func_001652c8:
	addiu	$29,$29,-2416
	sd	$31,2392($29)
	sw	$9,2292($29)
	sw	$10,2296($29)
	sd	$16,2320($29)
	sd	$17,2328($29)
	sd	$18,2336($29)
	addiu	$16,$29,32
	sd	$23,2376($29)
	move	$17,$4
	sd	$30,2384($29)
	addiu	$18,$4,144
	sd	$19,2344($29)
	move	$23,$7
	sd	$20,2352($29)
	move	$30,$8
	sd	$21,2360($29)
	move	$4,$29
	sd	$22,2368($29)
	swc1	$f22,2408($29)
	swc1	$f21,2404($29)
	swc1	$f20,2400($29)
	sw	$5,2288($29)
	lw	$3,20($6)
	lw	$15,0($6)
	move	$5,$18
	lw	$14,4($6)
	lw	$13,8($6)
	lw	$12,12($6)
	sw	$11,2300($29)
	lw	$11,16($6)
	sw	$15,0($29)
	sw	$14,4($29)
	sw	$13,8($29)
	sw	$12,12($29)
	sw	$11,16($29)
	jal	0x1449a8
	sw	$3,20($29)
	jal	0x144e30
	move	$4,$16
	jal	0x141970
	move	$4,$17
	move	$6,$2
	move	$4,$16
	jal	0x144e50
	move	$5,$29
	sh	$0,48($29)
	addiu	$5,$29,64
	jal	0x141980
	move	$4,$17
	move	$4,$17
	li	$5,1024
	li	$6,1024
	move	$7,$0
	jal	0x141c18
	move	$8,$0
	move	$6,$16
	addiu	$7,$29,48
	move	$4,$17
	move	$5,$0
	jal	0x141c38
	li	$8,15
	lhu	$15,48($29)
	beqz	$15,.L00165678
	move	$2,$0
	lui	$14,0x37
	lw	$15,2288($29)
	addiu	$14,$14,-19228
	sw	$0,2304($29)
	addiu	$19,$29,2192
	lwc1	$f22,0($14)
	lq	$8,0($15)
	sq	$8,0($19)
	addiu	$16,$29,2208
	lqc2	vf5,0($19)
	lqc2	vf1,0($18)
	lqc2	vf2,16($18)
	lqc2	vf3,32($18)
	lqc2	vf4,48($18)
	vmulax.wxyz	ACC,$vf1,$vf5x
	vmadday.wxyz	ACC,$vf2,$vf5y
	vmaddaz.wxyz	ACC,$vf3,$vf5z
	vmaddw.wxyz	vf5,$vf4,$vf5w
	sqc2	vf5,0($16)
	beq	$19,$16,.L0016542c
	lhu	$15,48($29)
	lq	$8,0($16)
	sq	$8,0($19)
	lhu	$15,48($29)
.L0016542c:
	lw	$14,2304($29)
	slt	$15,$14,$15
	beqz	$15,.L001655a4
	move	$20,$0
	lui	$15,0x37
	addiu	$18,$29,2144
	addiu	$15,$15,-19224
	addiu	$22,$29,2176
	lwc1	$f21,0($15)
	lw	$15,60($17)
.L00165454:
	sll	$14,$20,0x1
	lw	$5,12($17)
	move	$4,$17
	addu	$14,$14,$15
	addiu	$6,$29,2112
	lhu	$21,0($14)
	sll	$15,$21,0x4
	jal	0x141988
	addu	$5,$5,$15
	move	$4,$17
	addiu	$5,$29,2112
	move	$6,$19
	move	$7,$18
	addiu	$8,$29,2160
	jal	0x164d60
	move	$9,$22
	beqz	$2,.L0016558c
	addiu	$14,$29,2224
	beq	$14,$19,.L001654b0
	addiu	$13,$29,2240
	lq	$8,0($19)
	sq	$8,0($14)
	addiu	$13,$29,2240
.L001654b0:
	beq	$13,$18,.L001654c4
	addiu	$15,$29,2256
	lq	$8,0($18)
	sq	$8,0($13)
	addiu	$15,$29,2256
.L001654c4:
	beql	$15,$14,.L001654d8
	addiu	$15,$29,2272
	lq	$8,0($14)
	sq	$8,0($15)
	addiu	$15,$29,2272
.L001654d8:
	lqc2	vf1,0($13)
	lqc2	vf2,0($14)
	vsub.wxyz	vf1,$vf1,$vf2
	sqc2	vf1,0($16)
	beql	$15,$16,.L001654fc
	swc1	$f21,2284($29)
	lq	$8,0($16)
	sq	$8,0($15)
	swc1	$f21,2284($29)
.L001654fc:
	swc1	$f21,2268($29)
	lqc2	vf1,0($15)
	vmul.xyz	vf1,$vf1,$vf1
	vaddy.x	vf1,$vf1,$vf1y
	vaddz.x	vf1,$vf1,$vf1z
	vsqrt	Q,$vf1x
	vwaitq
	cfc2.ni	$8,$vi22
	mtc1	$8,$f20
	lw	$5,2288($29)
	move	$4,$17
	lw	$6,2296($29)
	jal	0x164c70
	move	$7,$18
	add.s	$f20,$f20,$f0
	c.le.s	$f20,$f22
	bc1f	.L00165590
	lhu	$15,48($29)
	beq	$23,$18,.L00165554
	mov.s	$f22,$f20
	lq	$8,0($18)
	sq	$8,0($23)
.L00165554:
	addiu	$14,$29,2160
	beq	$30,$14,.L0016556c
	lw	$15,2292($29)
	lq	$8,0($14)
	sq	$8,0($30)
	lw	$15,2292($29)
.L0016556c:
	beq	$15,$22,.L00165580
	lw	$14,2300($29)
	lq	$8,0($22)
	sq	$8,0($15)
	lw	$14,2300($29)
.L00165580:
	li	$15,1
	sh	$21,0($14)
	sw	$15,2304($29)
.L0016558c:
	lhu	$15,48($29)
.L00165590:
	addiu	$20,$20,1
	slt	$15,$20,$15
	bnezl	$15,.L00165454
	lw	$15,60($17)
	lw	$14,2304($29)
.L001655a4:
	li	$15,1
	bne	$14,$15,.L00165664
	move	$6,$19
	addiu	$4,$17,80
	lqc2	vf5,0($23)
	lqc2	vf1,0($4)
	lqc2	vf2,16($4)
	lqc2	vf3,32($4)
	lqc2	vf4,48($4)
	vmulax.wxyz	ACC,$vf1,$vf5x
	vmadday.wxyz	ACC,$vf2,$vf5y
	vmaddaz.wxyz	ACC,$vf3,$vf5z
	vmaddw.wxyz	vf5,$vf4,$vf5w
	sqc2	vf5,0($16)
	beq	$23,$16,.L001655ec
	nop
	lq	$8,0($16)
	sq	$8,0($23)
.L001655ec:
	lqc2	vf5,0($30)
	lqc2	vf1,0($4)
	lqc2	vf2,16($4)
	lqc2	vf3,32($4)
	lqc2	vf4,48($4)
	vmulax.wxyz	ACC,$vf1,$vf5x
	vmadday.wxyz	ACC,$vf2,$vf5y
	vmaddaz.wxyz	ACC,$vf3,$vf5z
	vmaddw.wxyz	vf5,$vf4,$vf5w
	sqc2	vf5,0($16)
	beq	$30,$16,.L00165628
	lw	$15,2292($29)
	lq	$8,0($16)
	sq	$8,0($30)
	lw	$15,2292($29)
.L00165628:
	lqc2	vf5,0($15)
	lqc2	vf1,0($4)
	lqc2	vf2,16($4)
	lqc2	vf3,32($4)
	lqc2	vf4,48($4)
	vmulax.wxyz	ACC,$vf1,$vf5x
	vmadday.wxyz	ACC,$vf2,$vf5y
	vmaddaz.wxyz	ACC,$vf3,$vf5z
	vmaddw.wxyz	vf5,$vf4,$vf5w
	sqc2	vf5,0($16)
	beq	$15,$16,.L00165664
	move	$6,$19
	lq	$8,0($16)
	sq	$8,0($15)
	move	$6,$19
.L00165664:
	addiu	$14,$29,2160
.L00165668:
	beq	$14,$6,.L00165678
	lw	$2,2304($29)
	b	.L00165668
	addiu	$6,$6,-16
.L00165678:
	ld	$16,2320($29)
	ld	$17,2328($29)
	ld	$18,2336($29)
	ld	$19,2344($29)
	ld	$20,2352($29)
	ld	$21,2360($29)
	ld	$22,2368($29)
	ld	$23,2376($29)
	ld	$30,2384($29)
	ld	$31,2392($29)
	lwc1	$f22,2408($29)
	lwc1	$f21,2404($29)
	lwc1	$f20,2400($29)
	jr	$31
	addiu	$29,$29,2416
	.end func_001652c8
	.size func_001652c8, .-func_001652c8
