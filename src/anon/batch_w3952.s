# Whole-function assembly (last step of the README match ladder, w3952 2026-11-10).
# Transcribed from the retail disassembly (mk_s.py); calls and globals with a func_/D_ symbol are referenced
# through it. Replace with C/C++ after 100%.
#   func_00193608: object world-matrix build (rotation from +1360 via func_0011b6a8/0011b7b0 or func_00193be8 with
#     table D_01c61ae0, scale by +48 * +60 * +2256, optional attach to a model node via func_0016b0e0, func_00193d38
#     adjust, copy to +64, func_001b78d0/func_00193e88). VU0 macro code.
#     Closest C: ~/re/kh2/tmp.w3952/best_00193608_ncfj.cpp (= best/00193608_w3947_ncfj.cpp, 173 of 375 lines off
#     in try.sh with -fno-strict-aliasing -fno-cse-follow-jumps): the skip bool (s2 = 0 before func_0019c090, u8 t,
#     xori s2,1) is jump-threaded away in every form tried.
#     No symbol, written as literal lui/addiu values: 0x0036cecc, 0x0036ced0 (float literal pool).
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00193608,"ax",@progbits
	.align 2
	.globl func_00193608
	.type func_00193608, @function
	.ent func_00193608
func_00193608:
	addiu	$29,$29,-496
	sd	$17,424($29)
	sd	$16,416($29)
	sd	$18,432($29)
	sd	$19,440($29)
	sd	$20,448($29)
	sd	$21,456($29)
	sd	$22,464($29)
	sd	$23,472($29)
	sd	$31,480($29)
	swc1	$f21,492($29)
	swc1	$f20,488($29)
	jal	func_0019c400
	move	$17,$4
	beqz	$2,.L00193bc0
	addiu	$23,$17,1360
	addiu	$21,$29,64
	jal	func_0011b6a8
	move	$4,$21
	move	$4,$21
	jal	func_0011b7b0
	move	$5,$23
	beq	$21,$2,.L0019368c
	addiu	$14,$17,48
	lq	$8,0($2)
	lq	$9,16($2)
	lq	$10,32($2)
	lq	$11,48($2)
	sq	$8,0($21)
	sq	$9,16($21)
	sq	$10,32($21)
	sq	$11,48($21)
	addiu	$14,$17,48
.L0019368c:
	lwc1	$f1,60($17)
	addiu	$15,$29,272
	addiu	$22,$29,16
	lqc2	$vf1,0($14)
	mfc1	$8,$f1
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($15)
	lwc1	$f0,2256($17)
	addiu	$16,$29,256
	lqc2	$vf1,0($15)
	mfc1	$8,$f0
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($16)
	beq	$22,$16,.L001936dc
	lui	$14,0x37
	lq	$8,0($16)
	sq	$8,0($22)
	lui	$14,0x37
.L001936dc:
	addiu	$14,$14,-12596
	lwc1	$f20,0($14)
	swc1	$f20,28($29)
	lqc2	$vf4,0($22)
	lqc2	$vf1,0($21)
	lqc2	$vf2,16($21)
	lqc2	$vf3,32($21)
	vmulx.wxyz	$vf1,$vf1,vf4x
	vmuly.wxyz	$vf2,$vf2,vf4y
	vmulz.wxyz	$vf3,$vf3,vf4z
	sqc2	$vf1,0($21)
	sqc2	$vf2,16($21)
	sqc2	$vf3,32($21)
	jal	func_001c0cd8
	move	$4,$17
	beqz	$2,.L00193ba0
	lui	$15,0x37
	addiu	$20,$29,48
	addiu	$15,$15,-12592
	addiu	$5,$17,320
	lwc1	$f21,0($15)
	move	$4,$16
	jal	func_0017fe10
	mov.s	$f12,$f21
	beq	$20,$16,.L00193750
	addiu	$18,$29,128
	lq	$8,0($16)
	sq	$8,0($20)
	addiu	$18,$29,128
.L00193750:
	jal	func_0011b6a8
	move	$4,$18
	lwc1	$f12,60($29)
	jal	func_0011b720
	move	$4,$18
	beq	$18,$2,.L00193790
	addiu	$15,$29,176
	lq	$8,0($2)
	lq	$9,16($2)
	lq	$10,32($2)
	lq	$11,48($2)
	sq	$8,0($18)
	sq	$9,16($18)
	sq	$10,32($18)
	sq	$11,48($18)
	addiu	$15,$29,176
.L00193790:
	addiu	$19,$17,1344
	lqc2	$vf1,0($19)
	lqc2	$vf2,0($20)
	vadd.wxyz	$vf1,$vf1,$vf2
	sqc2	$vf1,0($16)
	beql	$15,$16,.L001937b8
	lhu	$5,1396($17)
	lq	$8,0($16)
	sq	$8,0($15)
	lhu	$5,1396($17)
