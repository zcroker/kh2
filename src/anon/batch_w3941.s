# Whole-function assembly (last step of the README match ladder, w3941 2026-11-10).
# Transcribed from the retail disassembly; calls and globals go through func_/D_ symbols. Replace with C/C++ after 100%.
# func_0029af20: menu setup: builds the two header windows (D_0035f3d4-1), ten list rows (func_00288d80/
#   func_002891b8, attr 0x60000008, step from func_0023aa78), counts the set bits of *D_0035f5ac (19 entries),
#   picks the cursor/top row (D_0035f5b4 reset path or func_00287bc0 state), then configures the list and
#   scroll bar (func_0028af90 ... func_0028be78).
#   Closest C: ~/re/kh2/tmp.w3941/best_0029af20.cpp (= coord best/0029af20_w3818_g.cpp, _g, about 223 lines off):
#   the original keeps the pre-loop %hi parts in s1-s4 and 0x60000008 in s0, but rematerialises every %hi
#   inside the row loop (fresh lui t6/t7); our loop.c/gcse share or hoist them into saved registers and attr spills.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0029af20,"ax",@progbits
	.globl func_0029af20
	.type func_0029af20, @function
	.ent func_0029af20
func_0029af20:
	addiu	$29,$29,-128	# 29af20
	sd	$22,96($29)	# 29af24
	sd	$30,112($29)	# 29af28
	sd	$31,120($29)	# 29af2c
	sd	$16,48($29)	# 29af30
	sd	$17,56($29)	# 29af34
	sd	$18,64($29)	# 29af38
	sd	$19,72($29)	# 29af3c
	sd	$20,80($29)	# 29af40
	sd	$21,88($29)	# 29af44
	sd	$23,104($29)	# 29af48
	jal	func_00276348	# 29af4c
	nop	# 29af50
	jal	func_002766d0	# 29af54
	move	$30,$2	# 29af58
	move	$22,$2	# 29af5c
	jal	func_0028f930	# 29af60
	move	$4,$0	# 29af64
	bnez	$2, .L0029af84	# 29af68
	move	$21,$0	# 29af6c
	move	$4,$0	# 29af70
	li	$5,-1	# 29af74
	jal	func_0028f4d8	# 29af78
	move	$6,$0	# 29af7c
	move	$21,$0	# 29af80
.L0029af84:
	addiu	$12,$29,16	# 29af84
	li	$13,2	# 29af88
	sll	$15,$21,0x3	# 29af8c
.L0029af90:
	li	$14,3	# 29af90
	addu	$15,$15,$12	# 29af94
