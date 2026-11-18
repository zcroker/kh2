# Whole-function assembly (last step of the README ladder, 2026-11-10, w3939).
# Both functions were near misses in C/C++ after many sessions (-g, _g files); see attempts.tsv
# and the best C drafts (tmp.w3939/best_0029ee68_g.cpp, best_002b01d8_g.cpp). Replace with C/C++ after 100%.
# All globals here have D_ symbols; func_002b31c0 is taken as an address via %hi/%lo. No plain-value addresses.
#   func_0029ee68: menu/seq setup with a list of up to 10 entries (s-reg rotation of cam/w and the
#     loop-hoisted %hi copies of D_0035f14c/D_0035f148/D_0035f210/D_0035f3d4; ~90 lines off with -g)
# Split out of batch_w3939.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0029ee68,"ax",@progbits
	.globl func_0029ee68
	.type func_0029ee68, @function
	.ent func_0029ee68
func_0029ee68:
	addiu	$29,$29,-128
	sd	$31,120($29)
	sd	$22,96($29)
	sd	$30,112($29)
	sd	$16,48($29)
	sd	$17,56($29)
	sd	$18,64($29)
	sd	$19,72($29)
	sd	$20,80($29)
	sd	$21,88($29)
	sd	$23,104($29)
	jal	_ZN2Tz6Jiminy9GetParentEv
	nop
	jal	_ZN2Tz6Jiminy9GetSeqTblEv
	move	$30,$2
	jal	func_0029fbf0
	move	$22,$2
	jal	func_0028f930
	move	$4,$0
	bnez	$2,.L0029eed0
	move	$17,$0
	move	$4,$0
	li	$5,-1
	jal	func_0028f4d8
	move	$6,$0
	move	$17,$0
.L0029eed0:
	addiu	$12,$29,16
	li	$13,2
	sll	$15,$17,0x3
.L0029eedc:
	li	$14,3
	addu	$15,$15,$12
.L0029eee4:
	sh	$13,0($15)
	addiu	$14,$14,-1
	nop
	nop
	nop
	bgez	$14,.L0029eee4
	addiu	$15,$15,2
	addiu	$17,$17,1
	slti	$15,$17,2
	bnez	$15,.L0029eedc
	sll	$15,$17,0x3
	lui	$16, %hi(D_0035f3d4)
	addiu	$14,$22,1224
	lw	$15, %lo(D_0035f3d4)($16)
	lui	$23, %hi(D_0035f14c)
	sw	$14,36($29)
	lui	$19, %hi(D_0035f148)
	addiu	$18,$15,-1
	jal	func_00276e78
	lui	$20, %hi(D_0035f210)
	li	$21,10
	lw	$6, %lo(D_0035f14c)($23)
	li	$9,90
	lw	$7, %lo(D_0035f148)($19)
	li	$10,-1
	lw	$8, %lo(D_0035f210)($20)
	move	$11,$0
	move	$5,$18
	jal	_ZN2Tz5Pause16CreateFadeObjectEz
	move	$4,$22
	move	$17,$0
	jal	_ZN2dk5Obj2D17getSeqPraramXYOffEv
	move	$4,$22
	move	$4,$22
	jal	_ZN2Tz10MenuCursor12AttachSpriteEz
	move	$5,$30
	lw	$6, %lo(D_0035f14c)($23)
	move	$5,$18
	lw	$7, %lo(D_0035f148)($19)
	li	$9,95
	lw	$8, %lo(D_0035f210)($20)
	li	$10,-1
	lw	$4,36($29)
	jal	_ZN2Tz5Pause16CreateFadeObjectEz
	move	$11,$0
	jal	_ZN2dk5Obj2D17getSeqPraramXYOffEv
	lw	$4,36($29)
	lw	$4,36($29)
	jal	_ZN2Tz10MenuCursor12AttachSpriteEz
	move	$5,$30
	jal	_ZN2YI8SEQUENCE10GetParamCrEv
	addiu	$4,$22,24
	lui	$15, %hi(D_0035f5d0)
	sw	$2,32($29)
	lw	$14, %lo(D_0035f5d0)($15)
	lb	$13,0($14)
	slti	$15,$13,10
	movn	$21,$13,$15
	blez	$21,.L0029f0c8
	lw	$18, %lo(D_0035f3d4)($16)
	lui	$15,0x6000
	addiu	$18,$18,1
	sw	$15,40($29)
	lui	$14,0x6000
	sw	$18,44($29)
	ori	$14,$14,0x8
	move	$30,$19
	sw	$14,40($29)
	move	$23,$20
	li	$15,0xa998
	addu	$18,$22,$15
	lui	$20, %hi(D_0035f200)
	move	$19,$0
