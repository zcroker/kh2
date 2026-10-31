# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_00308a80,"ax",@progbits
	.align 2
	.globl func_00308a80
	.type func_00308a80, @function
	.ent func_00308a80
func_00308a80:
	lui	$25,0xffff
	ori	$25,$25,0xffc0
	blez	$5,.L00308b24
	addu	$10,$4,$5
	and	$8,$4,$25
	addiu	$10,$10,-1
	and	$9,$10,$25
	subu	$10,$9,$8
	srl	$11,$10,0x6
	addiu	$11,$11,1
	andi	$9,$11,0x7
	beqz	$9,.L00308ad0
	srl	$10,$11,0x3
.L00308ab4:
	sync
	cache	0x18,0($8)
	sync
	nop
	addiu	$9,$9,-1
	bgtz	$9,.L00308ab4
	addiu	$8,$8,64
.L00308ad0:
	beqz	$10,.L00308b24
.L00308ad4:
	addiu	$10,$10,-1
	sync
	cache	0x18,0($8)
	sync
	cache	0x18,64($8)
	sync
	cache	0x18,128($8)
	sync
	cache	0x18,192($8)
	sync
	cache	0x18,256($8)
	sync
	cache	0x18,320($8)
	sync
	cache	0x18,384($8)
	sync
	cache	0x18,448($8)
	sync
	bgtz	$10,.L00308ad4
	addiu	$8,$8,512
.L00308b24:
	jr	$31
	nop
	.end func_00308a80
	.size func_00308a80, 172
