# Third-party code notice: this file is a routine from Sony Computer Entertainment's PlayStation 2
# Runtime Library that the game links. It is kept as assembly; it is not covered by this project's MIT License.
	.set noreorder
	.set noat
	.set nomacro
	.section .text.func_0010001c,"ax",@progbits
	.align 2
	.globl func_0010001c
	.type func_0010001c, @function
	.ent func_0010001c
func_0010001c:
	padduw	$1,$0,$0
	padduw	$2,$0,$0
	padduw	$3,$0,$0
	padduw	$4,$0,$0
	padduw	$5,$0,$0
	padduw	$6,$0,$0
	padduw	$7,$0,$0
	padduw	$8,$0,$0
	padduw	$9,$0,$0
	padduw	$10,$0,$0
	padduw	$11,$0,$0
	padduw	$12,$0,$0
	padduw	$13,$0,$0
	padduw	$14,$0,$0
	padduw	$15,$0,$0
	padduw	$16,$0,$0
	padduw	$17,$0,$0
	padduw	$18,$0,$0
	padduw	$19,$0,$0
	padduw	$20,$0,$0
	padduw	$21,$0,$0
	padduw	$22,$0,$0
	padduw	$23,$0,$0
	padduw	$24,$0,$0
	padduw	$25,$0,$0
	padduw	$28,$0,$0
	padduw	$29,$0,$0
	padduw	$30,$0,$0
	padduw	$31,$0,$0
	mthi	$0
	mthi1	$0
	mtlo	$0
	mtlo1	$0
	mtsah	$0,0
	mtc1	$0,$f0
	mtc1	$0,$f1
	mtc1	$0,$f2
	mtc1	$0,$f3
	mtc1	$0,$f4
	mtc1	$0,$f5
	mtc1	$0,$f6
	mtc1	$0,$f7
	mtc1	$0,$f8
	mtc1	$0,$f9
	mtc1	$0,$f10
	mtc1	$0,$f11
	mtc1	$0,$f12
	mtc1	$0,$f13
	mtc1	$0,$f14
	mtc1	$0,$f15
	mtc1	$0,$f16
	mtc1	$0,$f17
	mtc1	$0,$f18
	mtc1	$0,$f19
	mtc1	$0,$f20
	mtc1	$0,$f21
	mtc1	$0,$f22
	mtc1	$0,$f23
	mtc1	$0,$f24
	mtc1	$0,$f25
	mtc1	$0,$f26
	mtc1	$0,$f27
	mtc1	$0,$f28
	mtc1	$0,$f29
	mtc1	$0,$f30
	mtc1	$0,$f31
	adda.s	$f0,$f1
	sync.p
	ctc1	$0,$31
	lui	$2,0x1fe
	lui	$3,0x200
	addiu	$2,$2,0
	addiu	$3,$3,0
	jal	0x100228
	nop
	lui	$2,0x1fc
	lui	$3,0x1fe
	addiu	$2,$2,0
	addiu	$3,$3,0
	jal	0x100228
	nop
	lui	$2,0x38
	lui	$3,0x1e5
	addiu	$2,$2,-22504
	addiu	$3,$3,-14232
	jal	0x100228
	nop
	lui	$4,0x38
	lui	$5,0x1fe
	lui	$6,0x2
	lui	$7,0x38
	lui	$8,0x10
	addiu	$4,$4,-22528
	addiu	$5,$5,0
	addiu	$6,$6,0
	addiu	$7,$7,-22400
	addiu	$8,$8,680
	move	$28,$4
	li	$3,60
	syscall
	move	$29,$2
	lui	$4,0x1fc
	lui	$5,0x2
	addiu	$4,$4,0
	addiu	$5,$5,0
	li	$3,61
	syscall
	jal	0x30f068
	nop
	jal	0x3058a0
	move	$4,$0
	lui	$16,0x32
	addiu	$16,$16,-26744
	beqz	$16,.L001001f0
	nop
	jalr	$16
	nop
.L001001f0:
	lui	$4,0x32
	addiu	$4,$4,-26708
	beqz	$4,.L00100208
	nop
	jal	0x2fd188
	nop
.L00100208:
	ei
	lui	$2,0x38
	addiu	$2,$2,-22400
	lw	$4,0($2)
	jal	0x101d68
	addiu	$5,$2,4
	j	0x2fd348
	move	$4,$2
	.end func_0010001c
	.size func_0010001c, 524
