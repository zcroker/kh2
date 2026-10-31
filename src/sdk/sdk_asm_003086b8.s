# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_003086b8,"ax",@progbits
	.align 2
	.globl func_003086b8
	.type func_003086b8, @function
	.ent func_003086b8
func_003086b8:
	move	$2,$4
	bgez	$2,.L003086fc
	move	$7,$5
	lui	$3,0x7fff
	li	$5,12
	ori	$3,$3,0xffff
	lui	$4,0x1e3
	and	$3,$2,$3
	addiu	$4,$4,22488
	mult	$3,$3,$5
	lw	$2,12($4)
	addu	$2,$3,$2
	sw	$6,4($2)
	sw	$7,0($2)
	move	$5,$28
	b	.L00308724
	lw	$2,12($4)
.L003086fc:
	li	$3,12
	lui	$4,0x1e3
	mult	$3,$2,$3
	addiu	$4,$4,22488
	lw	$2,20($4)
	addu	$2,$3,$2
	sw	$6,4($2)
	sw	$7,0($2)
	move	$5,$28
	lw	$2,20($4)
.L00308724:
	addu	$3,$3,$2
	jr	$31
	sw	$5,8($3)
	.end func_003086b8
	.size func_003086b8, 120
