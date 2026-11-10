# Whole-function assembly (last step of the README match ladder, w3951 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_0024ce18: smenu layout init: builds the D_0035edd4/D_0035eddc/D_0035edd8 layouts, one D_0035edcc list
#     row per func_0024e058 entry (36-byte records, req bytes checked with func_001a6d08), centres the rows,
#     func_002b4070 header, optional func_0024e080 extra row, then func_00288750(func_0024d6b8).
#     Closest C: ~/re/kh2/tmp.w3951/best_0024ce18.cpp (_mam, = coord best/0024ce18_w3937_mam.cpp, 42 lines off):
#     movz instead of movn (cmove tie goes to i+3), prologue sd s2/lui order, tbl spill not in the blez slot,
#     loop-2 move s6 slot, half in a2 not a1, func_002b4070 stack-arg block order.
#     No symbol, written as literal lui/addiu values: 0x00372158, 0x00372190, 0x00372198, 0x003721a0,
#     0x003721a8, 0x003721b0 (strings), 0x0024d6b8 (callback address).
#   func_001e8558: per-group callback pass over the node lists (two handler callbacks per node, each timed
#     with the EE timer at 0x10000000 into the handler's start/sum/max), then the free/relink pass.
#     Closest C: ~/re/kh2/tmp.w3951/best_001e8558.c (_nsa, = coord best/001e8558_w3937_nsa.c, 72 lines off by
#     difflib): D_01d9e6e8 store scheduled before the D_01d9ea9c load, j latch kept in t4 (ours reloads 16(sp)),
#     loop B load placement; needed 5 register pins already.
#     No symbol, written as literal lui values: 0x10000000 (timer T0 count), 0x6fff/0x7000 constants.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0024ce18,"ax",@progbits
	.globl func_0024ce18
	.type func_0024ce18, @function
	.ent func_0024ce18
func_0024ce18:
	addiu	$29,$29,-144
	lui	$15,%hi(D_0035edf0)
	sd	$31,136($29)
	li	$4,160
	sd	$16,64($29)
	sd	$17,72($29)
	sd	$20,96($29)
	sd	$22,112($29)
	lui	$17,%hi(D_0035edd4)
	sd	$23,120($29)
	move	$20,$0
	sb	$0,%lo(D_0035edf0)($15)
	sd	$18,80($29)
	sd	$19,88($29)
	sd	$21,104($29)
	sd	$30,128($29)
	jal	func_0023ee30
	move	$23,$0
	lui	$15,%hi(D_00347F98)
	move	$16,$2
	addiu	$15,$15,%lo(D_00347F98)
	addiu	$4,$2,12
	jal	func_0031a838
	sw	$15,0($2)
	lui	$15,%hi(D_0035eb98)
	addiu	$4,$16,24
	addiu	$15,$15,%lo(D_0035eb98)
	jal	func_002369a0
	sw	$15,0($16)
	jal	func_0023c008
	addiu	$4,$16,48
	sw	$16,%lo(D_0035edd4)($17)
	li	$5,30002
	move	$6,$0
	move	$7,$0
	sw	$0,0($29)
	li	$8,30
	li	$9,32
	move	$10,$0
	move	$11,$0
	jal	func_0028d7f0
	move	$4,$16
	jal	func_0023ef50
	lw	$4,%lo(D_0035edd4)($17)
	jal	func_0024dfe0
	nop
	jal	func_0024e058
	move	$22,$2
	blez	$22,.L0024cffc
	sw	$2,48($29)
	lw	$18,48($29)
	lui	$30,%hi(D_0035edcc)
.L0024cee8:
	move	$19,$0
	li	$21,1
	move	$17,$0
	addiu	$16,$18,28
	lb	$15,0($16)
.L0024cefc:
	addiu	$16,$16,1
	bltz	$15,.L0024cf1c
	move	$4,$15
	jal	func_001a6d08
	nop
	bnezl	$2,.L0024d334
	addiu	$17,$17,1
	move	$21,$0
