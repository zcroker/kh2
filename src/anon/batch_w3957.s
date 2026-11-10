# Whole-function assembly (last step of the README match ladder, w3957 2026-11-11).
# Transcribed from the retail disassembly; calls with a func_ symbol are referenced through it.
# Replace with C/C++ after 100%.
#   func_002e5518: rope/cloth grid draw (21x41 nodes, 16-byte nodes, 656-byte rows): VU0 quad normals,
#     normalize/dot/project/winding, GIF A+D tag and RGBAQ/ST/XYZ packets, soft-double maths via
#     func_00313b80/003144b0/00313f40/00313e80, func_002fd178 x3.
#     Closest C: ~/re/kh2/tmp.w3957/best_002e5518.cpp (_gnsa_nogcse, = coord best/002e5518_w3946_gnsa_nogcse.cpp,
#     ~346 lines off by difflib): frame 240 vs 272 (original spills more), s-register map differs (a0 in s8).
#     No symbol, written as literal lui/offset values: 0x00376020, 0x00376028, 0x0037602c, 0x00376030,
#     0x00376034, 0x00376038 (literal pool), 0x13000000 (GIF/VIF constant).
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002e5518,"ax",@progbits
	.align 2
	.globl func_002e5518
	.type func_002e5518, @function
	.ent func_002e5518
func_002e5518:
	addiu	$29,$29,-272
	mtc1	$0,$f0
	sd	$30,240($29)
	move	$13,$29
	sd	$16,176($29)
	move	$12,$4
	sd	$17,184($29)
	move	$30,$4
	sd	$18,192($29)
	addiu	$11,$4,13776
	sd	$19,200($29)
	sd	$20,208($29)
	sd	$21,216($29)
	sd	$22,224($29)
	sd	$23,232($29)
	sd	$31,248($29)
	swc1	$f23,268($29)
	swc1	$f22,264($29)
	swc1	$f21,260($29)
	swc1	$f20,256($29)
	sw	$5,96($29)
	sw	$6,100($29)
	sd	$7,104($29)
	addiu	$15,$12,4480
.L002e5578:
	li	$14,40
.L002e557c:
	swc1	$f0,0($29)
	swc1	$f0,4($29)
	swc1	$f0,8($29)
	beq	$15,$29,.L002e5598
	swc1	$f0,12($29)
	lq	$8,0($13)
	sq	$8,0($15)
.L002e5598:
	addiu	$14,$14,-1
	bgez	$14,.L002e557c
	addiu	$15,$15,16
	addiu	$12,$12,656
	slt	$15,$12,$11
	bnez	$15,.L002e5578
	addiu	$15,$12,4480
	lui	$12,0x37
	sw	$0,112($29)
	addiu	$12,$12,24616
	sw	$30,160($29)
	addiu	$23,$29,16
	lwc1	$f23,0($12)
	move	$17,$23
	addiu	$18,$29,32
	addiu	$21,$29,48
	addiu	$22,$29,64
.L002e55dc:
	lwc1	$f0,4($30)
	lw	$13,112($29)
	nop
	nop
	div.s	$f0,$f0,$f23
	lw	$14,160($29)
	addiu	$4,$13,-10
	addiu	$16,$13,-9
	mtc1	$4,$f2
	addiu	$20,$14,4480
	mtc1	$16,$f1
	addiu	$19,$14,5136
	cvt.s.w	$f2,$f2
	cvt.s.w	$f1,$f1
	mul.s	$f21,$f2,$f0
	jal	func_002fd178
	mul.s	$f22,$f1,$f0
	sll	$2,$2,0x2
	move	$4,$16
	addu	$2,$2,$30
	jal	func_002fd178
	lwc1	$f20,4432($2)
	sll	$2,$2,0x2
	move	$12,$0
	addu	$2,$2,$30
	move	$13,$30
	lwc1	$f2,4432($2)
