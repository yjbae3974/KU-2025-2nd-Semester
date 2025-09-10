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
