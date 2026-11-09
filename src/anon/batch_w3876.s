# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3876).
# Both functions were 2-3 difference near misses in C/C++ after many sessions; see coord attempts.tsv
# and the best/ADDR_w3876.cpp drafts. Replace with C/C++ after 100%.
#   func_0015efa0: fog/colour tint setter (sched2 places the t->r byte store after the g/b zero-extends;
#                  the original stores r before the c.a stack store)
#   _Z16wtarget_001b65e0jjjj: drive form change task (first wait loop: sched1 hoists the body's
#                  move a0,s3 into the last test block, which leaves the exit's own move a0,s3)
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0015efa0,"ax",@progbits
	.globl func_0015efa0
	.type func_0015efa0, @function
	.ent func_0015efa0
func_0015efa0:
	addiu	$29,$29,-112	# 27bdff90
	sd	$19,56($29)	# ffb30038
	sd	$20,64($29)	# ffb40040
	sd	$21,72($29)	# ffb50048
	andi	$19,$4,0xff	# 309300ff
	sd	$16,32($29)	# ffb00020
	andi	$20,$5,0xff	# 30b400ff
	sd	$17,40($29)	# ffb10028
	sd	$18,48($29)	# ffb20030
	sd	$31,80($29)	# ffbf0050
	swc1	$f22,96($29)	# e7b60060
	swc1	$f21,92($29)	# e7b5005c
	swc1	$f20,88($29)	# e7b40058
	jal	0x15f268	# 0c057c9a
	andi	$21,$6,0xff	# 30d500ff
	bnez	$2,.L0015f210	# 1440008c
	ld	$16,32($29)	# dfb00020
	mtc1	$19,$f2	# 44931000
	lui	$15,0x37	# 3c0f0037
	mtc1	$20,$f3	# 44941800
	addiu	$15,$15,-19348	# 25efb46c
	mtc1	$21,$f0	# 44950000
	li	$17,128	# 24110080
	cvt.s.w	$f2,$f2	# 468010a0
	sb	$19,16($29)	# a3b30010
	cvt.s.w	$f3,$f3	# 468018e0
	sb	$20,17($29)	# a3b40011
	cvt.s.w	$f0,$f0	# 46800020
	sb	$21,18($29)	# a3b50012
	lwc1	$f1,0($15)	# c5e10000
	addiu	$5,$29,1	# 27a50001
	sb	$17,19($29)	# a3b10013
	addiu	$6,$29,2	# 27a60002
	mul.s	$f21,$f2,$f1	# 46011542
	addiu	$7,$29,3	# 27a70003
	mul.s	$f22,$f0,$f1	# 46010582
	move	$4,$29	# 03a0202d
	jal	0x15cb18	# 0c0572c6
	mul.s	$f20,$f3,$f1	# 46011d02
	lbu	$12,16($29)	# 93ac0010
	lbu	$9,17($29)	# 93a90011
	lbu	$8,18($29)	# 93a80012
	lbu	$11,19($29)	# 93ab0013
	lbu	$15,0($29)	# 93af0000
	lbu	$14,1($29)	# 93ae0001
	lbu	$13,2($29)	# 93ad0002
	mult	$15,$15,$12	# 01ec7818
	lbu	$10,3($29)	# 93aa0003
	mult	$14,$14,$9	# 01c97018
	mult1	$13,$13,$8	# 71a86818
	mult	$10,$10,$11	# 014b5018
	sra	$15,$15,0x7	# 000f79c3
	sra	$14,$14,0x7	# 000e71c3
	sb	$15,0($29)	# a3af0000
	sra	$13,$13,0x7	# 000d69c3
	sb	$14,1($29)	# a3ae0001
	sra	$10,$10,0x7	# 000a51c3
	sb	$13,2($29)	# a3ad0002
	sb	$10,3($29)	# a3aa0003
	andi	$4,$15,0xff	# 31e400ff
	andi	$5,$14,0xff	# 31c500ff
	andi	$6,$13,0xff	# 31a600ff
	jal	0x15cbb8	# 0c0572ee
	andi	$7,$10,0xff	# 314700ff
	jal	0x15c4b8	# 0c05712e
	nop	# 00000000
	jal	0x15cc60	# 0c057318
	nop	# 00000000
	jal	0x15cc50	# 0c057314
	move	$16,$2	# 0040802d
	lbu	$14,1($16)	# 920e0001
	move	$18,$2	# 0040902d
	lbu	$15,2($16)	# 920f0002
	move	$4,$2	# 0040202d
	lbu	$13,0($16)	# 920d0000
	lbu	$11,16($29)	# 93ab0010
	lbu	$9,17($29)	# 93a90011
	lbu	$8,18($29)	# 93a80012
	mult	$13,$13,$11	# 01ab6818
	lbu	$12,3($29)	# 93ac0003
	mult	$14,$14,$9	# 01c97018
	lbu	$10,19($29)	# 93aa0013
	mult1	$15,$15,$8	# 71e87818
	mult	$12,$12,$10	# 018a6018
	sra	$13,$13,0x7	# 000d69c3
	sra	$14,$14,0x7	# 000e71c3
	sb	$13,0($29)	# a3ad0000
	sra	$15,$15,0x7	# 000f79c3
	sb	$14,1($29)	# a3ae0001
	sb	$15,2($29)	# a3af0002
	andi	$13,$13,0xff	# 31ad00ff
	sra	$12,$12,0x7	# 000c61c3
	sb	$13,0($2)	# a04d0000
	sb	$12,3($29)	# a3ac0003
	andi	$14,$14,0xff	# 31ce00ff
	andi	$15,$15,0xff	# 31ef00ff
	sb	$14,1($2)	# a04e0001
	sb	$15,2($2)	# a04f0002
	jal	0x15cc80	# 0c057320
	sb	$17,3($2)	# a0510003
	bnezl	$2,.L0015f164	# 5440000c
	lwc1	$f1,12($18)	# c641000c
	lwc1	$f12,12($18)	# c64c000c
	jal	0x10a8a8	# 0c042a2a
	lwc1	$f13,16($18)	# c64d0010
	lwc1	$f12,4($18)	# c64c0004
	jal	0x10a828	# 0c042a0a
	lwc1	$f13,8($18)	# c64d0008
	lbu	$4,0($18)	# 92440000
	lbu	$5,1($18)	# 92450001
	jal	0x10a7d8	# 0c0429f6
	lbu	$6,2($18)	# 92460002
	lwc1	$f1,12($18)	# c641000c
