## 디지털 시스템(논리회로)의 특성?
- 컴퓨터와 디지털 시스템의 차이: 컴퓨터는 프로그램을 실행하는 기계, 디지털 시스템은 논리회로를 사용하여 데이터를 처리하는 시스템이다.
- 디지털 시스템의 특성은, 모든 정보를 0과 1로 표현하는 것.
- 디지털 시스템: nand 게이트의 컬렉션

## 프로그램
- a sequence of instructions(code) with data
- 코드 영역은 작고, 데이터가 크면 프로그램이 커지는 것.
- 하나의 파일. `.exe`로 되어있음.

## 컴퓨터시스템의 하드웨어적 특징
- 프로세서를 가지고 있음.

### VA
- Virtual Address
- 프로그램의 주소.
- 메모리는 모두 가상이라 생각하면 됨. 컴퓨터 입장에서
- 가상메모리의 주소: program의 주소
- 물리메모리의 주소: DRAM의 주소

### Processor
- 프로세서: 프로그램을 실행하는 장치
- 프로세서는 프로그램의 주소를 해석하고, 프로그램을 실행함.
- fetch, decode, read, execute, write
- machine instruction: sequential circuit의 state를 변경하는 명령어
- IO port도 메모리 주소임.
### Micro processor
- a single chip processor

### word
- 연산의 기본 데이터 단위
- GPR, ALU data path는 word size에 dependent함.

### 32bit processer
- 32bit 프로세서: 32bit 데이터를 처리하는 프로세서
- 주소도 32bit로 표현됨.
- 전체 최대 메모리 크기: $2^{32} = 4GB$
- 32bit 프로세서는 4GB의 메모리를 사용할 수 있음.
- 단, 이는 커널과 프로그램을 모두 포함한 크기.

### 64bit processer
- 64bit 프로세서: 64bit 데이터를 처리하는 프로세서
- word: 연산의 기본 데이터 단위
- 주소도 64bit로 표현됨.
- 전체 최대 메모리 크기: $2^{64} = 16EB$


## CISC vs RISC
- CISC: Complex Instruction Set Computer (x86) - IA32, IA64. IA32 == x86. IA64 !== x86-64.
- 디코딩 복잡.
- RISC: Reduced Instruction Set Computer (ARM)
- 디코딩 간단.

## 컴퓨터에서 세대란?
- micro-architecture: 프로세서의 내부 구조
- 이 마이크로 아키텍처가 달라질 때마다 세대가 달라짐.
- ex: pipeline -> superscalar -> VLIW -> Out-of-order execution -> VLIW -> 

### cache
- sram사용.
- DRAM은 CMOS 1개로 이루어짐. 또한 leakage current가 있음.
  - 따라서 대용량에 적합하지만, 불안정함.
- SRAM은 latch 2개로 이루어짐.
  - 따라서 안정적이고 빠름.



### 인사이트
- 불가능한거를 가능하게 만드는 자신감.
- cs를 배움으로서 느는 problem solving 능력.
  - 결국 모든건 사칙연산.
  - 어려운 것도 번뜩이는 아이디어 통해 해결할 수 있다.
- 주식도 결국 이거더라.. 배우는 영역을 다른 영역에 적용.

### 좋은 책
- 거의 모든 것의 역사
- 화폐 전쟁

---

## Serial Processing

### Earliest computers
- os가 1950년도까지 없었음.
- 프로그래머는, 직접 하드웨어에 접근함.
### Problems
- Schedulng
- Setup Time
- Early computers were very expensive.


## Alan Turing, Bombe and Colossus
### Turing machine
- a new mathematical computing model
- a symbol manipulating device that can simulate the logic of any computer
  - consist of infinite tape, read/write head, and a control unit
- Theoretical background to modern computers

### Bombe
- a mechanical device that could crack the Enigma code
- consisted of a series of gears and wires
- could test all possible combinations of the Enigma machine's settings

### Turing test
- a test to determine if a machine is intelligent
- a human judge would communicate with a machine and a human
- if the judge cannot tell the difference, the machine is intelligent
- 1950년도에 제안됨.

### Colossus(1943)
- the 1st programmable digital computer with an electronic valve(vaccum tube)

### ENIAC(1946)
- used for H-bomb research
- characteristics:
  - 15000 square feet(아파트 15채 정도 크기)
  - 30tons
  - 18000 vacuum tubes
  - 140kW power
- decimal machine(숫자를 10진수로 표현)
- 5000 additions per second

### IAS(institude for advanced study) machine
- the first modern computer with stored program
- characteristics:
  - 450kg, 1700 vaccum tubes
  - binary machine(숫자를 2진수로 표현)
  - 40-bit word, 20-bit instructions

### Batch system
1. 기본 개념
순차 처리: 프로그램을 하나씩 순서대로 처리
일괄 처리: 여러 프로그램을 모아서 한 번에 처리
사용자와 분리: 사용자가 직접 컴퓨터를 조작하지 않음

2. 동작 과정
사용자 → 프로그램 작성 → 카드/테이프에 기록 → 컴퓨터에 제출 <br />
컴퓨터 → 프로그램 실행 → 결과 출력 → 다음 프로그램 실행


### Problems of batch system
- a) CPU 유휴 시간 (Processor Idle)
  - I/O 작업 중에는 CPU가 아무 일도 하지 않음
  - 예: 프린터 출력 중, 디스크 읽기 중
  - CPU 활용률이 매우 낮음
- b) 긴 응답 시간 (Long Turnaround Time)
  - 사용자가 프로그램을 제출하고 결과를 받기까지 수 시간~수일
  - 디버깅이 매우 어려움
  - 실시간 상호작용 불가능
- c) I/O 속도 문제
  - CPU: 마이크로초 단위
  - I/O: 밀리초~초 단위
  - 속도 차이가 수천~수만 배

### Multiprogramming(Multitasking)
- 여러 프로그램을 동시에 실행
- 프로그램은 메모리에 적재되어 실행됨.
- one Job이 I/O를 기다리는 동안, 다른 Job을 실행할 수 있음.

### Time-sharing system1. 
1. 핵심 변화
  - 동시성: 여러 사용자가 동시에 컴퓨터 사용
  - 상호작용: 실시간으로 사용자와 대화
공유: CPU 시간을 여러 사용자에게 나누어 할당
2. Multiprogramming vs Time Sharing
  - Multiprogramming (다중 프로그래밍)
    - 여러 프로그램을 메모리에 동시에 적재
    - I/O 대기 중인 프로그램을 다른 프로그램으로 전환
    - 목적: CPU 활용률 향상
  - Time Sharing (시분할)
    - Multiprogramming + 빠른 전환
    - 각 사용자에게 짧은 시간 슬라이스 할당
    - 목적: 사용자 응답성 향상
I/O 대기 중인 프로그램을 다른 프로그램으로 전환
목적: CPU 활용률 향상
  - Time Sharing (시분할)
    - Multiprogramming + 빠른 전환
    - 각 사용자에게 짧은 시간 슬라이스 할당
    - 목적: 사용자 응답성 향상

