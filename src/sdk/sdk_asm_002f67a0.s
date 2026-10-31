# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f67a0,"ax",@progbits
	.align 2
	.globl func_002f67a0
	.type func_002f67a0, @function
	.ent func_002f67a0
func_002f67a0:
	addiu	$29,$29,-160
	sd	$30,128($29)
	sd	$23,112($29)
	lui	$30,0x1e3
	sd	$22,96($29)
	lui	$23,0x36
	sd	$21,80($29)
	lui	$22,0x37
	sd	$20,64($29)
	lui	$21,0x1e3
	sd	$19,48($29)
	lui	$20,0x36
	sd	$18,32($29)
	lui	$19,0x36
	sd	$17,16($29)
	lui	$18,0x1e3
	sd	$31,144($29)
	lui	$17,0x36
	sd	$16,0($29)
	lui	$2,0x36
.L002f67f0:
	jal	0x305660
	lw	$4,15776($2)
	lw	$3,15840($20)
	li	$2,-1
	bne	$3,$2,.L002f6824
	lw	$2,15760($23)
	sw	$0,15796($19)
	lui	$2,0x36
	sw	$0,15840($20)
	sw	$0,15764($2)
	jal	0x305460
	sw	$0,12756($30)
	lw	$2,15760($23)
.L002f6824:
	blez	$2,.L002f6838
	addiu	$4,$22,27464
	lw	$5,12736($18)
	jal	0x3080d0
	lw	$6,15844($17)
.L002f6838:
	lw	$3,12736($18)
	beqz	$3,.L002f6864
	nop
	lw	$2,15844($17)
	beqz	$2,.L002f6864
	nop
	move	$16,$28
	lw	$28,12740($21)
	jalr	$3
	lw	$4,15844($17)
	move	$28,$16
.L002f6864:
	sw	$0,15796($19)
	b	.L002f67f0
	lui	$2,0x36
	.end func_002f67a0
	.size func_002f67a0, 208
