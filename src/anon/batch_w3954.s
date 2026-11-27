# Whole-function assembly (last step of the README match ladder, w3954 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   pppSnoMdlDttNormDraw: partMng GS packet builder; the middle is one long hand-written VU0 block
#     (transform/clip per triangle, ctc2/cfc2 flag polling) branching back into compiled code.
#     Closest C: ~/re/kh2/tmp.w3954/best_0020d528.cpp (= best/0020d528_w3947_nosched.cpp,
#     ~340 of 559 lines off under _nosched): prologue/schedule order, s-register choice, packet half-buffer locals.
#     No symbol, written as literal lui values: 0x00370708/0x00370710 (u64 GIF tag constants),
#     0x3a800000/0x45800000 (float bit patterns), 0x70000000 (scratchpad).
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0020d528,"ax",@progbits
	.globl pppSnoMdlDttNormDraw
	.type pppSnoMdlDttNormDraw, @function
	.ent pppSnoMdlDttNormDraw
pppSnoMdlDttNormDraw:
	addiu	$29,$29,-96
	sd	$17,24($29)
	sd	$18,32($29)
	sd	$16,16($29)
	andi	$17,$5,0xff
	sd	$19,40($29)
	move	$18,$4
	sd	$20,48($29)
	sd	$21,56($29)
	sd	$22,64($29)
	sd	$23,72($29)
	sd	$30,80($29)
	sd	$31,88($29)
	lw	$15,28($4)
	lw	$22,56($18)
	lw	$14,4($15)
	lw	$21,60($18)
	lw	$4,24($4)
	addu	$15,$15,$14
	li	$14,1
	sw	$15,0($29)
	addiu	$4,$4,224
	por	$15,$0,$0
	lui	$15,0x7000
	ori	$15,$15,0x2
	sq	$15,0($4)
	sw	$14,4($29)
	li	$15,1
	dsll32	$15,$15,0x1c
	ori	$15,$15,0x8001
	li	$14,14
	sd	$15,16($4)
	sd	$14,24($4)
	lbu	$15,72($18)
	beqz	$15,.L0020ddd8
	move	$13,$4
	li	$15,71
	lui	$14,0x2
.L0020d5c0:
	sd	$15,40($4)
	ori	$14,$14,0x1001
	sd	$14,32($4)
	jal	func_001e7470
	move	$4,$13
	jal	func_0020eaf8
	li	$4,288
	bnez	$22,.L0020d5f0
	move	$16,$2
	lw	$14,28($18)
	lw	$15,8($14)
	addu	$22,$14,$15
.L0020d5f0:
	bnezl	$21,.L0020d608
	lui	$15,0x37
	lw	$14,28($18)
	lw	$15,12($14)
	addu	$21,$14,$15
	lui	$15,0x37
.L0020d608:
	ld	$14,1800($15)
	sd	$14,0($16)
	lui	$15,0x37
	ld	$14,1808($15)
	sd	$14,8($16)
	li	$15,6
	ld	$13,8($18)
	sd	$15,24($16)
	sd	$13,16($16)
	beqz	$17,.L0020d638
	li	$15,68
	andi	$15,$17,0xff
