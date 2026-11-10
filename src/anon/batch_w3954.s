# Whole-function assembly (last step of the README match ladder, w3954 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_0020d528: partMng GS packet builder; the middle is one long hand-written VU0 block
#     (transform/clip per triangle, ctc2/cfc2 flag polling) branching back into compiled code.
#     Closest C: ~/re/kh2/tmp.w3954/best_0020d528.cpp (= coord best/0020d528_w3947_nosched.cpp,
#     ~340 of 559 lines off under _nosched): prologue/schedule order, s-register choice, packet half-buffer locals.
#     No symbol, written as literal lui values: 0x00370708/0x00370710 (u64 GIF tag constants),
#     0x3a800000/0x45800000 (float bit patterns), 0x70000000 (scratchpad).
#   func_001f25d0: scratchpad GS packet builder with float lerp (VU0) and perspective projection
#     per strip vertex, div.s hazard nops, double-buffered DMA packets.
#     Closest C: ~/re/kh2/tmp.w3954/best_001f25d0.c (= coord best/001f25d0_w3830_nsa.c, 216 of 617 lines off
#     under _nsa): global allocation (pkt caller-saved in t2 with sq/lq around calls, i*4 in s8).
#     No symbol, written as literal lui/addiu values: literal pool words 0x00370178, 0x0037017c,
#     0x00370180, 0x00370184 (lui 0x37 + offset), 0x70000000/0x70002000 (scratchpad).
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0020d528,"ax",@progbits
	.globl func_0020d528
	.type func_0020d528, @function
	.ent func_0020d528
func_0020d528:
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
	.end func_0020d528
	.size func_0020d528, 2236

	.section .text.func_001f25d0,"ax",@progbits
	.globl func_001f25d0
	.type func_001f25d0, @function
	.ent func_001f25d0
func_001f25d0:
	addiu	$29,$29,-432
	lui	$12,0x37
	swc1	$f24,416($29)
	addiu	$12,$12,376
	swc1	$f25,420($29)
	swc1	$f22,408($29)
	swc1	$f21,404($29)
	sd	$16,320($29)
	sd	$17,328($29)
	sd	$18,336($29)
	sd	$19,344($29)
	sd	$20,352($29)
	sd	$21,360($29)
	sd	$22,368($29)
	sd	$23,376($29)
	sd	$30,384($29)
	sd	$31,392($29)
	swc1	$f23,412($29)
	swc1	$f20,400($29)
	mtc1	$0,$f24
	sw	$5,260($29)
	sw	$4,256($29)
	mov.s	$f21,$f24
	mov.s	$f25,$f24
	lhu	$15,6($5)
	mov.s	$f22,$f24
	lbu	$11,18($4)
	lwc1	$f23,0($12)
	sltiu	$15,$15,3
	sw	$11,272($29)
	sw	$6,264($29)
	sw	$7,268($29)
	bnez	$15,.L001f2e90
	sw	$0,276($29)
	lbu	$14,8($4)
	li	$15,1
	bne	$14,$15,.L001f2f64
	lui	$15,%hi(D_00352be4)
	lui	$15,%hi(D_00352bec)
	lui	$13,%hi(D_00352bf0)
	lw	$14,%lo(D_00352bec)($15)
	lw	$15,%lo(D_00352bf0)($13)
.L001f2678:
	srl	$13,$15,0x1f
	srl	$12,$14,0x1f
	addu	$15,$15,$13
	addu	$14,$14,$12
	sra	$14,$14,0x1
	sra	$15,$15,0x1
	addiu	$14,$14,-2048
	addiu	$15,$15,-2048
	mtc1	$14,$f0
	lui	$13,0x37
	mtc1	$15,$f1
	addiu	$13,$13,380
	cvt.s.w	$f0,$f0
	lw	$14,256($29)
	cvt.s.w	$f1,$f1
	swc1	$f0,16($29)
	swc1	$f1,20($29)
	lwc1	$f0,0($13)
	lbu	$15,23($14)
	swc1	$f0,4($29)
	beqz	$15,.L001f2754
	swc1	$f0,0($29)
	lwc1	$f1,272($29)
	lui	$15,0x37
	lwc1	$f0,24($14)
	addiu	$15,$15,376
	cvt.s.w	$f1,$f1
	lwc1	$f23,0($15)
	mtc1	$0,$f3
	mul.s	$f2,$f1,$f0
	cvt.w.s	$f0,$f2
	mfc1	$15,$f0
	mtc1	$15,$f2
	cvt.s.w	$f2,$f2
	c.le.s	$f2,$f3
	bc1t	.L001f2714
	sub.s	$f1,$f1,$f2
	mov.s	$f23,$f3
	mtc1	$0,$f3
