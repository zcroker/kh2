# Whole-function assembly (last step of the README match ladder, w3949 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_00269658: fills the 9 list rows of a menu page (func_002891b8/func_00138c10 per row), then walks 5 categories
#     (counts from func_002827e0, ability mask from func_002813b8 & func_00281420) and sets each visible row's icon/text
#     from the s16/u16 tables at 0x00373738.. and the func_00281f30/func_00281f20 records.
#     Closest C: ~/re/kh2/tmp.w3949/best_00269658.cpp (C++, default flags, 42 of 258 lines off): orig copies the first
#     loop counter from cat (move s2,s5) and resets cat before the main loop; p/i swap s0/s1 in the first two loops;
#     hoisted table-address spill order 56/60/64.
#     No symbol, written as literal lui/addiu values: 0x00373738, 0x00373748, 0x00373758, 0x00373778 (s16 tables).
# Split out of batch_w3949.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00269658,"ax",@progbits
	.globl func_00269658
	.type func_00269658, @function
	.ent func_00269658
func_00269658:
	addiu	$29,$29,-160	# 269658
	sd	$31,152($29)	# 26965c
	sd	$16,80($29)	# 269660
	sd	$17,88($29)	# 269664
	sd	$18,96($29)	# 269668
	lui	$16,%hi(D_0035f01c)	# 26966c
	sd	$19,104($29)	# 269670
	sd	$20,112($29)	# 269674
	sd	$21,120($29)	# 269678
	lui	$19,%hi(D_0035ef6c)	# 26967c
	sd	$22,128($29)	# 269680
	move	$20,$16	# 269684
	sd	$23,136($29)	# 269688
	move	$21,$0	# 26968c
	sd	$30,144($29)	# 269690
	jal	func_00257130	# 269694
	move	$18,$21	# 269698
	jal	func_00281f18	# 26969c
	move	$4,$2	# 2696a0
	jal	func_00257770	# 2696a4
	sw	$2,48($29)	# 2696a8
	sw	$2,52($29)	# 2696ac
	jal	func_00139d78	# 2696b0
	lw	$4,52($29)	# 2696b4
	lw	$4, %lo(D_0035f01c)($16)	# 2696b8
	jal	func_0028b038	# 2696bc
	lw	$16,52($29)	# 2696c0
	lui	$15,%hi(D_0035f04c)	# 2696c4
	move	$5,$2	# 2696c8
	jal	func_0028be78	# 2696cc
	lw	$4, %lo(D_0035f04c)($15)	# 2696d0
	jal	func_00257140	# 2696d4
	move	$4,$0	# 2696d8
	move	$17,$2	# 2696dc
.L002696e0:
	lw	$4,-4068($20)	# 2696e0
	move	$5,$18	# 2696e4
	jal	func_002891b8	# 2696e8
	addiu	$18,$18,1	# 2696ec
	lw	$5, %lo(D_0035ef6c)($19)	# 2696f0
	jal	func_00138c10	# 2696f4
	move	$4,$2	# 2696f8
	addiu	$4,$16,24304	# 2696fc
	jal	func_00138c10	# 269700
	move	$5,$17	# 269704
	sw	$0,24712($16)	# 269708
	addiu	$4,$16,3376	# 26970c
	jal	func_00138c10	# 269710
	lw	$5, %lo(D_0035ef6c)($19)	# 269714
	sw	$0,3784($16)	# 269718
	slti	$15,$18,9	# 26971c
	bnez	$15, .L002696e0	# 269720
	addiu	$16,$16,436	# 269724
	move	$17,$0	# 269728
	move	$16,$29	# 26972c
.L00269730:
	jal	func_00257130	# 269730
	nop	# 269734
	move	$5,$17	# 269738
	jal	func_002827e0	# 26973c
	move	$4,$2	# 269740
	addiu	$17,$17,1	# 269744
	sw	$2,0($16)	# 269748
	slti	$15,$17,5	# 26974c
	bnez	$15, .L00269730	# 269750
	addiu	$16,$16,4	# 269754
	sw	$0,32($29)	# 269758
	lw	$15,4($29)	# 26975c
	beqz	$15, .L00269784	# 269760
	lui	$16,%hi(D_0035f01c)	# 269764
	jal	func_002813b8	# 269768
	nop	# 26976c
	jal	func_00281420	# 269770
	move	$16,$2	# 269774
	and	$16,$16,$2	# 269778
	sw	$16,32($29)	# 26977c
	lui	$16,%hi(D_0035f01c)	# 269780