.L0020d638:
	sd	$15,48($16)
	addiu	$11,$16,256
	li	$15,66
	sd	$15,56($16)
	ld	$12,40($18)
	dsrl32	$13,$12,0x10
	dsrl	$15,$12,0x10
	andi	$13,$13,0x7ff
	andi	$15,$15,0x7ff
	andi	$14,$12,0x7ff
	daddiu	$13,$13,-1
	daddiu	$15,$15,-1
	dsll32	$13,$13,0x2
	dsll	$14,$14,0x4
	dsll	$15,$15,0xe
	dsrl32	$12,$12,0x0
	or	$14,$14,$13
	ori	$15,$15,0xa
	andi	$12,$12,0x7ff
	or	$14,$14,$15
	dsll	$12,$12,0x18
	or	$14,$14,$12
	li	$15,8
	sd	$15,88($16)
	sd	$14,80($16)
	lhu	$15,0($18)
	daddiu	$15,$15,-8
	dsll32	$15,$15,0x0
	dsra32	$15,$15,0x0
	sw	$15,240($16)
	lhu	$14,4($18)
	daddiu	$14,$14,-8
	dsll32	$14,$14,0x0
	dsra32	$14,$14,0x0
	sw	$14,244($16)
	lw	$15,52($18)
	lw	$13,20($18)
	lw	$30,36($18)
	lw	$12,16($18)
	lw	$14,48($18)
	vsub.wxyz	$vf9,$vf0,$vf0
	lqc2	$vf31,0($12)
	vmove.x	$vf1,$vf31
	lqc2	$vf31,16($12)
	vmove.y	$vf1,$vf31
	lqc2	$vf2,32($12)
	lqc2	$vf31,48($12)
	vmove.wz	$vf1,$vf31
	lqc2	$vf16,0($13)
	lqc2	$vf17,16($13)
	lqc2	$vf18,32($13)
	lqc2	$vf19,48($13)
	lqc2	$vf29,32($18)
	lqc2	$vf5,0($16)
	lqc2	$vf6,16($16)
	lqc2	$vf8,48($16)
	lqc2	$vf10,80($16)
	lui	$2,0x3a80
	qmtc2	$2,$vf31
	vaddx.z	$vf4,$vf0,$vf31x
	lqc2	$vf12,240($16)
	vitof4.wxyz	$vf12,$vf12
	lui	$2,0x4580
	qmtc2	$2,$vf31
	vaddx.xy	$vf4,$vf0,$vf31x
	lqc2	$vf23,0($14)
	lqc2	$vf24,0($15)
	lw	$15,0($29)
	lbu	$13,1($15)
	lw	$14,0($29)
.L0020d750:
	lw	$15,0($29)
	lh	$19,2($14)
	addiu	$17,$15,16
	sll	$14,$13,0x18
	li	$15,1
	sra	$14,$14,0x18
	bnel	$14,$15,.L0020dd70
	li	$4,1
	li	$15,28
	mult	$15,$19,$15
	addu	$15,$17,$15
	blez	$19,.L0020dd4c
	sw	$15,0($29)
	addiu	$23,$16,272
	li	$20,6
