# L,R Values and Move Semantics

## General Points for L and R values

Let's satart by some definition (or some properties) about L and R values

1.<u> L values </u>:
  - 1.1  something that has addresses <-> memory location 
  - 1.2 we can store in it
  - 1.3 we can use the `&` operator, since it has an addresse

2.<u> R values </u>:
  - 2.1 some temporary value, that won't exist beyond a scope
  - 2.2 doesn't have a memory addresse
  - 2.3 we can't store in it

### <u> Examples </u>

`int a = 2;`
`int b = 1;`
`int c = a+b;`

- `a`,`b` and `c` are indeed L values since we can store in them
  - they have some memory addresse, and their location are in the stack
- whereas `2`,`1` are R values
  - after `int b = 1;`, `2` and `1` won't exist anymore in our code
- Now as for `a+b`: it is an R value, even if it is composed from variables
  - because we can see `a+b` as `(a+b)`: it is only an ***expression*** that will do the sum, 
    and  sotre it in `c`
- `int array[100];`
  - `array` is an L value, since it has location in memory and we can store in it
  - `aray[10+c]`: `10+c` is an R value


## L and R values cases in function call

- For this type of function prorotype `int double_data(int input)`, we can pass
  - `double_data(a)` or `double_data(5)`, where `a` is a variable (L value), and `5` is some constant (an R value)

- L value reference <-> `int double_data(int& input)`:
  - only using variable as `double_data(a)`
  - `double_data(5)` is not allowed

- Special case: L value reference can be used with R value if we add `const` <->
  `int double_data(const int& input)`
  - `double_data(5)` is allowed using this type of function signature

- If we want to create a function that accepts only R value, we use `&&` <->
  `int double_data(int&& input)`
  - `double_data(5)` is the only form allowed using double references

### Rules

1. Normal L values `int` can be used with L values or R values
2. L values references  `int&`: only using L value
3. Const L values references `const int&`: L and R values
4. Double reference R values `int&&`: only R values