# Kept as assembly: -O0 code with gp-relative addresses, which the -G0 build cannot emit from C.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002b6708,"ax",@progbits
	.align 2
	.globl func_002b6708
	.type func_002b6708, @function
	.ent func_002b6708
func_002b6708:
	addiu	$29,$29,-112
	sd	$30,32($29)
	sd	$31,40($29)
	move	$30,$29
	sd	$5,56($30)
	sd	$6,64($30)
	sd	$7,72($30)
	sd	$8,80($30)
	sd	$9,88($30)
	sd	$10,96($30)
	sd	$11,104($30)
	jal	0x2b6678
	sw	$4,0($30)
	move	$15,$2
	sw	$15,16($30)
	lw	$15,16($30)
	bgez	$15,.L002b675c
	nop
	li	$15,-1
	b	.L002b6904
	sw	$15,20($30)
.L002b675c:
	addiu	$15,$30,112
	addiu	$15,$15,-56
	sw	$15,4($30)
	sw	$0,8($30)
.L002b676c:
	lw	$15,8($30)
	lw	$14,0($30)
	slt	$15,$15,$14
	bnez	$15,.L002b6788
	nop
	b	.L002b67d4
	nop
.L002b6788:
	lw	$15,16($30)
	sll	$14,$15,0x4
	lw	$15,8($30)
	addu	$15,$14,$15
	sll	$14,$15,0x2
	lui	$15,0x1e2
	addiu	$15,$15,8320
	addu	$12,$14,$15
	addiu	$13,$30,4
	lw	$15,0($13)
	move	$14,$15
	addiu	$15,$15,8
	sw	$15,0($13)
	lw	$15,0($14)
	sw	$15,0($12)
	lw	$15,8($30)
	addiu	$15,$15,1
	b	.L002b676c
	sw	$15,8($30)
.L002b67d4:
	lw	$15,16($30)
	sll	$14,$15,0x6
	lui	$15,0x1e2
	addiu	$15,$15,8380
	addu	$14,$14,$15
	li	$15,1
	sw	$15,0($14)
	lw	$15,16($30)
	sll	$14,$15,0x4
	lui	$15,0x36
	addiu	$15,$15,-2336
	addu	$13,$14,$15
	lw	$15,16($30)
	sll	$14,$15,0x6
	lui	$15,0x1e2
	addiu	$15,$15,8320
	addu	$15,$15,$14
	sw	$15,0($13)
	lw	$15,16($30)
	sll	$14,$15,0x4
	lui	$15,0x36
	addiu	$15,$15,-2336
	addu	$13,$14,$15
	lw	$15,16($30)
	sll	$14,$15,0x6
	lw	$15,-7464($28)
	addu	$15,$15,$14
	sw	$15,4($13)
	lw	$15,16($30)
	sll	$14,$15,0x4
	lui	$15,0x36
	addiu	$15,$15,-2336
	addu	$14,$14,$15
	li	$15,64
	sw	$15,8($14)
	lw	$15,16($30)
	sll	$14,$15,0x4
	lui	$15,0x36
	addiu	$15,$15,-2336
	addu	$15,$14,$15
	sw	$0,12($15)
	jal	0x3058a0
	move	$4,$0
.L002b6880:
	lw	$15,16($30)
	sll	$14,$15,0x4
	lui	$15,0x36
	addiu	$15,$15,-2336
	addu	$15,$14,$15
	move	$4,$15
	jal	0x308310
	li	$5,1
	sw	$2,12($30)
	lw	$15,12($30)
	bnez	$15,.L002b68e0
	nop
	lui	$4,0x37
	addiu	$4,$4,19928
	lui	$5,0x33
	lw	$5,-18144($5)
	jal	0x2fdfc8
	nop
	lui	$4,0x37
	addiu	$4,$4,19944
	jal	0x2fdfc8
	lw	$5,12($30)
	b	.L002b6880
	nop
.L002b68e0:
	nop
.L002b68e4:
	lw	$4,12($30)
	jal	0x3059c0
	nop
	move	$15,$2
	bgez	$15,.L002b68e4
	nop
	lw	$15,16($30)
	sw	$15,20($30)
.L002b6904:
	lw	$2,20($30)
	move	$29,$30
	ld	$30,32($29)
	ld	$31,40($29)
	jr	$31
	addiu	$29,$29,112
	.end func_002b6708
	.size func_002b6708, 532