.L001937b8:
	andi	$15,$5,0x4000
	bnez	$15,.L001937f8
	swc1	$f20,188($29)
	addiu	$15,$29,80
	lqc2	$vf1,0($15)
	mfc1	$8,$f21
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($15)
	addiu	$14,$29,96
	lqc2	$vf1,0($14)
	mfc1	$8,$f21
	qmtc2	$8,$vf2
	vmulx.wxyz	$vf1,$vf1,vf2x
	sqc2	$vf1,0($14)
	lhu	$5,1396($17)
.L001937f8:
	addiu	$16,$29,192
	lw	$4,1392($17)
	move	$6,$16
	jal	func_0016b0e0
	andi	$5,$5,0xffff
	addiu	$15,$29,352
	lqc2	$vf1,0($16)
	lqc2	$vf2,16($16)
	lqc2	$vf3,32($16)
	lqc2	$vf4,48($16)
	lqc2	$vf5,0($21)
	lqc2	$vf6,16($21)
	lqc2	$vf7,32($21)
	lqc2	$vf8,48($21)
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	vmulax.wxyz	ACC,$vf1,vf6x
	vmadday.wxyz	ACC,$vf2,vf6y
	vmaddaz.wxyz	ACC,$vf3,vf6z
	vmaddw.wxyz	$vf6,$vf4,vf6w
	vmulax.wxyz	ACC,$vf1,vf7x
	vmadday.wxyz	ACC,$vf2,vf7y
	vmaddaz.wxyz	ACC,$vf3,vf7z
	vmaddw.wxyz	$vf7,$vf4,vf7w
	vmulax.wxyz	ACC,$vf1,vf8x
	vmadday.wxyz	ACC,$vf2,vf8y
	vmaddaz.wxyz	ACC,$vf3,vf8z
	vmaddw.wxyz	$vf8,$vf4,vf8w
	sqc2	$vf5,0($15)
	sqc2	$vf6,16($15)
	sqc2	$vf7,32($15)
	sqc2	$vf8,48($15)
	addiu	$14,$29,288
	lqc2	$vf1,0($15)
	lqc2	$vf2,16($15)
	lqc2	$vf3,32($15)
	lqc2	$vf4,48($15)
	lqc2	$vf5,0($18)
	lqc2	$vf6,16($18)
	lqc2	$vf7,32($18)
	lqc2	$vf8,48($18)
	vmulax.wxyz	ACC,$vf1,vf5x
	vmadday.wxyz	ACC,$vf2,vf5y
	vmaddaz.wxyz	ACC,$vf3,vf5z
	vmaddw.wxyz	$vf5,$vf4,vf5w
	vmulax.wxyz	ACC,$vf1,vf6x
	vmadday.wxyz	ACC,$vf2,vf6y
	vmaddaz.wxyz	ACC,$vf3,vf6z
	vmaddw.wxyz	$vf6,$vf4,vf6w
	vmulax.wxyz	ACC,$vf1,vf7x
	vmadday.wxyz	ACC,$vf2,vf7y
	vmaddaz.wxyz	ACC,$vf3,vf7z
	vmaddw.wxyz	$vf7,$vf4,vf7w
	vmulax.wxyz	ACC,$vf1,vf8x
	vmadday.wxyz	ACC,$vf2,vf8y
	vmaddaz.wxyz	ACC,$vf3,vf8z
	vmaddw.wxyz	$vf8,$vf4,vf8w
	sqc2	$vf5,0($14)
	sqc2	$vf6,16($14)
	sqc2	$vf7,32($14)
	sqc2	$vf8,48($14)
	beql	$21,$14,.L00193920
	lhu	$15,1398($17)
	lq	$8,0($14)
	lq	$9,16($14)
	lq	$10,32($14)
	lq	$11,48($14)
	sq	$8,0($21)
	sq	$9,16($21)
	sq	$10,32($21)
	sq	$11,48($21)
	lhu	$15,1398($17)
.L00193920:
	srl	$15,$15,0x1
	andi	$15,$15,0x1
	andi	$15,$15,0xff
	beqz	$15,.L0019396c
	addiu	$16,$29,112
	beq	$29,$16,.L00193948
	lui	$6,%hi(D_01c61ae0)
	lq	$8,0($16)
	sq	$8,0($29)
	lui	$6,%hi(D_01c61ae0)
.L00193948:
	move	$5,$23
	move	$4,$17
	addiu	$6,$6,%lo(D_01c61ae0)
	jal	func_00193be8
	move	$7,$21
	beql	$16,$29,.L00193970
	addiu	$16,$17,64
	lq	$8,0($29)
	sq	$8,0($16)
.L0019396c:
	addiu	$16,$17,64
.L00193970:
	beq	$16,$21,.L00193998
	nop
	lq	$8,0($21)
	lq	$9,16($21)
	lq	$10,32($21)
	lq	$11,48($21)
	sq	$8,0($16)
	sq	$9,16($16)
	sq	$10,32($16)
	sq	$11,48($16)