.L0024cf1c:
	beqz	$21,.L0024cfcc
	lui	$13,%hi(D_0035edf4)
	move	$5,$20
	lw	$14,%lo(D_0035edf4)($13)
	addiu	$15,$20,3
	move	$4,$0
	jal	func_002431d0
	movn	$5,$15,$14
	bnezl	$2,.L0024cf64
	lb	$15,16($18)
	lui	$14,%hi(D_0035edfc)
	li	$13,1
	lbu	$15,%lo(D_0035edfc)($14)
	sllv	$14,$13,$20
	or	$15,$15,$14
	lui	$14,%hi(D_0035edfc)
	sb	$15,%lo(D_0035edfc)($14)
	lb	$15,16($18)
.L0024cf64:
	lui	$13,%hi(D_0035edd4)
	lhu	$9,18($18)
	addiu	$11,$18,8
	lw	$8,%lo(D_0035edd4)($13)
	movn	$23,$20,$15
	lw	$4,%lo(D_0035edcc)($30)
	move	$6,$0
	move	$7,$0
	move	$10,$18
	jal	func_00288d80
	move	$5,$20
	lw	$4,%lo(D_0035edcc)($30)
	jal	func_002891b8
	move	$5,$20
	move	$19,$2
	jal	func_0023aa98
	addiu	$4,$2,24
	move	$16,$2
	jal	func_0028dd90
	move	$4,$2
	sw	$2,432($19)
	jal	func_0028ddd8
	move	$4,$16
	sw	$2,428($19)
	jal	func_001395f8
	move	$4,$19
.L0024cfcc:
	lbu	$15,17($18)
	xori	$15,$15,0x1
	andi	$15,$15,0x1
	andi	$15,$15,0xff
	beqzl	$15,.L0024cff0
	addiu	$20,$20,1
	jal	func_00139570
	move	$4,$19
	addiu	$20,$20,1
.L0024cff0:
	slt	$15,$20,$22
	bnez	$15,.L0024cee8
	addiu	$18,$18,36
.L0024cffc:
	lui	$16,%hi(D_0035edcc)
	move	$20,$0
	jal	func_002892f8
	lw	$4,%lo(D_0035edcc)($16)
	lw	$4,%lo(D_0035edcc)($16)
	move	$5,$0
	jal	func_002891b8
	move	$22,$2
	jal	func_0023aa78
	addiu	$4,$2,24
	mult	$15,$2,$22
	move	$18,$2
	srl	$14,$15,0x1f
	addu	$15,$15,$14
	blez	$22,.L0024d078
	sra	$5,$15,0x1
	move	$19,$16
	move	$17,$20
	negu	$16,$5
	lw	$4,-4660($19)
.L0024d04c:
	move	$5,$17
	jal	func_002891b8
	addiu	$17,$17,1
	move	$6,$16
	move	$4,$2
	move	$5,$0
	jal	func_00138c68
	addu	$16,$16,$18
	slt	$15,$17,$22
	bnezl	$15,.L0024d04c
	lw	$4,-4660($19)
