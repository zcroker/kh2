# Kept as assembly (last step of the match ladder): func_0010fb10 (camera target pick, _nsa C++ draft 13 lines off: loop
# preheader giv copy, cand store base t6/t7, post-loop &tab[k].t remat) and func_00212338 (model draw, sibling of 00215f28/0021aee8,
# _nsa C draft ~86% inline asm and still ~12 lines off). C drafts: coord/best/0010fb10_w3905.cpp, coord/best/00212338_w3905.c.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0010fb10,"ax",@progbits
	.align 3
	.globl func_0010fb10
	.type func_0010fb10, @function
	.ent func_0010fb10
func_0010fb10:
	addiu	$29,$29,-128
	move	$14,$0
	sd	$18,64($29)
	sd	$16,48($29)
	sd	$17,56($29)
	sd	$19,72($29)
	sd	$20,80($29)
	sd	$21,88($29)
	sd	$22,96($29)
	sd	$23,104($29)
	sd	$30,112($29)
	sd	$31,120($29)
	lw	$15,3300($4)
	beqz	$15,.L0010fdfc
	move	$18,$4
	jal	0x10f8d0
	nop
	bnez	$2,.L0010fdfc
	move	$14,$0
	lw	$15,2940($18)
	move	$4,$18
	lw	$14,3168($18)
	ori	$15,$15,0x20
	sw	$14,36($29)
	lw	$14,3172($18)
	sw	$14,40($29)
	jal	0x10eee8
	sw	$15,2940($18)
	lw	$4,2912($18)
	jal	0x1137e0
	sw	$0,3304($18)
	lw	$4,2912($18)
	jal	0x1137e8
	move	$21,$2
	sw	$2,44($29)
	lui	$15,0x3b
	lb	$14,-28016($15)
	bnez	$14,.L0010fbe4
	move	$4,$29
	lui	$15,0x3b
	li	$17,31
	addiu	$16,$15,-28008
	li	$19,-1
	addiu	$4,$16,4
.L0010fbc0:
	addiu	$17,$17,-1
	jal	0x190128
	addiu	$16,$16,28
	bne	$17,$19,.L0010fbc0
	addiu	$4,$16,4
	li	$14,1
	lui	$15,0x3b
	sb	$14,-28016($15)
	move	$4,$29
.L0010fbe4:
	jal	0x190128
	move	$20,$0
	move	$19,$0
.L0010fbf0:
	blez	$21,.L0010fd30
	move	$22,$0
	lw	$16,44($29)
	lui	$15,0x3b
	move	$30,$18
	addiu	$15,$15,-28008
	move	$18,$15
	move	$17,$16
	move	$23,$0
.L0010fc14:
	lw	$15,4($17)
	beqzl	$15,.L0010fd1c
	addiu	$19,$19,1
	beqz	$20,.L0010fe88
	li	$15,1
	beql	$20,$15,.L0010fe70
	lw	$15,0($17)
	lw	$15,16($17)
.L0010fc34:
	beqz	$15,.L0010fc64
	nop
	lw	$15,8($15)
	blez	$15,.L0010fc64
	nop
	lw	$4,1164($30)
	beqz	$4,.L0010fc64
	nop
	jal	0x1a1de0
	nop
	bnezl	$2,.L0010fd1c
	addiu	$19,$19,1
.L0010fc64:
	jal	0x190128
	move	$4,$29
	lw	$14,8($16)
	andi	$15,$14,0x1
	andi	$15,$15,0xff
	beqz	$15,.L0010fe64
	sra	$15,$14,0x1
	lw	$12,2912($30)
	lw	$14,4($16)
	addu	$15,$12,$15
	srl	$14,$14,0x2
	lw	$13,0($15)
	sll	$14,$14,0x2
	addu	$14,$14,$13
	lw	$14,0($14)
.L0010fca0:
	lw	$4,8($16)
	move	$5,$16
	move	$6,$29
	addiu	$7,$29,32
	sra	$4,$4,0x1
	li	$8,1
	jalr	$14
	addu	$4,$12,$4
	beqz	$2,.L0010fd18
	slti	$15,$22,32
	beqz	$15,.L0010fd18
	lui	$14,0x3b
	sw	$16,0($18)
	addiu	$14,$14,-28004
	addiu	$22,$22,1
	lw	$15,0($29)
	addu	$13,$23,$14
	addiu	$23,$23,28
	sw	$15,0($13)
	lw	$14,16($29)
	sw	$14,16($13)
	lw	$15,4($29)
	sw	$15,4($13)
	lw	$14,8($29)
	sw	$14,8($13)
	lw	$15,12($29)
	sw	$15,12($13)
	lw	$14,32($29)
	sw	$14,24($18)
	addiu	$18,$18,28
.L0010fd18:
	addiu	$19,$19,1
.L0010fd1c:
	addiu	$17,$17,36
	slt	$15,$19,$21
	bnez	$15,.L0010fc14
	addiu	$16,$16,36
	move	$18,$30
.L0010fd30:
	blezl	$22,.L0010fe40
	addiu	$20,$20,1
	jal	0x10f648
	move	$4,$22
	lui	$15,0x3b
	addiu	$15,$15,-28008
	addiu	$13,$15,4
	li	$15,28
	mult	$2,$2,$15
	lui	$15,0x3b
	addiu	$15,$15,-28008
	addu	$14,$2,$15
	lw	$16,0($14)
	lui	$15,0x3b
	addiu	$15,$15,-27984
	lw	$4,8($16)
	addu	$17,$2,$15
	andi	$15,$4,0x1
	andi	$15,$15,0xff
	beqz	$15,.L0010fe30
	addu	$6,$2,$13
	lw	$12,2912($18)
	sra	$15,$4,0x1
	lw	$14,4($16)
	addu	$15,$12,$15
	srl	$14,$14,0x2
	lw	$13,0($15)
	sll	$14,$14,0x2
	addu	$14,$14,$13
	lw	$14,0($14)
.L0010fda8:
	sra	$4,$4,0x1
	move	$5,$16
	addu	$4,$12,$4
	move	$7,$17
	jalr	$14
	move	$8,$0
	lw	$15,0($16)
	andi	$15,$15,0x1
	bnezl	$15,.L0010fde8
	sw	$0,3304($18)
	move	$4,$18
	jal	0x10ef28
	move	$5,$16
	lw	$15,3304($18)
	addiu	$15,$15,1
	sw	$15,3304($18)
.L0010fde8:
	lw	$6,0($17)
	move	$4,$18
	jal	0x10eed8
	move	$5,$16
	li	$14,1
.L0010fdfc:
	ld	$16,48($29)
	move	$2,$14
	ld	$17,56($29)
	ld	$18,64($29)
	ld	$19,72($29)
	ld	$20,80($29)
	ld	$21,88($29)
	ld	$22,96($29)
	ld	$23,104($29)
	ld	$30,112($29)
	ld	$31,120($29)
	jr	$31
	addiu	$29,$29,128
.L0010fe30:
	lw	$14,4($16)
	b	.L0010fda8
	lw	$12,2912($18)
	nop
.L0010fe40:
	slti	$15,$20,2
	bnez	$15,.L0010fbf0
	move	$19,$0
	lw	$14,40($29)
	sw	$14,3172($18)
	lw	$15,36($29)
	move	$14,$0
	b	.L0010fdfc
	sw	$15,3168($18)
.L0010fe64:
	lw	$14,4($16)
	b	.L0010fca0
	lw	$12,2912($30)
.L0010fe70:
	andi	$15,$15,0x20
	beqzl	$15,.L0010fd1c
	addiu	$19,$19,1
	b	.L0010fc34
	lw	$15,16($17)
	nop
.L0010fe88:
	lw	$15,0($17)
	andi	$15,$15,0x10
	bnezl	$15,.L0010fc34
	lw	$15,16($17)
	b	.L0010fd1c
	addiu	$19,$19,1
	.end func_0010fb10
	.size func_0010fb10, .-func_0010fb10
	.section .text.func_00212338,"ax",@progbits
	.align 3
	.globl func_00212338
	.type func_00212338, @function
	.ent func_00212338
