# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3890, carried to w3900).
# Both functions were 29-line near misses in C/C++ after many sessions; see coord attempts.tsv
# and the best/ADDR_w3890.cpp drafts. Replace with C/C++ after 100%.
#   func_001097e8: GS image upload (sched1 puts the 9th-argument copy for data between the
#                  trxpos and trxreg stores, so sched2 orders the packet stores 16,32,80,48)
#   func_00297e68: album menu setup (global allocation gives oy s3 and n+1 s4, swapped)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001097e8,"ax",@progbits
	.align 2
	.globl func_001097e8
	.type func_001097e8, @function
	.ent func_001097e8
func_001097e8:
	addiu	$29,$29,-160
	sltiu	$15,$11,59
	sd	$17,88($29)
	sd	$18,96($29)
	sd	$19,104($29)
	daddu	$17,$8,$0
	sd	$20,112($29)
	daddu	$18,$5,$0
	sd	$21,120($29)
	daddu	$19,$9,$0
	sd	$22,128($29)
	daddu	$20,$10,$0
	sd	$23,136($29)
	daddu	$21,$0,$0
	sd	$30,144($29)
	daddu	$22,$6,$0
	sd	$16,80($29)
	daddu	$23,$11,$0
	sd	$31,152($29)
	daddu	$30,$5,$0
	sw	$7,16($29)
	sw	$0,32($29)
	sw	$0,48($29)
	beqz	$15,.L001098e0
	sw	$0,64($29)
	lui	$14,0x37
	sll	$15,$11,0x2
	addiu	$14,$14,-23920
	addu	$15,$15,$14
	lw	$13,0($15)
	jr	$13
	nop
	sltiu	$15,$8,32
	bnez	$15,.L00109898
	addu	$14,$17,$20
	sll	$13,$6,0x5
.L00109878:
	addiu	$17,$17,-32
	sltiu	$15,$17,32
	nop
	nop
	nop
	beqz	$15,.L00109878
	addu	$18,$18,$13
	addu	$14,$17,$20
.L00109898:
	sltiu	$15,$14,33
	bnez	$15,.L001098dc
	mult	$15,$19,$20
	addiu	$14,$14,-32
	lw	$11,160($29)
	subu	$20,$20,$14
	sw	$14,32($29)
	mult1	$15,$19,$20
	sll	$13,$22,0x5
	mult	$14,$19,$14
	addu	$30,$18,$13
	sll	$15,$15,0x2
	srl	$14,$14,0x2
	addu	$15,$11,$15
	sw	$14,64($29)
	sw	$15,48($29)
	mult	$15,$19,$20
.L001098dc:
	srl	$21,$15,0x2
.L001098e0:
	sw	$4,0($29)
	addiu	$5,$0,6
	lui	$6,0x1300
	dsll32	$19,$19,0x0
	daddu	$4,$29,$0
	jal	0x1337f0
	dsrl32	$19,$19,0x0
	daddu	$16,$2,$0
	jal	0x108398
	daddu	$4,$2,$0
	lw	$13,16($29)
	dsll32	$15,$18,0x0
	dsll32	$11,$22,0x0
	ld	$10,80($16)
	dsll32	$8,$13,0x0
	dsll32	$14,$17,0x0
	dsll32	$13,$20,0x0
	dsrl32	$11,$11,0x0
	dsll32	$9,$23,0x0
	dsrl32	$15,$15,0x0
	dsll32	$20,$11,0x10
	dsrl32	$9,$9,0x0
	dsrl32	$8,$8,0x0
	dsll32	$15,$15,0x0
	dsrl32	$14,$14,0x0
	dsrl32	$13,$13,0x0
	dsll32	$17,$9,0x18
	dsll32	$18,$8,0x0
	or	$15,$15,$20
	dsll32	$14,$14,0x10
	dsll32	$13,$13,0x0
	or	$15,$15,$17
	or	$13,$19,$13
	sd	$15,16($16)
	or	$14,$18,$14
	sd	$13,48($16)
	dsll32	$12,$21,0x0
	sd	$14,32($16)
	addiu	$11,$0,-32768
	dsrl32	$12,$12,0x0
	andi	$12,$12,0x7fff
	lw	$5,160($29)
	and	$10,$10,$11
	daddu	$4,$29,$0
	or	$10,$10,$12
	daddu	$7,$0,$0
	andi	$6,$10,0x7fff
	sd	$10,80($16)
	dsll32	$6,$6,0x0
	jal	0x1337a0
	dsra32	$6,$6,0x0
	lw	$13,48($29)
	beqz	$13,.L00109a58
	lui	$7,0x1300
	daddu	$5,$0,$0
	lui	$6,0x1100
	jal	0x133848
	daddu	$4,$29,$0
	addiu	$5,$0,6
	lui	$6,0x1300
	jal	0x1337f0
	daddu	$4,$29,$0
	daddu	$16,$2,$0
	jal	0x108398
	daddu	$4,$2,$0
	lw	$14,64($29)
	dsll32	$15,$30,0x0
	lw	$11,32($29)
	dsrl32	$15,$15,0x0
	dsll32	$13,$14,0x0
	ld	$12,80($16)
	dsll32	$14,$11,0x0
	sd	$18,32($16)
	dsll32	$15,$15,0x0
	dsrl32	$14,$14,0x0
	or	$15,$15,$20
	dsll32	$14,$14,0x0
	or	$15,$15,$17
	or	$14,$19,$14
	dsrl32	$13,$13,0x0
	sd	$15,16($16)
	addiu	$11,$0,-32768
	sd	$14,48($16)
	and	$12,$12,$11
	andi	$13,$13,0x7fff
	or	$12,$12,$13
	lw	$5,48($29)
	andi	$6,$12,0x7fff
	daddu	$7,$0,$0
	dsll32	$6,$6,0x0
	sd	$12,80($16)
	dsra32	$6,$6,0x0
	jal	0x1337a0
	daddu	$4,$29,$0