.L0015f164:
	move	$16,$0	# 0000802d
	lwc1	$f0,16($18)	# c6400010
	cvt.w.s	$f2,$f1	# 460008a4
	cvt.w.s	$f1,$f0	# 46000064
	mfc1	$4,$f2	# 44041000
	andi	$4,$4,0xff	# 308400ff
	mfc1	$5,$f1	# 44050800
	jal	0x1dd1e8	# 0c07747a
	andi	$5,$5,0xff	# 30a500ff
	lwc1	$f12,4($18)	# c64c0004
	jal	0x1dd1b0	# 0c07746c
	lwc1	$f13,8($18)	# c64d0008
	lbu	$6,2($18)	# 92460002
	lbu	$4,0($18)	# 92440000
	jal	0x1dd1c8	# 0c077472
	lbu	$5,1($18)	# 92450001
	move	$4,$19	# 0260202d
	move	$5,$20	# 0280282d
	jal	0x1432f0	# 0c050cbc
	move	$6,$21	# 02a0302d
	move	$4,$19	# 0260202d
	move	$5,$20	# 0280282d
	jal	0x1611a8	# 0c05846a
	move	$6,$21	# 02a0302d
	lui	$15,0x35	# 3c0f0035
	li	$14,1	# 240e0001
	lbu	$13,-14580($15)	# 91edc70c
	bnel	$13,$14,.L0015f210	# 55ae000f
	ld	$16,32($29)	# dfb00020
	move	$17,$0	# 0000882d
	lui	$18,0x35	# 3c120035
.L0015f1e0:
	move	$6,$16	# 0200302d