func_00212338:
	addiu	$29,$29,-96
	sq	$16,16($29)
	sq	$17,32($29)
	sq	$18,48($29)
	move	$16,$4
	sd	$19,64($29)
	sd	$20,72($29)
	sd	$21,80($29)
	sd	$22,88($29)
	lui	$11,0x36
	lui	$13,0x36
	lw	$12,-26752($11)
	addiu	$13,$13,-26744
	sll	$15,$12,0x2
	addu	$15,$15,$13
	addiu	$12,$12,1
	lw	$25,0($15)
	sll	$14,$12,0x2
	addu	$14,$14,$13
	sw	$12,-26752($11)
	addiu	$15,$25,10240
	addiu	$22,$25,768
	sw	$15,0($14)
	lq	$2,0($5)
	sq	$2,0($22)
	addiu	$14,$25,784
	addiu	$15,$5,16
	lq	$2,0($15)
	sq	$2,0($14)
	addiu	$13,$25,800
	addiu	$15,$5,32
	lq	$2,0($15)
	sq	$2,0($13)
	addiu	$14,$25,816
	addiu	$15,$5,48
	lq	$2,0($15)
	sq	$2,0($14)
	addiu	$5,$5,64
	addiu	$15,$25,832
	lq	$2,0($5)
	sq	$2,0($15)
	sq	$0,480($25)
	lw	$15,52($22)
	lui	$14,0xfff
	ori	$14,$14,0xffc0
	lw	$13,56($22)
	addiu	$15,$15,63
	and	$15,$15,$14
	bnez	$13,.L00213e9c
	sw	$15,52($22)
	lw	$15,8($4)
	addu	$14,$4,$15
.L00212408:
	lw	$15,60($22)
	bnezl	$15,.L00212420
	sw	$15,60($22)
	lw	$15,12($16)
	addu	$15,$16,$15
	sw	$15,60($22)
.L00212420:
	sw	$14,56($22)
	lui	$15,0x35
	lw	$14,11320($15)
	beqzl	$14,.L002124a0
	lw	$15,24($22)
	lbu	$15,24($22)
	lbu	$14,25($22)
	mtc1	$15,$f1
	lbu	$13,26($22)
	lui	$15,0x37
	cvt.s.w	$f1,$f1
	addiu	$15,$15,2176
	mtc1	$14,$f3
	lwc1	$f0,0($15)
	mtc1	$13,$f2
	lui	$15,0x37
	mula.s	$f1,$f0
	addiu	$15,$15,2180
	cvt.s.w	$f3,$f3
	lwc1	$f0,0($15)
	cvt.s.w	$f2,$f2
	lui	$15,0x37
	addiu	$15,$15,2184
	madda.s	$f3,$f0
	lwc1	$f1,0($15)
	madd.s	$f2,$f2,$f1
	cvt.w.s	$f0,$f2
	mfc1	$15,$f0
	sb	$15,26($22)
	sb	$15,24($22)
	sb	$15,25($22)
	lw	$15,24($22)
.L002124a0:
	move	$2,$15
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,vf31
	lui	$3,0x3c00
	pextlw	$3,$3,$3
	pextlw	$3,$3,$3
	qmtc2	$3,vf30
	vitof0.wxyz	vf31,vf31
	vmul.wxyz	vf31,vf31,vf30
	sqc2	vf31,848($25)
	addiu	$14,$22,28
	lw	$2,0($14)
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,vf31
	vitof0.wxyz	vf31,vf31
	sqc2	vf31,880($25)
	lw	$20,4($22)
	lui	$14,0x36
	addiu	$14,$14,-28400
	sw	$20,916($25)
	lh	$15,18($16)
	lw	$13,4($22)
	sll	$15,$15,0x4
	addu	$21,$13,$15
	sw	$21,924($25)
	vmove.wxyz	vf28,vf0
	lui	$9,0xffff
	dsrl32	$9,$9,0x0
	lw	$2,32($22)
	lqc2	vf24,0($2)
	lqc2	vf25,16($2)
	lqc2	vf26,32($2)
	lqc2	vf27,48($2)
	lhu	$10,18($16)
	lwu	$8,56($22)
	lw	$2,0($22)
	lqc2	vf16,0($14)
	andi	$3,$2,0x200
	bnez	$3,.L0021254c
	nop
	lqc2	vf16,16($14)
.L0021254c:
	lqc2	vf17,32($14)
	andi	$3,$2,0x100
	bnez	$3,.L00212560
	nop
	lqc2	vf17,48($14)
.L00212560:
	lui	$2,0x3c00
	qmtc2	$2,vf18
	lwu	$7,916($25)
	lw	$2,68($22)
	bnez	$2,.L0021263c
	lwu	$6,924($25)
	lw	$2,32($22)
	sw	$2,68($22)
	blez	$10,.L0021271c
.L00212584:
	lh	$2,4($8)
	and	$2,$2,$9
	lh	$3,2($8)
	lh	$4,0($8)
	and	$4,$4,$9
	dsll32	$3,$3,0x0
	or	$3,$3,$4
	pcpyld	$2,$2,$3
	qmtc2	$2,vf29
	vitof0.xyz	vf28,vf29
	vmulax.wxyz	ACC,vf24,vf28x
	vmadday.wxyz	ACC,vf25,vf28y
	vmaddaz.wxyz	ACC,vf26,vf28z
	vmaddw.wxyz	vf31,vf27,vf28w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf31w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	beqz	$2,.L002125e0
	sqc2	vf0,0($7)
	b	.L00212620
.L002125e0:
	vmulx.w	vf2,vf31,vf17x
	vmulay.w	ACC,vf0,vf16y
	vmulx.w	vf1,vf0,vf16x
	vmaddw.w	vf1,vf1,vf31w
	vminiz.w	vf1,vf1,vf16z
	vmaxw.w	vf1,vf1,vf16w
	vaddy.w	vf2,vf2,vf17y
	vminiz.w	vf2,vf2,vf17z
	vmaxw.w	vf2,vf2,vf17w
	vmulx.w	vf2,vf2,vf18x
	vmr32.z	vf1,vf2
	vwaitq
	vmulq.xyz	vf29,vf31,Q
	vmulq.w	vf29,vf0,Q
	sqc2	vf29,0($7)
	sqc2	vf1,0($6)
.L00212620:
	addi	$10,$10,-1
	addiu	$8,$8,6
	addiu	$6,$6,16
	bgtz	$10,.L00212584
	addiu	$7,$7,16
	b	.L0021271c
	nop
.L0021263c:
	lqc2	vf20,0($2)
	lqc2	vf21,16($2)
	lqc2	vf22,32($2)
	lqc2	vf23,48($2)
	blez	$10,.L0021271c
.L00212650:
	lh	$2,4($8)
	and	$2,$2,$9
	lh	$3,2($8)
	lh	$4,0($8)
	and	$4,$4,$9
	dsll32	$3,$3,0x0
	or	$3,$3,$4
	pcpyld	$2,$2,$3
	qmtc2	$2,vf29
	vitof0.xyz	vf28,vf29
	vmulax.wxyz	ACC,vf24,vf28x
	vmadday.wxyz	ACC,vf25,vf28y
	vmaddaz.wxyz	ACC,vf26,vf28z
	vmaddw.wxyz	vf31,vf27,vf28w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf31w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	beqz	$2,.L002126ac
	sqc2	vf0,0($7)
	b	.L00212708
.L002126ac:
	vmulx.w	vf2,vf31,vf17x
	vmulay.w	ACC,vf0,vf16y
	vmulx.w	vf1,vf0,vf16x
	vmaddw.w	vf1,vf1,vf31w
	vmulax.wxyz	ACC,vf20,vf28x
	vmadday.wxyz	ACC,vf21,vf28y
	vmaddaz.wxyz	ACC,vf22,vf28z
	vmaddw.wxyz	vf30,vf23,vf28w
	vwaitq
	vmulq.xyz	vf29,vf31,Q
	vmulq.w	vf29,vf0,Q
	vdiv	Q,vf0w,vf30w
	vminiz.w	vf1,vf1,vf16z
	vmaxw.w	vf1,vf1,vf16w
	vaddy.w	vf2,vf2,vf17y
	vminiz.w	vf2,vf2,vf17z
	vmaxw.w	vf2,vf2,vf17w
	vmulx.w	vf2,vf2,vf18x
	vmr32.z	vf1,vf2
	vwaitq
	vmulq.z	vf29,vf30,Q
	sqc2	vf29,0($7)
	sqc2	vf1,0($6)
.L00212708:
	addi	$10,$10,-1
	addiu	$8,$8,6
	addiu	$6,$6,16
	bgtz	$10,.L00212650
	addiu	$7,$7,16
