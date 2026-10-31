# This layout row covers two functions: a tail-call stub (j 0x305df0) and newlib's snprintf at 0x2fee08.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002fedf0,"ax",@progbits
	.align 2
	.globl func_002fedf0
	.type func_002fedf0, @function
	.ent func_002fedf0
func_002fedf0:
	addiu	$29,$29,-16
	sd	$31,0($29)
	ld	$31,0($29)
	j	0x305df0
	addiu	$29,$29,16
	nop
	lui	$14,0x7fff
	addiu	$29,$29,-160
	move	$13,$5
	sd	$31,96($29)
	move	$12,$4
	sd	$7,120($29)
	ori	$14,$14,0xffff
	sd	$8,128($29)
	li	$15,520
	sd	$9,136($29)
	move	$5,$6
	sh	$15,12($29)
	sd	$10,144($29)
	addiu	$6,$29,120
	sd	$11,152($29)
	move	$4,$29
	sw	$13,16($29)
	sw	$14,20($29)
	sw	$12,84($29)
	sw	$13,0($29)
	jal	0x2ffd00
	sw	$14,8($29)
	lw	$15,0($29)
	ld	$31,96($29)
	sb	$0,0($15)
	jr	$31
	addiu	$29,$29,160
	nop
	.end func_002fedf0
	.size func_002fedf0, 136