.L0015f1e4:
	addiu	$4,$18,-14608	# 2644c6f0
	jal	0x1de4b0	# 0c07792c
	move	$5,$17	# 0220282d
	move	$16,$2	# 0040802d
	bnez	$2,.L0015f23c	# 14400011
	move	$4,$2	# 0040202d
	addiu	$17,$17,1	# 26310001
	slti	$15,$17,64	# 2a2f0040
	bnez	$15,.L0015f1e4	# 15e0fff7
	move	$6,$16	# 0200302d
	ld	$16,32($29)	# dfb00020
.L0015f210:
	ld	$17,40($29)	# dfb10028
	ld	$18,48($29)	# dfb20030
	ld	$19,56($29)	# dfb30038
	ld	$20,64($29)	# dfb40040
	ld	$21,72($29)	# dfb50048
	ld	$31,80($29)	# dfbf0050
	lwc1	$f22,96($29)	# c7b60060
	lwc1	$f21,92($29)	# c7b5005c
	lwc1	$f20,88($29)	# c7b40058
	jr	$31	# 03e00008
	addiu	$29,$29,112	# 27bd0070
.L0015f23c:
	jal	0x1dc9e0	# 0c077278
	nop	# 00000000
	beqz	$2,.L0015f1e0	# 1040ffe6
	move	$4,$16	# 0200202d
	jal	0x1dc670	# 0c07719c
	nop	# 00000000
	swc1	$f22,8($2)	# e4560008
	swc1	$f21,0($2)	# e4550000
	b	.L0015f1e0	# 1000ffe0
	swc1	$f20,4($2)	# e4540004
	.end func_0015efa0
	.size func_0015efa0, .-func_0015efa0

	.section .text.func_001b65e0,"ax",@progbits
	.globl _Z16wtarget_001b65e0jjjj
	.type _Z16wtarget_001b65e0jjjj, @function
	.ent _Z16wtarget_001b65e0jjjj
func_001b65e0:	# local label so the build registry maps 0x1b65e0 to this file
_Z16wtarget_001b65e0jjjj:
	addiu	$29,$29,-128	# 27bdff80
	sd	$18,80($29)	# ffb20050
	sd	$19,88($29)	# ffb30058
	swc1	$f20,112($29)	# e7b40070
	move	$18,$4	# 0080902d
	sd	$16,64($29)	# ffb00040
	move	$19,$5	# 00a0982d
	sd	$17,72($29)	# ffb10048
	sd	$20,96($29)	# ffb40060
	sd	$31,104($29)	# ffbf0068
	mtc1	$0,$f20	# 4480a000
	lw	$15,4($4)	# 8c8f0004
	xori	$14,$15,0x0	# 39ee0000
	swc1	$f20,0($29)	# e7b40000
	slti	$15,$15,7	# 29ef0007
	swc1	$f20,4($29)	# e7b40004
	movz	$15,$0,$14	# 000e780a
	swc1	$f20,8($29)	# e7b40008
	swc1	$f20,12($29)	# e7b4000c
	andi	$15,$15,0xff	# 31ef00ff
	swc1	$f20,16($29)	# e7b40010
	swc1	$f20,20($29)	# e7b40014
	swc1	$f20,24($29)	# e7b40018
	swc1	$f20,28($29)	# e7b4001c
	beqz	$15,.L001b677c	# 11e0004e
	swc1	$f20,32($29)	# e7b40020
	lui	$15,0x35	# 3c0f0035
	move	$5,$0	# 0000282d
	addiu	$16,$15,7864	# 25f01eb8
	jal	0x1c8db8	# 0c07236e
	move	$4,$16	# 0200202d
	xori	$2,$2,0x1	# 38420001
	andi	$2,$2,0xff	# 304200ff
	beqzl	$2,.L001b667c	# 50400005
	move	$4,$0	# 0000202d
	move	$4,$16	# 0200202d
	jal	0x1c8d80	# 0c072360
	move	$5,$0	# 0000282d
	move	$4,$0	# 0000202d