.L0029af98:
	sh	$13,0($15)	# 29af98
	addiu	$14,$14,-1	# 29af9c
	nop	# 29afa0
	nop	# 29afa4
	nop	# 29afa8
	bgez	$14, .L0029af98	# 29afac
	addiu	$15,$15,2	# 29afb0
	addiu	$21,$21,1	# 29afb4
	slti	$15,$21,2	# 29afb8
	bnez	$15, .L0029af90	# 29afbc
	sll	$15,$21,0x3	# 29afc0
	lui	$20,%hi(D_0035f3d4)	# 29afc4
	addiu	$14,$22,1224	# 29afc8
	lw	$15, %lo(D_0035f3d4)($20)	# 29afcc
	lui	$17,%hi(D_0035f14c)	# 29afd0
	sw	$14,32($29)	# 29afd4
	lui	$18,%hi(D_0035f148)	# 29afd8
	addiu	$23,$15,-1	# 29afdc
	jal	func_00276e78	# 29afe0
	lui	$19,%hi(D_0035f210)	# 29afe4
	lui	$16,0x6000	# 29afe8
	lw	$6, %lo(D_0035f14c)($17)	# 29afec
	li	$9,90	# 29aff0
	lw	$7, %lo(D_0035f148)($18)	# 29aff4
	li	$10,-1	# 29aff8
	lw	$8, %lo(D_0035f210)($19)	# 29affc
	move	$11,$0	# 29b000
	move	$5,$23	# 29b004
	jal	func_0028d8c0	# 29b008
	move	$4,$22	# 29b00c
	ori	$16,$16,0x8	# 29b010
	move	$4,$22	# 29b014
	jal	func_00139620	# 29b018
	move	$21,$0	# 29b01c
	move	$5,$30	# 29b020
	jal	func_0028dcc0	# 29b024
	move	$4,$22	# 29b028
	lw	$6, %lo(D_0035f14c)($17)	# 29b02c
	move	$5,$23	# 29b030
	lw	$7, %lo(D_0035f148)($18)	# 29b034
	li	$9,95	# 29b038
	lw	$8, %lo(D_0035f210)($19)	# 29b03c
	li	$10,-1	# 29b040
	lw	$4,32($29)	# 29b044
	move	$11,$0	# 29b048
	jal	func_0028d8c0	# 29b04c
	move	$18,$0	# 29b050
	jal	func_00139620	# 29b054
	lw	$4,32($29)	# 29b058
	lw	$4,32($29)	# 29b05c
	jal	func_0028dcc0	# 29b060
	move	$5,$30	# 29b064
	jal	func_0023aa78	# 29b068
	addiu	$4,$22,24	# 29b06c
	lw	$23, %lo(D_0035f3d4)($20)	# 29b070
	li	$15,0xa998	# 29b074
	move	$30,$2	# 29b078
	addu	$17,$22,$15	# 29b07c
	move	$20,$16	# 29b080
	addiu	$19,$23,1	# 29b084
.L0029b088:
	lui	$15,%hi(D_0035f148)	# 29b088
	lui	$14,%hi(D_0035f210)	# 29b08c
	lw	$7, %lo(D_0035f148)($15)	# 29b090
	li	$9,-1	# 29b094
	lw	$8, %lo(D_0035f210)($14)	# 29b098
	addiu	$10,$29,16	# 29b09c
	lui	$15,%hi(D_0035f14c)	# 29b0a0
	addiu	$11,$29,24	# 29b0a4
	lui	$14,%hi(D_0035f200)	# 29b0a8
	lw	$6, %lo(D_0035f14c)($15)	# 29b0ac
	lw	$4, %lo(D_0035f200)($14)	# 29b0b0
	jal	func_00288d80	# 29b0b4
	move	$5,$21	# 29b0b8
	lui	$15,%hi(D_0035f200)	# 29b0bc
	move	$5,$21	# 29b0c0
	lw	$4, %lo(D_0035f200)($15)	# 29b0c4
	jal	func_002891b8	# 29b0c8
	addiu	$21,$21,1	# 29b0cc
	move	$16,$2	# 29b0d0
	jal	func_00139620	# 29b0d4
	move	$4,$2	# 29b0d8
	move	$4,$16	# 29b0dc
	jal	func_0028dcc0	# 29b0e0
	move	$5,$22	# 29b0e4
	move	$6,$18	# 29b0e8
	move	$5,$0	# 29b0ec
	move	$4,$16	# 29b0f0
	jal	func_00138c68	# 29b0f4
	addu	$18,$18,$30	# 29b0f8
	li	$14,3	# 29b0fc
	sw	$20,420($16)	# 29b100
	sw	$14,428($16)	# 29b104
	jal	func_001395f8	# 29b108
	move	$4,$16	# 29b10c
	lui	$15,%hi(D_0035f14c)	# 29b110
	lui	$14,%hi(D_0035f148)	# 29b114
	lw	$6, %lo(D_0035f14c)($15)	# 29b118
	move	$4,$17	# 29b11c
	lw	$7, %lo(D_0035f148)($14)	# 29b120
	move	$5,$19	# 29b124
	lui	$15,%hi(D_0035f210)	# 29b128
	li	$9,2	# 29b12c
	lw	$8, %lo(D_0035f210)($15)	# 29b130
	li	$10,-1	# 29b134
	jal	func_0028d8c0	# 29b138
	move	$11,$0	# 29b13c
	move	$4,$17	# 29b140
	jal	func_0028dcc0	# 29b144
	move	$5,$16	# 29b148
	slti	$15,$21,10	# 29b14c
	bnez	$15, .L0029b088	# 29b150
	addiu	$17,$17,408	# 29b154
	jal	func_0029c958	# 29b158
	move	$17,$0	# 29b15c
	move	$18,$0	# 29b160
	move	$21,$0	# 29b164
	lui	$16,%hi(D_0035f5ac)	# 29b168
	li	$19,15	# 29b16c
	lw	$14, %lo(D_0035f5ac)($16)	# 29b170