.L001f2714:
	c.lt.s	$f3,$f2
	bc1f	.L001f2734
	lui	$11,0x37
	addiu	$11,$11,376
	lwc1	$f0,0($11)
	nop
	nop
	div.s	$f25,$f0,$f2
.L001f2734:
	c.lt.s	$f3,$f1
	bc1f	.L001f2754
	lui	$12,0x37
	addiu	$12,$12,376
	lwc1	$f0,0($12)
	nop
	nop
	div.s	$f24,$f0,$f1
.L001f2754:
	lui	$14,0x7000
	lui	$15,0x7000
	ori	$14,$14,0x2000
	sw	$15,64($29)
	sw	$14,68($29)
	lui	$10,0x7000
	ori	$15,$15,0x8
	lui	$13,0x7000
	por	$14,$0,$0
	sq	$14,0($10)
	ori	$13,$13,0x10
	sw	$15,0($10)
	li	$14,7
	dsll32	$14,$14,0x1c
	lui	$15,0xeee
	ori	$14,$14,0x8001
	ori	$15,$15,0xeeee
	sd	$14,0($13)
	sd	$15,8($13)
	lw	$11,256($29)
	lbu	$15,20($11)
	bnez	$15,.L001f2f54
	lui	$15,0x7000
	li	$14,71
	ori	$15,$15,0x20
	lui	$13,0x7
.L001f27bc:
	sd	$14,8($15)
	ori	$13,$13,0xd
	li	$14,1
	sd	$13,0($15)
	lui	$12,0x7000
	dsll32	$14,$14,0x0
	ori	$12,$12,0x30
	lui	$15,%hi(D_00352bf4)
	lw	$13,%lo(D_00352bf4)($15)
	lui	$15,0x3100
	or	$13,$13,$15
	or	$14,$13,$14
	li	$15,78
	sd	$15,8($12)
	sd	$14,0($12)
	li	$15,1
	lw	$12,256($29)
	lbu	$13,8($12)
	bne	$13,$15,.L001f2f40
	lui	$15,%hi(D_00352be4)
	lui	$15,%hi(D_00352bec)
	lui	$11,0x7000
	lw	$14,%lo(D_00352bec)($15)
	lui	$15,%hi(D_00352bf8)
	lw	$13,%lo(D_00352bf8)($15)
.L001f2820:
	slti	$15,$14,0
	addiu	$12,$14,63
	movn	$14,$12,$15
	sll	$13,$13,0x5
	sra	$14,$14,0x6
	ori	$11,$11,0x40
	dsll	$15,$14,0xe
	li	$14,85
	or	$15,$13,$15
	dsll	$14,$14,0x1b
	or	$15,$15,$14
	sd	$15,0($11)
	li	$14,6
	lui	$15,0x7000
	ori	$15,$15,0x40
	sd	$14,8($15)
	lw	$13,256($29)
	li	$15,1
	lbu	$14,21($13)
	beq	$14,$15,.L001f2f24
	li	$20,5
	slti	$15,$14,2
	beqz	$15,.L001f2f00
	li	$15,2
	bnez	$14,.L001f28a4
	li	$13,80
	li	$15,1
	lui	$14,0x7000
	dsll32	$15,$15,0x7
	ori	$14,$14,0x50
	li	$13,80
	ori	$15,$15,0x44
.L001f28a0:
	sd	$15,0($14)
