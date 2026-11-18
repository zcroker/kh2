# Kept as assembly after long C attempts (see the ledger ledger). Both functions miss
# only on sched2 tie order (epilogue ld s0 / lui v0 for 001c3f58, prologue sd ra /
# sd s0 for 002ce958), which no C form found so far reproduces. Globals with no
# symbol in the build (D_01d49568, D_00361f40) are written as plain addresses.
	.set noreorder
	.set noat
	.set nomacro

# R* func_001c3f58(s32 id): find the table entry with this id and the current
# kind, and fill the static result record D_01d49570 from it.
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

# func_002ce9c0: never-written gap right after func_002ce958 with the same bytes
# (probably its constructor twin); linked here as the same assembly.
	.section .text.func_002ce9c0,"ax",@progbits
	.align 3
	.globl func_002ce9c0
	.type func_002ce9c0, @function
	.ent func_002ce9c0
func_002ce9c0:
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
	.end func_002ce9c0
	.size func_002ce9c0, .-func_002ce9c0
