# Whole-function assembly (last step of the README match ladder, w3950 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_002a5590: Jiminy menu init: two fade objects and cursors (D_0035f3d4-1), the list (func_00288d80),
#     cursor/limit objects (D_0035f5f0), limit entry text into D_0035f5ec+31 (func_00192cc0 with D_00374ba8),
#     then list/scroll bar setup (func_0028af90 ... func_0028be78) and selector enable bits.
#     Closest C: ~/re/kh2/tmp.w3950/best_002a5590_g.cpp (= coord best/002a5590_w3945_g.cpp, _g, about 257 lines off):
#     the original reloads every global %hi with fresh t-regs (only hi(D_0035f5ec) in s3); ours keeps them in
#     saved registers and spills pg.
#   func_002a3ba8: builds the 9-row list objects under D_0035f5e8 (+0x7974/+0x88c8 per 436-byte row), optional
#     header (func_00276c18, text via func_00192cc0), then the 9 x 8 grid of icons.
#     Closest C: ~/re/kh2/tmp.w3950/best_002a3ba8_nsamam.cpp (= coord best/002a3ba8_w3945_nsa.cpp, about 318 lines off):
#     s-register choice for the global %hi parts and the live-range copies (move s3,s2; move s2,s4).
#     No symbol, written as a literal lui/addiu value: 0x00374b90 (format string, func_002a3ba8 at 0x2a3fb8).
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

	.section .text.func_002a3ba8,"ax",@progbits
	.globl func_002a3ba8
	.type func_002a3ba8, @function
	.ent func_002a3ba8
func_002a3ba8:
	addiu	$29,$29,-112	# 2a3ba8
	sd	$31,104($29)	# 2a3bac
	sd	$16,32($29)	# 2a3bb0
	sd	$18,48($29)	# 2a3bb4
	sd	$19,56($29)	# 2a3bb8
	sd	$20,64($29)	# 2a3bbc
	lui	$18,%hi(D_0035f148)	# 2a3bc0
	sd	$21,72($29)	# 2a3bc4
	lui	$19,%hi(D_0035f14c)	# 2a3bc8
	sd	$22,80($29)	# 2a3bcc
	lui	$20,%hi(D_0035f210)	# 2a3bd0
	sd	$23,88($29)	# 2a3bd4
	lui	$21,%hi(D_0035f5e8)	# 2a3bd8
	sd	$30,96($29)	# 2a3bdc
	sd	$17,40($29)	# 2a3be0
	jal	func_002766d0	# 2a3be4
	move	$22,$0	# 2a3be8
	lui	$15,%hi(D_0035f3d4)	# 2a3bec
	lw	$14, %lo(D_0035f5e8)($21)	# 2a3bf0
	lw	$15, %lo(D_0035f3d4)($15)	# 2a3bf4
	move	$4,$0	# 2a3bf8
	sw	$2,20($29)	# 2a3bfc
	addiu	$30,$14,30656	# 2a3c00
	jal	func_00276c38	# 2a3c04
	sw	$15,16($29)	# 2a3c08
	sw	$0,0($29)	# 2a3c0c
	move	$9,$2	# 2a3c10
	lw	$5,16($29)	# 2a3c14
	li	$10,-1	# 2a3c18
	lw	$7, %lo(D_0035f148)($18)	# 2a3c1c
	li	$11,-1	# 2a3c20
	lw	$8, %lo(D_0035f210)($20)	# 2a3c24
	move	$4,$30	# 2a3c28
	jal	func_0028d980	# 2a3c2c
	lw	$6, %lo(D_0035f14c)($19)	# 2a3c30
	move	$19,$18	# 2a3c34
	lw	$13,20($29)	# 2a3c38
	move	$4,$30	# 2a3c3c
	move	$18,$20	# 2a3c40
	addiu	$16,$13,24	# 2a3c44
	jal	func_00139620	# 2a3c48
	move	$20,$0	# 2a3c4c
	lui	$14,0x6000	# 2a3c50
	lw	$5,20($29)	# 2a3c54
	sw	$14,24($29)	# 2a3c58
	jal	func_0028dcc0	# 2a3c5c
	move	$4,$30	# 2a3c60
	jal	func_001395f8	# 2a3c64
	move	$4,$30	# 2a3c68
	jal	func_0023aa18	# 2a3c6c
	move	$4,$16	# 2a3c70
	move	$23,$2	# 2a3c74
	jal	func_0023aa38	# 2a3c78
	move	$4,$16	# 2a3c7c
	move	$4,$30	# 2a3c80
	move	$5,$23	# 2a3c84
	jal	func_00138c68	# 2a3c88
	move	$6,$2	# 2a3c8c
	lw	$15,16($29)	# 2a3c90
	li	$14,0x982c	# 2a3c94
	move	$5,$0	# 2a3c98
	li	$6,32	# 2a3c9c
	addiu	$15,$15,1	# 2a3ca0
	sw	$15,28($29)	# 2a3ca4
	li	$15,2	# 2a3ca8
	sw	$15,432($30)	# 2a3cac
	lw	$13,24($29)	# 2a3cb0
	lw	$15, %lo(D_0035f5e8)($21)	# 2a3cb4
	ori	$13,$13,0x8	# 2a3cb8
	sw	$13,24($29)	# 2a3cbc
	addu	$15,$15,$14	# 2a3cc0
	sw	$15,408($30)	# 2a3cc4
	lw	$4, %lo(D_0035f5e8)($21)	# 2a3cc8
	jal	func_002fde18	# 2a3ccc
	addu	$4,$4,$14	# 2a3cd0
	lui	$14,%hi(D_0035f5e8)	# 2a3cd4