.L001b667c:
	jal	0x1b1928	# 0c06c64a
	lui	$16,0x35	# 3c100035
	addiu	$16,$16,1096	# 26100448
	sw	$2,16($18)	# ae420010
	lui	$14,0x37	# 3c0e0037
	addiu	$14,$14,-9548	# 25cedab4
	li	$5,48	# 24050030
	lw	$15,16($2)	# 8c4f0010
	li	$6,48	# 24060030
	lwc1	$f12,0($14)	# c5cc0000
	li	$7,48	# 24070030
	ori	$15,$15,0x2	# 35ef0002
	li	$8,128	# 24080080
	sw	$15,16($2)	# ac4f0010
	li	$17,2	# 24110002
	jal	0x1b1bb8	# 0c06c6ee
	lw	$4,16($18)	# 8e440010
	lui	$15,0x37	# 3c0f0037
	move	$4,$19	# 0260202d
	addiu	$15,$15,-9544	# 25efdab8
	jal	0x102470	# 0c04091c
	lwc1	$f12,0($15)	# c5ec0000
	jal	0x19ec88	# 0c067b22
	move	$4,$16	# 0200202d
	mov.s	$f12,$f20	# 4600a306
	sw	$17,16($16)	# ae110010
	sw	$17,12($16)	# ae11000c
	jal	0x19ecb0	# 0c067b2c
	move	$4,$16	# 0200202d
	jal	0x170dd0	# 0c05c374
	move	$4,$19	# 0260202d
	jal	0x170320	# 0c05c0c8
	li	$4,5000	# 24041388
	jal	0x16ef28	# 0c05bbca
	lw	$4,4($18)	# 8e440004
	jal	0x170888	# 0c05c222
	move	$4,$19	# 0260202d
.L001b6710:
	jal	0x19ba60	# 0c066e98
	lw	$4,0($18)	# 8e440000
	beqzl	$2,.L001b6744	# 5040000a
	move	$4,$19	# 0260202d
	lw	$4,0($18)	# 8e440000
	jal	0x180618	# 0c060186
	addiu	$4,$4,320	# 24840140
	bnez	$2,.L001b6744	# 14400005
	move	$4,$19	# 0260202d
	jal	0x1c9df8	# 0c07277e
	nop	# 00000000
	bnez	$2,.L001b6a40	# 144000c0
	move	$4,$19	# 0260202d
.L001b6744:
	jal	0x102448	# 0c040912
	li	$5,2	# 24050002
	lui	$14,0x37	# 3c0e0037
	lw	$4,16($18)	# 8e440010
	addiu	$14,$14,-9540	# 25cedabc
	jal	0x1b1c10	# 0c06c704
	lwc1	$f12,0($14)	# c5cc0000
	lui	$15,0x37	# 3c0f0037
	sw	$0,16($18)	# ae400010
	addiu	$15,$15,-9536	# 25efdac0
	lui	$4,0x35	# 3c040035
	lwc1	$f12,0($15)	# c5ec0000
	jal	0x19ed78	# 0c067b5e
	addiu	$4,$4,1096	# 24840448
.L001b677c:
	jal	0x19ba60	# 0c066e98
	lw	$4,0($18)	# 8e440000
	beqzl	$2,.L001b6964	# 50400077
	ld	$16,64($29)	# dfb00040
	lw	$4,0($18)	# 8e440000
	addiu	$15,$4,192	# 248f00c0
	beql	$29,$15,.L001b67ac	# 53af0005
	lwc1	$f4,32($15)	# c5e40020
	lq	$8,0($15)	# 79e80000
	sq	$8,0($29)	# 7fa80000
	lw	$4,0($18)	# 8e440000
	lwc1	$f4,32($15)	# c5e40020
.L001b67ac:
	addiu	$20,$29,48	# 27b40030
	lwc1	$f3,16($15)	# c5e30010
	addiu	$14,$4,32	# 248e0020
	lwc1	$f0,20($15)	# c5e00014
	lwc1	$f1,24($15)	# c5e10018
	lwc1	$f2,28($15)	# c5e2001c
	swc1	$f3,16($29)	# e7a30010
	swc1	$f0,20($29)	# e7a00014
	swc1	$f1,24($29)	# e7a10018
	swc1	$f2,28($29)	# e7a2001c
	beq	$20,$14,.L001b67e8	# 128e0004
	swc1	$f4,32($29)	# e7a40020
	lq	$8,0($14)	# 79c80000
	sq	$8,0($20)	# 7e880000
	lw	$4,0($18)	# 8e440000
