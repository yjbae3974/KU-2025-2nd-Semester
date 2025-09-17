## Parser

### 파서의 역할

-   파서는 컴파일러의 프론트엔드에서 스캐너가 생성한 토큰을 구문 트리로 변환하는 역할을 한다.

### 파서의 주요 기능

1. **context-free analysis**

    - 문법 규칙에 따라 토큰 스트림을 분석
    - 구문 구조를 파악하여 구문 트리 생성

2. **guide context-sensitive analysis**

    - 변수 선언, 타입 체크 등 문맥에 의존적인 분석을 위한 기반 제공
    - 의미 분석기로 전달할 정보 준비

3. **construct IR**

    - 구문 트리를 중간 표현으로 변환
    - 후속 컴파일 단계를 위한 표준화된 형태 제공

4. **produce meaningful error messages**

    - 구문 오류 발생 시 정확한 위치와 원인 파악
    - 개발자가 이해하기 쉬운 오류 메시지 제공

5. **Attempt error correction**
    - 구문 오류를 자동으로 수정하거나 수정 제안
    - 컴파일 과정의 연속성 유지

## ex: parsing x + 2 \* y

`<goal>`: 시작 기호 - 파싱의 목표
`<expr>`: 표현식
`<op>`: 연산자
`<id>`: 식별자
`<num>`: 숫자

```
<goal> => <expr>
<expr> => <expr><op><expr>
<expr><op><expr> => <id,x><op><expr>
<id,x><op><expr> => <id,x>+<expr>
<id,x>+<expr> => <id,x>+<expr><op><expr>
<id,x>+<expr><op><expr> → <id,x>+<num,2><op><expr>
<id,x>+<num,2><op><expr> → <id,x>+<num,2>*<expr>
<id,x>+<num,2>*<expr> → <id,x>+<num,2>*<id,y>
<goal> ⇒ <id,x>+<num,2>*<id,y>
```

## Derivation

-   각 스텝마다, 대체할 non-terminal을 선택하는 과정
-   Leftmost derivation: 가장 왼쪽의 non-terminal을 대체
-   Rightmost derivation: 가장 오른쪽의 non-terminal을 대체

-   그러나, rightmost로 `x + 2 * y`를 하면, `(x + 2) * y`가 된다.

## 파싱 방법론

### Top-down Parsing (상향식 파싱)

#### 개념

-   **시작 기호에서 시작**하여 **입력 문자열을 생성**하는 방식
-   **예측적(Predictive)**: 어떤 규칙을 적용할지 미리 예측
-   **좌측 파생(Leftmost Derivation)** 사용

#### 동작 과정

```
<goal> → <expr> → <expr><op><expr> → <id,x><op><expr> → ...
```

-   시작 기호에서 시작
-   각 단계에서 어떤 규칙을 적용할지 결정
-   입력을 읽어가며 예측이 맞는지 확인

#### 장점

-   **직관적**: 문법 규칙을 그대로 따라감
-   **구현 간단**: 재귀 하강 파서로 쉽게 구현
-   **오류 처리**: 어느 지점에서 오류가 발생했는지 명확

#### 단점

-   **좌재귀 문제**: `A → Aα` 형태의 문법에서 무한 루프
-   **백트래킹**: 잘못된 예측 시 되돌아가야 함
-   **성능**: 예측 실패 시 비효율적

#### 예시

```javascript
// 재귀 하강 파서 (Recursive Descent Parser)
function parseExpr() {
    if (lookahead === "id" || lookahead === "num") {
        return parseTerminal();
    } else if (lookahead === "(") {
        return parseParenExpr();
    } else {
        throw new Error("Unexpected token");
    }
}
```

### Bottom-up Parsing (하향식 파싱)

#### 개념

-   **입력 문자열에서 시작**하여 **시작 기호로 축약**하는 방식
-   **감소적(Reductive)**: 토큰들을 점진적으로 문법 규칙으로 축약
-   **우측 파생(Rightmost Derivation)** 사용

#### 동작 과정

