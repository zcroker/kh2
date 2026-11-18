# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   Closest C drafts: ledger best/001f69c0_unit.cpp
#   001f69c0 (L60, 2026-11-18): near-miss 2 gap fn; local-alloc: q2 (v[2]) must be allocated after q1; reusing q2 for the 2nd result makes it global but with a v0 copy preference; 16 reuse combos, s16/f32 locals, set4 helpers, -g/-fno-sched flags no gain; permut
#     No symbol, written as literal lui/lo values: 0x003701e8, 0x003701ec
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001f69c0,"ax",@progbits
	.align 3
	.globl func_001f69c0
	.type func_001f69c0, @function
	.ent func_001f69c0
func_001f69c0:
	addiu	$29,$29,-80
	lui	$15,%hi(D_01d9e6e0)
	sd	$16,32($29)
	sd	$17,40($29)
	sd	$18,48($29)
	move	$16,$6
	sd	$19,56($29)
	move	$17,$5
	sd	$31,64($29)
	move	$18,$4
	swc1	$f21,76($29)
	move	$19,$0
	swc1	$f20,72($29)
	lw	$13,%lo(D_01d9e6e0)($15)
	lw	$14,12($5)
	lw	$15,128($13)
	move	$4,$13
	sll	$14,$14,0x4
	addu	$15,$15,$14
	beqz	$15,.L001f6a24
	move	$5,$15
	jal	func_001e7a98
	nop
	sw	$18,4($2)
	move	$19,$2
.L001f6a24:
	lh	$15,0($16)
	move	$5,$29
	lh	$13,4($16)
	mtc1	$15,$f0
	lh	$14,2($16)
	cvt.s.w	$f0,$f0
	lw	$4,16($17)
	mtc1	$13,$f2
	lui	$15,0x37
	mtc1	$14,$f1
	addiu	$15,$15,488
	cvt.s.w	$f2,$f2
	addu	$4,$19,$4
	cvt.s.w	$f1,$f1
	addiu	$4,$4,160
	swc1	$f0,0($29)
	lwc1	$f0,0($15)
	swc1	$f1,4($29)
	swc1	$f0,12($29)
	jal	func_002226b8
	swc1	$f2,8($29)
	lwc1	$f20,4($29)
	move	$4,$29
	lw	$15,24($17)
	addiu	$5,$29,16
	neg.s	$f0,$f20
	lwc1	$f21,0($29)
	addu	$16,$19,$15
	addiu	$17,$16,160
	swc1	$f21,4($29)
	jal	func_001f6868
	swc1	$f0,0($29)
	beqz	$2,.L001f6adc
	lui	$15,0x37
	lwc1	$f12,16($29)
	addiu	$15,$15,492
	lwc1	$f0,0($15)
	jal	func_00313b80
	mul.s	$f12,$f12,$f0
	lui	$15,0x37
	move	$4,$2
	jal	func_00314190
	ld	$5,480($15)
	jal	func_003143e0
	move	$4,$2
	sw	$2,8($17)
.L001f6adc:
	mula.s	$f20,$f20
	madd.s	$f20,$f21,$f21
	jal	func_00222978
	mov.s	$f12,$f20
	swc1	$f0,0($29)
	move	$4,$29
	addiu	$5,$29,16
	lwc1	$f0,8($29)
	neg.s	$f0,$f0
	jal	func_001f6868
	swc1	$f0,4($29)
	beqz	$2,.L001f6b40
	lui	$15,0x37
	lwc1	$f12,16($29)
	addiu	$15,$15,492
	lwc1	$f0,0($15)
	jal	func_00313b80
	mul.s	$f12,$f12,$f0
	lui	$15,0x37
	move	$4,$2
	jal	func_00314190
	ld	$5,480($15)
	jal	func_003143e0
	move	$4,$2
	sw	$2,160($16)
.L001f6b40:
	sw	$0,4($17)
	ld	$16,32($29)
	ld	$17,40($29)
	ld	$18,48($29)
	ld	$19,56($29)
	ld	$31,64($29)
	lwc1	$f21,76($29)
	lwc1	$f20,72($29)
	jr	$31
	addiu	$29,$29,80
	.end func_001f69c0
	.size func_001f69c0, 424
