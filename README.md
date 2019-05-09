# push_swap

## Getting started

### Compiling

```
$ make
```

### Run

```
$ ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG
```

## Rules

- This game is composed of 2 stacks named A and B
- **A** contains random numbers of either positive or negative numbers iwthout any duplicates.
- **B** is empty

### Objective

- Sort given inputs in ascending order into stack A by using only another stack B

### operations

You have following operations to sort stack

- `sa`:  swap a - swap the first 2 elements at the top of stack a
- `sb`:  swap b - swap the first 2 elements at the top of stack b
- `ss`:  `sa` and `sb` at the same time
- `pa`:  push a - take the first element at the top of b and put it at the top of a
- `pb`:  push b - take the first element at the top of a and put it at the top of b
- `ra`:  rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- `rb`:  rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr`:  `ra` and `rb` at the same time
- `rra`:  reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb`:  reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

## Example of operations
```
Initial states of A and B

2
1
3
6
8
5
- -
A B
```

```
sa       | pb pb pb  | ra rb    | rra rrb   | sa       | pa pa pa   |
         |           |          |           |          |            |
1        |           |          |           |          |  1         |
2        |           |          |           |          |  2         |    
3        |           |          |           |          |  3         |
6        |   6 3     |  5 2     |  6 3      |  5 3     |  5         |
5        |   5 2     |  8 1     |  5 2      |  6 2     |  6         |
8        |   8 1     |  6 3     |  8 1      |  8 1     |  8         |
- -          - -        - -        - -         - -        - -
A B          A B        A B        A B         A B        A B

```

## Exec

- `push_swap`
    - create a list of operations that sort stack and print on standerd output

- `checker`
    - read operations from standard input and apply to check if it correctly sorts or not.