.L0021271c:
	li	$15,5
	lw	$13,4($16)
	dsll32	$15,$15,0x1c
	lui	$14,0xe
	ori	$15,$15,0x8001
	ori	$14,$14,0xeeee
	sd	$15,272($25)
	sd	$14,280($25)
	li	$15,6
	sd	$15,296($25)
	lh	$15,8($22)
	beqz	$15,.L00213e8c
	addu	$19,$16,$13
	lbu	$15,8($22)
	sw	$15,304($25)
	lbu	$14,9($22)
.L0021275c:
	sw	$14,308($25)
	lui	$15,0x1db
	addiu	$15,$15,-29632
	li	$14,66
	sd	$14,312($25)
	lq	$14,64($15)
	lui	$15,0x1db
	sq	$14,320($25)
	addiu	$15,$15,-29776
	lq	$14,48($15)
	sq	$14,336($25)
	lw	$15,0($16)
	andi	$15,$15,0x4
	beqz	$15,.L00213e84
	li	$15,5
	sd	$0,352($25)
.L0021279c:
	li	$15,8
	lui	$14,0x36
	sd	$15,360($25)
	addiu	$14,$14,-26256
	lqc2	vf27,48($14)
	lqc2	vf28,64($14)
	lqc2	vf29,80($14)
	lui	$15,0x1db
	lui	$13,0x1000
	addiu	$15,$15,-15024
	ori	$13,$13,0xd000
	sw	$15,384($25)
.L002127cc:
	lw	$14,0($13)
	andi	$15,$14,0x100
	nop
	nop
	nop
	bnez	$15,.L002127cc
	nop
	nop
	nop
	nop
	nop
	lb	$14,1($19)
.L002127fc:
	li	$15,2
	beq	$14,$15,.L00213880
	slti	$15,$14,3
	beqz	$15,.L00212cdc
	li	$15,4
	beqz	$14,.L00212880
	lui	$15,0x2000
	lui	$13,0x1db
.L0021281c:
	lw	$11,480($25)
	addiu	$13,$13,-29488
	lq	$16,16($29)
	lw	$15,20($13)
	lui	$10,0x36
	lw	$12,16($13)
	addu	$15,$15,$11
	lw	$14,-26752($10)
	sw	$15,20($13)
	addiu	$14,$14,-1
	lq	$17,32($29)
	lw	$15,484($25)
	lq	$18,48($29)
	addu	$12,$12,$15
	sw	$14,-26752($10)
	sw	$12,16($13)
	ld	$19,64($29)
	lw	$2,820($25)
	ld	$20,72($29)
	ld	$21,80($29)
	addiu	$2,$2,64
	ld	$22,88($29)
	jr	$31
	addiu	$29,$29,96
	nop
.L00212880:
	lui	$14,0x37
	ori	$15,$15,0x9
	sd	$15,256($25)
	ld	$15,2128($14)
	sd	$15,496($25)
	lui	$14,0x1db
	addiu	$14,$14,-29488
	lui	$15,0x4141
	ori	$15,$15,0x41ee
	sd	$15,504($25)
	lh	$24,2($19)
	lw	$15,4($14)
	addiu	$19,$19,16
	addu	$15,$15,$24
	sw	$15,4($14)
	sq	$16,1008($25)
	sq	$17,992($25)
	sq	$18,976($25)
	lw	$18,768($25)
	move	$17,$20
	li	$12,4096
	lui	$10,0xffff
	dsrl32	$10,$10,0x0
	dsll32	$11,$10,0x0
	or	$11,$11,$10
	pcpyld	$11,$10,$11
	lbu	$2,503($25)
	srl	$2,$2,0x4
	addiu	$2,$2,2
	sh	$2,706($25)
	sll	$2,$2,0x4
	sh	$2,704($25)
	move	$13,$0
	lui	$2,0x100
	lui	$3,0xffff
	ori	$3,$3,0xffff
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	pextlb	$3,$0,$3
	pextlh	$3,$0,$3
	qmtc2	$2,vf19
	qmtc2	$3,vf20
	vitof0.wxyz	vf19,vf19
	vitof0.wxyz	vf20,vf20
.L00212930:
	beqz	$24,.L00212c94
	andi	$13,$13,0x1
	sll	$3,$13,0xc
	add	$15,$25,$3
	addi	$15,$15,2048
	move	$14,$0
.L00212948:
	move	$9,$0
	lhu	$2,12($19)
	lhu	$3,14($19)
	lhu	$4,16($19)
	dsll	$2,$2,0x4
	dsll	$3,$3,0x4
	dsll	$4,$4,0x4
	add	$2,$2,$17
	add	$3,$3,$17
	add	$4,$4,$17
	lqc2	vf15,0($2)
	lqc2	vf16,0($3)
	lqc2	vf17,0($4)
	andi	$2,$18,0x10
	beqz	$2,.L002129b0
	nop
	vsub.wxyz	vf7,vf15,vf16
	vsub.wxyz	vf8,vf17,vf16
	vopmula.xyz	ACC,vf7,vf8
	vopmsub.xyz	vf9,vf8,vf7
	vftoi4.z	vf9,vf9
	qmfc2	$6,vf9
	pextuw	$2,$0,$6
	sll	$2,$2,0x0
	bgez	$2,.L00212bd4
	nop
.L002129b0:
	move	$8,$0
	vsub.xyz	vf1,vf15,vf27
	vsub.xyz	vf2,vf16,vf27
	vsub.xyz	vf3,vf17,vf27
	vnop
	vmax.xyz	vf5,vf1,vf2
	vmax.xyz	vf5,vf5,vf3
	vmini.xyz	vf6,vf1,vf2
	vmini.xyz	vf6,vf6,vf3
	vclipw.xy	vf5,vf28w
	vclipw.xy	vf6,vf28w
	vclipw.xy	vf5,vf29w
	vclipw.xy	vf6,vf29w
	lui	$2,0x28
	ori	$2,$2,0x514a
	li	$3,2064
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$4,$18
	vclipw.z	vf5,vf27w
	vclipw.z	vf6,vf27w
	and	$4,$4,$2
	bnez	$4,.L00212bd4
	nop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$4,$18
	and	$4,$4,$3
	bnez	$4,.L00212bd4
	nop
	qmfc2	$6,vf21
	lw	$2,0($19)
	lw	$3,4($19)
	lw	$4,8($19)
	pextlb	$2,$0,$2
	pextlb	$3,$0,$3
	pextlb	$4,$0,$4
	pextlh	$2,$0,$2
	pextlh	$3,$0,$3
	pextlh	$4,$0,$4
	qmtc2	$2,vf4
	qmtc2	$3,vf5
	qmtc2	$4,vf6
	lhu	$2,12($19)
	lhu	$3,14($19)
	lhu	$4,16($19)
	dsll	$2,$2,0x4
	dsll	$3,$3,0x4
	dsll	$4,$4,0x4
	add	$2,$2,$21
	add	$3,$3,$21
	add	$4,$4,$21
	lqc2	vf22,0($2)
	lqc2	vf23,0($3)
	lqc2	vf24,0($4)
	lqc2	vf9,880($25)
	lqc2	vf10,848($25)
	vitof0.wxyz	vf4,vf4
	vitof0.wxyz	vf5,vf5
	vitof0.wxyz	vf6,vf6
	vmul.wxyz	vf1,vf4,vf10
	vmul.wxyz	vf2,vf5,vf10
	vmul.wxyz	vf3,vf6,vf10
	vadd.wxyz	vf1,vf1,vf9
	vadd.wxyz	vf2,vf2,vf9
	vadd.wxyz	vf3,vf3,vf9
	vmulz.wxyz	vf1,vf1,vf22z
	vmulz.wxyz	vf2,vf2,vf23z
	vmulz.wxyz	vf3,vf3,vf24z
	vmini.wxyz	vf1,vf1,vf20
	vmini.wxyz	vf2,vf2,vf20
	vmini.wxyz	vf3,vf3,vf20
	vmax.wxyz	vf1,vf1,vf19
	vmax.wxyz	vf2,vf2,vf19
	vmax.wxyz	vf3,vf3,vf19
	vftoi0.wxyz	vf1,vf1
	vftoi0.wxyz	vf2,vf2
	vftoi0.wxyz	vf3,vf3
	sqc2	vf1,64($15)
	sqc2	vf2,96($15)
	sqc2	vf3,128($15)
	vmove.w	vf15,vf22
	vmove.w	vf16,vf23
	vmove.w	vf17,vf24
	vftoi4.wxyz	vf15,vf15
	vftoi4.wxyz	vf16,vf16
	vftoi4.wxyz	vf17,vf17
	qmfc2	$2,vf15
	qmfc2	$3,vf16
	qmfc2	$4,vf17
	sqc2	vf15,80($15)
	sqc2	vf16,112($15)
	sqc2	vf17,144($15)
	paddw	$2,$2,$3
	paddw	$2,$2,$4
	pexew	$2,$2
	li	$3,0x9000
	pdivw	$2,$3
	lq	$3,256($25)
	lq	$4,496($25)
	lq	$6,304($25)
	lq	$2,352($25)
	sq	$3,0($15)
	sq	$4,16($15)
	sq	$6,32($15)
	sq	$2,48($15)
	pmflo	$2
	sltiu	$3,$2,256
	bnez	$3,.L00212b8c
	slt	$4,$2,$0
	bnez	$4,.L00212b88
	li	$2,255
	b	.L00212b8c
	nop