.L002e5648:
	lwc1	$f0,20($13)
	lwc1	$f1,16($13)
	mul.s	$f0,$f20,$f0
	swc1	$f1,0($17)
	swc1	$f21,8($17)
	lwc1	$f1,16($13)
	swc1	$f0,4($17)
	swc1	$f22,8($18)
	lwc1	$f0,20($13)
	swc1	$f1,0($18)
	mul.s	$f0,$f2,$f0
	beqz	$12,.L002e5734
	swc1	$f0,4($18)
	lqc2	$vf1,0($17)
	lqc2	$vf2,16($17)
	lqc2	$vf3,0($21)
	lqc2	$vf4,16($21)
	vsub.xyz	$vf5,$vf4,$vf3
	vsub.xyz	$vf6,$vf1,$vf4
	vopmula.xyz	ACC,$vf5,$vf6
	vopmsub.xyz	$vf7,$vf6,$vf5
	vmul.xyz	$vf8,$vf7,$vf7
	vaddy.x	$vf8,$vf8,vf8y
	vaddz.x	$vf8,$vf8,vf8z
	vrsqrt	Q,vf0w,vf8x
	vwaitq
	vmulq.xyz	$vf8,$vf7,Q
	vmove.w	$vf8,$vf0
	lqc2	$vf5,0($20)
	lqc2	$vf6,16($20)
	lqc2	$vf7,0($19)
	vadd.wxyz	$vf5,$vf5,$vf8
	vadd.wxyz	$vf6,$vf6,$vf8
	vadd.wxyz	$vf7,$vf7,$vf8
	sqc2	$vf5,0($20)
	sqc2	$vf6,16($20)
	sqc2	$vf7,0($19)
	vsub.xyz	$vf5,$vf1,$vf2
	vsub.xyz	$vf6,$vf4,$vf1
	vopmula.xyz	ACC,$vf5,$vf6
	vopmsub.xyz	$vf7,$vf6,$vf5
	vmul.xyz	$vf8,$vf7,$vf7
	vaddy.x	$vf8,$vf8,vf8y
	vaddz.x	$vf8,$vf8,vf8z
	vrsqrt	Q,vf0w,vf8x
	vwaitq
	vmulq.xyz	$vf8,$vf7,Q
	vmove.w	$vf8,$vf0
	lqc2	$vf5,16($20)
	lqc2	$vf6,0($19)
	lqc2	$vf7,16($19)
	vadd.wxyz	$vf5,$vf5,$vf8
	vadd.wxyz	$vf6,$vf6,$vf8
	vadd.wxyz	$vf7,$vf7,$vf8
	sqc2	$vf5,16($20)
	sqc2	$vf6,0($19)
	sqc2	$vf7,16($19)
	addiu	$20,$20,16
	addiu	$19,$19,16
.L002e5734:
	move	$14,$17
	addiu	$12,$12,1
	move	$17,$21
	addiu	$13,$13,96
	move	$21,$14
	slti	$15,$12,41
	move	$14,$18
	move	$18,$22
	bnez	$15,.L002e5648
	move	$22,$14
	lw	$15,112($29)
	lw	$12,160($29)
	addiu	$15,$15,1
	sw	$15,112($29)
	addiu	$12,$12,656
	slti	$15,$15,20
	bnez	$15,.L002e55dc
	sw	$12,160($29)
	addiu	$21,$29,80
	move	$15,$21