.L00109a58:
	daddu	$4,$29,$0
	daddu	$5,$0,$0
	lui	$6,0x1100
	jal	0x133898
	lui	$7,0x1300
	ld	$16,80($29)
	ld	$17,88($29)
	ld	$18,96($29)
	ld	$19,104($29)
	ld	$20,112($29)
	ld	$21,120($29)
	ld	$22,128($29)
	ld	$23,136($29)
	ld	$30,144($29)
	ld	$31,152($29)
	jr	$31
	addiu	$29,$29,160
	sltiu	$15,$8,64
	bnez	$15,.L00109ad4
	addu	$14,$17,$20
	addiu	$15,$6,1
	srl	$15,$15,0x1
	sll	$13,$15,0x5
.L00109ab4:
	addiu	$17,$17,-64
	sltiu	$15,$17,64
	nop
	nop
	nop
	beqz	$15,.L00109ab4
	addu	$18,$18,$13
	addu	$14,$17,$20
.L00109ad4:
	sltiu	$15,$14,65
	bnez	$15,.L00109b1c
	mult	$15,$19,$20
	addiu	$14,$14,-64
	addiu	$15,$22,1
	sw	$14,32($29)
	subu	$20,$20,$14
	mult1	$13,$19,$20
	srl	$15,$15,0x1
	mult	$14,$19,$14
	sll	$15,$15,0x5
	addu	$30,$18,$15
	srl	$14,$14,0x4
	sw	$14,64($29)
	lw	$14,160($29)
	addu	$13,$14,$13
	sw	$13,48($29)
	mult	$15,$19,$20
.L00109b1c:
	b	.L001098e0
	srl	$21,$15,0x4
	sltiu	$15,$8,128
	bnez	$15,.L00109b5c
	addu	$14,$17,$20
	addiu	$15,$6,1
	srl	$15,$15,0x1
	sll	$13,$15,0x5
.L00109b3c:
	addiu	$17,$17,-128
	sltiu	$15,$17,128
	nop
	nop
	nop
	beqz	$15,.L00109b3c
	addu	$18,$18,$13
	addu	$14,$17,$20
.L00109b5c:
	sltiu	$15,$14,129
	bnez	$15,.L00109ba8
	mult	$15,$19,$20
	addiu	$14,$14,-128
	addiu	$15,$22,1
	mult	$13,$19,$14
	sw	$14,32($29)
	subu	$20,$20,$14
	srl	$15,$15,0x1
	sll	$15,$15,0x5
	addu	$30,$18,$15
	mult1	$14,$19,$20
	lw	$15,160($29)
	srl	$13,$13,0x5
	sw	$13,64($29)
	srl	$14,$14,0x1
	addu	$14,$15,$14
	sw	$14,48($29)
	mult	$15,$19,$20
.L00109ba8:
	b	.L001098e0
	srl	$21,$15,0x5
	sltiu	$15,$8,64
	bnez	$15,.L00109be0
	addu	$14,$17,$20
	sll	$13,$6,0x5
.L00109bc0:
	addiu	$17,$17,-64
	sltiu	$15,$17,64
	nop
	nop
	nop
	beqz	$15,.L00109bc0
	addu	$18,$18,$13
	addu	$14,$17,$20
.L00109be0:
	sltiu	$15,$14,65
	bnez	$15,.L00109c24
	mult	$15,$19,$20
	addiu	$14,$14,-64
	sll	$13,$22,0x5
	subu	$20,$20,$14
	sw	$14,32($29)
	mult1	$15,$19,$20
	addu	$30,$18,$13
	mult	$14,$19,$14
	lw	$13,160($29)
	sll	$15,$15,0x1
	srl	$14,$14,0x3
	addu	$15,$13,$15
	sw	$14,64($29)
	sw	$15,48($29)
	mult	$15,$19,$20