.L0024d078:
	lui	$21,%hi(D_0035edcc)
	move	$5,$23
	lw	$4,%lo(D_0035edcc)($21)
	move	$6,$0
	li	$7,-1
	jal	func_002891f0
	li	$8,-1
	jal	func_0024df90
	lui	$22,%hi(D_0035edd4)
	lui	$18,%hi(D_00347F98)
	lw	$4,%lo(D_0035edcc)($21)
	addiu	$18,$18,%lo(D_00347F98)
	lui	$17,%hi(D_0035eb98)
	jal	func_002891e8
	lui	$19,%hi(D_0035eddc)
	addiu	$17,$17,%lo(D_0035eb98)
	lw	$4,%lo(D_0035edcc)($21)
	move	$23,$2
	move	$5,$2
	li	$6,1
	move	$7,$0
	jal	func_002891f0
	li	$8,2
	lui	$20,%hi(D_0035edd8)
	li	$14,36
	lw	$15,48($29)
	mult	$14,$23,$14
	li	$5,0xcb96
	sw	$5,8($29)
	lui	$7,0x37
	lui	$8,0x37
	lui	$9,0x37
	lui	$10,0x37
	lui	$11,0x37
	addu	$14,$15,$14
	addiu	$7,$7,8536
	lui	$15,0x37
	sw	$14,16($29)
	addiu	$15,$15,8624
	addiu	$8,$8,8592
	sw	$15,0($29)
	addiu	$9,$9,8600
	addiu	$10,$10,8608
	addiu	$11,$11,8616
	lui	$15,%hi(D_0035edec)
	li	$5,30003
	lw	$4,%lo(D_0035edec)($15)
	sw	$0,24($29)
	sw	$0,32($29)
	jal	func_002b4070
	lw	$6,%lo(D_0035edd4)($22)
	jal	func_0023ee30
	li	$4,160
	sw	$18,0($2)
	move	$16,$2
	jal	func_0031a838
	addiu	$4,$2,12
	sw	$17,0($16)
	jal	func_002369a0
	addiu	$4,$16,24
	jal	func_0023c008
	addiu	$4,$16,48
	sw	$16,%lo(D_0035eddc)($19)
	jal	func_0024e008
	move	$4,$23
	lh	$9,4($2)
	li	$5,30002
	lh	$8,0($2)
	move	$6,$0
	lw	$4,%lo(D_0035eddc)($19)
	move	$7,$0
	move	$10,$0
	move	$11,$0
	jal	func_0028d7f0
	sw	$0,0($29)
	jal	func_0023ef50
	lw	$4,%lo(D_0035eddc)($19)
	jal	func_0023ee30
	li	$4,160
	sw	$18,0($2)
	move	$16,$2
	jal	func_0031a838
	addiu	$4,$2,12
	sw	$17,0($16)
	jal	func_002369a0
	addiu	$4,$16,24
	jal	func_0023c008
	addiu	$4,$16,48
	sw	$16,%lo(D_0035edd8)($20)
	move	$4,$16
	li	$5,30019
	move	$6,$0
	sw	$0,0($29)
	move	$7,$0
	li	$8,33
	li	$9,35
	move	$10,$0
	jal	func_0028d7f0
	move	$11,$0
	jal	func_0023ef50
	lw	$4,%lo(D_0035edd8)($20)
	jal	func_001a6d08
	li	$4,7
	beqz	$2,.L0024d290
	nop
	jal	func_0024e080
	nop
	beqz	$2,.L0024d290
	lw	$4,%lo(D_0035edcc)($21)
	li	$5,512
	jal	func_0028af40
	lui	$16,%hi(D_0035ede0)
	lw	$8,%lo(D_0035edd4)($22)
	li	$5,30011
	move	$6,$0
	move	$7,$0
	sw	$0,0($29)
	li	$9,31
	li	$10,33
	li	$11,2887
	jal	func_0028d980
	lw	$4,%lo(D_0035ede0)($16)
	jal	func_00139620
	lw	$4,%lo(D_0035ede0)($16)
	jal	func_001395f8
	lw	$4,%lo(D_0035ede0)($16)
	lw	$13,%lo(D_0035ede0)($16)
	li	$15,1
	sb	$15,405($13)
	lw	$14,%lo(D_0035ede0)($16)
	addiu	$14,$14,24
	lw	$15,184($14)
	ori	$15,$15,0x8
	sw	$15,184($14)
.L0024d290:
	jal	func_0024e158
	nop
	move	$5,$0
	jal	func_00287bd0
	move	$4,$0
	jal	func_00287cc0
	move	$4,$0
	jal	func_002887c8
	nop
	beqz	$2,.L0024d308
	ld	$16,64($29)
	jal	func_0024d4a0
	nop
	li	$15,1
	ld	$16,64($29)
	lui	$14,%hi(D_0035edf0)
	ld	$17,72($29)
	sb	$15,%lo(D_0035edf0)($14)
	lui	$4,0x25
	ld	$18,80($29)
	addiu	$4,$4,-10568
	ld	$19,88($29)
	ld	$20,96($29)
	ld	$21,104($29)
	ld	$22,112($29)
	ld	$23,120($29)
	ld	$30,128($29)
	ld	$31,136($29)
	j	0x288750
	addiu	$29,$29,144