.L00269784:
	move	$23,$0	# 269784
	lw	$4, %lo(D_0035f01c)($16)	# 269788
	move	$18,$0	# 26978c
	jal	func_0028b038	# 269790
	move	$21,$0	# 269794
	jal	func_00257130	# 269798
	move	$22,$2	# 26979c
	jal	func_00281f30	# 2697a0
	move	$4,$2	# 2697a4
	jal	func_00257130	# 2697a8
	sw	$2,40($29)	# 2697ac
	jal	func_00281f20	# 2697b0
	move	$4,$2	# 2697b4
	sw	$2,44($29)	# 2697b8
	jal	func_0028afa8	# 2697bc
	lw	$4, %lo(D_0035f01c)($16)	# 2697c0
	sw	$2,36($29)	# 2697c4
	lw	$13,36($29)	# 2697c8
.L002697cc:
	addu	$15,$22,$18	# 2697cc
	slt	$15,$15,$13	# 2697d0
	beqz	$15, .L002699b8	# 2697d4
	sll	$30,$21,0x2	# 2697d8
	addu	$15,$30,$29	# 2697dc
	lw	$14,0($15)	# 2697e0
	blez	$14, .L00269980	# 2697e4
	move	$19,$0	# 2697e8
	slti	$15,$18,9	# 2697ec
	beqz	$15, .L00269980	# 2697f0
	lui	$14,0x37	# 2697f4
	sll	$13,$21,0x1	# 2697f8
	addiu	$14,$14,14136	# 2697fc
	lui	$15,0x37	# 269800
	addu	$14,$13,$14	# 269804
	addiu	$15,$15,14168	# 269808
	sw	$14,64($29)	# 26980c
	addu	$15,$13,$15	# 269810
	sw	$15,56($29)	# 269814
	lui	$14,%hi(D_00373768)	# 269818
	addiu	$14, $14, %lo(D_00373768)	# 26981c
	addu	$13,$13,$14	# 269820
	sw	$13,60($29)	# 269824
	slt	$15,$23,$22	# 269828
.L0026982c:
	bnez	$15, .L00269960	# 26982c
	addu	$14,$30,$29	# 269830
	beqz	$19, .L00269848	# 269834
	li	$17,-1	# 269838
	li	$15,1	# 26983c
	bne	$21, $15, .L00269898	# 269840
	nop	# 269844
.L00269848:
	li	$20,-1	# 269848
	li	$15,1	# 26984c
	beq	$21, $15, .L002699f8	# 269850
	li	$16,-1	# 269854
	lw	$15,56($29)	# 269858
	lw	$13,60($29)	# 26985c
	lh	$16,0($15)	# 269860
	lhu	$20,0($13)	# 269864
.L00269868:
	move	$5,$16	# 269868
.L0026986c:
	lw	$14,52($29)	# 26986c
	li	$16,436	# 269870
	mult	$16,$18,$16	# 269874
	addu	$16,$14,$16	# 269878
	addiu	$16,$16,3376	# 26987c
	jal	func_00138c10	# 269880
	move	$4,$16	# 269884
	jal	func_00192048	# 269888
	move	$4,$20	# 26988c
	sw	$2,408($16)	# 269890
	li	$15,1	# 269894
.L00269898:
	beq	$21, $15, .L002699e8	# 269898
	lui	$13,0x37	# 26989c
	lw	$15,64($29)	# 2698a0
.L002698a4:
	lh	$16,0($15)	# 2698a4
	move	$5,$18	# 2698a8
	lw	$14,48($29)	# 2698ac
	addu	$15,$22,$18	# 2698b0
	div	$0,$15,$14	# 2698b4
	beqzl	$14, .L002698c0	# 2698b8
	break	0x7	# 2698bc
.L002698c0:
	lui	$14,%hi(D_0035f01c)	# 2698c0
	mfhi	$20	# 2698c4
	jal	func_002891b8	# 2698c8
	lw	$4, %lo(D_0035f01c)($14)	# 2698cc
	move	$4,$2	# 2698d0
	jal	func_00138c10	# 2698d4
	move	$5,$16	# 2698d8
	jal	func_00257140	# 2698dc
	move	$4,$0	# 2698e0
	li	$15,4	# 2698e4
	bne	$21, $15, .L00269920	# 2698e8
	move	$17,$2	# 2698ec
	li	$15,6	# 2698f0
	lw	$13,44($29)	# 2698f4
	mult	$15,$20,$15	# 2698f8
	addu	$15,$15,$13	# 2698fc
	lbu	$6,3($15)	# 269900
	lhu	$4,0($15)	# 269904
	lbu	$5,2($15)	# 269908
	jal	func_00257158	# 26990c
	sltu	$6,$0,$6	# 269910
	jal	func_00257140	# 269914
	move	$4,$2	# 269918
	move	$17,$2	# 26991c
