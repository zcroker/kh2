# Whole-function assembly (last step of the README match ladder, w3950 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_002a5590: Jiminy menu init: two fade objects and cursors (D_0035f3d4-1), the list (func_00288d80),
#     cursor/limit objects (D_0035f5f0), limit entry text into D_0035f5ec+31 (func_00192cc0 with D_00374ba8),
#     then list/scroll bar setup (func_0028af90 ... func_0028be78) and selector enable bits.
#     Closest C: ~/re/kh2/tmp.w3950/best_002a5590_g.cpp (= best/002a5590_w3945_g.cpp, _g, about 257 lines off):
#     the original reloads every global %hi with fresh t-regs (only hi(D_0035f5ec) in s3); ours keeps them in
#     saved registers and spills pg.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002a5590,"ax",@progbits
	.globl func_002a5590
	.type func_002a5590, @function
	.ent func_002a5590
func_002a5590:
	addiu	$29,$29,-128	# 2a5590
	sd	$31,120($29)	# 2a5594
	sd	$23,104($29)	# 2a5598
	sd	$30,112($29)	# 2a559c
	sd	$16,48($29)	# 2a55a0
	sd	$17,56($29)	# 2a55a4
	sd	$18,64($29)	# 2a55a8
	sd	$19,72($29)	# 2a55ac
	sd	$20,80($29)	# 2a55b0
	sd	$21,88($29)	# 2a55b4
	sd	$22,96($29)	# 2a55b8
	jal	func_00276348	# 2a55bc
	nop	# 2a55c0
	jal	func_002766d0	# 2a55c4
	move	$23,$2	# 2a55c8
	move	$30,$2	# 2a55cc
	jal	func_00276690	# 2a55d0
	li	$4,1	# 2a55d4
	move	$13,$0	# 2a55d8
	addiu	$11,$29,16	# 2a55dc
	li	$12,2	# 2a55e0
	sll	$15,$13,0x3	# 2a55e4
.L002a55e8:
	li	$14,3	# 2a55e8
	addu	$15,$15,$11	# 2a55ec
