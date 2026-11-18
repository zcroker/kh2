# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001610c0,"ax",@progbits
	.align 3
	.globl func_001610c0
	.type func_001610c0, @function
	.ent func_001610c0
func_001610c0:
	addiu	$29,$29,-128
	sd	$17,72($29)
	sd	$18,80($29)
	sd	$19,88($29)
	move	$17,$0
	sd	$20,96($29)
	addiu	$18,$29,16
	sd	$21,104($29)
	lui	$19,%hi(D_004f3b38)
	sd	$16,64($29)
	li	$20,128
	sd	$31,112($29)
	li	$21,0xffff
.L001610f4:
	bnezl	$17,.L00161100
	lw	$16,128($17)
	lw	$16,%lo(D_004f3b38)($19)
.L00161100:
	bnez	$16,.L00161130
	move	$17,$16
	ld	$16,64($29)
	ld	$17,72($29)
	ld	$18,80($29)
	ld	$19,88($29)
	ld	$20,96($29)
	ld	$21,104($29)
	ld	$31,112($29)
	jr	$31
	addiu	$29,$29,128
	nop
.L00161130:
	lw	$15,428($16)
	andi	$15,$15,0x2
	beqz	$15,.L001610f4
	nop
	sw	$21,36($29)
	sw	$0,40($29)
	sw	$0,44($29)
	sw	$0,48($29)
	sb	$0,52($29)
	sqc2	$vf0,0($29)
	lqc2	$vf4,0($29)
	vsub.xyz	$vf5,$vf0,$vf4
	sqc2	$vf5,0($18)
	addiu	$4,$16,80
	jal	func_00143520
	move	$5,$29
	lbu	$14,33($29)
	addiu	$15,$16,420
	lbu	$12,32($29)
	lbu	$13,34($29)
	sb	$14,1($15)
	sb	$13,2($15)
	sb	$20,3($15)
	lbu	$14,421($16)
	lbu	$15,422($16)
	sb	$12,680($16)
	sb	$15,682($16)
	sb	$14,681($16)
	b	.L001610f4
	sb	$12,420($16)
	.end func_001610c0
	.size func_001610c0, 232
