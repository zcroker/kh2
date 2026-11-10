# Whole-function assembly (last step of the README match ladder, w3960 2026-11-11).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_00121cc8: model part draw (per-part GS state, textures, optional matrix/scissor packets).
#     Closest C: ~/re/kh2/tmp.w3960/best_00121cc8_nsa.cpp (_nsa, = coord best/00121cc8_w3870_nsa.cpp,
#     opcode ratio 0.921, 1282 vs 1308 insns): frame 368 vs 384 (original caller-saves a value with sq/lq
#     at 288(sp) around the func_00133bb8 call), part-loop latch/return block placement, TBW/PSM and-form.
#     No symbol, written as literal lui/addiu values: 0x0036a9a8 (100000000.0f), 0x0036a9ac (2048.0f),
#     0x0036a9b0 (4096.0f) literal-pool floats; other luis are GS register constants.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00121cc8,"ax",@progbits
	.align 2
	.globl func_00121cc8
	.type func_00121cc8, @function
	.ent func_00121cc8
func_00121cc8:
	addiu	$29,$29,-384
	andi	$10,$10,0xff
	sd	$16,304($29)
	sd	$18,320($29)
	sd	$20,336($29)
	move	$16,$11
	sd	$17,312($29)
	move	$18,$5
	sd	$19,328($29)
	move	$20,$7
	sd	$21,344($29)
	move	$17,$0
	sd	$22,352($29)
	sd	$23,360($29)
	sd	$30,368($29)
	sd	$31,376($29)
	sw	$4,176($29)
	sw	$6,180($29)
	sw	$8,184($29)
	sw	$9,188($29)
	jal	func_0010ae90
	sw	$10,192($29)
	sw	$2,196($29)
	lui	$14,0x1
	sw	$0,204($29)
	lw	$13,176($29)
	lw	$15,0($20)
	lw	$13,4($13)
	and	$15,$15,$14
	move	$14,$0
	sw	$13,200($29)
	movn	$14,$16,$15
	bnez	$14,.L00121d64
	sw	$14,208($29)
	lw	$13,176($29)
	lw	$15,12($13)
	andi	$15,$15,0x2
	bnez	$15,.L00121d68
	sw	$16,212($29)
.L00121d64:
	sw	$0,212($29)
.L00121d68:
	lw	$14,200($29)
	lw	$15,8($14)
	andi	$15,$15,0x1
	andi	$15,$15,0xff
	beqz	$15,.L00121d88
	sw	$0,216($29)
	lw	$15,48($20)
	sw	$15,216($29)
.L00121d88:
	addiu	$13,$29,16
	move	$23,$0
	sw	$13,276($29)
	lw	$16,276($29)
.L00121d98:
	move	$5,$23
	jal	func_00108930
	move	$4,$20
	addiu	$23,$23,1
	sw	$2,0($16)
	slti	$15,$23,32
	bnez	$15,.L00121d98
	addiu	$16,$16,4
	lw	$14,200($29)
	move	$23,$0
	lw	$10,28($14)
	blez	$10,.L00121e54
	move	$9,$10
	addiu	$13,$14,32
.L00121dd0:
	lw	$14,184($29)
	addu	$15,$14,$23
	lbu	$14,0($15)
	addiu	$23,$23,1
	andi	$14,$14,0xf
	andi	$12,$14,0xff
	beqz	$12,.L00121e4c
	slt	$11,$23,$9
	lw	$14,0($13)
	srl	$15,$14,0x4
	andi	$10,$14,0x1
	lw	$14,276($29)
	andi	$15,$15,0x7c
	addu	$15,$15,$14
	lw	$14,0($15)
	lbu	$14,3($14)
	andi	$15,$14,0xff
	beqz	$15,.L00121e4c
	nop
	bnez	$10,.L00121e40
	addiu	$17,$17,1
	sll	$15,$14,0x18
	sra	$15,$15,0x18
	bgez	$15,.L00121e44
	lw	$15,204($29)
	andi	$15,$12,0x4
	beqz	$15,.L00121e4c
	nop
.L00121e40:
	lw	$15,204($29)
.L00121e44:
	addiu	$15,$15,1
	sw	$15,204($29)
.L00121e4c:
	bnez	$11,.L00121dd0
	addiu	$13,$13,32
.L00121e54:
	beqz	$17,.L00122258
	li	$2,1
	jal	func_001344f8
	nop
	sw	$2,220($29)
	sw	$0,228($29)
	lw	$13,36($20)
	sw	$0,232($29)
	beqz	$13,.L00121ea8
	sw	$13,224($29)
	lh	$14,0($13)
	li	$15,-1
	bnel	$14,$15,.L00121eac
	lw	$4,220($29)
	lw	$15,8($13)
	lw	$14,12($13)
	addu	$15,$13,$15
	addu	$14,$13,$14
	sw	$15,228($29)
	sw	$14,232($29)
	sw	$15,224($29)
.L00121ea8:
	lw	$4,220($29)
.L00121eac:
	jal	func_00109360
	li	$5,2
	lw	$5,220($29)
	jal	func_00108730
	move	$4,$20
	lw	$14,224($29)
	bnez	$14,.L00122fd8
	move	$16,$2
	jal	func_0010aba8
	nop
	li	$15,10
	bne	$2,$15,.L00122fdc
	lw	$13,208($29)
	lui	$15,0x37
	addiu	$15,$15,-22104
	lwc1	$f0,0($15)
	swc1	$f0,56($16)