.L002a55f0:
	sh	$12,0($15)	# 2a55f0
	addiu	$14,$14,-1	# 2a55f4
	nop	# 2a55f8
	nop	# 2a55fc
	nop	# 2a5600
	bgez	$14, .L002a55f0	# 2a5604
	addiu	$15,$15,2	# 2a5608
	addiu	$13,$13,1	# 2a560c
	slti	$15,$13,2	# 2a5610
	bnez	$15, .L002a55e8	# 2a5614
	sll	$15,$13,0x3	# 2a5618
	lui	$14,%hi(D_0035f3d4)	# 2a561c
	addiu	$20,$30,1224	# 2a5620
	lw	$17, %lo(D_0035f3d4)($14)	# 2a5624
	addiu	$21,$30,3400	# 2a5628
	li	$22,1	# 2a562c
	jal	func_00276e78	# 2a5630
	lui	$19,%hi(D_0035f5ec)	# 2a5634
	addiu	$18,$17,-1	# 2a5638
	lui	$15,%hi(D_0035f14c)	# 2a563c
	lui	$14,%hi(D_0035f148)	# 2a5640
	lw	$6, %lo(D_0035f14c)($15)	# 2a5644
	li	$9,97	# 2a5648
	lw	$7, %lo(D_0035f148)($14)	# 2a564c
	li	$10,-1	# 2a5650
	lui	$15,%hi(D_0035f210)	# 2a5654
	move	$11,$0	# 2a5658
	lw	$8, %lo(D_0035f210)($15)	# 2a565c
	move	$5,$18	# 2a5660
	jal	func_0028d8c0	# 2a5664
	move	$4,$30	# 2a5668
	jal	func_00139620	# 2a566c
	move	$4,$30	# 2a5670
	lui	$14,0x6000	# 2a5674
	move	$4,$30	# 2a5678
	sw	$14,32($29)	# 2a567c
	jal	func_0028dcc0	# 2a5680
	move	$5,$23	# 2a5684
	lui	$15,%hi(D_0035f14c)	# 2a5688
	lui	$14,%hi(D_0035f148)	# 2a568c
	lw	$6, %lo(D_0035f14c)($15)	# 2a5690
	move	$5,$18	# 2a5694
	lw	$7, %lo(D_0035f148)($14)	# 2a5698
	li	$9,100	# 2a569c
	lui	$15,%hi(D_0035f210)	# 2a56a0
	li	$10,-1	# 2a56a4
	lw	$8, %lo(D_0035f210)($15)	# 2a56a8
	move	$11,$0	# 2a56ac
	move	$4,$20	# 2a56b0
	jal	func_0028d8c0	# 2a56b4
	addiu	$18,$30,3376	# 2a56b8
	lw	$14,32($29)	# 2a56bc
	move	$4,$20	# 2a56c0
	ori	$14,$14,0x8	# 2a56c4
	jal	func_00139620	# 2a56c8
	sw	$14,32($29)	# 2a56cc
	move	$4,$20	# 2a56d0
	jal	func_0028dcc0	# 2a56d4
	move	$5,$23	# 2a56d8
	lui	$15,%hi(D_0035f14c)	# 2a56dc
	lui	$14,%hi(D_0035f148)	# 2a56e0
	lw	$6, %lo(D_0035f14c)($15)	# 2a56e4
	addiu	$11,$29,24	# 2a56e8
	lw	$7, %lo(D_0035f148)($14)	# 2a56ec
	li	$9,-1	# 2a56f0
	lui	$15,%hi(D_0035f210)	# 2a56f4
	addiu	$10,$29,16	# 2a56f8
	lui	$14,%hi(D_0035f200)	# 2a56fc
	lw	$8, %lo(D_0035f210)($15)	# 2a5700
	lw	$4, %lo(D_0035f200)($14)	# 2a5704
	jal	func_00288d80	# 2a5708
	move	$5,$0	# 2a570c
	lui	$15,%hi(D_0035f200)	# 2a5710
	move	$5,$0	# 2a5714
	jal	func_002891b8	# 2a5718
	lw	$4, %lo(D_0035f200)($15)	# 2a571c
	move	$16,$2	# 2a5720
	jal	func_00139620	# 2a5724
	move	$4,$2	# 2a5728
	move	$4,$16	# 2a572c
	jal	func_0028dcc0	# 2a5730
	move	$5,$30	# 2a5734
	li	$14,3	# 2a5738
	move	$4,$16	# 2a573c
	sw	$14,428($16)	# 2a5740
	lw	$15,32($29)	# 2a5744
	jal	func_001395f8	# 2a5748
	sw	$15,420($16)	# 2a574c
	lui	$15,%hi(func_002a63a0)	# 2a5750
	lui	$14,%hi(D_0035f14c)	# 2a5754
	addiu	$15, $15, %lo(func_002a63a0)	# 2a5758
	li	$9,99	# 2a575c
	sw	$15,436($16)	# 2a5760
	li	$10,-1	# 2a5764
	li	$11,-1	# 2a5768
	move	$5,$17	# 2a576c
	lw	$6, %lo(D_0035f14c)($14)	# 2a5770
	lui	$15,%hi(D_0035f148)	# 2a5774
	lw	$7, %lo(D_0035f148)($15)	# 2a5778
	move	$4,$18	# 2a577c
	lui	$14,%hi(D_0035f210)	# 2a5780
	sw	$0,0($29)	# 2a5784
	lw	$8, %lo(D_0035f210)($14)	# 2a5788
	jal	func_0028d980	# 2a578c
	addiu	$17,$17,1	# 2a5790
	jal	func_00139620	# 2a5794
	move	$4,$18	# 2a5798
	move	$4,$18	# 2a579c
	jal	func_0028dcc0	# 2a57a0
	move	$5,$23	# 2a57a4
	li	$15,3	# 2a57a8
	move	$4,$18	# 2a57ac
	sw	$15,428($18)	# 2a57b0
	lw	$14,32($29)	# 2a57b4
	jal	func_001395f8	# 2a57b8
	sw	$14,420($18)	# 2a57bc
	lui	$15,%hi(D_0035f5f0)	# 2a57c0
	lui	$14,%hi(D_0035f210)	# 2a57c4
	lw	$16, %lo(D_0035f5f0)($15)	# 2a57c8
	li	$9,2	# 2a57cc
	lw	$8, %lo(D_0035f210)($14)	# 2a57d0
	li	$10,-1	# 2a57d4
	lui	$15,%hi(D_0035f148)	# 2a57d8
	sw	$0,0($29)	# 2a57dc
	lw	$7, %lo(D_0035f148)($15)	# 2a57e0
	li	$11,-1	# 2a57e4
	move	$5,$17	# 2a57e8
	move	$4,$16	# 2a57ec
	lui	$15,%hi(D_0035f14c)	# 2a57f0
	jal	func_0028d980	# 2a57f4
	lw	$6, %lo(D_0035f14c)($15)	# 2a57f8
	jal	func_00139620	# 2a57fc
	move	$4,$30	# 2a5800
	move	$5,$18	# 2a5804
	jal	func_0028dcc0	# 2a5808
	move	$4,$16	# 2a580c
	jal	func_0023aa18	# 2a5810
	move	$4,$21	# 2a5814
	move	$17,$2	# 2a5818
	jal	func_0023aa38	# 2a581c
	move	$4,$21	# 2a5820
	move	$5,$17	# 2a5824
	move	$6,$2	# 2a5828
	jal	func_00138c68	# 2a582c
	move	$4,$16	# 2a5830
	li	$14,3	# 2a5834
	li	$4,37	# 2a5838
	sw	$14,428($16)	# 2a583c
	lw	$15,32($29)	# 2a5840
	sw	$22,432($16)	# 2a5844
	sw	$15,420($16)	# 2a5848
	lw	$15, %lo(D_0035f5ec)($19)	# 2a584c
	addiu	$15,$15,31	# 2a5850
	jal	func_00276638	# 2a5854
	sw	$15,408($16)	# 2a5858
	lw	$15, %lo(D_0035f5ec)($19)	# 2a585c
	addu	$15,$15,$2	# 2a5860
	jal	func_002a6368	# 2a5864
	lb	$4,6($15)	# 2a5868
	lw	$14, %lo(D_0035f5ec)($19)	# 2a586c
	move	$17,$2	# 2a5870
	lhu	$15,4($2)	# 2a5874
	addiu	$4,$30,24	# 2a5878
	sh	$15,4($14)	# 2a587c
	jal	func_0023aa78	# 2a5880
	lw	$16, %lo(D_0035f5ec)($19)	# 2a5884
	sb	$2,2($16)	# 2a5888
	lhu	$4,4($17)	# 2a588c
	jal	func_00192048	# 2a5890
	lw	$16, %lo(D_0035f5ec)($19)	# 2a5894
	jal	func_00192b80	# 2a5898
	move	$4,$2	# 2a589c
	sb	$2,1($16)	# 2a58a0
	jal	func_00192048	# 2a58a4
	lhu	$4,2($17)	# 2a58a8
	sw	$2,408($18)	# 2a58ac
	jal	func_001d44d8	# 2a58b0
	lhu	$4,0($17)	# 2a58b4
	jal	func_001d4550	# 2a58b8
	move	$4,$2	# 2a58bc
	lw	$4, %lo(D_0035f5ec)($19)	# 2a58c0
	lui	$5,%hi(D_00374ba8)	# 2a58c4
	move	$6,$2	# 2a58c8
	addiu	$5, $5, %lo(D_00374ba8)	# 2a58cc
	jal	func_00192cc0	# 2a58d0
	addiu	$4,$4,31	# 2a58d4
	jal	func_00192b30	# 2a58d8
	move	$4,$2	# 2a58dc
	move	$16,$2	# 2a58e0
	jal	func_00192048	# 2a58e4
	li	$4,19206	# 2a58e8
	lw	$5, %lo(D_0035f5ec)($19)	# 2a58ec
	move	$4,$2	# 2a58f0
	addu	$5,$5,$16	# 2a58f4
	jal	func_00192c90	# 2a58f8
	addiu	$5,$5,31	# 2a58fc
	lui	$15,%hi(D_0035f200)	# 2a5900
	lw	$14, %lo(D_0035f5ec)($19)	# 2a5904
	lw	$4, %lo(D_0035f200)($15)	# 2a5908
	lb	$15,1($14)	# 2a590c
	addiu	$13,$15,-8	# 2a5910
	slti	$15,$15,10	# 2a5914
	movz	$22,$13,$15	# 2a5918
	jal	func_0028af90	# 2a591c
	move	$5,$22	# 2a5920
	lui	$14,%hi(D_0035f200)	# 2a5924
	move	$6,$0	# 2a5928
	lw	$4, %lo(D_0035f200)($14)	# 2a592c
	li	$7,-1	# 2a5930
	li	$8,-1	# 2a5934
	jal	func_002891f0	# 2a5938
	move	$5,$0	# 2a593c
	lui	$15,%hi(D_0035f200)	# 2a5940
	move	$5,$0	# 2a5944
	jal	func_0028afd0	# 2a5948
	lw	$4, %lo(D_0035f200)($15)	# 2a594c
	lui	$15,%hi(D_0035f210)	# 2a5950
	lui	$14,%hi(D_0035f3d4)	# 2a5954
	lw	$4, %lo(D_0035f210)($15)	# 2a5958
	jal	func_0023f1b0	# 2a595c
	lw	$18, %lo(D_0035f3d4)($14)	# 2a5960
	lui	$14,%hi(D_0035f14c)	# 2a5964
	move	$4,$2	# 2a5968
	jal	func_0023c4b8	# 2a596c
	lw	$5, %lo(D_0035f14c)($14)	# 2a5970
	lui	$15,%hi(D_0035f210)	# 2a5974
	move	$17,$2	# 2a5978
	jal	func_0023f1b0	# 2a597c
	lw	$4, %lo(D_0035f210)($15)	# 2a5980
	lui	$14,%hi(D_0035f148)	# 2a5984
	lw	$4,40($2)	# 2a5988
	jal	func_00236ca8	# 2a598c
	lw	$5, %lo(D_0035f148)($14)	# 2a5990
	jal	func_00276678	# 2a5994
	move	$16,$2	# 2a5998
	lw	$15, %lo(D_0035f5ec)($19)	# 2a599c
	lui	$14,%hi(D_0035f214)	# 2a59a0
	lw	$4, %lo(D_0035f214)($14)	# 2a59a4
	move	$7,$16	# 2a59a8
	lb	$9,1($15)	# 2a59ac
	move	$8,$2	# 2a59b0
	move	$6,$17	# 2a59b4
	move	$11,$20	# 2a59b8
	sw	$0,0($29)	# 2a59bc
	li	$10,9	# 2a59c0
	jal	func_0028bae0	# 2a59c4
	move	$5,$18	# 2a59c8
	lui	$15,%hi(D_0035f214)	# 2a59cc
	move	$5,$0	# 2a59d0
	jal	func_0028be78	# 2a59d4
	lw	$4, %lo(D_0035f214)($15)	# 2a59d8
	lui	$14,%hi(D_0035f200)	# 2a59dc
	jal	func_0028af88	# 2a59e0
	lw	$4, %lo(D_0035f200)($14)	# 2a59e4
	jal	func_002a6290	# 2a59e8
	move	$16,$2	# 2a59ec
	slti	$2,$2,2	# 2a59f0
	ori	$15,$16,0xc000	# 2a59f4
	movz	$16,$15,$2	# 2a59f8
	li	$14,-17	# 2a59fc
	lui	$15,%hi(D_0035f200)	# 2a5a00
	and	$16,$16,$14	# 2a5a04
	lw	$4, %lo(D_0035f200)($15)	# 2a5a08
	jal	func_0028af18	# 2a5a0c
	move	$5,$16	# 2a5a10
	slti	$5,$22,2	# 2a5a14
	bnez	$5, .L002a5a40	# 2a5a18
	lui	$14,%hi(D_0035f200)	# 2a5a1c
	li	$5,1	# 2a5a20
	jal	func_0028b218	# 2a5a24
	lw	$4, %lo(D_0035f200)($14)	# 2a5a28
	lui	$15,%hi(D_0035f200)	# 2a5a2c
	li	$5,9	# 2a5a30
	jal	func_0028b248	# 2a5a34
	lw	$4, %lo(D_0035f200)($15)	# 2a5a38
	lui	$14,%hi(D_0035f200)	# 2a5a3c
.L002a5a40:
	move	$5,$0	# 2a5a40
	jal	func_0028b1e8	# 2a5a44
	lw	$4, %lo(D_0035f200)($14)	# 2a5a48
	jal	func_002a65a0	# 2a5a4c
	nop	# 2a5a50
	jal	func_00287cc0	# 2a5a54
	move	$4,$0	# 2a5a58
	ld	$16,48($29)	# 2a5a5c
	ld	$17,56($29)	# 2a5a60
	ld	$18,64($29)	# 2a5a64
	ld	$19,72($29)	# 2a5a68
	ld	$20,80($29)	# 2a5a6c
	ld	$21,88($29)	# 2a5a70
	ld	$22,96($29)	# 2a5a74
	ld	$23,104($29)	# 2a5a78
	ld	$30,112($29)	# 2a5a7c
	ld	$31,120($29)	# 2a5a80
	jr	$31	# 2a5a84
	addiu	$29,$29,128	# 2a5a88
	.end func_002a5590
	.size func_002a5590, 1276

