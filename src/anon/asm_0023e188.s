# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/0023e188_perm760.c, ledger best/0023e188_unit.cpp
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0023e188,"ax",@progbits
	.align 3
	.globl func_0023e188
	.type func_0023e188, @function
	.ent func_0023e188
func_0023e188:
	addiu	$29,$29,-176
	move	$11,$0
	sd	$18,112($29)
	li	$10,320
	sd	$16,96($29)
	addiu	$13,$4,2916
	sd	$17,104($29)
	move	$18,$4
	sd	$19,120($29)
	move	$12,$29
	sd	$20,128($29)
	sd	$21,136($29)
	sd	$22,144($29)
	sd	$23,152($29)
	sd	$30,160($29)
	sd	$31,168($29)
	lbu	$15,0($13)
.L0023e1cc:
	mult	$15,$15,$10
	addu	$15,$15,$18
	lbu	$14,1948($15)
	beqz	$14,.L0023e1e8
	addiu	$13,$13,1
	sw	$11,0($12)
	addiu	$12,$12,4
.L0023e1e8:
	addiu	$11,$11,1
	slti	$15,$11,4
	bnezl	$15,.L0023e1cc
	lbu	$15,0($13)
	lw	$14,2920($18)
	move	$20,$0
	blez	$14,.L0023e26c
	move	$5,$14
.L0023e208:
	addiu	$6,$20,1
	slt	$15,$6,$14
	beqz	$15,.L0023e25c
	sll	$15,$20,0x2
	sll	$14,$6,0x2
	addu	$7,$15,$29
	addu	$11,$14,$29
	subu	$10,$5,$6
.L0023e228:
	lw	$8,0($11)
	lw	$9,0($7)
	addu	$13,$8,$18
	addu	$12,$9,$18
	lbu	$15,2912($13)
	lbu	$14,2912($12)
	sltu	$15,$15,$14
	beqz	$15,.L0023e254
	addiu	$10,$10,-1
	sw	$9,0($11)
	sw	$8,0($7)
.L0023e254:
	bnez	$10,.L0023e228
	addiu	$11,$11,4
.L0023e25c:
	move	$20,$6
	slt	$15,$6,$5
	bnez	$15,.L0023e208
	move	$14,$5
.L0023e26c:
	lw	$14,2924($18)
	blez	$14,.L0023e2ac
	move	$20,$0
	move	$16,$18
.L0023e27c:
	lw	$15,5328($16)
	beqz	$15,.L0023e29c
	move	$4,$15
	jal	func_00139d78
	nop
	beqzl	$2,.L0023e298
	sw	$0,5328($16)
.L0023e298:
	lw	$14,2924($18)
.L0023e29c:
	addiu	$20,$20,1
	slt	$15,$20,$14
	bnez	$15,.L0023e27c
	addiu	$16,$16,4
.L0023e2ac:
	move	$4,$18
	jal	func_0023e9f0
	move	$20,$0
	lw	$15,2920($18)
	blez	$15,.L0023e574
	move	$30,$0
	addiu	$23,$18,4512
	move	$22,$29
.L0023e2cc:
	lw	$19,0($22)
	li	$13,320
	addu	$15,$19,$18
	lbu	$14,2916($15)
	mult	$14,$14,$13
	sw	$0,80($29)
	sw	$0,84($29)
	addu	$14,$18,$14
	addiu	$17,$14,1632
	lbu	$15,316($17)
	beqzl	$15,.L0023e440
	lw	$15,192($17)
	lbu	$15,5345($18)
	beqz	$15,.L0023e358
	sll	$15,$19,0x2
	addu	$16,$15,$18
	lw	$4,5312($16)
	beqz	$4,.L0023e358
	addiu	$5,$29,80
	jal	func_00138c50
	addiu	$6,$29,84
	lw	$4,5312($16)
	addiu	$5,$29,88
	jal	func_00138cb8
	addiu	$6,$29,92
	lw	$13,80($29)
	lw	$15,88($29)
	lw	$14,84($29)
	addu	$13,$13,$15
	lw	$15,92($29)
	addiu	$13,$13,-256
	sw	$13,80($29)
	addu	$14,$14,$15
	addiu	$14,$14,-208
	sw	$14,84($29)
.L0023e358:
	jal	func_0014c350
	addiu	$4,$18,2944
	lbu	$15,5346($18)
	beqzl	$15,.L0023e378
	lw	$15,48($17)
	jal	func_0014c350
	addiu	$4,$18,3728
	lw	$15,48($17)