.L00212b88:
	move	$2,$0
.L00212b8c:
	lhu	$6,704($25)
	multu	$6,$14
	sll	$2,$2,0x4
	lw	$3,384($25)
	add	$2,$3,$2
	sll	$5,$14,0x2
	add	$5,$5,$25
	sw	$2,576($5)
	lw	$3,8($2)
	mflo	$6
	lw	$7,820($25)
	add	$7,$7,$6
	sw	$15,8($2)
	addiu	$2,$2,16
	sw	$7,4($3)
	sw	$2,4($15)
	addi	$15,$15,160
	addi	$14,$14,1
.L00212bd4:
	addi	$24,$24,-1
	addi	$2,$14,-8
	addi	$19,$19,20
	bgez	$2,.L00212bf0
	addi	$3,$3,1
	bgtz	$24,.L00212948
	nop
.L00212bf0:
	lw	$2,480($25)
	add	$2,$2,$14
	sw	$2,480($25)
	beqz	$14,.L00212930
	sll	$4,$13,0xc
	add	$4,$25,$4
	addi	$4,$4,2048
	move	$2,$14
	lhu	$3,704($25)
	addi	$7,$25,576
	lw	$5,820($25)
.L00212c1c:
	addi	$2,$2,-1
	lw	$6,0($7)
	sw	$5,8($6)
	addiu	$7,$7,4
	add	$5,$5,$3
	bgtz	$2,.L00212c1c
	nop
	lui	$2,0x1000
	ori	$2,$2,0xd000
.L00212c40:
	lw	$3,0($2)
	nop
	nop
	nop
	nop
	andi	$3,$3,0x100
	bne	$0,$3,.L00212c40
	lhu	$6,706($25)
	multu	$6,$14
	sw	$4,128($2)
	lw	$5,820($25)
	sw	$5,16($2)
	mflo	$6
	sw	$6,32($2)
	sll	$6,$6,0x4
	add	$6,$6,$5
	sw	$6,820($25)
	li	$4,256
	sw	$4,0($2)
	b	.L00212930
	addi	$13,$13,1
.L00212c94:
	lui	$13,0x1000
	ori	$13,$13,0xd000
.L00212c9c:
	lw	$14,0($13)
	andi	$15,$14,0x100
	nop
	nop
	nop
	bnez	$15,.L00212c9c
	nop
	nop
	nop
	nop
	nop
	lq	$18,976($25)
	lq	$17,992($25)
	lq	$16,1008($25)
	b	.L002127fc
	lb	$14,1($19)
.L00212cdc:
	beq	$14,$15,.L002133a0
	li	$15,6
	bne	$14,$15,.L0021281c
	lui	$13,0x1db
	lui	$15,0x2000
	li	$14,-16135
	ori	$15,$15,0x10
	dsll32	$14,$14,0xe
	sd	$15,256($25)
	ori	$14,$14,0x8001
	sd	$14,496($25)
	lui	$12,0x36
	lui	$15,0x37
	addiu	$12,$12,-28288
	ld	$14,2168($15)
	sd	$14,504($25)
	lhu	$14,12($22)
	lw	$15,8($19)
	addu	$15,$15,$14
	sw	$15,288($25)
	lhu	$14,14($22)
	li	$15,6
	lw	$13,12($19)
	sll	$14,$14,0x5
	addu	$13,$13,$14
	sd	$15,296($25)
	sw	$13,292($25)
	lw	$14,16($22)
	lw	$15,20($22)
	sq	$0,864($25)
	ld	$2,288($25)
	dsra	$2,$2,0x18
	andi	$3,$2,0x3c
	dsra	$2,$2,0x4
	andi	$4,$2,0x3c
	add	$3,$3,$12
	add	$4,$4,$12
	lw	$3,0($3)
	lw	$4,0($4)
	dsll	$5,$3,0x10
	bnez	$5,.L00212d88
	div	$0,$14,$5
	break	0x7
.L00212d88:
	li	$1,-1
	bne	$5,$1,.L00212da0
	lui	$1,0x8000
	bne	$14,$1,.L00212da0
	nop
	break	0x7
.L00212da0:
	mflo	$14
	mfhi	$5
	dsra	$5,$5,0x4
	bnez	$3,.L00212db8
	div	$0,$5,$3
	break	0x7
.L00212db8:
	li	$1,-1
	bne	$3,$1,.L00212dd0
	lui	$1,0x8000
	bne	$5,$1,.L00212dd0
	nop
	break	0x7
.L00212dd0:
	mflo	$5
	mflo	$5
	sw	$5,864($25)
	dsll	$5,$4,0x10
	bnez	$5,.L00212dec
	div	$0,$15,$5
	break	0x7
.L00212dec:
	li	$1,-1
	bne	$5,$1,.L00212e04
	lui	$1,0x8000
	bne	$15,$1,.L00212e04
	nop
	break	0x7
.L00212e04:
	mflo	$15
	mfhi	$5
	dsra	$5,$5,0x4
	bnez	$4,.L00212e1c
	div	$0,$5,$4
	break	0x7
.L00212e1c:
	li	$1,-1
	bne	$4,$1,.L00212e34
	lui	$1,0x8000
	bne	$5,$1,.L00212e34
	nop
	break	0x7
.L00212e34:
	mflo	$5
	mflo	$5
	sw	$5,868($25)
	lui	$13,0x1db
	lh	$24,2($19)
	lw	$15,-29488($13)
	addu	$15,$15,$24
	sw	$15,-29488($13)
	lw	$2,820($25)
	sw	$2,0($29)
	addiu	$19,$19,16
	sq	$16,1008($25)
	sq	$17,992($25)
	sq	$18,976($25)
	lw	$18,768($25)
	move	$17,$20
	li	$12,4096
	lui	$10,0xffff
	dsrl32	$10,$10,0x0
	dsll32	$11,$10,0x0
	or	$11,$11,$10
	pcpyld	$11,$10,$11
	lbu	$2,503($25)
	srl	$2,$2,0x4
	addiu	$2,$2,2
	sh	$2,706($25)
	sll	$2,$2,0x4
	sh	$2,704($25)
	move	$13,$0
	lui	$2,0x100
	lui	$3,0xffff
	ori	$3,$3,0xffff
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	pextlb	$3,$0,$3
	pextlh	$3,$0,$3
	qmtc2	$2,vf19
	qmtc2	$3,vf20
	vitof0.wxyz	vf19,vf19
	vitof0.wxyz	vf20,vf20
.L00212ed4:
	beqz	$24,.L00213358
	andi	$13,$13,0x1
	sll	$3,$13,0xc
	add	$15,$25,$3
	addi	$15,$15,2048
	move	$14,$0
.L00212eec:
	move	$9,$0
	lhu	$2,16($19)
	lhu	$3,18($19)
	lhu	$4,20($19)
	lhu	$5,22($19)
	dsll	$2,$2,0x4
	dsll	$3,$3,0x4
	dsll	$4,$4,0x4
	dsll	$5,$5,0x4
	add	$2,$2,$17
	add	$3,$3,$17
	add	$4,$4,$17
	add	$5,$5,$17
	lqc2	vf15,0($2)
	lqc2	vf16,0($3)
	lqc2	vf17,0($4)
	lqc2	vf18,0($5)
	andi	$2,$18,0x10
	beqz	$2,.L00212f64
	nop
	vsub.wxyz	vf7,vf15,vf16
	vsub.wxyz	vf8,vf17,vf16
	vopmula.xyz	ACC,vf7,vf8
	vopmsub.xyz	vf9,vf8,vf7
	vftoi4.z	vf9,vf9
	qmfc2	$6,vf9
	pextuw	$2,$0,$6
	sll	$2,$2,0x0
	bgez	$2,.L00213298
	nop