.L00109c24:
	b	.L001098e0
	srl	$21,$15,0x3
	.end func_001097e8
	.size func_001097e8, .-func_001097e8

	.section .text.func_00297e68,"ax",@progbits
	.align 2
	.globl func_00297e68
	.type func_00297e68, @function
	.ent func_00297e68
func_00297e68:
	addiu	$29,$29,-128
	sd	$31,120($29)
	sd	$21,88($29)
	sd	$22,96($29)
	sd	$16,48($29)
	sd	$17,56($29)
	sd	$18,64($29)
	sd	$19,72($29)
	sd	$20,80($29)
	sd	$23,104($29)
	sd	$30,112($29)
	jal	0x276348
	nop
	jal	0x2766d0
	daddu	$22,$2,$0
	addiu	$13,$0,-1
	lui	$15,0x36
	sb	$13,-2655($15)
	lui	$14,0x36
	sb	$13,-2656($14)
	daddu	$21,$2,$0
	lui	$15,0x36
	sb	$0,-2653($15)
	lui	$14,0x36
	sb	$0,-2654($14)
	lui	$15,0x36
	jal	0x288e88
	lw	$4,-3584($15)
	jal	0x28f930
	daddu	$4,$0,$0
	bnez	$2,.L00297efc
	daddu	$17,$0,$0
	daddu	$4,$0,$0
	addiu	$5,$0,-1
	jal	0x28f4d8
	daddu	$6,$0,$0
	daddu	$17,$0,$0
.L00297efc:
	addiu	$13,$0,2
	sll	$15,$17,0x3
.L00297f04:
	addiu	$14,$0,3
	addu	$15,$15,$29
.L00297f0c:
	sh	$13,0($15)
	addiu	$14,$14,-1
	nop
	nop
	nop
	bgez	$14,.L00297f0c
	addiu	$15,$15,2
	addiu	$17,$17,1
	slti	$15,$17,2
	bnez	$15,.L00297f04
	sll	$15,$17,0x3
	lui	$20,0x36
	lui	$19,0x36
	lw	$15,-3116($20)
	lui	$17,0x36
	lui	$18,0x36
	lui	$23,0x6000
	addiu	$16,$15,-1
	jal	0x276e78
	daddu	$30,$19,$0
	ori	$23,$23,0x8
	lw	$6,-3764($17)
	daddu	$5,$16,$0
	lw	$7,-3768($18)
	addiu	$9,$0,90
	lw	$8,-3568($19)
	addiu	$10,$0,-1
	daddu	$11,$0,$0
	jal	0x28d8c0
	daddu	$4,$21,$0
	daddu	$17,$0,$0
	jal	0x139620
	daddu	$4,$21,$0
	daddu	$5,$22,$0
	jal	0x28dcc0
	daddu	$4,$21,$0
	lui	$22,0x36
	jal	0x23aa78
	addiu	$4,$21,24
	lw	$16,-3116($20)
	ori	$15,$0,0xa998
	sw	$2,20($29)
	addu	$18,$21,$15
	daddu	$20,$0,$0
	addiu	$19,$16,1
.L00297fc0:
	lui	$14,0x36
	lw	$8,-3568($30)
	lui	$15,0x36
	lw	$7,-3768($14)
	lw	$6,-3764($15)
	addiu	$9,$0,-1
	lw	$4,-3584($22)
	daddu	$10,$29,$0
	addiu	$11,$29,8
	jal	0x288d80
	daddu	$5,$17,$0
	lw	$4,-3584($22)
	daddu	$5,$17,$0
	jal	0x2891b8
	addiu	$17,$17,1
	daddu	$16,$2,$0
	jal	0x139620
	daddu	$4,$2,$0
	daddu	$4,$16,$0
	jal	0x28dcc0
	daddu	$5,$21,$0
	daddu	$6,$20,$0
	daddu	$5,$0,$0
	jal	0x138c68
	daddu	$4,$16,$0
	lw	$14,20($29)
	addiu	$15,$0,3
	daddu	$4,$16,$0
	sw	$15,428($16)
	addu	$20,$20,$14
	jal	0x1395f8
	sw	$23,420($16)
	lui	$15,0x36
	lw	$8,-3568($30)
	lui	$14,0x36
	lw	$7,-3768($15)
	lw	$6,-3764($14)
	daddu	$4,$18,$0
	daddu	$5,$19,$0
	addiu	$9,$0,2
	addiu	$10,$0,-1
	jal	0x28d8c0
	daddu	$11,$0,$0
	daddu	$4,$18,$0
	jal	0x28dcc0
	daddu	$5,$16,$0
	slti	$15,$17,8
	bnez	$15,.L00297fc0
	addiu	$18,$18,408
	jal	0x2982f0
	lui	$16,0x36
	lui	$4,0x1
	daddu	$5,$0,$0
	ori	$4,$4,0x10a0
	addiu	$6,$0,640
	jal	0x2fde18
	addu	$4,$21,$4
	lw	$15,-2664($16)
	lw	$20,0($15)
	bnezl	$20,.L0029819c
	sw	$20,16($29)
	addiu	$4,$0,1
	jal	0x276690
	sw	$4,16($29)
	lui	$15,0x36
	daddu	$5,$0,$0
	jal	0x2891b8
	lw	$4,-3584($15)
	daddu	$16,$2,$0
	jal	0x192048
	addiu	$4,$0,13021
	sw	$2,408($16)
