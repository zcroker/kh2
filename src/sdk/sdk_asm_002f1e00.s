# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_002f1e00,"ax",@progbits
	.align 2
	.globl func_002f1e00
	.type func_002f1e00, @function
	.ent func_002f1e00
func_002f1e00:
	addiu	$29,$29,-16
	lw	$4,-7456($28)
	sd	$31,0($29)
	ld	$31,0($29)
	j	0x305650
	addiu	$29,$29,16
	.end func_002f1e00
	.size func_002f1e00, 24
