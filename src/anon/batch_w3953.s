# Whole-function assembly (last step of the README match ladder, w3953 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_002c3638: dk::WM_LANDING update (entries[8] x448, Tz::Select lists, wrap search, two function-local
#     static vectors with atexit thunks).
#     Closest C: ~/re/kh2/tmp.w3953/best_002c3638.c (= best/002c3638_w3944.c, ~221 lines off):
#     constant 1 shared in s3 (delay slot), register allocation s0/s2, static-vector init order.
#     No symbol, written as literal values: 0x002c5378, 0x002c5380 (atexit thunks in a layout gap),
#     0x00375564, 0x00375568, 0x0037556c (float data), 0x01e2bd50, 0x01e2bd58, 0x01e2bd60, 0x01e2bd70
#     (static guard/vector storage), and the tail jump j 0x2c24a8 (only a mangled name exists there).
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002c3638,"ax",@progbits
	.align 2
	.globl func_002c3638
	.type func_002c3638, @function
	.ent func_002c3638
func_002c3638:
	addiu	$29,$29,-80
	sd	$17,8($29)
	sd	$18,16($29)
	move	$17,$4
	sd	$16,0($29)
	sd	$19,24($29)
	sd	$20,32($29)
	sd	$21,40($29)
	sd	$22,48($29)
	sd	$23,56($29)
	sd	$30,64($29)
	sd	$31,72($29)
	jal	func_00167f18
	move	$4,$0
	move	$18,$2
	jal	func_002c5130
	move	$4,$17
	bnezl	$2,.L002c3be0
	ld	$15,8($18)
	lw	$15,24($17)
	andi	$15,$15,0x1
	bnez	$15,.L002c37a0
	li	$19,1
	ld	$14,8($18)
	andi	$15,$14,0x100
	beqz	$15,.L002c3768
	andi	$15,$14,0x400
	jal	func_002cac40
	li	$4,2
	lui	$13,0x1e3
	lb	$15,-17072($13)
	bnez	$15,.L002c3704
	li	$15,2
	mtc1	$0,$f0
	lui	$15,0x1e3
	addiu	$14,$15,-17056
	lui	$12,0x37
	swc1	$f0,-17056($15)
	addiu	$12,$12,21860
	swc1	$f0,12($14)
	lui	$4,0x2c
	lui	$15,0x37
	addiu	$4,$4,21368
	addiu	$15,$15,21864
	lwc1	$f0,0($12)
	lwc1	$f1,0($15)
	swc1	$f0,4($14)
	swc1	$f1,8($14)
	jal	func_002fd188
	sb	$19,-17072($13)
	li	$15,2
.L002c3704:
	move	$5,$0
	sw	$15,8244($17)
	jal	func_002c3240
	move	$4,$17
	move	$16,$2
	move	$4,$17
	jal	func_002c3240
	li	$5,2
	move	$6,$2
	addiu	$4,$17,28
	jal	func_0023f070
	move	$5,$16
	sw	$19,8260($17)
.L002c3738:
	ld	$16,0($29)
.L002c373c:
	ld	$17,8($29)
