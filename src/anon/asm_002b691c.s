# Kept as assembly: -O0 code with gp-relative addresses, which the -G0 build cannot emit from C.
	.set noreorder
	.set noat
	.set nomacro
	.section .text._Z16u_call4_002b691cjjjj,"ax",@progbits
	.align 2
	.globl func_002b691c
	.type func_002b691c, @function
	.globl _Z16u_call4_002b691cjjjj
	.type _Z16u_call4_002b691cjjjj, @function
	.ent func_002b691c
func_002b691c:
_Z16u_call4_002b691cjjjj:
	addiu	$29,$29,-48
	sd	$30,32($29)
	sd	$31,40($29)
	move	$30,$29
	sw	$4,16($30)
	lui	$4,0x1e2
	addiu	$4,$4,8320
	move	$5,$0
	jal	0x2fde18
	li	$6,0x8000
	lui	$4,0x1e2
	addiu	$4,$4,8000
	move	$5,$0
	jal	0x2fde18
	li	$6,256
.L002b6958:
	lui	$4,0x1e2
	addiu	$4,$4,8256
	li	$5,17
	jal	0x3092d8
	move	$6,$0
	move	$15,$2
	bgez	$15,.L002b69a8
	nop
	lui	$4,0x37
	addiu	$4,$4,19928
	lui	$5,0x33
	lw	$5,-18144($5)
	jal	0x2fdfc8
	nop
	lui	$4,0x37
	jal	0x2fdfc8
	addiu	$4,$4,19976
	li	$15,-1
	b	.L002b6aa0
	sw	$15,28($30)
.L002b69a8:
	lui	$15,0x1e2
	addiu	$15,$15,8292
	lw	$15,0($15)
	beqz	$15,.L002b69c4
	nop
	b	.L002b69f0
	nop
.L002b69c4:
	lui	$15,0x1
	sw	$15,20($30)
.L002b69cc:
	lw	$15,20($30)
	addiu	$15,$15,-1
	move	$14,$15
	sw	$14,20($30)
	li	$15,-1
	bne	$14,$15,.L002b69cc
	nop
	b	.L002b6958
	nop
.L002b69f0:
	lw	$15,16($30)
	lui	$1,0x1e2
	sw	$15,8000($1)
	lui	$14,0x1e2
	addiu	$14,$14,8004
	lui	$15,0x1e3
	addiu	$15,$15,-24448
	sw	$15,0($14)
	lui	$14,0x1e2
	addiu	$14,$14,8008
	lui	$15,0x1e2
	addiu	$15,$15,8320
	sw	$15,0($14)
	lui	$14,0x1e2
	addiu	$14,$14,8012
	lui	$15,0x1e3
	addiu	$15,$15,-23616
	sw	$15,0($14)
.L002b6a38:
	sw	$0,0($29)
	lui	$4,0x1e2
	addiu	$4,$4,8256
	move	$5,$0
	move	$6,$0
	lui	$7,0x1e2
	addiu	$7,$7,8000
	li	$8,256
	lui	$9,0x1e2
	addiu	$9,$9,8000
	li	$10,256
	jal	0x3094b8
	move	$11,$0
	move	$15,$2
	sw	$15,24($30)
	lw	$15,24($30)
	bnez	$15,.L002b6a38
	nop
	lui	$15,0x1e2
	lw	$15,8000($15)
	sw	$15,-7464($28)
	lui	$15,0x1e2
	addiu	$15,$15,8004
	lw	$15,0($15)
	sw	$15,-7460($28)
	sw	$0,28($30)
.L002b6aa0:
	lw	$2,28($30)
	move	$29,$30
	ld	$30,32($29)
	ld	$31,40($29)
	jr	$31
	addiu	$29,$29,48
	.end func_002b691c
	.size func_002b691c, 412
	.size _Z16u_call4_002b691cjjjj, 412
