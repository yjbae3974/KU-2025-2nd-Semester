## State of a system
- particles, bodies specified by certain properties/conditions
- complete description without contradiction
- properties/conditions could be imposed by `suitable preparation`
- cannot be perceived directly, only be deduced from experimental observations.


## Mathmetical Formulation
- In application of a theory
  - given certain physical information(특정 물리량 정보로 받음)
  - express by equations between math quantities
  - deduce new equations with help of axioms(공리) and rules of manipulation
    - Axioms: postulates, assumptions, laws of nature
  - Interpreting these new equations as physical conclusions
  - `Can we find causality in the equations?`
    - No, we cannot find causality in the equations.
  - `When does a math theory becoms 'valid'?`
    - self consistent(모순이 없는)
    - ability to predict experimental results

## Requirements for our scheme
- math relations between states of a system at some instance of time.
- relations comes from math formulation based on principle of superposition.(중첩원리)
  - some kind of additive process
- states connected with math quantities of a kind which can be added together to give quantities of the same kind.
- a math quantity that can hold a lot of information with regard to the state.
- vectors dimension can be infinite.

## Ket Vector
- 양자역학에서 시스템을 나타내는 벡터.
- vectors connected to states of a system
- ket vectors or simply ket
- symbol: $| \psi \rangle$
- specify by label `A`, we write $| A \rangle$
- kets can be multiplied by complex numbers and added together to give another ket vector.
<div align="center">

$C_1 | A \rangle + C_2 | B \rangle = | R \rangle$

</div>

- A ket vector expressible `linearly` in terms of certain other ket vectors is said to be dependent on them(recall linear algebra)

- A set of ket vectors are independent if no one of them is expressible linearly in terms of the others.
  - 어떤 ket vector를 다른 ket vector의 선형 조합으로 표현할 수 없을 때 이를 linearly independent라고 한다.

## Assumptions
- Each state of a system at a particular time corresponds to the ket vector.
- If a state results from the superposition of other status, its corresponding ket vector is `dependent` on corresponding ket vectors of other states.

## In general
- A state is `dependent` on any set of states if
  - corresponding ket vector is dependent on the corresponding ket vectors of the set of states.
- A set of states is indenpendent if no one is dependent on others.

## More assumptions
- Superposing a state with itself will `not` form a new state. but the original state over and over again.
  - which is different from classical mechanics.

- original state corresponds to $| A \rangle$ 
- superposed state corresponds to $|C_1 A \rangle + |C_2 A \rangle = (C_1 + C_2) | A \rangle$
- since $(C_1 + C_2)|A\rangle$ must correspond to the same state, $C_1 + C_2$ is an arbitary number.
  - ket vector multiplied by a non-zero number results in ket vector that corresponds to same state.
  - state is specified by the ket vector `direction`
  - Any `length` assigned to the ket vector is irrelevant to the state.
- All states of system are in one-to-one correspondence with all possible direction of ket vectors.
- No distinction made between directions of $|A\rangle$ and $-|A\rangle$
- Zero ket vector corresponds to no state at all.