.L001b67e8:
	lw	$15,2880($4)	# 8c8f0b40
	beqzl	$15,.L001b680c	# 51e00007
	lw	$14,0($4)	# 8c8e0000
	jal	0x19ca20	# 0c067288
	move	$4,$15	# 01e0202d
	lw	$15,0($18)	# 8e4f0000
	sw	$0,2880($15)	# ade00b40
	lw	$4,0($18)	# 8e440000
	lw	$14,0($4)	# 8c8e0000
.L001b680c:
	lw	$15,32($14)	# 8dcf0020
	jalr	$15	# 01e0f809
	nop	# 00000000
	jal	0x1050d8	# 0c041436
	li	$4,2944	# 24040b80
	lw	$4,8($18)	# 8e440008
	jal	0x16e920	# 0c05ba48
	move	$17,$2	# 0040882d
	lw	$4,0($18)	# 8e440000
	jal	0x16c028	# 0c05b00a
	move	$16,$2	# 0040802d
	lw	$15,0($18)	# 8e4f0000
	move	$4,$17	# 0220202d
	lw	$6,4($18)	# 8e460004
	move	$8,$2	# 0040402d
	lwc1	$f12,1372($15)	# c5ec055c
	move	$5,$16	# 0200282d
	jal	0x1d0980	# 0c074260
	lw	$7,2872($15)	# 8de70b38
	lw	$15,12($18)	# 8e4f000c
	lw	$13,0($18)	# 8e4d0000
	ori	$15,$15,0x8	# 35ef0008
	sw	$15,12($18)	# ae4f000c
	lw	$14,2760($13)	# 8dae0ac8
	sw	$14,2760($17)	# ae2e0ac8
	lw	$15,0($18)	# 8e4f0000
	sw	$0,2760($15)	# ade00ac8
	lw	$14,0($18)	# 8e4e0000
	lw	$15,2764($14)	# 8dcf0acc
	sw	$15,2764($17)	# ae2f0acc
	lw	$14,0($18)	# 8e4e0000
	sw	$0,2764($14)	# adc00acc
	lw	$4,0($18)	# 8e440000
	lw	$15,2040($4)	# 8c8f07f8
	andi	$15,$15,0x4	# 31ef0004
	beqz	$15,.L001b6994	# 11e0003e
	mtc1	$0,$f12	# 44806000
	addiu	$4,$4,320	# 24840140
	move	$5,$0	# 0000282d
	jal	0x17f488	# 0c05fd22
	mov.s	$f13,$f12	# 46006346
	li	$15,3	# 240f0003
.L001b68b4:
	sw	$15,2924($17)	# ae2f0b6c
.L001b68b8:
	jal	0x1b6ab8	# 0c06daae
	move	$4,$18	# 0240202d
	lw	$4,0($18)	# 8e440000
	jal	0x190570	# 0c06415c
	move	$5,$17	# 0220282d
	lw	$4,0($18)	# 8e440000
	jal	0x1995b8	# 0c06656e
	move	$5,$17	# 0220282d
	lw	$4,0($18)	# 8e440000
	jal	0x1e0230	# 0c07808c
	move	$5,$17	# 0220282d
	lw	$4,0($18)	# 8e440000
	jal	0x18ef98	# 0c063be6
	move	$5,$17	# 0220282d
	lw	$4,0($18)	# 8e440000
	jal	0x197e08	# 0c065f82
	move	$5,$17	# 0220282d
	lw	$4,0($18)	# 8e440000
	jal	0x1b1360	# 0c06c4d8
	move	$5,$17	# 0220282d
	lw	$4,0($18)	# 8e440000
	jal	0x2edca0	# 0c0bb728
	move	$5,$17	# 0220282d
	jal	0x111e50	# 0c044794
	nop	# 00000000
	lw	$15,12($18)	# 8e4f000c
	ori	$15,$15,0x4	# 35ef0004
	sw	$15,12($18)	# ae4f000c
