## Recall
- bra vectors
- ket vectors
- linear operators
- are they commutative? does the commutative axiom of multiplication holds? -> no

## Physical significance of scheme
- we already assumed directions of bras and kets correspond to state of a system at a particular time
- Now we further assume that the linear operators corespond to dynamical variables at that time.

## conjugate Relations
- consider the ket which is the conjugate imaginary of $\langle P | \alpha$
- Depends antilinearly on $\langle P |$
- Depends linearly on $| P \rangle$
- can be considered as the result of the same operator operating on $| P \rangle$
- this operator is called the adjoint(conjugate transpose of $alpha$) of $\alpha$ and denoted by $\overline{\alpha}$
- the conjugate of $\langle P | \alpha$ is $\overline{\alpha} | P \rangle$

## Recall
- $\langle B | A \rangle = \overline{\langle A | B \rangle}$
- replace $\langle A |$ with $\langle P | \alpha$
- replace $| A \rangle$ with $\overline{\alpha}| P \rangle$
- then we habe the general formula $\langle B | \overline{\alpha} | P \rangle = \overline{\langle P | \alpha | B \rangle}$

## Replacing $\alpha$ with $\overline{\alpha}$
- We have $\langle B | \overline{\overline{\alpha}} | P \rangle = \overline{\langle P | \overline{\alpha} | B \rangle} = \langle P | \alpha | B \rangle$
- then, $\overline{\overline{\alpha}} = \alpha$
- A linear operator may equal to its adjoint -> self-adjoint
- A linear operator may not equal to its adjoint -> non-self-adjoint
  - corresponds too a real dynamical variable
  - alternatively called real linear operator
  - It can be split into real & imaginary parts hence we use `'conjugate complex'`
- The conjugate complex of the sum of two linear operators is the sum of their conjugates
- we will use this to get the conjugate complex of the product of two linear operators $\alpha$ and $\beta$

## Recall $\langle B | A \rangle = \overline{\langle A | B \rangle}$

- Let $\langle A | = \langle P | \alpha$ and $\langle B | = \langle Q | \overline{\beta} | A \rangle = \overline{\alpha} | P \rangle$ and $| B \rangle = \beta | Q \rangle$
- we have $\langle Q | \overline{\beta}\overline{\alpha} | P \rangle = \overline{\langle P | \alpha \beta | Q \rangle} = \langle P | \overline{\alpha\beta} | B \rangle$
- => $\overline{\alpha\beta} = \overline{\beta}\overline{\alpha}$

## Conjugate complex of the product of three linear operators
- $\overline{\alpha\beta\gamma} = \overline{\alpha(\beta\gamma)} = \overline{\beta\gamma}\overline{\alpha} =\overline{\gamma}\overline{\beta}\overline{\alpha}$
- can it be extended to any number of operators?

## Recall
- $| A \rangle \langle B |$ is a linear operator, we may get its conjugate complex by referring directly to the definition of the adjoint 
- multiply $| A \rangle \langle B |$ into general bra $\langle P |$ and we get $\langle P | A \rangle \langle B |$
- Its conjugate imaginary ket is $\overline{\langle P | A \rangle} | B \rangle = \langle A | P \rangle | B \rangle= | B \rangle \langle A | P \rangle$
- Hence $\overline{| A \rangle \langle B |} = | B \rangle \langle A |$

## General Rule
- conjugate complex or imaginary of any product of bras, kets and linear operators is obtained by taking conjugate complex or imaginary of each factor and reversing the order of all the factors