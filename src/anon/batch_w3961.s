# Whole-function assembly (last step of the README match ladder, w3961 2026-11-11).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_0021d048: GS packet builder around six hand-written VU0 transform/clip loops (vclipw/cfc2
#     flag tests, vdiv/vwaitq perspective, vftoi4 output), GIF tags built in place, D_00359780 ring.
#     Closest C: ~/re/kh2/tmp.w3961/best_0021d048.c (= coord best/0021d048_nsa.c, 310 lines off by
#     difflib under _nsa): gcse/PRE of hi(D_01da8cd0) and the (flags&0x80) tests, GIF-tag scheduling,
#     movz clamps, loop counter register.
#     No symbol, written as literal lui/addiu values: 0x00370b10 (string for func_002fdfc8),
#     0x00370b30 (u64 GIF tag constant), 0x00370b38/0x00370b3c/0x00370b40 (float constants),
#     0x01da8be0/0x01da8c70 (qword constants), plus float bit patterns and GS register constants.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0021d048,"ax",@progbits
	.align 2
	.globl func_0021d048
	.type func_0021d048, @function
	.ent func_0021d048
func_0021d048:
	addiu	$29,$29,-32
	sd	$16,0($29)
	sd	$17,8($29)
	sd	$18,16($29)
	move	$16,$5
	sd	$31,24($29)
	lhu	$11,2($5)
	move	$12,$11
	andi	$15,$12,0x80
	beqz	$15,.L0021d0c0
	move	$5,$6
	lui	$14,%hi(D_01d9eaa8)
	lui	$13,%hi(D_01d9eab0)
	lw	$15,%lo(D_01d9eaa8)($14)
	lw	$14,%lo(D_01d9eab0)($13)
	addu	$15,$15,$6
	slt	$15,$15,$14
	bnez	$15,.L0021d0c4
	lui	$15,%hi(D_00352c38)
	lui	$4,0x37
	jal	func_002fdfc8
	addiu	$4,$4,2832
	lui	$15,%hi(D_01d9eaa4)
	lw	$2,%lo(D_01d9eaa4)($15)
.L0021d0a8:
	ld	$16,0($29)
	ld	$17,8($29)
	ld	$18,16($29)
	ld	$31,24($29)
	jr	$31
	addiu	$29,$29,32
.L0021d0c0:
	lui	$15,%hi(D_00352c38)
.L0021d0c4:
	lw	$14,%lo(D_00352c38)($15)
	beqz	$14,.L0021d13c
	andi	$15,$12,0x80
	lbu	$15,4($16)
	lbu	$14,5($16)
	mtc1	$15,$f1
	lbu	$13,6($16)
	lui	$15,0x37
	cvt.s.w	$f1,$f1
	addiu	$15,$15,2872
	mtc1	$14,$f3
	lwc1	$f0,0($15)
	mtc1	$13,$f2
	lui	$15,0x37
	mula.s	$f1,$f0
	addiu	$15,$15,2876
	cvt.s.w	$f3,$f3
	lwc1	$f0,0($15)
	cvt.s.w	$f2,$f2
	lui	$15,0x37
	addiu	$15,$15,2880
	madda.s	$f3,$f0
	lwc1	$f1,0($15)
	madd.s	$f2,$f2,$f1
	cvt.w.s	$f0,$f2
	mfc1	$15,$f0
	sb	$15,6($16)
	sb	$15,4($16)
	sb	$15,5($16)
	andi	$15,$12,0x80
.L0021d13c:
	beqz	$15,.L0021e948
	li	$14,-16
	lw	$15,20($16)
	addiu	$15,$15,15
	and	$24,$15,$14
.L0021d150:
	lw	$14,4($4)
	move	$17,$24
	lhu	$15,0($4)
	addiu	$25,$4,32
	andi	$15,$15,0x8
	beqz	$15,.L0021e940
	addu	$5,$4,$14
	lui	$18,%hi(D_01da8cd0)
	lh	$13,2($4)
	addiu	$14,$18,%lo(D_01da8cd0)
	lw	$15,12($14)
	addu	$15,$15,$13
	sw	$15,12($14)
.L0021d184:
	addiu	$13,$18,%lo(D_01da8cd0)
	lh	$12,2($4)
	lw	$14,8($13)
	lui	$15,%hi(D_00359970)
	addiu	$15,$15,%lo(D_00359970)
	addu	$14,$14,$12
	sw	$14,8($13)
	lqc2	$vf12,48($15)
	lqc2	$vf13,64($15)
	lqc2	$vf14,80($15)
	lhu	$11,2($16)
	addiu	$12,$24,80
	lhu	$6,0($4)
	addiu	$13,$24,96
	andi	$15,$11,0x10
	move	$24,$13
	andi	$14,$6,0x8
	bnez	$14,.L0021de60
	movz	$24,$12,$15
	andi	$15,$11,0xc00
	bnez	$15,.L0021db8c
	nop
	lw	$15,28($16)
	bnez	$15,.L0021d924
	nop
	lhu	$15,2($4)
	move	$9,$0
	lw	$2,4($16)
	lui	$3,0x3c00
	qmtc2	$3,$vf1
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf15
	vitof0.wxyz	$vf15,$vf15
	vmulx.wxyz	$vf15,$vf15,vf1x
	lw	$2,16($16)
	lqc2	$vf28,0($2)
	lqc2	$vf29,16($2)
	lqc2	$vf30,32($2)
	lqc2	$vf31,48($2)
	paddw	$14,$0,$0
	lui	$14,0x3f80
	prot3w	$14,$14
	paddw	$13,$0,$0
	ppacw	$12,$14,$0
	ld	$11,16($4)
	lhu	$2,10($16)
	lhu	$3,8($16)
	dsll32	$2,$2,0x5
	or	$2,$2,$3
	dadd	$11,$11,$2
	li	$10,0x8000
