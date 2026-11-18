# Whole-function assembly (last step of the README ladder, 2026-11-10, w3939).
# Both functions were near misses in C/C++ after many sessions (-g, _g files); see attempts.tsv
# and the best C drafts (tmp.w3939/best_0029ee68_g.cpp, best_002b01d8_g.cpp). Replace with C/C++ after 100%.
#   func_002b01d8: sibling setup (constant 3 hoisted to s3, %hi(D_0035f638)/%hi(D_0035f200) not kept in s4/s3; ~118 lines off with -g)
# All globals here have D_ symbols; func_002b31c0 is taken as an address via %hi/%lo. No plain-value addresses.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002b01d8,"ax",@progbits
	.globl func_002b01d8
	.type func_002b01d8, @function
	.ent func_002b01d8
func_002b01d8:
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
	move	$22,$2
	jal	_ZN2Tz8MenuBase7GetModeEv
	move	$30,$2
	li	$15,31
	beq	$2,$15,.L002b0250
	sw	$2,36($29)
	jal	func_0028f930
	li	$4,1
	bnez	$2,.L002b0254
	move	$13,$0
	jal	func_002b3b60
	move	$4,$0
	move	$5,$2
	li	$4,1
	jal	func_0028f4d8
	move	$6,$0
.L002b0250:
	move	$13,$0
.L002b0254:
	addiu	$11,$29,16
	li	$12,2
	sll	$15,$13,0x3
.L002b0260:
	li	$14,3
	addu	$15,$15,$11
