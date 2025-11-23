	.text
	.attribute	4, 16
	.attribute	5, "rv32i2p0_m2p0"
	.file	"conv.c"
	.globl	main
	.p2align	2
	.type	main,@function
main:
	addi	sp, sp, -32
	sw	ra, 28(sp)
	sw	s0, 24(sp)
	addi	s0, sp, 32
	li	a0, 0
	sw	a0, -12(s0)
	li	a1, 2
	sw	a1, -16(s0)
	sw	a0, -20(s0)
	sw	a0, -20(s0)
	j	.LBB0_1
.LBB0_1:
	lw	a1, -20(s0)
	li	a0, 59
	blt	a0, a1, .LBB0_4
	j	.LBB0_2
.LBB0_2:
	lw	a0, -20(s0)
	lui	a1, %hi(in)
	addi	a1, a1, %lo(in)
	slli	a0, a0, 2
	add	a1, a0, a1
	li	a0, 3
	sw	a0, 0(a1)
	j	.LBB0_3
.LBB0_3:
	lw	a0, -20(s0)
	addi	a0, a0, 1
	sw	a0, -20(s0)
	j	.LBB0_1
.LBB0_4:
	li	a0, 0
	sw	a0, -20(s0)
	j	.LBB0_5
.LBB0_5:
	lw	a1, -20(s0)
	li	a0, 19
	blt	a0, a1, .LBB0_8
	j	.LBB0_6
.LBB0_6:
	lw	a0, -20(s0)
	lui	a1, %hi(wgt)
	addi	a1, a1, %lo(wgt)
	slli	a0, a0, 2
	add	a1, a0, a1
	li	a0, 2
	sw	a0, 0(a1)
	j	.LBB0_7
.LBB0_7:
	lw	a0, -20(s0)
	addi	a0, a0, 1
	sw	a0, -20(s0)
	j	.LBB0_5
.LBB0_8:
	li	a0, 0
	sw	a0, -20(s0)
	j	.LBB0_9
.LBB0_9:
	lw	a1, -20(s0)
	li	a0, 199
	blt	a0, a1, .LBB0_12
	j	.LBB0_10
.LBB0_10:
	lw	a0, -20(s0)
	lui	a1, %hi(out)
	addi	a1, a1, %lo(out)
	slli	a0, a0, 2
	add	a1, a0, a1
	li	a0, 0
	sw	a0, 0(a1)
	j	.LBB0_11
.LBB0_11:
	lw	a0, -20(s0)
	addi	a0, a0, 1
	sw	a0, -20(s0)
	j	.LBB0_9
.LBB0_12:
	lw	a0, -16(s0)
	call	conv
	li	a0, 0
	lw	ra, 28(sp)
	lw	s0, 24(sp)
	addi	sp, sp, 32
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main

	.globl	conv
	.p2align	2
	.type	conv,@function
conv:
	addi	sp, sp, -32
	sw	ra, 28(sp)
	sw	s0, 24(sp)
	addi	s0, sp, 32
	sw	a0, -12(s0)
	li	a0, 0
	sw	a0, -16(s0)
	sw	a0, -20(s0)
	sw	a0, -16(s0)
	j	.LBB1_1
.LBB1_1:
	lw	a1, -16(s0)
	li	a0, 29
	blt	a0, a1, .LBB1_8
	j	.LBB1_2
.LBB1_2:
	li	a0, 0
	sw	a0, -20(s0)
	j	.LBB1_3
.LBB1_3:
	lw	a1, -20(s0)
	li	a0, 19
	blt	a0, a1, .LBB1_6
	j	.LBB1_4
