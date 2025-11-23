; ModuleID = 'conv.c'
source_filename = "conv.c"
target datalayout = "e-m:e-p:32:32-i64:64-n32-S128"
target triple = "riscv32-unknown-unknown"

@in = dso_local global [60 x i32] zeroinitializer, align 4
@wgt = dso_local global [20 x i32] zeroinitializer, align 4
@out = dso_local global [200 x i32] zeroinitializer, align 4

; Function Attrs: noinline nounwind optnone
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 2, i32* %2, align 4
  store i32 0, i32* %3, align 4
  store i32 0, i32* %3, align 4
  br label %4

4:                                                ; preds = %10, %0
  %5 = load i32, i32* %3, align 4
  %6 = icmp slt i32 %5, 60
  br i1 %6, label %7, label %13

7:                                                ; preds = %4
  %8 = load i32, i32* %3, align 4
  %9 = getelementptr inbounds [60 x i32], [60 x i32]* @in, i32 0, i32 %8
  store i32 3, i32* %9, align 4
  br label %10

10:                                               ; preds = %7
  %11 = load i32, i32* %3, align 4
  %12 = add nsw i32 %11, 1
  store i32 %12, i32* %3, align 4
  br label %4, !llvm.loop !5

13:                                               ; preds = %4
  store i32 0, i32* %3, align 4
  br label %14

14:                                               ; preds = %20, %13
  %15 = load i32, i32* %3, align 4
  %16 = icmp slt i32 %15, 20
  br i1 %16, label %17, label %23

17:                                               ; preds = %14
  %18 = load i32, i32* %3, align 4
  %19 = getelementptr inbounds [20 x i32], [20 x i32]* @wgt, i32 0, i32 %18
  store i32 2, i32* %19, align 4
  br label %20

20:                                               ; preds = %17
  %21 = load i32, i32* %3, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, i32* %3, align 4
  br label %14, !llvm.loop !7

23:                                               ; preds = %14
  store i32 0, i32* %3, align 4
  br label %24

24:                                               ; preds = %30, %23
  %25 = load i32, i32* %3, align 4
  %26 = icmp slt i32 %25, 200
  br i1 %26, label %27, label %33

27:                                               ; preds = %24
  %28 = load i32, i32* %3, align 4
  %29 = getelementptr inbounds [200 x i32], [200 x i32]* @out, i32 0, i32 %28
  store i32 0, i32* %29, align 4
  br label %30

30:                                               ; preds = %27
  %31 = load i32, i32* %3, align 4
  %32 = add nsw i32 %31, 1
  store i32 %32, i32* %3, align 4
  br label %24, !llvm.loop !8

33:                                               ; preds = %24
  %34 = load i32, i32* %2, align 4
  call void @conv(i32 noundef %34) #1
  ret i32 0
}