.L00269920:
	li	$16,436	# 269920
	lw	$14,52($29)	# 269924
	mult	$16,$18,$16	# 269928
	move	$5,$17	# 26992c
	addu	$16,$14,$16	# 269930
	addiu	$18,$18,1	# 269934
	addiu	$16,$16,24304	# 269938
	jal	func_00138c10	# 26993c
	move	$4,$16	# 269940
	li	$15,80	# 269944
	lw	$13,40($29)	# 269948
	mult	$15,$20,$15	# 26994c
	addu	$15,$13,$15	# 269950
	addiu	$15,$15,16	# 269954
	sw	$15,408($16)	# 269958
	addu	$14,$30,$29	# 26995c
.L00269960:
	addiu	$19,$19,1	# 269960
	lw	$15,0($14)	# 269964
	slt	$15,$19,$15	# 269968
	beqz	$15, .L00269980	# 26996c
	addiu	$23,$23,1	# 269970
	slti	$15,$18,9	# 269974
	bnez	$15, .L0026982c	# 269978
	slt	$15,$23,$22	# 26997c
.L00269980:
	addiu	$14,$21,1	# 269980
	slti	$15,$14,5	# 269984
	bnez	$15, .L002699a4	# 269988
	nop	# 26998c
	slti	$14,$18,9	# 269990
	li	$15,-1	# 269994
	movn	$21,$15,$14	# 269998
	addiu	$14,$21,1	# 26999c
	slti	$15,$14,5	# 2699a0
.L002699a4:
	beqz	$15, .L002699b8	# 2699a4
	move	$21,$14	# 2699a8
	slti	$15,$18,9	# 2699ac
	bnez	$15, .L002697cc	# 2699b0
	lw	$13,36($29)	# 2699b4
.L002699b8:
	ld	$16,80($29)	# 2699b8
	ld	$17,88($29)	# 2699bc
	ld	$18,96($29)	# 2699c0
	ld	$19,104($29)	# 2699c4
	ld	$20,112($29)	# 2699c8
	ld	$21,120($29)	# 2699cc
	ld	$22,128($29)	# 2699d0
	ld	$23,136($29)	# 2699d4
	ld	$30,144($29)	# 2699d8
	ld	$31,152($29)	# 2699dc
	jr	$31	# 2699e0
	addiu	$29,$29,160	# 2699e4
.L002699e8:
	sll	$15,$17,0x1	# 2699e8
	addiu	$13,$13,14152	# 2699ec
	b	.L002698a4	# 2699f0
	addu	$15,$15,$13	# 2699f4
.L002699f8:
	move	$14,$0	# 2699f8
	move	$17,$0	# 2699fc
	lw	$13,32($29)	# 269a00
.L00269a04:
	srav	$15,$13,$17	# 269a04
	andi	$15,$15,0x1	# 269a08
	andi	$15,$15,0xff	# 269a0c
	beqzl	$15, .L00269a24	# 269a10
	addiu	$17,$17,1	# 269a14
	beq	$14, $19, .L00269a38	# 269a18
	addiu	$14,$14,1	# 269a1c
	addiu	$17,$17,1	# 269a20
.L00269a24:
	slti	$15,$17,7	# 269a24
	bnez	$15, .L00269a04	# 269a28
	lw	$13,32($29)	# 269a2c
	b	.L0026986c	# 269a30
	move	$5,$16	# 269a34
.L00269a38:
	lui	$13,%hi(D_00373788)	# 269a38
	sll	$15,$17,0x1	# 269a3c
	addiu	$13, $13, %lo(D_00373788)	# 269a40
	addu	$14,$15,$13	# 269a44
	lui	$13,0x37	# 269a48
	lhu	$20,0($14)	# 269a4c
	addiu	$13,$13,14200	# 269a50
	addu	$15,$15,$13	# 269a54
	b	.L00269868	# 269a58
	lh	$16,0($15)	# 269a5c
	.end func_00269658
	.size func_00269658, 1032

#   func_002958b0: Jiminy's journal menu setup: cover, main frame, mode positions, then the fade objects and menu
#     cursors on the sequence table (D_0035f3d4/D_0035f14c/D_0035f148/D_0035f210), 9 selector rows with two fade
#     objects each, cursor position restore and enabled buttons |= 0x3000.
#     Closest C: ~/re/kh2/tmp.w3949/best_002958b0_nsa.cpp (= best/002958b0_w3817_nsa.cpp, _nsa, 135 lines off):
#     pure register permutation; orig keeps hi(D_0035f148)/hi(D_0035f210) function-wide in s6/s7, ours per block.
#     No literal addresses: every call and global has a func_/D_ symbol.
	.set noreorder
	.set noat
	.set nomacro