.L001f28a4:
	addu	$14,$13,$10
	li	$15,66
	sd	$15,8($14)
	addiu	$20,$20,1
	sll	$13,$20,0x4
	lui	$4,0x7000
	addu	$13,$13,$10
	li	$15,96
	sd	$15,0($13)
	li	$14,20
	sd	$14,8($13)
	addiu	$20,$20,1
	sll	$15,$20,0x4
	addu	$15,$15,$10
	li	$14,8
	sd	$14,8($15)
	addiu	$20,$20,1
	sd	$0,0($15)
	sll	$14,$20,0x4
	addu	$14,$14,$10
	li	$15,63
	sd	$15,8($14)
	sd	$0,0($14)
	jal	func_001e7470
	sw	$0,288($29)
	jal	func_001e7440
	nop
	lw	$14,256($29)
	por	$13,$0,$0
	lw	$11,64($29)
	li	$10,1042
	lbu	$15,19($14)
	lw	$12,68($29)
	sll	$15,$15,0x1
	addiu	$15,$15,2
	sw	$15,280($29)
	sq	$13,0($12)
	sll	$15,$15,0x1
	lw	$14,280($29)
	sq	$13,0($11)
	addu	$15,$15,$14
	addiu	$15,$15,1
	ori	$13,$14,0x8000
	lui	$14,0x7000
	move	$13,$13
	or	$15,$15,$14
	li	$14,0xc0b9
	sw	$15,0($12)
	dsll32	$14,$14,0xe
	or	$13,$13,$14
	lw	$14,280($29)
	srl	$14,$14,0x1
	sw	$14,280($29)
	sw	$15,0($11)
	sd	$13,16($12)
	sd	$13,16($11)
	sd	$10,24($12)
	sd	$10,24($11)
	lw	$11,264($29)
	lbu	$15,8($11)
	lbu	$12,11($11)
	lbu	$14,9($11)
	lbu	$13,10($11)
	sw	$12,60($29)
	sw	$15,48($29)
	sw	$14,52($29)
	sw	$13,56($29)
	lw	$12,280($29)
	lq	$15,48($29)
	beqz	$12,.L001f2a48
	sq	$15,32($29)
	lw	$13,280($29)
	lw	$14,256($29)
	addiu	$15,$13,-1
	lw	$12,288($29)
	mtc1	$15,$f1
	lbu	$11,23($14)
	lui	$15,0x37
	cvt.s.w	$f1,$f1
	addiu	$15,$15,376
	lw	$5,260($29)
	lui	$14,0x37
	lwc1	$f4,0($15)
	addiu	$14,$14,384
	lwc1	$f3,0($14)
	move	$15,$29
.L001f29fc:
	mtc1	$12,$f0
	cvt.s.w	$f0,$f0
	addiu	$12,$12,1
	slt	$14,$12,$13
	nop
	nop
	div.s	$f2,$f0,$f1
	bnez	$11,.L001f2a38
	swc1	$f2,80($15)
	lwc1	$f0,24($5)
	sub.s	$f2,$f2,$f3
	add.s	$f0,$f0,$f4
	mul.s	$f2,$f2,$f0
	add.s	$f2,$f2,$f3
	swc1	$f2,144($15)
.L001f2a38:
	bnez	$14,.L001f29fc
	addiu	$15,$15,4
	sw	$5,260($29)
	sw	$13,280($29)
.L001f2a48:
	sw	$0,292($29)
	sw	$0,284($29)
	lw	$11,272($29)
	beqz	$11,.L001f2e88
	nop
.L001f2a5c:
	lw	$12,256($29)
	li	$13,1
	lbu	$15,23($12)
	beqz	$15,.L001f2b30
	sw	$13,296($29)
	lui	$14,0x37
	addiu	$14,$14,376
	lwc1	$f0,0($14)
	c.le.s	$f0,$f23
	bc1f	.L001f2a94
	lw	$15,276($29)
	bnezl	$15,.L001f2aa4
	sub.s	$f23,$f23,$f24
	sw	$13,276($29)