; Function Attrs: noinline nounwind optnone
define dso_local void @conv(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  store i32 0, i32* %3, align 4
  store i32 0, i32* %4, align 4
  store i32 0, i32* %3, align 4
  br label %5

5:                                                ; preds = %37, %1
  %6 = load i32, i32* %3, align 4
  %7 = icmp slt i32 %6, 30
  br i1 %7, label %8, label %40

8:                                                ; preds = %5
  store i32 0, i32* %4, align 4
  br label %9

9:                                                ; preds = %28, %8
  %10 = load i32, i32* %4, align 4
  %11 = icmp slt i32 %10, 20
  br i1 %11, label %12, label %31

12:                                               ; preds = %9
  %13 = load i32, i32* %3, align 4
  %14 = load i32, i32* %4, align 4
  %15 = add nsw i32 %13, %14
  %16 = getelementptr inbounds [60 x i32], [60 x i32]* @in, i32 0, i32 %15
  %17 = load i32, i32* %16, align 4
  %18 = load i32, i32* %4, align 4
  %19 = getelementptr inbounds [20 x i32], [20 x i32]* @wgt, i32 0, i32 %18
  %20 = load i32, i32* %19, align 4
  %21 = mul nsw i32 %17, %20
  %22 = load i32, i32* %3, align 4
  %23 = getelementptr inbounds [200 x i32], [200 x i32]* @out, i32 0, i32 %22
  %24 = load i32, i32* %23, align 4
  %25 = add nsw i32 %21, %24
  %26 = load i32, i32* %3, align 4
  %27 = getelementptr inbounds [200 x i32], [200 x i32]* @out, i32 0, i32 %26
  store i32 %25, i32* %27, align 4
  br label %28

28:                                               ; preds = %12
  %29 = load i32, i32* %4, align 4
  %30 = add nsw i32 %29, 1
  store i32 %30, i32* %4, align 4
  br label %9, !llvm.loop !9

31:                                               ; preds = %9
  %32 = load i32, i32* %2, align 4
  %33 = load i32, i32* %3, align 4
  %34 = getelementptr inbounds [200 x i32], [200 x i32]* @out, i32 0, i32 %33
  %35 = load i32, i32* %34, align 4
  %36 = add nsw i32 %35, %32
  store i32 %36, i32* %34, align 4
  br label %37

37:                                               ; preds = %31
  %38 = load i32, i32* %3, align 4
  %39 = add nsw i32 %38, 1
  store i32 %39, i32* %3, align 4
  br label %5, !llvm.loop !10

40:                                               ; preds = %5
  ret void
}

; Function Attrs: noinline nounwind optnone
define dso_local i32 @loop_test(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca [128 x i32], align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  store i32 1, i32* %3, align 4
  store i32 0, i32* %5, align 4
  br label %7

7:                                                ; preds = %13, %1
  %8 = load i32, i32* %5, align 4
  %9 = icmp slt i32 %8, 128
  br i1 %9, label %10, label %16

10:                                               ; preds = %7
  %11 = load i32, i32* %5, align 4
  %12 = getelementptr inbounds [128 x i32], [128 x i32]* %4, i32 0, i32 %11
  store i32 10, i32* %12, align 4
  br label %13

13:                                               ; preds = %10
  %14 = load i32, i32* %5, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, i32* %5, align 4
  br label %7, !llvm.loop !11

16:                                               ; preds = %7
  store i32 0, i32* %6, align 4
  br label %17

17:                                               ; preds = %28, %16
  %18 = load i32, i32* %6, align 4
  %19 = icmp slt i32 %18, 128
  br i1 %19, label %20, label %31

20:                                               ; preds = %17
  %21 = load i32, i32* %3, align 4
  %22 = load i32, i32* %6, align 4
  %23 = getelementptr inbounds [128 x i32], [128 x i32]* %4, i32 0, i32 %22
  %24 = load i32, i32* %23, align 4
  %25 = mul nsw i32 %21, %24
  %26 = load i32, i32* %2, align 4
  %27 = add nsw i32 %25, %26
  store i32 %27, i32* %3, align 4
  br label %28

28:                                               ; preds = %20
  %29 = load i32, i32* %6, align 4
  %30 = add nsw i32 %29, 1
  store i32 %30, i32* %6, align 4
  br label %17, !llvm.loop !12

31:                                               ; preds = %17
  %32 = load i32, i32* %3, align 4
  ret i32 %32
}

attributes #0 = { noinline nounwind optnone "frame-pointer"="all" "min-legal-vector-width"="0" "no-builtins" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+m" }
attributes #1 = { nobuiltin "no-builtins" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 1, !"target-abi", !"ilp32"}
!2 = !{i32 7, !"frame-pointer", i32 2}
!3 = !{i32 1, !"SmallDataLimit", i32 8}
!4 = !{!"Ubuntu clang version 14.0.6"}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
!9 = distinct !{!9, !6}
!10 = distinct !{!10, !6}
!11 = distinct !{!11, !6}
!12 = distinct !{!12, !6}
