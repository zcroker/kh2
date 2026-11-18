# Kept as assembly (last step of the match ladder): func_0010fb10 (camera target pick, _nsa C++ draft 13 lines off: loop
# preheader giv copy, cand store base t6/t7, post-loop &tab[k].t remat) and func_00212338 (model draw, sibling of 00215f28/0021aee8,
# _nsa C draft ~86% inline asm and still ~12 lines off). C drafts: best/0010fb10_w3905.cpp, best/00212338_w3905.c.
# Split out of batch_w3905.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0010fb10,"ax",@progbits
	.align 3
	.globl func_0010fb10
	.type func_0010fb10, @function
	.ent func_0010fb10
func_0010fb10:
	addiu	$29,$29,-128
	move	$14,$0
	sd	$18,64($29)
	sd	$16,48($29)
	sd	$17,56($29)
	sd	$19,72($29)
	sd	$20,80($29)
	sd	$21,88($29)
	sd	$22,96($29)
	sd	$23,104($29)
	sd	$30,112($29)
	sd	$31,120($29)
	lw	$15,3300($4)
	beqz	$15,.L0010fdfc
	move	$18,$4
	jal	0x10f8d0
	nop
	bnez	$2,.L0010fdfc
	move	$14,$0
	lw	$15,2940($18)
	move	$4,$18
	lw	$14,3168($18)
	ori	$15,$15,0x20
	sw	$14,36($29)
	lw	$14,3172($18)
	sw	$14,40($29)
	jal	0x10eee8
	sw	$15,2940($18)
	lw	$4,2912($18)
	jal	0x1137e0
	sw	$0,3304($18)
	lw	$4,2912($18)
	jal	0x1137e8
	move	$21,$2
	sw	$2,44($29)
	lui	$15,0x3b
	lb	$14,-28016($15)
	bnez	$14,.L0010fbe4
	move	$4,$29
	lui	$15,0x3b
	li	$17,31
	addiu	$16,$15,-28008
	li	$19,-1
	addiu	$4,$16,4
.L0010fbc0:
	addiu	$17,$17,-1
	jal	0x190128
	addiu	$16,$16,28
	bne	$17,$19,.L0010fbc0
	addiu	$4,$16,4
	li	$14,1
	lui	$15,0x3b
	sb	$14,-28016($15)
	move	$4,$29
.L0010fbe4:
	jal	0x190128
	move	$20,$0
	move	$19,$0
.L0010fbf0:
	blez	$21,.L0010fd30
	move	$22,$0
	lw	$16,44($29)
	lui	$15,0x3b
	move	$30,$18
	addiu	$15,$15,-28008
	move	$18,$15
	move	$17,$16
	move	$23,$0
.L0010fc14:
	lw	$15,4($17)
	beqzl	$15,.L0010fd1c
	addiu	$19,$19,1
	beqz	$20,.L0010fe88
	li	$15,1
	beql	$20,$15,.L0010fe70
	lw	$15,0($17)
	lw	$15,16($17)
.L0010fc34:
	beqz	$15,.L0010fc64
	nop
	lw	$15,8($15)
	blez	$15,.L0010fc64
	nop
	lw	$4,1164($30)
	beqz	$4,.L0010fc64
	nop
	jal	0x1a1de0
	nop
	bnezl	$2,.L0010fd1c
	addiu	$19,$19,1
.L0010fc64:
	jal	0x190128
	move	$4,$29
	lw	$14,8($16)
	andi	$15,$14,0x1
	andi	$15,$15,0xff
	beqz	$15,.L0010fe64
	sra	$15,$14,0x1
	lw	$12,2912($30)
	lw	$14,4($16)
	addu	$15,$12,$15
	srl	$14,$14,0x2
	lw	$13,0($15)
	sll	$14,$14,0x2
	addu	$14,$14,$13
	lw	$14,0($14)