.L00212f64:
	move	$8,$0
	vsub.xyz	vf1,vf15,vf27
	vsub.xyz	vf2,vf16,vf27
	vsub.xyz	vf3,vf17,vf27
	vsub.xyz	vf4,vf18,vf27
	vmax.xyz	vf5,vf1,vf2
	vmax.xyz	vf5,vf5,vf3
	vmax.xyz	vf5,vf5,vf4
	vmini.xyz	vf6,vf1,vf2
	vmini.xyz	vf6,vf6,vf3
	vmini.xyz	vf6,vf6,vf4
	vclipw.xy	vf5,vf28w
	vclipw.xy	vf6,vf28w
	vclipw.xy	vf5,vf29w
	vclipw.xy	vf6,vf29w
	lui	$2,0x28
	ori	$2,$2,0x514a
	li	$3,2064
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$4,$18
	vclipw.z	vf5,vf27w
	vclipw.z	vf6,vf27w
	and	$4,$4,$2
	bnez	$4,.L00213298
	nop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$4,$18
	and	$4,$4,$3
	bnez	$4,.L00213298
	nop
	qmfc2	$6,vf21
	lw	$2,0($19)
	lw	$3,4($19)
	lw	$4,8($19)
	lw	$5,12($19)
	pextlb	$2,$0,$2
	pextlb	$3,$0,$3
	pextlb	$4,$0,$4
	pextlb	$5,$0,$5
	pextlh	$2,$0,$2
	pextlh	$3,$0,$3
	pextlh	$4,$0,$4
	pextlh	$5,$0,$5
	qmtc2	$2,vf5
	qmtc2	$3,vf6
	qmtc2	$4,vf7
	qmtc2	$5,vf8
	lhu	$2,16($19)
	lhu	$3,18($19)
	lhu	$4,20($19)
	lhu	$5,22($19)
	dsll	$2,$2,0x4
	dsll	$3,$3,0x4
	dsll	$4,$4,0x4
	dsll	$5,$5,0x4
	add	$2,$2,$21
	add	$3,$3,$21
	add	$4,$4,$21
	add	$5,$5,$21
	lqc2	vf22,0($2)
	lqc2	vf23,0($3)
	lqc2	vf24,0($4)
	lqc2	vf25,0($5)
	lqc2	vf9,880($25)
	lqc2	vf10,848($25)
	vitof0.wxyz	vf5,vf5
	vitof0.wxyz	vf6,vf6
	vitof0.wxyz	vf7,vf7
	vitof0.wxyz	vf8,vf8
	vmul.wxyz	vf1,vf5,vf10
	vmul.wxyz	vf2,vf6,vf10
	vmul.wxyz	vf3,vf7,vf10
	vmul.wxyz	vf4,vf8,vf10
	vadd.wxyz	vf1,vf1,vf9
	vadd.wxyz	vf2,vf2,vf9
	vadd.wxyz	vf3,vf3,vf9
	vadd.wxyz	vf4,vf4,vf9
	vmulz.wxyz	vf1,vf1,vf22z
	vmulz.wxyz	vf2,vf2,vf23z
	vmulz.wxyz	vf3,vf3,vf24z
	vmulz.wxyz	vf4,vf4,vf25z
	vmini.wxyz	vf1,vf1,vf20
	vmini.wxyz	vf2,vf2,vf20
	vmini.wxyz	vf3,vf3,vf20
	vmini.wxyz	vf4,vf4,vf20
	vmax.wxyz	vf1,vf1,vf19
	vmax.wxyz	vf2,vf2,vf19
	vmax.wxyz	vf3,vf3,vf19
	vmax.wxyz	vf4,vf4,vf19
	vftoi0.wxyz	vf1,vf1
	vftoi0.wxyz	vf2,vf2
	vftoi0.wxyz	vf3,vf3
	vftoi0.wxyz	vf4,vf4
	sqc2	vf1,96($15)
	sqc2	vf2,144($15)
	sqc2	vf3,192($15)
	sqc2	vf4,240($15)
	lq	$6,864($25)
	lw	$2,24($19)
	lw	$3,28($19)
	lw	$4,32($19)
	lw	$5,36($19)
	and	$2,$2,$10
	and	$3,$3,$10
	and	$4,$4,$10
	and	$5,$5,$10
	pextlh	$2,$0,$2
	pextlh	$3,$0,$3
	pextlh	$4,$0,$4
	pextlh	$5,$0,$5
	pcpyld	$2,$12,$2
	pcpyld	$3,$12,$3
	pcpyld	$4,$12,$4
	pcpyld	$5,$12,$5
	paddw	$2,$2,$6
	paddw	$3,$3,$6
	paddw	$4,$4,$6
	paddw	$5,$5,$6
	qmtc2	$2,vf1
	qmtc2	$3,vf2
	qmtc2	$4,vf3
	qmtc2	$5,vf4
	vitof12.xyz	vf1,vf1
	vitof12.xyz	vf2,vf2
	vitof12.xyz	vf3,vf3
	vitof12.xyz	vf4,vf4
	vmulw.xyz	vf5,vf1,vf15w
	vmulw.xyz	vf6,vf2,vf16w
	vmulw.xyz	vf7,vf3,vf17w
	vmulw.xyz	vf8,vf4,vf18w
	sqc2	vf5,80($15)
	sqc2	vf6,128($15)
	sqc2	vf7,176($15)
	sqc2	vf8,224($15)
	vmove.w	vf15,vf22
	vmove.w	vf16,vf23
	vmove.w	vf17,vf24
	vmove.w	vf18,vf25
	vftoi4.wxyz	vf15,vf15
	vftoi4.wxyz	vf16,vf16
	vftoi4.wxyz	vf17,vf17
	vftoi4.wxyz	vf18,vf18
	qmfc2	$2,vf15
	qmfc2	$3,vf16
	qmfc2	$4,vf17
	qmfc2	$5,vf18
	sqc2	vf15,112($15)
	sqc2	vf16,160($15)
	sqc2	vf17,208($15)
	sqc2	vf18,256($15)
	lw	$6,124($15)
	lw	$7,172($15)
	ori	$6,$6,0x8000
	ori	$7,$7,0x8000
	sw	$6,124($15)
	sw	$7,172($15)
	paddw	$2,$2,$3
	paddw	$2,$2,$4
	paddw	$2,$2,$5
	pexew	$2,$2
	li	$3,0xc000
	pdivw	$2,$3
	lq	$3,256($25)
	lq	$4,496($25)
	lq	$5,288($25)
	lq	$6,304($25)
	lq	$2,352($25)
	sq	$3,0($15)
	sq	$4,16($15)
	sq	$5,32($15)
	sq	$6,48($15)
	sq	$2,64($15)
	pmflo	$2
	sltiu	$3,$2,256
	bnez	$3,.L00213250
	slt	$4,$2,$0
	bnez	$4,.L0021324c
	li	$2,255
	b	.L00213250
	nop
.L0021324c:
	move	$2,$0
.L00213250:
	lhu	$6,704($25)
	multu	$6,$14
	sll	$2,$2,0x4
	lw	$3,384($25)
	add	$2,$3,$2
	sll	$5,$14,0x2
	add	$5,$5,$25
	sw	$2,576($5)
	lw	$3,8($2)
	mflo	$6
	lw	$7,820($25)
	add	$7,$7,$6
	sw	$15,8($2)
	addiu	$2,$2,16
	sw	$7,4($3)
	sw	$2,4($15)
	addi	$15,$15,272
	addi	$14,$14,1
.L00213298:
	addi	$24,$24,-1
	addi	$2,$14,-8
	addi	$19,$19,40
	bgez	$2,.L002132b4
	addi	$3,$3,1
	bgtz	$24,.L00212eec
	nop
