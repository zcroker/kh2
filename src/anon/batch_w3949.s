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
#     Closest C: ~/re/kh2/tmp.w3949/best_002958b0_nsa.cpp (= coord best/002958b0_w3817_nsa.cpp, _nsa, 135 lines off):
#     pure register permutation; orig keeps hi(D_0035f148)/hi(D_0035f210) function-wide in s6/s7, ours per block.
#     No literal addresses: every call and global has a func_/D_ symbol.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002958b0,"ax",@progbits
	.globl func_002958b0
	.type func_002958b0, @function
	.ent func_002958b0
func_002958b0:
	addiu	$29,$29,-144	# 2958b0
	sd	$31,136($29)	# 2958b4
	sd	$30,128($29)	# 2958b8
	sd	$16,64($29)	# 2958bc
	sd	$17,72($29)	# 2958c0
	sd	$18,80($29)	# 2958c4
	sd	$19,88($29)	# 2958c8
	sd	$20,96($29)	# 2958cc
	sd	$21,104($29)	# 2958d0
	sd	$22,112($29)	# 2958d4
	sd	$23,120($29)	# 2958d8
	jal	func_00276348	# 2958dc
	move	$30,$0	# 2958e0
	jal	func_002766d0	# 2958e4
	sw	$2,44($29)	# 2958e8
	sw	$2,48($29)	# 2958ec
	jal	func_00276588	# 2958f0
	li	$4,1	# 2958f4
	lui	$15,%hi(D_0035f200)	# 2958f8
	jal	func_00288e88	# 2958fc
	lw	$4, %lo(D_0035f200)($15)	# 295900
	jal	func_002969e0	# 295904
	nop	# 295908
	jal	func_00275a80	# 29590c
	nop	# 295910
	jal	func_00287bc0	# 295914
	nop	# 295918
	addiu	$6,$29,36	# 29591c
	move	$4,$2	# 295920
	jal	func_00276088	# 295924
	addiu	$5,$29,32	# 295928
	lw	$4,32($29)	# 29592c
	jal	func_00275f68	# 295930
	lw	$5,36($29)	# 295934
	jal	func_00276568	# 295938
	nop	# 29593c
	lb	$4,0($2)	# 295940
	jal	func_00295430	# 295944
	move	$5,$0	# 295948
	jal	func_00275e68	# 29594c
	move	$4,$2	# 295950
	addiu	$12,$29,16	# 295954
	li	$13,3	# 295958
	sll	$15,$30,0x3	# 29595c
.L00295960:
	li	$14,3	# 295960
	addu	$15,$15,$12	# 295964
