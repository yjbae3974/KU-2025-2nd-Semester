## IR이란?

-   IR은 컴파일러가 소스 코드를 목표 코드로 변환하는 과정에서 사용하는 중간 단계 표현
-   IR 단계에서 다양한 최적화 수행.
-   여러 언어에서 동일한 IR 사용 가능.

## 특징

1. Structural IR
    1. 그래프 구조
    2. AST 등
    3. 노드와 엣지로 구성.
2. Linear IR
    1. 선형적 구조
    2. 3-address code, 바이트코드
    3. 순차적인 명령어 나열
3. Hybrid IR
    1. 구조 + 선형
    2. CFG(Control Flow Graph)

## IR의 종류

### DAG(Directed Acyclic Graph)

-   AST의 일종으로, 같은 subtree는 공유.

#### 예시: `a×2+a×2×b`

**AST (Abstract Syntax Tree):**

```
        +
       / \
      ×   ×
     /|   |\
    a 2   × b
         /|
        a 2
```

**DAG (Directed Acyclic Graph):**

-   `a×2` 서브트리가 두 번 나타남 (중복)
-   DAG에서는 `a×2` 노드가 하나만 존재하고, 두 곳에서 공유됨
-   메모리 효율성 향상 및 중복 제거
-   오늘날 대부분의 컴파일러는 DAG를 사용.