.L002a3cd8:
	sw	$0,0($29)	# 2a3cd8
	lw	$16, %lo(D_0035f5e8)($14)	# 2a3cdc
	lui	$15,%hi(D_0035f14c)	# 2a3ce0
	lw	$6, %lo(D_0035f14c)($15)	# 2a3ce4
	li	$9,72	# 2a3ce8
	addu	$16,$16,$22	# 2a3cec
	lw	$7,-3768($19)	# 2a3cf0
	lw	$8,-3568($18)	# 2a3cf4
	addiu	$30,$16,31092	# 2a3cf8
	lw	$5,16($29)	# 2a3cfc
	li	$10,-1	# 2a3d00
	li	$11,-1	# 2a3d04
	jal	func_0028d980	# 2a3d08
	move	$4,$30	# 2a3d0c
	addiu	$16,$16,31116	# 2a3d10
	jal	func_00139620	# 2a3d14
	move	$4,$30	# 2a3d18
	lw	$5,20($29)	# 2a3d1c
	jal	func_0028dcc0	# 2a3d20
	move	$4,$30	# 2a3d24
	jal	func_0023aa78	# 2a3d28
	move	$4,$16	# 2a3d2c
	move	$4,$16	# 2a3d30
	jal	func_0023aa18	# 2a3d34
	move	$21,$2	# 2a3d38
	move	$4,$16	# 2a3d3c
	jal	func_0023aa38	# 2a3d40
	move	$23,$2	# 2a3d44
	mult	$6,$20,$21	# 2a3d48
	move	$16,$2	# 2a3d4c
	move	$4,$30	# 2a3d50
	jal	func_00138c68	# 2a3d54
	move	$5,$0	# 2a3d58
	li	$13,3	# 2a3d5c
	move	$4,$30	# 2a3d60
	sw	$13,428($30)	# 2a3d64
	lw	$14,24($29)	# 2a3d68
	jal	func_001395f8	# 2a3d6c
	sw	$14,420($30)	# 2a3d70
	move	$4,$30	# 2a3d74
	jal	func_00138c10	# 2a3d78
	li	$5,2	# 2a3d7c
	lui	$13,%hi(D_0035f5e8)	# 2a3d80
	sw	$0,0($29)	# 2a3d84
	lw	$15, %lo(D_0035f5e8)($13)	# 2a3d88
	li	$14,0x88c8	# 2a3d8c
	lw	$7,-3768($19)	# 2a3d90
	li	$9,2	# 2a3d94
	addu	$15,$15,$22	# 2a3d98
	lw	$8,-3568($18)	# 2a3d9c
	addu	$30,$15,$14	# 2a3da0
	lw	$5,16($29)	# 2a3da4
	lui	$15,%hi(D_0035f14c)	# 2a3da8
	li	$10,-1	# 2a3dac
	lw	$6, %lo(D_0035f14c)($15)	# 2a3db0
	li	$11,-1	# 2a3db4
	jal	func_0028d980	# 2a3db8
	move	$4,$30	# 2a3dbc
	jal	func_00139620	# 2a3dc0
	move	$4,$30	# 2a3dc4
	lui	$13,%hi(D_0035f5e8)	# 2a3dc8
	move	$4,$30	# 2a3dcc
	lw	$5, %lo(D_0035f5e8)($13)	# 2a3dd0
	addu	$5,$5,$22	# 2a3dd4
	jal	func_0028dcc0	# 2a3dd8
	addiu	$5,$5,31092	# 2a3ddc
	move	$6,$16	# 2a3de0
	move	$4,$30	# 2a3de4
	move	$5,$23	# 2a3de8
	jal	func_00138c68	# 2a3dec
	li	$16,408	# 2a3df0
	mult	$16,$20,$16	# 2a3df4
	lw	$14,24($29)	# 2a3df8
	li	$15,3	# 2a3dfc
	lui	$13,%hi(D_0035f14c)	# 2a3e00
	li	$9,2	# 2a3e04
	sw	$15,428($30)	# 2a3e08
	li	$10,-1	# 2a3e0c
	sw	$14,420($30)	# 2a3e10
	move	$11,$0	# 2a3e14
	li	$15,0xa998	# 2a3e18
	addiu	$20,$20,1	# 2a3e1c
	lw	$14,20($29)	# 2a3e20
	lw	$5,28($29)	# 2a3e24
	addu	$16,$14,$16	# 2a3e28
	lw	$6, %lo(D_0035f14c)($13)	# 2a3e2c
	addu	$16,$16,$15	# 2a3e30
	lw	$7,-3768($19)	# 2a3e34
	lw	$8,-3568($18)	# 2a3e38
	jal	func_0028d8c0	# 2a3e3c
	move	$4,$16	# 2a3e40
	lui	$15,%hi(D_0035f5e8)	# 2a3e44
	move	$4,$16	# 2a3e48
	lw	$5, %lo(D_0035f5e8)($15)	# 2a3e4c
	addu	$5,$5,$22	# 2a3e50
	addiu	$5,$5,31092	# 2a3e54
	jal	func_0028dcc0	# 2a3e58
	addiu	$22,$22,436	# 2a3e5c
	slti	$15,$20,9	# 2a3e60
	bnez	$15, .L002a3cd8	# 2a3e64
	lui	$14,%hi(D_0035f5e8)	# 2a3e68
	jal	func_00276c18	# 2a3e6c
	nop	# 2a3e70
	beqz	$2, .L002a3fd4	# 2a3e74
	lui	$13,%hi(D_0035f5e8)	# 2a3e78
	sw	$0,0($29)	# 2a3e7c
	lw	$16, %lo(D_0035f5e8)($13)	# 2a3e80
	lui	$19,%hi(D_0035f14c)	# 2a3e84
	lui	$20,%hi(D_0035f148)	# 2a3e88
	lw	$6, %lo(D_0035f14c)($19)	# 2a3e8c
	lui	$21,%hi(D_0035f210)	# 2a3e90
	lw	$7, %lo(D_0035f148)($20)	# 2a3e94
	lw	$8, %lo(D_0035f210)($21)	# 2a3e98
	addiu	$30,$16,29784	# 2a3e9c
	lw	$5,16($29)	# 2a3ea0
	li	$9,60	# 2a3ea4
	li	$10,-1	# 2a3ea8
	li	$11,-1	# 2a3eac
	move	$4,$30	# 2a3eb0
	jal	func_0028d980	# 2a3eb4
	addiu	$16,$16,29808	# 2a3eb8
	li	$18,0x981c	# 2a3ebc
	jal	func_00139620	# 2a3ec0
	move	$4,$30	# 2a3ec4
	lw	$5,20($29)	# 2a3ec8
	jal	func_0028dcc0	# 2a3ecc
	move	$4,$30	# 2a3ed0
	jal	func_001395f8	# 2a3ed4
	move	$4,$30	# 2a3ed8
	jal	func_002a43f0	# 2a3edc
	nop	# 2a3ee0
	li	$15,18963	# 2a3ee4
	li	$4,18961	# 2a3ee8
	jal	func_00192048	# 2a3eec
	movz	$4,$15,$2	# 2a3ef0
	sw	$2,408($30)	# 2a3ef4
	jal	func_0023aa18	# 2a3ef8
	move	$4,$16	# 2a3efc
	move	$23,$2	# 2a3f00
	jal	func_0023aa38	# 2a3f04
	move	$4,$16	# 2a3f08
	move	$22,$2	# 2a3f0c
	jal	func_00276c38	# 2a3f10
	li	$4,2	# 2a3f14
	lui	$14,%hi(D_0035f5e8)	# 2a3f18
	lw	$7, %lo(D_0035f148)($20)	# 2a3f1c
	lw	$15, %lo(D_0035f5e8)($14)	# 2a3f20
	move	$9,$2	# 2a3f24
	lw	$8, %lo(D_0035f210)($21)	# 2a3f28
	li	$10,-1	# 2a3f2c
	lw	$6, %lo(D_0035f14c)($19)	# 2a3f30
	addiu	$30,$15,30220	# 2a3f34
	lw	$5,16($29)	# 2a3f38
	li	$11,-1	# 2a3f3c
	sw	$0,0($29)	# 2a3f40
	jal	func_0028d980	# 2a3f44
	move	$4,$30	# 2a3f48
	jal	func_00139620	# 2a3f4c
	move	$4,$30	# 2a3f50
	lui	$15,%hi(D_0035f5e8)	# 2a3f54
	move	$4,$30	# 2a3f58
	lw	$5, %lo(D_0035f5e8)($15)	# 2a3f5c
	jal	func_0028dcc0	# 2a3f60
	addiu	$5,$5,29784	# 2a3f64
	move	$5,$23	# 2a3f68
	move	$6,$22	# 2a3f6c
	jal	func_00138c68	# 2a3f70
	move	$4,$30	# 2a3f74
	jal	func_001395f8	# 2a3f78
	move	$4,$30	# 2a3f7c
	li	$15,1	# 2a3f80
	lui	$13,%hi(D_0035f5e8)	# 2a3f84
	sw	$15,432($30)	# 2a3f88
	move	$5,$0	# 2a3f8c
	li	$6,16	# 2a3f90
	lw	$15, %lo(D_0035f5e8)($13)	# 2a3f94
	addu	$15,$15,$18	# 2a3f98
	sw	$15,408($30)	# 2a3f9c
	lw	$4, %lo(D_0035f5e8)($13)	# 2a3fa0
	jal	func_002fde18	# 2a3fa4
	addu	$4,$4,$18	# 2a3fa8
	lui	$14,%hi(D_0035f5e8)	# 2a3fac
	lui	$15,%hi(D_0035f5e4)	# 2a3fb0
	lw	$4, %lo(D_0035f5e8)($14)	# 2a3fb4
	lui	$5,0x37	# 2a3fb8
	addiu	$5,$5,19344	# 2a3fbc
	lw	$14, %lo(D_0035f5e4)($15)	# 2a3fc0
	addu	$4,$4,$18	# 2a3fc4
	lw	$7,4216($14)	# 2a3fc8
	jal	func_00192cc0	# 2a3fcc
	lw	$6,4220($14)	# 2a3fd0
