# Whole-function assembly (last step of the README ladder, 2026-11-10, w3931).
# Both functions were near misses in C/C++ after several sessions; see attempts.tsv
# and the best C drafts (tmp.w3931/best_00271b78_mam.cpp, best_001cc5c8_nsa.cpp). Replace with C/C++ after 100%.
# Globals and literal-pool words that no C source names yet are written as plain lui/%lo values
# (gas drops the carry in %hi(0x...)); calls and named globals use symbols.
#   func_001cc5c8: YS::PRIZE_CA prize transfer (loop.c hoists 2^-32 twice, 100, 40 but not -50/-4/-20; ~120 lines off under _nsa)
# Split out of batch_w3931.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_001cc5c8,"ax",@progbits
	.globl func_001cc5c8
	.type func_001cc5c8, @function
	.ent func_001cc5c8
func_001cc5c8:
	addiu	$29,$29,-144
	lui	$13,0x1d5
	sd	$16,32($29)
	sd	$17,40($29)
	sd	$23,88($29)
	move	$16,$4
	sd	$18,48($29)
	move	$17,$5
	sd	$19,56($29)
	sd	$20,64($29)
	sd	$21,72($29)
	sd	$22,80($29)
	sd	$30,96($29)
	sd	$31,104($29)
	swc1	$f25,132($29)
	swc1	$f24,128($29)
	swc1	$f23,124($29)
	swc1	$f22,120($29)
	swc1	$f21,116($29)
	swc1	$f20,112($29)
	lb	$15,-26224($13)
	bnez	$15,.L001cc860
	move	$23,$6
	li	$15,1
	lui	$18,0x1d5
	sb	$15,-26224($13)
	addiu	$14,$18,-26208
	lui	$4,0x1d
	sw	$0,-26208($18)
	lui	$15,0x37
	addiu	$4,$4,-12816
	addiu	$15,$15,-7720
	lwc1	$f0,0($15)
	lui	$15,0x37
	swc1	$f0,12($14)
	addiu	$15,$15,-7716
	lwc1	$f1,0($15)
	lui	$15,0x37
	swc1	$f1,4($14)
	addiu	$15,$15,-7712
	lwc1	$f0,0($15)
	jal	func_002fd188
	swc1	$f0,8($14)
.L001cc674:
	addiu	$14,$18,-26208
	addiu	$15,$16,64
	lqc2	$vf5,0($14)
	lqc2	$vf1,0($15)
	lqc2	$vf2,16($15)
	lqc2	$vf3,32($15)
	lqc2	$vf4,48($15)
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	sqc2	$vf5,0($29)
	move	$5,$17
	addiu	$4,$29,16
	jal	_Z16ctarget_0016bda8jjjj
	move	$18,$0
	blez	$23,.L001cc7ec
	lui	$15,0x37
	lwc1	$f23,16($29)
	addiu	$15,$15,-7708
	lwc1	$f20,24($29)
	lwc1	$f22,0($15)
	lui	$21,0x1
	lui	$19,%hi(D_003638d0)
	ori	$21,$21,0xdcd
	lui	$15,0x37
	mov.s	$f25,$f22
	addiu	$15,$15,-7704
	lui	$30,%hi(D_00352050)
	lwc1	$f24,0($15)
	move	$22,$19
	move	$20,$21
	lui	$15,0x37
	addiu	$15,$15,-7700
	lwc1	$f21,0($15)
.L001cc700:
	lw	$15,2760($16)
	beqz	$15,.L001cc858
	lw	$4,%lo(D_00352050)($30)
	jal	_ZN2YS5PRIZE6appearEPKNS_11PRIZEEFFECT5PARAMERKN2kn7FVectorE
	move	$5,$29
	beqz	$2,.L001cc858
	addiu	$12,$2,48
	lui	$15,0x1d
	sw	$17,72($2)
	addiu	$15,$15,-14232
	sw	$15,16($2)
	lw	$15,%lo(D_003638d0)($19)
	mult	$15,$15,$21
	srl	$14,$15,0x1
	sw	$15,%lo(D_003638d0)($19)
	andi	$13,$15,0x1
	bltz	$15,.L001cc848
	or	$13,$13,$14
	mtc1	$15,$f0
	cvt.s.w	$f0,$f0
.L001cc750:
	lw	$15,%lo(D_003638d0)($22)
	mul.s	$f0,$f0,$f22
	mult	$14,$15,$20
	mul.s	$f0,$f0,$f24
	lui	$15,0x37
	sw	$14,%lo(D_003638d0)($22)
	addiu	$15,$15,-7696
	andi	$13,$14,0x1
	lwc1	$f1,0($15)
	add.s	$f1,$f1,$f0
	srl	$15,$14,0x1
	or	$13,$13,$15
	bltz	$14,.L001cc838
	add.s	$f0,$f23,$f1
	mtc1	$14,$f1
	cvt.s.w	$f1,$f1
.L001cc790:
	swc1	$f0,0($12)
	lui	$15,0x37
	mul.s	$f1,$f1,$f25
	addiu	$15,$15,-7692
	lwc1	$f0,0($15)
	addiu	$18,$18,1
	sw	$0,12($12)
	slt	$13,$18,$23
	swc1	$f0,4($12)
	lui	$15,0x37
	mul.s	$f1,$f1,$f21
	addiu	$15,$15,-7688
	lwc1	$f0,0($15)
	add.s	$f0,$f0,$f1
	add.s	$f0,$f20,$f0
	swc1	$f0,8($12)
	lw	$15,2760($16)
	addiu	$15,$15,-1
	sw	$15,2760($16)
	lw	$14,2760($17)
	addiu	$14,$14,1
	bnez	$13,.L001cc700
	sw	$14,2760($17)
.L001cc7ec:
	move	$2,$0
.L001cc7f0:
	ld	$16,32($29)
	ld	$17,40($29)
	ld	$18,48($29)
	ld	$19,56($29)
	ld	$20,64($29)
	ld	$21,72($29)
	ld	$22,80($29)
	ld	$23,88($29)
	ld	$30,96($29)
	ld	$31,104($29)
	lwc1	$f25,132($29)
	lwc1	$f24,128($29)
	lwc1	$f23,124($29)
	lwc1	$f22,120($29)
	lwc1	$f21,116($29)
	lwc1	$f20,112($29)
	jr	$31
	addiu	$29,$29,144
.L001cc838:
	mtc1	$13,$f1
	cvt.s.w	$f1,$f1
	b	.L001cc790
	add.s	$f1,$f1,$f1
.L001cc848:
	mtc1	$13,$f0
	cvt.s.w	$f0,$f0
	b	.L001cc750
	add.s	$f0,$f0,$f0
.L001cc858:
	b	.L001cc7f0
	li	$2,1
.L001cc860:
	b	.L001cc674
	lui	$18,0x1d5
	.end func_001cc5c8
	.size func_001cc5c8, 672
