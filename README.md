# Arbitrary Precision Calculator (APC)

A C-based **Arbitrary Precision Calculator (APC)** that performs arithmetic operations on integers of **unlimited length** using a **Doubly Linked List**. Unlike built-in C integer types (`int`, `long`, `long long`), this project can process numbers containing hundreds or even thousands of digits.

## Features

- ✅ Addition
- ✅ Subtraction
- ✅ Multiplication (Schoolbook Algorithm)
- ✅ Division (Long Division Algorithm)
- ✅ Supports positive and negative integers
- ✅ Handles arbitrarily large integers
- ✅ Removes leading zeros automatically
- ✅ Command-line based execution
- ✅ Modular implementation using multiple source files

---

## Project Structure

```
APC/
│── main.c
│── apc.c
│── apc.h
│── add.c
│── sub.c
│── mul.c
│── div.c
│── Makefile
```

---

## Data Structure

Each digit of the number is stored in a **Doubly Linked List**.

Example:

```
Number : 123456

Head
 ↓
1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ⇄ 6
                     ↑
                   Tail
```

This representation enables efficient carry propagation, borrow handling, and reverse traversal during arithmetic operations.

---

## Algorithms Implemented

### Addition
- Traverses both operands from the least significant digit.
- Handles carry propagation.
- Inserts the result at the beginning of the result list.

### Subtraction
- Compares operands before subtraction.
- Performs borrow handling.
- Removes leading zeros from the final result.

### Multiplication
- Implements the traditional **Schoolbook Multiplication Algorithm**.
- Generates partial products for each digit.
- Applies positional shifting.
- Adds partial products using the APC addition routine.

### Division
- Implements the **Long Division Algorithm**.
- Builds the dividend digit by digit.
- Uses repeated subtraction to determine each quotient digit.
- Stores the quotient as a linked list.

---

## Build

Using GCC

```bash
gcc *.c -o apc
```

Or using the Makefile

```bash
make
```

---

## Usage

Addition

```bash
./apc 123456789 + 987654321
```

Subtraction

```bash
./apc 987654321 - 123456789
```

Multiplication

```bash
./apc 12345 x 6789
```

Division

```bash
./apc 1000 / 25
```

---

## Sample Output

### Addition

```text
$ ./apc 999999999999999999 + 1

999999999999999999 + 1 = 1000000000000000000
```

### Subtraction

```text
$ ./apc 1000000000000000000 - 999999999999999999

1000000000000000000 - 999999999999999999 = 1
```

### Multiplication

```text
$ ./apc 12345 x 6789

12345 x 6789 = 83810205
```

### Division

```text
$ ./apc 123456 / 123

123456 / 123 = 1003
```

---

## Concepts Used

- C Programming
- Doubly Linked Lists
- Dynamic Memory Allocation
- Modular Programming
- Command-Line Argument Processing
- Arbitrary Precision Arithmetic
- Schoolbook Multiplication
- Long Division Algorithm
- Carry & Borrow Propagation

---

## Learning Outcomes

Through this project, I gained practical experience in:

- Designing arbitrary precision arithmetic algorithms
- Implementing mathematical operations using linked lists
- Dynamic memory management in C
- Modular software development
- Efficient handling of very large integers
- Algorithm design and optimization

---

## Future Enhancements

- Modulus (`%`) operation
- Exponentiation
- Decimal (floating-point) support
- Expression evaluation
- Performance optimization for multiplication (Karatsuba)
- Unit testing

---