.L002980e0:
	lui	$16,0x36
.L002980e4:
	lw	$5,16($29)
	jal	0x28af90
	lw	$4,-3584($16)
	jal	0x287bc0
	nop
	jal	0x276608
	daddu	$4,$2,$0
	lw	$4,-3584($16)
	daddu	$5,$2,$0
	daddu	$6,$0,$0
	addiu	$7,$0,-1
	jal	0x2891f0
	addiu	$8,$0,-1
	jal	0x287bc0
	nop
	daddu	$4,$2,$0
	daddu	$5,$0,$0
	jal	0x2765e8
	daddu	$6,$0,$0
	lui	$15,0x36
	lw	$14,-2664($15)
	lw	$13,0($14)
	bnez	$13,.L0029814c
	lw	$4,-3584($16)
	jal	0x28af28
	addiu	$5,$0,16
.L0029814c:
	jal	0x299260
	nop
	jal	0x299290
	nop
	jal	0x2766b0
	addiu	$4,$0,1
	jal	0x287cc0
	daddu	$4,$0,$0
	ld	$16,48($29)
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
.L0029819c:
	addiu	$4,$0,2
	jal	0x294000
	daddu	$17,$0,$0
	addiu	$2,$2,16
	lw	$20,16($29)
	blez	$20,.L002980e0
	sw	$2,24($29)
	lui	$14,0x1
	ori	$15,$0,0xa998
	sw	$14,28($29)
	addu	$22,$21,$15
	lui	$15,0x1
	daddu	$23,$16,$0
	ori	$14,$14,0x10a0
	ori	$15,$15,0x10a0
	sw	$15,28($29)
	daddu	$30,$14,$0
	sw	$14,32($29)
.L002981e4:
	lw	$15,-2664($23)
	sll	$16,$17,0x1
	addu	$15,$16,$15
	jal	0x2983d8
	lh	$4,4($15)
	jal	0x294348
	daddu	$4,$2,$0
	lw	$15,-2664($23)
	addiu	$14,$0,12
	daddu	$19,$2,$0
	addiu	$6,$0,64
	addu	$16,$16,$15
	lh	$18,4($16)
	mult	$15,$18,$14
	lw	$14,24($29)
	addu	$15,$15,$14
	lhu	$15,8($15)
	bnez	$2,.L002982c8
	daddu	$4,$15,$0
	sll	$16,$17,0x6
	lw	$15,28($29)
	addu	$5,$21,$16
	jal	0x28de08
	addu	$5,$5,$15
	lui	$15,0x36
.L00298248:
	daddu	$5,$17,$0
	lw	$4,-3584($15)
	jal	0x2891b8
	addiu	$17,$17,1
	addu	$15,$21,$16
	addu	$15,$15,$30
	beqz	$19,.L002982b4
	sw	$15,408($2)
	jal	0x276568
	nop
	lb	$4,0($2)
	jal	0x2aa668
	daddu	$5,$18,$0
	beqz	$2,.L002982b8
	slt	$15,$17,$20
	jal	0x276568
	nop
	lb	$4,0($2)
	jal	0x2aa788
	daddu	$5,$18,$0
	lui	$14,0x37
	daddu	$4,$22,$0
	lw	$15,18368($14)
	lui	$14,0x37
	lw	$5,18364($14)
	jal	0x138c10
	movn	$5,$15,$2
.L002982b4:
	slt	$15,$17,$20
.L002982b8:
	bnez	$15,.L002981e4
	addiu	$22,$22,408
	b	.L002980e4
	lui	$16,0x36
.L002982c8:
	jal	0x192048
	sll	$16,$17,0x6
	lw	$14,32($29)
	addu	$5,$21,$16
	daddu	$4,$2,$0
	jal	0x192c90
	addu	$5,$5,$14
	b	.L00298248
	lui	$15,0x36
	.end func_00297e68
	.size func_00297e68, .-func_00297e68

