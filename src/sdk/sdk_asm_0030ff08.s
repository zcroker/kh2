# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0030ff08,"ax",@progbits
	.align 2
	.globl func_0030ff08
	.type func_0030ff08, @function
	.ent func_0030ff08
func_0030ff08:
	lui	$3,0x1000
	lui	$4,0x36
	ori	$3,$3,0x1000
	lwu	$2,0($3)
	lw	$8,16($3)
	ld	$10,28952($4)
	andi	$9,$8,0x800
	beqz	$9,.L0030ff34
	li	$9,2
	lwu	$2,0($3)
	daddiu	$10,$10,1
.L0030ff34:
	andi	$8,$8,0x3
	dsll	$10,$10,0x10
	movz	$9,$0,$8
	or	$2,$2,$10
	dsllv	$9,$9,$8
	dsllv	$2,$2,$9
	jr	$31
	nop
	.end func_0030ff08
	.size func_0030ff08, 76
