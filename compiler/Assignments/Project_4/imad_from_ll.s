	.text
	.attribute	4, 16
	.attribute	5, "rv32i2p0_m2p0"
	.file	"imad.ll"
	.globl	mul                             # -- Begin function mul
	.p2align	2
	.type	mul,@function
mul:                                    # @mul
# %bb.0:
	imad	a0, a0, a1, a1
	ret
.Lfunc_end0:
	.size	mul, .Lfunc_end0-mul
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
