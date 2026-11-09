# Kept as assembly after long C attempts (see the coord ledger). Both functions miss
# only on sched2 tie order (epilogue ld s0 / lui v0 for 001c3f58, prologue sd ra /
# sd s0 for 002ce958), which no C form found so far reproduces. Globals with no
# symbol in the build (D_01d49568, D_00361f40) are written as plain addresses.
	.set noreorder
	.set noat
	.set nomacro

# R* func_001c3f58(s32 id): find the table entry with this id and the current
# kind, and fill the static result record D_01d49570 from it.
	.section .text.func_001c3f58,"ax",@progbits
	.align 2
	.globl func_001c3f58
	.type func_001c3f58, @function
	.ent func_001c3f58
func_001c3f58:
	addiu	$29,$29,-48
	sd	$16,16($29)
	sd	$17,24($29)
	sd	$31,32($29)
	jal	func_001b6d70
	move	$16,$4
	lui	$11,0x1d5
	move	$12,$0
	lw	$15,-27288($11)
	lw	$14,4($15)
	blez	$14,.L001c3fe0
	addiu	$13,$15,8
	lui	$15,%hi(D_01d49570)
	li	$9,0xffff
	addiu	$10,$15,%lo(D_01d49570)
	addiu	$8,$10,4
.L001c3f98:
	lbu	$15,0($13)
	bne	$15,$16,.L001c4030
	lw	$14,-27288($11)
	lbu	$14,1($13)
	lbu	$15,1($2)
	bnel	$14,$15,.L001c4030
	lw	$14,-27288($11)
	lbu	$5,2($13)
	sltiu	$15,$5,51
	beq	$15,$0,.L001c3ffc
	lui	$17,%hi(D_01d49570)
	lbu	$15,3($13)
	sh	$9,4($8)
	sb	$16,%lo(D_01d49570)($17)
	sb	$5,1($10)
	sb	$15,2($10)
	sh	$9,4($10)
	sh	$9,2($8)
.L001c3fe0:
	ld	$16,16($29)
.L001c3fe4:
	lui	$2,%hi(D_01d49570)
	addiu	$2,$2,%lo(D_01d49570)
	ld	$17,24($29)
	ld	$31,32($29)
	jr	$31
	addiu	$29,$29,48
.L001c3ffc:
	move	$6,$16
	jal	func_00199718
	move	$4,$29
	addiu	$15,$17,%lo(D_01d49570)
	ldl	$12,7($29)
	ldr	$12,0($29)
	lh	$13,8($29)
	sdl	$12,7($15)
	sdr	$12,0($15)
	sh	$13,8($15)
	b	.L001c3fe4
	ld	$16,16($29)
	nop
.L001c4030:
	addiu	$12,$12,1
	lw	$15,4($14)
	slt	$15,$12,$15
	bne	$15,$0,.L001c3f98
	addiu	$13,$13,4
	b	.L001c3fe4
	ld	$16,16($29)
	.end func_001c3f58
	.size func_001c3f58, .-func_001c3f58

# void func_002ce958(T* p, s32 a, s32 b, s32 c): set up the object, register it
# as the current one in D_00361f60, then call the init helpers.
	.section .text.func_002ce958,"ax",@progbits
	.align 2
	.globl func_002ce958
	.type func_002ce958, @function
	.ent func_002ce958
func_002ce958:
	lui	$15,%hi(D_00361f70)
	sb	$0,4($4)
	addiu	$15,$15,%lo(D_00361f70)
	sw	$0,92($4)
	sw	$15,0($4)
	addiu	$29,$29,-16
	sw	$0,96($4)
	sd	$31,8($29)
	lui	$15,%hi(D_00361f60)
	sd	$16,0($29)
	sw	$4,%lo(D_00361f60)($15)
	sw	$5,80($4)
	move	$16,$7
	sw	$6,84($4)
	sb	$0,88($4)
	lui	$5,0x36
	addiu	$5,$5,0x1f40
	jal	func_002cedd0
	li	$4,2
	jal	func_002cf320
	move	$4,$16
	ld	$16,0($29)
	ld	$31,8($29)
	j	func_002e7500
	addiu	$29,$29,16
	.end func_002ce958
	.size func_002ce958, .-func_002ce958
