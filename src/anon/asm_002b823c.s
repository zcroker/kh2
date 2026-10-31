# Kept as assembly: -O0 code with gp-relative addresses, which the -G0 build cannot emit from C.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002b823c,"ax",@progbits
	.align 2
	.globl func_002b823c
	.type func_002b823c, @function
	.ent func_002b823c
func_002b823c:
	addiu	$29,$29,-16
	sd	$30,0($29)
	sd	$31,8($29)
	move	$30,$29
	li	$4,1
	jal	0x2b6708
	li	$5,33
	lw	$15,-7460($28)
	move	$2,$15
	move	$29,$30
	ld	$30,0($29)
	ld	$31,8($29)
	jr	$31
	addiu	$29,$29,16
	.end func_002b823c
	.size func_002b823c, 56