.L002132b4:
	lw	$2,484($25)
	add	$2,$2,$14
	sw	$2,484($25)
	beqz	$14,.L00212ed4
	sll	$4,$13,0xc
	add	$4,$25,$4
	addi	$4,$4,2048
	move	$2,$14
	lhu	$3,704($25)
	addi	$7,$25,576
	lw	$5,820($25)
.L002132e0:
	addi	$2,$2,-1
	lw	$6,0($7)
	sw	$5,8($6)
	addiu	$7,$7,4
	add	$5,$5,$3
	bgtz	$2,.L002132e0
	nop
	lui	$2,0x1000
	ori	$2,$2,0xd000
.L00213304:
	lw	$3,0($2)
	nop
	nop
	nop
	nop
	andi	$3,$3,0x100
	bne	$0,$3,.L00213304
	lhu	$6,706($25)
	multu	$6,$14
	sw	$4,128($2)
	lw	$5,820($25)
	sw	$5,16($2)
	mflo	$6
	sw	$6,32($2)
	sll	$6,$6,0x4
	add	$6,$6,$5
	sw	$6,820($25)
	li	$4,256
	sw	$4,0($2)
	b	.L00212ed4
	addi	$13,$13,1
.L00213358:
	lui	$13,0x1000
	ori	$13,$13,0xd000
.L00213360:
	lw	$14,0($13)
	andi	$15,$14,0x100
	nop
	nop
	nop
	bnez	$15,.L00213360
	nop
	nop
	nop
	nop
	nop
	lq	$18,976($25)
	lq	$17,992($25)
	lq	$16,1008($25)
	b	.L002127fc
	lb	$14,1($19)
.L002133a0:
	lui	$15,0x2000
	lui	$14,0x37
	ori	$15,$15,0xb
	lui	$13,0x1db
	sd	$15,256($25)
	ld	$15,2152($14)
	sd	$15,496($25)
	lui	$14,0x37
	ld	$15,2160($14)
	sd	$15,504($25)
	lh	$24,2($19)
	lw	$15,-29488($13)
	addiu	$19,$19,16
	addu	$15,$15,$24
	sw	$15,-29488($13)
	sq	$16,1008($25)
	sq	$17,992($25)
	sq	$18,976($25)
	lw	$18,768($25)
	move	$17,$20
	li	$12,4096
	lui	$10,0xffff
	dsrl32	$10,$10,0x0
	dsll32	$11,$10,0x0
	or	$11,$11,$10
	pcpyld	$11,$10,$11
	lbu	$2,503($25)
	srl	$2,$2,0x4
	addiu	$2,$2,2
	sh	$2,706($25)
	sll	$2,$2,0x4
	sh	$2,704($25)
	move	$13,$0
	lui	$2,0x100
	lui	$3,0xffff
	ori	$3,$3,0xffff
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	pextlb	$3,$0,$3
	pextlh	$3,$0,$3
	qmtc2	$2,vf19
	qmtc2	$3,vf20
	vitof0.wxyz	vf19,vf19
	vitof0.wxyz	vf20,vf20
.L00213450:
	beqz	$24,.L00213838
	andi	$13,$13,0x1
	sll	$3,$13,0xc
	add	$15,$25,$3
	addi	$15,$15,2048
	move	$14,$0
.L00213468:
	move	$9,$0
	lhu	$2,16($19)
	lhu	$3,18($19)
	lhu	$4,20($19)
	lhu	$5,22($19)
	dsll	$2,$2,0x4
	dsll	$3,$3,0x4
	dsll	$4,$4,0x4
	dsll	$5,$5,0x4
	add	$2,$2,$17
	add	$3,$3,$17
	add	$4,$4,$17
	add	$5,$5,$17
	lqc2	vf15,0($2)
	lqc2	vf16,0($3)
	lqc2	vf17,0($4)
	lqc2	vf18,0($5)
	andi	$2,$18,0x10
	beqz	$2,.L002134e0
	nop
	vsub.wxyz	vf7,vf15,vf16
	vsub.wxyz	vf8,vf17,vf16
	vopmula.xyz	ACC,vf7,vf8
	vopmsub.xyz	vf9,vf8,vf7
	vftoi4.z	vf9,vf9
	qmfc2	$6,vf9
	pextuw	$2,$0,$6
	sll	$2,$2,0x0
	bgez	$2,.L00213778
	nop
.L002134e0:
	move	$8,$0
	vsub.xyz	vf1,vf15,vf27
	vsub.xyz	vf2,vf16,vf27
	vsub.xyz	vf3,vf17,vf27
	vsub.xyz	vf4,vf18,vf27
	vmax.xyz	vf5,vf1,vf2
	vmax.xyz	vf5,vf5,vf3
	vmax.xyz	vf5,vf5,vf4
	vmini.xyz	vf6,vf1,vf2
	vmini.xyz	vf6,vf6,vf3
	vmini.xyz	vf6,vf6,vf4
	vclipw.xy	vf5,vf28w
	vclipw.xy	vf6,vf28w
	vclipw.xy	vf5,vf29w
	vclipw.xy	vf6,vf29w
	lui	$2,0x28
	ori	$2,$2,0x514a
	li	$3,2064
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$4,$18
	vclipw.z	vf5,vf27w
	vclipw.z	vf6,vf27w
	and	$4,$4,$2
	bnez	$4,.L00213778
	nop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$4,$18
	and	$4,$4,$3
	bnez	$4,.L00213778
	nop
	qmfc2	$6,vf21
	lw	$2,0($19)
	lw	$3,4($19)
	lw	$4,8($19)
	lw	$5,12($19)
	pextlb	$2,$0,$2
	pextlb	$3,$0,$3
	pextlb	$4,$0,$4
	pextlb	$5,$0,$5
	pextlh	$2,$0,$2
	pextlh	$3,$0,$3
	pextlh	$4,$0,$4
	pextlh	$5,$0,$5
	qmtc2	$2,vf5
	qmtc2	$3,vf6
	qmtc2	$4,vf7
	qmtc2	$5,vf8
	lhu	$2,16($19)
	lhu	$3,18($19)
	lhu	$4,20($19)
	lhu	$5,22($19)
	dsll	$2,$2,0x4
	dsll	$3,$3,0x4
	dsll	$4,$4,0x4
	dsll	$5,$5,0x4
	add	$2,$2,$21
	add	$3,$3,$21
	add	$4,$4,$21
	add	$5,$5,$21
	lqc2	vf22,0($2)
	lqc2	vf23,0($3)
	lqc2	vf24,0($4)
	lqc2	vf25,0($5)
	lqc2	vf9,880($25)
	lqc2	vf10,848($25)
	vitof0.wxyz	vf5,vf5
	vitof0.wxyz	vf6,vf6
	vitof0.wxyz	vf7,vf7
	vitof0.wxyz	vf8,vf8
	vmul.wxyz	vf1,vf5,vf10
	vmul.wxyz	vf2,vf6,vf10
	vmul.wxyz	vf3,vf7,vf10
	vmul.wxyz	vf4,vf8,vf10
	vadd.wxyz	vf1,vf1,vf9
	vadd.wxyz	vf2,vf2,vf9
	vadd.wxyz	vf3,vf3,vf9
	vadd.wxyz	vf4,vf4,vf9
	vmulz.wxyz	vf1,vf1,vf22z
	vmulz.wxyz	vf2,vf2,vf23z
	vmulz.wxyz	vf3,vf3,vf24z
	vmulz.wxyz	vf4,vf4,vf25z
	vmini.wxyz	vf1,vf1,vf20
	vmini.wxyz	vf2,vf2,vf20
	vmini.wxyz	vf3,vf3,vf20
	vmini.wxyz	vf4,vf4,vf20
	vmax.wxyz	vf1,vf1,vf19
	vmax.wxyz	vf2,vf2,vf19
	vmax.wxyz	vf3,vf3,vf19
	vmax.wxyz	vf4,vf4,vf19
	vftoi0.wxyz	vf1,vf1
	vftoi0.wxyz	vf2,vf2
	vftoi0.wxyz	vf3,vf3
	vftoi0.wxyz	vf4,vf4
	sqc2	vf1,64($15)
	sqc2	vf2,96($15)
	sqc2	vf3,128($15)
	sqc2	vf4,160($15)
	vmove.w	vf15,vf22
	vmove.w	vf16,vf23
	vmove.w	vf17,vf24
	vmove.w	vf18,vf25
	vftoi4.wxyz	vf15,vf15
	vftoi4.wxyz	vf16,vf16
	vftoi4.wxyz	vf17,vf17
	vftoi4.wxyz	vf18,vf18
	qmfc2	$2,vf15
	qmfc2	$3,vf16
	qmfc2	$4,vf17
	qmfc2	$5,vf18
	sqc2	vf15,80($15)
	sqc2	vf16,112($15)
	sqc2	vf17,144($15)
	sqc2	vf18,176($15)
	lw	$6,92($15)
	lw	$7,124($15)
	ori	$6,$6,0x8000
	ori	$7,$7,0x8000
	sw	$6,92($15)
	sw	$7,124($15)
	paddw	$2,$2,$3
	paddw	$2,$2,$4
	paddw	$2,$2,$5
	pexew	$2,$2
	li	$3,0xc000
	pdivw	$2,$3
	lq	$3,256($25)
	lq	$4,496($25)
	lq	$6,304($25)
	lq	$2,352($25)
	sq	$3,0($15)
	sq	$4,16($15)
	sq	$6,32($15)
	sq	$2,48($15)
	pmflo	$2
	sltiu	$3,$2,256
	bnez	$3,.L00213730
	slt	$4,$2,$0
	bnez	$4,.L0021372c
	li	$2,255
	b	.L00213730
	nop