.L001f2a94:
	lw	$11,276($29)
	bnezl	$11,.L001f2aa4
	sub.s	$f23,$f23,$f24
	add.s	$f23,$f23,$f25
.L001f2aa4:
	mtc1	$0,$f0
	c.lt.s	$f23,$f0
	bc1tl	.L001f2ad0
	mov.s	$f23,$f0
	lui	$12,0x37
	addiu	$12,$12,376
	lwc1	$f0,0($12)
	c.le.s	$f0,$f23
	bc1f	.L001f2ad4
	lw	$13,280($29)
	mov.s	$f23,$f0
.L001f2ad0:
	lw	$13,280($29)
.L001f2ad4:
	beqz	$13,.L001f2b30
	lw	$14,260($29)
	lui	$12,0x37
	addiu	$12,$12,376
	lui	$11,0x37
	lwc1	$f0,24($14)
	addiu	$11,$11,384
	lwc1	$f2,0($11)
	move	$15,$29
	mul.s	$f1,$f0,$f23
	sw	$13,288($29)
	lwc1	$f0,0($12)
	add.s	$f1,$f1,$f0
.L001f2b08:
	lwc1	$f0,80($15)
	lw	$13,288($29)
	sub.s	$f0,$f0,$f2
	addiu	$13,$13,-1
	sw	$13,288($29)
	mul.s	$f0,$f0,$f1
	add.s	$f0,$f0,$f2
	swc1	$f0,144($15)
	bnez	$13,.L001f2b08
	addiu	$15,$15,4
.L001f2b30:
	lw	$14,256($29)
	lbu	$13,22($14)
	andi	$15,$13,0xff
	beqz	$15,.L001f2b6c
	lw	$11,280($29)
	lui	$12,0x37
	addiu	$12,$12,388
	mtc1	$0,$f21
	addiu	$15,$11,-1
	lwc1	$f0,0($12)
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	nop
	nop
	div.s	$f22,$f0,$f1
.L001f2b6c:
	lw	$14,292($29)
	sll	$15,$14,0x2
	xori	$14,$14,0x1
	addu	$15,$15,$29
	sw	$14,292($29)
	lw	$10,64($15)
	sw	$0,288($29)
	lw	$15,280($29)
	beqz	$15,.L001f2e54
	li	$20,2
	lw	$11,284($29)
	addiu	$22,$29,208
	sll	$11,$11,0x4
	sw	$11,300($29)
.L001f2ba4:
	lw	$11,264($29)
	andi	$13,$13,0xff
	lw	$14,288($29)
	lbu	$15,11($11)
	sll	$30,$14,0x2
	mtc1	$15,$f0
	addu	$14,$30,$29
	lw	$17,80($14)
	beqz	$13,.L001f2bf4
	cvt.s.w	$f0,$f0
	mul.s	$f0,$f0,$f21
	lui	$12,0x37
	addiu	$12,$12,376
	lwc1	$f1,0($12)
	add.s	$f21,$f21,$f22
	c.le.s	$f1,$f21
	bc1fl	.L001f2eec
	mtc1	$0,$f1
	mov.s	$f21,$f1
	neg.s	$f22,$f22
.L001f2bf4:
	cvt.w.s	$f1,$f0