.L0024d308:
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
.L0024d334:
	slti	$15,$17,4
	bnezl	$15,.L0024cefc
	lb	$15,0($16)
	b	.L0024cf1c
	nop
	.end func_0024ce18
	.size func_0024ce18, 1328

	.section .text.func_001e8558,"ax",@progbits
	.globl func_001e8558
	.type func_001e8558, @function
	.ent func_001e8558
func_001e8558:
	addiu	$29,$29,-128
	sd	$16,48($29)
	sd	$17,56($29)
	sd	$18,64($29)
	sd	$19,72($29)
	sd	$20,80($29)
	sd	$21,88($29)
	sd	$22,96($29)
	sd	$23,104($29)
	sd	$30,112($29)
	sd	$31,120($29)
	sw	$4,0($29)
	sw	$5,4($29)
	lw	$13,104($4)
	blez	$13,.L001e881c
	sw	$0,8($29)
	lw	$12,0($29)
.L001e859c:
	lw	$15,128($12)
	lw	$12,8($29)
	sll	$14,$12,0x4
	addu	$15,$15,$14
	sw	$15,12($29)
	lw	$22,0($15)
	lhu	$15,12($15)
	beqz	$15,.L001e8808
	lw	$15,8($29)
	lhu	$14,38($22)
	sll	$15,$14,0x10
	sra	$15,$15,0x10
	blez	$15,.L001e877c
	sw	$0,16($29)
	move	$23,$22
.L001e85d8:
	lw	$21,40($23)
	addiu	$13,$23,40
	lw	$15,12($29)
	sw	$13,20($29)
	lw	$17,4($15)
	lw	$12,4($21)
	sw	$12,24($29)
	lw	$13,12($21)
	beqz	$13,.L001e875c
	sw	$13,28($29)
	beqz	$12,.L001e8a04
	lw	$14,16($29)
	lhu	$18,12($15)
	sll	$14,$14,0x2
	sw	$14,32($29)
.L001e8614:
	lw	$15,32($22)
	lw	$12,32($29)
	addu	$15,$17,$15
	lw	$30,0($17)
	lbu	$14,156($17)
	bnez	$14,.L001e874c
	addu	$16,$15,$12
	lw	$19,0($16)
	lui	$13,%hi(D_01d9ea9c)
	lhu	$15,44($23)
	lui	$12,%hi(D_01d9e6e8)
	lw	$14,%lo(D_01d9ea9c)($13)
	sw	$17,%lo(D_01d9e6e8)($12)
	bnez	$14,.L001e8694
	addu	$20,$19,$15
	lui	$13,%hi(D_01d9e6e0)
	lw	$14,%lo(D_01d9e6e0)($13)
	ld	$15,168($14)
	li	$14,255
	dsll32	$14,$14,0x0
	ori	$14,$14,0xff00
	and	$15,$15,$14
	bnezl	$15,.L001e8698
	lw	$14,0($20)
	lbu	$15,158($17)
	beqz	$15,.L001e8694
	li	$15,1
	sw	$0,12($17)
	sb	$15,157($17)
	jal	func_001e7948
	move	$4,$17
	sb	$0,158($17)
.L001e8694:
	lw	$14,0($20)
.L001e8698:
	lw	$15,12($17)
	bnel	$14,$15,.L001e86b0
	lui	$20,0x1000
	sw	$20,0($16)
	move	$19,$20
	lui	$20,0x1000
.L001e86b0:
	lw	$6,20($29)
	lw	$15,0($20)
	move	$4,$17
	move	$5,$19
	sw	$15,40($21)
	lw	$12,24($29)
	jalr	$12
	addiu	$16,$21,40
	lw	$14,0($20)
	lw	$13,40($21)
	lw	$12,4($16)
	subu	$14,$14,$13
	lw	$15,8($16)
	addu	$12,$12,$14
	slt	$15,$15,$12
	beqz	$15,.L001e86f8
	sw	$12,4($16)
	sw	$12,8($16)