.L0021372c:
	move	$2,$0
.L00213730:
	lhu	$6,704($25)
	multu	$6,$14
	sll	$2,$2,0x4
	lw	$3,384($25)
	add	$2,$3,$2
	sll	$5,$14,0x2
	add	$5,$5,$25
	sw	$2,576($5)
	lw	$3,8($2)
	mflo	$6
	lw	$7,820($25)
	add	$7,$7,$6
	sw	$15,8($2)
	addiu	$2,$2,16
	sw	$7,4($3)
	sw	$2,4($15)
	addi	$15,$15,192
	addi	$14,$14,1
.L00213778:
	addi	$24,$24,-1
	addi	$2,$14,-8
	addi	$19,$19,24
	bgez	$2,.L00213794
	addi	$3,$3,1
	bgtz	$24,.L00213468
	nop
.L00213794:
	lw	$2,484($25)
	add	$2,$2,$14
	sw	$2,484($25)
	beqz	$14,.L00213450
	sll	$4,$13,0xc
	add	$4,$25,$4
	addi	$4,$4,2048
	move	$2,$14
	lhu	$3,704($25)
	addi	$7,$25,576
	lw	$5,820($25)
.L002137c0:
	addi	$2,$2,-1
	lw	$6,0($7)
	sw	$5,8($6)
	addiu	$7,$7,4
	add	$5,$5,$3
	bgtz	$2,.L002137c0
	nop
	lui	$2,0x1000
	ori	$2,$2,0xd000
.L002137e4:
	lw	$3,0($2)
	nop
	nop
	nop
	nop
	andi	$3,$3,0x100
	bne	$0,$3,.L002137e4
	lhu	$6,706($25)
	multu	$6,$14
	sw	$4,128($2)
	lw	$5,820($25)
	sw	$5,16($2)
	mflo	$6
	sw	$6,32($2)
	sll	$6,$6,0x4
	add	$6,$6,$5
	sw	$6,820($25)
	li	$4,256
	sw	$4,0($2)
	b	.L00213450
	addi	$13,$13,1
.L00213838:
	lui	$13,0x1000
	ori	$13,$13,0xd000
.L00213840:
	lw	$14,0($13)
	andi	$15,$14,0x100
	nop
	nop
	nop
	bnez	$15,.L00213840
	nop
	nop
	nop
	nop
	nop
	lq	$18,976($25)
	lq	$17,992($25)
	lq	$16,1008($25)
	b	.L002127fc
	lb	$14,1($19)
.L00213880:
	lui	$15,0x2000
	lui	$14,0x37
	ori	$15,$15,0xd
	lui	$12,0x36
	sd	$15,256($25)
	addiu	$12,$12,-28288
	ld	$15,2136($14)
	sd	$15,496($25)
	lui	$15,0x37
	ld	$14,2144($15)
	sd	$14,504($25)
	lhu	$13,12($22)
	lw	$15,8($19)
	addu	$15,$15,$13
	sw	$15,288($25)
	lhu	$14,14($22)
	li	$15,6
	lw	$13,12($19)
	sll	$14,$14,0x5
	addu	$13,$13,$14
	sd	$15,296($25)
	sw	$13,292($25)
	lw	$14,16($22)
	lw	$15,20($22)
	sq	$0,864($25)
	ld	$2,288($25)
	dsra	$2,$2,0x18
	andi	$3,$2,0x3c
	dsra	$2,$2,0x4
	andi	$4,$2,0x3c
	add	$3,$3,$12
	add	$4,$4,$12
	lw	$3,0($3)
	lw	$4,0($4)
	dsll	$5,$3,0x10
	bnez	$5,.L00213918
	div	$0,$14,$5
	break	0x7
.L00213918:
	li	$1,-1
	bne	$5,$1,.L00213930
	lui	$1,0x8000
	bne	$14,$1,.L00213930
	nop
	break	0x7
.L00213930:
	mflo	$14
	mfhi	$5
	dsra	$5,$5,0x4
	bnez	$3,.L00213948
	div	$0,$5,$3
	break	0x7
.L00213948:
	li	$1,-1
	bne	$3,$1,.L00213960
	lui	$1,0x8000
	bne	$5,$1,.L00213960
	nop
	break	0x7
.L00213960:
	mflo	$5
	mflo	$5
	sw	$5,864($25)
	dsll	$5,$4,0x10
	bnez	$5,.L0021397c
	div	$0,$15,$5
	break	0x7
.L0021397c:
	li	$1,-1
	bne	$5,$1,.L00213994
	lui	$1,0x8000
	bne	$15,$1,.L00213994
	nop
	break	0x7
.L00213994:
	mflo	$15
	mfhi	$5
	dsra	$5,$5,0x4
	bnez	$4,.L002139ac
	div	$0,$5,$4
	break	0x7
.L002139ac:
	li	$1,-1
	bne	$4,$1,.L002139c4
	lui	$1,0x8000
	bne	$5,$1,.L002139c4
	nop
	break	0x7
.L002139c4:
	mflo	$5
	mflo	$5
	sw	$5,868($25)
	lui	$14,0x1db
	lh	$24,2($19)
	addiu	$14,$14,-29488
	lw	$15,4($14)
	addiu	$19,$19,16
	addu	$15,$15,$24
	sw	$15,4($14)
	sq	$16,1008($25)
	sq	$17,992($25)
	sq	$18,976($25)
	lw	$18,768($25)
	move	$17,$20
	li	$12,4096
	lui	$10,0xffff
	dsrl32	$10,$10,0x0
	dsll32	$11,$10,0x0
	or	$11,$11,$10
	pcpyld	$11,$10,$11
	lbu	$2,503($25)
	srl	$2,$2,0x4
	addiu	$2,$2,2
	sh	$2,706($25)
	sll	$2,$2,0x4
	sh	$2,704($25)
	move	$13,$0
	lui	$2,0x100
	lui	$3,0xffff
	ori	$3,$3,0xffff
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	pextlb	$3,$0,$3
	pextlh	$3,$0,$3
	qmtc2	$2,vf19
	qmtc2	$3,vf20
	vitof0.wxyz	vf19,vf19
	vitof0.wxyz	vf20,vf20
.L00213a60:
	beqz	$24,.L00213e3c
	andi	$13,$13,0x1
	sll	$3,$13,0xc
	add	$15,$25,$3
	addi	$15,$15,2048
	move	$14,$0
.L00213a78:
	move	$9,$0
	lhu	$2,12($19)
	lhu	$3,14($19)
	lhu	$4,16($19)
	dsll	$2,$2,0x4
	dsll	$3,$3,0x4
	dsll	$4,$4,0x4
	add	$2,$2,$17
	add	$3,$3,$17
	add	$4,$4,$17
	lqc2	vf15,0($2)
	lqc2	vf16,0($3)
	lqc2	vf17,0($4)
	andi	$2,$18,0x10
	beqz	$2,.L00213ae0
	nop
	vsub.wxyz	vf7,vf15,vf16
	vsub.wxyz	vf8,vf17,vf16
	vopmula.xyz	ACC,vf7,vf8
	vopmsub.xyz	vf9,vf8,vf7
	vftoi4.z	vf9,vf9
	qmfc2	$6,vf9
	pextuw	$2,$0,$6
	sll	$2,$2,0x0
	bgez	$2,.L00213d7c
	nop
