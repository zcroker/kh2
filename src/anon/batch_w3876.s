# Whole-function assembly (last step of the README ladder, 2026-11-09, helper w3876).
# Both functions were 2-3 difference near misses in C/C++ after many sessions; see attempts.tsv
# and the best/ADDR_w3876.cpp drafts. Replace with C/C++ after 100%.
#   func_0015efa0: fog/colour tint setter (sched2 places the t->r byte store after the g/b zero-extends;
#                  the original stores r before the c.a stack store)
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

