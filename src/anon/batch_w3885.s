# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3885).
# These functions were long-standing near misses in C/C++ after many sessions and permuter runs;
# see attempts.tsv and the best/ADDR_w3885.* drafts. Replace with C/C++ after 100%.
#   func_0019e848: VLA function; sched2 puts the a0 spill store sw a0,32(s8) before the VLA sp save
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0019e848,"ax",@progbits
	.align 2
	.globl func_0019e848
	.type func_0019e848, @function
	.ent func_0019e848
func_0019e848:
	addiu	$29,$29,-160
	sd	$30,144($29)
	sd	$16,80($29)
	sd	$20,112($29)
	move	$30,$29
	sd	$21,120($29)
	move	$16,$6
	sd	$22,128($29)
	move	$20,$0
	sd	$23,136($29)
	move	$21,$7
	sd	$31,152($29)
	move	$22,$0
	sd	$17,88($29)
	move	$23,$5
	sd	$18,96($29)
	sd	$19,104($29)
	sw	$29,36($30)
	sw	$4,32($30)
	jal	0x190128
	move	$4,$30
	move	$4,$30
	move	$5,$23
	jal	0x190878
	move	$6,$0
	sll	$15,$21,0x2
	addiu	$15,$15,15
	srl	$15,$15,0x4
	sll	$15,$15,0x4
	subu	$29,$29,$15
	blez	$21,.L0019e930
	sw	$29,40($30)
	move	$18,$16
	move	$19,$29
.L0019e8d0:
	jal	0x1a80c8
	lhu	$4,0($18)
	addiu	$18,$18,2
	lhu	$4,16($2)
	jal	0x1b8e88
	move	$16,$2
	move	$17,$2
	move	$4,$23
	move	$5,$16
	jal	0x19ea10
	move	$6,$2
	beqz	$2,.L0019e920
	lw	$14,32($30)
	lhu	$13,0($17)
	lw	$15,0($14)
	lhu	$14,38($15)
	beq	$14,$13,.L0019e9f8
	addiu	$22,$22,1
	sw	$17,0($19)
	addiu	$19,$19,4
.L0019e920:
	addiu	$20,$20,1
	slt	$15,$20,$21
	bnez	$15,.L0019e8d0
	nop
.L0019e930:
	blez	$22,.L0019e9ec
	lui	$14,0x36
	lui	$15,0x1
	lw	$16,14544($14)
	ori	$15,$15,0xdcd
	addiu	$4,$22,-1
	dsll32	$5,$22,0x0
	mult	$16,$16,$15
	dsll32	$4,$4,0x0
	dsrl32	$4,$4,0x0
	dsrl32	$5,$5,0x0
	sw	$16,14544($14)
	li	$15,1
	dsll32	$15,$15,0x0
	daddu	$4,$4,$15
	jal	0x312db8
	dsll32	$16,$16,0x0
	dsrl32	$16,$16,0x0
	move	$5,$2
	jal	0x312db8
	move	$4,$16
	dsll32	$2,$2,0x0
	lw	$15,40($30)
	dsra32	$2,$2,0x0
	lw	$4,32($30)
	sll	$2,$2,0x2
	move	$6,$30
	addu	$2,$2,$15
	move	$7,$0
	lw	$5,0($2)
.L0019e9a8:
	jal	0x19da68
	move	$8,$0
	lw	$29,36($30)
	li	$2,1
.L0019e9b8:
	move	$29,$30
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
.L0019e9ec:
	lw	$29,36($30)
	b	.L0019e9b8
	move	$2,$0
.L0019e9f8:
	lw	$4,32($30)
	move	$5,$17
	move	$6,$30
	b	.L0019e9a8
	move	$7,$0
	.end func_0019e848
	.size func_0019e848, .-func_0019e848