.L0010fca0:
	lw	$4,8($16)
	move	$5,$16
	move	$6,$29
	addiu	$7,$29,32
	sra	$4,$4,0x1
	li	$8,1
	jalr	$14
	addu	$4,$12,$4
	beqz	$2,.L0010fd18
	slti	$15,$22,32
	beqz	$15,.L0010fd18
	lui	$14,0x3b
	sw	$16,0($18)
	addiu	$14,$14,-28004
	addiu	$22,$22,1
	lw	$15,0($29)
	addu	$13,$23,$14
	addiu	$23,$23,28
	sw	$15,0($13)
	lw	$14,16($29)
	sw	$14,16($13)
	lw	$15,4($29)
	sw	$15,4($13)
	lw	$14,8($29)
	sw	$14,8($13)
	lw	$15,12($29)
	sw	$15,12($13)
	lw	$14,32($29)
	sw	$14,24($18)
	addiu	$18,$18,28
.L0010fd18:
	addiu	$19,$19,1
.L0010fd1c:
	addiu	$17,$17,36
	slt	$15,$19,$21
	bnez	$15,.L0010fc14
	addiu	$16,$16,36
	move	$18,$30
.L0010fd30:
	blezl	$22,.L0010fe40
	addiu	$20,$20,1
	jal	0x10f648
	move	$4,$22
	lui	$15,0x3b
	addiu	$15,$15,-28008
	addiu	$13,$15,4
	li	$15,28
	mult	$2,$2,$15
	lui	$15,0x3b
	addiu	$15,$15,-28008
	addu	$14,$2,$15
	lw	$16,0($14)
	lui	$15,0x3b
	addiu	$15,$15,-27984
	lw	$4,8($16)
	addu	$17,$2,$15
	andi	$15,$4,0x1
	andi	$15,$15,0xff
	beqz	$15,.L0010fe30
	addu	$6,$2,$13
	lw	$12,2912($18)
	sra	$15,$4,0x1
	lw	$14,4($16)
	addu	$15,$12,$15
	srl	$14,$14,0x2
	lw	$13,0($15)
	sll	$14,$14,0x2
	addu	$14,$14,$13
	lw	$14,0($14)
.L0010fda8:
	sra	$4,$4,0x1
	move	$5,$16
	addu	$4,$12,$4
	move	$7,$17
	jalr	$14
	move	$8,$0
	lw	$15,0($16)
	andi	$15,$15,0x1
	bnezl	$15,.L0010fde8
	sw	$0,3304($18)
	move	$4,$18
	jal	0x10ef28
	move	$5,$16
	lw	$15,3304($18)
	addiu	$15,$15,1
	sw	$15,3304($18)
.L0010fde8:
	lw	$6,0($17)
	move	$4,$18
	jal	0x10eed8
	move	$5,$16
	li	$14,1
.L0010fdfc:
	ld	$16,48($29)
	move	$2,$14
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
.L0010fe30:
	lw	$14,4($16)
	b	.L0010fda8
	lw	$12,2912($18)
	nop
.L0010fe40:
	slti	$15,$20,2
	bnez	$15,.L0010fbf0
	move	$19,$0
	lw	$14,40($29)
	sw	$14,3172($18)
	lw	$15,36($29)
	move	$14,$0
	b	.L0010fdfc
	sw	$15,3168($18)
.L0010fe64:
	lw	$14,4($16)
	b	.L0010fca0
	lw	$12,2912($30)
.L0010fe70:
	andi	$15,$15,0x20
	beqzl	$15,.L0010fd1c
	addiu	$19,$19,1
	b	.L0010fc34
	lw	$15,16($17)
	nop
.L0010fe88:
	lw	$15,0($17)
	andi	$15,$15,0x10
	bnezl	$15,.L0010fc34
	lw	$15,16($17)
	b	.L0010fd1c
	addiu	$19,$19,1
	.end func_0010fb10
	.size func_0010fb10, .-func_0010fb10