.L00121ef0:
	addiu	$2,$16,80
.L00121ef4:
	beq	$2,$18,.L00121f20
	lw	$15,224($29)
	lq	$8,0($18)
	lq	$9,16($18)
	lq	$10,32($18)
	lq	$11,48($18)
	sq	$8,0($2)
	sq	$9,16($2)
	sq	$10,32($2)
	sq	$11,48($2)
	lw	$15,224($29)
.L00121f20:
	beqz	$15,.L0012214c
	lw	$13,232($29)
	bnez	$13,.L00122150
	lw	$13,176($29)
	lw	$15,20($15)
	lw	$14,224($29)
	lw	$4,220($29)
	addu	$15,$14,$15
	sw	$15,236($29)
	jal	func_00109788
	lw	$5,236($29)
	beqz	$2,.L00121f60
	lw	$4,224($29)
	jal	func_00109708
	lw	$4,220($29)
	lw	$4,224($29)
.L00121f60:
	jal	func_00132018
	move	$23,$0
	lw	$15,200($29)
	move	$8,$2
	lw	$4,188($29)
	li	$6,0xf000
	lhu	$7,18($15)
	lui	$15,%hi(D_003a99f0)
	addiu	$16,$15,%lo(D_003a99f0)
	jal	func_00133078
	move	$5,$16
	lw	$13,200($29)
	lhu	$10,18($13)
	andi	$15,$10,0xffff
.L00121f98:
	beqz	$15,.L0012214c
	lw	$15,224($29)
	sll	$11,$23,0x3
	lw	$14,16($15)
	lw	$13,20($15)
	lui	$15,%hi(D_003a99f0)
	addiu	$15,$15,%lo(D_003a99f0)
	addu	$12,$11,$15
	lw	$15,224($29)
	lw	$21,0($12)
	addu	$14,$15,$14
	addu	$14,$14,$23
	lbu	$15,0($14)
	li	$14,144
	mult	$15,$15,$14
	addiu	$15,$15,144
	addu	$13,$13,$15
	lw	$15,224($29)
	addu	$13,$15,$13
	beqz	$21,.L00122144
	sw	$13,236($29)
	lw	$15,4($12)
	lui	$13,%hi(D_003a99f0)
	addiu	$13,$13,%lo(D_003a99f0)
	addu	$30,$15,$13
.L00121ffc:
	beqzl	$30,.L0012210c
	addiu	$23,$23,1
	blez	$21,.L00122108
	lui	$14,%hi(D_003a99f0)
	li	$15,160
	mult	$13,$23,$15
	addiu	$14,$14,%lo(D_003a99f0)
	addu	$11,$11,$14
	sw	$11,252($29)
	sw	$13,240($29)
.L00122024:
	lw	$22,0($30)
	move	$5,$0
	jal	func_00132d90
	move	$4,$22
	move	$4,$22
	beqz	$2,.L00122118
	slti	$14,$21,2
	lw	$14,224($29)
	lw	$15,240($29)
	lw	$16,24($14)
	addu	$16,$16,$15
	jal	func_00132c98
	addu	$16,$14,$16
	move	$18,$2
	jal	func_00132cd0
	move	$4,$22
	move	$17,$2
	jal	func_00132d00
	move	$4,$22
	sw	$2,244($29)
	jal	func_00132d30
	move	$4,$22
	sw	$2,248($29)
	jal	func_00132d60
	move	$4,$22
	move	$19,$2
	move	$4,$22
	jal	func_00132d90
	move	$5,$0
	lw	$13,236($29)
	lui	$14,0x3f0
	ld	$6,112($16)
	lui	$15,0xf
	ld	$5,32($13)
	ori	$15,$15,0xc000
	and	$11,$6,$14
	lw	$8,244($29)
	li	$13,16383
	sw	$2,0($29)
	and	$6,$6,$15
	lw	$9,248($29)
	dsll32	$13,$13,0x0
	dsll	$6,$6,0x12
	and	$5,$5,$13
	dsll	$11,$11,0xc
	move	$4,$18
	move	$7,$17
	dsra32	$5,$5,0x0
	dsra32	$6,$6,0x0
	dsra32	$11,$11,0x0
	jal	func_001097e8
	move	$10,$19
.L001220f4:
	addiu	$21,$21,-1
	bgtz	$21,.L00122024
	addiu	$30,$30,4
	lw	$14,200($29)
	lhu	$10,18($14)
.L00122108:
	addiu	$23,$23,1
.L0012210c:
	andi	$15,$10,0xffff
	b	.L00121f98
	slt	$15,$23,$15
.L00122118:
	lw	$13,252($29)
	lw	$15,0($13)
	addiu	$15,$15,-1
	bnez	$14,.L001220f4
	sw	$15,0($13)
	sll	$15,$21,0x2
	addu	$15,$30,$15
	lw	$14,-4($15)
	sw	$14,0($30)
	b	.L001220f4
	addiu	$30,$30,-4
.L00122144:
	b	.L00121ffc
	move	$30,$0
.L0012214c:
	lw	$13,176($29)
