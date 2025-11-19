### 컴파일러를 배운다는 것

-   컴파일러 과목은, 다양한 SW알고리즘을 이에 접목하고, 효율적인 알고리즘을 고민해보는 과정이다.
-   `Code Tuning`을 통해, `Higher performance`를 낼 수 있다.

### Large O

-   시간복잡도, 공간복잡도를 나타내는 표기법
-   `O(n³)`의 뜻은, `0< f(n) < c*n³ (n>n₀)` 인 함수 `f(n)`이 존재한다는 뜻이다. 이때 `C > 0, n₀ > 0`이며, `C`가 작을수록 하드웨어 성능이 좋다고 할 수 있다.
-   예시
    -   `O(1)`: 상수시간
    -   `O(log n)`: 이진탐색
    -   `O(n)`: 선형탐색
    -   `O(n log n)`: 병합정렬, 퀵정렬
    -   `O(n²)`: 버블정렬, 삽입정렬, 선택정렬
    -   `O(2^n)`: 피보나치 수열(재귀)
    -   `O(n!)`: 외판원 문제(Brute-force)

### data, control dependency

-   data dependency: 이전 연산의 결과가 이후 연산에 영향을 미치는 경우
-   control dependency: 이전 연산의 결과에 따라 이후 연산이 실행될지 말지가 결정되는 경우
-   예시
    -   data dependency: `a = b + c; d = a * 2;`
    -   control dependency: `if (a > b) { c = a; } else { c = b; }`
-   state diagram을 그릴 때, data dependency는 화살표로, control dependency는 점선으로 표현한다.
-   data dependency는 컴파일러가 최적화를 할 때, 고려해야 하는 요소이다. 예를 들어, `a = b + c; d = a * 2;` 에서, a를 바로 d에 넣어버리면, 코드가 더 효율적이게 된다.
-   control dependency는 컴파일러가 최적화를 할 때, 고려하지 않아도 되는 요소이다. 예를 들어, `if (a > b) { c = a; } else { c = b; }` 에서, a와 b의 값을 미리 계산해놓고, c에 넣어버리면, 코드가 더 효율적이게 된다.

### 컴파일러의 역할

-   기본적인 의미는, 한 언어를 다른 언어로 번역하는 것이다.(at compile tiem, at run time, or both)
-   그러나 통상적으로, 고수준의 언어를 저수준의 언어로 번역하는 것을 의미한다.(예: C -> Assembly)
-   또한, 대중적으로, 컴파일러는 .exe 파일을 만드는 역할을 한다고 생각한다.
    -   그러나, 그것은 compiler, assembler, linker가 함께 하는 작업이다.

### 컴파일러의 구성

-   프론트엔드<br />
    역할: 소스 코드를 언어 규칙에 맞게 해석해 `중간 표현`(IR)으로 변환<br />
    구성요소:
    -   `스캐너`(어휘 분석기): vocab을 찾아냄.
    -   `파서`(구문 분석기): grammar에 맞는지를 체크.
    -   의미 분석기: 타입 검사, 이름 해석, 범위/제약 확인
    -   IR 생성: AST를 타깃-독립적 IR로 변환
    -   산출물: IR, 심볼 테이블, 진단(에러/경고)
-   백엔드 <br />
    역할: IR을 특정 하드웨어용 효율적인 기계어/어셈블리로 변환<br />
    구성요소:

    -   최적화: 상수 접기, 데드 코드 제거, 인라이닝, 루프 최적화 등
    -   명령 선택: IR → 타깃 ISA 명령으로 매핑
    -   레지스터 할당: 가상 레지스터 → 물리 레지스터 배치
    -   명령 스케줄링: 파이프라인/의존성 고려한 순서 조정
    -   코드 생성: 목적 코드/어셈블리 출력
    -   산출물: 목적 파일(.o/.obj) 또는 어셈블리, 메타데이터

-   토큰: 더 이상 쪼갤 수 없는 언어의 최소 단위
-   프론트 통과: 컴파일러가 지원하는 소스코드의 스펙에 맞다는 의미.

### Scanner

-   어휘 분석기
-   역할: 소스코드를 읽어 토큰으로 분해
-   white space, 주석 제거

### Parser

-   Recognizes context-free syntax & report errors
-   IR 생성
-   context-free vs context-sensitive
    -   context-free: 문법적으로 올바른지 검사
        -   괄호가 올바르게 닫혔는가?
        -   키워드가 올바르게 사용되었는가?
    -   context-sensitive: 의미적으로 올바른지 검사
        -   변수가 선언되었는가?
        -   자료형이 일치하는가?

### Intermediate Representation (IR)

-   data structure that is used by a compiler
-   트리로 표현

### Backend

-   역할: IR을 타깃 머신 코드로 변환
-   choose instructions

### Instruction Selection?

-   IR의 연산(add, mul, load, store 등)을 대상 CPU의 실제 기계 명령어로 변환
-   RISC를 사용하는 이유:
    -   단순한 명령어 집합
    -   고정된 명령어 길이
    -   빠른 명령어 실행
-   Optimization
    -   dynamic programming
        -   matrix multiplication
        -   matrix가 여러개 있다면, 이를 나눠서 해결.
        -   특정 범위까지의 값을 구하기 위해서 그것과 다른 범위까지의 값을 이용하여 효율적으로 값을 구하는 방법
    -   greedy algorithm
        -   큰 문제를 작은 문제로 나누어 해결

### Register Allocation

-   역할: 가상 레지스터를 물리 레지스터에 매핑(레지스터 개수는 한정)
-   Optimal allocation == NP-Complete(최적해를 구하는 것이 매우 어려움)
-   ISA에 보이는 레지스터(아키텍처 레지스터)는 보통 물리적 레지스터보다 “적다.”
    → 예: ISA는 16개 정의, 실제 CPU는 내부적으로 100개 이상 물리 레지스터를 둠.

### Instruction Scheduling

-   역할: 명령어 실행 순서 재배열
-   목표: 파이프라인 활용 극대화, 데이터 의존성 최소화
    -   Hardware Stalls, interlocks를 피함.
-   방법: 리스트 스케줄링, 소프트웨어 파이프라이닝 등

### 그래프 알고리즘: BFS, DFS.

-   BFS: 너비 우선 탐색
    -   큐 자료구조 사용
    -   최단 경로 탐색에 유리
-   DFS: 깊이 우선 탐색
    -   스택 자료구조 사용(재귀적 구현 가능)
    -   경로 존재 여부 탐색에 유리
    -   DFS -> DAG -> Topological Sort

### Code Optimizer

```C
int sumcalc(int a, int b, int N){
  int i;
  int x;

  x=0;
  y=0;
  for(i=0; i<N; i++){
    x += x + (4*a/b)*i + (i + 1)*(i + 1);
    x = x + b * y
  }
}

```

constant propagation -> Algebraic simplification -> dead code elimination

```C
int sumcalc(int a, int b, int N){
  int i;
  int x;

  x=0;
  for(i=0; i<N; i++){
    x += (4*a/b)*i + (i + 1)*(i + 1); // dead code elimination
  }
}
```
common subexpression elimination -> Loop Invariant Code Motion -> strength Reduction  

```C
int sumcalc(int a, int b, int N){
  int i;
  int x;
  int c = 4*a/b; // common subexpression elimination
  int u, v;
  u = ( a << 2 / b); // strength Reduction
  v = 0;

  x=0;
  for(i=0; i<N; i++){
    t = i + 1; // Loop Invariant Code Motion
    x = x + v + t * t;
    v = v + u; // strength Reduction
  }
}
```