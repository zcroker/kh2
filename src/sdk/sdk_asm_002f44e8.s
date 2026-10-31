# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f44e8,"ax",@progbits
	.align 2
	.globl func_002f44e8
	.type func_002f44e8, @function
	.ent func_002f44e8
func_002f44e8:
	addiu	$29,$29,-160
	neg.s	$f0,$f17
	swc1	$f20,96($29)
	neg.s	$f20,$f18
	lwc1	$f1,160($29)
	swc1	$f21,104($29)
	add.s	$f0,$f0,$f18
	mul.s	$f21,$f1,$f19
	sd	$16,64($29)
	mul.s	$f20,$f20,$f19
	move	$16,$4
	mul.s	$f17,$f17,$f1
	swc1	$f26,144($29)
	neg.s	$f19,$f19
	swc1	$f25,136($29)
	mul.s	$f21,$f21,$f0
	swc1	$f24,128($29)
	add.s	$f20,$f20,$f17
	swc1	$f23,120($29)
	add.s	$f19,$f19,$f1
	swc1	$f22,112($29)
	mov.s	$f22,$f12
	mov.s	$f24,$f13
	mov.s	$f23,$f14
	mov.s	$f26,$f15
	nop
	nop
	div.s	$f21,$f21,$f19
	nop
	nop
	div.s	$f20,$f20,$f19
	sd	$31,80($29)
	jal	0x2f4000
	mov.s	$f25,$f16
	lui	$1,0x3f80
	mtc1	$1,$f0
	move	$4,$29
	swc1	$f22,20($16)
	swc1	$f22,0($16)
	sw	$0,40($16)
	sw	$0,60($16)
	swc1	$f0,44($16)
	jal	0x2f4000
	swc1	$f0,56($16)
	move	$4,$16
	swc1	$f24,0($29)
	swc1	$f23,20($29)
	move	$5,$29
	swc1	$f21,40($29)
	move	$6,$4
	swc1	$f26,48($29)
	swc1	$f25,52($29)
	jal	0x2f3d08
	swc1	$f20,56($29)
	ld	$31,80($29)
	ld	$16,64($29)
	lwc1	$f26,144($29)
	lwc1	$f25,136($29)
	lwc1	$f24,128($29)
	lwc1	$f23,120($29)
	lwc1	$f22,112($29)
	lwc1	$f21,104($29)
	lwc1	$f20,96($29)
	jr	$31
	addiu	$29,$29,160
	.end func_002f44e8
	.size func_002f44e8, 260
