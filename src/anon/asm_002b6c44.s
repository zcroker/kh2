# Kept as assembly: -O0 code with gp-relative addresses, which the -G0 build cannot emit from C.
	.set noreorder
	.set noat
	.set nomacro
	.section .text._Z16wtarget_002b6c44jjjj,"ax",@progbits
	.align 2
	.globl func_002b6c44
	.type func_002b6c44, @function
	.globl _Z16wtarget_002b6c44jjjj
	.type _Z16wtarget_002b6c44jjjj, @function
	.ent func_002b6c44
func_002b6c44:
_Z16wtarget_002b6c44jjjj:
	addiu	$29,$29,-48
	sd	$30,32($29)
	sd	$31,40($29)
	move	$30,$29
	sw	$4,0($30)
	sw	$5,4($30)
	sw	$6,8($30)
	sw	$7,12($30)
	lw	$15,4($30)
	sw	$15,16($30)
	lw	$15,16($30)
	lb	$14,0($15)
	li	$15,87
	bne	$14,$15,.L002b6c9c
	nop
	lw	$15,16($30)
	lb	$14,1($15)
	li	$15,68
	bne	$14,$15,.L002b6c9c
	nop
	b	.L002b6cec
	nop
.L002b6c9c:
	lui	$4,0x37
	addiu	$4,$4,19928
	lui	$5,0x33
	lw	$5,-18144($5)
	jal	0x2fdfc8
	nop
	lui	$4,0x37
	jal	0x2fdfc8
	addiu	$4,$4,20000
	addiu	$4,$28,-7480
	jal	0x2fdfc8
	nop
	lw	$4,4($30)
	jal	0x2b6550
	li	$5,8
	addiu	$4,$28,-7472
	jal	0x2fdfc8
	nop
	b	.L002b6d1c
	sw	$0,20($30)
.L002b6cec:
	move	$4,$0
	jal	0x2b6adc
	lw	$5,0($30)
	li	$4,5
	li	$5,11
	lw	$6,0($30)
	lw	$7,4($30)
	lw	$8,8($30)
	jal	0x2b6708
	lw	$9,12($30)
	move	$15,$2
	sw	$15,20($30)
.L002b6d1c:
	lw	$2,20($30)
	move	$29,$30
	ld	$30,32($29)
	ld	$31,40($29)
	jr	$31
	addiu	$29,$29,48
	.end func_002b6c44
	.size func_002b6c44, 240
	.size _Z16wtarget_002b6c44jjjj, 240
