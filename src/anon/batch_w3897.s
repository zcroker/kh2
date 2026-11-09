# Whole-function assembly (last step of the README ladder, 2026-11-10, zl90 w3897).
# Both functions were near misses in C/C++ after many sessions; see coord attempts.tsv and
# best/0020e960_w3897.c, best/0024f710_w3897.cpp. Replace with C/C++ after 100%.
#   _Z16u_call0_0020e960v: 4x4 float table + 3 colour bytes setter (sched2 order of the 3 sb stores, 4 lines)
#   func_0024f710: menu slot setup (prologue sched2 order of addiu s5 against sd s8, 2 lines)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0020e960,"ax",@progbits
	.globl _Z16u_call0_0020e960v
	.type _Z16u_call0_0020e960v, @function
	.globl func_0020e960
	.type func_0020e960, @function
	.ent _Z16u_call0_0020e960v
_Z16u_call0_0020e960v:
func_0020e960:
	lui	$14,0x37	# 3c0e0037
	mtc1	$0,$f2	# 44801000
	addiu	$14,$14,1968	# 25ce07b0
	li	$13,-128	# 240dff80
	lwc1	$f3,0($14)	# c5c30000
	lui	$15,0x37	# 3c0f0037
	addiu	$15,$15,1972	# 25ef07b4
	lui	$12,0x36	# 3c0c0036
	lui	$14,0x36	# 3c0e0036
	lwc1	$f4,0($15)	# c5e40000
	sb	$13,-28336($14)	# a1cd9150
	addiu	$11,$14,-28336	# 25cb9150
	addiu	$15,$12,-28400	# 258f9110
	swc1	$f2,-28400($12)	# e5829110
	lui	$14,0x37	# 3c0e0037
	swc1	$f2,60($15)	# e5e2003c
	addiu	$14,$14,1976	# 25ce07b8
	swc1	$f3,28($15)	# e5e3001c
	lwc1	$f0,0($14)	# c5c00000
	swc1	$f4,56($15)	# e5e40038
	lui	$14,0x37	# 3c0e0037
	swc1	$f0,32($15)	# e5e00020
	addiu	$14,$14,1980	# 25ce07bc
	sb	$13,1($11)	# a16d0001
	lwc1	$f1,0($14)	# c5c10000
	swc1	$f2,4($15)	# e5e20004
	swc1	$f1,36($15)	# e5e10024
	swc1	$f3,8($15)	# e5e30008
	swc1	$f2,12($15)	# e5e2000c
	swc1	$f2,20($15)	# e5e20014
	swc1	$f2,16($15)	# e5e20010
	swc1	$f3,24($15)	# e5e30018
	swc1	$f4,40($15)	# e5e40028
	swc1	$f2,44($15)	# e5e2002c
	swc1	$f2,48($15)	# e5e20030
	swc1	$f4,52($15)	# e5e40034
	jr	$31	# 03e00008
	sb	$13,2($11)	# a16d0002
	.end _Z16u_call0_0020e960v
	.size _Z16u_call0_0020e960v, .-_Z16u_call0_0020e960v

	.section .text.func_0024f710,"ax",@progbits
	.globl func_0024f710
	.type func_0024f710, @function
	.ent func_0024f710
func_0024f710:
	addiu	$29,$29,-128	# 27bdff80
	lui	$15,0x36	# 3c0f0036
	sd	$31,120($29)	# ffbf0078
	li	$4,160	# 240400a0
	sd	$16,48($29)	# ffb00030
	sd	$17,56($29)	# ffb10038
	sd	$19,72($29)	# ffb30048
	sd	$21,88($29)	# ffb50058
	lui	$17,0x36	# 3c110036
	sd	$22,96($29)	# ffb60060
	move	$19,$0	# 0000982d
	sd	$23,104($29)	# ffb70068
	lui	$21,0x37	# 3c150037
	addiu	$21,$21,9360	# 26b52490
	sd	$30,112($29)	# ffbe0070
	sb	$0,-4528($15)	# a1e0ee50
	move	$23,$0	# 0000b82d
	sd	$18,64($29)	# ffb20040
	sd	$20,80($29)	# ffb40050
	jal	0x23ee30	# 0c08fb8c
	move	$30,$0	# 0000f02d
	lui	$15,0x34	# 3c0f0034
	move	$16,$2	# 0040802d
	addiu	$15,$15,32664	# 25ef7f98
	addiu	$4,$2,12	# 2444000c
	jal	0x31a838	# 0c0c6a0e
	sw	$15,0($2)	# ac4f0000
	lui	$15,0x36	# 3c0f0036
	addiu	$4,$16,24	# 26040018
	addiu	$15,$15,-5224	# 25efeb98
	jal	0x2369a0	# 0c08da68
	sw	$15,0($16)	# ae0f0000
	jal	0x23c008	# 0c08f002
	addiu	$4,$16,48	# 26040030
	sw	$16,-4548($17)	# ae30ee3c
	move	$4,$16	# 0200202d
	li	$5,30002	# 24057532
	move	$6,$0	# 0000302d
	sw	$0,0($29)	# afa00000
	move	$7,$0	# 0000382d
	li	$8,30	# 2408001e
	li	$9,32	# 24090020
	move	$10,$0	# 0000502d
	jal	0x28d7f0	# 0c0a35fc
	move	$11,$0	# 0000582d
	jal	0x23ef50	# 0c08fbd4
	lw	$4,-4548($17)	# 8e24ee3c
	lui	$13,0x37	# 3c0d0037
	addiu	$13,$13,9360	# 25ad2490
	addiu	$22,$13,17	# 25b60011