.L002b0268:
	sh	$12,0($15)
	addiu	$14,$14,-1
	nop
	nop
	nop
	bgez	$14,.L002b0268
	addiu	$15,$15,2
	addiu	$13,$13,1
	slti	$15,$13,2
	bnez	$15,.L002b0260
	sll	$15,$13,0x3
	lui	$14, %hi(D_0035f3d4)
	lui	$18, %hi(D_0035f210)
	lw	$23, %lo(D_0035f3d4)($14)
	addiu	$21,$30,1224
	lui	$17,0x6000
	jal	func_00276e78
	lui	$20, %hi(D_0035f638)
	addiu	$19,$23,-1
	lui	$15, %hi(D_0035f14c)
	lw	$8, %lo(D_0035f210)($18)
	lui	$14, %hi(D_0035f148)
	lw	$6, %lo(D_0035f14c)($15)
	lw	$7, %lo(D_0035f148)($14)
	li	$9,97
	li	$10,-1
	move	$11,$0
	move	$5,$19
	jal	_ZN2Tz5Pause16CreateFadeObjectEz
	move	$4,$30
	ori	$17,$17,0x8
	jal	_ZN2dk5Obj2D17getSeqPraramXYOffEv
	move	$4,$30
	move	$4,$30
	jal	_ZN2Tz10MenuCursor12AttachSpriteEz
	move	$5,$22
	lui	$15, %hi(D_0035f14c)
	lw	$8, %lo(D_0035f210)($18)
	lui	$14, %hi(D_0035f148)
	lw	$6, %lo(D_0035f14c)($15)
	lw	$7, %lo(D_0035f148)($14)
	move	$5,$19
	li	$9,100
	li	$10,-1
	move	$11,$0
	jal	_ZN2Tz5Pause16CreateFadeObjectEz
	move	$4,$21
	lui	$19, %hi(D_0035f200)
	jal	_ZN2dk5Obj2D17getSeqPraramXYOffEv
	move	$4,$21
	move	$4,$21
	jal	_ZN2Tz10MenuCursor12AttachSpriteEz
	move	$5,$22
	lui	$15, %hi(D_0035f14c)
	lw	$8, %lo(D_0035f210)($18)
	lw	$6, %lo(D_0035f14c)($15)
	lui	$14, %hi(D_0035f148)
	lw	$7, %lo(D_0035f148)($14)
	addiu	$11,$29,24
	li	$15,1
	lw	$4, %lo(D_0035f200)($19)
	sw	$15,32($29)
	li	$9,-1
	addiu	$10,$29,16
	jal	func_00288d80
	move	$5,$0
	lw	$4, %lo(D_0035f200)($19)
	jal	_ZN2Tz6Select10GetItemPtrEi
	move	$5,$0
	move	$16,$2
	jal	_ZN2dk5Obj2D17getSeqPraramXYOffEv
	move	$4,$2
	move	$4,$16
	jal	_ZN2Tz10MenuCursor12AttachSpriteEz
	move	$5,$30
	li	$14,3
	sw	$17,420($16)
	sw	$14,428($16)
	jal	_ZN2dk5Obj2D17resetSeqAlphaOnlyEv
	move	$4,$16
	lui	$15, %hi(func_002b31c0)
	lui	$14, %hi(D_0035f148)
	addiu	$15, $15, %lo(func_002b31c0)
	li	$9,98
	sw	$15,436($16)
	li	$10,-1
	li	$11,-1
	move	$5,$23
	lui	$15, %hi(D_0035f634)
	lw	$7, %lo(D_0035f148)($14)
	lw	$16, %lo(D_0035f634)($15)
	lw	$8, %lo(D_0035f210)($18)
	lui	$15, %hi(D_0035f14c)
	sw	$0,0($29)
	lw	$6, %lo(D_0035f14c)($15)
	addiu	$16,$16,22032
	jal	_ZN2Tz10MenuCursor6CreateEz
	move	$4,$16
	jal	_Z16u_tail4_00192048jjjj
	li	$4,20421
	sw	$2,408($16)
	jal	_ZN2dk5Obj2D17getSeqPraramXYOffEv
	move	$4,$16
	move	$5,$22
	jal	_ZN2Tz10MenuCursor12AttachSpriteEz
	move	$4,$16
	li	$15,3
	sw	$17,420($16)
	sw	$15,428($16)
	jal	_ZN2dk5Obj2D17resetSeqAlphaOnlyEv
	move	$4,$16
	li	$15,2
	addiu	$4,$30,24
	sw	$15,432($16)
	jal	_ZN2YI8SEQUENCE10GetParamCrEv
	lw	$16, %lo(D_0035f638)($20)
	sh	$2,40($16)
	li	$4,20298
	jal	_Z16u_tail4_00192048jjjj
	lw	$16, %lo(D_0035f638)($20)
	jal	func_00192b80
	move	$4,$2
	sh	$2,42($16)
	lw	$14, %lo(D_0035f638)($20)
	lw	$4, %lo(D_0035f200)($19)
	lh	$15,42($14)
	lw	$14,32($29)
	addiu	$13,$15,-8
	slti	$15,$15,10
	movz	$14,$13,$15
	sw	$14,32($29)
	jal	func_0028af90
	lw	$5,32($29)
	lw	$4, %lo(D_0035f200)($19)
	move	$6,$0
	li	$7,-1
	li	$8,-1
	jal	func_002891f0
	move	$5,$0
	lw	$4, %lo(D_0035f200)($19)
	jal	func_0028afd0
	move	$5,$0
	lui	$15, %hi(D_0035f3d4)
	lw	$4, %lo(D_0035f210)($18)
	jal	_ZN2Tz6Layout9getLayoutEv
	lw	$19, %lo(D_0035f3d4)($15)
	lui	$14, %hi(D_0035f14c)
	move	$4,$2
	jal	_ZN2YI6LAYOUT15GetSequenceUnitEi
	lw	$5, %lo(D_0035f14c)($14)
	lw	$4, %lo(D_0035f210)($18)
	jal	_ZN2Tz6Layout9getLayoutEv
	move	$17,$2
	lui	$15, %hi(D_0035f148)
	lw	$4,40($2)
	jal	_ZN2YI12IMAGE_FREEZE8GetImageEi
	lw	$5, %lo(D_0035f148)($15)
	jal	_ZN2Tz6Jiminy15GetScrBarSeqTblEv
	move	$16,$2
	lw	$15, %lo(D_0035f638)($20)
	lui	$14, %hi(D_0035f214)
	lw	$4, %lo(D_0035f214)($14)
	move	$8,$2
	lh	$9,42($15)
	move	$6,$17
	move	$7,$16
	move	$11,$21
	sw	$0,0($29)
	li	$10,9
	jal	func_0028bae0
	move	$5,$19
	lui	$15, %hi(D_0035f214)
	move	$5,$0
	jal	func_0028be78
	lw	$4, %lo(D_0035f214)($15)
	jal	_ZN2Tz9JmNewInfo7GetSramEv
	nop
	lw	$14,36($29)
	li	$15,31
	beq	$14,$15,.L002b054c
	lui	$15, %hi(D_0035f200)
	lhu	$15,486($2)
	andi	$15,$15,0x1
	beqz	$15,.L002b0568
	lui	$15, %hi(D_0035f200)
.L002b054c:
	jal	_ZN2Tz6Select15GetEnableButtonEv
	lw	$4, %lo(D_0035f200)($15)
	lui	$14, %hi(D_0035f200)
	li	$15,-17
	lw	$4, %lo(D_0035f200)($14)
	jal	_ZN2Tz6Select15SetEnableButtonEj
	and	$5,$2,$15
.L002b0568:
	lw	$14,32($29)
	slti	$15,$14,2
	bnez	$15,.L002b0598
	lui	$15, %hi(D_0035f200)
	lui	$16, %hi(D_0035f200)
	li	$5,1
	jal	func_0028b218
	lw	$4, %lo(D_0035f200)($16)
	lw	$4, %lo(D_0035f200)($16)
	jal	func_0028b248
	li	$5,9
	lui	$15, %hi(D_0035f200)
.L002b0598:
	move	$5,$0
	jal	_ZN2Tz6Select15SetSelectorLoopEb
	lw	$4, %lo(D_0035f200)($15)
	jal	func_002b1a00
	nop
	jal	_ZN2Tz6Jiminy13SetHideCursorEb
	li	$4,1
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
	.end func_002b01d8
	.size func_002b01d8, 1052