.L001e86f8:
	lw	$13,4($29)
	beqzl	$13,.L001e8750
	addiu	$18,$18,-1
	lw	$15,0($20)
	move	$4,$17
	lw	$6,20($29)
	move	$5,$19
	sw	$15,56($21)
	lw	$14,28($29)
	jalr	$14
	addiu	$16,$21,56
	lw	$14,0($20)
	lw	$13,56($21)
	lw	$12,4($16)
	subu	$14,$14,$13
	lw	$15,8($16)
	addu	$12,$12,$14
	slt	$15,$15,$12
	beqz	$15,.L001e874c
	sw	$12,4($16)
	sw	$12,8($16)
.L001e874c:
	addiu	$18,$18,-1
.L001e8750:
	bnez	$18,.L001e8614
	move	$17,$30
	lhu	$14,38($22)
.L001e875c:
	lw	$12,16($29)
	sll	$15,$14,0x10
	sra	$15,$15,0x10
	addiu	$23,$23,16
	addiu	$12,$12,1
	slt	$15,$12,$15
	bnez	$15,.L001e85d8
	sw	$12,16($29)
.L001e877c:
	lui	$15,%hi(D_01d9ea9c)
	lw	$14,%lo(D_01d9ea9c)($15)
	bnezl	$14,.L001e89fc
	lw	$12,0($29)
	lui	$14,%hi(D_01d9e6e0)
	lw	$13,%lo(D_01d9e6e0)($14)
	li	$14,255
	ld	$15,168($13)
	dsll32	$14,$14,0x0
	ori	$14,$14,0xff00
	and	$15,$15,$14
	bnez	$15,.L001e89f4
	lw	$14,0($29)
	lw	$14,12($29)
	lui	$12,0x6fff
	lui	$11,0x6fff
	ori	$12,$12,0xffff
	lhu	$13,12($14)
	ori	$11,$11,0xf000
	lw	$14,4($14)
.L001e87cc:
	lbu	$15,156($14)
	bnezl	$15,.L001e87f0
	sb	$0,156($14)
	lw	$15,12($14)
	addiu	$15,$15,4096
	sw	$15,12($14)
	slt	$15,$12,$15
	bnezl	$15,.L001e87f0
	sw	$11,12($14)
.L001e87f0:
	addiu	$13,$13,-1
	bnez	$13,.L001e87cc
	lw	$14,0($14)
	lw	$15,0($29)
	lw	$13,104($15)
.L001e8804:
	lw	$15,8($29)
.L001e8808:
	addiu	$15,$15,1
	sw	$15,8($29)
	slt	$15,$15,$13
	bnezl	$15,.L001e859c
	lw	$12,0($29)
.L001e881c:
	lui	$15,%hi(D_01d9ea9c)
	lw	$14,%lo(D_01d9ea9c)($15)
	bnez	$14,.L001e894c
	ld	$16,48($29)
	lui	$14,%hi(D_01d9e6e0)
	lw	$13,%lo(D_01d9e6e0)($14)
	li	$14,255
	ld	$15,168($13)
	dsll32	$14,$14,0x0
	ori	$14,$14,0xff00
	and	$15,$15,$14
	bnezl	$15,.L001e8950
	ld	$17,56($29)
	lw	$12,0($29)
	move	$20,$0
	lw	$16,116($12)
	beqz	$16,.L001e8908
	addiu	$19,$12,116
	lui	$21,%hi(D_01d9eab4)
	li	$30,1
	move	$23,$21
	li	$22,1
.L001e8874:
	lw	$14,8($16)
	lw	$13,0($29)
	lw	$18,0($16)
	lbu	$15,133($13)
	bnez	$15,.L001e89ec
	lw	$17,0($14)
	lw	$14,12($16)
	lw	$12,28($17)
	slt	$15,$14,$12
	bnezl	$15,.L001e89cc
	lw	$15,20($17)
	lw	$15,24($17)
	lui	$13,0x6fff
	ori	$13,$13,0xffff
	slt	$15,$13,$15
	bnezl	$15,.L001e89cc
	lw	$15,20($17)
	slt	$15,$13,$12
	bnezl	$15,.L001e89cc
	lw	$15,20($17)
	sw	$0,12($16)
	move	$4,$16
	jal	func_001e7948
	sb	$30,157($16)
	lw	$15,24($17)
	bnez	$15,.L001e8978
	li	$14,1
	sw	$22,%lo(D_01d9eab4)($21)
	move	$5,$16
	jal	func_001e8e28
	lw	$4,0($29)
	sw	$0,%lo(D_01d9eab4)($21)
	sb	$22,158($16)
