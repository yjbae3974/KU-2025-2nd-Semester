## Context-sensitive Parser
- 파서가 이런 문법 규칙을 잡을 수 있을까?
```c
int a;
a = 1;

int a;
b = 1; // 오류

int a;
a = 1.0; // 오류
```
- 이런 문법 규칙은, context-free grammar로는 표현할 수 없다.

## 왜 Context-sensitive analysis는 어려운가?
- Answer은 syntax가 아닌, value에 의존한다.
- 가까이 있지 않은, 먼 정보가 필요할 수 있다.
- 단순한 문법 처리가 아닌, 추가적인 계산이 필요할 수 있다.
  - 예를 들면, `int arr[10]`은, `10개 원소를 가진 정수 배열` 이라는 의미를 계산해야 한다.

## Type system
- Textual representation of types.
- boolean, integer, char등..
### Purpose
- runtime safety
- improving expressiveness
- generating better codes
- Type checking

## Symbol table
- 변수의 이름과 타입을 저장하는 테이블
- 식별자의 이름, kind, type, other..등을 저장.
- scope 내에서 생성.
- 만약 특정 scope에서 사용된 변수가 symbol table에 없다면, 상위 스코프에서 검색한다.

## Symbol Table의 구현 방법
- Array implementation
  - 고정된 테이블 크기
  - 사전에 entry 개수 정해야됨.
- List implementation
  - 동적 테이블 크기
  - 필요할 때마다 entry 추가
  - large symbol table에 부적합
- Hash table implementation
  - good hash function -> even distribution

## Syntax directed translation
- 컴파일러에서 프로그램의 구문 구조를 기반으로 번역 수행.
- Parser에 의해 생성된 구문 트리를 기반으로 번역 수행.
- context-free grammar의 production에 action(semantic rules) 추가.

### 이점
- Clean Formalism
- Automatic generation of an evaluator
- High-level specification

### 단점
- Handling nonlocal information
- Evaluation strategy determines efficiency
- Increased space requirements
- Parse tree evaluators need a dependency graph
- Results are distributed over the tree
- Circularity testing