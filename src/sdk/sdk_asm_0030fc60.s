# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0030fc60,"ax",@progbits
	.align 2
	.globl func_0030fc60
	.type func_0030fc60, @function
	.ent func_0030fc60
func_0030fc60:
	addiu	$29,$29,-144
	lui	$3,0x1000
	sd	$22,96($29)
	ori	$3,$3,0x1010
	sd	$31,128($29)
	move	$22,$6
	sd	$23,112($29)
	sd	$21,80($29)
	sd	$20,64($29)
	sd	$19,48($29)
	sd	$18,32($29)
	sd	$17,16($29)
	sd	$16,0($29)
	lw	$2,0($3)
	andi	$2,$2,0x400
	beqz	$2,.L0030fe10
	lui	$21,0x36
	addiu	$2,$21,28952
	lw	$16,24($2)
	beqz	$16,.L0030fe10
	move	$20,$21
	li	$23,14745
	lui	$2,0x1000
	nop
.L0030fcc0:
	lui	$3,0x1000
	ori	$2,$2,0x1000
	ori	$3,$3,0x1010
	lw	$6,0($2)
	lw	$17,0($3)
	ld	$4,32($16)
	ld	$2,16($16)
	andi	$5,$17,0x800
	ld	$3,24($16)
	daddu	$4,$4,$2
	beqz	$5,.L0030fd14
	dsubu	$19,$4,$3
	ld	$2,28952($20)
	lui	$4,0xffff
	ori	$4,$4,0xfbff
	daddiu	$2,$2,1
	and	$4,$17,$4
	jal	0x30f6a0
	sd	$2,28952($20)
	lui	$6,0x1000
	lw	$6,4096($6)
.L0030fd14:
	ld	$4,28952($20)
	dsll32	$2,$6,0x0
	dsrl32	$2,$2,0x0
	andi	$3,$17,0x3
	dsll	$4,$4,0x10
	sll	$3,$3,0x2
	or	$4,$4,$2
	dsllv	$17,$4,$3
	sltu	$2,$17,$19
	bnez	$2,.L0030fe10
	addiu	$18,$20,28952
	jal	0x30fc28
	move	$4,$16
	move	$19,$2
	ld	$6,24($16)
	lw	$2,8($16)
	sll	$7,$16,0x4
	ld	$3,16($16)
	daddu	$6,$17,$6
	or	$2,$7,$2
	sw	$2,28($18)
	dsubu	$6,$6,$3
	lw	$28,44($16)
	lw	$4,8($16)
	move	$8,$22
	lw	$2,40($16)
	or	$4,$7,$4
	ld	$5,32($16)
	jalr	$2
	lw	$7,48($16)
	move	$5,$2
	bnez	$5,.L0030fdb0
	li	$2,-1
	lw	$3,12($16)
	lui	$2,0xffff
	ori	$2,$2,0xfffd
	and	$3,$3,$2
	b	.L0030fdfc
	sw	$3,12($16)
.L0030fdb0:
	bne	$5,$2,.L0030fde0
	li	$2,14744
	sw	$0,8($16)
	sw	$0,12($16)
	lw	$3,20($18)
	lw	$2,16($18)
	sw	$3,0($16)
	addiu	$2,$2,-1
	sw	$16,20($18)
	sw	$2,16($18)
	b	.L0030fe00
	move	$16,$19
.L0030fde0:
	ld	$3,32($16)
	sltu	$2,$2,$5
	move	$4,$16
	movz	$5,$23,$2
	daddu	$3,$3,$5
	jal	0x30fba0
	sd	$3,32($16)
.L0030fdfc:
	move	$16,$19
.L0030fe00:
	bnez	$16,.L0030fcc0
	lui	$2,0x1000
	b	.L0030fe14
	addiu	$4,$21,28952
.L0030fe10:
	addiu	$4,$21,28952
.L0030fe14:
	li	$3,-1
	sw	$3,28($4)
	lui	$2,0x1000
	ori	$2,$2,0x1000
	lui	$3,0x1000
	lw	$4,0($2)
	ori	$3,$3,0x1010
	lw	$16,0($3)
	andi	$2,$16,0x800
	beqz	$2,.L0030fe64
	nop
	ld	$2,28952($21)
	lui	$4,0xffff
	ori	$4,$4,0xfbff
	daddiu	$2,$2,1
	and	$4,$16,$4
	jal	0x30f6a0
	sd	$2,28952($21)
	lui	$4,0x1000
	lw	$4,4096($4)
.L0030fe64:
	ld	$2,28952($21)
	dsll32	$3,$4,0x0
	dsrl32	$3,$3,0x0
	andi	$4,$16,0x3
	dsll	$2,$2,0x10
	sll	$4,$4,0x2
	or	$2,$2,$3
	jal	0x30fa10
	dsllv	$4,$2,$4
	lui	$2,0x1000
	lw	$2,4096($2)
	lui	$3,0x1000
	lw	$3,4112($3)
	andi	$2,$3,0x800
	beqz	$2,.L0030fec8
	nop
	ld	$2,28952($21)
	lui	$4,0xffff
	ori	$4,$4,0xfbff
	daddiu	$2,$2,1
	and	$4,$3,$4
	jal	0x30f6a0
	sd	$2,28952($21)
	lui	$2,0x1000
	lw	$2,4096($2)
.L0030fec8:
	ld	$2,28952($21)
	sync
	ei
	ld	$31,128($29)
	move	$2,$0
	ld	$23,112($29)
	ld	$22,96($29)
	ld	$21,80($29)
	ld	$20,64($29)
	ld	$19,48($29)
	ld	$18,32($29)
	ld	$17,16($29)
	ld	$16,0($29)
	jr	$31
	addiu	$29,$29,144
	.end func_0030fc60
	.size func_0030fc60, 676