.L0020d78c:
	lw	$4,24($18)
	lw	$13,4($29)
	lhu	$14,12($17)
	addiu	$15,$4,224
	movz	$4,$15,$13
	mult	$14,$14,$20
	xori	$13,$13,0x1
	sw	$13,4($29)
	addu	$13,$22,$14
	lh	$15,0($13)
	sw	$15,96($16)
	lh	$14,2($13)
	sw	$14,100($16)
	lh	$13,4($13)
	sw	$13,104($16)
	lhu	$15,14($17)
	mult	$15,$15,$20
	addu	$13,$22,$15
	lh	$14,0($13)
	sw	$14,112($16)
	lh	$15,2($13)
	sw	$15,116($16)
	lh	$14,4($13)
	sw	$14,120($16)
	lhu	$15,16($17)
	mult	$15,$15,$20
	addu	$13,$22,$15
	lh	$14,0($13)
	sw	$14,128($16)
	lh	$15,2($13)
	sw	$15,132($16)
	lh	$14,4($13)
	sw	$14,136($16)
	lbu	$15,0($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,192($16)
	lbu	$15,1($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,196($16)
	lbu	$15,2($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,200($16)
	lbu	$15,3($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,204($16)
	lbu	$15,4($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,208($16)
	lbu	$15,5($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,212($16)
	lbu	$15,6($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,216($16)
	lbu	$15,7($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,220($16)
	lbu	$15,8($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,224($16)
	lbu	$15,9($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,228($16)
	lbu	$15,10($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,232($16)
	lbu	$15,11($17)
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	swc1	$f0,236($16)
	lhu	$15,20($17)
	mult	$15,$15,$20
	addu	$13,$21,$15
	lh	$14,0($13)
	sw	$14,144($16)
	lh	$15,2($13)
	sw	$15,148($16)
	lh	$14,4($13)
	sw	$14,152($16)
	lhu	$15,22($17)
	mult	$15,$15,$20
	addu	$13,$21,$15
	lh	$14,0($13)
	sw	$14,160($16)
	lh	$15,2($13)
	sw	$15,164($16)
	lh	$14,4($13)
	sw	$14,168($16)
	lhu	$15,24($17)
	mult	$15,$15,$20
	addu	$13,$21,$15
	lh	$14,0($13)
	sw	$14,176($16)
	lh	$15,2($13)
	sw	$15,180($16)
	lh	$14,4($13)
	sw	$14,184($16)
	lw	$13,64($18)
	lw	$15,68($18)
	lqc2	$vf31,96($16)
	vitof0.wxyz	$vf31,$vf31
	vaddax.wxyz	ACC,$vf19,$vf0x
	vmaddax.wxyz	ACC,$vf16,$vf31x
	vmadday.wxyz	ACC,$vf17,$vf31y
	vmaddz.xyz	$vf22,$vf18,$vf31z
	vaddax.wz	ACC,$vf1,$vf0x
	vmulax.x	ACC,$vf1,$vf22x
	vmulay.y	ACC,$vf1,$vf22y
	vmaddz.wxyz	$vf11,$vf2,$vf22z
	vdiv	Q,$vf0w,$vf11w
	vwaitq
	vaddq.w	$vf22,$vf1,Q
	vmulq.xyz	$vf11,$vf11,Q
	vnop
	ctc2.ni	$0,$16
	vsub.w	$vf0,$vf11,$vf0
	vsub.xy	$vf0,$vf11,$vf0
	vsub.xy	$vf0,$vf4,$vf11
	vnop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$2,$16
	andi	$14,$2,0xc0
	bnez	$14,.L0020dd1c
	vnop
	lqc2	$vf31,112($16)
	vitof0.wxyz	$vf31,$vf31
	vaddax.wxyz	ACC,$vf19,$vf0x
	vmaddax.wxyz	ACC,$vf16,$vf31x
	vmadday.wxyz	ACC,$vf17,$vf31y
	vmaddz.xyz	$vf21,$vf18,$vf31z
	vaddax.wz	ACC,$vf1,$vf0x
	vmulax.x	ACC,$vf1,$vf21x
	vmulay.y	ACC,$vf1,$vf21y
	vmaddz.wxyz	$vf25,$vf2,$vf21z
	vdiv	Q,$vf0w,$vf25w
	vwaitq
	vaddq.w	$vf21,$vf1,Q
	vmulq.xyz	$vf25,$vf25,Q
	vnop
	ctc2.ni	$0,$16
	vsub.w	$vf0,$vf25,$vf0
	vsub.xy	$vf0,$vf25,$vf0
	vsub.xy	$vf0,$vf4,$vf25
	vnop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$2,$16
	andi	$14,$2,0xc0
	bnez	$14,.L0020dd1c
	vnop
	lqc2	$vf31,128($16)
	vitof0.wxyz	$vf31,$vf31
	vaddax.wxyz	ACC,$vf19,$vf0x
	vmaddax.wxyz	ACC,$vf16,$vf31x
	vmadday.wxyz	ACC,$vf17,$vf31y
	vmaddz.xyz	$vf20,$vf18,$vf31z
	vaddax.wz	ACC,$vf1,$vf0x
	vmulax.x	ACC,$vf1,$vf20x
	vmulay.y	ACC,$vf1,$vf20y
	vmaddz.wxyz	$vf26,$vf2,$vf20z
	vdiv	Q,$vf0w,$vf26w
	vwaitq
	vaddq.w	$vf20,$vf1,Q
	vmulq.xyz	$vf26,$vf26,Q
	vnop
	ctc2.ni	$0,$16
	vsub.w	$vf0,$vf26,$vf0
	vsub.xy	$vf0,$vf26,$vf0
	vsub.xy	$vf0,$vf4,$vf26
	vnop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$2,$16
	andi	$14,$2,0xc0
	bnez	$14,.L0020dd1c
	vnop
	beqz	$13,.L0020dad0
	nop
	vsub.xyz	$vf28,$vf25,$vf11
	vsub.xyz	$vf3,$vf26,$vf25
	vopmula.xyz	ACC,$vf28,$vf3
	vopmsub.xyz	$vf0,$vf3,$vf28
	vnop
	vnop
	vnop
	vnop
	vnop
	cfc2.ni	$2,$17
	andi	$2,$2,0x20
	bnez	$2,.L0020dd1c
	addi	$14,$0,128
.L0020dad0:
	sqc2	$vf5,16($4)
	sqc2	$vf6,32($4)
	sqc2	$vf8,48($4)
	sqc2	$vf10,64($4)
	lqc2	$vf30,192($16)
	vmul.wxyz	$vf30,$vf30,$vf23
	vftoi0.wxyz	$vf30,$vf30
	sqc2	$vf30,96($4)
	beqz	$15,.L0020db04
	nop
	vsub.wxyz	$vf28,$vf22,$vf19
	j	.L0020db1c
	nop
.L0020db04:
	lqc2	$vf28,144($16)
	vitof12.wxyz	$vf28,$vf28
	vaddax.wxyz	ACC,$vf0,$vf0x
	vmaddax.wxyz	ACC,$vf16,$vf28x
	vmadday.wxyz	ACC,$vf17,$vf28y
	vmaddz.xyz	$vf28,$vf18,$vf28z
.L0020db1c:
	vmul.xyz	$vf31,$vf28,$vf28
	vaddy.x	$vf31,$vf31,$vf31y
	vaddz.x	$vf31,$vf31,$vf31z
	vsqrt	Q,$vf31x
	vaddz.x	$vf14,$vf0,$vf11z
	vftoi4.xyz	$vf9,$vf11
	sqc2	$vf9,112($4)
	vaddw.z	$vf15,$vf0,$vf0w
	vwaitq
	vaddq.z	$vf12,$vf0,Q
	vdiv	Q,$vf0w,$vf12z
	vwaitq
	vmulq.xyz	$vf31,$vf28,Q
	beqz	$15,.L0020db5c
	nop
	vmove.wxyz	$vf28,$vf31
.L0020db5c:
	beqz	$30,.L0020db68
	nop
	vmulz.xy	$vf28,$vf28,$vf31z
.L0020db68:
	vmulx.xyz	$vf28,$vf28,$vf29x
	vadd.xyz	$vf28,$vf28,$vf22
	vmulaw.wz	ACC,$vf1,$vf0w
	vmula.xy	ACC,$vf1,$vf28
	vmaddz.wxyz	$vf28,$vf2,$vf28z
	vdiv	Q,$vf0w,$vf28w
	vwaitq
	vmulq.xyz	$vf28,$vf28,Q
	vaddw.z	$vf15,$vf0,$vf0w
	vsub.xy	$vf28,$vf28,$vf12
	vmulz.xy	$vf15,$vf28,$vf4z
	sqc2	$vf15,80($4)
	lqc2	$vf30,208($16)
	vmul.wxyz	$vf30,$vf30,$vf23
	vftoi0.wxyz	$vf30,$vf30
	sqc2	$vf30,144($4)
	beqz	$15,.L0020dbbc
	nop
	vsub.wxyz	$vf28,$vf21,$vf19
	j	.L0020dbd4
	nop
.L0020dbbc:
	lqc2	$vf28,160($16)
	vitof12.wxyz	$vf28,$vf28
	vaddax.wxyz	ACC,$vf0,$vf0x
	vmaddax.wxyz	ACC,$vf16,$vf28x
	vmadday.wxyz	ACC,$vf17,$vf28y
	vmaddz.xyz	$vf28,$vf18,$vf28z
.L0020dbd4:
	vmul.xyz	$vf31,$vf28,$vf28
	vaddy.x	$vf31,$vf31,$vf31y
	vaddz.x	$vf31,$vf31,$vf31z
	vsqrt	Q,$vf31x
	vaddz.y	$vf14,$vf0,$vf25z
	vftoi4.xyz	$vf9,$vf25
	sqc2	$vf9,160($4)
	vaddw.z	$vf15,$vf0,$vf0w
	vwaitq
	vaddq.z	$vf12,$vf0,Q
	vdiv	Q,$vf0w,$vf12z
	vwaitq
	vmulq.xyz	$vf31,$vf28,Q
	beqz	$15,.L0020dc14
	nop
	vmove.wxyz	$vf28,$vf31
.L0020dc14:
	beqz	$30,.L0020dc20
	nop
	vmulz.xy	$vf28,$vf28,$vf31z
.L0020dc20:
	vmulx.xyz	$vf28,$vf28,$vf29x
	vadd.xyz	$vf28,$vf28,$vf21
	vmulaw.wz	ACC,$vf1,$vf0w
	vmula.xy	ACC,$vf1,$vf28
	vmaddz.wxyz	$vf28,$vf2,$vf28z
	vdiv	Q,$vf0w,$vf28w
	vwaitq
	vmulq.xyz	$vf28,$vf28,Q
	vaddw.z	$vf15,$vf0,$vf0w
	vsub.xy	$vf28,$vf28,$vf12
	vmulz.xy	$vf15,$vf28,$vf4z
	sqc2	$vf15,128($4)
	lqc2	$vf30,224($16)
	vmul.wxyz	$vf30,$vf30,$vf23
	vftoi0.wxyz	$vf30,$vf30
	sqc2	$vf30,192($4)
	beqz	$15,.L0020dc74
	nop
	vsub.wxyz	$vf28,$vf20,$vf19
	j	.L0020dc8c
	nop
.L0020dc74:
	lqc2	$vf28,176($16)
	vitof12.wxyz	$vf28,$vf28
	vaddax.wxyz	ACC,$vf0,$vf0x
	vmaddax.wxyz	ACC,$vf16,$vf28x
	vmadday.wxyz	ACC,$vf17,$vf28y
	vmaddz.xyz	$vf28,$vf18,$vf28z
.L0020dc8c:
	vmul.xyz	$vf31,$vf28,$vf28
	vaddy.x	$vf31,$vf31,$vf31y
	vaddz.x	$vf31,$vf31,$vf31z
	vsqrt	Q,$vf31x
	vaddz.z	$vf14,$vf0,$vf26z
	vftoi4.xyz	$vf9,$vf26
	sqc2	$vf9,208($4)
	vaddw.z	$vf15,$vf0,$vf0w
	vwaitq
	vaddq.z	$vf12,$vf0,Q
	vdiv	Q,$vf0w,$vf12z
	vwaitq
	vmulq.xyz	$vf31,$vf28,Q
	beqz	$15,.L0020dccc
	nop
	vmove.wxyz	$vf28,$vf31
.L0020dccc:
	beqz	$30,.L0020dcd8
	nop
	vmulz.xy	$vf28,$vf28,$vf31z
.L0020dcd8:
	vmulx.xyz	$vf28,$vf28,$vf29x
	vadd.xyz	$vf28,$vf28,$vf20
	vmulaw.wz	ACC,$vf1,$vf0w
	vmula.xy	ACC,$vf1,$vf28
	vmaddz.wxyz	$vf28,$vf2,$vf28z
	vdiv	Q,$vf0w,$vf28w
	vwaitq
	vmulq.xyz	$vf28,$vf28,Q
	vaddw.z	$vf15,$vf0,$vf0w
	vsub.xy	$vf28,$vf28,$vf12
	vmulz.xy	$vf15,$vf28,$vf4z
	sqc2	$vf15,176($4)
	vminix.y	$vf31,$vf14,$vf14x
	vminiy.z	$vf31,$vf14,$vf31y
	vftoi4.wxyz	$vf31,$vf31
	sqc2	$vf31,240($16)
	add	$14,$0,$0
.L0020dd1c:
	bnezl	$14,.L0020ddb8
	li	$4,1
	lui	$15,0x7000
	sd	$0,8($4)
	ori	$15,$15,0xd
	jal	func_001e7470
	sd	$15,0($4)
	addiu	$15,$19,-1
.L0020dd3c:
	sll	$19,$15,0x10
	sra	$19,$19,0x10
	bgtz	$19,.L0020d78c
	addiu	$17,$17,28
.L0020dd4c:
	lw	$14,0($29)
	lbu	$15,1($14)
	move	$13,$15
	sll	$14,$13,0x18
	li	$15,-1
	sra	$14,$14,0x18
	bne	$14,$15,.L0020d750
	lw	$14,0($29)
	li	$4,1
.L0020dd70:
	jal	sceGsSyncPath
	move	$5,$0
	andi	$2,$2,0x10
	bnez	$2,.L0020dd70
	li	$4,1
	ld	$16,16($29)
	li	$4,288
	ld	$17,24($29)
	ld	$18,32($29)
	ld	$19,40($29)
	ld	$20,48($29)
	ld	$21,56($29)
	ld	$22,64($29)
	ld	$23,72($29)
	ld	$30,80($29)
	ld	$31,88($29)
	j	func_0020ebd8
	addiu	$29,$29,96
.L0020ddb8:
	jal	sceGsSyncPath
	move	$5,$0
	andi	$2,$2,0x10
	bnez	$2,.L0020ddb8
	li	$4,1
	b	.L0020dd3c
	addiu	$15,$19,-1
	nop
.L0020ddd8:
	li	$15,71
	b	.L0020d5c0
	lui	$14,0x7
	.end pppSnoMdlDttNormDraw
	.size pppSnoMdlDttNormDraw, 2236

