# Whole-function assembly (last step of the README match ladder, w3942 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced by name.
# Replace with C/C++ after 100%.
#   func_001faea8: partMng GS draw-env packet + z-buffer occlusion test (alpha *= visible fraction).
#     Closest C: tmp.w3942/best_001faea8.c (= best/001faea8_w3859_nsa.c, 82 multi.py lines):
#     p/bw get s2/s1 instead of s1/s2, late `move s1,v0`, scissor field unpack t4/t6 swap.
#     Addresses with no D_ symbol, written as plain lui/offset values: 0x01da8ad0..0x01da8b40 (GS packet,
#     lui 0x1db with offsets -30000..-29888) and 0x0037025c (float literal 1.0f pool, lui 0x37 + addiu 604).
# Split out of batch_w3942.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001faea8,"ax",@progbits
	.globl func_001faea8
	.type func_001faea8, @function
	.ent func_001faea8
func_001faea8:
	addiu	$29,$29,-272
	mtc1	$0,$f0
	sd	$19,200($29)
	lui	$15,%hi(D_00352c00)
	sd	$16,176($29)
	lui	$14,%hi(D_00352c08)
	sd	$17,184($29)
	lui	$5,0x1db
	sd	$18,192($29)
	sd	$20,208($29)
	sd	$21,216($29)
	sd	$22,224($29)
	sd	$23,232($29)
	sd	$30,240($29)
	sd	$31,248($29)
	swc1	$f20,256($29)
	ld	$11,%lo(D_00352c00)($15)
	ld	$10,%lo(D_00352c08)($14)
	lui	$15,%hi(D_00352c10)
	ld	$8,%lo(D_00352c10)($15)
	pcpyld	$10,$0,$10
	pcpyld	$11,$0,$11
	lui	$15,%hi(D_00352c18)
	sq	$11,-30000($5)
	ld	$7,%lo(D_00352c18)($15)
	pcpyld	$8,$0,$8
	lui	$14,0x1db
	addiu	$5,$5,-30000
	lui	$15,%hi(D_00352c30)
	ld	$9,%lo(D_00352c30)($15)
	por	$11,$0,$0
	sq	$11,-29936($14)
	pcpyld	$7,$0,$7
	lui	$15,%hi(D_00352c28)
	ld	$12,%lo(D_00352c28)($15)
	lui	$14,0x1db
	pcpyld	$9,$0,$9
	lui	$15,%hi(D_00352c20)
	sq	$9,-29920($14)
	ld	$13,%lo(D_00352c20)($15)
	pcpyld	$12,$0,$12
	lui	$14,0x1db
	lui	$15,0x1db
	sq	$10,-29984($15)
	pcpyld	$13,$0,$13
	sq	$13,-29888($14)
	lui	$15,0x1db
	sq	$8,-29968($15)
	li	$14,64
	lui	$15,0x1db
	sq	$7,-29952($15)
	lui	$15,0x1db
	sq	$12,-29904($15)
	li	$15,76
	sd	$14,56($5)
	sd	$15,8($5)
	li	$14,70
	li	$15,78
	sd	$14,88($5)
	sd	$15,24($5)
	li	$14,71
	li	$15,24
	sd	$15,40($5)
	li	$15,26
	sd	$15,72($5)
	li	$15,69
	sd	$15,104($5)
	sd	$14,120($5)
	lwc1	$f1,124($4)
	c.eq.s	$f1,$f0
	bc1t	.L001fb000
	move	$19,$4
	lbu	$14,141($4)
	lbu	$15,140($4)
	addiu	$16,$14,1
	div	$0,$15,$16
	beqzl	$16,.L001fafe0
	break	0x7
.L001fafe0:
	mfhi	$13
	div	$0,$6,$16
	mfhi	$14
	beq	$13,$14,.L001fb034
	move	$30,$5
	lwc1	$f0,172($4)
	mul.s	$f0,$f1,$f0
	swc1	$f0,124($4)
.L001fb000:
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
	lwc1	$f20,256($29)
	jr	$31
	addiu	$29,$29,272
.L001fb034:
	ld	$14,48($30)
	addiu	$5,$4,176
	lhu	$10,32($30)
	move	$4,$29
	dsrl32	$13,$14,0x10
	lhu	$11,36($30)
	dsrl	$15,$14,0x10
	dsrl32	$12,$14,0x0
	andi	$15,$15,0x7ff
	andi	$13,$13,0x7ff
	dsll32	$15,$15,0x0
	andi	$12,$12,0x7ff
	dsll32	$13,$13,0x0
	andi	$14,$14,0x7ff
	dsra32	$15,$15,0x0
	dsra32	$13,$13,0x0
	dsll32	$12,$12,0x0
	dsll32	$14,$14,0x0
	dsll32	$22,$10,0x0
	dsll32	$23,$11,0x0
	dsra32	$12,$12,0x0
	dsra32	$14,$14,0x0
	addiu	$15,$15,1
	addiu	$13,$13,1
	dsra32	$22,$22,0x0
	dsra32	$23,$23,0x0
	sll	$14,$14,0x4
	sll	$12,$12,0x4
	sll	$15,$15,0x4
	sll	$13,$13,0x4
	addu	$14,$22,$14
	addu	$12,$23,$12
	addu	$15,$22,$15
	sw	$14,32($29)
	addu	$13,$23,$13
	sw	$12,36($29)
	sw	$15,40($29)
	jal	sceVu0FTOI4Vector
	sw	$13,44($29)
	lbu	$11,192($19)
	lw	$12,4($29)
	sw	$11,160($29)
	sll	$15,$11,0x3
	lbu	$13,193($19)
	sw	$13,164($29)
	lw	$11,164($29)
	lw	$13,0($29)
	sll	$14,$11,0x3
	addu	$9,$13,$15
	addu	$10,$12,$14
	subu	$11,$12,$14
	sw	$9,24($29)
	subu	$13,$13,$15
	lw	$12,32($29)
	sw	$11,20($29)
	sw	$10,28($29)
	slt	$15,$13,$12
	beqz	$15,.L001fb33c
	sw	$13,16($29)
	sw	$12,16($29)
