# Whole-function assembly (last step of the README ladder, 2026-11-09, zl90 w3891, carried by w3901).
# func_003241a0: compiler-generated constructor of a large game object (A[9][8], A, 3 B, B[9], B[9]
# via placement new). C++ drafts stay at about 37-54 differing lines: global-alloc choice of
# saved registers for the x[9] loop (original keeps 8/-1 in s7/s8 and the element pointer in s3,
# rematerialising the vtables) and gcse sharing of vtable addresses. See coord attempts.tsv and
# best/003241a0_w3891.cpp and best/003241a0_w3901.cpp. Replace with C/C++ after 100%.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_003241a0,"ax",@progbits
	.align 2
	.globl func_003241a0
	.type func_003241a0, @function
	.ent func_003241a0
func_003241a0:
	addiu	$29,$29,-80
	lui	$15,0x34
	sd	$18,16($29)
	sd	$19,24($29)
	sd	$20,32($29)
	move	$18,$4
	sd	$21,40($29)
	li	$19,-1
	sd	$22,48($29)
	addiu	$20,$15,32352
	sd	$23,56($29)
	li	$21,8
	sd	$16,0($29)
	move	$22,$4
	sd	$17,8($29)
	li	$23,-1
	sd	$30,64($29)
	sd	$31,72($29)
.L003241e8:
	move	$16,$18
	li	$17,7
.L003241f0:
	sw	$0,12($16)
	addiu	$4,$16,24
	sw	$20,0($16)
	jal	0x239700
	addiu	$17,$17,-1
	bne	$17,$19,.L003241f0
	addiu	$16,$16,408
	addiu	$21,$21,-1
	bne	$21,$23,.L003241e8
	addiu	$18,$18,3264
	lui	$16,0x34
	sw	$0,29388($22)
	addiu	$16,$16,32352
	addiu	$4,$22,29400
	sw	$16,29376($22)
	lui	$18,0x34
	addiu	$18,$18,32664
	jal	0x239700
	addiu	$19,$22,29784
	lui	$17,0x34
	sw	$18,29784($22)
	addiu	$4,$22,29796
	addiu	$17,$17,32320
	jal	0x31a838
	addiu	$20,$22,30220
	addiu	$21,$22,30656
	sw	$16,29784($22)
	addiu	$4,$22,29808
	li	$23,8
	jal	0x239700
	li	$30,-1
	sw	$0,408($19)
	addiu	$4,$22,30232
	sw	$17,29784($22)
	sw	$18,30220($22)
	jal	0x31a838
	addiu	$19,$22,31092
	sw	$16,30220($22)
	jal	0x239700
	addiu	$4,$22,30244
	sw	$0,408($20)
	addiu	$4,$22,30668
	sw	$17,30220($22)
	jal	0x31a838
	sw	$18,30656($22)
	sw	$16,30656($22)
	jal	0x239700
	addiu	$4,$22,30680
	sw	$0,408($21)
	sw	$17,30656($22)
.L003242b8:
	lui	$15,0x34
	addiu	$4,$19,12
	addiu	$15,$15,32664
	addiu	$23,$23,-1
	jal	0x31a838
	sw	$15,0($19)
	lui	$15,0x34
	addiu	$4,$19,24
	addiu	$15,$15,32352
	jal	0x239700
	sw	$15,0($19)
	lui	$15,0x34
	sw	$0,408($19)
	addiu	$15,$15,32320
	sw	$15,0($19)
	bne	$23,$30,.L003242b8
	addiu	$19,$19,436
	li	$15,0x88c8
	lui	$14,0x34
	addu	$19,$22,$15
	addiu	$21,$14,32664
	lui	$15,0x34
	lui	$14,0x34
	addiu	$20,$15,32352
	addiu	$18,$14,32320
	li	$16,8
	li	$17,-1
.L00324324:
	sw	$21,0($19)
	addiu	$4,$19,12
	jal	0x31a838
	addiu	$16,$16,-1
	sw	$20,0($19)
	jal	0x239700
	addiu	$4,$19,24
	sw	$18,0($19)
	sw	$0,408($19)
	bne	$16,$17,.L00324324
	addiu	$19,$19,436
	ld	$16,0($29)
	ld	$17,8($29)
	ld	$18,16($29)
	ld	$19,24($29)
	ld	$20,32($29)
	ld	$21,40($29)
	ld	$22,48($29)
	ld	$23,56($29)
	ld	$30,64($29)
	ld	$31,72($29)
	jr	$31
	addiu	$29,$29,80
	.end func_003241a0
	.size func_003241a0, .-func_003241a0
