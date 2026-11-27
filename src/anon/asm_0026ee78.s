# Kept as assembly (whole function, last step of the match ladder, helper w3916 2026-11-10).
# Tz__CmCustom__SetupTop: creates up to four menu entry objects (one per active slot) and, for slot 0, a linked label.
#   Closest C: best/0026ee78_w3916.cpp under -fmove-all-movables (20 lines off): the original copies the
#   func_00257770 result s0 -> s5 before the loop and puts o in s1 / the 0x87d0 pointer in s0; giv, copy and
#   asm-copy forms did not reproduce it.
# func_002af418: builds ten list rows (two labels each) and counts flagged entries.
#   Closest C: best/002af418_w3916.cpp (frame and spill slots match with volatile a/sz; the original keeps
#   hi(D_0035f3d4) in s4 across five calls and b in s8, ours rematerialises the lui).
# Split out of batch_w3916.s on 2026-11-18 to link it as its own unit.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0026ee78,"ax",@progbits
	.globl Tz__CmCustom__SetupTop
	.type Tz__CmCustom__SetupTop, @function
	.ent Tz__CmCustom__SetupTop
Tz__CmCustom__SetupTop:
	addiu	$29,$29,-96
	sd	$16,16($29)
	sd	$18,32($29)
	sd	$19,40($29)
	sd	$20,48($29)
	sd	$21,56($29)
	move	$19,$0
	sd	$22,64($29)
	move	$20,$0
	sd	$23,72($29)
	sd	$31,88($29)
	lui	$22,0x36
	sd	$17,24($29)
	sd	$30,80($29)
	jal	0x257770
	lui	$23,0x36
	move	$16,$2
	move	$4,$0
	li	$5,-1
	jal	0x28f4d8
	move	$6,$0
	move	$21,$16
	lui	$14,0x36
	li	$15,30017
	lw	$18,-3116($14)
	sw	$15,-3116($14)
	lw	$4,-4080($23)
.L0026eee4:
	jal	0x281180
	move	$5,$19
	beqz	$2,.L0026f028
	move	$4,$0
	jal	0x257100
	nop
	move	$16,$2
	jal	0x257100
	li	$4,1
	lui	$14,0x36
	lw	$4,-4068($22)
	lw	$8,-4036($14)
	lui	$15,0x36
	lw	$6,-4248($15)
	move	$11,$2
	lui	$14,0x36
	move	$10,$16
	lw	$7,-4252($14)
	li	$9,-1
	jal	0x288d80
	move	$5,$20
	lw	$4,-4068($22)
	jal	0x2891b8
	move	$5,$20
	lw	$4,-4068($22)
	move	$17,$2
	move	$6,$0
	li	$7,-1
	jal	0x288e08
	move	$5,$20
	addiu	$20,$20,1
	jal	0x139620
	move	$4,$17
	lw	$4,-4080($23)
	jal	0x281140
	move	$5,$19
	sw	$2,408($17)
	jal	0x1395f8
	move	$4,$17
	bnez	$19,.L0026f024
	li	$4,-1
	lui	$14,0x36
	lw	$15,-3116($14)
	jal	0x286068
	addiu	$30,$15,1
	beqz	$2,.L0026f024
	li	$4,-1
	jal	0x286160
	li	$16,0x87d0
	addiu	$15,$17,24
	lui	$14,0x37
	sw	$15,0($29)
	addu	$16,$21,$16
	li	$10,-1
	move	$11,$0
	lw	$15,14832($14)
	move	$5,$30
	move	$4,$16
	lui	$14,0x37
	lw	$9,14828($14)
	movn	$9,$15,$2
	lui	$14,0x36
	lui	$15,0x36
	lw	$7,-4252($14)
	lw	$6,-4248($15)
	lui	$15,0x36
	jal	0x28d8c0
	lw	$8,-4036($15)
	move	$5,$17
	jal	0x28dcc0
	move	$4,$16
	jal	0x23aa18
	lw	$4,0($29)
	lw	$4,0($29)
	jal	0x23aa38
	move	$17,$2
	move	$6,$2
	move	$4,$16
	jal	0x138c68
	move	$5,$17
.L0026f024:
	addiu	$21,$21,408
.L0026f028:
	addiu	$19,$19,1
	slti	$15,$19,4
	bnezl	$15,.L0026eee4
	lw	$4,-4080($23)
	jal	0x257070
	li	$4,25
	lui	$15,0x36
	move	$5,$2
	lw	$4,-4068($15)
	li	$6,1
	move	$7,$0
	jal	0x2891f0
	li	$8,2
	jal	0x287cc0
	move	$4,$0
	lui	$15,0x36
	jal	0x271900
	sw	$18,-3116($15)
	ld	$16,16($29)
	ld	$17,24($29)
	ld	$18,32($29)
	ld	$19,40($29)
	ld	$20,48($29)
	ld	$21,56($29)
	ld	$22,64($29)
	ld	$23,72($29)
	ld	$30,80($29)
	ld	$31,88($29)
	j	0x271b78
	addiu	$29,$29,96
	.end Tz__CmCustom__SetupTop
	.size Tz__CmCustom__SetupTop, .-Tz__CmCustom__SetupTop
