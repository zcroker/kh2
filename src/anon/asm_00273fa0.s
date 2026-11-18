# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/00273fa0_unit.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00273fa0,"ax",@progbits
	.align 3
	.globl func_00273fa0
	.type func_00273fa0, @function
	.ent func_00273fa0
func_00273fa0:
	addiu	$29,$29,-80
	sd	$31,72($29)
	sd	$16,0($29)
	sd	$17,8($29)
	sd	$18,16($29)
	sd	$19,24($29)
	lui	$17,%hi(D_0035f214)
	sd	$20,32($29)
	lui	$18,%hi(D_0035f218)
	sd	$21,40($29)
	lui	$19,%hi(D_00347E60)
	sd	$22,48($29)
	sd	$23,56($29)
	sd	$30,64($29)
	lui	$23,%hi(D_0035f1fc)
	jal	func_00292540
	addiu	$19,$19,%lo(D_00347E60)
	li	$30,-1
	li	$5,3
	jal	func_00287b18
	li	$4,41
	jal	func_00253818
	li	$4,3
	jal	func_00259350
	li	$4,3
	jal	func_0028d0c8
	move	$4,$0
	lui	$15,%hi(D_0035f13c)
	li	$4,30065
	sw	$2,%lo(D_0035f13c)($15)
	jal	func_0028d068
	li	$5,-1
	lui	$13,%hi(D_0035f140)
	sw	$0,%lo(D_0035f214)($17)
	lw	$15,%lo(D_0035f140)($13)
	li	$5,-1
	sw	$0,%lo(D_0035f218)($18)
	li	$4,30065
	andi	$14,$15,0x4
	movz	$15,$0,$14
	sw	$15,%lo(D_0035f140)($13)
	li	$14,5
	lui	$15,%hi(D_0035f14c)
	sw	$14,%lo(D_0035f14c)($15)
	lui	$15,%hi(D_0035f144)
	lui	$14,%hi(D_0035f150)
	sw	$30,%lo(D_0035f144)($15)
	lui	$15,%hi(D_0035f148)
	sw	$0,%lo(D_0035f148)($15)
	li	$15,1
	sw	$15,%lo(D_0035f150)($14)
	lui	$15,%hi(D_0035f210)
	lui	$14,%hi(D_0035f204)
	sw	$0,%lo(D_0035f210)($15)
	sw	$0,%lo(D_0035f204)($14)
	lui	$15,0x36
	jal	func_0028d068
	sw	$0,-3576($15)
	jal	func_00288be8
	li	$4,56
	move	$16,$2
	move	$4,$2
	li	$5,18
	jal	func_002889f0
	li	$6,1
	lui	$14,%hi(D_0032ba14)
	lui	$15,%hi(D_0035f200)
	lw	$4,%lo(D_0032ba14)($14)
	move	$6,$31
	sw	$16,%lo(D_0035f200)($15)
	lw	$15,0($4)
	lw	$2,0($15)
	jalr	$2
	li	$5,52
	move	$16,$2
	jal	func_0028b9b0
	move	$4,$2
	lui	$15,%hi(D_00347F80)
	sw	$16,%lo(D_0035f214)($17)
	lw	$14,%lo(D_00347F80)($15)
	move	$6,$0
	li	$5,444
	lui	$17,%hi(D_00347e40)
	lw	$4,20($14)
	lw	$15,0($4)
	lw	$2,0($15)
	jalr	$2
	addiu	$17,$17,%lo(D_00347e40)
	move	$16,$2
	jal	func_0028d140
	move	$4,$2
	jal	func_00103570
	sw	$16,%lo(D_0035f218)($18)
	lui	$18,%hi(D_00347F98)
	move	$5,$2
	jal	func_001063c0
	li	$4,1872
	addiu	$18,$18,%lo(D_00347F98)
	sw	$0,12($2)
	move	$16,$2
	sw	$19,0($2)
	addiu	$4,$2,24
	addiu	$20,$16,436
	jal	func_00239700
	addiu	$21,$16,872
	addiu	$22,$16,1308
	sw	$17,0($16)
	addiu	$4,$16,448
	sw	$0,408($16)
	jal	func_0031a838
	sw	$18,436($16)
	sw	$19,436($16)
	jal	func_00239700
	addiu	$4,$16,460
	sw	$0,408($20)
	addiu	$4,$16,884
	sw	$17,436($16)
	jal	func_0031a838
	sw	$18,872($16)
	sw	$19,872($16)
	jal	func_00239700
	addiu	$4,$16,896
	sw	$0,408($21)
	addiu	$4,$16,1320
	sw	$17,872($16)
	jal	func_0031a838
	sw	$18,1308($16)
	sw	$19,1308($16)
	jal	func_00239700
	addiu	$4,$16,1332
	sw	$17,1308($16)
	lui	$15,0x36
	sw	$0,408($22)
	jal	func_00103570
	sw	$16,-3572($15)
	move	$5,$2
	jal	func_001063c0
	li	$4,4
	jal	func_00103570
	sw	$2,%lo(D_0035f1fc)($23)
	lui	$4,0x1
	move	$5,$2
	jal	func_001063c0
	ori	$4,$4,0x1320
	move	$16,$2
	jal	func_00323540
	move	$4,$2
	lui	$15,0x36
	jal	func_00103570
	sw	$16,-3556($15)
	move	$5,$2
	jal	func_001063f0
	li	$4,80
	li	$15,2
	addiu	$17,$2,16
	sw	$15,12($2)
	move	$16,$2
	move	$4,$17
	jal	func_0014b920
	addiu	$16,$16,48
	jal	func_0014b920
	move	$4,$16
	lui	$15,%hi(D_0035f224)
	lw	$14,%lo(D_0035f1fc)($23)
	sw	$17,%lo(D_0035f224)($15)
	sb	$30,0($14)
	lui	$15,0x36
	jal	func_0013a9d0
	sb	$30,-3544($15)
	beqz	$2,.L00274260
	li	$14,30045
	jal	func_0013aa38
	move	$4,$0
	lui	$15,%hi(D_0035f228)
	sb	$2,%lo(D_0035f228)($15)
	li	$14,30045