.L00122150:
	addiu	$14,$20,4
	move	$23,$0
	lw	$15,4($13)
	li	$13,-1
	sw	$14,256($29)
	sw	$13,272($29)
	jal	func_0010aba8
	lw	$16,4($15)
	lbu	$6,7($20)
	move	$4,$2
	jal	func_00109f58
	move	$5,$16
	li	$15,-49
	sd	$2,264($29)
	sw	$15,160($29)
	lw	$14,200($29)
	lw	$10,28($14)
	blez	$10,.L00122240
	lw	$14,192($29)
	lw	$18,180($29)
.L001221a0:
	lw	$15,184($29)
	addu	$14,$15,$23
	lbu	$15,0($14)
	andi	$15,$15,0xf
	andi	$13,$15,0xff
	beqz	$13,.L0012222c
	lw	$14,200($29)
	sll	$19,$23,0x5
	addu	$15,$19,$14
	lw	$12,32($15)
	lw	$15,276($29)
	srl	$14,$12,0x4
	andi	$14,$14,0x7c
	addu	$14,$14,$15
	lw	$17,0($14)
	lbu	$11,3($17)
	andi	$15,$11,0xff
	beqz	$15,.L0012222c
	andi	$15,$13,0x4
	bnezl	$15,.L00122230
	addiu	$23,$23,1
	lw	$15,0($20)
	andi	$15,$15,0x10
	beqz	$15,.L00122fa8
	sll	$15,$11,0x18
	sra	$15,$15,0x18
	bgez	$15,.L00122288
	sll	$15,$11,0x18
	andi	$15,$12,0x1
	bnez	$15,.L00122288
	sll	$15,$11,0x18
	lw	$13,192($29)
	li	$15,1
	bne	$13,$15,.L00122288
	sll	$15,$11,0x18
.L0012222c:
	addiu	$23,$23,1
.L00122230:
	slt	$15,$23,$10
	bnez	$15,.L001221a0
	addiu	$18,$18,4
	lw	$14,192($29)
.L00122240:
	bnez	$14,.L00122258
	li	$2,1
	lw	$15,204($29)
	bnez	$15,.L00122258
	move	$2,$0
	li	$2,1
.L00122258:
	ld	$16,304($29)
	ld	$17,312($29)
	ld	$18,320($29)
	ld	$19,328($29)
	ld	$20,336($29)
	ld	$21,344($29)
	ld	$22,352($29)
	ld	$23,360($29)
	ld	$30,368($29)
	ld	$31,376($29)
	jr	$31
	addiu	$29,$29,384
.L00122288:
	sra	$15,$15,0x18
.L0012228c:
	bltz	$15,.L0012229c
	lw	$15,192($29)
	beqzl	$15,.L00122230
	addiu	$23,$23,1
.L0012229c:
	lw	$13,176($29)
	li	$14,1
	lw	$15,4($13)
	lw	$13,4($15)
	beq	$13,$14,.L001222cc
	lw	$15,200($29)
	addu	$14,$19,$15
	lw	$15,32($14)
	srl	$15,$15,0x15
	andi	$15,$15,0x1
	beqz	$15,.L001222f0
	lw	$4,220($29)
.L001222cc:
	lw	$13,200($29)
	addu	$14,$19,$13
	lw	$15,32($14)
	andi	$15,$15,0x1
	beqz	$15,.L001222ec
	lw	$14,192($29)
	beqzl	$14,.L00122230
	addiu	$23,$23,1
.L001222ec:
	lw	$4,220($29)
.L001222f0:
	move	$5,$0
	lui	$6,0x1100
	jal	func_00133bb8
	lui	$7,0x1300
	lw	$15,0($20)
	li	$13,4
	andi	$14,$15,0x8
	sw	$0,156($29)
	movz	$13,$0,$14
	sw	$0,152($29)
	sw	$0,148($29)
	andi	$15,$15,0x4
	beqz	$15,.L00122330
	sw	$13,144($29)
	ori	$13,$13,0x1
	sw	$13,144($29)
.L00122330:
	lw	$15,208($29)
	beqz	$15,.L00122344
	lw	$15,144($29)
	ori	$13,$15,0x4000
	sw	$13,144($29)
.L00122344:
	lw	$13,216($29)
	beqz	$13,.L00122f78
	lw	$14,212($29)
	beqz	$14,.L00122f60
	lw	$15,200($29)
	addu	$14,$19,$15
	lw	$14,32($14)
	srl	$15,$14,0x1d
	andi	$15,$15,0x1
	beqz	$15,.L00122f40
	lw	$15,144($29)
	ori	$13,$15,0x20
.L00122374:
	sw	$13,144($29)
.L00122378:
	lw	$13,256($29)
.L0012237c:
	beq	$13,$17,.L0012248c
	lw	$4,220($29)
	jal	func_001085a8
	move	$5,$17
	sw	$17,256($29)
	lw	$15,144($29)
	lw	$14,0($20)
	ori	$13,$15,0x8
	andi	$14,$14,0x10
	beqz	$14,.L00122eb0
	sw	$13,144($29)
	lw	$15,200($29)
	addu	$14,$19,$15
	lw	$15,32($14)
	srl	$14,$15,0x6
	andi	$14,$14,0x1f
	addiu	$15,$14,-10
	sltiu	$15,$15,10
	bnez	$15,.L001223d4
	li	$13,1
	addiu	$15,$14,-20
	sltiu	$13,$15,10