.L0024f7d8:
	move	$18,$0	# 0000902d
	li	$20,1	# 24140001
	move	$17,$0	# 0000882d
	addiu	$16,$21,28	# 26b0001c
	lb	$15,0($16)	# 820f0000
.L0024f7ec:
	addiu	$16,$16,1	# 26100001
	bltz	$15,.L0024f80c	# 05e00006
	move	$4,$15	# 01e0202d
	jal	0x1a6d08	# 0c069b42
	nop	# 00000000
	bnezl	$2,.L0024fbbc	# 544000ee
	addiu	$17,$17,1	# 26310001
	move	$20,$0	# 0000a02d
.L0024f80c:
	beqzl	$20,.L0024f8cc	# 5280002f
	lbu	$15,0($22)	# 92cf0000
	li	$4,6	# 24040006
	jal	0x2431d0	# 0c090c74
	move	$5,$19	# 0260282d
	bnez	$2,.L0024f848	# 14400009
	lui	$13,0x36	# 3c0d0036
	lui	$14,0x36	# 3c0e0036
	li	$13,1	# 240d0001
	lbu	$15,-4527($14)	# 91cfee51
	sllv	$14,$13,$19	# 026d7004
	or	$15,$15,$14	# 01ee7825
	lui	$14,0x36	# 3c0e0036
	sb	$15,-4527($14)	# a1cfee51
	lui	$13,0x36	# 3c0d0036
.L0024f848:
	lui	$15,0x37	# 3c0f0037
	lw	$8,-4548($13)	# 8da8ee3c
	addiu	$15,$15,9360	# 25ef2490
	addu	$10,$23,$15	# 02ef5021
	lui	$14,0x37	# 3c0e0037
	lb	$15,16($10)	# 814f0010
	lui	$13,0x36	# 3c0d0036
	lw	$4,-4556($13)	# 8da4ee34
	addiu	$14,$14,9368	# 25ce2498
	lhu	$9,18($10)	# 95490012
	addu	$11,$23,$14	# 02ee5821
	movn	$30,$19,$15	# 026ff00b
	move	$6,$0	# 0000302d
	move	$7,$0	# 0000382d
	jal	0x288d80	# 0c0a2360
	move	$5,$19	# 0260282d
	lui	$14,0x36	# 3c0e0036
	move	$5,$19	# 0260282d
	jal	0x2891b8	# 0c0a246e
	lw	$4,-4556($14)	# 8dc4ee34
	move	$18,$2	# 0040902d
	jal	0x23aa98	# 0c08eaa6
	addiu	$4,$2,24	# 24440018
	move	$16,$2	# 0040802d
	jal	0x28dd90	# 0c0a3764
	move	$4,$2	# 0040202d
	sw	$2,432($18)	# ae4201b0
	jal	0x28ddd8	# 0c0a3776
	move	$4,$16	# 0200202d
	sw	$2,428($18)	# ae4201ac
	jal	0x1395f8	# 0c04e57e
	move	$4,$18	# 0240202d
	lbu	$15,0($22)	# 92cf0000
.L0024f8cc:
	xori	$15,$15,0x1	# 39ef0001
	andi	$15,$15,0x1	# 31ef0001
	andi	$15,$15,0xff	# 31ef00ff
	beqzl	$15,.L0024f8ec	# 51e00004
	addiu	$19,$19,1	# 26730001
	jal	0x139570	# 0c04e55c
	move	$4,$18	# 0240202d
	addiu	$19,$19,1	# 26730001