.L001b6928:
	jal	0x1ba028	# 0c06e80a
	lw	$4,0($18)	# 8e440000
	move	$4,$19	# 0260202d
	bnez	$2,.L001b6984	# 14400013
	move	$5,$0	# 0000282d
	jal	0x102448	# 0c040912
	li	$5,2	# 24050002
	lbu	$15,28($18)	# 924f001c
	beqz	$15,.L001b6964	# 11e00006
	ld	$16,64($29)	# dfb00040
	jal	0x170888	# 0c05c222
	move	$4,$19	# 0260202d
	jal	0x1c9e50	# 0c072794
	move	$4,$19	# 0260202d
	ld	$16,64($29)	# dfb00040
.L001b6964:
	ld	$17,72($29)	# dfb10048
	ld	$18,80($29)	# dfb20050
	ld	$19,88($29)	# dfb30058
	ld	$20,96($29)	# dfb40060
	ld	$31,104($29)	# dfbf0068
	lwc1	$f20,112($29)	# c7b40070
	jr	$31	# 03e00008
	addiu	$29,$29,128	# 27bd0080
.L001b6984:
	jal	0x102448	# 0c040912
	nop	# 00000000
	b	.L001b6928	# 1000ffe6
	nop	# 00000000
.L001b6994:
	lw	$14,4($18)	# 8e4e0004
	slti	$15,$14,7	# 29cf0007
	beqz	$15,.L001b68b8	# 11e0ffc6
	nop	# 00000000
	lw	$15,12($18)	# 8e4f000c
	andi	$15,$15,0x1	# 31ef0001
	beqz	$15,.L001b68b4	# 11e0ffc1
	li	$15,1	# 240f0001
	bnez	$14,.L001b68b4	# 15c0ffbf
	li	$15,2	# 240f0002
	lw	$4,12($17)	# 8e24000c
	move	$5,$17	# 0220282d
	lw	$15,0($4)	# 8c8f0000
	lw	$14,12($15)	# 8dee000c
	jalr	$14	# 01c0f809
	mtc1	$0,$f12	# 44806000
	lw	$15,12($18)	# 8e4f000c
	andi	$15,$15,0x2	# 31ef0002
	beqz	$15,.L001b6a1c	# 11e0000f
	addiu	$15,$17,192	# 262f00c0
	beq	$15,$29,.L001b69f8	# 11fd0004
	lwc1	$f0,16($29)	# c7a00010
	lq	$8,0($29)	# 7ba80000
	sq	$8,0($15)	# 7de80000
	lwc1	$f0,16($29)	# c7a00010
.L001b69f8:
	lwc1	$f1,32($29)	# c7a10020
	swc1	$f0,16($15)	# e5e00010
	swc1	$f1,32($15)	# e5e10020
	lwc1	$f0,20($29)	# c7a00014
	lwc1	$f1,24($29)	# c7a10018
	swc1	$f0,20($15)	# e5e00014
	swc1	$f1,24($15)	# e5e10018
	lwc1	$f0,28($29)	# c7a0001c
	swc1	$f0,28($15)	# e5e0001c
.L001b6a1c:
	addiu	$15,$17,32	# 262f0020
	beql	$15,$20,.L001b6a34	# 51f40004
	sw	$0,36($17)	# ae200024
	lq	$8,0($20)	# 7a880000
	sq	$8,0($15)	# 7de80000
	sw	$0,36($17)	# ae200024
.L001b6a34:
	b	.L001b68b4	# 1000ff9f
	li	$15,2	# 240f0002
	nop	# 00000000
.L001b6a40:
	jal	0x102448	# 0c040912
	move	$5,$0	# 0000282d
	b	.L001b6710	# 1000ff31
	nop	# 00000000
	.end _Z16wtarget_001b65e0jjjj
	.size _Z16wtarget_001b65e0jjjj, .-_Z16wtarget_001b65e0jjjj