.L001e88f8:
	move	$19,$16
.L001e88fc:
	bnez	$18,.L001e8874
	move	$16,$18
	lw	$12,0($29)
.L001e8908:
	lbu	$15,132($12)
	beqzl	$15,.L001e894c
	ld	$16,48($29)
	lbu	$15,133($12)
	beqz	$15,.L001e8948
	lui	$15,0x7000
	bne	$20,$15,.L001e894c
	ld	$16,48($29)
	lw	$4,116($12)
.L001e892c:
	beqz	$4,.L001e8944
	lw	$13,0($29)
	jal	func_001e7be0
	lw	$16,0($4)
	b	.L001e892c
	move	$4,$16
.L001e8944:
	sw	$0,116($13)
.L001e8948:
	ld	$16,48($29)
.L001e894c:
	ld	$17,56($29)
.L001e8950:
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
.L001e8978:
	sw	$14,-5452($23)
	lw	$15,12($16)
	lw	$14,24($17)
	slt	$15,$15,$14
	beqz	$15,.L001e89b8
	move	$19,$17
	lw	$17,0($29)
	move	$4,$17
.L001e8998:
	jal	func_001e8e28
	move	$5,$16
	lw	$15,12($16)
	lw	$14,24($19)
	slt	$15,$15,$14
	bnezl	$15,.L001e8998
	move	$4,$17
	sw	$17,0($29)
.L001e89b8:
	lui	$15,%hi(D_01d9eab4)
	b	.L001e88f8
	sw	$0,%lo(D_01d9eab4)($15)
	nop
.L001e89c8:
	lw	$15,20($17)
.L001e89cc:
	sltu	$14,$14,$15
	bnez	$14,.L001e88f8
	or	$20,$20,$15
	sw	$18,0($19)
	jal	func_001e7be0
	move	$4,$16
	b	.L001e88fc
	nop
.L001e89ec:
	b	.L001e89c8
	lw	$14,12($16)
.L001e89f4:
	b	.L001e8804
	lw	$13,104($14)
.L001e89fc:
	b	.L001e8804
	lw	$13,104($12)
.L001e8a04:
	lw	$15,12($29)
	lui	$19,%hi(D_01d9e6e8)
	lw	$12,16($29)
	lui	$20,0x1000
	lhu	$18,12($15)
	sll	$12,$12,0x2
	sw	$12,32($29)
.L001e8a20:
	lw	$15,32($22)
	lw	$13,32($29)
	addu	$15,$17,$15
	lbu	$14,156($17)
	bnez	$14,.L001e8ab0
	addu	$12,$15,$13
	lhu	$15,44($23)
	lw	$5,0($12)
	sw	$17,%lo(D_01d9e6e8)($19)
	addu	$13,$5,$15
	lw	$14,12($17)
	lw	$15,0($13)
	bne	$15,$14,.L001e8a64
	lw	$14,4($29)
	sw	$13,0($12)
	move	$5,$13
	lw	$14,4($29)
.L001e8a64:
	beqzl	$14,.L001e8ab4
	addiu	$18,$18,-1
	lw	$15,0($20)
	move	$4,$17
	lw	$6,20($29)
	sw	$15,56($21)
	lw	$15,28($29)
	jalr	$15
	addiu	$16,$21,56
	lw	$14,0($20)
	lw	$13,56($21)
	lw	$12,4($16)
	subu	$14,$14,$13
	lw	$15,8($16)
	addu	$12,$12,$14
	slt	$15,$15,$12
	beqz	$15,.L001e8ab0
	sw	$12,4($16)
	sw	$12,8($16)
.L001e8ab0:
	addiu	$18,$18,-1
.L001e8ab4:
	bnez	$18,.L001e8a20
	lw	$17,0($17)
	b	.L001e875c
	lhu	$14,38($22)
	.end func_001e8558
	.size func_001e8558, 1388
