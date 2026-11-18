# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
# libkernl (Sony PS2 Runtime Library 3.0.0), 0x311740-0x311aa0: hand-written exception handlers (assembly in the
# original). 0x311740 and 0x311980 are installed by libkernl_00310fe0.c through the syscall stubs 0x3052d0 and
# 0x3052e0; each saves every GPR, hi/lo/sa to the save area at 0x1e3c540, sets EPC to its own continuation (0x311840,
# 0x311a7c) and erets into it, which calls a C handler from a table at 0x367470; 0x311880 restores the saved state
# and erets.
# Never written before.
	.set noreorder
	.set noat
	.set nomacro

	.section .text.func_00311740,"ax",@progbits
	.align 2
	.globl func_00311740
	.type func_00311740, @function
	.ent func_00311740
func_00311740:
	lui	$26,0x1e4
	addiu	$26,$26,-15040
	sq	$1,16($26)
	sq	$2,32($26)
	sq	$3,48($26)
	sq	$4,64($26)
	sq	$5,80($26)
	sq	$6,96($26)
	sq	$7,112($26)
	sq	$8,128($26)
	sq	$9,144($26)
	sq	$10,160($26)
	sq	$11,176($26)
	sq	$12,192($26)
	sq	$13,208($26)
	sq	$14,224($26)
	sq	$15,240($26)
	sq	$16,256($26)
	sq	$17,272($26)
	sq	$18,288($26)
	sq	$19,304($26)
	sq	$20,320($26)
	sq	$21,336($26)
	sq	$22,352($26)
	sq	$23,368($26)
	sq	$24,384($26)
	sq	$25,400($26)
	sq	$28,448($26)
	sq	$29,464($26)
	sq	$30,480($26)
	sq	$31,496($26)
	mfhi	$2
	lui	$1,0x1e4
	sd	$2,-14528($1)
	mfhi1	$2
	lui	$1,0x1e4
	sd	$2,-14520($1)
	mflo	$2
	lui	$1,0x1e4
	sd	$2,-14512($1)
	mflo1	$2
	lui	$1,0x1e4
	sd	$2,-14504($1)
	mfsa	$2
	lui	$1,0x1e4
	sd	$2,-14496($1)
	mfc0	$4,$12
	mfc0	$5,$13
	mfc0	$6,$14
	mfc0	$7,$8
	lui	$8,0x1e4
	addiu	$8,$8,-15040
	lui	$1,0x1e4
	sw	$6,-14488($1)
	lui	$1,0x31
	addiu	$1,$1,6208
	mtc0	$1,$14
	sync.p
	mfc0	$1,$12
	li	$2,-2
	and	$1,$1,$2
	mtc0	$1,$12
	sync.p
	eret
	lui	$1,0x36
	lw	$1,29808($1)
	lui	$29,0x1e4
	jalr	$1
	addiu	$29,$29,-15040
	li	$3,-84
	syscall
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	.end func_00311740
	.size func_00311740, 320

	.section .text.func_00311880,"ax",@progbits
	.align 2
	.globl func_00311880
	.type func_00311880, @function
	.ent func_00311880
func_00311880:
	mfc0	$1,$12
	li	$26,-28
	and	$1,$1,$26
	mtc0	$1,$12
	sync.p
	lui	$2,0x1e4
	lw	$2,-14488($2)
	mtc0	$2,$14
	sync.p
	lui	$2,0x1e4
	ld	$2,-14528($2)
	mthi	$2
	lui	$2,0x1e4
	ld	$2,-14520($2)
	mthi1	$2
	lui	$2,0x1e4
	ld	$2,-14512($2)
	mtlo	$2
	lui	$2,0x1e4
	ld	$2,-14504($2)
	mtlo1	$2
	lui	$2,0x1e4
	ld	$2,-14496($2)
	mtsa	$2
	sync.p
	lui	$26,0x1e4
	addiu	$26,$26,-15040
	lq	$1,16($26)
	lq	$2,32($26)
	lq	$3,48($26)
	lq	$4,64($26)
	lq	$5,80($26)
	lq	$6,96($26)
	lq	$7,112($26)
	lq	$8,128($26)
	lq	$9,144($26)
	lq	$10,160($26)
	lq	$11,176($26)
	lq	$12,192($26)
	lq	$13,208($26)
	lq	$14,224($26)
	lq	$15,240($26)
	lq	$16,256($26)
	lq	$17,272($26)
	lq	$18,288($26)
	lq	$19,304($26)
	lq	$20,320($26)
	lq	$21,336($26)
	lq	$22,352($26)
	lq	$23,368($26)
	lq	$24,384($26)
	lq	$25,400($26)
	lq	$28,448($26)
	lq	$29,464($26)
	lq	$30,480($26)
	lq	$31,496($26)
	mfc0	$26,$12
	ori	$26,$26,0x13
	mtc0	$26,$12
	sync.p
	eret
	nop
	nop
	nop
	.end func_00311880
	.size func_00311880, 256

	.section .text.func_00311980,"ax",@progbits
	.align 2
	.globl func_00311980
	.type func_00311980, @function
	.ent func_00311980
func_00311980:
	lui	$26,0x1e4
	addiu	$26,$26,-15040
	sq	$1,16($26)
	sq	$2,32($26)
	sq	$3,48($26)
	sq	$4,64($26)
	sq	$5,80($26)
	sq	$6,96($26)
	sq	$7,112($26)
	sq	$8,128($26)
	sq	$9,144($26)
	sq	$10,160($26)
	sq	$11,176($26)
	sq	$12,192($26)
	sq	$13,208($26)
	sq	$14,224($26)
	sq	$15,240($26)
	sq	$16,256($26)
	sq	$17,272($26)
	sq	$18,288($26)
	sq	$19,304($26)
	sq	$20,320($26)
	sq	$21,336($26)
	sq	$22,352($26)
	sq	$23,368($26)
	sq	$24,384($26)
	sq	$25,400($26)
	sq	$28,448($26)
	sq	$29,464($26)
	sq	$30,480($26)
	sq	$31,496($26)
	mfhi	$2
	lui	$1,0x1e4
	sd	$2,-14528($1)
	mfhi1	$2
	lui	$1,0x1e4
	sd	$2,-14520($1)
	mflo	$2
	lui	$1,0x1e4
	sd	$2,-14512($1)
	mflo1	$2
	lui	$1,0x1e4
	sd	$2,-14504($1)
	mfsa	$2
	lui	$1,0x1e4
	sd	$2,-14496($1)
	mfc0	$4,$12
	mfc0	$5,$13
	mfc0	$6,$14
	mfc0	$7,$8
	mfc0	$8,$23
	lui	$9,0x1e4
	addiu	$9,$9,-15040
	lui	$1,0x31
	addiu	$1,$1,6780
	mtc0	$1,$14
	sync.p
	mfc0	$1,$12
	li	$2,-2
	and	$1,$1,$2
	mtc0	$1,$12
	sync.p
	eret
	andi	$2,$5,0x7c
	lui	$1,0x36
	addu	$1,$1,$2
	lw	$1,29816($1)
	lui	$29,0x1e4
	jalr	$1
	addiu	$29,$29,-15040
	break	0xfffff
	nop
	.end func_00311980
	.size func_00311980, 288