.L0029b174:
	lw	$15,0($14)	# 29b174
	srav	$15,$15,$21	# 29b178
	andi	$15,$15,0x1	# 29b17c
	andi	$15,$15,0xff	# 29b180
	beqzl	$15, .L0029b1dc	# 29b184
	addiu	$21,$21,1	# 29b188
	jal	func_00276568	# 29b18c
	nop	# 29b190
	lb	$15,0($2)	# 29b194
	bltzl	$15, .L0029b1d8	# 29b198
	addiu	$17,$17,1	# 29b19c
	jal	func_00276568	# 29b1a0
	nop	# 29b1a4
	lb	$15,0($2)	# 29b1a8
	beql	$15, $19, .L0029b1d8	# 29b1ac
	addiu	$17,$17,1	# 29b1b0
	beqzl	$21, .L0029b1d8	# 29b1b4
	addiu	$17,$17,1	# 29b1b8
	jal	func_00276568	# 29b1bc
	nop	# 29b1c0
	lb	$14,0($2)	# 29b1c4
	addiu	$15,$21,-1	# 29b1c8
	xor	$15,$15,$14	# 29b1cc
	movz	$18,$17,$15	# 29b1d0
	addiu	$17,$17,1	# 29b1d4
.L0029b1d8:
	addiu	$21,$21,1	# 29b1d8
.L0029b1dc:
	slti	$15,$21,19	# 29b1dc
	bnez	$15, .L0029b174	# 29b1e0
	lw	$14, %lo(D_0035f5ac)($16)	# 29b1e4
	lui	$15,%hi(D_0035f5b4)	# 29b1e8
	lbu	$14, %lo(D_0035f5b4)($15)	# 29b1ec
	beqz	$14, .L0029b34c	# 29b1f0
	addiu	$2,$17,-10	# 29b1f4
	slt	$15,$18,$2	# 29b1f8
	beqz	$15, .L0029b33c	# 29b1fc
	move	$20,$2	# 29b200
	move	$20,$18	# 29b204
	move	$21,$0	# 29b208
.L0029b20c:
	lui	$15,%hi(D_0035f5b4)	# 29b20c
	sb	$0, %lo(D_0035f5b4)($15)	# 29b210