.L001223d4:
	andi	$15,$13,0xff
	beqz	$15,.L00122eb0
	lw	$13,200($29)
	addu	$14,$19,$13
	lw	$15,32($14)
	srl	$15,$15,0x6
	andi	$15,$15,0x1f
	sltiu	$15,$15,20
	beqz	$15,.L00122ea8
	lbu	$15,3($17)
	sltiu	$15,$15,96
.L00122400:
	beqz	$15,.L00122e94
	li	$15,1
	ld	$14,24($20)
	dsll32	$15,$15,0x0
	or	$16,$14,$15
.L00122414:
	jal	func_0010aba8
	nop
	lw	$14,176($29)
	move	$4,$2
	lbu	$6,3($17)
	lw	$15,4($14)
	jal	func_00109f58
	lw	$5,4($15)
	lbu	$13,2($17)
	li	$15,127
	lbu	$12,1($17)
	dsll32	$15,$15,0x17
	lbu	$11,0($17)
	dsll	$13,$13,0x10
	dsll	$12,$12,0x8
	lbu	$14,3($17)
	or	$11,$11,$15
	lw	$4,196($29)
	or	$13,$13,$12
	dsll	$14,$14,0x18
	or	$11,$11,$13
	lui	$8,0x5
	move	$9,$2
	move	$7,$16
	or	$11,$11,$14
	li	$5,46
	move	$6,$0
	ori	$8,$8,0xd
.L00122484:
	jal	func_00108c00
	move	$10,$0
.L0012248c:
	lw	$15,200($29)
	addu	$16,$19,$15
	lw	$15,32($16)
	srl	$15,$15,0x16
	andi	$8,$15,0x1f
	beqz	$8,.L00122590
	lw	$13,224($29)
	beqz	$13,.L00122590
	lw	$4,188($29)
	addiu	$8,$8,-1
	move	$5,$0
	li	$6,2
	jal	func_00132390
	li	$7,-1
	beqz	$2,.L00122590
	move	$17,$2
	lw	$13,224($29)
	lw	$15,36($16)
	lw	$14,24($13)
	li	$13,160
	mult	$15,$15,$13
	addu	$14,$14,$15
	lw	$15,224($29)
	addu	$16,$15,$14
	ld	$15,128($16)
	andi	$14,$15,0x3
	beqz	$14,.L00122504
	li	$15,3
	bne	$14,$15,.L00122594
	ld	$14,144($29)
.L00122504:
	lw	$15,144($29)
	ori	$13,$15,0x2
	sw	$13,144($29)
	ld	$4,112($16)
	dsrl	$4,$4,0x1a
	andi	$4,$4,0xf
	dsll32	$4,$4,0x0
	jal	func_0010aed8
	dsra32	$4,$4,0x0
	ld	$5,128($16)
	move	$6,$2
	move	$4,$17
	dsrl	$5,$5,0x4
	andi	$5,$5,0x3ff
	dsll32	$5,$5,0x0
	dsra32	$5,$5,0x0
	jal	func_001333f8
	addiu	$5,$5,1
	sw	$2,152($29)
	ld	$4,112($16)
	dsrl	$4,$4,0x1e
	andi	$4,$4,0xf
	dsll32	$4,$4,0x0
	jal	func_0010aed8
	dsra32	$4,$4,0x0
	ld	$5,128($16)
	move	$6,$2
	move	$4,$17
	dsrl	$5,$5,0x18
	andi	$5,$5,0x3ff
	dsll32	$5,$5,0x0
	dsra32	$5,$5,0x0
	jal	func_001334a8
	addiu	$5,$5,1
	sw	$2,156($29)
.L00122590:
	ld	$14,144($29)
.L00122594:
	ld	$15,160($29)
	bne	$14,$15,.L001225b0
	move	$13,$0
	ld	$14,152($29)
	ld	$15,168($29)
	beq	$14,$15,.L001225b8
	andi	$15,$13,0xff
.L001225b0:
	li	$13,1
	andi	$15,$13,0xff
.L001225b8:
	bnezl	$15,.L001225f4
	lw	$5,144($29)
	lw	$15,144($29)
	andi	$15,$15,0x20
	beqz	$15,.L0012289c
	lw	$14,224($29)
	lw	$13,224($29)
	beqz	$13,.L001228cc
	lw	$14,200($29)
	addu	$15,$19,$14
	lw	$14,36($15)
	lw	$15,272($29)
	beq	$14,$15,.L0012289c
	lw	$14,224($29)
	lw	$5,144($29)
.L001225f4:
	move	$6,$0
	lw	$4,220($29)
	lw	$7,148($29)
	lw	$8,152($29)
	jal	func_001093c8
	lw	$9,156($29)
	lw	$14,144($29)
	andi	$15,$14,0x20
	beqz	$15,.L00122e5c
	lw	$13,224($29)
	beqz	$13,.L00122e60
	andi	$15,$14,0x10
	lw	$14,200($29)
	lw	$16,24($13)
	addu	$15,$19,$14
	lw	$14,36($15)
	li	$15,160
	mult	$14,$14,$15
	addu	$16,$16,$14
	addu	$16,$13,$16
	ld	$4,112($16)
	dsrl	$4,$4,0x1a
	andi	$4,$4,0xf
	dsll32	$4,$4,0x0
	jal	func_0010aed8
	dsra32	$4,$4,0x0
	ld	$4,112($16)
	move	$17,$2
	dsrl	$4,$4,0x1e
	andi	$4,$4,0xf
	dsll32	$4,$4,0x0
	jal	func_0010aed8
	dsra32	$4,$4,0x0
	ld	$13,128($16)
	andi	$14,$13,0x3
	beqz	$14,.L00122694
	move	$22,$2
	li	$15,3
	bne	$14,$15,.L00122e1c
	dsrl32	$12,$13,0x2