.L0021d254:
	lh	$2,0($25)
	lh	$3,2($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf20
	vitof4.xy	$vf20,$vf20
	vmulax.wxyz	ACC,$vf28,vf20x
	vmadday.wxyz	ACC,$vf29,vf20y
	vmaddaz.wxyz	ACC,$vf30,vf20z
	vmaddw.wxyz	$vf20,$vf31,vf20w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf20w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021d3e8
	lh	$2,4($25)
	lh	$3,6($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf23
	vitof4.xy	$vf23,$vf23
	vwaitq
	vmulq.xyz	$vf20,$vf20,Q
	vmulax.wxyz	ACC,$vf28,vf23x
	vmadday.wxyz	ACC,$vf29,vf23y
	vmaddaz.wxyz	ACC,$vf30,vf23z
	vmaddw.wxyz	$vf23,$vf31,vf23w
	vdiv	Q,vf0w,vf23w
	vwaitq
	vmulq.xyz	$vf23,$vf23,Q
	vsub.xyz	$vf1,$vf20,$vf12
	vsub.xyz	$vf4,$vf23,$vf12
	vnop
	vnop
	vmax.xyz	$vf5,$vf1,$vf4
	vmini.xyz	$vf6,$vf1,$vf4
	vclipw.xy	$vf5,vf13w
	vclipw.xy	$vf6,vf13w
	vclipw.xy	$vf5,vf14w
	vclipw.xy	$vf6,vf14w
	lui	$2,0x28
	ori	$2,$2,0x514a
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$3,$18
	vclipw.z	$vf5,vf12w
	vclipw.z	$vf6,vf12w
	and	$3,$3,$2
	bnez	$3,.L0021d3e8
	li	$2,2064
	vftoi4.wxyz	$vf20,$vf20
	vftoi4.wxyz	$vf23,$vf23
	vnop
	vnop
	cfc2.ni	$3,$18
	and	$3,$3,$2
	bnez	$3,.L0021d3e8
	lbu	$13,7($5)
	paddw	$2,$0,$0
	dsll32	$2,$13,0x5
	paddw	$2,$2,$11
	sq	$2,0($24)
	lw	$2,4($5)
	li	$3,66
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	sd	$2,16($24)
	sd	$3,24($24)
	lw	$2,0($5)
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf1
	vitof0.wxyz	$vf1,$vf1
	vmul.wxyz	$vf1,$vf1,$vf15
	vftoi0.wxyz	$vf1,$vf1
	sqc2	$vf1,48($24)
	lh	$2,8($25)
	lh	$3,10($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf1
	vitof12.xy	$vf1,$vf1
	lh	$2,12($25)
	lh	$3,14($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf4
	vitof12.xy	$vf4,$vf4
	vadd.xy	$vf4,$vf1,$vf4
	sqc2	$vf20,64($24)
	sqc2	$vf23,96($24)
	sw	$0,76($24)
	sw	$0,108($24)
	sqc2	$vf1,32($24)
	sqc2	$vf4,80($24)
	addiu	$9,$9,1
	addiu	$24,$24,112
.L0021d3e8:
	addi	$15,$15,-1
	addi	$25,$25,16
	addi	$5,$5,8
	bgtz	$15,.L0021d254
	nop
.L0021d3fc:
	move	$7,$9
	andi	$6,$6,0x8
	beqz	$6,.L0021d41c
	andi	$7,$7,0xffff
	addiu	$14,$18,%lo(D_01da8cd0)
	lw	$15,28($14)
	addu	$15,$15,$7
	sw	$15,28($14)
.L0021d41c:
	addiu	$14,$18,%lo(D_01da8cd0)
	move	$12,$0
	lw	$15,24($14)
	addu	$15,$15,$7
	sw	$15,24($14)
	lhu	$11,2($16)
	li	$15,32
	andi	$14,$11,0x800
	beqz	$7,.L0021d570
	movn	$12,$15,$14
	andi	$15,$11,0x10
	beqz	$15,.L0021d728
	andi	$15,$11,0x80
	beqz	$15,.L0021d6e8
	li	$15,3
	li	$14,4072
	dsll32	$15,$15,0x1c
	sd	$14,24($17)
	ori	$15,$15,0x1
	sd	$15,16($17)
	lui	$14,0x3
	ori	$14,$14,0xd
	por	$15,$0,$0
	sd	$14,48($17)
	sq	$15,64($17)
	li	$15,5
	sd	$15,32($17)
	li	$15,71
	sd	$15,56($17)
.L0021d490:
	lhu	$15,0($4)
	andi	$15,$15,0x8
	beqz	$15,.L0021d6b4
	ori	$15,$12,0x54
	andi	$13,$7,0xffff
	move	$15,$15
	li	$14,-32767
	dsll32	$15,$15,0xf
	dsll32	$14,$14,0xe
	or	$13,$13,$15
	or	$13,$13,$14
	lui	$15,0x37
	ld	$14,2864($15)
	sd	$14,88($17)
.L0021d4c8:
	li	$15,1
	sd	$13,80($17)
	dsll32	$15,$15,0x1c
	li	$14,14
	ori	$15,$15,0x8001
	sd	$14,8($24)
	sd	$15,0($24)
	lui	$13,%hi(D_01da8bf0)
	lq	$15,%lo(D_01da8bf0)($13)
	sq	$15,16($24)
	addiu	$24,$24,32
	lhu	$11,2($16)
	subu	$15,$24,$17
	addiu	$13,$15,15
	slti	$14,$15,0
	movn	$15,$13,$14
	andi	$12,$11,0x80
	beqz	$12,.L0021d620
	sra	$10,$15,0x4
	andi	$15,$11,0x20
	beqzl	$15,.L0021d5b4
	lw	$14,-8($24)
	lh	$13,12($16)
	bltzl	$13,.L0021d538
	move	$13,$0
	slti	$14,$13,256
.L0021d530:
	li	$15,255
	movz	$13,$15,$14
.L0021d538:
	lui	$15,%hi(D_01dac550)
	addiu	$15,$15,%lo(D_01dac550)
	psubw	$2,$2,$2
	lui	$2,0x2000
	addi	$3,$10,-1
	or	$2,$2,$3
	sq	$2,0($17)
	dsll	$2,$13,0x4
	add	$2,$2,$15
	lw	$3,8($2)
	sw	$17,8($2)
	addiu	$2,$2,16
	sw	$17,4($3)
	sw	$2,4($17)
.L0021d570:
	andi	$15,$11,0x80
.L0021d574:
	beqz	$15,.L0021d59c
	lui	$15,%hi(D_01d9eaa4)
	lui	$13,%hi(D_01d9eaa8)
	lw	$14,%lo(D_01d9eaa4)($15)
	move	$2,$24
	lw	$15,%lo(D_01d9eaa8)($13)
	subu	$14,$24,$14
	addu	$15,$15,$14
	b	.L0021d0a8
	sw	$15,%lo(D_01d9eaa8)($13)
.L0021d59c:
	lui	$14,%hi(D_00359780)
	lw	$15,%lo(D_00359780)($14)
	addiu	$15,$15,-1
	sw	$15,%lo(D_00359780)($14)
	b	.L0021d0a8
	lw	$2,20($16)
.L0021d5b4:
	li	$15,12288
	beqzl	$15,.L0021d5c0
	break	0x7
.L0021d5c0:
	div	$0,$14,$15
	move	$13,$0
	mflo	$15
	bltz	$15,.L0021d5e0
	mflo	$14
	slti	$15,$15,256
	li	$13,255
	movn	$13,$14,$15
.L0021d5e0:
	lui	$15,%hi(D_01dac550)
	addiu	$15,$15,%lo(D_01dac550)
	psubw	$2,$2,$2
	lui	$2,0x2000
	addi	$3,$10,-1
	or	$2,$2,$3
	sq	$2,0($17)
	dsll	$2,$13,0x4
	add	$2,$2,$15
	lw	$3,8($2)
	sw	$17,8($2)
	addiu	$2,$2,16
	sw	$17,4($3)
	sw	$2,4($17)
	b	.L0021d574
	andi	$15,$11,0x80
.L0021d620:
	addiu	$15,$10,-1
	sd	$0,8($17)
	lui	$14,0x7000
	or	$15,$15,$14
	move	$15,$15
	sd	$15,0($17)
	lui	$2,0x1000
	ori	$2,$2,0xa000
.L0021d640:
	lw	$3,0($2)
	nop
	nop
	nop
	nop
	andi	$3,$3,0x100
	bne	$0,$3,.L0021d640
	lui	$5,0x8000
	or	$17,$5,$17
	li	$5,-1
	lw	$6,48($2)
	bnel	$6,$5,.L0021d674
	sw	$17,48($2)
.L0021d674:
	lui	$4,0xffff
	ori	$4,$4,0xfff3
	sw	$0,32($2)
	and	$4,$4,$3
	ori	$4,$4,0x105
	sw	$4,0($2)
.L0021d68c:
	lw	$3,0($2)
	nop
	nop
	nop
	nop
	andi	$3,$3,0x100
	bne	$0,$3,.L0021d68c
	nop
	b	.L0021d570
	lhu	$11,2($16)
.L0021d6b4:
	ori	$15,$12,0x56
	andi	$13,$7,0xffff
	move	$15,$15
	lui	$14,0x424
	dsll32	$15,$15,0xf
	ori	$14,$14,0x12e6
	or	$13,$13,$15
	sd	$14,88($17)
	lui	$15,0x1
	ori	$15,$15,0xc001
	dsll32	$15,$15,0xe
	b	.L0021d4c8
	or	$13,$13,$15
.L0021d6e8:
	li	$14,3816
	dsll32	$15,$15,0x1c
	sd	$14,24($17)
	ori	$15,$15,0x1
	sd	$15,16($17)
	lui	$14,0x3
	ori	$14,$14,0xd
	li	$15,5
	sd	$14,48($17)
	sd	$15,32($17)
	lui	$14,0x1db
	li	$15,71
	sd	$15,56($17)
	lq	$15,-29728($14)
	b	.L0021d490
	sq	$15,64($17)
.L0021d728:
	beqz	$15,.L0021d8e0
	li	$15,1
	li	$14,248
	dsll32	$15,$15,0x1d
	sd	$14,24($17)
	ori	$15,$15,0x1
	sd	$15,16($17)
	por	$15,$0,$0
	sq	$15,48($17)
	li	$15,5
	sd	$15,32($17)
.L0021d754:
	lhu	$15,0($4)
	andi	$15,$15,0x8
	beqz	$15,.L0021d8a0
	ori	$14,$12,0x54
	li	$15,-32768
	or	$15,$7,$15
	move	$14,$14
	dsll32	$14,$14,0xf
	andi	$15,$15,0xffff
	li	$13,-32767
	or	$15,$15,$14
	dsll32	$13,$13,0xe
	lui	$14,0x37
	or	$15,$15,$13
	sd	$15,64($17)
	ld	$15,2864($14)
	sd	$15,72($17)
.L0021d798:
	subu	$14,$24,$17
	lhu	$11,2($16)
	addiu	$13,$14,15
	slti	$15,$14,0
	movn	$14,$13,$15
	andi	$12,$11,0x80
	beqz	$12,.L0021d80c
	sra	$10,$14,0x4
	andi	$15,$11,0x20
	beqzl	$15,.L0021d7d8
	lw	$14,-8($24)
	lh	$13,12($16)
	bgez	$13,.L0021d530
	slti	$14,$13,256
	b	.L0021d538
	move	$13,$0
.L0021d7d8:
	li	$15,12288
	beqzl	$15,.L0021d7e4
	break	0x7
.L0021d7e4:
	div	$0,$14,$15
	mflo	$15
	bgez	$15,.L0021d7fc
	mflo	$13
	b	.L0021d5e0
	move	$13,$0
.L0021d7fc:
	slti	$14,$15,256
	li	$15,255
	b	.L0021d5e0
	movz	$13,$15,$14
.L0021d80c:
	addiu	$15,$10,-1
	sd	$0,8($17)
	lui	$14,0x7000
	or	$15,$15,$14
	move	$15,$15
	sd	$15,0($17)
	lui	$2,0x1000
	ori	$2,$2,0xa000
.L0021d82c:
	lw	$3,0($2)
	nop
	nop
	nop
	nop
	andi	$3,$3,0x100
	bne	$0,$3,.L0021d82c
	lui	$5,0x8000
	or	$17,$5,$17
	li	$5,-1
	lw	$6,48($2)
	bnel	$6,$5,.L0021d860
	sw	$17,48($2)
.L0021d860:
	lui	$4,0xffff
	ori	$4,$4,0xfff3
	sw	$0,32($2)
	and	$4,$4,$3
	ori	$4,$4,0x105
	sw	$4,0($2)
.L0021d878:
	lw	$3,0($2)
	nop
	nop
	nop
	nop
	andi	$3,$3,0x100
	bne	$0,$3,.L0021d878
	nop
	b	.L0021d570
	lhu	$11,2($16)
.L0021d8a0:
	ori	$14,$12,0x56
	li	$15,-32768
	or	$15,$7,$15
	move	$14,$14
	dsll32	$14,$14,0xf
	andi	$15,$15,0xffff
	lui	$13,0x1
	or	$15,$15,$14
	ori	$13,$13,0xc001
	lui	$14,0x424
	dsll32	$13,$13,0xe
	ori	$14,$14,0x12e6
	or	$15,$15,$13
	sd	$14,72($17)
	b	.L0021d798
	sd	$15,64($17)
.L0021d8e0:
	li	$14,232
	dsll32	$15,$15,0x1d
	sd	$14,24($17)
	ori	$15,$15,0x1
	li	$13,5
	sd	$15,16($17)
	sd	$13,32($17)
	lhu	$15,2($16)
	andi	$15,$15,0x100
	beqz	$15,.L0021d918
	lui	$14,0x1db
	lq	$15,-29584($14)
.L0021d910:
	b	.L0021d754
	sq	$15,48($17)
.L0021d918:
	lui	$14,0x1db
	b	.L0021d910
	lq	$15,-29728($14)
.L0021d924:
	lhu	$15,2($4)
	move	$9,$0
	lw	$2,4($16)
	lui	$3,0x3c00
	qmtc2	$3,$vf1
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf15
	vitof0.wxyz	$vf15,$vf15
	vmulx.wxyz	$vf15,$vf15,vf1x
	lw	$2,16($16)
	lqc2	$vf28,0($2)
	lqc2	$vf29,16($2)
	lqc2	$vf30,32($2)
	lqc2	$vf31,48($2)
	lw	$3,28($16)
	bnez	$3,.L0021d970
	nop
	move	$3,$2
.L0021d970:
	lqc2	$vf8,0($3)
	lqc2	$vf9,16($3)
	lqc2	$vf10,32($3)
	lqc2	$vf11,48($3)
	paddw	$14,$0,$0
	lui	$14,0x3f80
	prot3w	$14,$14
	paddw	$13,$0,$0
	ppacw	$12,$14,$0
	ld	$11,16($4)
	lhu	$2,10($16)
	lhu	$3,8($16)
	dsll32	$2,$2,0x5
	or	$2,$2,$3
	dadd	$11,$11,$2
	li	$10,0x8000
.L0021d9b0:
	lh	$2,0($25)
	lh	$3,2($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf20
	vitof4.xy	$vf20,$vf20
	qmtc2	$12,$vf24
	vitof4.xy	$vf24,$vf24
	vmulax.wxyz	ACC,$vf28,vf20x
	vmadday.wxyz	ACC,$vf29,vf20y
	vmaddaz.wxyz	ACC,$vf30,vf20z
	vmaddw.wxyz	$vf20,$vf31,vf20w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf20w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021db70
	vmulax.wxyz	ACC,$vf8,vf24x
	vmadday.wxyz	ACC,$vf9,vf24y
	vmaddaz.wxyz	ACC,$vf10,vf24z
	vmaddw.wxyz	$vf24,$vf11,vf24w
	vwaitq
	vmulq.xyz	$vf20,$vf20,Q
	vdiv	Q,vf0w,vf24w
	lh	$2,4($25)
	lh	$3,6($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf23
	vitof4.xy	$vf23,$vf23
	vwaitq
	vmulq.z	$vf24,$vf24,Q
	vmulax.wxyz	ACC,$vf28,vf23x
	vmadday.wxyz	ACC,$vf29,vf23y
	vmaddaz.wxyz	ACC,$vf30,vf23z
	vmaddw.wxyz	$vf23,$vf31,vf23w
	vdiv	Q,vf0w,vf23w
	vmove.z	$vf20,$vf24
	vwaitq
	vmulq.xyz	$vf23,$vf23,Q
	vmove.z	$vf23,$vf24
	vsub.xyz	$vf1,$vf20,$vf12
	vsub.xyz	$vf4,$vf23,$vf12
	vnop
	vnop
	vmax.xyz	$vf5,$vf1,$vf4
	vmini.xyz	$vf6,$vf1,$vf4
	vclipw.xy	$vf5,vf13w
	vclipw.xy	$vf6,vf13w
	vclipw.xy	$vf5,vf14w
	vclipw.xy	$vf6,vf14w
	lui	$2,0x28
	ori	$2,$2,0x514a
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$3,$18
	vclipw.z	$vf5,vf12w
	vclipw.z	$vf6,vf12w
	and	$3,$3,$2
	bnez	$3,.L0021db70
	li	$2,2064
	vftoi4.wxyz	$vf20,$vf20
	vftoi4.wxyz	$vf23,$vf23
	vnop
	vnop
	cfc2.ni	$3,$18
	and	$3,$3,$2
	bnez	$3,.L0021db70
	lbu	$13,7($5)
	paddw	$2,$0,$0
	dsll32	$2,$13,0x5
	paddw	$2,$2,$11
	sq	$2,0($24)
	lw	$2,4($5)
	li	$3,66
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	sd	$2,16($24)
	sd	$3,24($24)
	lw	$2,0($5)
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf1
	vitof0.wxyz	$vf1,$vf1
	vmul.wxyz	$vf1,$vf1,$vf15
	vftoi0.wxyz	$vf1,$vf1
	sqc2	$vf1,48($24)
	lh	$2,8($25)
	lh	$3,10($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf1
	vitof12.xy	$vf1,$vf1
	lh	$2,12($25)
	lh	$3,14($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf4
	vitof12.xy	$vf4,$vf4
	vadd.xy	$vf4,$vf1,$vf4
	sqc2	$vf20,64($24)
	sqc2	$vf23,96($24)
	sw	$0,76($24)
	sw	$0,108($24)
	sqc2	$vf1,32($24)
	sqc2	$vf4,80($24)
	addiu	$9,$9,1
	addiu	$24,$24,112
.L0021db70:
	addi	$15,$15,-1
	addi	$25,$25,16
	addi	$5,$5,8
	bgtz	$15,.L0021d9b0
	nop
	b	.L0021d3fc
	nop
.L0021db8c:
	lui	$7,%hi(D_00359110)
	addiu	$7,$7,%lo(D_00359110)
	lhu	$15,2($4)
	move	$9,$0
	lw	$2,4($16)
	lui	$3,0x3c00
	qmtc2	$3,$vf1
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf15
	vitof0.wxyz	$vf15,$vf15
	vmulx.wxyz	$vf15,$vf15,vf1x
	lw	$2,16($16)
	lqc2	$vf28,0($2)
	lqc2	$vf29,16($2)
	lqc2	$vf30,32($2)
	lqc2	$vf31,48($2)
	lw	$3,28($16)
	bnez	$3,.L0021dbe0
	nop
	move	$3,$2
.L0021dbe0:
	lqc2	$vf8,0($3)
	lqc2	$vf9,16($3)
	lqc2	$vf10,32($3)
	lqc2	$vf11,48($3)
	paddw	$14,$0,$0
	lui	$14,0x3f80
	prot3w	$14,$14
	paddw	$13,$0,$0
	ppacw	$12,$14,$0
	ld	$11,16($4)
	lhu	$2,10($16)
	lhu	$3,8($16)
	dsll32	$2,$2,0x5
	or	$2,$2,$3
	dadd	$11,$11,$2
	li	$10,0x8000
	lhu	$2,2($16)
	andi	$3,$2,0x400
	lqc2	$vf19,32($7)
	bnez	$3,.L0021dc38
	nop
	lqc2	$vf19,48($7)
.L0021dc38:
	andi	$3,$2,0x800
	lqc2	$vf7,0($7)
	bnez	$3,.L0021dc4c
	nop
	lqc2	$vf7,16($7)
.L0021dc4c:
	lh	$2,0($25)
	lh	$3,2($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf20
	vitof4.xy	$vf20,$vf20
	qmtc2	$12,$vf24
	vitof4.xy	$vf24,$vf24
	vmulax.wxyz	ACC,$vf28,vf20x
	vmadday.wxyz	ACC,$vf29,vf20y
	vmaddaz.wxyz	ACC,$vf30,vf20z
	vmaddw.wxyz	$vf20,$vf31,vf20w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf20w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021de44
	vmulax.wxyz	ACC,$vf8,vf24x
	vmadday.wxyz	ACC,$vf9,vf24y
	vmaddaz.wxyz	ACC,$vf10,vf24z
	vmaddw.wxyz	$vf24,$vf11,vf24w
	vmove.wxyz	$vf18,$vf20
	vmulay.w	ACC,$vf0,vf7y
	vmulx.w	$vf4,$vf0,vf7x
	vmaddw.w	$vf4,$vf4,vf24w
	vminiz.w	$vf4,$vf4,vf7z
	vmaxw.w	$vf4,$vf4,vf7w
	vwaitq
	vmulq.xyz	$vf20,$vf20,Q
	vdiv	Q,vf0w,vf24w
	lh	$2,4($25)
	lh	$3,6($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf23
	vitof4.xy	$vf23,$vf23
	vwaitq
	vmulq.z	$vf24,$vf24,Q
	vmulax.wxyz	ACC,$vf28,vf23x
	vmadday.wxyz	ACC,$vf29,vf23y
	vmaddaz.wxyz	ACC,$vf30,vf23z
	vmaddw.wxyz	$vf23,$vf31,vf23w
	vdiv	Q,vf0w,vf23w
	vmove.z	$vf20,$vf24
	vmove.w	$vf20,$vf4
	vwaitq
	vmulq.xyz	$vf23,$vf23,Q
	vmove.z	$vf23,$vf24
	vmove.w	$vf23,$vf4
	vsub.xyz	$vf1,$vf20,$vf12
	vsub.xyz	$vf4,$vf23,$vf12
	vnop
	vnop
	vmax.xyz	$vf5,$vf1,$vf4
	vmini.xyz	$vf6,$vf1,$vf4
	vclipw.xy	$vf5,vf13w
	vclipw.xy	$vf6,vf13w
	vclipw.xy	$vf5,vf14w
	vclipw.xy	$vf6,vf14w
	lui	$2,0x28
	ori	$2,$2,0x514a
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$3,$18
	vclipw.z	$vf5,vf12w
	vclipw.z	$vf6,vf12w
	and	$3,$3,$2
	bnez	$3,.L0021de44
	li	$2,2064
	vftoi4.wxyz	$vf20,$vf20
	vftoi4.wxyz	$vf23,$vf23
	vnop
	vnop
	cfc2.ni	$3,$18
	and	$3,$3,$2
	bnez	$3,.L0021de44
	lbu	$13,7($5)
	paddw	$2,$0,$0
	dsll32	$2,$13,0x5
	paddw	$2,$2,$11
	sq	$2,0($24)
	lw	$2,4($5)
	li	$3,66
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	sd	$2,16($24)
	sd	$3,24($24)
	lw	$2,0($5)
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf1
	vitof0.wxyz	$vf1,$vf1
	vmul.wxyz	$vf1,$vf1,$vf15
	lui	$3,0x3c00
	qmtc2	$3,$vf2
	vmulx.w	$vf4,$vf18,vf19x
	vaddy.w	$vf4,$vf4,vf19y
	vminiz.w	$vf4,$vf4,vf19z
	vmaxw.w	$vf4,$vf4,vf19w
	vmulw.wxyz	$vf1,$vf1,vf4w
	vmulx.wxyz	$vf1,$vf1,vf2x
	vftoi0.wxyz	$vf1,$vf1
	sqc2	$vf1,48($24)
	lh	$2,8($25)
	lh	$3,10($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf1
	vitof12.xy	$vf1,$vf1
	lh	$2,12($25)
	lh	$3,14($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf4
	vitof12.xy	$vf4,$vf4
	vadd.xy	$vf4,$vf1,$vf4
	sqc2	$vf20,64($24)
	sqc2	$vf23,96($24)
	sqc2	$vf1,32($24)
	sqc2	$vf4,80($24)
	addiu	$9,$9,1
	addiu	$24,$24,112
.L0021de44:
	addi	$15,$15,-1
	addi	$25,$25,16
	addi	$5,$5,8
	bgtz	$15,.L0021dc4c
	nop
	b	.L0021d3fc
	nop
.L0021de60:
	andi	$15,$11,0xc00
	bnez	$15,.L0021e528
	nop
	lw	$15,28($16)
	bnez	$15,.L0021e18c
	nop
	lhu	$15,2($4)
	move	$9,$0
	lw	$2,4($16)
	lui	$3,0x3c00
	qmtc2	$3,$vf1
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf15
	vitof0.wxyz	$vf15,$vf15
	vmulx.wxyz	$vf15,$vf15,vf1x
	lw	$2,16($16)
	lqc2	$vf28,0($2)
	lqc2	$vf29,16($2)
	lqc2	$vf30,32($2)
	lqc2	$vf31,48($2)
	paddw	$14,$0,$0
	lui	$14,0x3f80
	prot3w	$14,$14
	paddw	$13,$0,$0
	ppacw	$12,$14,$0
	ld	$11,16($4)
	lhu	$2,10($16)
	lhu	$3,8($16)
	dsll32	$2,$2,0x5
	or	$2,$2,$3
	dadd	$11,$11,$2
	li	$10,0x8000
.L0021dee4:
	lh	$2,0($25)
	lh	$3,2($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf20
	vitof4.xy	$vf20,$vf20
	vmulax.wxyz	ACC,$vf28,vf20x
	vmadday.wxyz	ACC,$vf29,vf20y
	vmaddaz.wxyz	ACC,$vf30,vf20z
	vmaddw.wxyz	$vf20,$vf31,vf20w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf20w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e170
	lh	$2,4($25)
	lh	$3,6($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf21
	vitof4.xy	$vf21,$vf21
	vwaitq
	vmulq.xyz	$vf20,$vf20,Q
	vmulax.wxyz	ACC,$vf28,vf21x
	vmadday.wxyz	ACC,$vf29,vf21y
	vmaddaz.wxyz	ACC,$vf30,vf21z
	vmaddw.wxyz	$vf21,$vf31,vf21w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf21w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e170
	lh	$2,8($25)
	lh	$3,10($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf22
	vitof4.xy	$vf22,$vf22
	vwaitq
	vmulq.xyz	$vf21,$vf21,Q
	vmulax.wxyz	ACC,$vf28,vf22x
	vmadday.wxyz	ACC,$vf29,vf22y
	vmaddaz.wxyz	ACC,$vf30,vf22z
	vmaddw.wxyz	$vf22,$vf31,vf22w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf22w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e170
	lh	$2,12($25)
	lh	$3,14($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf23
	vitof4.xy	$vf23,$vf23
	vwaitq
	vmulq.xyz	$vf22,$vf22,Q
	vmulax.wxyz	ACC,$vf28,vf23x
	vmadday.wxyz	ACC,$vf29,vf23y
	vmaddaz.wxyz	ACC,$vf30,vf23z
	vmaddw.wxyz	$vf23,$vf31,vf23w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf23w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e170
	nop
	vwaitq
	vmulq.xyz	$vf23,$vf23,Q
	vsub.xyz	$vf1,$vf20,$vf12
	vsub.xyz	$vf2,$vf21,$vf12
	vsub.xyz	$vf3,$vf22,$vf12
	vsub.xyz	$vf4,$vf23,$vf12
	vmax.xyz	$vf5,$vf1,$vf2
	vmini.xyz	$vf6,$vf1,$vf2
	vmax.xyz	$vf5,$vf5,$vf3
	vmini.xyz	$vf6,$vf6,$vf3
	vmax.xyz	$vf5,$vf5,$vf4
	vmini.xyz	$vf6,$vf6,$vf4
	vclipw.xy	$vf5,vf13w
	vclipw.xy	$vf6,vf13w
	vclipw.xy	$vf5,vf14w
	vclipw.xy	$vf6,vf14w
	lui	$2,0x28
	ori	$2,$2,0x514a
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$3,$18
	vclipw.z	$vf5,vf12w
	vclipw.z	$vf6,vf12w
	and	$3,$3,$2
	bnez	$3,.L0021e170
	li	$2,2064
	vftoi4.wxyz	$vf20,$vf20
	vftoi4.wxyz	$vf21,$vf21
	vftoi4.wxyz	$vf22,$vf22
	vftoi4.wxyz	$vf23,$vf23
	cfc2.ni	$3,$18
	and	$3,$3,$2
	bnez	$3,.L0021e170
	lbu	$13,7($5)
	paddw	$2,$0,$0
	dsll32	$2,$13,0x5
	paddw	$2,$2,$11
	sq	$2,0($24)
	lw	$2,4($5)
	li	$3,66
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	sd	$2,16($24)
	sd	$3,24($24)
	lw	$2,0($5)
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf1
	vitof0.wxyz	$vf1,$vf1
	vmul.wxyz	$vf1,$vf1,$vf15
	vftoi0.wxyz	$vf1,$vf1
	sqc2	$vf1,48($24)
	sqc2	$vf1,96($24)
	sqc2	$vf1,144($24)
	sqc2	$vf1,192($24)
	lh	$2,16($25)
	lh	$3,18($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf1
	vitof12.xy	$vf1,$vf1
	lh	$2,20($25)
	lh	$3,22($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf4
	vitof12.xy	$vf4,$vf4
	vmove.wxyz	$vf2,$vf1
	vmove.wxyz	$vf3,$vf1
	vadd.x	$vf2,$vf2,$vf4
	vadd.y	$vf3,$vf3,$vf4
	vadd.xy	$vf4,$vf1,$vf4
	sqc2	$vf20,64($24)
	sqc2	$vf21,112($24)
	sqc2	$vf22,160($24)
	sqc2	$vf23,208($24)
	sw	$10,76($24)
	sw	$10,124($24)
	sw	$0,172($24)
	sw	$0,220($24)
	sqc2	$vf1,32($24)
	sqc2	$vf2,80($24)
	sqc2	$vf3,128($24)
	sqc2	$vf4,176($24)
	addiu	$9,$9,1
	addiu	$24,$24,224
.L0021e170:
	addi	$15,$15,-1
	addi	$25,$25,24
	addi	$5,$5,8
	bgtz	$15,.L0021dee4
	nop
	b	.L0021d3fc
	nop
.L0021e18c:
	lhu	$15,2($4)
	move	$9,$0
	lw	$2,4($16)
	lui	$3,0x3c00
	qmtc2	$3,$vf1
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf15
	vitof0.wxyz	$vf15,$vf15
	vmulx.wxyz	$vf15,$vf15,vf1x
	lw	$2,16($16)
	lqc2	$vf28,0($2)
	lqc2	$vf29,16($2)
	lqc2	$vf30,32($2)
	lqc2	$vf31,48($2)
	lw	$3,28($16)
	bnez	$3,.L0021e1d8
	nop
	move	$3,$2
.L0021e1d8:
	lqc2	$vf8,0($3)
	lqc2	$vf9,16($3)
	lqc2	$vf10,32($3)
	lqc2	$vf11,48($3)
	paddw	$14,$0,$0
	lui	$14,0x3f80
	prot3w	$14,$14
	paddw	$13,$0,$0
	ppacw	$12,$14,$0
	ld	$11,16($4)
	lhu	$2,10($16)
	lhu	$3,8($16)
	dsll32	$2,$2,0x5
	or	$2,$2,$3
	dadd	$11,$11,$2
	li	$10,0x8000
.L0021e218:
	lh	$2,0($25)
	lh	$3,2($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf20
	vitof4.xy	$vf20,$vf20
	qmtc2	$12,$vf24
	vitof4.xy	$vf24,$vf24
	vmulax.wxyz	ACC,$vf28,vf20x
	vmadday.wxyz	ACC,$vf29,vf20y
	vmaddaz.wxyz	ACC,$vf30,vf20z
	vmaddw.wxyz	$vf20,$vf31,vf20w
	vdiv	Q,vf0w,vf20w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e50c
	vmulax.wxyz	ACC,$vf8,vf24x
	vmadday.wxyz	ACC,$vf9,vf24y
	vmaddaz.wxyz	ACC,$vf10,vf24z
	vmaddw.wxyz	$vf24,$vf11,vf24w
	vwaitq
	vmulq.xyz	$vf20,$vf20,Q
	vdiv	Q,vf0w,vf24w
	lh	$2,4($25)
	lh	$3,6($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf21
	vitof4.xy	$vf21,$vf21
	qmtc2	$12,$vf25
	vitof4.xy	$vf25,$vf25
	vwaitq
	vmulq.z	$vf20,$vf24,Q
	vmulax.wxyz	ACC,$vf28,vf21x
	vmadday.wxyz	ACC,$vf29,vf21y
	vmaddaz.wxyz	ACC,$vf30,vf21z
	vmaddw.wxyz	$vf21,$vf31,vf21w
	vdiv	Q,vf0w,vf21w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e50c
	vmulax.wxyz	ACC,$vf8,vf25x
	vmadday.wxyz	ACC,$vf9,vf25y
	vmaddaz.wxyz	ACC,$vf10,vf25z
	vmaddw.wxyz	$vf25,$vf11,vf25w
	vwaitq
	vmulq.xyz	$vf21,$vf21,Q
	vdiv	Q,vf0w,vf25w
	lh	$2,8($25)
	lh	$3,10($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf22
	vitof4.xy	$vf22,$vf22
	qmtc2	$12,$vf26
	vitof4.xy	$vf26,$vf26
	vwaitq
	vmulq.z	$vf21,$vf25,Q
	vmulax.wxyz	ACC,$vf28,vf22x
	vmadday.wxyz	ACC,$vf29,vf22y
	vmaddaz.wxyz	ACC,$vf30,vf22z
	vmaddw.wxyz	$vf22,$vf31,vf22w
	vdiv	Q,vf0w,vf22w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e50c
	vmulax.wxyz	ACC,$vf8,vf26x
	vmadday.wxyz	ACC,$vf9,vf26y
	vmaddaz.wxyz	ACC,$vf10,vf26z
	vmaddw.wxyz	$vf26,$vf11,vf26w
	vwaitq
	vmulq.xyz	$vf22,$vf22,Q
	vdiv	Q,vf0w,vf26w
	lh	$2,12($25)
	lh	$3,14($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf23
	vitof4.xy	$vf23,$vf23
	qmtc2	$12,$vf27
	vitof4.xy	$vf27,$vf27
	vwaitq
	vmulq.z	$vf22,$vf26,Q
	vmulax.wxyz	ACC,$vf28,vf23x
	vmadday.wxyz	ACC,$vf29,vf23y
	vmaddaz.wxyz	ACC,$vf30,vf23z
	vmaddw.wxyz	$vf23,$vf31,vf23w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf23w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e50c
	vmulax.wxyz	ACC,$vf28,vf27x
	vmadday.wxyz	ACC,$vf29,vf27y
	vmaddaz.wxyz	ACC,$vf30,vf27z
	vmaddw.wxyz	$vf27,$vf31,vf27w
	vwaitq
	vmulq.xyz	$vf23,$vf23,Q
	vdiv	Q,vf0w,vf27w
	vwaitq
	vmulq.z	$vf23,$vf27,Q
	vsub.xyz	$vf1,$vf20,$vf12
	vsub.xyz	$vf2,$vf21,$vf12
	vsub.xyz	$vf3,$vf22,$vf12
	vsub.xyz	$vf4,$vf23,$vf12
	vmax.xyz	$vf5,$vf1,$vf2
	vmini.xyz	$vf6,$vf1,$vf2
	vmax.xyz	$vf5,$vf5,$vf3
	vmini.xyz	$vf6,$vf6,$vf3
	vmax.xyz	$vf5,$vf5,$vf4
	vmini.xyz	$vf6,$vf6,$vf4
	vclipw.xy	$vf5,vf13w
	vclipw.xy	$vf6,vf13w
	vclipw.xy	$vf5,vf14w
	vclipw.xy	$vf6,vf14w
	lui	$2,0x28
	ori	$2,$2,0x514a
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$3,$18
	vclipw.z	$vf5,vf12w
	vclipw.z	$vf6,vf12w
	and	$3,$3,$2
	bnez	$3,.L0021e50c
	li	$2,2064
	vftoi4.wxyz	$vf20,$vf20
	vftoi4.wxyz	$vf21,$vf21
	vftoi4.wxyz	$vf22,$vf22
	vftoi4.wxyz	$vf23,$vf23
	cfc2.ni	$3,$18
	and	$3,$3,$2
	bnez	$3,.L0021e50c
	lbu	$13,7($5)
	paddw	$2,$0,$0
	dsll32	$2,$13,0x5
	paddw	$2,$2,$11
	sq	$2,0($24)
	lw	$2,4($5)
	li	$3,66
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	sd	$2,16($24)
	sd	$3,24($24)
	lw	$2,0($5)
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf1
	vitof0.wxyz	$vf1,$vf1
	vmul.wxyz	$vf1,$vf1,$vf15
	vftoi0.wxyz	$vf1,$vf1
	sqc2	$vf1,48($24)
	sqc2	$vf1,96($24)
	sqc2	$vf1,144($24)
	sqc2	$vf1,192($24)
	lh	$2,16($25)
	lh	$3,18($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf1
	vitof12.xy	$vf1,$vf1
	lh	$2,20($25)
	lh	$3,22($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf4
	vitof12.xy	$vf4,$vf4
	vmove.wxyz	$vf2,$vf1
	vmove.wxyz	$vf3,$vf1
	vadd.x	$vf2,$vf2,$vf4
	vadd.y	$vf3,$vf3,$vf4
	vadd.xy	$vf4,$vf1,$vf4
	sqc2	$vf20,64($24)
	sqc2	$vf21,112($24)
	sqc2	$vf22,160($24)
	sqc2	$vf23,208($24)
	sw	$10,76($24)
	sw	$10,124($24)
	sw	$0,172($24)
	sw	$0,220($24)
	sqc2	$vf1,32($24)
	sqc2	$vf2,80($24)
	sqc2	$vf3,128($24)
	sqc2	$vf4,176($24)
	addiu	$9,$9,1
	addiu	$24,$24,224
.L0021e50c:
	addi	$15,$15,-1
	addi	$25,$25,24
	addi	$5,$5,8
	bgtz	$15,.L0021e218
	nop
	b	.L0021d3fc
	nop
.L0021e528:
	lui	$7,%hi(D_00359110)
	addiu	$7,$7,%lo(D_00359110)
	lhu	$15,2($4)
	move	$9,$0
	lw	$2,4($16)
	lui	$3,0x3c00
	qmtc2	$3,$vf1
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf15
	vitof0.wxyz	$vf15,$vf15
	vmulx.wxyz	$vf15,$vf15,vf1x
	lw	$2,16($16)
	lqc2	$vf28,0($2)
	lqc2	$vf29,16($2)
	lqc2	$vf30,32($2)
	lqc2	$vf31,48($2)
	lw	$3,28($16)
	bnez	$3,.L0021e57c
	nop
	move	$3,$2
.L0021e57c:
	lqc2	$vf8,0($3)
	lqc2	$vf9,16($3)
	lqc2	$vf10,32($3)
	lqc2	$vf11,48($3)
	paddw	$14,$0,$0
	lui	$14,0x3f80
	prot3w	$14,$14
	paddw	$13,$0,$0
	ppacw	$12,$14,$0
	ld	$11,16($4)
	lhu	$2,10($16)
	lhu	$3,8($16)
	dsll32	$2,$2,0x5
	or	$2,$2,$3
	dadd	$11,$11,$2
	li	$10,0x8000
	lhu	$2,2($16)
	andi	$3,$2,0x400
	lqc2	$vf19,32($7)
	bnez	$3,.L0021e5d4
	nop
	lqc2	$vf19,48($7)
.L0021e5d4:
	andi	$3,$2,0x800
	lqc2	$vf7,0($7)
	bnez	$3,.L0021e5e8
	nop
	lqc2	$vf7,16($7)
.L0021e5e8:
	lh	$2,0($25)
	lh	$3,2($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf20
	vitof4.xy	$vf20,$vf20
	qmtc2	$12,$vf24
	vitof4.xy	$vf24,$vf24
	vmulax.wxyz	ACC,$vf28,vf20x
	vmadday.wxyz	ACC,$vf29,vf20y
	vmaddaz.wxyz	ACC,$vf30,vf20z
	vmaddw.wxyz	$vf20,$vf31,vf20w
	vdiv	Q,vf0w,vf20w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e924
	vmulax.wxyz	ACC,$vf8,vf24x
	vmadday.wxyz	ACC,$vf9,vf24y
	vmaddaz.wxyz	ACC,$vf10,vf24z
	vmaddw.wxyz	$vf24,$vf11,vf24w
	vmove.wxyz	$vf18,$vf20
	vmulay.w	ACC,$vf0,vf7y
	vmulx.w	$vf4,$vf0,vf7x
	vmaddw.w	$vf4,$vf4,vf24w
	vminiz.w	$vf4,$vf4,vf7z
	vmaxw.w	$vf4,$vf4,vf7w
	vwaitq
	vmulq.xyz	$vf20,$vf20,Q
	vdiv	Q,vf0w,vf24w
	lh	$2,4($25)
	lh	$3,6($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf21
	vitof4.xy	$vf21,$vf21
	qmtc2	$12,$vf25
	vitof4.xy	$vf25,$vf25
	vwaitq
	vmulq.z	$vf20,$vf24,Q
	vmove.w	$vf20,$vf4
	vmulax.wxyz	ACC,$vf28,vf21x
	vmadday.wxyz	ACC,$vf29,vf21y
	vmaddaz.wxyz	ACC,$vf30,vf21z
	vmaddw.wxyz	$vf21,$vf31,vf21w
	vdiv	Q,vf0w,vf21w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e924
	vmulax.wxyz	ACC,$vf8,vf25x
	vmadday.wxyz	ACC,$vf9,vf25y
	vmaddaz.wxyz	ACC,$vf10,vf25z
	vmaddw.wxyz	$vf25,$vf11,vf25w
	vwaitq
	vmulq.xyz	$vf21,$vf21,Q
	vdiv	Q,vf0w,vf25w
	lh	$2,8($25)
	lh	$3,10($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf22
	vitof4.xy	$vf22,$vf22
	qmtc2	$12,$vf26
	vitof4.xy	$vf26,$vf26
	vwaitq
	vmulq.z	$vf21,$vf25,Q
	vmove.w	$vf21,$vf4
	vmulax.wxyz	ACC,$vf28,vf22x
	vmadday.wxyz	ACC,$vf29,vf22y
	vmaddaz.wxyz	ACC,$vf30,vf22z
	vmaddw.wxyz	$vf22,$vf31,vf22w
	vdiv	Q,vf0w,vf22w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e924
	vmulax.wxyz	ACC,$vf8,vf26x
	vmadday.wxyz	ACC,$vf9,vf26y
	vmaddaz.wxyz	ACC,$vf10,vf26z
	vmaddw.wxyz	$vf26,$vf11,vf26w
	vwaitq
	vmulq.xyz	$vf22,$vf22,Q
	vdiv	Q,vf0w,vf26w
	lh	$2,12($25)
	lh	$3,14($25)
	pextlw	$2,$3,$2
	move	$12,$2
	qmtc2	$12,$vf23
	vitof4.xy	$vf23,$vf23
	qmtc2	$12,$vf27
	vitof4.xy	$vf27,$vf27
	vwaitq
	vmulq.z	$vf22,$vf26,Q
	vmove.w	$vf22,$vf4
	vmulax.wxyz	ACC,$vf28,vf23x
	vmadday.wxyz	ACC,$vf29,vf23y
	vmaddaz.wxyz	ACC,$vf30,vf23z
	vmaddw.wxyz	$vf23,$vf31,vf23w
	vnop
	vnop
	vnop
	vdiv	Q,vf0w,vf23w
	cfc2.ni	$2,$17
	andi	$2,$2,0x11
	bnez	$2,.L0021e924
	vmulax.wxyz	ACC,$vf28,vf27x
	vmadday.wxyz	ACC,$vf29,vf27y
	vmaddaz.wxyz	ACC,$vf30,vf27z
	vmaddw.wxyz	$vf27,$vf31,vf27w
	vwaitq
	vmulq.xyz	$vf23,$vf23,Q
	vdiv	Q,vf0w,vf27w
	vwaitq
	vmulq.z	$vf23,$vf27,Q
	vmove.w	$vf23,$vf4
	vsub.xyz	$vf1,$vf20,$vf12
	vsub.xyz	$vf2,$vf21,$vf12
	vsub.xyz	$vf3,$vf22,$vf12
	vsub.xyz	$vf4,$vf23,$vf12
	vmax.xyz	$vf5,$vf1,$vf2
	vmini.xyz	$vf6,$vf1,$vf2
	vmax.xyz	$vf5,$vf5,$vf3
	vmini.xyz	$vf6,$vf6,$vf3
	vmax.xyz	$vf5,$vf5,$vf4
	vmini.xyz	$vf6,$vf6,$vf4
	vclipw.xy	$vf5,vf13w
	vclipw.xy	$vf6,vf13w
	vclipw.xy	$vf5,vf14w
	vclipw.xy	$vf6,vf14w
	lui	$2,0x28
	ori	$2,$2,0x514a
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$3,$18
	vclipw.z	$vf5,vf12w
	vclipw.z	$vf6,vf12w
	and	$3,$3,$2
	bnez	$3,.L0021e924
	li	$2,2064
	vftoi4.wxyz	$vf20,$vf20
	vftoi4.wxyz	$vf21,$vf21
	vftoi4.wxyz	$vf22,$vf22
	vftoi4.wxyz	$vf23,$vf23
	cfc2.ni	$3,$18
	and	$3,$3,$2
	bnez	$3,.L0021e924
	lbu	$13,7($5)
	paddw	$2,$0,$0
	dsll32	$2,$13,0x5
	paddw	$2,$2,$11
	sq	$2,0($24)
	lw	$2,4($5)
	li	$3,66
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	sd	$2,16($24)
	sd	$3,24($24)
	lw	$2,0($5)
	pextlb	$2,$0,$2
	pextlh	$2,$0,$2
	qmtc2	$2,$vf1
	vitof0.wxyz	$vf1,$vf1
	vmul.wxyz	$vf1,$vf1,$vf15
	lui	$3,0x3c00
	qmtc2	$3,$vf2
	vmulx.w	$vf4,$vf18,vf19x
	vaddy.w	$vf4,$vf4,vf19y
	vminiz.w	$vf4,$vf4,vf19z
	vmaxw.w	$vf4,$vf4,vf19w
	vmulw.wxyz	$vf1,$vf1,vf4w
	vmulx.wxyz	$vf1,$vf1,vf2x
	vftoi0.wxyz	$vf1,$vf1
	sqc2	$vf1,48($24)
	sqc2	$vf1,96($24)
	sqc2	$vf1,144($24)
	sqc2	$vf1,192($24)
	lh	$2,16($25)
	lh	$3,18($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf1
	vitof12.xy	$vf1,$vf1
	lh	$2,20($25)
	lh	$3,22($25)
	pextlw	$2,$3,$2
	move	$14,$2
	qmtc2	$14,$vf4
	vitof12.xy	$vf4,$vf4
	vmove.wxyz	$vf2,$vf1
	vmove.wxyz	$vf3,$vf1
	vadd.x	$vf2,$vf2,$vf4
	vadd.y	$vf3,$vf3,$vf4
	vadd.xy	$vf4,$vf1,$vf4
	sqc2	$vf20,64($24)
	sqc2	$vf21,112($24)
	sqc2	$vf22,160($24)
	sqc2	$vf23,208($24)
	lw	$2,220($24)
	or	$2,$10,$2
	sw	$2,76($24)
	sw	$2,124($24)
	sqc2	$vf1,32($24)
	sqc2	$vf2,80($24)
	sqc2	$vf3,128($24)
	sqc2	$vf4,176($24)
	addiu	$9,$9,1
	addiu	$24,$24,224
.L0021e924:
	addi	$15,$15,-1
	addi	$25,$25,24
	addi	$5,$5,8
	bgtz	$15,.L0021e5e8
	nop
	b	.L0021d3fc
	nop
.L0021e940:
	b	.L0021d184
	lui	$18,%hi(D_01da8cd0)
.L0021e948:
	lui	$10,%hi(D_00359780)
	lui	$13,%hi(D_00359788)
	lw	$12,%lo(D_00359780)($10)
	addiu	$13,$13,%lo(D_00359788)
	sll	$15,$12,0x2
	addu	$15,$15,$13
	addiu	$12,$12,1
	lw	$11,0($15)
	sll	$14,$12,0x2
	addu	$14,$14,$13
	sw	$12,%lo(D_00359780)($10)
	addiu	$15,$11,8192
	move	$24,$11
	b	.L0021d150
	sw	$15,0($14)
	.end func_0021d048
	.size func_0021d048, 6460

