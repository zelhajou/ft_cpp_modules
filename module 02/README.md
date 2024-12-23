# Module 02

C++ Module 02 is designed to introduce and deepen your understanding of some of the foundational concepts in C++ programming: ad-hoc polymorphism, operator overloading, and the Orthodox Canonical class form. This module aims to equip you with the skills necessary to write robust, maintainable, and efficient C++ code.

## Key Concepts

1. **Ad-hoc Polymorphism**:
    - Ad-hoc polymorphism, also known as function overloading or operator overloading, allows functions or operators to operate in different ways depending on the types of their arguments. This form of polymorphism enhances the flexibility and readability of your code by enabling the same function or operator to be used for different data types.

2. **Operator Overloading**:
    - Operator overloading is a specific form of ad-hoc polymorphism that allows you to define the behavior of operators such as `+`, `-`, `*`, `/`, and `<<` for user-defined types. By overloading operators, you can extend the functionality of C++'s built-in operators to work with custom data structures.

3. **Orthodox Canonical Class Form**:
    - The Orthodox Canonical Form (OCF) refers to a specific way of designing classes in C++ to ensure they manage resources correctly and behave predictably when copied. An OCF-compliant class includes four essential member functions:
        - **Default Constructor**: Initializes objects in a default state.
        - **Copy Constructor**: Initializes a new object as a copy of an existing object.
        - **Copy Assignment Operator**: Assigns the state of one object to another existing object.
        - **Destructor**: Cleans up resources when an object is destroyed.

## Understanding Fixed-Point Numbers

![fixed-point](https://github.com/user-attachments/assets/95ef4e6e-8b51-4473-a108-bc46b1ebeed8)



In this module, you will work with fixed-point numbers, A fixed-point number is a way of representing fractional numbers (numbers with decimal points) using integers. It is particularly useful in environments where floating-point arithmetic is either too slow or unavailable, such as in embedded systems, digital signal processing, and certain types of financial calculations. Fixed-point numbers are often used to represent currency values, percentages, and other quantities that require precise decimal precision.

In a fixed-point number, a certain number of bits are reserved for the fractional part of the number, while the remaining bits represent the integer part. For example, in an 8-bit fixed-point number with 4 fractional bits, the format would be as follows:

```plaintext
| Integer Part (4 bits) | Fractional Part (4 bits) |
```

The value of the fixed-point number is calculated by interpreting the integer and fractional parts as separate values and combining them. For example, the fixed-point number `5.25` in an 8-bit format with 4 fractional bits would be represented as follows:

```plaintext
| Integer Part (4 bits) | Fractional Part (4 bits) |
|-----------------------|-------------------------|
| 0101 (5)              | 0100 (0.25)             |
```

In a fixed-point representation, fractional parts are represented using binary fractions. The value `0.25` can be converted to binary by understanding the place values in binary fractions, which are 1/2, 1/4, 1/8, 1/16, etc.

Here's how you can represent `0.25` in binary:

1. Multiply the decimal value by 2:
   - `0.25 * 2 = 0.5`
2. The whole number part becomes the next binary digit:
   - `0.25 * 2 = 0.5` → `0`
3. Repeat the process with the fractional part:
   - `0.5 * 2 = 1.0`
4. The whole number part becomes the next binary digit:
   - `0.5 * 2 = 1.0` → `1`
5. Continue the process until you reach the desired precision:
   - `0.25` in binary: `0.01`

Therefore, `0.25` in binary is `0.01`. This binary value is stored in the fractional part of the fixed-point number.

Another way to convert `0.25` to binary is to convert the decimal value to a fraction and then convert the fraction to binary. Here's how you can do it:

1. Write the decimal value as a fraction:
   - `0.25 = 1/4`
2. Convert the fraction to binary:
   - `1/4 = 0.01`

Therefore, `0.25` in binary is `0.01`. In the fixed-point representation, this binary value is stored in the fractional part of the fixed-point number.

In an 8-bit fixed-point number with 4 fractional bits, `0.25` would be represented as `0.0100`. for the fractional part, where each bit represents 1/2, 1/4, 1/8, 1/16 represents. Therefore, in the 4-bit fractional part `0100`:

- The first bit (0) represents 1/2 (0.5) or 2^-1
- The second bit (1) represents 1/4 (0.25) or 2^-2
- The third bit (0) represents 1/8 (0.125) or 2^-3
- The fourth bit (0) represents 1/16 (0.0625) or 2^-4

When combined with the integer part `0101` (5), the fixed-point number `5.25` is represented as `0101.0100`.




## Exercises details

This module includes the following exercises to help you practice and apply the concepts covered:

1. **Exercise 01: Towards a more useful fixed-point number class**
   - In this exercise, you will extend the `Fixed` class from Exercise 00 to make it more functional. You will add constructors for integer and floating-point inputs, and methods to convert the fixed-point value back to these types. Additionally, you will overload the insertion (`<<`) operator to allow for easy printing of the fixed-point values.

2. **Exercise 02: Implementing a fixed-point number class with arithmetic operations**
   - In this exercise, you will implement arithmetic operations for the `Fixed` class, including addition, subtraction, multiplication, and division. You will also add comparison operators to compare fixed-point numbers and test the arithmetic operations with various inputs.

3. **Exercise 03: BSP**
   - In this exercise, you will implement Binary Space Partitioning (BSP) to create a simple 2D game engine. You will create a BSP tree to partition a 2D space and implement functions to insert and query objects in the space. This exercise will test your understanding of tree data structures and spatial partitioning algorithms.


## Resources

- [Ad-hoc Polymorphism](https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/)
- [Operator Overloading](https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/)


### Floating point

![floating-point-weird](https://github.com/user-attachments/assets/b53c506a-1551-4387-a031-e3258edc2650)
![float-gaps](https://github.com/user-attachments/assets/1151fb2f-021b-4698-b3f1-4958b2437cbe)
![science-floating-point](https://github.com/user-attachments/assets/98830177-9322-4575-8e43-96279979e017)
![floating-point-representation](https://github.com/user-attachments/assets/c44003fc-08b2-475a-8022-16165bedae0e)
![the-bits](https://github.com/user-attachments/assets/c8a59722-6055-4c43-a0c7-104d8452971e)

![nan](https://github.com/user-attachments/assets/51d29454-5681-4140-9748-b978c1eb7a5e)


![printing-floats](https://github.com/user-attachments/assets/b63443ec-7af4-4739-8d2d-70c0f85f926a)

![floating-point-math](https://github.com/user-attachments/assets/c8b54880-00b8-40b3-ac0e-1bba6f0385b6)


![fixed-point](https://github.com/user-attachments/assets/95ef4e6e-8b51-4473-a108-bc46b1ebeed8)

![floating-point-alternatives](https://github.com/user-attachments/assets/c3deafb5-b1a8-49cd-9409-51b87808878c)