.L0024f8ec:
	addiu	$22,$22,36	# 26d60024
	addiu	$23,$23,36	# 26f70024
	slti	$15,$19,5	# 2a6f0005
	bnez	$15,.L0024f7d8	# 15e0ffb7
	addiu	$21,$21,36	# 26b50024
	lui	$20,0x36	# 3c140036
	move	$19,$0	# 0000982d
	jal	0x2892f8	# 0c0a24be
	lw	$4,-4556($20)	# 8e84ee34
	lw	$4,-4556($20)	# 8e84ee34
	move	$16,$2	# 0040802d
	jal	0x2891b8	# 0c0a246e
	move	$5,$0	# 0000282d
	jal	0x23aa78	# 0c08ea9e
	addiu	$4,$2,24	# 24440018
	mult	$15,$2,$16	# 00507818
	move	$18,$2	# 0040902d
	srl	$14,$15,0x1f	# 000f77c2
	addu	$15,$15,$14	# 01ee7821
	blez	$16,.L0024f980	# 1a000011
	sra	$6,$15,0x1	# 000f3043
	move	$17,$19	# 0260882d
	move	$21,$16	# 0200a82d
	move	$19,$20	# 0280982d
	negu	$16,$6	# 00068023
	lw	$4,-4556($19)	# 8e64ee34
.L0024f954:
	move	$5,$17	# 0220282d
	jal	0x2891b8	# 0c0a246e
	addiu	$17,$17,1	# 26310001
	move	$6,$16	# 0200302d
	move	$4,$2	# 0040202d
	move	$5,$0	# 0000282d
	jal	0x138c68	# 0c04e31a
	addu	$16,$16,$18	# 02128021
	slt	$15,$17,$21	# 0235782a
	bnezl	$15,.L0024f954	# 55e0fff6
	lw	$4,-4556($19)	# 8e64ee34
