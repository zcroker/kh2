# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
# libcdvd (Sony PS2 Runtime Library 3.0.0), 0x2f7418: maps an RPC function number (0x8001-0x8004, 0x8011-0x8014)
# to its result buffer and stores it through a1; returns 1. Plain C in the original (ee-gcc 2.9), never matched in C:
# retail is an equality chain with out-of-line bodies; every if/switch form tried gave inline bodies or a jump table
# (ledger best/002f7418_L70.c). Linked as assembly to close out linking; convert later.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_002f7418,"ax",@progbits
	.align 2
	.globl func_002f7418
	.type func_002f7418, @function
	.ent func_002f7418
func_002f7418:
	li	$2,0x8001
	beq	$4,$2,.L002f74b8
	lui	$2,0x36
	li	$2,0x8003
	beq	$4,$2,.L002f74b0
	lui	$2,0x36
	li	$2,0x8002
	beq	$4,$2,.L002f74a8
	lui	$2,0x36
	li	$2,0x8004
	beq	$4,$2,.L002f74a0
	lui	$2,0x36
	li	$2,0x8011
	beq	$4,$2,.L002f7490
	li	$2,0x8013
	beq	$4,$2,.L002f7488
	lui	$2,0x36
	li	$2,0x8012
	beq	$4,$2,.L002f7480
	lui	$2,0x36
	li	$2,0x8014
	bnel	$4,$2,.L002f74bc
	move	$2,$0
	lui	$2,0x36
	b	.L002f74bc
	addiu	$2,$2,22784
.L002f7480:
	b	.L002f74bc
	addiu	$2,$2,21440
.L002f7488:
	b	.L002f74bc
	addiu	$2,$2,20352
.L002f7490:
	lui	$2,0x36
	lw	$2,15788($2)
	b	.L002f74c0
	sw	$2,0($5)
.L002f74a0:
	b	.L002f74bc
	addiu	$2,$2,20304
.L002f74a8:
	b	.L002f74bc
	addiu	$2,$2,16000
.L002f74b0:
	b	.L002f74bc
	addiu	$2,$2,15872
.L002f74b8:
	lw	$2,15784($2)
.L002f74bc:
	sw	$2,0($5)
.L002f74c0:
	jr	$31
	li	$2,1
	.end func_002f7418
	.size func_002f7418, 176