```
<id,x>+<num,2>*<id,y> → <id,x>+<num,2>*<expr> → <id,x>+<expr> → <expr> → <goal>
```

-   입력 토큰에서 시작
-   문법 규칙의 우측을 좌측으로 축약 (Reduce)
-   필요시 토큰을 스택에 저장 (Shift)

#### 장점

-   **좌재귀 처리**: 좌재귀 문법도 문제없이 처리
-   **효율성**: LR 파서는 O(n) 시간에 파싱
-   **강력함**: 대부분의 문맥 자유 문법 처리 가능

#### 단점

-   **복잡한 구현**: LR 파서 테이블 생성이 복잡
-   **디버깅 어려움**: 축약 과정이 직관적이지 않음
-   **오류 처리**: 오류 발생 지점 파악이 어려움

#### 예시

```javascript
// LR 파서의 Shift-Reduce 과정
// 입력: x + 2 * y
// 스택: [] → [x] → [expr] → [expr, +] → [expr, +, 2] → [expr, +, expr] → [expr] → [goal]

function shiftReduceParse(tokens) {
    const stack = [];
    let i = 0;

    while (i < tokens.length || stack.length > 1) {
        if (canReduce(stack)) {
            reduce(stack); // 축약
        } else {
            stack.push(tokens[i++]); // 이동
        }
    }

    return stack[0]; // 최종 결과
}
```

### Top-down vs Bottom-up 비교

| 특징          | Top-down    | Bottom-up   |
| ------------- | ----------- | ----------- |
| **시작점**    | 시작 기호   | 입력 토큰   |
| **방향**      | 상향 (생성) | 하향 (축약) |
| **파생**      | 좌측 파생   | 우측 파생   |
| **구현**      | 재귀 하강   | LR/SLR 파서 |
| **좌재귀**    | 문제 있음   | 문제 없음   |
| **성능**      | O(n)        | O(n)        |
| **오류 처리** | 쉬움        | 어려움      |
| **직관성**    | 높음        | 낮음        |

### 실제 사용 사례

#### Top-down 파싱

-   **LL 파서**: 간단한 문법에 적합
-   **재귀 하강**: 수동으로 파서 작성 시
-   **ANTLR**: 파서 생성기

#### Bottom-up 파싱

-   **LR 파서**: 대부분의 프로그래밍 언어
-   **Yacc/Bison**: 파서 생성기
-   **컴파일러**: C, Java, C++ 등

### 결론

-   **Top-down**: 직관적이고 구현하기 쉬우나 제한적
-   **Bottom-up**: 강력하고 효율적이나 복잡함
-   **선택 기준**: 문법의 복잡성과 구현 요구사항에 따라 결정

---

## terminal vs non-terminal

-   terminal: 더 이상 쪼갤 수 없는 기호
-   non-terminal: 더 이상 쪼갤 수 없는 기호

### 예시

-   terminal: `x`, `+`, `2`, `y`
-   non-terminal: `<expr>`, `<op>`, `<id>`, `<num>`

## predictive parsing

-   First(A)의 정의: 문법 기호의 문자열. terminal과 non-terminal의 조합으로 이루어진다.

### Left Factoring

**문제**: 같은 시작 기호를 가진 여러 규칙이 있을 때 파싱이 어려움

```
A → αβ | αγ
```

**해결**: 공통 부분을 분리

```
A → αA'
A' → β | γ
```

**예시**:

```
E → E + T | E - T | T
↓
E → T E'
E' → + T E' | - T E' | ε
```

## Recursive vs Non-recursive

### Recursive (재귀적)

-   **정의**: Non-terminal이 자기 자신을 참조
-   **예시**: `E → E + T | T`
-   **문제**: 무한 루프 위험, 스택 오버플로우
-   **해결**: 우재귀로 변환

### Non-recursive (비재귀적)

-   **정의**: 재귀 참조가 없는 문법
-   **예시**: `E → T E'`, `E' → + T E' | ε`
-   **장점**: 안전하고 예측 가능
-   **사용**: 실제 파서 구현에서 선호