.L0023e378:
	beqz	$15,.L0023e43c
	li	$14,400
	lui	$15,0x3100
	mult	$14,$19,$14
	lui	$13,0x8
	ori	$15,$15,0x70
	ori	$13,$13,0x140
	sd	$15,80($17)
	sd	$13,72($17)
	addu	$14,$18,$14
	addiu	$13,$14,288
	addiu	$15,$14,304
	addiu	$30,$14,32
	movz	$15,$0,$13
	addiu	$14,$29,16
	lqc2	$vf1,0($30)
	lqc2	$vf2,16($30)
	lqc2	$vf3,32($30)
	lqc2	$vf4,48($30)
	lqc2	$vf5,0($15)
	lqc2	$vf6,16($15)
	lqc2	$vf7,32($15)
	lqc2	$vf8,48($15)
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	vmulax.wxyz	ACC,$vf1,vf6x
	vmadday.wxyz	ACC,$vf2,vf6y
	vmaddaz.wxyz	ACC,$vf3,vf6z
	vmaddw.wxyz	$vf6,$vf4,vf6w
	vmulax.wxyz	ACC,$vf1,vf7x
	vmadday.wxyz	ACC,$vf2,vf7y
	vmaddaz.wxyz	ACC,$vf3,vf7z
	vmaddw.wxyz	$vf7,$vf4,vf7w
	vmulax.wxyz	ACC,$vf1,vf8x
	vmadday.wxyz	ACC,$vf2,vf8y
	vmaddaz.wxyz	ACC,$vf3,vf8z
	vmaddw.wxyz	$vf8,$vf4,vf8w
	sqc2	$vf5,0($14)
	sqc2	$vf6,16($14)
	sqc2	$vf7,32($14)
	sqc2	$vf8,48($14)
	lw	$4,48($17)
	addiu	$6,$17,128
	addiu	$7,$17,56
	move	$5,$14
	jal	func_0011cdf0
	move	$8,$0
.L0023e43c:
	lw	$15,192($17)
.L0023e440:
	beqz	$15,.L0023e480
	addiu	$4,$17,192
	addiu	$16,$17,220
	jal	func_001de590
	move	$21,$17
	li	$17,15
	lw	$15,0($16)
.L0023e45c:
	addiu	$16,$16,4
	beqz	$15,.L0023e470
	move	$4,$15
	jal	func_001dcb98
	addiu	$5,$21,312
.L0023e470:
	addiu	$17,$17,-1
	bgezl	$17,.L0023e45c
	lw	$15,0($16)
	move	$17,$21
.L0023e480:
	sll	$14,$19,0x1
	lw	$15,80($29)
	addu	$14,$14,$18
	lbu	$12,316($17)
	lh	$13,2928($14)
	addu	$15,$15,$13
	sw	$15,80($29)
	lw	$15,84($29)
	lh	$13,2936($14)
	addu	$15,$15,$13
	beqz	$12,.L0023e4f0
	sw	$15,84($29)
	lh	$6,84($29)
	move	$4,$23
	jal	func_0014b1e0
	lh	$5,80($29)
	lui	$5,0xff
	move	$4,$23
	jal	func_0014b200
	ori	$5,$5,0xffff
	lbu	$8,315($17)
	move	$4,$23
	lbu	$5,312($17)
	lbu	$6,313($17)
	jal	func_0014b220
	lbu	$7,314($17)
	jal	func_0014c350
	move	$4,$23
.L0023e4f0:
	lw	$15,2920($18)
	addiu	$20,$20,1
	slt	$15,$20,$15
	bnez	$15,.L0023e2cc
	addiu	$22,$22,4
.L0023e504:
	beqz	$30,.L0023e520
	move	$4,$30
	addiu	$5,$30,256
	jal	func_001dd320
	move	$6,$0
	jal	func_001dd920
	move	$4,$0
.L0023e520:
	move	$4,$23
	move	$5,$0
	jal	func_0014b1e0
	move	$6,$0
	lw	$15,2920($18)
	beqz	$15,.L0023e548
	ld	$16,96($29)
	jal	func_00236d60
	nop
	ld	$16,96($29)
.L0023e548:
	ld	$17,104($29)
	ld	$18,112($29)
	ld	$19,120($29)
	ld	$20,128($29)
	ld	$21,136($29)
	ld	$22,144($29)
	ld	$23,152($29)
	ld	$30,160($29)
	ld	$31,168($29)
	jr	$31
	addiu	$29,$29,176
.L0023e574:
	b	.L0023e504
	addiu	$23,$18,4512
	nop
	.end func_0023e188
	.size func_0023e188, 1016
