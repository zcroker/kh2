# Kept as assembly: -O0 code with gp-relative addresses, which the -G0 build cannot emit from C.
	.set noreorder
	.set noat
	.set nomacro
	.section .text._Z13func_002b6d34Pv,"ax",@progbits
	.align 2
	.globl func_002b6d34
	.type func_002b6d34, @function
	.globl _Z13func_002b6d34Pv
	.type _Z13func_002b6d34Pv, @function
	.ent func_002b6d34
func_002b6d34:
_Z13func_002b6d34Pv:
	addiu	$29,$29,-48
	sd	$30,32($29)
	sd	$31,40($29)
	move	$30,$29
	sw	$4,0($30)
	sw	$5,4($30)
	sw	$6,8($30)
	lw	$15,4($30)
	sw	$15,12($30)
	lw	$15,12($30)
	lb	$14,0($15)
	li	$15,66
	bne	$14,$15,.L002b6d88
	nop
	lw	$15,12($30)
	lb	$14,1($15)
	li	$15,71
	bne	$14,$15,.L002b6d88
	nop
	b	.L002b6dd8
	nop
.L002b6d88:
	lui	$4,0x37
	addiu	$4,$4,19928
	lui	$5,0x33
	lw	$5,-18144($5)
	jal	0x2fdfc8
	nop
	lui	$4,0x37
	jal	0x2fdfc8
	addiu	$4,$4,20032
	addiu	$4,$28,-7480
	jal	0x2fdfc8
	nop
	lw	$4,4($30)
	jal	0x2b6550
	li	$5,8
	addiu	$4,$28,-7472
	jal	0x2fdfc8
	nop
	b	.L002b6e0c
	sw	$0,16($30)
.L002b6dd8:
	jal	0x2b7078
	lw	$4,0($30)
	li	$4,1
	jal	0x2b6adc
	lw	$5,0($30)
	li	$4,4
	li	$5,12
	lw	$6,0($30)
	lw	$7,4($30)
	jal	0x2b6708
	lw	$8,8($30)
	move	$15,$2
	sw	$15,16($30)
.L002b6e0c:
	lw	$2,16($30)
	move	$29,$30
	ld	$30,32($29)
	ld	$31,40($29)
	jr	$31
	addiu	$29,$29,48
	.end func_002b6d34
	.size func_002b6d34, 240
	.size _Z13func_002b6d34Pv, 240
