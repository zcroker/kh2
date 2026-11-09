# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3884).
# Both functions were long-standing near misses in C/C++ after many sessions; see coord attempts.tsv
# and the best/ADDR_w3884.cpp drafts. Replace with C/C++ after 100%.
#   func_0015c958: colour/position setter (sched2 order of the flag sb, sd s1/ra and lui s1 in the prologue)
#   func_0028be78: scroll bar update (sched1 hoists li a1,1 above the len+pos addu, so cprop cannot keep len in a1)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0015c958,"ax",@progbits
	.align 2
	.globl func_0015c958
	.type func_0015c958, @function
	.ent func_0015c958
func_0015c958:
	mtc1	$9,$f0
	lui	$14,0x4f
	addiu	$14,$14,13904
	mtc1	$8,$f1
	cvt.s.w	$f0,$f0
	li	$13,1
	cvt.s.w	$f1,$f1
	lui	$15,0x34
	sb	$13,3760($15)
	addiu	$29,$29,-32
	sd	$16,0($29)
	andi	$5,$5,0xff
	swc1	$f0,84($14)
	andi	$7,$7,0xff
	swc1	$f1,80($14)
	addiu	$16,$14,68
	mtc1	$4,$f0
	li	$15,128
	sd	$31,16($29)
	andi	$6,$6,0xff
	cvt.s.w	$f0,$f0
	sb	$5,68($14)
	sd	$17,8($29)
	lwc1	$f12,12($16)
	lui	$17,0x4f
	swc1	$f0,72($14)
	lwc1	$f13,16($16)
	sb	$7,2($16)
	sb	$15,3($16)
	jal	0x10a8a8
	sb	$6,1($16)
	lwc1	$f12,4($16)
	jal	0x10a828
	lwc1	$f13,8($16)
	lbu	$6,2($16)
	lbu	$4,13972($17)
	jal	0x10a7d8
	lbu	$5,1($16)
	lwc1	$f0,12($16)
	lwc1	$f1,16($16)
	cvt.w.s	$f2,$f0
	cvt.w.s	$f0,$f1
	mfc1	$4,$f2
	andi	$4,$4,0xff
	mfc1	$5,$f0
	jal	0x1dd1e8
	andi	$5,$5,0xff
	lwc1	$f12,4($16)
	jal	0x1dd1b0
	lwc1	$f13,8($16)
	lbu	$4,13972($17)
	lbu	$6,2($16)
	lbu	$5,1($16)
	ld	$17,8($29)
	ld	$16,0($29)
	ld	$31,16($29)
	j	0x1dd1c8
	addiu	$29,$29,32
	.end func_0015c958
	.size func_0015c958, .-func_0015c958


	.section .text.func_0028be78,"ax",@progbits
	.align 2
	.globl func_0028be78
	.type func_0028be78, @function
	.ent func_0028be78
func_0028be78:
	addiu	$29,$29,-48
	lui	$15,0x37
	sd	$17,8($29)
	addiu	$15,$15,17452
	sd	$18,16($29)
	move	$7,$5
	sd	$16,0($29)
	move	$11,$5
	sd	$31,24($29)
	move	$17,$4
	swc1	$f20,32($29)
	move	$18,$0
	sw	$11,40($4)
	lw	$12,36($4)
	lw	$14,32($4)
	mtc1	$12,$f0
	mtc1	$14,$f3
	subu	$13,$14,$12
	cvt.s.w	$f0,$f0
	cvt.s.w	$f3,$f3
	lwc1	$f4,0($15)
	addu	$15,$5,$12
	nop
	nop
	div.s	$f2,$f0,$f3
	slt	$15,$15,$14
	movz	$7,$13,$15
	li	$5,1
	mtc1	$7,$f1
	c.le.s	$f4,$f2
	bc1f	.L0028bf00
	cvt.s.w	$f1,$f1
	mov.s	$f2,$f4
	li	$18,1
.L0028bf00:
	lwc1	$f0,44($17)
	move	$6,$0
	lwc1	$f20,48($17)
	cvt.s.w	$f0,$f0
	lw	$4,0($17)
	cvt.s.w	$f20,$f20
	nop
	nop
	div.s	$f20,$f0,$f20
	nop
	nop
	div.s	$f0,$f0,$f3
	mul.s	$f20,$f20,$f2
	mul.s	$f2,$f0,$f1
	cvt.w.s	$f0,$f2
	mfc1	$16,$f0
	jal	0x28e8b8
	move	$7,$16
	lw	$4,0($17)
	li	$5,2
	move	$6,$0
	jal	0x28e8b8
	move	$7,$16
	lwc1	$f0,48($17)
	li	$5,3
	move	$6,$0
	cvt.s.w	$f0,$f0
	mul.s	$f0,$f0,$f20
	cvt.w.s	$f1,$f0
	mfc1	$15,$f1
	beqz	$18,.L0028bf9c
	addu	$7,$16,$15
	mtc1	$7,$f1
	cvt.s.w	$f1,$f1
	sub.s	$f1,$f0,$f1
	mtc1	$0,$f0
	c.eq.s	$f1,$f0
	bc1tl	.L0028bf9c
	addiu	$7,$7,-1
.L0028bf9c:
	lw	$4,0($17)
	ld	$16,0($29)
	ld	$17,8($29)
	ld	$18,16($29)
	ld	$31,24($29)
	lwc1	$f20,32($29)
	j	0x28e8b8
	addiu	$29,$29,48
	.end func_0028be78
	.size func_0028be78, .-func_0028be78

