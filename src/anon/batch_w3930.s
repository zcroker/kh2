# Kept as assembly (whole function, last step of the match ladder, w3930 2026-11-10).
# func_0015af48 (wtarget_0015af48): allocates the target-system objects through the heap allocator
#   (one 0x24 list, one 0x1b8 object, then a 0x340 or 0x24 object depending on func_001492f8/func_00149300).
#   Closest C: ~/re/kh2/tmp.w3930/best_0015af48_nsa.cpp (= coord best/0015af48_w3918.cpp, about 100 lines off
#   under _nsa): the original keeps gcse copies (move s6,s2 = hi of D_00347f80; move s4,s5 = base vtable) for
#   the small arm; our cprop folds them back and no flag or source shape stops it.
#   The vtables 0x0034ab18, 0x0034aaf8 and 0x0034aab8 have no linker symbol, so they are written as literal lui/addiu values.
	.set noreorder
	.set noat
	.set nomacro
	.section .text._Z16wtarget_0015af48jjjj,"ax",@progbits
	.align 2
	.globl func_0015af48
	.type func_0015af48, @function
	.globl _Z16wtarget_0015af48jjjj
	.type _Z16wtarget_0015af48jjjj, @function
	.ent func_0015af48
func_0015af48:
_Z16wtarget_0015af48jjjj:
	lui	$15,%hi(D_0034aaac)
	addiu	$29,$29,-64
	sw	$4,%lo(D_0034aaac)($15)
	li	$5,36
	sd	$18,16($29)
	move	$6,$0
	lui	$15,%hi(D_0034aa98)
	sd	$17,8($29)
	sw	$0,%lo(D_0034aa98)($15)
	lui	$18,%hi(D_00347f80)
	sd	$31,56($29)
	move	$17,$4
	sd	$16,0($29)
	sd	$19,24($29)
	sd	$20,32($29)
	sd	$21,40($29)
	sd	$22,48($29)
	lw	$15,%lo(D_00347f80)($18)
	lw	$4,20($15)
	lw	$14,0($4)
	lw	$2,0($14)
	jalr	$2
	move	$22,$18
	lui	$15,0x35
	sw	$0,12($2)
	addiu	$15,$15,-21736
	lui	$14,%hi(D_00347f98)
	sw	$15,0($2)
	addiu	$21,$14,%lo(D_00347f98)
	li	$5,440
	move	$6,$0
	lui	$15,%hi(D_0034aaa0)
	sw	$2,%lo(D_0034aaa0)($15)
	lw	$15,%lo(D_00347f80)($18)
	lw	$4,20($15)
	lw	$14,0($4)
	lw	$2,0($14)
	jalr	$2
	move	$20,$21
	move	$16,$2
	addiu	$4,$2,12
	jal	func_0031a838
	sw	$21,0($16)
	lui	$15,%hi(D_00347e60)
	addiu	$4,$16,24
	addiu	$19,$15,%lo(D_00347e60)
	jal	func_00239700
	sw	$19,0($16)
	lui	$15,0x35
	sw	$0,408($16)
	addiu	$15,$15,-21768
	lui	$14,%hi(D_0034aa9c)
	sw	$15,0($16)
	move	$4,$17
	jal	func_001492f8
	sw	$16,%lo(D_0034aa9c)($14)
	move	$16,$2
	jal	func_00149300
	move	$4,$17
	beqz	$16,.L0015b048
	lw	$14,%lo(D_00347f80)($22)
	bnez	$2,.L0015b0ac
	lw	$14,%lo(D_00347f80)($18)
	lw	$14,%lo(D_00347f80)($22)
.L0015b048:
	li	$5,36
	lw	$4,20($14)
	lw	$15,0($4)
	lw	$2,0($15)
	jalr	$2
	move	$6,$0
	sw	$20,0($2)
	move	$16,$2
	jal	func_0031a838
	addiu	$4,$2,12
	lui	$15,0x35
	lui	$14,%hi(D_0034aaa8)
	addiu	$15,$15,-21832
	sw	$15,0($16)
	sw	$16,%lo(D_0034aaa8)($14)
.L0015b084:
	ld	$16,0($29)
	ld	$17,8($29)
	ld	$18,16($29)
	ld	$19,24($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	ld	$31,56($29)
	jr	$31
	addiu	$29,$29,64
.L0015b0ac:
	li	$5,832
	lw	$4,20($14)
	lw	$15,0($4)
	lw	$2,0($15)
	jalr	$2
	move	$6,$0
	sw	$21,0($2)
	move	$16,$2
	jal	func_0031a838
	addiu	$4,$2,12
	sw	$19,0($16)
	jal	func_00239700
	addiu	$4,$16,24
	lui	$15,%hi(D_0034aad8)
	addiu	$4,$16,416
	addiu	$15,$15,%lo(D_0034aad8)
	jal	func_002361a0
	sw	$15,0($16)
	lui	$15,%hi(D_0034aaa4)
	b	.L0015b084
	sw	$16,%lo(D_0034aaa4)($15)
	.end func_0015af48
	.size func_0015af48, 440
	.size _Z16wtarget_0015af48jjjj, 440