.L0029b214:
	lui	$16,%hi(D_0035f200)	# 29b214
	move	$5,$17	# 29b218
	lw	$4, %lo(D_0035f200)($16)	# 29b21c
	lui	$18,%hi(D_0035f210)	# 29b220
	jal	func_0028af90	# 29b224
	lui	$19,%hi(D_0035f214)	# 29b228
	lw	$4, %lo(D_0035f200)($16)	# 29b22c
	move	$6,$0	# 29b230
	li	$7,-1	# 29b234
	li	$8,-1	# 29b238
	jal	func_002891f0	# 29b23c
	move	$5,$21	# 29b240
	li	$21,10	# 29b244
	lw	$4, %lo(D_0035f200)($16)	# 29b248
	jal	func_0028afd0	# 29b24c
	move	$5,$20	# 29b250
	lw	$4, %lo(D_0035f200)($16)	# 29b254
	jal	func_0028b218	# 29b258
	li	$5,1	# 29b25c
	lw	$4, %lo(D_0035f200)($16)	# 29b260
	jal	func_0028b248	# 29b264
	li	$5,10	# 29b268
	lui	$15,%hi(D_0035f3d4)	# 29b26c
	lw	$4, %lo(D_0035f210)($18)	# 29b270
	slti	$14,$17,11	# 29b274
	lw	$23, %lo(D_0035f3d4)($15)	# 29b278
	jal	func_0023f1b0	# 29b27c
	movz	$21,$17,$14	# 29b280
	lui	$15,%hi(D_0035f14c)	# 29b284
	move	$4,$2	# 29b288
	jal	func_0023c4b8	# 29b28c
	lw	$5, %lo(D_0035f14c)($15)	# 29b290
	lw	$4, %lo(D_0035f210)($18)	# 29b294
	jal	func_0023f1b0	# 29b298
	move	$17,$2	# 29b29c
	lui	$15,%hi(D_0035f148)	# 29b2a0
	lw	$4,40($2)	# 29b2a4
	jal	func_00236ca8	# 29b2a8
	lw	$5, %lo(D_0035f148)($15)	# 29b2ac
	jal	func_00276678	# 29b2b0
	move	$16,$2	# 29b2b4
	sw	$0,0($29)	# 29b2b8
	move	$6,$17	# 29b2bc
	lw	$11,32($29)	# 29b2c0
	move	$7,$16	# 29b2c4
	lw	$4, %lo(D_0035f214)($19)	# 29b2c8
	move	$9,$21	# 29b2cc
	move	$8,$2	# 29b2d0
	li	$10,10	# 29b2d4
	jal	func_0028bae0	# 29b2d8
	move	$5,$23	# 29b2dc
	lw	$4, %lo(D_0035f214)($19)	# 29b2e0
	jal	func_0028be78	# 29b2e4
	move	$5,$20	# 29b2e8
	jal	func_0029cdf8	# 29b2ec
	nop	# 29b2f0
	jal	func_0029ea30	# 29b2f4
	nop	# 29b2f8
	jal	func_002766b0	# 29b2fc
	li	$4,1	# 29b300
	jal	func_00287cc0	# 29b304
	move	$4,$0	# 29b308
	ld	$16,48($29)	# 29b30c
	ld	$17,56($29)	# 29b310
	ld	$18,64($29)	# 29b314
	ld	$19,72($29)	# 29b318
	ld	$20,80($29)	# 29b31c
	ld	$21,88($29)	# 29b320
	ld	$22,96($29)	# 29b324
	ld	$23,104($29)	# 29b328
	ld	$30,112($29)	# 29b32c
	ld	$31,120($29)	# 29b330
	jr	$31	# 29b334
	addiu	$29,$29,128	# 29b338
.L0029b33c:
	slti	$15,$2,0	# 29b33c
	movn	$20,$0,$15	# 29b340
	b	.L0029b20c	# 29b344
	subu	$21,$18,$20	# 29b348
.L0029b34c:
	jal	func_00287bc0	# 29b34c
	nop	# 29b350
	move	$16,$2	# 29b354
	jal	func_00276608	# 29b358
	move	$4,$2	# 29b35c
	move	$21,$2	# 29b360
	jal	func_00276620	# 29b364
	move	$4,$16	# 29b368
	b	.L0029b214	# 29b36c
	move	$20,$2	# 29b370
	.end func_0029af20
	.size func_0029af20, 1108

# func_00205d60: partMng sprite emitter: per-emitter scale matrices (sceVu0UnitMatrix/sceVu0ScaleVector), then one
#   sprite packet per live point of D_00354680 (VU0 random start frame, VU0 model matrix, func_0021cdd0) and
#   frame advance unless paused (D_01d9ea9c / D_01d9e6e0 flags).
#   The float literal-pool words 0x00370508 (255.0f) and 0x0037050c (1.0f) have no D_ symbol, so their lui/addiu
#   are written as literal values.
#   Closest C: ~/re/kh2/tmp.w3941/best_00205d60.c (_nsa, about 230 lines off in try.sh): the original keeps &pos
#   in s8 and the emitter table in s7 (ours swaps them), holds the frame byte in t4 with andi at each use, and
#   schedules the shape-pointer load and pool luis differently.

	.section .text.func_00205d60,"ax",@progbits
	.globl func_00205d60
	.type func_00205d60, @function
	.ent func_00205d60
