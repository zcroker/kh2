# Whole-function assembly (last step of the README ladder, 2026-11-10, w3931).
# Both functions were near misses in C/C++ after several sessions; see attempts.tsv
# and the best C drafts (tmp.w3931/best_00271b78_mam.cpp, best_001cc5c8_nsa.cpp). Replace with C/C++ after 100%.
#   func_00271b78: menu sprite list setup (register rotation i s5/s6 and giv split for spr[k+24]; ~100 lines off under _mam)
# Globals and literal-pool words that no C source names yet are written as plain lui/%lo values
# (gas drops the carry in %hi(0x...)); calls and named globals use symbols.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00271b78,"ax",@progbits
	.globl func_00271b78
	.type func_00271b78, @function
	.ent func_00271b78
func_00271b78:
	addiu	$29,$29,-144
	sd	$31,136($29)
	sd	$16,64($29)
	sd	$17,72($29)
	sd	$18,80($29)
	sd	$21,104($29)
	sd	$19,88($29)
	lui	$18,%hi(D_0035ef6c)
	sd	$20,96($29)
	sd	$22,112($29)
	sd	$23,120($29)
	sd	$30,128($29)
	jal	_ZN2Tz5CmTop13GetListBufferEv
	li	$21,17
	sw	$2,56($29)
	jal	_Z16u_call4_00139d78jjjj
	lw	$4,56($29)
	lui	$15,%hi(D_0035f01c)
	lw	$17,56($29)
	jal	_ZN2Tz6Select10GetCurrentEv
	lw	$4,%lo(D_0035f01c)($15)
	sw	$2,36($29)
	jal	func_00271b58
	lw	$4,36($29)
	lw	$4,36($29)
	lui	$5,0x1e2
	addiu	$6,$29,32
	jal	func_002713a0
	addiu	$5,$5,7892
	jal	_ZN2Tz5CmTop18GetFontColorSeqNumEi
	move	$4,$0
	move	$16,$2
.L00271bf8:
	lw	$5,%lo(D_0035ef6c)($18)
	addiu	$4,$17,13840
	jal	_ZN2dk6Sprite6setNumEi
	addiu	$21,$21,-1
	addiu	$4,$17,24304
	jal	_ZN2dk6Sprite6setNumEi
	move	$5,$16
	sw	$0,24712($17)
	sw	$0,3784($17)
	bgez	$21,.L00271bf8
	addiu	$17,$17,436
	lw	$13,32($29)
	blez	$13,.L00271c60
	move	$21,$0
	lui	$17,0x1e2
	move	$16,$29
.L00271c38:
	lw	$15,7892($17)
	addu	$15,$15,$21
	lb	$4,0($15)
	jal	func_00272c20
	addiu	$21,$21,1
	sw	$2,0($16)
	lw	$13,32($29)
	slt	$15,$21,$13
	bnez	$15,.L00271c38
	addiu	$16,$16,4
.L00271c60:
	sw	$0,52($29)
	move	$21,$0
	blez	$13,.L00271dd4
	sw	$0,48($29)
	lw	$30,56($29)
	sw	$29,60($29)
	move	$23,$30
.L00271c7c:
	lw	$15,60($29)
	lui	$12,0x1e2
	lw	$14,7892($12)
	lw	$15,0($15)
	addu	$14,$14,$21
	lui	$12,0x37
	sw	$15,40($29)
	addiu	$12,$12,14736
	lb	$15,0($14)
	sll	$15,$15,0x1
	lw	$14,40($29)
	addu	$15,$15,$12
	lh	$15,0($15)
	blez	$14,.L00271da4
	sw	$15,44($29)
	lw	$15,48($29)
	li	$13,436
	lw	$12,56($29)
	li	$14,0xae10
	mult	$13,$15,$13
	lw	$18,40($29)
	addu	$20,$23,$14
	li	$15,0xb110
	addu	$17,$13,$12
	addu	$22,$30,$15
	addiu	$19,$17,13840
.L00271ce4:
	lw	$5,44($29)
	jal	_ZN2dk6Sprite6setNumEi
	move	$4,$19
	lui	$12,0x1e2
	lw	$14,52($29)
	lw	$15,7892($12)
	li	$5,1
	sll	$13,$14,0x3
	move	$4,$0
	addu	$15,$15,$21
	lb	$14,0($15)
	li	$15,3
	beq	$14,$15,.L00271d38
	xori	$6,$14,0x1
	lui	$12,%hi(D_0035f12c)
	sltiu	$6,$6,1
	lw	$15,%lo(D_0035f12c)($12)
	addu	$15,$13,$15
	jal	func_00257158
	lh	$4,8($15)
	move	$4,$2
.L00271d38:
	jal	_ZN2Tz5CmTop18GetFontColorSeqNumEi
	nop
	addiu	$4,$17,24304
	jal	_ZN2dk6Sprite6setNumEi
	move	$5,$2
	sw	$20,24712($17)
	lw	$14,36($29)
	beqz	$14,.L00271d78
	addiu	$20,$20,32
	lui	$12,0x1e2
	lw	$15,7892($12)
	addu	$15,$15,$21
	lb	$14,0($15)
	li	$15,3
	bnel	$14,$15,.L00271d78
	sw	$22,3784($17)
.L00271d78:
	lw	$12,52($29)
	addiu	$22,$22,4
	addiu	$23,$23,32
	addiu	$30,$30,4
	addiu	$12,$12,1
	addiu	$17,$17,436
	sw	$12,52($29)
	addiu	$18,$18,-1
	bnez	$18,.L00271ce4
	addiu	$19,$19,436
	lw	$13,32($29)
.L00271da4:
	lw	$14,40($29)
	addiu	$21,$21,1
	lw	$12,48($29)
	andi	$15,$14,0x1
	addu	$12,$12,$14
	lw	$14,60($29)
	addu	$12,$12,$15
	sw	$12,48($29)
	slt	$15,$21,$13
	addiu	$14,$14,4
	bnez	$15,.L00271c7c
	sw	$14,60($29)
.L00271dd4:
	ld	$16,64($29)
	ld	$17,72($29)
	ld	$18,80($29)
	ld	$19,88($29)
	ld	$20,96($29)
	ld	$21,104($29)
	ld	$22,112($29)
	ld	$23,120($29)
	ld	$30,128($29)
	ld	$31,136($29)
	jr	$31
	addiu	$29,$29,144
	.end func_00271b78
	.size func_00271b78, 652