.L00122694:
	dsrl	$14,$13,0x18
	dsrl	$15,$13,0x4
	andi	$15,$15,0x3ff
	andi	$14,$14,0x3ff
	dsll32	$13,$15,0x0
	dsll32	$12,$14,0x0
	dsra32	$13,$13,0x0
	dsra32	$12,$12,0x0
	move	$30,$0
	move	$11,$0
.L001226bc:
	subu	$15,$13,$30
	subu	$14,$12,$11
	addiu	$16,$15,1
	lw	$15,216($29)
	beqz	$15,.L00122bb0
	addiu	$21,$14,1
	lw	$15,160($29)
	andi	$15,$15,0x20
	bnez	$15,.L00122bb4
	sq	$11,288($29)
	lui	$6,0x100
	lui	$7,0x6c04
	lw	$4,220($29)
	li	$5,4
	ori	$6,$6,0x101
	jal	func_00133bb8
	ori	$7,$7,0x400a
	bltz	$16,.L00122b90
	lq	$11,288($29)
	mtc1	$16,$f1
	cvt.s.w	$f1,$f1
.L00122710:
	lui	$13,0x37
	addiu	$13,$13,-22100
	lwc1	$f0,0($13)
	bltz	$17,.L00122b74
	mul.s	$f1,$f1,$f0
	mtc1	$17,$f0
	cvt.s.w	$f0,$f0
.L0012272c:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$13,$2,4
	bltz	$21,.L00122b58
	swc1	$f0,0($2)
	mtc1	$21,$f1
	cvt.s.w	$f1,$f1
.L0012274c:
	lui	$14,0x37
	addiu	$14,$14,-22100
	lwc1	$f0,0($14)
	bltz	$22,.L00122b3c
	mul.s	$f1,$f1,$f0
	mtc1	$22,$f0
	cvt.s.w	$f0,$f0
.L00122768:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$12,$2,8
	bltz	$30,.L00122b20
	swc1	$f0,0($13)
	mtc1	$30,$f1
	cvt.s.w	$f1,$f1
.L00122788:
	lui	$15,0x37
	addiu	$15,$15,-22096
	lwc1	$f0,0($15)
	bltz	$16,.L00122b04
	mul.s	$f2,$f1,$f0
	mtc1	$16,$f1
	cvt.s.w	$f1,$f1
.L001227a4:
	lui	$13,0x37
	addiu	$13,$13,-22100
	lwc1	$f0,0($13)
	mul.s	$f0,$f1,$f0
	bltz	$17,.L00122ae8
	add.s	$f1,$f2,$f0
	mtc1	$17,$f0
	cvt.s.w	$f0,$f0
.L001227c4:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$13,$2,12
	bltz	$11,.L00122acc
	swc1	$f0,0($12)
	mtc1	$11,$f1
	cvt.s.w	$f1,$f1
.L001227e4:
	lui	$14,0x37
	addiu	$14,$14,-22096
	lwc1	$f0,0($14)
	bltz	$21,.L00122ab0
	mul.s	$f2,$f1,$f0
	mtc1	$21,$f1
	cvt.s.w	$f1,$f1
.L00122800:
	lui	$15,0x37
	addiu	$15,$15,-22100
	lwc1	$f0,0($15)
	mul.s	$f0,$f1,$f0
	bltz	$22,.L00122a94
	add.s	$f1,$f2,$f0
	mtc1	$22,$f0
	cvt.s.w	$f0,$f0
.L00122820:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$15,$2,16
	swc1	$f0,0($13)
	lw	$13,212($29)
	beq	$15,$13,.L00122850
	addiu	$14,$2,32
	lq	$8,0($13)
	sq	$8,0($15)
	lw	$13,212($29)
	addiu	$14,$2,32
.L00122850:
	addiu	$15,$13,16
	beql	$14,$15,.L00122868
	lw	$14,212($29)
	lq	$8,0($15)
	sq	$8,0($14)
	lw	$14,212($29)
.L00122868:
	addiu	$2,$2,48
	addiu	$15,$14,32
	beq	$2,$15,.L00122884
	addiu	$14,$29,160
	lq	$8,0($15)
	sq	$8,0($2)
.L00122880:
	addiu	$14,$29,160
.L00122884:
	addiu	$15,$29,144
.L00122888:
	beql	$14,$15,.L0012289c
	lw	$14,224($29)
	lq	$8,0($15)
	sq	$8,0($14)
	lw	$14,224($29)
.L0012289c:
	beqz	$14,.L001228cc
	lw	$15,232($29)
	beqz	$15,.L00122958
	lw	$4,176($29)
	move	$6,$23
	lw	$5,220($29)
	move	$7,$20
	lw	$8,188($29)
	lw	$9,192($29)
	lw	$10,228($29)
	jal	func_001219b8
	lw	$11,232($29)
.L001228cc:
	lw	$14,192($29)