.L0024f980:
	lui	$16,0x36	# 3c100036
	move	$5,$30	# 03c0282d
	lw	$4,-4556($16)	# 8e04ee34
	move	$6,$0	# 0000302d
	li	$7,-1	# 2407ffff
	jal	0x2891f0	# 0c0a247c
	li	$8,-1	# 2408ffff
	lui	$18,0x34	# 3c120034
	lw	$4,-4556($16)	# 8e04ee34
	addiu	$18,$18,32664	# 26527f98
	lui	$17,0x36	# 3c110036
	jal	0x2891e8	# 0c0a247a
	lui	$19,0x36	# 3c130036
	addiu	$17,$17,-5224	# 2631eb98
	lw	$4,-4556($16)	# 8e04ee34
	move	$30,$2	# 0040f02d
	move	$5,$2	# 0040282d
	li	$6,1	# 24060001
	move	$7,$0	# 0000382d
	jal	0x2891f0	# 0c0a247c
	li	$8,2	# 24080002
	lui	$20,0x36	# 3c140036
	li	$13,36	# 240d0024
	lui	$15,0x37	# 3c0f0037
	mult	$13,$30,$13	# 03cd6818
	addiu	$15,$15,9360	# 25ef2490
	lui	$14,0x37	# 3c0e0037
	lui	$7,0x37	# 3c070037
	addiu	$14,$14,9352	# 25ce2488
	lui	$8,0x37	# 3c080037
	sw	$14,0($29)	# afae0000
	lui	$9,0x37	# 3c090037
	addu	$13,$13,$15	# 01af6821
	lui	$10,0x37	# 3c0a0037
	li	$15,5310	# 240f14be
	sw	$13,16($29)	# afad0010
	sw	$15,8($29)	# afaf0008
	lui	$14,0x36	# 3c0e0036
	lui	$11,0x37	# 3c0b0037
	addiu	$7,$7,9280	# 24e72440
	lui	$15,0x36	# 3c0f0036
	lw	$4,-4532($14)	# 8dc4ee4c
	lw	$6,-4548($15)	# 8de6ee3c
	addiu	$8,$8,9320	# 25082468
	addiu	$9,$9,9328	# 25292470
	addiu	$10,$10,9336	# 254a2478
	sw	$0,24($29)	# afa00018
	addiu	$11,$11,9344	# 256b2480
	sw	$0,32($29)	# afa00020
	jal	0x2b4070	# 0c0ad01c
	li	$5,30003	# 24057533
	jal	0x23ee30	# 0c08fb8c
	li	$4,160	# 240400a0
	sw	$18,0($2)	# ac520000
	move	$16,$2	# 0040802d
	jal	0x31a838	# 0c0c6a0e
	addiu	$4,$2,12	# 2444000c
	sw	$17,0($16)	# ae110000
	jal	0x2369a0	# 0c08da68
	addiu	$4,$16,24	# 26040018
	jal	0x23c008	# 0c08f002
	addiu	$4,$16,48	# 26040030
	li	$14,6	# 240e0006
	sw	$16,-4540($19)	# ae70ee44
	mult	$14,$30,$14	# 03ce7018
	lui	$15,0x37	# 3c0f0037
	addiu	$15,$15,9288	# 25ef2448
	sw	$0,0($29)	# afa00000
	li	$5,30002	# 24057532
	move	$6,$0	# 0000302d
	move	$7,$0	# 0000382d
	move	$10,$0	# 0000502d
	addu	$14,$14,$15	# 01cf7021
	move	$11,$0	# 0000582d
	lh	$9,4($14)	# 85c90004
	move	$4,$16	# 0200202d
	jal	0x28d7f0	# 0c0a35fc
	lh	$8,0($14)	# 85c80000
	jal	0x23ef50	# 0c08fbd4
	lw	$4,-4540($19)	# 8e64ee44
	jal	0x23ee30	# 0c08fb8c
	li	$4,160	# 240400a0
	sw	$18,0($2)	# ac520000
	move	$16,$2	# 0040802d
	jal	0x31a838	# 0c0c6a0e
	addiu	$4,$2,12	# 2444000c
	sw	$17,0($16)	# ae110000
	jal	0x2369a0	# 0c08da68
	addiu	$4,$16,24	# 26040018
	jal	0x23c008	# 0c08f002
	addiu	$4,$16,48	# 26040030
	sw	$16,-4544($20)	# ae90ee40
	move	$6,$0	# 0000302d
	move	$7,$0	# 0000382d
	li	$8,33	# 24080021
	sw	$0,0($29)	# afa00000
	li	$9,35	# 24090023
	move	$10,$0	# 0000502d
	move	$11,$0	# 0000582d
	li	$5,30019	# 24057543
	jal	0x28d7f0	# 0c0a35fc
	move	$4,$16	# 0200202d
	jal	0x23ef50	# 0c08fbd4
	lw	$4,-4544($20)	# 8e84ee40
	move	$5,$0	# 0000282d
	jal	0x287bd0	# 0c0a1ef4
	move	$4,$0	# 0000202d
	jal	0x287cc0	# 0c0a1f30
	move	$4,$0	# 0000202d
	jal	0x2887c8	# 0c0a21f2
	nop	# 00000000
	beqz	$2,.L0024fb90	# 10400014
	ld	$16,48($29)	# dfb00030
	jal	0x24fd28	# 0c093f4a
	nop	# 00000000
	li	$15,1	# 240f0001
	ld	$16,48($29)	# dfb00030
	lui	$14,0x36	# 3c0e0036
	ld	$17,56($29)	# dfb10038
	sb	$15,-4528($14)	# a1cfee50
	lui	$4,0x25	# 3c040025
	ld	$18,64($29)	# dfb20040
	addiu	$4,$4,-264	# 2484fef8
	ld	$19,72($29)	# dfb30048
	ld	$20,80($29)	# dfb40050
	ld	$21,88($29)	# dfb50058
	ld	$22,96($29)	# dfb60060
	ld	$23,104($29)	# dfb70068
	ld	$30,112($29)	# dfbe0070
	ld	$31,120($29)	# dfbf0078
	j	0x288750	# 080a21d4
	addiu	$29,$29,128	# 27bd0080
.L0024fb90:
	ld	$17,56($29)	# dfb10038
	ld	$18,64($29)	# dfb20040
	ld	$19,72($29)	# dfb30048
	ld	$20,80($29)	# dfb40050
	ld	$21,88($29)	# dfb50058
	ld	$22,96($29)	# dfb60060
	ld	$23,104($29)	# dfb70068
	ld	$30,112($29)	# dfbe0070
	ld	$31,120($29)	# dfbf0078
	jr	$31	# 03e00008
	addiu	$29,$29,128	# 27bd0080
.L0024fbbc:
	slti	$15,$17,4	# 2a2f0004
	bnezl	$15,.L0024f7ec	# 55e0ff0a
	lb	$15,0($16)	# 820f0000
	b	.L0024f80c	# 1000ff10
	nop	# 00000000
	.end func_0024f710
	.size func_0024f710, .-func_0024f710