func_00205d60:
	addiu	$29,$29,-752	# 205d60
	lui	$15,%hi(D_00354680)	# 205d64
	sd	$17,680($29)	# 205d68
	sd	$23,728($29)	# 205d6c
	sd	$16,672($29)	# 205d70
	move	$17,$5	# 205d74
	sd	$18,688($29)	# 205d78
	sd	$19,696($29)	# 205d7c
	sd	$20,704($29)	# 205d80
	sd	$21,712($29)	# 205d84
	sd	$22,720($29)	# 205d88
	sd	$30,736($29)	# 205d8c
	sd	$31,744($29)	# 205d90
	lw	$14, %lo(D_00354680)($15)	# 205d94
	beqz	$14, .L00206190	# 205d98
	addiu	$23,$5,4	# 205d9c
	lui	$15,%hi(D_00354684)	# 205da0
	lw	$14, %lo(D_00354684)($15)	# 205da4
	blez	$14, .L00206190	# 205da8
	move	$4,$0	# 205dac
	jal	func_0021cda0	# 205db0
	move	$16,$0	# 205db4
	jal	func_0021e988	# 205db8
	nop	# 205dbc
	jal	func_0021e998	# 205dc0
	move	$18,$2	# 205dc4
	sw	$0,0($2)	# 205dc8
	addiu	$5,$17,11	# 205dcc
	li	$14,2	# 205dd0
	sw	$0,0($18)	# 205dd4
	lbu	$15,0($5)	# 205dd8
.L00205ddc:
	sltiu	$15,$15,255	# 205ddc
	bnez	$15, .L002061c0	# 205de0
	addiu	$5,$5,12	# 205de4
	sw	$14,0($2)	# 205de8
	sw	$14,0($18)	# 205dec
	mtc1	$0,$f0	# 205df0
.L00205df4:
	move	$16,$29	# 205df4
	move	$17,$23	# 205df8
	li	$19,9	# 205dfc
	swc1	$f0,8($2)	# 205e00
	swc1	$f0,8($18)	# 205e04
	move	$4,$16	# 205e08
.L00205e0c:
	jal	sceVu0UnitMatrix	# 205e0c
	addiu	$19,$19,-1	# 205e10
	lwc1	$f12,8($17)	# 205e14
	move	$4,$16	# 205e18
	jal	sceVu0ScaleVector	# 205e1c
	move	$5,$16	# 205e20
	addiu	$4,$16,16	# 205e24
	lwc1	$f12,8($17)	# 205e28
	jal	sceVu0ScaleVector	# 205e2c
	move	$5,$4	# 205e30
	lwc1	$f12,8($17)	# 205e34
	addiu	$4,$16,32	# 205e38
	addiu	$16,$16,64	# 205e3c
	move	$5,$4	# 205e40
	jal	sceVu0ScaleVector	# 205e44
	addiu	$17,$17,12	# 205e48
	bgez	$19, .L00205e0c	# 205e4c
	move	$4,$16	# 205e50
	lui	$15,%hi(D_00354684)	# 205e54
	lw	$14, %lo(D_00354684)($15)	# 205e58
	blez	$14, .L00206180	# 205e5c
	move	$16,$0	# 205e60
	move	$21,$16	# 205e64
	addiu	$30,$29,640	# 205e68
	lui	$22,%hi(D_01d9e6e8)	# 205e6c
	lui	$14,%hi(D_00354680)	# 205e70