.L001f2bf8:
	lw	$11,268($29)
	lw	$12,300($29)
	addu	$16,$11,$12
	mfc1	$15,$f1
	addiu	$18,$16,4096
	sw	$15,60($29)
	sw	$15,44($29)
	lqc2	$vf4,0($18)
	lqc2	$vf5,0($16)
	qmtc2	$17,$vf6
	vaddw.x	$vf7,$vf0,$vf0w
	vsub.x	$vf8,$vf7,$vf6
	vmulax.wxyz	ACC,$vf4,$vf6x
	vmaddx.wxyz	$vf9,$vf5,$vf8x
	sqc2	$vf9,0($22)
	lui	$13,0x37
	sq	$10,304($29)
	addiu	$13,$13,376
	lui	$15,%hi(D_01d9e8c0)
	lwc1	$f20,0($13)
	addiu	$23,$15,%lo(D_01d9e8c0)
	move	$4,$22
	addiu	$5,$29,224
	swc1	$f20,220($29)
	move	$6,$23
	addiu	$21,$16,4112
	jal	func_001f4640
	addiu	$19,$16,16
	beqz	$2,.L001f2ee4
	lq	$10,304($29)
	lqc2	$vf4,0($21)
	lqc2	$vf5,0($19)
	qmtc2	$17,$vf6
	vaddw.x	$vf7,$vf0,$vf0w
	vsub.x	$vf8,$vf7,$vf6
	vmulax.wxyz	ACC,$vf4,$vf6x
	vmaddx.wxyz	$vf9,$vf5,$vf8x
	sqc2	$vf9,0($22)
	sq	$10,304($29)
	addiu	$5,$29,240
	swc1	$f20,220($29)
	move	$6,$23
	jal	func_001f4640
	move	$4,$22
	lq	$10,304($29)
	beqz	$2,.L001f2ee4
	addu	$14,$30,$29
	lw	$17,144($14)
	lqc2	$vf4,0($18)
	lqc2	$vf5,0($16)
	qmtc2	$17,$vf6
	vaddw.x	$vf7,$vf0,$vf0w
	vsub.x	$vf8,$vf7,$vf6
	vmulax.wxyz	ACC,$vf4,$vf6x
	vmaddx.wxyz	$vf9,$vf5,$vf8x
	sqc2	$vf9,0($22)
	sll	$15,$20,0x4
	swc1	$f20,220($29)
	addu	$15,$10,$15
	addiu	$14,$29,16
	addiu	$20,$20,1
	lqc2	$vf12,0($22)
	lqc2	$vf4,0($23)
	lqc2	$vf5,16($23)
	lqc2	$vf6,32($23)
	lqc2	$vf7,48($23)
	vmulax.wxyz	ACC,$vf4,$vf12x
	vmadday.wxyz	ACC,$vf5,$vf12y
	vmaddaz.wxyz	ACC,$vf6,$vf12z
	vmaddw.wxyz	$vf12,$vf7,$vf12w
	vdiv	Q,$vf0w,$vf12w
	lqc2	$vf4,0($14)
	lqc2	$vf5,0($29)
	vwaitq
	vmulq.xyz	$vf12,$vf12,Q
	vadd.xy	$vf12,$vf12,$vf4
	vmul.xy	$vf12,$vf12,$vf5
	sqc2	$vf12,0($15)
	swc1	$f20,12($15)
	sll	$14,$20,0x4
	swc1	$f20,8($15)
	addu	$14,$14,$10
	addiu	$20,$20,1
	lq	$15,48($29)
	sll	$12,$20,0x4
	addu	$12,$12,$10
	addiu	$20,$20,1
	sq	$15,0($14)
	lw	$13,224($29)
	lw	$14,228($29)
	addiu	$13,$13,-8
	addiu	$14,$14,-8
	sw	$13,224($29)
	sw	$14,228($29)
	lq	$15,224($29)
	sq	$15,0($12)
	lqc2	$vf4,0($21)
	lqc2	$vf5,0($19)
	qmtc2	$17,$vf6
	vaddw.x	$vf7,$vf0,$vf0w
	vsub.x	$vf8,$vf7,$vf6
	vmulax.wxyz	ACC,$vf4,$vf6x
	vmaddx.wxyz	$vf9,$vf5,$vf8x
	sqc2	$vf9,0($22)
	sll	$15,$20,0x4
	swc1	$f20,220($29)
	addu	$15,$10,$15
	addiu	$20,$20,1
	addiu	$11,$29,16
	lqc2	$vf12,0($22)
	lqc2	$vf4,0($23)
	lqc2	$vf5,16($23)
	lqc2	$vf6,32($23)
	lqc2	$vf7,48($23)
	vmulax.wxyz	ACC,$vf4,$vf12x
	vmadday.wxyz	ACC,$vf5,$vf12y
	vmaddaz.wxyz	ACC,$vf6,$vf12z
	vmaddw.wxyz	$vf12,$vf7,$vf12w
	vdiv	Q,$vf0w,$vf12w
	lqc2	$vf4,0($11)
	lqc2	$vf5,0($29)
	vwaitq
	vmulq.xyz	$vf12,$vf12,Q
	vadd.xy	$vf12,$vf12,$vf4
	vmul.xy	$vf12,$vf12,$vf5
	sqc2	$vf12,0($15)
	swc1	$f20,12($15)
	sll	$14,$20,0x4
	swc1	$f20,8($15)
	addu	$14,$14,$10
	addiu	$20,$20,1
	lw	$12,288($29)
	sll	$13,$20,0x4
	lq	$15,32($29)
	addu	$13,$13,$10
	addiu	$12,$12,1
	addiu	$20,$20,1
	sw	$12,288($29)
	sq	$15,0($14)
	lw	$14,288($29)
	lw	$15,280($29)
	slt	$12,$14,$15
	lw	$15,240($29)
	lw	$14,244($29)
	addiu	$15,$15,-8
	addiu	$14,$14,-8
	sw	$15,240($29)
	sw	$14,244($29)
	lq	$15,240($29)
	bnez	$12,.L001f2ed8
	sq	$15,0($13)