.L00193998:
	jal	func_0019bad8
	move	$4,$17
	beqz	$2,.L00193abc
	nop
	lw	$15,1636($17)
	beqz	$15,.L00193abc
	move	$4,$17
	jal	func_0019c090
	move	$18,$0
	bnezl	$2,.L001939fc
	li	$18,1
	lw	$14,12($17)
	lw	$15,8($14)
	andi	$15,$15,0x2
	bnez	$15,.L001939e8
	move	$13,$0
	lw	$15,352($17)
	andi	$15,$15,0x40
	beqz	$15,.L001939f0
	andi	$15,$13,0xff
.L001939e8:
	li	$13,1
	andi	$15,$13,0xff
.L001939f0:
	beqz	$15,.L00193a00
	xori	$15,$18,0x1
	li	$18,1
.L001939fc:
	xori	$15,$18,0x1
.L00193a00:
	beqz	$15,.L00193abc
	nop
	jal	func_001c0cd8
	move	$4,$17
	bnez	$2,.L00193abc
	move	$4,$17
	jal	func_00193d38
	move	$5,$16
	lqc2	$vf4,0($22)
	lqc2	$vf1,0($16)
	lqc2	$vf2,16($16)
	lqc2	$vf3,32($16)
	vmulx.wxyz	$vf1,$vf1,vf4x
	vmuly.wxyz	$vf2,$vf2,vf4y
	vmulz.wxyz	$vf3,$vf3,vf4z
	sqc2	$vf1,0($16)
	sqc2	$vf2,16($16)
	sqc2	$vf3,32($16)
	addiu	$15,$17,112
	beq	$15,$19,.L00193a60
	lui	$14,0x37
	lq	$8,0($19)
	sq	$8,0($15)
	lui	$14,0x37
.L00193a60:
	addiu	$14,$14,-12596
	lwc1	$f0,0($14)
	swc1	$f0,12($15)
.L00193a6c:
	lw	$4,2088($17)
.L00193a70:
	beqz	$4,.L00193a80
	nop
	jal	func_001b78d0
	nop
.L00193a80:
	jal	func_00193e88
	move	$4,$17
	ld	$16,416($29)
	ld	$17,424($29)
	ld	$18,432($29)
	ld	$19,440($29)
	ld	$20,448($29)
	ld	$21,456($29)
	ld	$22,464($29)
	ld	$23,472($29)
	ld	$31,480($29)
	lwc1	$f21,492($29)
	lwc1	$f20,488($29)
	jr	$31
	addiu	$29,$29,496
.L00193abc:
	jal	func_0016a070
	move	$4,$17
	li	$15,5067
	bnel	$2,$15,.L00193a70
	lw	$4,2088($17)
	lw	$15,1636($17)
	beqz	$15,.L00193a6c
	move	$4,$17
	jal	func_0019c090
	move	$18,$0
	bnezl	$2,.L00193b24
	li	$18,1
	lw	$14,12($17)
	lw	$15,8($14)
	andi	$15,$15,0x2
	bnez	$15,.L00193b10
	move	$13,$0
	lw	$15,352($17)
	andi	$15,$15,0x40
	beqz	$15,.L00193b18
	andi	$15,$13,0xff
.L00193b10:
	li	$13,1
	andi	$15,$13,0xff
.L00193b18:
	beqz	$15,.L00193b28
	xori	$15,$18,0x1
	li	$18,1
.L00193b24:
	xori	$15,$18,0x1
.L00193b28:
	beqz	$15,.L00193a6c
	addiu	$19,$29,32
	addiu	$18,$17,112
	beq	$19,$18,.L00193b48
	move	$4,$17
	lq	$8,0($18)
	sq	$8,0($19)
	move	$4,$17
.L00193b48:
	jal	func_00193d38
	move	$5,$16
	lqc2	$vf4,0($22)
	lqc2	$vf1,0($16)
	lqc2	$vf2,16($16)
	lqc2	$vf3,32($16)
	vmulx.wxyz	$vf1,$vf1,vf4x
	vmuly.wxyz	$vf2,$vf2,vf4y
	vmulz.wxyz	$vf3,$vf3,vf4z
	sqc2	$vf1,0($16)
	sqc2	$vf2,16($16)
	sqc2	$vf3,32($16)
	beq	$18,$19,.L00193b8c
	lui	$15,0x37
	lq	$8,0($19)
	sq	$8,0($18)
	lui	$15,0x37
.L00193b8c:
	addiu	$15,$15,-12596
	lwc1	$f0,0($15)
	b	.L00193a6c
	swc1	$f0,12($18)
	nop
.L00193ba0:
	addiu	$19,$17,1344
	addiu	$15,$29,112
	beql	$15,$19,.L0019396c
	swc1	$f20,124($29)
	lq	$8,0($19)
	sq	$8,0($15)
	b	.L0019396c
	swc1	$f20,124($29)
.L00193bc0:
	addiu	$21,$29,64
	lui	$6,%hi(D_01c61ae0)
	move	$4,$17
	addiu	$6,$6,%lo(D_01c61ae0)
	move	$5,$23
	jal	func_00193be8
	move	$7,$21
	b	.L0019368c
	addiu	$14,$17,48
	.end func_00193608
	.size func_00193608, 1500

