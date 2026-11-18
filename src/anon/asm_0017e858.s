# Whole-function assembly: gap code that was never written in C (not in layout.tsv before; L77 2026-11-18).
# Transcribed from the retail disassembly; calls and globals with a func_/D_ symbol are referenced
# through it. Linked as its own unit (close-out of linking); replace with C/C++ later.
#   No C draft saved.
#     No symbol, written as literal lui/lo values: 0x0036c588, 0x0036c58c, 0x0036c590
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_0017e858,"ax",@progbits
	.align 3
	.globl func_0017e858
	.type func_0017e858, @function
	.ent func_0017e858
func_0017e858:
	addiu	$29,$29,-32
	sw	$0,0($4)
	sd	$16,0($29)
	li	$15,-1
	sd	$17,8($29)
	addiu	$11,$4,60
	move	$16,$4
	sd	$31,16($29)
	sw	$5,8($16)
	move	$17,$5
	sw	$15,28($4)
	addiu	$14,$4,68
	sw	$0,4($4)
	li	$13,3
	sw	$0,12($4)
	li	$12,-1
	sw	$0,16($4)
	sw	$15,20($4)
	sw	$15,24($4)
	sw	$0,32($4)
	sw	$0,36($4)
	sw	$0,40($4)
.L0017e8b0:
	sw	$0,16($14)
	addiu	$13,$13,-1
	nop
	nop
	nop
	bne	$13,$12,.L0017e8b0
	addiu	$14,$14,20
	lui	$14,0x37
	sw	$0,4($11)
	addiu	$14,$14,-14968
	sw	$0,0($11)
	lwc1	$f12,0($14)
	addiu	$15,$16,176
	mtc1	$0,$f0
	addiu	$4,$16,216
	lui	$14,0x37
	sw	$0,152($16)
	addiu	$14,$14,-14964
	sw	$0,148($16)
	lwc1	$f15,0($14)
	swc1	$f0,12($15)
	swc1	$f0,4($15)
	swc1	$f0,8($15)
	mov.s	$f13,$f12
	mov.s	$f14,$f12
	sw	$0,208($16)
	mov.s	$f16,$f15
	sw	$0,212($16)
	mov.s	$f17,$f15
	jal	func_00144490
	swc1	$f0,176($16)
	lui	$14,0x37
	sw	$0,252($16)
	addiu	$14,$14,-14960
	sw	$0,256($16)
	addiu	$15,$17,128
	lwc1	$f0,0($14)
	sw	$15,240($16)
	li	$13,-1
	swc1	$f0,244($16)
	li	$14,7
	sw	$0,260($16)
	addiu	$15,$16,264
.L0017e95c:
	sw	$0,0($15)
	addiu	$14,$14,-1
	nop
	nop
	nop
	bne	$14,$13,.L0017e95c
	addiu	$15,$15,8
	sw	$0,328($16)
	move	$4,$16
	sw	$0,400($16)
	sw	$0,396($16)
	sw	$0,404($16)
	jal	func_0017fdf8
	sw	$0,440($16)
	addiu	$4,$16,332
	li	$14,-1
	li	$15,15
.L0017e9a0:
	sw	$14,0($4)
	addiu	$15,$15,-1
	nop
	nop
	nop
	bgez	$15,.L0017e9a0
	addiu	$4,$4,4
	ld	$16,0($29)
	ld	$17,8($29)
	ld	$31,16($29)
	jr	$31
	addiu	$29,$29,32
	.end func_0017e858
	.size func_0017e858, 376