.L00295968:
	sh	$13,0($15)	# 295968
	addiu	$14,$14,-1	# 29596c
	nop	# 295970
	nop	# 295974
	nop	# 295978
	bgez	$14, .L00295968	# 29597c
	addiu	$15,$15,2	# 295980
	addiu	$30,$30,1	# 295984
	slti	$15,$30,2	# 295988
	bnez	$15, .L00295960	# 29598c
	sll	$15,$30,0x3	# 295990
	lui	$14,%hi(D_0035f3d4)	# 295994
	lw	$4,48($29)	# 295998
	lw	$15, %lo(D_0035f3d4)($14)	# 29599c
	lui	$17,%hi(D_0035f14c)	# 2959a0
	lw	$6, %lo(D_0035f14c)($17)	# 2959a4
	li	$9,159	# 2959a8
	addiu	$18,$15,-1	# 2959ac
	lui	$14,%hi(D_0035f210)	# 2959b0
	lui	$15,%hi(D_0035f148)	# 2959b4
	lw	$8, %lo(D_0035f210)($14)	# 2959b8
	lw	$7, %lo(D_0035f148)($15)	# 2959bc
	li	$10,-1	# 2959c0
	move	$11,$0	# 2959c4
	jal	func_0028d8c0	# 2959c8
	move	$5,$18	# 2959cc
	lui	$22,%hi(D_0035f148)	# 2959d0
	lw	$4,48($29)	# 2959d4
	lui	$23,%hi(D_0035f210)	# 2959d8
	move	$19,$17	# 2959dc
	move	$30,$0	# 2959e0
	jal	func_00139620	# 2959e4
	addiu	$16,$4,816	# 2959e8
	lw	$4,48($29)	# 2959ec
	lw	$5,44($29)	# 2959f0
	jal	func_0028dcc0	# 2959f4
	addiu	$20,$4,1632	# 2959f8
	lw	$15,48($29)	# 2959fc
	lui	$14,%hi(D_0035f148)	# 295a00
	lw	$7, %lo(D_0035f148)($14)	# 295a04
	li	$9,169	# 295a08
	addiu	$21,$15,2068	# 295a0c
	lw	$6, %lo(D_0035f14c)($17)	# 295a10
	lui	$15,%hi(D_0035f210)	# 295a14
	li	$10,-1	# 295a18
	lw	$8, %lo(D_0035f210)($15)	# 295a1c
	move	$11,$0	# 295a20
	move	$5,$18	# 295a24
	jal	func_0028d8c0	# 295a28
	move	$4,$16	# 295a2c
	jal	func_00139620	# 295a30
	move	$4,$16	# 295a34
	lw	$14,48($29)	# 295a38
	move	$4,$16	# 295a3c
	lw	$5,44($29)	# 295a40
	jal	func_0028dcc0	# 295a44
	addiu	$16,$14,2504	# 295a48
	lw	$15,48($29)	# 295a4c
	lui	$14,%hi(D_0035f148)	# 295a50
	sw	$0,0($29)	# 295a54
	li	$9,167	# 295a58
	addiu	$15,$15,2940	# 295a5c
	lw	$7, %lo(D_0035f148)($14)	# 295a60
	sw	$15,52($29)	# 295a64
	li	$10,-1	# 295a68
	lw	$6, %lo(D_0035f14c)($17)	# 295a6c
	li	$11,-1	# 295a70
	lui	$15,%hi(D_0035f210)	# 295a74
	move	$5,$18	# 295a78
	lw	$8, %lo(D_0035f210)($15)	# 295a7c
	jal	func_0028d980	# 295a80
	move	$4,$20	# 295a84
	jal	func_001395f8	# 295a88
	move	$4,$20	# 295a8c
	lw	$5,44($29)	# 295a90
	jal	func_0028dcc0	# 295a94
	move	$4,$20	# 295a98
	sw	$0,0($29)	# 295a9c
	li	$9,3	# 295aa0
	lw	$7, %lo(D_0035f148)($22)	# 295aa4
	li	$10,-1	# 295aa8
	lw	$6, %lo(D_0035f14c)($17)	# 295aac
	li	$11,-1	# 295ab0
	lw	$8, %lo(D_0035f210)($23)	# 295ab4
	move	$5,$18	# 295ab8
	jal	func_0028d980	# 295abc
	move	$4,$21	# 295ac0
	jal	func_00139620	# 295ac4
	move	$4,$21	# 295ac8
	move	$4,$21	# 295acc
	jal	func_0028dcc0	# 295ad0
	move	$5,$20	# 295ad4
	lw	$20,48($29)	# 295ad8
	li	$14,2	# 295adc
	li	$9,168	# 295ae0
	li	$10,-1	# 295ae4
	sw	$14,432($21)	# 295ae8
	li	$11,-1	# 295aec
	move	$5,$18	# 295af0
	move	$4,$16	# 295af4
	sw	$0,0($29)	# 295af8
	move	$21,$0	# 295afc
	lw	$7, %lo(D_0035f148)($22)	# 295b00
	lw	$6, %lo(D_0035f14c)($17)	# 295b04
	jal	func_0028d980	# 295b08
	lw	$8, %lo(D_0035f210)($23)	# 295b0c
	jal	func_001395f8	# 295b10
	move	$4,$16	# 295b14
	lw	$5,44($29)	# 295b18
	jal	func_0028dcc0	# 295b1c
	move	$4,$16	# 295b20
	sw	$0,0($29)	# 295b24
	move	$5,$18	# 295b28
	lw	$7, %lo(D_0035f148)($22)	# 295b2c
	li	$9,3	# 295b30
	lw	$6, %lo(D_0035f14c)($17)	# 295b34
	li	$10,-1	# 295b38
	lw	$8, %lo(D_0035f210)($23)	# 295b3c
	li	$11,-1	# 295b40
	jal	func_0028d980	# 295b44
	lw	$4,52($29)	# 295b48
	jal	func_00139620	# 295b4c
	lw	$4,52($29)	# 295b50
	lw	$4,52($29)	# 295b54
	jal	func_0028dcc0	# 295b58
	move	$5,$16	# 295b5c
	lw	$15,52($29)	# 295b60
	li	$14,2	# 295b64
	sw	$14,432($15)	# 295b68
	lw	$15,48($29)	# 295b6c
	jal	func_0023aa78	# 295b70
	addiu	$4,$15,24	# 295b74
	lui	$14,%hi(D_0035f3d4)	# 295b78
	sw	$2,40($29)	# 295b7c
	lw	$18, %lo(D_0035f3d4)($14)	# 295b80
	addiu	$15,$18,2	# 295b84
	sw	$15,56($29)	# 295b88
	addiu	$18,$18,1	# 295b8c
	lui	$14,%hi(D_0035f200)	# 295b90