**핵심**: 실제 구현에서는 재귀를 피하고 반복문 사용!

## Bottom-up Parsing 상세

### 목표

-   입력 문자열 `w`와 문법 `G`가 주어졌을 때, **leaves(단말 기호)에서 시작하여 root(시작 기호)로 올라가면서** 구문 트리를 구성합니다.

### 핵심 개념: Reduction (환원)

-   **정의**: 프로덕션 규칙의 **오른쪽 부분과 일치하는 부분 문자열을 왼쪽의 Non-terminal 기호로 대체**하는 연산.
-   즉, 입력 문자열을 시작 기호로 줄여나가는 과정.

### 예시 문법

산술 표현식을 위한 문법 규칙:

1. `Expr → Expr + Term`
2. `Expr → Expr - Term`
3. `Expr → Term`
4. `Term → Term × Factor`
5. `Term → Term ÷ Factor`
6. `Term → Factor`
7. `Factor → ( Expr )`
8. `Factor → num`
9. `Factor → ident`

### 파싱 예시: `x - 2 * y`

입력 문자열 `x - 2 * y`를 위 문법을 사용하여 Bottom-up 방식으로 파싱하는 과정은 다음과 같습니다. 각 단계는 입력 문자열의 일부를 문법 규칙에 따라 더 높은 수준의 Non-terminal로 **환원(Reduction)**하는 것을 보여줍니다.

1. **초기 상태**: `ident - num * ident` (여기서 `x`는 `ident`, `2`는 `num`, `y`는 `ident`로 토큰화되었다고 가정)

2. **`ident` 환원**: 첫 번째 `ident` (`x`)를 `Factor`로 환원 (규칙 9: `Factor → ident`)

    - 상태: `Factor - num * ident`

3. **`Factor` 환원**: `Factor`를 `Term`으로 환원 (규칙 6: `Term → Factor`)

    - 상태: `Term - num * ident`

4. **`Term` 환원**: `Term`을 `Expr`로 환원 (규칙 3: `Expr → Term`)

    - 상태: `Expr - num * ident`

5. **`num` 환원**: `num` (`2`)을 `Factor`로 환원 (규칙 8: `Factor → num`)

    - 상태: `Expr - Factor * ident`

6. **`Factor` 환원**: `Factor`를 `Term`으로 환원 (규칙 6: `Term → Factor`)

    - 상태: `Expr - Term * ident`

7. **`ident` 환원**: 두 번째 `ident` (`y`)를 `Factor`로 환원 (규칙 9: `Factor → ident`)

    - 상태: `Expr - Term * Factor`

8. **`Term * Factor` 환원**: `Term * Factor`를 `Term`으로 환원 (규칙 4: `Term → Term × Factor`)

    - 상태: `Expr - Term`

9. **`Expr - Term` 환원**: `Expr - Term`을 `Expr`로 환원 (규칙 2: `Expr → Expr - Term`)

    - 상태: `Expr`

10. **최종 목표**: `Expr`이 시작 기호이므로 파싱 성공.

### Bottom-up 파싱의 특징

#### 장점

-   **좌재귀 처리**: 좌재귀 문법도 문제없이 처리
-   **효율성**: LR 파서는 O(n) 시간에 파싱
-   **강력함**: 대부분의 문맥 자유 문법 처리 가능
-   **연산자 우선순위**: 자동으로 올바른 우선순위 적용

#### 단점

-   **복잡한 구현**: LR 파서 테이블 생성이 복잡
-   **디버깅 어려움**: 축약 과정이 직관적이지 않음
-   **오류 처리**: 오류 발생 지점 파악이 어려움

### 핵심 원리

이 과정은 입력 문자열의 가장 기본적인 구성 요소(leaves)에서 시작하여 점차적으로 더 큰 문법 구조(branches)를 형성하고, 최종적으로 전체 문장을 나타내는 시작 기호(root)에 도달하는 것을 보여줍니다.

**Bottom-up 파싱의 핵심**: "작은 단위부터 시작해서 점점 큰 단위로 합쳐나가는 방식"
