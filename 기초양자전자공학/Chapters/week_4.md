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