.L00295b94:
	lw	$7, %lo(D_0035f148)($22)	# 295b94
	lw	$4, %lo(D_0035f200)($14)	# 295b98
	li	$9,-1	# 295b9c
	lw	$8, %lo(D_0035f210)($23)	# 295ba0
	addiu	$10,$29,16	# 295ba4
	lw	$6,-3764($19)	# 295ba8
	addiu	$11,$29,24	# 295bac
	move	$5,$30	# 295bb0
	jal	func_00288d80	# 295bb4
	addiu	$17,$20,30360	# 295bb8
	lui	$15,%hi(D_0035f200)	# 295bbc
	move	$5,$30	# 295bc0
	lw	$4, %lo(D_0035f200)($15)	# 295bc4
	jal	func_002891b8	# 295bc8
	addiu	$30,$30,1	# 295bcc
	move	$16,$2	# 295bd0
	jal	func_00139620	# 295bd4
	move	$4,$2	# 295bd8
	lw	$5,48($29)	# 295bdc
	jal	func_0028dcc0	# 295be0
	move	$4,$16	# 295be4
	move	$6,$21	# 295be8
	move	$4,$16	# 295bec
	jal	func_00138c68	# 295bf0
	move	$5,$0	# 295bf4
	lw	$14,40($29)	# 295bf8
	li	$9,3	# 295bfc
	lw	$6,-3764($19)	# 295c00
	li	$10,-1	# 295c04
	lw	$7, %lo(D_0035f148)($22)	# 295c08
	addu	$21,$21,$14	# 295c0c
	lw	$8, %lo(D_0035f210)($23)	# 295c10
	move	$11,$0	# 295c14
	move	$4,$17	# 295c18
	jal	func_0028d8c0	# 295c1c
	move	$5,$18	# 295c20
	move	$4,$17	# 295c24
	jal	func_0028dcc0	# 295c28
	move	$5,$16	# 295c2c
	li	$15,0xa998	# 295c30
	lw	$6,-3764($19)	# 295c34
	addu	$17,$20,$15	# 295c38
	lw	$7, %lo(D_0035f148)($22)	# 295c3c
	lw	$8, %lo(D_0035f210)($23)	# 295c40
	li	$9,3	# 295c44
	lw	$5,56($29)	# 295c48
	li	$10,-1	# 295c4c
	move	$11,$0	# 295c50
	jal	func_0028d8c0	# 295c54
	move	$4,$17	# 295c58
	addiu	$20,$20,408	# 295c5c
	move	$4,$17	# 295c60
	jal	func_0028dcc0	# 295c64
	move	$5,$16	# 295c68
	slti	$15,$30,9	# 295c6c
	bnez	$15, .L00295b94	# 295c70
	lui	$14,%hi(D_0035f200)	# 295c74
	move	$4,$0	# 295c78
	jal	func_00296b80	# 295c7c
	lui	$16,%hi(D_0035f200)	# 295c80
	jal	func_00287bc0	# 295c84
	nop	# 295c88
	jal	func_00276608	# 295c8c
	move	$4,$2	# 295c90
	lw	$4, %lo(D_0035f200)($16)	# 295c94
	li	$7,-1	# 295c98
	li	$8,-1	# 295c9c
	move	$5,$2	# 295ca0
	jal	func_002891f0	# 295ca4
	move	$6,$0	# 295ca8
	jal	func_00287bc0	# 295cac
	nop	# 295cb0
	move	$6,$0	# 295cb4
	move	$4,$2	# 295cb8
	jal	func_002765e8	# 295cbc
	move	$5,$0	# 295cc0
	jal	func_002960d0	# 295cc4
	nop	# 295cc8
	jal	func_00295d28	# 295ccc
	nop	# 295cd0
	jal	func_0028af88	# 295cd4
	lw	$4, %lo(D_0035f200)($16)	# 295cd8
	lw	$4, %lo(D_0035f200)($16)	# 295cdc
	jal	func_0028af18	# 295ce0
	ori	$5,$2,0x3000	# 295ce4
	jal	_ZN2Tz8JmReport10DrawUpdateEPNS_6SelectEii	# 295ce8
	nop	# 295cec
	jal	func_00287cc0	# 295cf0
	move	$4,$0	# 295cf4
	ld	$16,64($29)	# 295cf8
	ld	$17,72($29)	# 295cfc
	ld	$18,80($29)	# 295d00
	ld	$19,88($29)	# 295d04
	ld	$20,96($29)	# 295d08
	ld	$21,104($29)	# 295d0c
	ld	$22,112($29)	# 295d10
	ld	$23,120($29)	# 295d14
	ld	$30,128($29)	# 295d18
	ld	$31,136($29)	# 295d1c
	jr	$31	# 295d20
	addiu	$29,$29,144	# 295d24
	.end func_002958b0
	.size func_002958b0, 1144