.L00274260:
	lui	$15,0x36
	jal	func_002535c0
	sw	$14,-3116($15)
	slti	$14,$2,0
	lw	$13,%lo(D_0035f1fc)($23)
	move	$17,$2
	movn	$17,$0,$14
	xori	$15,$17,0x2
	li	$14,2
	sltiu	$15,$15,1
	beq	$17,$14,.L002742b4
	sb	$15,2($13)
	lui	$15,0x36
	lw	$16,%lo(D_0035f1fc)($23)
	jal	func_002764b0
	lw	$4,-3784($15)
	sb	$2,0($16)
	lw	$14,%lo(D_0035f1fc)($23)
	lb	$15,0($14)
	slti	$15,$15,0
	movn	$17,$0,$15
.L002742b4:
	li	$15,1
	beq	$17,$15,.L00274458
	move	$16,$0
	slti	$15,$17,2
	beqz	$15,.L00274428
	li	$15,2
	beqz	$17,.L00274420
	lw	$15,%lo(D_0035f1fc)($23)
.L002742d4:
	lui	$14,%hi(D_0035f140)
.L002742d8:
	lw	$15,%lo(D_0035f140)($14)
	andi	$15,$15,0x4
	bnez	$15,.L00274404
	li	$15,1
	jal	func_00103570
	nop
	jal	func_00293e00
	move	$4,$2
	lui	$15,%hi(D_0035f222)
	sb	$0,%lo(D_0035f222)($15)
	lui	$15,%hi(D_0035f220)
.L00274304:
	lui	$14,0x36
	sb	$0,%lo(D_0035f220)($15)
	jal	func_002a1f88
	sb	$0,-3551($14)
	jal	func_002a9ce8
	nop
	jal	func_002acda8
	nop
	jal	func_002944f8
	nop
	jal	func_002957b8
	nop
	jal	_ZN2Tz7JmStory4InitEv
	nop
	jal	func_00297cf8
	nop
	jal	func_002994f8
	nop
	jal	func_0029a820
	nop
	jal	func_0029edb8
	nop
	jal	func_002a0588
	nop
	jal	func_002a4c68
	nop
	jal	func_002a68e8
	nop
	jal	func_002a7678
	nop
	jal	func_002a8948
	nop
	jal	func_002aea98
	nop
	jal	func_002926c0
	li	$4,1
	lui	$15,%hi(D_0035f1fc)
	move	$5,$0
	lw	$14,%lo(D_0035f1fc)($15)
	move	$4,$16
	jal	func_00287bd0
	sb	$0,1($14)
	jal	func_00287cc0
	move	$4,$0
	jal	func_00103eb0
	nop
	lw	$4,4($2)
	lui	$7,%hi(func_00274b40)
	ld	$16,0($29)
	move	$5,$0
	ld	$17,8($29)
	addiu	$7,$7,%lo(func_00274b40)
	ld	$18,16($29)
	li	$6,2000
	ld	$19,24($29)
	li	$8,4096
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	ld	$23,56($29)
	ld	$30,64($29)
	ld	$31,72($29)
	j	func_00102818
	addiu	$29,$29,80
.L00274404:
	lui	$14,%hi(D_0035f222)
	lui	$4,0x27
	sb	$15,%lo(D_0035f222)($14)
	jal	func_00288670
	addiu	$4,$4,26304
	b	.L00274304
	lui	$15,%hi(D_00360000)
.L00274420:
	b	.L002742d4
	sb	$30,%lo(D_00360000)($15)
.L00274428:
	beq	$17,$15,.L00274440
	li	$15,3
	beql	$17,$15,.L002742d4
	li	$16,11
	b	.L002742d8
	lui	$14,0x36
.L00274440:
	lui	$15,%hi(D_0035f1fc)
	li	$16,1
	lw	$14,%lo(D_0035f1fc)($15)
	li	$15,19
	b	.L002742d4
	sb	$15,0($14)
.L00274458:
	b	.L002742d4
	li	$16,2
	.end func_00273fa0
	.size func_00273fa0, 1216