.L002e5784:
	nop
	nop
	nop
	nop
	nop
	bne	$23,$15,.L002e5784
	addiu	$15,$15,-16
	lui	$13,0x37
	mtc1	$0,$f1
	addiu	$13,$13,24620
	lwc1	$f0,0($13)
	swc1	$f1,12($29)
	swc1	$f0,4($29)
	swc1	$f1,0($29)
	swc1	$f1,8($29)
	lqc2	$vf1,0($29)
	vmul.xyz	$vf2,$vf1,$vf1
	vaddy.x	$vf2,$vf2,vf2y
	vaddz.x	$vf2,$vf2,vf2z
	vsqrt	Q,vf2x
	vwaitq
	cfc2.ni	$8,$22
	vaddq.x	$vf2,$vf0,Q
	mtc1	$8,$f0
	vnop
	vdiv	Q,vf0w,vf2x
	vwaitq
	vmulq.xyz	$vf1,$vf1,Q
	sqc2	$vf1,0($29)
	lw	$14,96($29)
	lq	$8,0($14)
	lq	$9,16($14)
	lq	$10,32($14)
	lq	$11,48($14)
	sq	$8,0($23)
	sq	$9,16($23)
	sq	$10,32($23)
	sq	$11,48($23)
	lui	$15,0x37
	lui	$12,0x37
	addiu	$15,$15,24624
	addiu	$12,$12,24628
	lwc1	$f0,0($15)
	lwc1	$f20,0($12)
	swc1	$f0,88($29)
	swc1	$f0,80($29)
	swc1	$f0,84($29)
	swc1	$f20,92($29)
	lqc2	$vf4,0($21)
	lqc2	$vf1,0($23)
	lqc2	$vf2,16($23)
	lqc2	$vf3,32($23)
	vmulx.wxyz	$vf1,$vf1,vf4x
	vmuly.wxyz	$vf2,$vf2,vf4y
	vmulz.wxyz	$vf3,$vf3,vf4z
	sqc2	$vf1,0($23)
	sqc2	$vf2,16($23)
	sqc2	$vf3,32($23)
	li	$4,1
	jal	func_00106a18
	mov.s	$f23,$f20
	move	$20,$0
	lui	$13,0x37
	move	$4,$2
	addiu	$13,$13,24632
	move	$22,$0
	jal	func_001070a0
	lwc1	$f21,0($13)
	mov.s	$f12,$f0
	lui	$14,0x37
	addiu	$14,$14,24616
	jal	func_002f8870
	lwc1	$f22,0($14)
	nop
	nop
	div.s	$f20,$f20,$f0
.L002e58b4:
	addiu	$19,$20,-10
	move	$17,$30
	addu	$16,$22,$30
	li	$18,40
.L002e58c4:
	lwc1	$f0,4492($16)
	addiu	$15,$16,4480
	nop
	nop
	div.s	$f0,$f23,$f0
	lqc2	$vf1,0($15)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($15)
	lqc2	$vf1,0($29)
	lqc2	$vf2,0($15)
	vmul.xyz	$vf1,$vf1,$vf2
	vaddy.x	$vf1,$vf1,vf1y
	vaddz.x	$vf1,$vf1,vf1z
	qmfc2	$8,$vf1
	mtc1	$8,$f1
	neg.s	$f1,$f1
	move	$4,$19
	mul.s	$f1,$f1,$f21
	c.lt.s	$f21,$f1
	bc1f	.L002e5924
	mtc1	$0,$f0
	mov.s	$f1,$f21
.L002e5924:
	c.lt.s	$f1,$f0
	bc1tl	.L002e5930
	mov.s	$f1,$f0
