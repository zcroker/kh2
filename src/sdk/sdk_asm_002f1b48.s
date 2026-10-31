# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f1b48,"ax",@progbits
	.align 2
	.globl func_002f1b48
	.type func_002f1b48, @function
	.ent func_002f1b48
func_002f1b48:
	addiu	$29,$29,-64
	li	$2,1
	move	$4,$29
	sd	$16,32($29)
	sd	$17,40($29)
	sd	$18,48($29)
	sd	$31,56($29)
	sw	$2,4($29)
	jal	0x305620
	sw	$2,8($29)
	li	$3,-1
	bne	$2,$3,.L002f1ba8
	sw	$2,-7456($28)
	lui	$4,0x37
	jal	0x2fdfc8
	addiu	$4,$4,25248
.L002f1b88:
	nop
	nop
	nop
	nop
	nop
	b	.L002f1b88
	nop
	nop
.L002f1ba8:
	move	$4,$0
	jal	0x308b30
	lui	$16,0x1e3
	lui	$18,0x37
	addiu	$17,$16,-9984
	nop
.L002f1bc0:
	lui	$5,0x8000
	addiu	$4,$16,-9984
	ori	$5,$5,0x210
	jal	0x3092d8
	move	$6,$0
	bgezl	$2,.L002f1c08
	lw	$2,36($17)
	jal	0x2fdfc8
	addiu	$4,$18,25272
	nop
.L002f1be8:
	nop
	nop
	nop
	nop
	nop
	b	.L002f1be8
	nop
	nop
.L002f1c08:
	bnezl	$2,.L002f1c48
	ld	$16,32($29)
	li	$3,-1
	li	$2,0xffff
	addiu	$2,$2,-4
	nop
.L002f1c20:
	nop
	nop
	nop
	nop
	nop
	bnel	$2,$3,.L002f1c20
	addiu	$2,$2,-4
	b	.L002f1bc0
	nop
	nop
.L002f1c48:
	move	$2,$0
	ld	$17,40($29)
	ld	$18,48($29)
	ld	$31,56($29)
	jr	$31
	addiu	$29,$29,64
	.end func_002f1b48
	.size func_002f1b48, 280