.L0029f008:
	lui	$15, %hi(D_0035f14c)
	lw	$7, %lo(D_0035f148)($30)
	lw	$8, %lo(D_0035f210)($23)
	li	$9,-1
	lw	$6, %lo(D_0035f14c)($15)
	addiu	$10,$29,16
	lw	$4, %lo(D_0035f200)($20)
	addiu	$11,$29,24
	jal	func_00288d80
	move	$5,$17
	lw	$4, %lo(D_0035f200)($20)
	move	$5,$17
	jal	_ZN2Tz6Select10GetItemPtrEi
	addiu	$17,$17,1
	move	$16,$2
	jal	_ZN2dk5Obj2D17getSeqPraramXYOffEv
	move	$4,$2
	move	$4,$16
	jal	_ZN2Tz10MenuCursor12AttachSpriteEz
	move	$5,$22
	move	$6,$19
	move	$5,$0
	jal	_ZN2dk6Sprite12setOffsetPosEii
	move	$4,$16
	lw	$14,32($29)
	li	$15,3
	move	$4,$16
	sw	$15,428($16)
	addu	$19,$19,$14
	lw	$14,40($29)
	jal	_ZN2dk5Obj2D17resetSeqAlphaOnlyEv
	sw	$14,420($16)
	lui	$15, %hi(D_0035f14c)
	lw	$5,44($29)
	lw	$6, %lo(D_0035f14c)($15)
	move	$4,$18
	lw	$7, %lo(D_0035f148)($30)
	li	$9,2
	lw	$8, %lo(D_0035f210)($23)
	li	$10,-1
	jal	_ZN2Tz5Pause16CreateFadeObjectEz
	move	$11,$0
	move	$4,$18
	jal	_ZN2Tz10MenuCursor12AttachSpriteEz
	move	$5,$16
	slt	$15,$17,$21
	bnez	$15,.L0029f008
	addiu	$18,$18,408
.L0029f0c8:
	lui	$15, %hi(D_0035f5d0)
	lui	$16, %hi(D_0035f200)
	lw	$14, %lo(D_0035f5d0)($15)
	jal	_ZN2Tz8MenuBase7GetModeEv
	lb	$17,0($14)
	jal	_ZN2Tz6Jiminy9GetCurPosEi
	move	$4,$2
	lw	$4, %lo(D_0035f200)($16)
	move	$6,$0
	li	$7,-1
	li	$8,-1
	jal	func_002891f0
	move	$5,$2
	lw	$4, %lo(D_0035f200)($16)
	jal	func_0028af90
	move	$5,$17
	jal	_ZN2Tz8MenuBase7GetModeEv
	nop
	jal	_ZN2Tz6Jiminy12GetCurTopPosEi
	move	$4,$2
	lw	$4, %lo(D_0035f200)($16)
	jal	func_0028afd0
	move	$5,$2
	slti	$15,$17,2
	bnezl	$15,.L0029f14c
	lui	$16, %hi(D_0035f200)
	lw	$4, %lo(D_0035f200)($16)
	jal	func_0028b218
	li	$5,1
	lw	$4, %lo(D_0035f200)($16)
	jal	func_0028b248
	li	$5,10
	lui	$16, %hi(D_0035f210)
.L0029f14c:
	lui	$15, %hi(D_0035f3d4)
	slti	$14,$17,11
	lw	$18, %lo(D_0035f3d4)($15)
	lw	$4, %lo(D_0035f210)($16)
	li	$21,10
	jal	_ZN2Tz6Layout9getLayoutEv
	movz	$21,$17,$14
	lui	$15, %hi(D_0035f14c)
	move	$4,$2
	jal	_ZN2YI6LAYOUT15GetSequenceUnitEi
	lw	$5, %lo(D_0035f14c)($15)
	lw	$4, %lo(D_0035f210)($16)
	jal	_ZN2Tz6Layout9getLayoutEv
	move	$17,$2
	lui	$15, %hi(D_0035f148)
	lw	$4,40($2)
	jal	_ZN2YI12IMAGE_FREEZE8GetImageEi
	lw	$5, %lo(D_0035f148)($15)
	jal	_ZN2Tz6Jiminy15GetScrBarSeqTblEv
	move	$16,$2
	sw	$0,0($29)
	lui	$15, %hi(D_0035f214)
	lw	$11,36($29)
	move	$5,$18
	lw	$4, %lo(D_0035f214)($15)
	move	$6,$17
	move	$7,$16
	move	$9,$21
	move	$8,$2
	jal	func_0028bae0
	li	$10,10
	jal	func_0029fcb0
	nop
	jal	func_002a03d0
	nop
	jal	func_002a03a0
	nop
	jal	_ZN2Tz6Jiminy18SetHideLightCursorEb
	li	$4,1
	jal	_ZN2Tz8Selector8SetStateEi
	move	$4,$0
	ld	$16,48($29)
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
	.end func_0029ee68
	.size func_0029ee68, 952