.L002e5930:
	lwc1	$f0,16($17)
	swc1	$f1,4492($16)
	jal	func_002fd178
	swc1	$f0,80($29)
	mtc1	$19,$f1
	sll	$2,$2,0x2
	lwc1	$f0,4($30)
	addu	$2,$2,$30
	cvt.s.w	$f1,$f1
	addiu	$15,$16,18256
	lwc1	$f2,20($17)
	mul.s	$f1,$f1,$f0
	nop
	nop
	div.s	$f1,$f1,$f22
	lwc1	$f0,4432($2)
	mul.s	$f0,$f0,$f2
	swc1	$f0,84($29)
	swc1	$f1,88($29)
	lqc2	$vf1,0($23)
	lqc2	$vf2,16($23)
	lqc2	$vf3,32($23)
	lqc2	$vf4,48($23)
	lqc2	$vf5,0($21)
	vmove.w	$vf5,$vf0
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	vdiv	Q,vf0w,vf5w
	vwaitq
	vmove.w	$vf5,$vf0
	vmulq.wxyz	$vf5,$vf5,Q
	vftoi4.xy	$vf5,$vf5
	vftoi0.z	$vf5,$vf5
	sqc2	$vf5,0($15)
	addiu	$17,$17,96
	addiu	$18,$18,-1
	bgez	$18,.L002e58c4
	addiu	$16,$16,16
	addiu	$20,$20,1
	slti	$15,$20,21
	bnez	$15,.L002e58b4
	addiu	$22,$22,656
	lui	$15,0x37
	lw	$4,100($29)
	addiu	$15,$15,24616
	li	$5,5082
	lwc1	$f23,0($15)
	lui	$6,0x1300
	move	$22,$0
	jal	func_00133ba0
	move	$17,$0
	por	$12,$0,$0
	sq	$12,0($2)
	li	$14,-32768
	li	$13,-16
	ld	$15,0($2)
	dsrl	$13,$13,0x4
	ld	$12,8($2)
	and	$15,$15,$14
	li	$14,-16
	ori	$15,$15,0x93d9
	and	$12,$12,$14
	and	$15,$15,$13
	li	$14,1
	addiu	$13,$2,32
	dsll32	$14,$14,0x1c
	ori	$12,$12,0xe
	or	$15,$15,$14
	sd	$15,0($2)
	sw	$13,116($29)
	li	$15,6
	sd	$12,8($2)
	ld	$14,104($29)
	sd	$14,16($2)
	sw	$0,120($29)
	sd	$15,24($2)
.L002e5a68:
	lw	$15,120($29)
	li	$13,656
	lwc1	$f0,120($29)
	addiu	$15,$15,1
	lw	$12,120($29)
	mtc1	$15,$f1
	mult1	$14,$15,$13
	cvt.s.w	$f0,$f0
	mult	$12,$12,$13
	cvt.s.w	$f1,$f1
	sw	$15,124($29)
	sw	$0,128($29)
	sw	$14,148($29)
	nop
	nop
	div.s	$f22,$f0,$f23
	sw	$12,140($29)
	sw	$14,156($29)
	nop
	nop
	div.s	$f21,$f1,$f23
.L002e5abc:
	lw	$13,128($29)
	li	$12,20
	lw	$15,116($29)
	li	$14,40
	movz	$12,$0,$13
	li	$20,4
	sw	$12,132($29)
	move	$19,$0
	sd	$0,8($15)
	lw	$12,116($29)
	li	$15,28
	sd	$15,0($12)
	addiu	$16,$12,16
	li	$15,20
	lw	$18,132($29)
	movz	$14,$15,$13
	slt	$15,$14,$18
	bnez	$15,.L002e5dc8
	sw	$14,136($29)
	lw	$12,156($29)
	sll	$15,$18,0x4
	lw	$13,140($29)
	lw	$14,148($29)
	addu	$15,$15,$12
	addu	$13,$30,$13
	addu	$15,$15,$30
	addu	$14,$30,$14
	sw	$13,144($29)
	sw	$14,152($29)
	addiu	$23,$15,4492
.L002e5b34:
	lw	$15,128($29)
	beqz	$15,.L002e5ef0
	lw	$12,132($29)
	lui	$13,0x37
	addiu	$13,$13,24616
	lui	$14,0x37
	subu	$15,$18,$12
	lwc1	$f1,0($13)
	mtc1	$15,$f0
	addiu	$14,$14,24628
	lwc1	$f12,0($14)
	cvt.s.w	$f0,$f0
	nop
	nop
	div.s	$f0,$f0,$f1
	jal	func_00313b80
	sub.s	$f12,$f12,$f0
	lui	$15,0x37
	move	$4,$2
	addiu	$15,$15,24608
	ld	$5,0($15)