.L001228d0:
	beqz	$14,.L0012290c
	lw	$15,200($29)
	addu	$14,$19,$15
	lw	$14,32($14)
	srl	$15,$14,0x1b
	andi	$15,$15,0x1
	beqz	$15,.L00122930
	li	$5,1
	lw	$4,196($29)
	dsll32	$5,$5,0x7
	ori	$5,$5,0x48
.L001228fc:
	jal	func_00108eb8
	nop
	jal	func_00109008
	lw	$4,196($29)
.L0012290c:
	lw	$5,0($18)
	move	$6,$0
	lw	$4,220($29)
	move	$7,$0
	jal	func_00133c60
	move	$8,$0
	lw	$13,200($29)
	b	.L0012222c
	lw	$10,28($13)
.L00122930:
	srl	$15,$14,0x1c
	andi	$15,$15,0x1
	beqz	$15,.L00122950
	lw	$4,196($29)
	li	$5,1
	dsll32	$5,$5,0x7
	b	.L001228fc
	ori	$5,$5,0x42
.L00122950:
	b	.L001228fc
	ld	$5,264($29)
.L00122958:
	lw	$14,224($29)
	lw	$15,200($29)
	lw	$13,16($14)
	addu	$16,$19,$15
	lw	$12,20($14)
	lw	$15,36($16)
	addu	$13,$14,$13
	li	$14,144
	lw	$4,220($29)
	addu	$13,$13,$15
	lbu	$15,0($13)
	mult	$15,$15,$14
	lw	$13,224($29)
	addiu	$15,$15,144
	addu	$12,$12,$15
	addu	$21,$13,$12
	jal	func_00109788
	move	$5,$21
	lw	$14,36($16)
	lui	$15,%hi(D_003a99f0)
	addiu	$4,$15,%lo(D_003a99f0)
	sltu	$2,$0,$2
	sll	$14,$14,0x3
	dsll32	$22,$2,0x0
	addu	$14,$14,$4
	lw	$17,0($14)
	beqz	$17,.L00122a8c
	dsra32	$22,$22,0x0
	lw	$15,4($14)
	addu	$16,$15,$4
.L001229d0:
	beqz	$16,.L00122a2c
	lw	$14,200($29)
	blez	$17,.L00122a30
	lw	$15,272($29)
	li	$22,1
	lw	$4,0($16)
.L001229e8:
	jal	func_00132c98
	addiu	$17,$17,-1
	lw	$4,220($29)
	move	$5,$2
	move	$6,$0
	move	$7,$0
	jal	func_00133c60
	move	$8,$0
	jal	func_00132c98
	lw	$4,0($16)
	addiu	$16,$16,4
	move	$5,$2
	jal	func_001094e0
	move	$4,$21
	bgtzl	$17,.L001229e8
	lw	$4,0($16)
	lw	$14,200($29)
.L00122a2c:
	lw	$15,272($29)
.L00122a30:
	addu	$16,$19,$14
	lw	$14,36($16)
	beq	$14,$15,.L00122a74
	li	$15,160
	lw	$13,224($29)
	mult	$15,$14,$15
	lw	$4,220($29)
	lw	$5,24($13)
	move	$6,$0
	move	$7,$0
	move	$8,$0
	addu	$5,$5,$15
	jal	func_00133c60
	addu	$5,$13,$5
	lw	$16,36($16)
	b	.L001228cc
	sw	$16,272($29)
.L00122a74:
	beqzl	$22,.L001228d0
	lw	$14,192($29)
	jal	func_00109690
	lw	$4,220($29)
	b	.L001228d0
	lw	$14,192($29)
.L00122a8c:
	b	.L001229d0
	move	$16,$0
.L00122a94:
	srl	$14,$22,0x1
	andi	$15,$22,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L00122820
	add.s	$f0,$f0,$f0
.L00122ab0:
	srl	$14,$21,0x1
	andi	$15,$21,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122800
	add.s	$f1,$f1,$f1
.L00122acc:
	srl	$14,$11,0x1
	andi	$15,$11,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L001227e4
	add.s	$f1,$f1,$f1
.L00122ae8:
	srl	$14,$17,0x1
	andi	$15,$17,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L001227c4
	add.s	$f0,$f0,$f0
.L00122b04:
	srl	$14,$16,0x1
	andi	$15,$16,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L001227a4
	add.s	$f1,$f1,$f1
.L00122b20:
	srl	$14,$30,0x1
	andi	$15,$30,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122788
	add.s	$f1,$f1,$f1
.L00122b3c:
	andi	$15,$22,0x1
	srl	$14,$22,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L00122768
	add.s	$f0,$f0,$f0
.L00122b58:
	andi	$15,$21,0x1
	srl	$14,$21,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L0012274c
	add.s	$f1,$f1,$f1
.L00122b74:
	andi	$15,$17,0x1
	srl	$14,$17,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L0012272c
	add.s	$f0,$f0,$f0
.L00122b90:
	andi	$15,$16,0x1
	srl	$14,$16,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122710
	add.s	$f1,$f1,$f1
	nop
.L00122bb0:
	sq	$11,288($29)
.L00122bb4:
	lui	$6,0x100
	lui	$7,0x6c01
	lw	$4,220($29)
	li	$5,1
	ori	$6,$6,0x101
	jal	func_00133bb8
	ori	$7,$7,0x400a
	bltz	$16,.L00122e00
	lq	$11,288($29)
	mtc1	$16,$f1
	cvt.s.w	$f1,$f1