.L00205e74:
	sll	$15,$21,0x4	# 205e74
	lw	$13, %lo(D_00354680)($14)	# 205e78
	addu	$17,$13,$15	# 205e7c
	lbu	$20,13($17)	# 205e80
	beqz	$20, .L00206168	# 205e84
	li	$15,12	# 205e88
	lbu	$19,12($17)	# 205e8c
	mult	$15,$19,$15	# 205e90
	addu	$16,$15,$23	# 205e94
	lw	$14,0($16)	# 205e98
	li	$15,0xffff	# 205e9c
	beq	$14, $15, .L0020616c	# 205ea0
	lui	$14,%hi(D_00354684)	# 205ea4
	jal	func_0021e9a8	# 205ea8
	nop	# 205eac
	lui	$15,%hi(D_01d9e6e4)	# 205eb0
	lw	$14,0($16)	# 205eb4
	lw	$12, %lo(D_01d9e6e4)($15)	# 205eb8
	sll	$11,$19,0x6	# 205ebc
	sll	$14,$14,0x3	# 205ec0
	move	$18,$2	# 205ec4
	lbu	$15,4($16)	# 205ec8
	addu	$11,$29,$11	# 205ecc
	lw	$13,20($12)	# 205ed0
	sw	$15,16($2)	# 205ed4
	addu	$13,$13,$14	# 205ed8
	lbu	$15,5($16)	# 205edc
	sw	$15,20($2)	# 205ee0
	lbu	$14,6($16)	# 205ee4
	li	$15,255	# 205ee8
	sw	$14,24($2)	# 205eec
	sw	$20,28($2)	# 205ef0
	lbu	$12,15($17)	# 205ef4
	andi	$14,$12,0xff	# 205ef8
	bne	$14, $15, .L00205f98	# 205efc
	lw	$16,0($13)	# 205f00
	lh	$15,6($16)	# 205f04
	sll	$15,$15,0x3	# 205f08
	addu	$15,$16,$15	# 205f0c
	lb	$14,12($15)	# 205f10
	andi	$14,$14,0x80	# 205f14
	beqzl	$14, .L00205f9c	# 205f18
	lbu	$14,14($17)	# 205f1c
	addi	$8,$0,-1	# 205f20
	qmtc2	$8,$vf2	# 205f24
	vrxor	R,vf2x	# 205f28
	vrnext.x	$vf1,R	# 205f2c
	vrxor	R,vf2x	# 205f30
	vrnext.x	$vf1,R	# 205f34
	vrxor	R,vf2x	# 205f38
	vrnext.x	$vf1,R	# 205f3c
	vrxor	R,vf2x	# 205f40
	vrnext.x	$vf1,R	# 205f44
	vrxor	R,vf2x	# 205f48
	vrnext.x	$vf1,R	# 205f4c
	vitof0.x	$vf2,$vf2	# 205f50
	vadd.x	$vf1,$vf1,$vf2	# 205f54
	qmfc2	$10,$vf1	# 205f58
	lh	$13,6($16)	# 205f5c
	mtc1	$10,$f0	# 205f60
	addiu	$15,$13,-1	# 205f64
	mtc1	$15,$f1	# 205f68
	cvt.s.w	$f1,$f1	# 205f6c
	mul.s	$f0,$f0,$f1	# 205f70
	cvt.w.s	$f1,$f0	# 205f74
	mfc1	$14,$f1	# 205f78
	bltz	$14, .L00205f8c	# 205f7c
	slt	$15,$14,$13	# 205f80
	bnezl	$15, .L00205f94	# 205f84
	sb	$14,15($17)	# 205f88
.L00205f8c:
	move	$14,$0	# 205f8c
	sb	$14,15($17)	# 205f90
.L00205f94:
	move	$12,$14	# 205f94
.L00205f98:
	lbu	$14,14($17)	# 205f98