.L002e5b88:
	jal	func_00313f40
	sll	$19,$19,0x1
	li	$5,16293
	move	$4,$2
	jal	func_00313e80
	dsll32	$5,$5,0x10
	jal	func_003144b0
	move	$4,$2
	mov.s	$f2,$f0
	lw	$13,120($29)
	li	$14,41
	lw	$12,144($29)
	mult	$15,$13,$14
	move	$9,$22
	sll	$8,$18,0x4
	move	$22,$17
	lwc1	$f0,0($23)
	addu	$14,$12,$8
	cvt.w.s	$f3,$f0
	addiu	$17,$14,18256
	addu	$15,$15,$18
	lwc1	$f1,12($17)
	sll	$15,$15,0x4
	addu	$15,$15,$30
	mul.s	$f0,$f2,$f1
	mfc1	$7,$f3
	c.lt.s	$f20,$f1
	mul.s	$f3,$f22,$f1
	mfc1	$11,$f0
	mfc1	$14,$f1
	lwc1	$f0,4492($15)
	mfc1	$13,$f3
	cvt.w.s	$f3,$f0
	bc1t	.L002e5c24
	mfc1	$10,$f3
	mtc1	$0,$f0
	c.lt.s	$f1,$f0
	bc1f	.L002e5c2c
	andi	$15,$19,0x7
.L002e5c24:
	ori	$19,$19,0x1
	andi	$15,$19,0x7
.L002e5c2c:
	beqz	$15,.L002e5e94
	nop
	li	$20,12
.L002e5c38:
	move	$15,$14
.L002e5c3c:
	move	$10,$10
	dsll32	$15,$15,0x0
	li	$14,1
	dsrl32	$15,$15,0x0
	dsll	$12,$10,0x10
	dsll	$14,$14,0x1f
	dsll32	$15,$15,0x0
	or	$12,$12,$14
	or	$15,$10,$15
	or	$15,$15,$12
	dsll	$10,$10,0x8
	or	$15,$15,$10
	dsll32	$13,$13,0x0
	sd	$15,0($16)
	dsll32	$11,$11,0x0
	dsrl32	$13,$13,0x0
	dsrl32	$11,$11,0x0
	dsll32	$13,$13,0x0
	li	$15,1
	or	$11,$11,$13
	sd	$15,8($16)
	sd	$11,16($16)
	move	$9,$22
	li	$15,2
	move	$22,$17
	lw	$13,152($29)
	sll	$19,$19,0x1
	sd	$15,24($16)
	addu	$12,$13,$8
	lw	$15,4($17)
	lw	$13,0($17)
	lw	$14,8($17)
	dsll	$15,$15,0x10
	or	$13,$13,$15
	dsll32	$14,$14,0x0
	sd	$20,40($16)
	or	$13,$13,$14
	addiu	$17,$12,18256
	sd	$13,32($16)
	lw	$14,12($17)
	addiu	$16,$16,48
	mtc1	$14,$f0
	mtc1	$14,$f1
	mul.s	$f0,$f2,$f0
	mul.s	$f1,$f21,$f1
	mtc1	$14,$f3
	c.lt.s	$f20,$f3
	mfc1	$11,$f0
	bc1t	.L002e5d14
	mfc1	$13,$f1
	mtc1	$0,$f0
	c.lt.s	$f3,$f0
	bc1f	.L002e5d1c
	andi	$15,$19,0x7
.L002e5d14:
	ori	$19,$19,0x1
	andi	$15,$19,0x7
.L002e5d1c:
	beqz	$15,.L002e5e38
	nop
	li	$20,12
.L002e5d28:
	move	$15,$14
