## `Bra` Vector

-   In any math theory, if we have a set of vectors, we can set up a second set of vectors, which are called "dual" vectors.
-   we will do the same for `ket` vectors.
-   suppose we have a number $phi$ which is a linear $fn$ of $| A \rangle$
    -   the number $phi$ corresponds to $| A \rangle + | A' \rangle$ is the sum of the numbers corresponding to $| A \rangle$ & $| A' \rangle$
    -   $phi$ can be viewed as a **scalar product** of $| A \rangle$ with some new vector.
-   These new vectors we call them "`bra`" vectors. denoted by $\langle A |$
-   The scalar product of $\langle B |$ and $| A \rangle$ is denoted by $\langle B | A \rangle$
-   Scalar product(내적) $\langle B | A \rangle$ appears as complete `bra`c`ket` expression -> denotes a number
-   $\langle B |$ or $| A \rangle$ appears as incomplete bracket expression -> denotes a vector

---

-   Scalar product of $\langle B |$ and $| A \rangle$
    -   is a linear $fn$ of $| A \rangle$
    -   represented symbolically by $\langle B |\{| A \rangle + | A' \rangle\} = \langle B | A \rangle + \langle B | A' \rangle$ and $\langle B |\{c | A \rangle\} = c \langle B | A \rangle$
-   A `bra` vector is considered to be completely defined when its scalar product with every `ket` vector is given
-   Hence if $\langle P |$ has its scalar product with every `ket` vector vanishes, then $\langle P |$ itself must be considered vanishing(`zero vector`)
-   sum of two `bra` vectors: $\langle B | + \langle B' |$
    $\{\langle B | + \langle B' |\} | A \rangle = \langle B | A \rangle + \langle B' | A \rangle$

## Further assumptions

-   There is a one-to-one correspondence between `bras` and `kets` such that
    -   `bra` corrensponds to $| A \rangle + | A' \rangle$ is the sum of the `bras` corresponding to $| A \rangle$ & $| A' \rangle$, respectively
    -   `bra` corresponds to $c | A \rangle$ is the `bra` corresponding to $| A \rangle$ multiplied by $\bar{c}$, where $\bar{c}$ is a conjugate complex number of $c$.
    -   we shall use the same label to specify a `ket` and corresponding `bra` vector. Thus `bra` corresponds to $| A \rangle$ is denoted by $\langle A |$
    -   The relationship between a `ket` and a `bra` makes it reasonable to call them `conjugate imaginary` of the other.
    -   `bras` and `kets` are complex quantities of a special kind
        -   cannot be split up into real & imaginary parts
    -   `conjugate complex` - can be split into real and imaginary parts
    -   `conjugate imaginary` - cannot be split into real and imaginary parts
---
## Specifying the state of system
- Based on the one-to-one correspondence between `bras` and `kets`, any state of the system can be specified by a `bra` as well as a `ket`
- The theory will be symmetical in its essential between `bras` and `kets`
  
## Linear and Anti-linear
- Given any two kets $| A \rangle$ and $| B \rangle$, how can we construct a number?
  - $\phi = \langle B | A \rangle$ : depends linearly on A, anti-linear on B
  - $\phi = \langle A | B \rangle$ : depends linearly on B, anti-linear on A
    - what is the relationship between $\langle A | B \rangle$ and $\langle B | A \rangle$?
    - answer: conjugate complex
  - setting $| B \rangle = | A \rangle$
  - then $\langle A | A \rangle$ is a **real** number
  - $\langle A | A \rangle > 0$ unless $| A \rangle$ is a zero vector

## Bra and Ket vector spaces
- Any two vectors can construct a number

## Orthogonality
- A bra and ket are orthogonal if their scalar product is zero i.e. $\langle A | B \rangle = 0$
- two bras or two kets are orthogonal if the scalar product of one with the conjugate imaginary of the other is zero

### Given $| A \rangle$ and $| B \rangle$
- they are orthogonal when $\langle A | B \rangle = 0$ or $\langle B | A \rangle = 0$
- the same applies to  $\langle A |$ and $\langle B |$
- $\langle A |$ and $| A \rangle$  is in same state.
- THe length of $\langle A |$or $| A \rangle$ is defined as the square root of $\langle A | A \rangle$
- since only the direction is required to set up a corr. vector for a state, the vector itself is undetermined to the extent of an arbitary numerical factor.
- For convenience, we choose this numerical factor so that the vector length is unity -> `Normalization`

## End comments
- complete scheme of relations between states of system at a particular time.
- Relations appear in math formalism. But they imply physical conditions which lead to results expressible in ters of observations.

## Linear Operators
- Recall we considered a number which is a linear $fn$ of a ket vector
  - which will leads to the concept of bra vector
- Now we consider a ket vector which is a linear $fn$ of a bra vector(ket vector을 함수로 본다. bra vector을 Input으로 받는 함수.)
  - this will lead to the concept of linear operator
- Suppose we have ket $| F \rangle$ which is a linear $fn$ of ket $| A \rangle$
  - to each ket $| A \rangle$, there corresponds a ket $| F \rangle$
  - suppose the $fn$ is linear.
- $| F \rangle$ corresponds to $| A \rangle + | A' \rangle$ is the sum of $| F \rangle$ corresponding to $| A \rangle$ and $| F \rangle$ corresponding to $| A' \rangle$
- $| F \rangle$ corresponds to $c | A \rangle$ is the ket $| F \rangle$ corresponding to $| A \rangle$ multiplied by $c$

## Introducing Symbol for linear operator $\alpha$

- We may write $\alpha | A \rangle = | F \rangle$
  - which is the result of operator $\alpha$ operating on ket $| A \rangle$
  - written like a product of ket $| A \rangle$ and operator $\alpha$
- We make the rule that ket vector must always be on the right side of the operator.
- conditions of linearity expresses as
$\alpha \{| A \rangle + | A' \rangle\} = \alpha | A \rangle + \alpha | A' \rangle$
$\alpha \{c | A \rangle\} = c \alpha | A \rangle$
- A linear operator is considered to be completely defined when the result of its application to every ket is given.
- Two linear operators are considered equal if they produce the same result when applied to every ket.

## Sum of linear operators
- Suppose we have two linear operators $\alpha$ and $\beta$
- $\alpha + \beta$ is defined by $\{\alpha + \beta\} | A \rangle = \alpha | A \rangle + \beta | A \rangle$ for any ket $| A \rangle$

## Product of linear operators
- Suppose we have two linear operators $\alpha$ and $\beta$
- $\alpha \beta$ is defined by $\{\alpha \beta\} | A \rangle = \alpha (\beta | A \rangle)$ for any ket $| A \rangle$
- `important`: $\alpha \beta | A \rangle \neq \beta \alpha | A \rangle$ in general
  - only in special case, $\alpha \beta | A \rangle = \beta \alpha | A \rangle$

- we can build up algebra with them
  - commutative axiom of multiplication does not apply(교환법칙 성립 안함.)
  - product of two linear operators may vanish without either factor vanishing(두 연산자의 곱이 0일 수 있지만, 둘 다 0이 아닐 수 있음.)
  - A number is a special case of linear operator.(숫자는 선형 연산자의 특별한 경우.)

## Meaning of linear operations operating on bra vectors
- similiar to that for kets
- $\langle B | \alpha$
### Associative axiom of multiplication for triple product of $\langle \Beta |, \alpha, | A \rangle$
- $\{\langle B | \alpha\} | A \rangle = \langle B |\{(\alpha | A \rangle)\}$
- simply written as $\langle B | \alpha | A \rangle$
- distributive axiom of multiplication holds for
  - product of bras and linear operators
  - product of kets and linear operators
### Another kind of product $| A \rangle \langle B |$
- How do we figure out what it does?