.L001f2e54:
	jal	func_001e7440
	sq	$10,304($29)
	lw	$11,296($29)
	beqz	$11,.L001f2e70
	lq	$10,304($29)
	jal	func_001e7470
	move	$4,$10
.L001f2e70:
	lw	$12,284($29)
	lw	$13,272($29)
	addiu	$12,$12,1
	slt	$15,$12,$13
	bnez	$15,.L001f2a5c
	sw	$12,284($29)
.L001f2e88:
	jal	func_001e7440
	nop
.L001f2e90:
	ld	$16,320($29)
	ld	$17,328($29)
	ld	$18,336($29)
	ld	$19,344($29)
	ld	$20,352($29)
	ld	$21,360($29)
	ld	$22,368($29)
	ld	$23,376($29)
	ld	$30,384($29)
	ld	$31,392($29)
	lwc1	$f25,420($29)
	lwc1	$f24,416($29)
	lwc1	$f23,412($29)
	lwc1	$f22,408($29)
	lwc1	$f21,404($29)
	lwc1	$f20,400($29)
	jr	$31
	addiu	$29,$29,432
.L001f2ed8:
	lw	$12,256($29)
	b	.L001f2ba4
	lbu	$13,22($12)
.L001f2ee4:
	b	.L001f2e54
	sw	$0,296($29)
.L001f2eec:
	c.le.s	$f21,$f1
	bc1tl	.L001f2bf4
	mov.s	$f21,$f1
	b	.L001f2bf8
	cvt.w.s	$f1,$f0
.L001f2f00:
	bne	$14,$15,.L001f28a4
	li	$13,80
	li	$15,1
	lui	$14,0x7000
	dsll32	$15,$15,0x7
	ori	$14,$14,0x50
	li	$13,80
	b	.L001f28a0
	ori	$15,$15,0x42
.L001f2f24:
	li	$15,1
	lui	$14,0x7000
	dsll32	$15,$15,0x7
	ori	$14,$14,0x50
	li	$13,80
	b	.L001f28a0
	ori	$15,$15,0x48
.L001f2f40:
	lui	$11,0x7000
	lw	$14,%lo(D_00352be4)($15)
	lui	$15,%hi(D_00352bfc)
	b	.L001f2820
	lw	$13,%lo(D_00352bfc)($15)
.L001f2f54:
	li	$14,71
	ori	$15,$15,0x20
	b	.L001f27bc
	lui	$13,0x3
.L001f2f64:
	lui	$13,%hi(D_00352be8)
	lw	$14,%lo(D_00352be4)($15)
	b	.L001f2678
	lw	$15,%lo(D_00352be8)($13)
	.end func_001f25d0
	.size func_001f25d0, 2468