.L002e5d2c:
	move	$10,$7
	dsll32	$15,$15,0x0
	li	$14,1
	dsrl32	$15,$15,0x0
	dsll	$12,$10,0x10
	dsll	$14,$14,0x1f
	dsll32	$15,$15,0x0
	or	$12,$12,$14
	or	$15,$10,$15
	or	$15,$15,$12
	dsll	$10,$10,0x8
	or	$15,$15,$10
	dsll32	$13,$13,0x0
	sd	$15,0($16)
	dsll32	$11,$11,0x0
	dsrl32	$13,$13,0x0
	dsrl32	$11,$11,0x0
	dsll32	$13,$13,0x0
	li	$15,1
	or	$11,$11,$13
	sd	$15,8($16)
	sd	$11,16($16)
	addiu	$18,$18,1
	li	$15,2
	addiu	$23,$23,16
	lw	$13,136($29)
	sd	$15,24($16)
	slt	$12,$13,$18
	lw	$14,4($17)
	lw	$15,0($17)
	lw	$13,8($17)
	dsll	$14,$14,0x10
	or	$15,$15,$14
	dsll32	$13,$13,0x0
	sd	$20,40($16)
	or	$15,$15,$13
	sd	$15,32($16)
	beqz	$12,.L002e5b34
	addiu	$16,$16,48
.L002e5dc8:
	lw	$15,116($29)
	lw	$14,128($29)
	addiu	$15,$15,2032
	addiu	$14,$14,1
	sw	$15,116($29)
	slti	$15,$14,2
	bnez	$15,.L002e5abc
	sw	$14,128($29)
	lw	$12,124($29)
	slti	$15,$12,20
	bnez	$15,.L002e5a68
	sw	$12,120($29)
	ld	$16,176($29)
	ld	$17,184($29)
	ld	$18,192($29)
	ld	$19,200($29)
	ld	$20,208($29)
	ld	$21,216($29)
	ld	$22,224($29)
	ld	$23,232($29)
	ld	$30,240($29)
	ld	$31,248($29)
	lwc1	$f23,268($29)
	lwc1	$f22,264($29)
	lwc1	$f21,260($29)
	lwc1	$f20,256($29)
	jr	$31
	addiu	$29,$29,272
.L002e5e38:
	beqz	$18,.L002e5d2c
	move	$15,$14
	lqc2	$vf1,0($17)
	lqc2	$vf2,0($22)
	lqc2	$vf3,0($9)
	vitof4.xy	$vf1,$vf1
	vitof4.xy	$vf2,$vf2
	vitof4.xy	$vf3,$vf3
	vsub.xy	$vf2,$vf2,$vf1
	vsub.xy	$vf3,$vf3,$vf1
	vopmula.xyz	ACC,$vf2,$vf3
	vopmsub.xyz	$vf1,$vf3,$vf2
	sqc2	$vf1,0($21)
	lwc1	$f1,88($29)
	mtc1	$0,$f0
	c.le.s	$f0,$f1
	bc1t	.L002e5e84
	li	$12,1
	move	$12,$0
.L002e5e84:
	li	$20,12
	li	$15,4
	b	.L002e5d28
	movz	$20,$15,$12
.L002e5e94:
	beqz	$18,.L002e5c3c
	move	$15,$14
	lqc2	$vf1,0($17)
	lqc2	$vf2,0($22)
	lqc2	$vf3,0($9)
	vitof4.xy	$vf1,$vf1
	vitof4.xy	$vf2,$vf2
	vitof4.xy	$vf3,$vf3
	vsub.xy	$vf2,$vf2,$vf1
	vsub.xy	$vf3,$vf3,$vf1
	vopmula.xyz	ACC,$vf2,$vf3
	vopmsub.xyz	$vf1,$vf3,$vf2
	sqc2	$vf1,0($21)
	lwc1	$f1,88($29)
	mtc1	$0,$f0
	c.le.s	$f0,$f1
	bc1t	.L002e5ee0
	li	$12,1
	move	$12,$0
.L002e5ee0:
	li	$20,4
	li	$15,12
	b	.L002e5c38
	movz	$20,$15,$12
.L002e5ef0:
	mtc1	$18,$f12
	lui	$12,0x37
	addiu	$12,$12,24616
	cvt.s.w	$f12,$f12
	lwc1	$f0,0($12)
	nop
	nop
	div.s	$f12,$f12,$f0
	jal	func_00313b80
	nop
	lui	$15,0x37
	move	$4,$2
	b	.L002e5b88
	ld	$5,24608($15)
	.end func_002e5518
	.size func_002e5518, 2576