.L00213ae0:
	move	$8,$0
	vsub.xyz	vf1,vf15,vf27
	vsub.xyz	vf2,vf16,vf27
	vsub.xyz	vf3,vf17,vf27
	vnop
	vmax.xyz	vf5,vf1,vf2
	vmax.xyz	vf5,vf5,vf3
	vmini.xyz	vf6,vf1,vf2
	vmini.xyz	vf6,vf6,vf3
	vclipw.xy	vf5,vf28w
	vclipw.xy	vf6,vf28w
	vclipw.xy	vf5,vf29w
	vclipw.xy	vf6,vf29w
	lui	$2,0x28
	ori	$2,$2,0x514a
	li	$3,2064
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$4,$18
	vclipw.z	vf5,vf27w
	vclipw.z	vf6,vf27w
	and	$4,$4,$2
	bnez	$4,.L00213d7c
	nop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$4,$18
	and	$4,$4,$3
	bnez	$4,.L00213d7c
	nop
	qmfc2	$6,vf21
	lw	$2,0($19)
	lw	$3,4($19)
	lw	$4,8($19)
	pextlb	$2,$0,$2
	pextlb	$3,$0,$3
	pextlb	$4,$0,$4
	pextlh	$2,$0,$2
	pextlh	$3,$0,$3
	pextlh	$4,$0,$4
	qmtc2	$2,vf4
	qmtc2	$3,vf5
	qmtc2	$4,vf6
	lhu	$2,12($19)
	lhu	$3,14($19)
	lhu	$4,16($19)
	dsll	$2,$2,0x4
	dsll	$3,$3,0x4
	dsll	$4,$4,0x4
	add	$2,$2,$21
	add	$3,$3,$21
	add	$4,$4,$21
	lqc2	vf22,0($2)
	lqc2	vf23,0($3)
	lqc2	vf24,0($4)
	lqc2	vf9,880($25)
	lqc2	vf10,848($25)
	vitof0.wxyz	vf4,vf4
	vitof0.wxyz	vf5,vf5
	vitof0.wxyz	vf6,vf6
	vmul.wxyz	vf1,vf4,vf10
	vmul.wxyz	vf2,vf5,vf10
	vmul.wxyz	vf3,vf6,vf10
	vadd.wxyz	vf1,vf1,vf9
	vadd.wxyz	vf2,vf2,vf9
	vadd.wxyz	vf3,vf3,vf9
	vmulz.wxyz	vf1,vf1,vf22z
	vmulz.wxyz	vf2,vf2,vf23z
	vmulz.wxyz	vf3,vf3,vf24z
	vmini.wxyz	vf1,vf1,vf20
	vmini.wxyz	vf2,vf2,vf20
	vmini.wxyz	vf3,vf3,vf20
	vmax.wxyz	vf1,vf1,vf19
	vmax.wxyz	vf2,vf2,vf19
	vmax.wxyz	vf3,vf3,vf19
	vftoi0.wxyz	vf1,vf1
	vftoi0.wxyz	vf2,vf2
	vftoi0.wxyz	vf3,vf3
	sqc2	vf1,96($15)
	sqc2	vf2,144($15)
	sqc2	vf3,192($15)
	lq	$6,864($25)
	lw	$2,20($19)
	lw	$3,24($19)
	lw	$4,28($19)
	and	$2,$2,$10
	and	$3,$3,$10
	and	$4,$4,$10
	pextlh	$2,$0,$2
	pextlh	$3,$0,$3
	pextlh	$4,$0,$4
	pcpyld	$2,$12,$2
	pcpyld	$3,$12,$3
	pcpyld	$4,$12,$4
	paddw	$2,$2,$6
	paddw	$3,$3,$6
	paddw	$4,$4,$6
	qmtc2	$2,vf1
	qmtc2	$3,vf2
	qmtc2	$4,vf3
	vitof12.xyz	vf1,vf1
	vitof12.xyz	vf2,vf2
	vitof12.xyz	vf3,vf3
	vmulw.xyz	vf4,vf1,vf15w
	vmulw.xyz	vf5,vf2,vf16w
	vmulw.xyz	vf6,vf3,vf17w
	sqc2	vf4,80($15)
	sqc2	vf5,128($15)
	sqc2	vf6,176($15)
	vmove.w	vf15,vf22
	vmove.w	vf16,vf23
	vmove.w	vf17,vf24
	vftoi4.wxyz	vf15,vf15
	vftoi4.wxyz	vf16,vf16
	vftoi4.wxyz	vf17,vf17
	qmfc2	$2,vf15
	qmfc2	$3,vf16
	qmfc2	$4,vf17
	sqc2	vf15,112($15)
	sqc2	vf16,160($15)
	sqc2	vf17,208($15)
	paddw	$2,$2,$3
	paddw	$2,$2,$4
	pexew	$2,$2
	li	$3,0x9000
	pdivw	$2,$3
	lq	$3,256($25)
	lq	$4,496($25)
	lq	$5,288($25)
	lq	$6,304($25)
	lq	$2,352($25)
	sq	$3,0($15)
	sq	$4,16($15)
	sq	$5,32($15)
	sq	$6,48($15)
	sq	$2,64($15)
	pmflo	$2
	sltiu	$3,$2,256
	bnez	$3,.L00213d34
	slt	$4,$2,$0
	bnez	$4,.L00213d30
	li	$2,255
	b	.L00213d34
	nop
.L00213d30:
	move	$2,$0
.L00213d34:
	lhu	$6,704($25)
	multu	$6,$14
	sll	$2,$2,0x4
	lw	$3,384($25)
	add	$2,$3,$2
	sll	$5,$14,0x2
	add	$5,$5,$25
	sw	$2,576($5)
	lw	$3,8($2)
	mflo	$6
	lw	$7,820($25)
	add	$7,$7,$6
	sw	$15,8($2)
	addiu	$2,$2,16
	sw	$7,4($3)
	sw	$2,4($15)
	addi	$15,$15,224
	addi	$14,$14,1
.L00213d7c:
	addi	$24,$24,-1
	addi	$2,$14,-8
	addi	$19,$19,32
	bgez	$2,.L00213d98
	addi	$3,$3,1
	bgtz	$24,.L00213a78
	nop
.L00213d98:
	lw	$2,480($25)
	add	$2,$2,$14
	sw	$2,480($25)
	beqz	$14,.L00213a60
	sll	$4,$13,0xc
	add	$4,$25,$4
	addi	$4,$4,2048
	move	$2,$14
	lhu	$3,704($25)
	addi	$7,$25,576
	lw	$5,820($25)
.L00213dc4:
	addi	$2,$2,-1
	lw	$6,0($7)
	sw	$5,8($6)
	addiu	$7,$7,4
	add	$5,$5,$3
	bgtz	$2,.L00213dc4
	nop
	lui	$2,0x1000
	ori	$2,$2,0xd000
.L00213de8:
	lw	$3,0($2)
	nop
	nop
	nop
	nop
	andi	$3,$3,0x100
	bne	$0,$3,.L00213de8
	lhu	$6,706($25)
	multu	$6,$14
	sw	$4,128($2)
	lw	$5,820($25)
	sw	$5,16($2)
	mflo	$6
	sw	$6,32($2)
	sll	$6,$6,0x4
	add	$6,$6,$5
	sw	$6,820($25)
	li	$4,256
	sw	$4,0($2)
	b	.L00213a60
	addi	$13,$13,1
.L00213e3c:
	lui	$13,0x1000
	ori	$13,$13,0xd000
.L00213e44:
	lw	$14,0($13)
	andi	$15,$14,0x100
	nop
	nop
	nop
	bnez	$15,.L00213e44
	nop
	nop
	nop
	nop
	nop
	lq	$18,976($25)
	lq	$17,992($25)
	lq	$16,1008($25)
	b	.L002127fc
	lb	$14,1($19)
.L00213e84:
	b	.L0021279c
	sd	$15,352($25)
.L00213e8c:
	lbu	$15,22($16)
	sw	$15,304($25)
	b	.L0021275c
	lbu	$14,23($16)
.L00213e9c:
	b	.L00212408
	move	$14,$13
	.end func_00212338
	.size func_00212338, .-func_00212338
