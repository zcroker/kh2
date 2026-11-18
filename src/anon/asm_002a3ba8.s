# Whole-function assembly (last step of the README match ladder, w3950 2026-11-10).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_002a3ba8: builds the 9-row list objects under D_0035f5e8 (+0x7974/+0x88c8 per 436-byte row), optional
#     header (func_00276c18, text via func_00192cc0), then the 9 x 8 grid of icons.
#     Closest C: ~/re/kh2/tmp.w3950/best_002a3ba8_nsamam.cpp (= best/002a3ba8_w3945_nsa.cpp, about 318 lines off):
#     s-register choice for the global %hi parts and the live-range copies (move s3,s2; move s2,s4).
#     No symbol, written as a literal lui/addiu value: 0x00374b90 (format string, func_002a3ba8 at 0x2a3fb8).
# Split out of batch_w3950.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

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
