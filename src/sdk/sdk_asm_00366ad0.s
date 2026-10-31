# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00366ad0,"ax",@progbits
	.align 2
	.globl func_00366ad0
	.type func_00366ad0, @function
	.ent func_00366ad0
func_00366ad0:
	addiu	$29,$29,-144
	lui	$2,0xb000
	sd	$23,112($29)
	ori	$2,$2,0x1800
	sd	$22,96($29)
	move	$23,$6
	sd	$21,80($29)
	move	$22,$5
	sd	$19,48($29)
	lui	$21,0x8007
	sd	$31,128($29)
	andi	$19,$4,0xffff
	sd	$18,32($29)
	sd	$17,16($29)
	sd	$16,0($29)
	sd	$20,64($29)
	lw	$3,26368($21)
	lw	$20,0($2)
	slti	$3,$3,64
	bnez	$3,.L00366b40
	addu	$19,$19,$20
	b	.L00366be0
	li	$2,-1
.L00366b2c:
	move	$18,$3
	dsllv	$2,$2,$3
	or	$2,$4,$2
	b	.L00366b70
	sd	$2,26376($5)
.L00366b40:
	lui	$5,0x8007
	move	$3,$0
	ld	$4,26376($5)
	dsrlv	$2,$4,$3
.L00366b50:
	andi	$2,$2,0x1
	beqz	$2,.L00366b2c
	li	$2,1
	addiu	$3,$3,1
	slti	$2,$3,64
	bnez	$2,.L00366b50
	dsrlv	$2,$4,$3
	li	$18,-1
.L00366b70:
	bltz	$18,.L00366be0
	move	$2,$18
	move	$17,$28
	move	$5,$19
	jal	0x76058
	move	$4,$20
	li	$4,20
	lui	$8,0x8007
	mult	$2,$2,$4
	addiu	$3,$8,26432
	lw	$5,26368($21)
	addiu	$16,$3,4
	addiu	$5,$5,1
	addu	$4,$2,$3
	addu	$7,$3,$2
	addu	$16,$2,$16
	sh	$20,2($4)
	sh	$19,0($4)
	move	$6,$7
	sw	$18,0($16)
	move	$3,$6
	sw	$17,16($7)
	lhu	$4,26432($8)
	sw	$22,8($6)
	sw	$23,12($3)
	jal	0x76460
	sw	$5,26368($21)
	lw	$2,0($16)
.L00366be0:
	ld	$31,128($29)
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
	.end func_00366ad0
	.size func_00366ad0, 316
