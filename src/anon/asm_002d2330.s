# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/002d2330_unit.cpp, ledger best/002d2330_unit_v2.cpp
#     No symbol, written as literal lui/lo values: 0x00375a34, 0x00375a38
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002d2330,"ax",@progbits
	.align 3
	.globl func_002d2330
	.type func_002d2330, @function
	.ent func_002d2330
func_002d2330:
	addiu	$29,$29,-128
	sd	$16,64($29)
	sd	$17,72($29)
	sd	$18,80($29)
	move	$16,$5
	sd	$20,96($29)
	move	$17,$7
	sd	$19,88($29)
	move	$18,$4
	sd	$21,104($29)
	sd	$31,112($29)
	lbu	$15,88($4)
	beqz	$15,.L002d2440
	move	$20,$6
	lw	$15,1416($5)
	andi	$15,$15,0x80
	bnez	$15,.L002d2390
	move	$4,$16
	lw	$15,8($5)
	li	$14,1565
	lw	$13,0($15)
	bnel	$13,$14,.L002d2444
	ld	$16,64($29)
	move	$4,$16
.L002d2390:
	jal	func_0016c028
	addiu	$19,$29,16
	lqc2	$vf1,0($2)
	lqc2	$vf2,0($20)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($19)
	lqc2	$vf1,0($19)
	lqc2	$vf2,0($17)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($29)
	lq	$8,0($29)
	sq	$8,0($19)
	lui	$15,0x37
	mtc1	$0,$f0
	addiu	$15,$15,23092
	addiu	$21,$29,48
	lwc1	$f2,0($15)
	addiu	$20,$29,32
	move	$4,$18
	move	$5,$19
	lui	$15,0x37
	move	$7,$21
	addiu	$15,$15,23096
	lwc1	$f1,0($15)
	lw	$15,1416($16)
	andi	$15,$15,0x80
	beqz	$15,.L002d2464
	move	$6,$20
	jal	func_002d1b90
	nop
	addiu	$20,$29,32
	addiu	$21,$29,48
.L002d2410:
	lqc2	$vf1,0($19)
	lqc2	$vf2,0($29)
	vsub.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($21)
	lqc2	$vf1,0($21)
	lqc2	$vf2,0($17)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($20)
	beq	$17,$20,.L002d2444
	ld	$16,64($29)
	lq	$8,0($20)
	sq	$8,0($17)
.L002d2440:
	ld	$16,64($29)
.L002d2444:
	ld	$17,72($29)
	ld	$18,80($29)
	ld	$19,88($29)
	ld	$20,96($29)
	ld	$21,104($29)
	ld	$31,112($29)
	jr	$31
	addiu	$29,$29,128
.L002d2464:
	swc1	$f2,48($29)
	move	$4,$18
	swc1	$f1,52($29)
	move	$5,$19
	swc1	$f0,60($29)
	swc1	$f2,32($29)
	swc1	$f1,36($29)
	swc1	$f0,40($29)
	swc1	$f0,44($29)
	jal	func_002d1bf8
	swc1	$f0,56($29)
	b	.L002d2410
	nop
	.end func_002d2330
	.size func_002d2330, 360