.L00122be0:
	lui	$15,0x37
	addiu	$15,$15,-22100
	lwc1	$f0,0($15)
	bltz	$17,.L00122de4
	mul.s	$f1,$f1,$f0
	mtc1	$17,$f0
	cvt.s.w	$f0,$f0
.L00122bfc:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$13,$2,4
	bltz	$21,.L00122dc8
	swc1	$f0,0($2)
	mtc1	$21,$f1
	cvt.s.w	$f1,$f1
.L00122c1c:
	lui	$14,0x37
	addiu	$14,$14,-22100
	lwc1	$f0,0($14)
	bltz	$22,.L00122dac
	mul.s	$f1,$f1,$f0
	mtc1	$22,$f0
	cvt.s.w	$f0,$f0
.L00122c38:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$12,$2,8
	bltz	$30,.L00122d90
	swc1	$f0,0($13)
	mtc1	$30,$f1
	cvt.s.w	$f1,$f1
.L00122c58:
	lui	$15,0x37
	addiu	$15,$15,-22096
	lwc1	$f0,0($15)
	bltz	$16,.L00122d74
	mul.s	$f2,$f1,$f0
	mtc1	$16,$f1
	cvt.s.w	$f1,$f1
.L00122c74:
	lui	$13,0x37
	addiu	$13,$13,-22100
	lwc1	$f0,0($13)
	mul.s	$f0,$f1,$f0
	bltz	$17,.L00122d58
	add.s	$f1,$f2,$f0
	mtc1	$17,$f0
	cvt.s.w	$f0,$f0
.L00122c94:
	nop
	nop
	div.s	$f0,$f1,$f0
	addiu	$2,$2,12
	bltz	$11,.L00122d3c
	swc1	$f0,0($12)
	mtc1	$11,$f1
	cvt.s.w	$f1,$f1
.L00122cb4:
	lui	$14,0x37
	addiu	$14,$14,-22096
	lwc1	$f0,0($14)
	bltz	$21,.L00122d20
	mul.s	$f2,$f1,$f0
	mtc1	$21,$f1
	cvt.s.w	$f1,$f1
.L00122cd0:
	lui	$15,0x37
	addiu	$15,$15,-22100
	lwc1	$f0,0($15)
	mul.s	$f0,$f1,$f0
	bltz	$22,.L00122d04
	add.s	$f1,$f2,$f0
	mtc1	$22,$f0
	cvt.s.w	$f0,$f0
.L00122cf0:
	nop
	nop
	div.s	$f0,$f1,$f0
	b	.L00122880
	swc1	$f0,0($2)
.L00122d04:
	srl	$14,$22,0x1
	andi	$15,$22,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L00122cf0
	add.s	$f0,$f0,$f0
.L00122d20:
	srl	$14,$21,0x1
	andi	$15,$21,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122cd0
	add.s	$f1,$f1,$f1
.L00122d3c:
	srl	$14,$11,0x1
	andi	$15,$11,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122cb4
	add.s	$f1,$f1,$f1
.L00122d58:
	srl	$14,$17,0x1
	andi	$15,$17,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L00122c94
	add.s	$f0,$f0,$f0
.L00122d74:
	srl	$14,$16,0x1
	andi	$15,$16,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122c74
	add.s	$f1,$f1,$f1
.L00122d90:
	srl	$14,$30,0x1
	andi	$15,$30,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122c58
	add.s	$f1,$f1,$f1
.L00122dac:
	andi	$15,$22,0x1
	srl	$14,$22,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L00122c38
	add.s	$f0,$f0,$f0
.L00122dc8:
	andi	$15,$21,0x1
	srl	$14,$21,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122c1c
	add.s	$f1,$f1,$f1
.L00122de4:
	andi	$15,$17,0x1
	srl	$14,$17,0x1
	or	$15,$15,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
	b	.L00122bfc
	add.s	$f0,$f0,$f0
.L00122e00:
	andi	$15,$16,0x1
	srl	$14,$16,0x1
	or	$15,$15,$14
	mtc1	$15,$f1
	cvt.s.w	$f1,$f1
	b	.L00122be0
	add.s	$f1,$f1,$f1
.L00122e1c:
	dsrl	$15,$13,0x4
	dsrl	$14,$13,0x18
	andi	$15,$15,0x3ff
	dsrl	$13,$13,0xe
	andi	$14,$14,0x3ff
	andi	$13,$13,0x3ff
	andi	$12,$12,0x3ff
	dsll32	$30,$15,0x0
	dsll32	$11,$14,0x0
	dsll32	$13,$13,0x0
	dsll32	$12,$12,0x0
	dsra32	$30,$30,0x0
	dsra32	$11,$11,0x0
	dsra32	$13,$13,0x0
	b	.L001226bc
	dsra32	$12,$12,0x0
.L00122e5c:
	andi	$15,$14,0x10
.L00122e60:
	beqz	$15,.L00122884
	addiu	$14,$29,160
	lw	$13,212($29)
	beqz	$13,.L00122884
	lw	$15,160($29)
	andi	$15,$15,0x10
	bnez	$15,.L00122888
	addiu	$15,$29,144
	lw	$4,216($29)
	jal	func_00134c00
	lw	$5,220($29)
	b	.L00122884
	addiu	$14,$29,160
.L00122e94:
	ld	$14,24($20)
	dsll32	$15,$15,0x0
	nor	$15,$0,$15
	b	.L00122414
	and	$16,$14,$15