.L00205f9c:
	lui	$10,0x37	# 205f9c
	addiu	$10,$10,1288	# 205fa0
	lw	$13, %lo(D_01d9e6e8)($22)	# 205fa4
	mtc1	$14,$f1	# 205fa8
	andi	$15,$12,0xff	# 205fac
	lwc1	$f0,0($10)	# 205fb0
	sll	$15,$15,0x3	# 205fb4
	cvt.s.w	$f1,$f1	# 205fb8
	addu	$15,$16,$15	# 205fbc
	lh	$4,16($15)	# 205fc0
	addiu	$19,$15,16	# 205fc4
	lui	$10,%hi(D_01d9e730)	# 205fc8
	addiu	$12,$29,656	# 205fcc
	lui	$15,0x37	# 205fd0
	addiu	$14,$13,80	# 205fd4
	nop	# 205fd8
	nop	# 205fdc
	div.s	$f1,$f1,$f0	# 205fe0
	addiu	$15,$15,1292	# 205fe4
	addiu	$10, $10, %lo(D_01d9e730)	# 205fe8
	addu	$4,$16,$4	# 205fec
	swc1	$f1,656($29)	# 205ff0
	lwc1	$f0,0($17)	# 205ff4
	swc1	$f0,640($29)	# 205ff8
	lwc1	$f0,4($17)	# 205ffc
	swc1	$f0,644($29)	# 206000
	lwc1	$f0,0($15)	# 206004
	lwc1	$f1,8($17)	# 206008
	lui	$15,%hi(D_01d9e8c0)	# 20600c
	addiu	$15, $15, %lo(D_01d9e8c0)	# 206010
	swc1	$f0,652($29)	# 206014
	swc1	$f1,648($29)	# 206018
	lqc2	$vf1,0($11)	# 20601c
	lqc2	$vf2,16($11)	# 206020
	lqc2	$vf3,32($11)	# 206024
	lqc2	$vf4,48($11)	# 206028
	lqc2	$vf5,0($10)	# 20602c
	lqc2	$vf6,16($10)	# 206030
	lqc2	$vf7,32($10)	# 206034
	lqc2	$vf8,48($10)	# 206038
	lqc2	$vf9,0($15)	# 20603c
	lqc2	$vf10,16($15)	# 206040
	lqc2	$vf11,32($15)	# 206044
	lqc2	$vf12,48($15)	# 206048
	lqc2	$vf13,0($30)	# 20604c
	lw	$1,0($12)	# 206050
	qmtc2	$1,$vf14	# 206054
	vmulax.wxyz	ACC,$vf5,vf13x	# 206058
	vmadday.wxyz	ACC,$vf6,vf13y	# 20605c
	vmaddaz.wxyz	ACC,$vf7,vf13z	# 206060
	vmaddw.wxyz	$vf4,$vf8,vf13w	# 206064
	vmulx.wxyz	$vf1,$vf1,vf14x	# 206068
	vmulx.wxyz	$vf2,$vf2,vf14x	# 20606c
	vmulx.wxyz	$vf3,$vf3,vf14x	# 206070
	vmulax.wxyz	ACC,$vf9,vf1x	# 206074
	vmadday.wxyz	ACC,$vf10,vf1y	# 206078
	vmaddaz.wxyz	ACC,$vf11,vf1z	# 20607c
	vmaddw.wxyz	$vf1,$vf12,vf1w	# 206080
	vmulax.wxyz	ACC,$vf9,vf2x	# 206084
	vmadday.wxyz	ACC,$vf10,vf2y	# 206088
	vmaddaz.wxyz	ACC,$vf11,vf2z	# 20608c
	vmaddw.wxyz	$vf2,$vf12,vf2w	# 206090
	vmulax.wxyz	ACC,$vf9,vf3x	# 206094
	vmadday.wxyz	ACC,$vf10,vf3y	# 206098
	vmaddaz.wxyz	ACC,$vf11,vf3z	# 20609c
	vmaddw.wxyz	$vf3,$vf12,vf3w	# 2060a0
	vmulax.wxyz	ACC,$vf9,vf4x	# 2060a4
	vmadday.wxyz	ACC,$vf10,vf4y	# 2060a8
	vmaddaz.wxyz	ACC,$vf11,vf4z	# 2060ac
	vmaddw.wxyz	$vf4,$vf12,vf4w	# 2060b0
	sqc2	$vf1,0($14)	# 2060b4
	sqc2	$vf2,16($14)	# 2060b8
	sqc2	$vf3,32($14)	# 2060bc
	sqc2	$vf4,48($14)	# 2060c0
	lq	$15,80($13)	# 2060c4
	move	$5,$18	# 2060c8
	sq	$15,48($18)	# 2060cc
	lw	$14, %lo(D_01d9e6e8)($22)	# 2060d0
	lq	$15,96($14)	# 2060d4
	sq	$15,64($18)	# 2060d8
	lw	$14, %lo(D_01d9e6e8)($22)	# 2060dc
	lq	$15,112($14)	# 2060e0
	sq	$15,80($18)	# 2060e4
	lw	$14, %lo(D_01d9e6e8)($22)	# 2060e8
	lq	$15,128($14)	# 2060ec
	jal	func_0021cdd0	# 2060f0
	sq	$15,96($18)	# 2060f4
	li	$15,10	# 2060f8
	lui	$14,%hi(D_01d9ea9c)	# 2060fc
	sw	$15,0($18)	# 206100
	lw	$15, %lo(D_01d9ea9c)($14)	# 206104
	bnez	$15, .L0020616c	# 206108
	lui	$14,%hi(D_00354684)	# 20610c
	lui	$14,%hi(D_01d9e6e0)	# 206110
	lw	$13, %lo(D_01d9e6e0)($14)	# 206114
	li	$14,255	# 206118
	ld	$15,168($13)	# 20611c
	dsll32	$14,$14,0x0	# 206120
	ori	$14,$14,0xff00	# 206124
	and	$15,$15,$14	# 206128
	bnez	$15, .L0020616c	# 20612c
	lui	$14,%hi(D_00354684)	# 206130
	lbu	$13,15($17)	# 206134
	addiu	$15,$13,1	# 206138
	sb	$15,15($17)	# 20613c
	lh	$14,6($16)	# 206140
	andi	$15,$15,0xff	# 206144
	slt	$15,$15,$14	# 206148
	bnez	$15, .L0020616c	# 20614c
	lui	$14,%hi(D_00354684)	# 206150
	lb	$15,4($19)	# 206154
	andi	$15,$15,0x80	# 206158
	beqzl	$15, .L0020616c	# 20615c
	sb	$13,15($17)	# 206160
	sb	$0,15($17)	# 206164