.L001fb124:
	lw	$11,20($29)
	lw	$13,36($29)
	slt	$15,$11,$13
	beqz	$15,.L001fb328
	lw	$14,44($29)
	move	$11,$13
.L001fb13c:
	sw	$11,20($29)
	lw	$9,24($29)
.L001fb144:
	slt	$15,$9,$12
	beqz	$15,.L001fb314
	lw	$14,40($29)
	move	$9,$12
.L001fb154:
	sw	$9,24($29)
	lw	$10,28($29)
.L001fb15c:
	slt	$15,$10,$13
	beqz	$15,.L001fb300
	lw	$14,44($29)
	move	$10,$13
.L001fb16c:
	sw	$10,28($29)
	lw	$12,16($29)
.L001fb174:
	subu	$15,$10,$11
	addiu	$15,$15,15
	subu	$14,$9,$12
	addiu	$14,$14,15
	sra	$20,$14,0x4
	blez	$20,.L001fb198
	sra	$21,$15,0x4
	bgtzl	$21,.L001fb1a4
	li	$15,-8
.L001fb198:
	sw	$0,172($19)
	b	.L001fb000
	sw	$0,124($19)
.L001fb1a4:
	mtc1	$0,$f20
	subu	$12,$12,$22
	addiu	$13,$20,7
	li	$14,-4
	subu	$11,$11,$23
	addiu	$16,$21,3
	and	$18,$13,$15
	and	$16,$16,$14
	sra	$22,$12,0x4
	sra	$23,$11,0x4
	jal	func_0020eaf8
	li	$4,12384
	sll	$16,$16,0x10
	ld	$6,0($30)
	sll	$8,$22,0x10
	lhu	$5,16($30)
	sll	$9,$23,0x10
	dsrl	$6,$6,0x10
	sra	$16,$16,0x10
	andi	$6,$6,0x3f
	andi	$5,$5,0x1ff
	andi	$6,$6,0xffff
	sll	$10,$18,0x10
	sll	$6,$6,0x10
	move	$11,$16
	sra	$8,$8,0x10
	sra	$9,$9,0x10
	sra	$6,$6,0x10
	sra	$10,$10,0x10
	li	$7,49
	sll	$5,$5,0x5
	move	$17,$2
	jal	sceGsSetDefStoreImage
	addiu	$4,$29,48
	addiu	$17,$17,96
	jal	func_003058a0
	move	$4,$0
	addiu	$4,$29,48
	jal	sceGsExecStoreImage
	move	$5,$17
	move	$4,$0
	jal	sceGsSyncPath
	move	$5,$0
	lw	$15,8($29)
	blez	$21,.L001fb2c4
	sra	$11,$15,0x4
	subu	$14,$18,$20
	move	$16,$21
	sll	$15,$14,0x1
	addu	$10,$15,$14
.L001fb26c:
	blez	$20,.L001fb2b8
	lui	$13,0x37
	move	$12,$20
	addiu	$13,$13,604
	lwc1	$f0,0($13)
	lbu	$15,1($17)
.L001fb284:
	lbu	$14,0($17)
	lbu	$13,2($17)
	sll	$15,$15,0x8
	or	$14,$14,$15
	sll	$13,$13,0x10
	or	$14,$14,$13
	sltu	$14,$14,$11
	beqz	$14,.L001fb2ac
	addiu	$17,$17,3
	add.s	$f20,$f20,$f0
.L001fb2ac:
	addiu	$12,$12,-1
	bnezl	$12,.L001fb284
	lbu	$15,1($17)
.L001fb2b8:
	addiu	$16,$16,-1
	bnez	$16,.L001fb26c
	addu	$17,$17,$10
.L001fb2c4:
	jal	func_0020ebd8
	li	$4,12384
	lw	$14,160($29)
	lw	$11,164($29)
	lwc1	$f1,124($19)
	mult	$15,$14,$11
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	nop
	nop
	div.s	$f20,$f20,$f0
	mul.s	$f1,$f1,$f20
	swc1	$f20,172($19)
	b	.L001fb000
	swc1	$f1,124($19)
.L001fb300:
	slt	$15,$14,$10
	beqz	$15,.L001fb174
	lw	$12,16($29)
	b	.L001fb16c
	move	$10,$14
.L001fb314:
	slt	$15,$14,$9
	beqz	$15,.L001fb15c
	lw	$10,28($29)
	b	.L001fb154
	move	$9,$14
.L001fb328:
	slt	$15,$14,$11
	beqz	$15,.L001fb144
	lw	$9,24($29)
	b	.L001fb13c
	move	$11,$14
.L001fb33c:
	lw	$14,40($29)
	slt	$15,$14,$13
	movn	$13,$14,$15
	b	.L001fb124
	sw	$13,16($29)
	.end func_001faea8
	.size func_001faea8, 1192
