target datalayout = "e-m:e-p:32:32-i64:64-n32-S128"
target triple = "riscv32"

@in = dso_local global [60 x i32] zeroinitializer, align 4
@wgt = dso_local global [20 x i32] zeroinitializer, align 4
@out = dso_local global [200 x i32] zeroinitializer, align 4

define void @conv(i32 %bias) {
entry:
  ; Load in[0]
  %0 = load i32, i32* getelementptr inbounds ([60 x i32], [60 x i32]* @in, i32 0, i32 0), align 4
  ; Load wgt[0]
  %1 = load i32, i32* getelementptr inbounds ([20 x i32], [20 x i32]* @wgt, i32 0, i32 0), align 4
  ; Load out[0]
  %2 = load i32, i32* getelementptr inbounds ([200 x i32], [200 x i32]* @out, i32 0, i32 0), align 4
  
  ; Calculate: in[0] * wgt[0]
  %mul = mul i32 %0, %1
  
  ; Calculate: (in[0] * wgt[0]) + out[0]
  %add = add i32 %mul, %2
  
  ; Store result back to out[0]
  store i32 %add, i32* getelementptr inbounds ([200 x i32], [200 x i32]* @out, i32 0, i32 0), align 4
  
  ret void
}