.L002a3fd4:
	move	$20,$0	# 2a3fd4
	lui	$17,%hi(D_0035f148)	# 2a3fd8
	lui	$30,%hi(D_0035f210)	# 2a3fdc
	li	$15,3264	# 2a3fe0
.L002a3fe4:
	move	$19,$0	# 2a3fe4
	mult	$18,$20,$15	# 2a3fe8
	lui	$13,%hi(D_0035f5e8)	# 2a3fec
.L002a3ff0:
	lw	$7, %lo(D_0035f148)($17)	# 2a3ff0
	lw	$16, %lo(D_0035f5e8)($13)	# 2a3ff4
	lui	$14,%hi(D_0035f14c)	# 2a3ff8
	lw	$6, %lo(D_0035f14c)($14)	# 2a3ffc
	li	$9,74	# 2a4000
	addu	$16,$18,$16	# 2a4004
	lw	$8, %lo(D_0035f210)($30)	# 2a4008
	lw	$5,16($29)	# 2a400c
	li	$10,-1	# 2a4010
	move	$11,$0	# 2a4014
	jal	func_0028d8c0	# 2a4018
	move	$4,$16	# 2a401c
	addiu	$22,$16,24	# 2a4020
	move	$4,$16	# 2a4024
	jal	func_00139620	# 2a4028
	addiu	$18,$18,408	# 2a402c
	lw	$5,20($29)	# 2a4030
	jal	func_0028dcc0	# 2a4034
	move	$4,$16	# 2a4038
	jal	func_0023aa78	# 2a403c
	move	$4,$22	# 2a4040
	move	$4,$22	# 2a4044
	jal	func_0023aa98	# 2a4048
	move	$21,$2	# 2a404c
	mult1	$22,$21,$20	# 2a4050
	mult	$23,$2,$19	# 2a4054
	move	$4,$16	# 2a4058
	move	$6,$22	# 2a405c
	move	$5,$23	# 2a4060
	jal	func_00138c68	# 2a4064
	addiu	$19,$19,1	# 2a4068
	move	$4,$16	# 2a406c
	jal	func_00138c10	# 2a4070
	li	$5,2	# 2a4074
	slti	$15,$19,8	# 2a4078
	bnez	$15, .L002a3ff0	# 2a407c
	lui	$13,%hi(D_0035f5e8)	# 2a4080
	addiu	$20,$20,1	# 2a4084
	slti	$15,$20,9	# 2a4088
	bnezl	$15, .L002a3fe4	# 2a408c
	li	$15,3264	# 2a4090
	ld	$16,32($29)	# 2a4094
	ld	$17,40($29)	# 2a4098
	ld	$18,48($29)	# 2a409c
	ld	$19,56($29)	# 2a40a0
	ld	$20,64($29)	# 2a40a4
	ld	$21,72($29)	# 2a40a8
	ld	$22,80($29)	# 2a40ac
	ld	$23,88($29)	# 2a40b0
	ld	$30,96($29)	# 2a40b4
	ld	$31,104($29)	# 2a40b8
	jr	$31	# 2a40bc
	addiu	$29,$29,112	# 2a40c0
	.end func_002a3ba8
	.size func_002a3ba8, 1308
