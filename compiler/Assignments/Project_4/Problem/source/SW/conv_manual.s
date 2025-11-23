	.text
	.attribute	4, 16
	.attribute	5, "rv32i2p0_m2p0"
	.file	"conv_manual.ll"
	.globl	conv                            # -- Begin function conv
	.p2align	2
	.type	conv,@function
conv:                                   # @conv
	.cfi_startproc
# %bb.0:                                # %entry
	lui	a0, %hi(in)
	lw	a0, %lo(in)(a0)
	lui	a1, %hi(wgt)
	lw	a1, %lo(wgt)(a1)
	lui	a2, %hi(out)
	lw	a3, %lo(out)(a2)
	imad	a0, a0, a1, a3
	sw	a0, %lo(out)(a2)
	ret
.Lfunc_end0:
	.size	conv, .Lfunc_end0-conv
	.cfi_endproc
                                        # -- End function
	.type	in,@object                      # @in
	.bss
	.globl	in
	.p2align	2
in:
	.zero	240
	.size	in, 240

	.type	wgt,@object                     # @wgt
	.globl	wgt
	.p2align	2
wgt:
	.zero	80
	.size	wgt, 80

	.type	out,@object                     # @out
	.globl	out
	.p2align	2
out:
	.zero	800
	.size	out, 800

	.section	".note.GNU-stack","",@progbits