.L00122ea8:
	b	.L00122400
	sltiu	$15,$15,32
.L00122eb0:
	jal	func_0010aba8
	nop
	lw	$13,176($29)
	move	$4,$2
	lbu	$6,3($17)
	lw	$15,4($13)
	jal	func_00109f58
	lw	$5,4($15)
	jal	func_0010aba8
	move	$16,$2
	lw	$14,176($29)
	move	$4,$2
	lbu	$6,3($17)
	lw	$15,4($14)
	jal	func_00109ea8
	lw	$5,4($15)
	lbu	$13,2($17)
	li	$15,127
	lbu	$12,1($17)
	dsll32	$15,$15,0x17
	lbu	$11,0($17)
	dsll	$13,$13,0x10
	dsll	$12,$12,0x8
	lbu	$14,3($17)
	or	$11,$11,$15
	lw	$4,196($29)
	or	$13,$13,$12
	dsll	$14,$14,0x18
	or	$11,$11,$13
	move	$8,$2
	or	$11,$11,$14
	move	$9,$16
	li	$5,44
	move	$6,$0
	b	.L00122484
	move	$7,$0
.L00122f40:
	srl	$15,$14,0x1e
.L00122f44:
	andi	$15,$15,0x1
	bnezl	$15,.L0012237c
	lw	$13,256($29)
	lw	$15,144($29)
	b	.L00122374
	ori	$13,$15,0x10
.L00122f5c:
	lw	$13,216($29)
.L00122f60:
	beqz	$13,.L00122378
	lw	$15,200($29)
	addu	$14,$19,$15
	lw	$15,32($14)
	b	.L00122f44
	srl	$15,$15,0x1e
.L00122f78:
	lw	$13,212($29)
	beqz	$13,.L00122f5c
	lw	$15,200($29)
	addu	$14,$19,$15
	lw	$15,32($14)
	srl	$15,$15,0x1d
	andi	$15,$15,0x1
	beqz	$15,.L00122f5c
	lw	$15,144($29)
	ori	$13,$15,0x20
	b	.L00122f5c
	sw	$13,144($29)
.L00122fa8:
	andi	$15,$12,0x1
	bnez	$15,.L00122288
	sll	$15,$11,0x18
	sra	$15,$15,0x18
	bgez	$15,.L00122288
	sll	$15,$11,0x18
	lw	$14,192($29)
	li	$15,1
	beq	$14,$15,.L0012222c
	sll	$15,$11,0x18
	b	.L0012228c
	sra	$15,$15,0x18
.L00122fd8:
	lw	$13,208($29)
.L00122fdc:
	beqz	$13,.L00123068
	lui	$6,0x100
	lw	$4,220($29)
	lui	$7,0x6c04
	li	$5,4
	ori	$6,$6,0x101
	jal	func_00133bb8
	ori	$7,$7,0x400a
	lw	$14,208($29)
	beql	$2,$14,.L0012302c
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
.L0012302c:
	li	$14,2047
	dsll32	$14,$14,0xf
	lui	$12,0x303e
	dsrl32	$15,$13,0xf
	sw	$0,224($29)
	andi	$15,$15,0x7ff
	nor	$14,$0,$14
	ori	$15,$15,0x50
	and	$13,$13,$14
	dsll32	$15,$15,0xf
	ori	$12,$12,0xc000
	or	$13,$13,$15
	sd	$13,0($16)
	b	.L00121ef0
	sw	$12,0($16)
.L00123068:
	lw	$15,216($29)
	bnez	$15,.L0012311c
	lw	$14,212($29)
	lw	$13,212($29)
	beqz	$13,.L00121ef0
	lui	$6,0x100
	lw	$4,220($29)
	lui	$7,0x6c04
	li	$5,4
	ori	$6,$6,0x101
	jal	func_00133bb8
	ori	$7,$7,0x400a
	lui	$15,0x37
	addiu	$15,$15,-22100
	lwc1	$f0,0($15)
	swc1	$f0,156($29)
	addiu	$15,$29,144
	swc1	$f0,144($29)
	swc1	$f0,148($29)
	beq	$2,$15,.L001230c4
	swc1	$f0,152($29)
	lq	$8,0($15)
	sq	$8,0($2)
.L001230c4:
	lw	$13,212($29)
	addiu	$15,$2,16
	beq	$15,$13,.L001230e4
	addiu	$14,$2,32
	lq	$8,0($13)
	sq	$8,0($15)
	lw	$13,212($29)
	addiu	$14,$2,32
.L001230e4:
	addiu	$15,$13,16
	beql	$14,$15,.L001230fc
	lw	$14,212($29)
	lq	$8,0($15)
	sq	$8,0($14)
	lw	$14,212($29)
.L001230fc:
	addiu	$2,$2,48
	addiu	$15,$14,32
	beql	$2,$15,.L00121ef4
	addiu	$2,$16,80
	lq	$8,0($15)
	sq	$8,0($2)
	b	.L00121ef4
	addiu	$2,$16,80
.L0012311c:
	bnezl	$14,.L00121ef4
	addiu	$2,$16,80
	lw	$4,216($29)
	jal	func_00134c00
	lw	$5,220($29)
	b	.L00121ef4
	addiu	$2,$16,80
	.end func_00121cc8
	.size func_00121cc8, 5232