.LBB1_4:
	lw	a1, -16(s0)
	lw	a2, -20(s0)
	add	a0, a1, a2
	slli	a0, a0, 2
	lui	a3, %hi(in)
	addi	a3, a3, %lo(in)
	add	a0, a0, a3
	lw	a0, 0(a0)
	lui	a3, %hi(wgt)
	addi	a3, a3, %lo(wgt)
	slli	a2, a2, 2
	add	a2, a2, a3
	lw	a2, 0(a2)
	mul	a0, a0, a2
	lui	a2, %hi(out)
	addi	a2, a2, %lo(out)
	slli	a1, a1, 2
	add	a1, a1, a2
	lw	a2, 0(a1)
	add	a0, a0, a2
	sw	a0, 0(a1)
	j	.LBB1_5
.LBB1_5:
	lw	a0, -20(s0)
	addi	a0, a0, 1
	sw	a0, -20(s0)
	j	.LBB1_3
.LBB1_6:
	lw	a2, -12(s0)
	lw	a0, -16(s0)
	lui	a1, %hi(out)
	addi	a1, a1, %lo(out)
	slli	a0, a0, 2
	add	a1, a0, a1
	lw	a0, 0(a1)
	add	a0, a0, a2
	sw	a0, 0(a1)
	j	.LBB1_7
.LBB1_7:
	lw	a0, -16(s0)
	addi	a0, a0, 1
	sw	a0, -16(s0)
	j	.LBB1_1
.LBB1_8:
	lw	ra, 28(sp)
	lw	s0, 24(sp)
	addi	sp, sp, 32
	ret
.Lfunc_end1:
	.size	conv, .Lfunc_end1-conv

	.globl	loop_test
	.p2align	2
	.type	loop_test,@function
loop_test:
	addi	sp, sp, -544
	sw	ra, 540(sp)
	sw	s0, 536(sp)
	addi	s0, sp, 544
	sw	a0, -12(s0)
	li	a0, 1
	sw	a0, -16(s0)
	li	a0, 0
	sw	a0, -532(s0)
	j	.LBB2_1
.LBB2_1:
	lw	a1, -532(s0)
	li	a0, 127
	blt	a0, a1, .LBB2_4
	j	.LBB2_2
.LBB2_2:
	lw	a0, -532(s0)
	slli	a1, a0, 2
	addi	a0, s0, -528
	add	a1, a0, a1
	li	a0, 10
	sw	a0, 0(a1)
	j	.LBB2_3
.LBB2_3:
	lw	a0, -532(s0)
	addi	a0, a0, 1
	sw	a0, -532(s0)
	j	.LBB2_1
.LBB2_4:
	li	a0, 0
	sw	a0, -536(s0)
	j	.LBB2_5
.LBB2_5:
	lw	a1, -536(s0)
	li	a0, 127
	blt	a0, a1, .LBB2_8
	j	.LBB2_6
.LBB2_6:
	lw	a0, -16(s0)
	lw	a1, -536(s0)
	slli	a2, a1, 2
	addi	a1, s0, -528
	add	a1, a1, a2
	lw	a1, 0(a1)
	mul	a0, a0, a1
	lw	a1, -12(s0)
	add	a0, a0, a1
	sw	a0, -16(s0)
	j	.LBB2_7
.LBB2_7:
	lw	a0, -536(s0)
	addi	a0, a0, 1
	sw	a0, -536(s0)
	j	.LBB2_5
.LBB2_8:
	lw	a0, -16(s0)
	lw	ra, 540(sp)
	lw	s0, 536(sp)
	addi	sp, sp, 544
	ret
.Lfunc_end2:
	.size	loop_test, .Lfunc_end2-loop_test

	.type	in,@object
	.bss
	.globl	in
	.p2align	2
in:
	.zero	240
	.size	in, 240

	.type	wgt,@object
	.globl	wgt
	.p2align	2
wgt:
	.zero	80
	.size	wgt, 80

	.type	out,@object
	.globl	out
	.p2align	2
out:
	.zero	800
	.size	out, 800

	.ident	"Ubuntu clang version 14.0.6"
	.section	".note.GNU-stack","",@progbits