.L00206168:
	lui	$14,%hi(D_00354684)	# 206168
.L0020616c:
	addiu	$21,$21,1	# 20616c
	lw	$15, %lo(D_00354684)($14)	# 206170
	slt	$15,$21,$15	# 206174
	bnez	$15, .L00205e74	# 206178
	lui	$14,%hi(D_00354680)	# 20617c
.L00206180:
	jal	func_001e7538	# 206180
	nop	# 206184
	jal	func_0020e0a0	# 206188
	nop	# 20618c
.L00206190:
	ld	$16,672($29)	# 206190
	ld	$17,680($29)	# 206194
	ld	$18,688($29)	# 206198
	ld	$19,696($29)	# 20619c
	ld	$20,704($29)	# 2061a0
	ld	$21,712($29)	# 2061a4
	ld	$22,720($29)	# 2061a8
	ld	$23,728($29)	# 2061ac
	ld	$30,736($29)	# 2061b0
	ld	$31,744($29)	# 2061b4
	jr	$31	# 2061b8
	addiu	$29,$29,752	# 2061bc
.L002061c0:
	addiu	$16,$16,1	# 2061c0
	slti	$15,$16,10	# 2061c4
	bnezl	$15, .L00205ddc	# 2061c8
	lbu	$15,0($5)	# 2061cc
	b	.L00205df4	# 2061d0
	mtc1	$0,$f0	# 2061d4
	.end func_00205d60
	.size func_00205d60, 1144
