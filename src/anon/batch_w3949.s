# Whole-function assembly (last step of the README match ladder, w3949 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
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