.L002c3740:
	ld	$18,16($29)
	ld	$19,24($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	ld	$23,56($29)
	ld	$30,64($29)
	ld	$31,72($29)
	jr	$31
	addiu	$29,$29,80
.L002c3768:
	beqz	$15,.L002c37a0
	ld	$16,0($29)
	lw	$4,8236($17)
	ld	$17,8($29)
	ld	$18,16($29)
	ld	$19,24($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	ld	$23,56($29)
	ld	$30,64($29)
	ld	$31,72($29)
	j	0x2c24a8
	addiu	$29,$29,80
.L002c37a0:
	jal	func_002c5130
	move	$4,$17
	bnez	$2,.L002c3ac8
	nop
	lw	$14,24($17)
	andi	$15,$14,0x1
	beqz	$15,.L002c380c
	li	$20,1
	ld	$15,8($18)
	andi	$15,$15,0xfc
	beqz	$15,.L002c3808
	li	$15,-2
	addiu	$16,$17,13648
	and	$15,$14,$15
	move	$4,$16
	sw	$15,24($17)
	jal	func_00138c10
	li	$5,93
	li	$15,-1
	li	$4,4
	jal	func_002cac40
	sw	$15,392($16)
	ld	$15,8($18)
	lw	$14,24($17)
	andi	$15,$15,0xc
	movn	$20,$0,$15
.L002c3808:
	andi	$15,$14,0x1
.L002c380c:
	bnez	$15,.L002c373c
	ld	$16,0($29)
	jal	func_002891e8
	lw	$4,872($17)
	lw	$4,872($17)
	jal	func_00289380
	move	$18,$2
	lw	$4,872($17)
	jal	func_002891e8
	move	$19,$2
	lw	$4,872($17)
	jal	func_00289310
	move	$16,$2
	beqz	$2,.L002c38e0
	li	$15,-2
	lw	$11,11856($17)
	move	$12,$16
	slt	$13,$16,$18
	addiu	$14,$11,-1
	beqz	$13,.L002c3ab0
	and	$2,$14,$15
	subu	$15,$18,$16
	slt	$15,$15,$2
	beqz	$15,.L002c3a64
	move	$13,$11
.L002c3870:
	blez	$11,.L002c38b8
	move	$10,$0
	li	$8,448
	move	$9,$11
.L002c3880:
	mult	$15,$12,$8
	addu	$15,$17,$15
	lw	$14,8704($15)
	andi	$14,$14,0x2
	bnez	$14,.L002c38b8
	addu	$14,$12,$11
	addiu	$10,$10,1
	addiu	$12,$14,-1
	slt	$13,$10,$11
	div	$0,$12,$11
	beqzl	$9,.L002c38b0
	break	0x7
.L002c38b0:
	bnez	$13,.L002c3880
	mfhi	$12
.L002c38b8:
	beq	$18,$12,.L002c38c8
	move	$16,$12
	jal	func_002cac40
	li	$4,1
.L002c38c8:
	lw	$4,872($17)
	move	$5,$16
	li	$6,1
	move	$7,$0
	jal	func_002891f0
	li	$8,2
.L002c38e0:
	beqz	$20,.L002c3954
	li	$15,-2
	beq	$19,$15,.L002c3a48
	slti	$15,$19,-1
	beqz	$15,.L002c38fc
	li	$15,-1
	li	$15,-4
.L002c38fc:
	beq	$19,$15,.L002c3954
	li	$15,448
	mult	$15,$16,$15
	addu	$18,$17,$15
	lw	$14,8704($18)
	andi	$15,$14,0x1
	beqz	$15,.L002c39f0
	li	$4,5
	jal	func_002cac40
	addiu	$18,$17,13648
	lw	$15,24($17)
	move	$4,$18
	ori	$15,$15,0x1
	jal	func_00139d78
	sw	$15,24($17)
	beqz	$2,.L002c3998
	nop
	move	$4,$18
	jal	func_00138c10
	li	$5,91
	li	$15,92
	sw	$15,392($18)
.L002c3954:
	li	$15,448
.L002c3958:
	ld	$18,16($29)
	mult	$15,$16,$15
	ld	$19,24($29)
	addiu	$4,$17,188
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	addu	$15,$15,$17
	ld	$16,0($29)
	lw	$5,8272($15)
	ld	$17,8($29)
	ld	$23,56($29)
	ld	$30,64($29)
	ld	$31,72($29)
	j	func_0023f618
	addiu	$29,$29,80
.L002c3998:
	jal	func_00192048
	li	$4,19469
	lw	$6,13640($17)
	move	$9,$2
	lw	$7,13644($17)
	li	$5,30060
	li	$8,91
	move	$10,$0
	jal	func_00138d60
	move	$4,$18
	li	$15,92
	move	$4,$18
	jal	func_001395e8
	sw	$15,392($18)
	jal	func_001395f8
	move	$4,$18
	li	$15,2
	move	$4,$18
	jal	func_00139620
	sw	$15,432($18)
	b	.L002c3958
	li	$15,448
.L002c39f0:
	andi	$15,$14,0x2
	beqz	$15,.L002c3958
	li	$15,448
	jal	func_002cac40
	li	$4,2
	lw	$14,24($17)
	li	$15,1
	sw	$15,8240($17)
	ori	$14,$14,0x2
	sw	$14,24($17)
	ldl	$12,8715($18)
	ldr	$12,8708($18)
	lh	$13,8716($18)
	sdl	$12,13615($17)
	sdr	$12,13608($17)
	sh	$13,13616($17)
	jal	func_002c3da0
	move	$4,$17
	jal	func_002c8648
	nop
	b	.L002c3958
	li	$15,448
.L002c3a48:
	jal	func_002cac40
	li	$4,4
	sw	$0,8240($17)
	jal	func_002c3da0
	move	$4,$17
	b	.L002c3958
	li	$15,448
.L002c3a64:
	blez	$13,.L002c38b8
	move	$11,$0
	li	$9,448
	move	$10,$13
.L002c3a74:
	mult	$15,$12,$9
	addu	$15,$17,$15
	lw	$14,8704($15)
	andi	$14,$14,0x2
	bnez	$14,.L002c38b8
	addiu	$11,$11,1
	addiu	$12,$12,1
	div	$0,$12,$13
	slt	$14,$11,$13
	beqzl	$10,.L002c3aa0
	break	0x7
.L002c3aa0:
	bnez	$14,.L002c3a74
	mfhi	$12
	b	.L002c38b8
	nop
.L002c3ab0:
	subu	$15,$16,$18
	slt	$15,$15,$2
	beqz	$15,.L002c3870
	move	$13,$11
	b	.L002c3a64
	nop
.L002c3ac8:
	jal	func_00139d78
	addiu	$4,$17,11872
	beqz	$2,.L002c3738
	li	$15,3
	lw	$14,12368($17)
	bne	$14,$15,.L002c373c
	ld	$16,0($29)
	lw	$15,12364($17)
	slt	$15,$14,$15
	beqzl	$15,.L002c3740
	ld	$17,8($29)
	jal	func_00289380
	lw	$4,12360($17)
	jal	func_00289310
	lw	$4,12360($17)
	lw	$4,12360($17)
	jal	func_0028b040
	move	$16,$2
	beqz	$16,.L002c3b20
	move	$22,$2
	jal	func_002cac40
	li	$4,1
.L002c3b20:
	jal	func_00289310
	lw	$4,12360($17)
	beqz	$2,.L002c3738
	li	$6,1
	lw	$4,12360($17)
	move	$5,$22
	move	$7,$0
	li	$8,2
	jal	func_002891f0
	move	$21,$0
	addiu	$4,$17,12308
	jal	func_0028be78
	move	$5,$22
	lw	$15,12368($17)
	blez	$15,.L002c3738
	lui	$23,%hi(D_0037558c)
	lui	$30,%hi(D_00375590)
	addiu	$20,$17,12384
	addiu	$19,$17,12372
	addu	$18,$22,$21
.L002c3b70:
	move	$5,$18
	bltz	$18,.L002c3738
	addiu	$21,$21,1
	lw	$15,12364($17)
	slt	$15,$18,$15
	beqz	$15,.L002c373c
	ld	$16,0($29)
	lw	$16,0($19)
	lw	$4,8236($17)
	jal	func_002c2598
	addiu	$19,$19,4
	sw	$2,408($16)
	move	$5,$18
	jal	func_002c2688
	lw	$4,8236($17)
	lw	$15,%lo(D_0037558c)($23)
	move	$4,$20
	lw	$5,%lo(D_00375590)($30)
	addiu	$20,$20,408
	jal	func_00138c10
	movn	$5,$15,$2
	lw	$15,12368($17)
	slt	$15,$21,$15
	bnez	$15,.L002c3b70
	addu	$18,$22,$21
	b	.L002c373c
	ld	$16,0($29)
	nop
.L002c3be0:
	andi	$15,$15,0x208
	beqz	$15,.L002c37a0
	nop
	jal	func_002cac40
	li	$4,2
	lui	$12,0x1e3
	lb	$15,-17064($12)
	bnez	$15,.L002c3c50
	li	$15,3
	mtc1	$0,$f0
	lui	$13,0x1e3
	addiu	$14,$13,-17040
	li	$15,1
	swc1	$f0,12($14)
	lui	$4,0x2c
	swc1	$f0,-17040($13)
	addiu	$4,$4,21376
	sb	$15,-17064($12)
	lui	$13,0x37
	lui	$12,0x37
	addiu	$13,$13,21868
	addiu	$12,$12,21860
	lwc1	$f1,0($13)
	lwc1	$f0,0($12)
	swc1	$f1,8($14)
	jal	func_002fd188
	swc1	$f0,4($14)
	li	$15,3
.L002c3c50:
	move	$5,$0
	sw	$15,8244($17)
	jal	func_002c3240
	move	$4,$17
	move	$16,$2
	move	$4,$17
	jal	func_002c3240
	li	$5,2
	move	$6,$2
	addiu	$4,$17,28
	jal	func_0023f070
	move	$5,$16
	li	$15,2
	b	.L002c3738
	sw	$15,8260($17)
	.end func_002c3638
	.size func_002c3638, 1620

