# C++ Programming Language

C++ is a powerful and versatile programming language that is used to develop a wide range of software applications, from system software and device drivers to high-performance games and interactive websites. It combines the features of both procedural and object-oriented programming paradigms, making it a popular choice for software development.


## Table of Contents

- [Introduction](#introduction)
  - [Key Features of C++](#key-features-of-c)
  - [C++ vs. C](#c-vs-c)
- [Table of Contents](#table-of-contents)
- [Installation and Setup](#installation-and-setup)
- [Hello World Program](#hello-world-program)
  - [Header Files and Preprocessor Directives](#header-files-and-preprocessor-directives)
  - [Comments](#comments)
  - [Main Function](#main-function)
  - [Output Statement](#output-statement)
  - [Return Statement](#return-statement)
- [Keywords](#keywords)
- [Command Line Arguments](#command-line-arguments)
- [Data Types](#data-types)
  - [Static and Dynamic Data Types](#static-and-dynamic-data-types)
  - [Type Casting](#type-casting)
- [Operators](#operators)
- [Control Structures](#control-structures)
  - [Conditional Statements](#conditional-statements)
  - [Loops](#loops)
  - [Jump Statements](#jump-statements)
  - [Conditional Operator](#conditional-operator)
  - [Exception Handling](#exception-handling)
  - [Conditional Compilation](#conditional-compilation)
- [Functions](#functions)
- [Structures and Classes](#structures-and-classes)
  - [Structures](#structures)
  - [Classes](#classes)
- [Object-Oriented Programming](#object-oriented-programming)
  - [Basic Concepts](#basic-concepts)
  - [Classes and Objects](#classes-and-objects)
    - [Defining Classes and Objects](#defining-classes-and-objects)
    - [Access Modifiers](#access-modifiers)
    - [Member Functions](#member-functions)
    - [Constructors and Destructors](#constructors-and-destructors)
    - [Copy Constructors and Copy Assignment Operators](#copy-constructors-and-copy-assignment-operators)
  - [Rule of Zero, Three, and Five](#rule-of-zero-three-and-five)
  - [Encapsulation](#encapsulation)
    - [Access Modifiers](#access-modifiers)
    - [Getters and Setters](#getters-and-setters)
  - [Inheritance](#inheritance)
    - [Single Inheritance](#single-inheritance)
    - [Multiple Inheritance](#multiple-inheritance)
    - [Multilevel Inheritance](#multilevel-inheritance)
    - [Hierarchical Inheritance](#hierarchical-inheritance)
    - [Hybrid Inheritance](#hybrid-inheritance)
    - [Virtual Inheritance](#virtual-inheritance)
    - [Aggregation](#aggregation)
  - [Polymorphism](#polymorphism)
    - [Function Overloading](#function-overloading)
    - [Function Overriding](#function-overriding)
    - [Virtual Functions](#virtual-functions)
	- [Operator Overloading](#operator-overloading)
  - [Abstraction](#abstraction)
- [Templates](#templates)
  - [Function Templates](#function-templates)
  - [Class Templates](#class-templates)
  - [Template Specialization](#template-specialization)
  - [Template Meta-programming](#template-meta-programming)
  - [Variadic Templates](#variadic-templates)
  - [Concepts (C++20)](#concepts-c20)
- [Pointers and Reference](#pointers-and-reference)
- [Memory Model](#memory-model)
- [Memory Management](#memory-management)
  - [Stack vs. Heap](#stack-vs-heap)
  - [Static Memory Allocation](#static-memory-allocation)
  - [Dynamic Memory Allocation](#dynamic-memory-allocation)
  - [Memory Leaks](#memory-leaks)
  - [Smart Pointers](#smart-pointers)
    - [Unique Pointer](#unique-pointer)
    - [Shared Pointer](#shared-pointer)
    - [Weak Pointer](#weak-pointer)
    - [RAII (Resource Acquisition Is Initialization)](#raii-resource-acquisition-is-initialization)
- [Standard library](#standard-library)
  - [Input and Output](#input-and-output)
  - [File I/O](#file-io)
  - [Strings](#strings)
    <!-- - [String Operations](#string-operations)
    - [String Conversion](#string-conversion) -->
  - [Containers](#containers)
    - [Sequence Containers](#sequence-containers)
        - [Array](#array)
        - [Vector](#vector)
        - [Deque](#deque)
        - [List](#list)
        - [Forward List](#forward-list)
    - [Associative Containers](#associative-containers)
        - [Set](#set)
        - [Map](#map)
        - [Multiset](#multiset)
        - [Multimap](#multimap)
    - [Unordered Associative Containers](#unordered-associative-containers)
        - [Unordered Set](#unordered-set)
        - [Unordered Map](#unordered-map)
        - [Unordered Multiset](#unordered-multiset)
        - [Unordered Multimap](#unordered-multimap)
    - [Container Adapters](#container-adapters)
        - [Stack](#stack)
        - [Queue](#queue)
        - [Priority Queue](#priority-queue)
  - [Iterators](#iterators)
    - [Input Iterators](#input-iterators)
    - [Output Iterators](#output-iterators)
    - [Forward Iterators](#forward-iterators)
    - [Bidirectional Iterators](#bidirectional-iterators)
    - [Random Access Iterators](#random-access-iterators)
  - [Algorithms](#algorithms)
    - [Non-modifying Algorithms](#non-modifying-algorithms)
    - [Modifying Algorithms](#modifying-algorithms)
    - [Sorting Algorithms](#sorting-algorithms)
    - [Numeric Algorithms](#numeric-algorithms)
  - [Math](#math)
    - [Math Functions](#math-functions)
    - [Random Numbers](#random-numbers)
  - [Time and Date](#time-and-date)
  - [Error Handling](#error-handling)
    - [Exceptions](#exceptions)
  - [Utility Components](#utility-components)
    - [Pair and Tuple](#pair-and-tuple)
  <!-- - [Concurrency](#concurrency)
    - [Threads](#threads)
    - [Mutexes](#mutexes)
    - [Condition Variables](#condition-variables)
    - [Futures and Promises](#futures-and-promises)
  - [Networking](#networking)
    - [Sockets](#sockets)
    - [HTTP Requests](#http-requests)
    - [Websockets](#websockets)
  - [Filesystem](#filesystem)
    - [File Operations](#file-operations)
    - [Directory Operations](#directory-operations) -->
- [Structuring Codebase](#structuring-codebase)
  - [Header Files](#header-files)
  - [Namespaces](#namespaces)
  - [Preprocessor Directives](#preprocessor-directives)
  - [Scope](#scope)
  - [Forward Declarations](#forward-declarations)
- [Dependency Management](#dependency-management)
  - [Package Managers](#package-managers)
  - [Build Systems](#build-systems)
    - [Make](#gnu-make)
    - [CMake](#cmake)
- [Working with Libraries](#working-with-libraries)
  - [Static Libraries](#static-libraries)
  - [Dynamic Libraries](#dynamic-libraries)
  - [Linking Libraries](#linking-libraries)
  - [Using Libraries](#using-libraries)
  - [Library Directories](#library-directories)
- [Compilers](#compilers)
- [Debugging](#debugging)
- [Standard Versions](#standard-versions)
- [languge Concepts](#languge-concepts)
- [References](#references)

## Introduction

C++ is a general-purpose programming language that was developed by Bjarne Stroustrup in 1979 at Bell Labs. It is an extension of the C programming language and adds support for object-oriented programming, generic programming, and exception handling. C++ is widely used for developing system software, application software, device drivers, embedded software, and high-performance software applications.

### Key Features of C++

- **Object-Oriented Programming**: C++ supports object-oriented programming (OOP) concepts such as classes, objects, inheritance, polymorphism, and encapsulation.

- **Generic Programming**: C++ provides support for generic programming through templates, allowing you to write generic algorithms and data structures.

- **Standard Library**: C++ includes a rich standard library that provides a wide range of functions and classes for common programming tasks.

- **Performance**: C++ is known for its high performance and efficiency, making it suitable for low-level programming and performance-critical applications.

- **Portability**: C++ code can be compiled and run on a wide range of platforms, including Windows, macOS, Linux, and embedded systems.

- **Compatibility with C**: C++ is compatible with C code, allowing you to use existing C libraries and code in C++ programs.

- **Memory Management**: C++ provides manual memory management through features such as pointers, dynamic memory allocation, and deallocation.

- **Exception Handling**: C++ supports exception handling to manage runtime errors and abnormal conditions that may occur during program execution.

- **Multi-Paradigm Language**: C++ supports multiple programming paradigms, including procedural programming, object-oriented programming, and generic programming.

### C++ vs. C

C++ is an extension of the C programming language and shares many features with C. However, there are some key differences between the two languages that set them apart.

| **C++** | **C** |
| --- | --- |
| C++ is a high-level programming language that supports object-oriented programming, generic programming, and procedural programming paradigms. | C is a procedural programming language that is widely used for system programming, embedded programming, and low-level programming. |
| C++ is a superset of C, meaning that most C programs can be compiled using a C++ compiler. | C++ is a superset of C, meaning that most C programs can be compiled using a C++ compiler. |
| C++ introduces new features such as classes, objects, inheritance, polymorphism, and templates for generic programming. | C does not support object-oriented programming features such as classes, objects, and inheritance. |
| C++ provides a rich standard library that includes containers, algorithms, input/output streams, and other utilities. | C provides a standard library with basic functions for input/output, string manipulation, and memory management. |
| C++ supports exception handling to manage runtime errors and abnormal conditions that may occur during program execution. | C does not provide built-in support for exception handling, making error handling more challenging. |
| C++ is known for its high performance and efficiency, making it suitable for performance-critical applications. | C is known for its simplicity and portability, making it suitable for system programming and embedded systems. |

## Installation and Setup

Before you can start programming in C++, you need to set up your development environment. Here are the basic steps to get started:

1. **Install a C++ compiler**: You need a C++ compiler to compile and run your C++ code. Some popular C++ compilers include:
   - GCC (GNU Compiler Collection): A free and open-source compiler available on Linux, macOS, and Windows.
   - Clang: Another open-source compiler that supports C++ and is known for its fast compilation times.
   - Microsoft Visual C++: A compiler provided by Microsoft for Windows development.

2. **Choose a text editor or IDE**: You can write C++ code in any text editor, but using an Integrated Development Environment (IDE) can make your coding experience more productive. Some popular C++ IDEs include:
   - Visual Studio Code: A lightweight and versatile code editor with C++ support through extensions.
   - Visual Studio: A full-featured IDE from Microsoft that provides comprehensive C++ development tools.
   - CLion: A cross-platform C++ IDE from JetBrains that offers advanced code analysis and refactoring features.

3. **Set up a build system**: To compile and run your C++ code, you need a build system that automates the compilation process. Common build systems for C++ include:

   - Make: A build automation tool that uses Makefiles to specify build rules.
   - CMake: A cross-platform build system generator that simplifies the process of building C++ projects.
   - Visual Studio Build Tools: A set of tools provided by Microsoft for building C++ projects on Windows.

## Hello World Program

```cpp
#include <iostream> // Preprocessor directive to include the iostream header file
int main() { // Main function directive
    std::cout << "Hello, World!" << std::endl; // Output statement
    return 0; // Return statement
}
```

Save the above code in a file named `hello.cpp` and compile it using a C++ compiler. For example, if you are using GCC, you can compile the code with the following command:

```bash
g++ hello.cpp -o hello
```

This will generate an executable file named `hello`. Run the executable to see the output:

```bash
./hello
```

You should see the output `Hello, World!` printed to the console.

### Header Files and Preprocessor Directives

- **Header Files**: Header files in C++ contain declarations of functions, classes, and variables that are used in a program. They typically have a `.h` or `.hpp` extension and are included in the source code using the `#include` directive.

- **Preprocessor Directives**: Preprocessor directives in C++ are commands that are processed by the preprocessor before compilation. They start with a `#` symbol and are used to include header files, define macros, and conditionally compile code.

in the `hello world` program, the `#include <iostream>` directive includes the `iostream` header file, which provides input and output functionality in C++. The `std::cout` statement is used to print the output `Hello, World!` to the console.

### Comments

Comments in C++ are used to document code and improve its readability. They are ignored by the compiler and do not affect the program's execution.

- **Single-line comments**: Single-line comments in C++ start with `//` and continue until the end of the line. They are used to add explanatory notes or disable code temporarily.

- **Multi-line comments**: Multi-line comments in C++ start with `/*` and end with `*/`. They can span multiple lines and are used for longer comments or to comment out blocks of code.

### Main Function

- The `main()` function is the entry point of a C++ program. It is called automatically when the program is executed and is responsible for controlling the program's flow.

- The `int` before `main()` indicates that the function returns an integer value. By convention, a return value of `0` indicates successful execution, while a non-zero value indicates an error.

### Output Statement

- The `std::cout` object is used to output data to the console in C++. It is part of the `iostream` standard library and is used with the insertion operator `<<` to display text, variables, and expressions.

- The `std::endl` manipulator is used to insert a newline character and flush the output buffer. It is equivalent to `\n` but ensures that the output is displayed immediately.

### Return Statement

- The `return` statement is used to exit a function and return a value to the caller. In the `main()` function, returning `0` indicates successful program execution, while returning a non-zero value indicates an error.

## keywords

C++ has a set of reserved keywords that have special meanings and cannot be used as identifiers (such as variable names, function names, or class names). These keywords are used to define the syntax and structure of the language and should not be used for other purposes.

[Keywords in C++ | List of all keywords in C++ ( Full Explanation )](https://www.scholarhat.com/tutorial/cpp/keywords-in-cpp)

## Command Line Arguments

Command-line arguments are parameters passed to a program when it is executed from the command line. In C++, the `main()` function can accept command-line arguments as arguments.

```cpp
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}
```

the `argc` parameter is an integer that represents the number of command-line arguments passed to the program, and `argv` is an array of strings that contains the actual arguments.

```bash
./program arg1 arg2 arg3
```

```bash
Argument 0: ./program
Argument 1: arg1
Argument 2: arg2
Argument 3: arg3
```

## Data Types

Data types in C++ specify the type of data that a variable can hold. They define the size, range, and operations that can be performed on the data. C++ provides a variety of built-in data types, including primitive types, derived types, and user-defined types.

- **Primitive Data Types**: Basic data types that are directly supported by the language. They include integers, floating-point numbers, characters, and booleans.

  - **Integer Types**: `int`, `short`, `long`, `long long`, `unsigned int`, `unsigned short`, `unsigned long`, `unsigned long long`, `char`, `bool`
  - **Floating-Point Types**: `float`, `double`, `long double`
  - **Character Types**: `char`, `wchar_t`, `char16_t`, `char32_t`
  - **Boolean Type**: `bool`

- **Derived Data Types**: Data types that are derived from primitive types or other derived types. They include pointers, arrays, references, and functions.

  - **Pointers**: `int*`, `char*`, `double*`, `void*`
  - **Arrays**: `int[]`, `char[]`, `double[]`
  - **References**: `int&`, `char&`, `double&`
  - **Functions**: `int(*)(int, int)`, `void(*)(int)`

- **User-Defined Data Types**: Data types that are defined by the user using classes, structures, and enumerations.

  - **Classes**: User-defined data types that encapsulate data and functions into a single entity.
  - **Structures**: User-defined data types that group related data items together.
  - **Enumerations**: User-defined data types that define a set of named constants.

- **Standard Library Data Types**: Data types provided by the C++ standard library that offer additional functionality and features.

  - **Strings**: `std::string`, `std::wstring`, `std::u16string`, `std::u32string`
  - **Containers**: `std::vector`, `std::list`, `std::map`, `std::set`
  - **Iterators**: `std::iterator`, `std::reverse_iterator`, `std::move_iterator`
  - **Algorithms**: `std::sort`, `std::find`, `std::transform`, `std::accumulate`

- **User-Defined Literals**: Custom data types that can be defined by the user to extend the language's syntax and functionality.

- **User-Defined Literals**: `42s`, `3.14f`, `100ms`, `2h`

- **Type Modifiers**: Keywords that modify the properties of data types, such as signedness, size, and volatility.

  - **Type Modifiers**: `signed`, `unsigned`, `short`, `long`, `const`, `volatile`

- **Type Aliases**: Custom names given to existing data types to improve code readability and maintainability.

  - **Type Aliases**: `using`, `typedef`, `alias`

- **Type Inference**: Mechanism that allows the compiler to deduce the type of a variable based on its initializer.

  - **Type Inference**: `auto`, `decltype`, `std::decay`, `std::common_type`

- **Type Traits**: Template classes that provide information about the properties of data types at compile time.

  - **Type Traits**: `std::is_integral`, `std::is_floating_point`, `std::is_pointer`, `std::is_array`

### Static and Dynamic Data Types

- **Static Data Types**: Data types that are known at compile time and do not change during program execution. They are determined by the compiler based on the variable declaration.

Example:

```cpp
int x = 42; // Static data type (int)
```

- **Dynamic Data Types**: Data types that are determined at runtime and can change during program execution. They are typically used in dynamically allocated memory and polymorphic programming.

Example:

```cpp
int *ptr = new int; // Dynamic data type (int*)
```

### Type Casting

Type casting in C++ is the process of converting a variable from one data type to another. It can be done implicitly by the compiler or explicitly by the programmer using casting operators.

- **Implicit Type Casting**: Automatic conversion of data types by the compiler when compatible.

    ```cpp
    int x = 5;
    double y = x; // Implicit type casting from int to double
    ```

- **Explicit Type Casting**: Manual conversion of data types using casting operators.

    ```cpp
    double x = 3.14;
    int y = static_cast<int>(x); // Explicit type casting from double to int
    ```

- **C++ Casting Operators**: `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`.

    `satic_cast` : It is used to convert one data type to another. It is similar to the C-style cast but provides more type safety.

    ```cpp
    double x = 3.14;
    int y = static_cast<int>(x); // Convert double to int
    ```

    `dynamic_cast` : It is used for safe downcasting of pointers and references in polymorphic classes.

    ```cpp
    class Base {
    public:
        virtual void foo() {}
    };

    class Derived : public Base {};

    int main() {
        Base *base = new Derived;
        Derived *derived = dynamic_cast<Derived*>(base);
        if (derived) {
            derived->foo();
        }
        delete base;
        return 0;
    }
    ```

    `const_cast` : It is used to add or remove const or volatile qualifiers from a variable.

    ```cpp
    const int x = 42;
    int y = const_cast<int>(x); // Remove const qualifier
    ```

    `reinterpret_cast` : It is used to convert one pointer type to another pointer type or to convert a pointer to an integer type.

    ```cpp
    #include <iostream>
    int main() {
        int num = 42;
        int *num_ptr = &num;

        // Disguise the integer pointer as a char pointer
        char *char_ptr = reinterpret_cast<char *>(num_ptr);

        for (size_t i = 0; i < sizeof(int); ++i) {
            // Print the individual bytes of the integer as characters
            std::cout << "Byte " << i << ": " << char_ptr[i] << std::endl;
        }

        return 0;
    }
    ```

- **C-Style Casting**: Traditional casting method that can be used to convert between data types.

    ```cpp
    double x = 3.14;
    int y = (int)x; // C-style casting from double to int
    ```

- **Type Conversion Functions**: Functions provided by the standard library to convert between data types.

    ```cpp
    std::string str = std::to_string(42); // Convert int to string
    int num = std::stoi("42"); // Convert string to int
    ```

## Operators

Operators in C++ are symbols that perform specific operations on one or more operands. They can be classified into various categories based on their functionality and usage.

- **Arithmetic Operators**: Perform mathematical operations on numeric operands.

  - **Addition (+)**: Adds two operands.
  - **Subtraction (-)**: Subtracts the second operand from the first.
  - **Multiplication (*)**: Multiplies two operands.
  - **Division (/)**: Divides the first operand by the second.
  - **Modulus (%)**: Returns the remainder of the division.

- **Relational Operators**: Compare two operands and return a boolean value.

  - **Equal to (==)**: Checks if two operands are equal.
  - **Not equal to (!=)**: Checks if two operands are not equal.
  - **Greater than (>)**: Checks if the first operand is greater than the second.
  - **Less than (<)**: Checks if the first operand is less than the second.
  - **Greater than or equal to (>=)**: Checks if the first operand is greater than or equal to the second.
  - **Less than or equal to (<=)**: Checks if the first operand is less than or equal to the second.

- **Logical Operators**: Combine multiple conditions and return a boolean value.
  - **Logical AND (&&)**: Returns true if both operands are true.
  - **Logical OR (||)**: Returns true if at least one operand is true.
  - **Logical NOT (!)**: Returns the opposite of the operand's value.

- **Assignment Operators**: Assign a value to a variable and perform an operation on it.
  - **Assignment (=)**: Assigns the value of the right operand to the left operand.
  - **Addition assignment (+=)**: Adds the right operand to the left operand and assigns the result.
  - **Subtraction assignment (-=)**: Subtracts the right operand from the left operand and assigns the result.
  - **Multiplication assignment (*=)**: Multiplies the left operand by the right operand and assigns the result.
  - **Division assignment (/=)**: Divides the left operand by the right operand and assigns the result.
  - **Modulus assignment (%=)**: Calculates the modulus of the left operand by the right operand and assigns the result.

- **Increment and Decrement Operators**: Increase or decrease the value of a variable by one.
  - **Increment (++)**: Increases the value of the operand by one.
  - **Decrement (--)**: Decreases the value of the operand by one.

- **Bitwise Operators**: Perform bitwise operations on integer operands.
  - **Bitwise AND (&)**: Performs a bitwise AND operation.
  - **Bitwise OR (|)**: Performs a bitwise OR operation.
  - **Bitwise XOR (^)**: Performs a bitwise XOR (exclusive OR) operation.
  - **Bitwise NOT (~)**: Performs a bitwise NOT (complement) operation.
  - **Left shift (<<)**: Shifts the bits of the left operand to the left by the number of positions specified by the right operand.
  - **Right shift (>>)**: Shifts the bits of the left operand to the right by the number of positions specified by the right operand.

- **Ternary Operator**: A conditional operator that evaluates a condition and returns one of two values based on the result.
  - **Ternary Operator (condition ? value1 : value2)**: Returns value1 if the condition is true, and value2 if the condition is false.

- **Comma Operator**: Evaluates multiple expressions and returns the value of the last expression.
  - **Comma Operator (expr1, expr2, expr3, ...)**: Evaluates expr1, expr2, expr3, and so on, and returns the value of the last expression.

- **Member Access Operators**: Access members of a class or structure.
  - **Dot Operator (.)**: Accesses members of an object using the object name.
  - **Arrow Operator (->)**: Accesses members of an object using a pointer to the object.

- **Scope Resolution Operator**: Specifies the scope of a function or variable.
  - **Scope Resolution Operator (::)**: Specifies the scope of a function or variable in a namespace or class.

## Control Structures

Control structures in C++ are used to alter the flow of a program based on certain conditions or loops. They include if-else statements, switch statements, loops, and jump statements.

### Conditional Statements

Conditional statements in C++ are used to execute different blocks of code based on specified conditions. They include if statements, if-else statements, nested if statements, and switch statements.

- **if Statement**: Executes a block of code if a specified condition is true.

    ```cpp
    int x = 5;
    if (x > 0) {
        std::cout << "Positive number" << std::endl;
    }
    ```

- **if-else Statement**: Executes one block of code if a condition is true and another block if it is false.

    ```cpp
    int x = -5;
    if (x > 0) {
        std::cout << "Positive number" << std::endl;
    } else {
        std::cout << "Negative number" << std::endl;
    }
    ```

- **Nested if Statements**: Using if statements inside other if statements to create complex conditions.

    ```cpp
    int x = 5;
    if (x > 0) {
        if (x % 2 == 0) {
            std::cout << "Positive even number" << std::endl;
        } else {
            std::cout << "Positive odd number" << std::endl;
        }
    }
    ```

- **switch Statement**: Executes different code blocks based on the value of an expression.

    ```cpp
    int day = 3;
    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        default:
            std::cout << "Invalid day" << std::endl;
    }
    ```

### Loops

Loops in C++ are used to execute a block of code repeatedly based on a specified condition. They include while loops, do-while loops, for loops, and range-based for loops.

- **while Loop**: Executes a block of code as long as a specified condition is true.

    ```cpp
    int i = 0;
    while (i < 5) {
        std::cout << i << std::endl;
        i++;
    }
    ```

- **do-while Loop**: Executes a block of code at least once and then repeats it as long as a specified condition is true.

    ```cpp
    int i = 0;
    do {
        std::cout << i << std::endl;
        i++;
    } while (i < 5);
    ```

- **for Loop**: Executes a block of code a specified number of times.

    ```cpp
    for (int i = 0; i < 5; i++) {
        std::cout << i << std::endl;
    }
    ```

- **Range-based for Loop (C++11)**: Iterates over the elements of a range-based container.

    ```cpp
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (int x : vec) {
        std::cout << x << std::endl;
    }
    ```

- **Nested Loops**: Using loops inside other loops to create complex patterns or iterate over multi-dimensional arrays.

    ```cpp
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << i << "," << j << std::endl;
        }
    }
    ```

### Jump Statements

Jump statements in C++ are used to alter the flow of a program by transferring control to a different part of the program. They include break, continue, return, and goto statements.

- **break Statement**: Exits the innermost loop or switch statement.

    ```cpp
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            break;
        }
        std::cout << i << std::endl;
    }
    ```

- **continue Statement**: Skips the current iteration of a loop and continues with the next iteration.

    ```cpp
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            continue;
        }
        std::cout << i << std::endl;
    }
    ```

- **return Statement**: Exits a function and returns a value to the caller.

    ```cpp
    int add(int a, int b) {
        return a + b;
    }
    ```

- **goto Statement**: Transfers control to a labeled statement in the program. (use sparingly, can lead to spaghetti code)

    ```cpp
    goto label;
    // Code
    label:
    // Statement
    ```

### Conditional Operator

The conditional operator in C++ is a ternary operator that evaluates a condition and returns one of two values based on the result. It is a shorthand way of writing if-else statements.

- **Conditional Operator**: `condition ? value1 : value2`

    ```cpp
    int x = 5;
    std::string result = (x > 0) ? "Positive" : "Negative";
    std::cout << result << std::endl;
    ```

- **Multiple Conditional Operators**: Nesting conditional operators to handle multiple conditions.

    ```cpp
    int x = 5;
    std::string result = (x > 0) ? "Positive" : (x < 0) ? "Negative" : "Zero";
    std::cout << result << std::endl;
    ```

- **Conditional Operator vs. if-else**: Using the conditional operator for simple conditions and if-else for more complex conditions.

    ```cpp
    int x = 5;
    std::string result = (x > 0) ? "Positive" : "Non-positive";
    if (x == 0) {
        result = "Zero";
    }
    std::cout << result << std::endl;
    ```

### Exception Handling

Exception handling in C++ is a mechanism to handle runtime errors and abnormal conditions that occur during program execution. It allows you to catch and handle exceptions, preventing the program from crashing.

- **try-catch Block**: A try block is used to enclose code that may throw an exception, and a catch block is used to handle the exception.

    ```cpp
    try {
        int x = 5;
        int y = 0;
        if (y == 0) {
            throw std::runtime_error("Division by zero");
        }
        int result = x / y;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    ```

- **throw Statement**: Used to throw an exception when an error condition is encountered.

    ```cpp
    int x = 5;
    int y = 0;
    if (y == 0) {
        throw std::runtime_error("Division by zero");
    }
    int result = x / y;
    std::cout << "Result: " << result << std::endl;
    ```

- **Exception Classes**: Standard exception classes provided by the C++ standard library.
  - **std::exception**: Base class for all standard exceptions.
  - **std::runtime_error**: Exception class for runtime errors.
  - **std::logic_error**: Exception class for logical errors.
  - **std::invalid_argument**: Exception class for invalid arguments.
  - **std::out_of_range**: Exception class for out-of-range errors.

- **Custom Exceptions**: Defining custom exception classes to handle specific error conditions.

    ```cpp
    class MyException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "My custom exception";
        }
    };

    int x = 5;
    int y = 0;
    if (y == 0) {
        throw MyException();
    }
    int result = x / y;
    std::cout << "Result: " << result << std::endl;
    ```

- **Exception Specifications**: Specifying the types of exceptions that a function can throw.

    ```cpp
    void foo() throw(std::runtime_error) {
        throw std::runtime_error("Error in foo");
    }
    ```

### Conditional Compilation

Conditional compilation in C++ allows you to include or exclude code based on preprocessor directives. It is used to create different versions of a program for different platforms or configurations.

- **Conditional Compilation**: `#ifdef`, `#ifndef`, `#endif`, `#if`, `#else`, `#elif`

    ```cpp
    #define DEBUG
    #ifdef DEBUG
    std::cout << "Debug mode" << std::endl;
    #else
    std::cout << "Release mode" << std::endl;
    #endif
    ```

- **Preprocessor Directives**: Special commands that are processed by the preprocessor before compilation.

    ```cpp
    #define PI 3.14159
    #define MAX(x, y) ((x) > (y) ? (x) : (y))

    double area = PI * radius * radius;
    int max = MAX(a, b);
    ```

- **Conditional Compilation with Macros**: Using macros to define conditional compilation directives.

    ```cpp
    #define DEBUG
    #ifdef DEBUG
    std::cout << "Debug mode" << std::endl;
    #else
    std::cout << "Release mode" << std::endl;
    #endif
    ```

- **Conditional Compilation with Command-Line Arguments**: Specifying conditional compilation directives using command-line arguments.

    ```bash
    g++ -DDEBUG -o program program.cpp
    ```

- **Conditional Compilation with Macros**: Using macros to define conditional compilation directives.

    ```cpp
    #define DEBUG
    #ifdef DEBUG
    std::cout << "Debug mode" << std::endl;
    #else
    std::cout << "Release mode" << std::endl;
    #endif
    ```

## Functions

Functions in C++ are blocks of code that perform a specific task. They are used to modularize code, improve code reusability, and simplify program structure.

- **Function Declaration**: `returnType functionName(parameters);`

    ```cpp
    int add(int a, int b);
    void printMessage(std::string message);
    ```

- **Function Definition**: `returnType functionName(parameters) { body }`

    ```cpp
    int add(int a, int b) {
        return a + b;
    }
    void printMessage(std::string message) {
        std::cout << message << std::endl;
    }
    ```

- **Function Call**: `functionName(arguments);`

    ```cpp
    int sum = add(3, 5);
    printMessage("Hello, World!");
    ```

- **Function Parameters**: Input values passed to a function when it is called.

    ```cpp
    int add(int a, int b) {
        return a + b;
    }
    ```

- **Return Statement**: Value returned by a function to the caller.

    ```cpp
    int add(int a, int b) {
        return a + b;
    }
    ```

- **Function Overloading**: Defining multiple functions with the same name but different parameters.

    ```cpp
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    ```

- **Default Arguments**: Providing default values for function parameters.

    ```cpp
    void printMessage(std::string message, int count = 1) {
        for (int i = 0; i < count; i++) {
            std::cout << message << std::endl;
        }
    }
    ```

- **Function Prototypes**: Forward declaration of a function before its actual definition.

    ```cpp
    int add(int a, int b); // Function prototype
    int main() {
        int sum = add(3, 5);
        return 0;
    }
    int add(int a, int b) { // Function definition
        return a + b;
    }
    ```

- **Recursive Functions**: Functions that call themselves to solve a problem.

    ```cpp
    int factorial(int n) {
        if (n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
    ```

- **Inline Functions**: Functions that are expanded in place at the call site to improve performance.

    ```cpp
    inline int add(int a, int b) {
        return a + b;
    }
    ```

- **Lambda Functions (C++11)**: Anonymous functions that can capture variables from their enclosing scope.

    ```cpp
    auto add = [](int a, int b) { return a + b; };
    int sum = add(3, 5);
    ```

- **Function Pointers**: Pointers that store the address of a function.

    ```cpp
    int add(int a, int b) {
        return a + b;
    }
    int (*ptr)(int, int) = add;
    int sum = ptr(3, 5);
    ```

- **Function Objects**: Objects that behave like functions by overloading the function call operator.

    ```cpp
    class Add {
    public:
        int operator()(int a, int b) {
            return a + b;
        }
    };
    Add add;
    int sum = add(3, 5);
    ```

- **Variadic Functions**: Functions that accept a variable number of arguments.

    ```cpp
    void printValues(int count, ...) {
        va_list args;
        va_start(args, count);
        for (int i = 0; i < count; i++) {
            int value = va_arg(args, int);
            std::cout << value << std::endl;
        }
        va_end(args);
    }

    printValues(3, 1, 2, 3);
    ```

- **Function Templates**: Generic functions that can operate on different data types.

    ```cpp
    template <typename T>
    T add(T a, T b) {
        return a + b;
    }
    int sum = add(3, 5);
    double total = add(3.14, 2.71);
    ```

## Structures and Classes

Structures and classes are user-defined data types in C++ that allow for the grouping of variables of different data types under a single name. They make it easier to manage and organize complex data by creating objects that have particular attributes and behaviors. The main difference between a structure and a class is their default access specifier: members of a structure are public by default, while members of a class are private.

### Structures

Structures in C++ are used to group related data items of different data types under a single name. They are defined using the `struct` keyword and can contain variables, functions, and constructors. To create an object of a structure, you use the structure name followed by the object name.

- **Structure Definition**: `struct structName { members };`

    ```cpp
    struct Rectangle {
        int width;
        int height;
        int area() {
            return width * height;
        }
    };
    ```

- **Structure Declaration**: `structName objectName;`

    ```cpp
    Rectangle rect;
    rect.width = 5;
    rect.height = 3;
    int area = rect.area();
    ```

- **Structure Initialization**: Initializing structure members when creating an object.

    ```cpp
    Rectangle rect = {5, 3};
    int area = rect.area();
    ```

- **Structure Pointers**: Using pointers to access structure members.

    ```cpp
    Rectangle rect = {5, 3};
    Rectangle *ptr = &rect;
    int area = ptr->area();
    ```

### Classes

Classes in C++ are used to create user-defined data types that encapsulate data and functions into a single entity. They are defined using the `class` keyword and can contain private, protected, and public members. To create an object of a class, you use the class name followed by the object name.

- **Class Definition**: `class className { members };`

    ```cpp
    class student {
    public:
        std::string name;
        int age;
        void display() {
            std::cout << "Name: " << name << ", Age: " << age << std::endl;
        }
    };
    ```

- **Class Declaration

    ```cpp
    student s;
    s.name = "Alice";
    s.age = 20;
    s.display();
    ```

- **Class Initialization**: Initializing class members when creating an object.

    ```cpp
    student s = {"Alice", 20};
    s.display();
    ```

## Object-Oriented Programming

Object-oriented programming (OOP) is a programming paradigm that uses objects and classes to model real-world entities and concepts. It focuses on data abstraction, encapsulation, inheritance, and polymorphism to create modular and reusable code.

### Basic Concepts

- **Class**: A blueprint for creating objects.
- **Object**: An instance of a class.
- **Encapsulation**: Bundling data and methods that operate on the data within one unit (class).
- **Inheritance**: Mechanism by which one class can inherit traits from another class.
- **Polymorphism**: Ability to process objects differently based on their data type or class.
- **Abstraction**: Hiding complex implementation details and showing only the necessary features.

### Classes and Objects

Classes and objects are fundamental concepts in object-oriented programming that allow you to model real-world entities as software objects. A class is a blueprint for creating objects, while an object is an instance of a class that represents a specific entity.

#### Defining Classes and Objects

- **Class**: A blueprint for creating objects that defines data members and member functions.

    ```cpp
    class Rectangle {
    public:
        int width;
        int height;
        int area() {
            return width * height;
        }
    };
    ```

- **Object**: An instance of a class that represents a specific entity.

    ```cpp
    Rectangle rect;
    rect.width = 5;
    rect.height = 3;
    int area = rect.area();
    ```

#### Access Modifiers

Access modifiers in C++ control the visibility and accessibility of class members. They include public, private, and protected modifiers.

- **Public**: Members are accessible from outside the class.
- **Private**: Members are accessible only from within the class.
- **Protected**: Members are accessible from derived classes.

#### Member Functions

Member functions in C++ are functions that are defined inside a class and operate on class objects. They can access class data members and provide behavior to the class.

- **Member Function Definition**: `returnType functionName(parameters) { body }`

    ```cpp
    class Rectangle {
    public:
        int width;
        int height;
        int area() {
            return width * height;
        }
    };
    ```

- **Member Function Declaration**: `returnType functionName(parameters);`

    ```cpp
    class Rectangle {
    public:
        int width;
        int height;
        int area();
    };
    int Rectangle::area() {
        return width * height;
    }
    ```

- **Member Function Call**: `objectName.functionName(arguments);`

    ```cpp
    Rectangle rect;
    rect.width = 5;
    rect.height = 3;
    int area = rect.area();
    ```

#### Constructors and Destructors

Constructors and destructors in C++ are special member functions of a class that are used to initialize and destroy class objects. They are automatically called when an object is created and destroyed.

- **Constructor**: Special function called when an object is instantiated. No return type.

```cpp
class MyClass {
public:
    MyClass() { // Constructor
        // Initialization code
    }
};

- **Default Constructor**: Constructor with no parameters.

```cpp
class Dog {
public:
    Dog() : name("Unknown"), age(0) {} // Default constructor
    Dog(std::string n, int a) : name(n), age(a) {} // Parameterized constructor
};
```

- **Destructor**: Special function called when an object is destroyed. No parameters or return type.

```cpp
class MyClass {
public:
    ~MyClass() { // Destructor
        // Cleanup code
    }
};
```

- **Default Destructor**: Destructor that is automatically generated if not defined.

```cpp
class MyClass {
public:
    ~MyClass() = default; // Default destructor
};
```

- **Virtual Destructor**: Destructor that is declared as virtual in the base class to ensure proper cleanup in derived classes.

```cpp
class Base {
public:
    virtual ~Base() {} // Virtual destructor
};

class Derived : public Base {
public:
    ~Derived() {} // Derived class destructor
};
```

- **Overloading Constructors**: Defining multiple constructors with different parameters.

```cpp
class Rectangle {
public:
    int width;
    int height;
    Rectangle() : width(0), height(0) {} // Default constructor
    Rectangle(int w, int h) : width(w), height(h) {} // Parameterized constructor
};
```

- **Member Initialization List**: Initializing class members in the constructor using the member initialization list.

```cpp
class Rectangle {
public:
    int width;
    int height;
    Rectangle(int w, int h) : width(w), height(h) {} // Member initialization list
};
```

#### Copy Constructors and Copy Assignment Operators

- **Copy Constructor**: Constructor that initializes an object as a copy of another object.

```cpp
class Rectangle {
public:
    int width;
    int height;
    Rectangle(const Rectangle& other) : width(other.width), height(other.height) {} // Copy constructor
};
```

- **Copy Assignment Operator**: Operator that assigns the value of one object to another object.

```cpp
class Rectangle {
public:
    int width;
    int height;
    Rectangle& operator=(const Rectangle& other) { // Copy assignment operator
        if (this != &other) {
            width = other.width;
            height = other.height;
        }
        return *this;
    }
};
```

## Rule of Zero, Three, and Five

The Rule of Zero, Rule of Three, and Rule of Five are guidelines for managing resources in C++ classes. They help ensure proper resource management, prevent memory leaks, and avoid undefined behavior.

- **Rule of Zero**: Classes that do not manage resources should not define custom destructors, copy constructors, or copy assignment operators.

```cpp
class MyClass {
public:
    // No custom destructor, copy constructor, or copy assignment operator
};
```

- **Rule of Three**: Classes that manage resources should define custom destructors, copy constructors, and copy assignment operators.

```cpp
class MyClass {
public:
    MyClass() : data(new int) {}
    ~MyClass() { delete data; }
    MyClass(const MyClass& other) : data(new int(*other.data)) {}
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            *data = *other.data;
        }
        return *this;
    }
private:
    int* data;
};
```

- **Rule of Five**: Classes that manage resources should define custom destructors, copy constructors, copy assignment operators, move constructors, and move assignment operators.

```cpp
class MyClass {
public:
    MyClass() : data(new int) {}
    ~MyClass() { delete data; }
    MyClass(const MyClass& other) : data(new int(*other.data)) {}
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            *data = *other.data;
        }
        return *this;
    }
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
private:
    int* data;
};
```

### Encapsulation

Encapsulation is a fundamental concept in object-oriented programming (OOP) that involves bundling the data (attributes) and the methods (functions) that operate on the data into a single unit called a class. It also involves restricting direct access to some of the object's components, which is a means of preventing unintended interference and misuse of the data.

#### Access Modifiers

Access modifiers in C++ are keywords that control the visibility and accessibility of class members. They include public, protected, and private modifiers.

- **Public**: Members are accessible from outside the class.

```cpp
class Rectangle {
public:
    int width;
    int height;
    int area() {
        return width * height;
    }
};
```

- **Private**: Members are accessible only from within the class.

```cpp
class Rectangle {
private:
    int width;
    int height;
public:
    int area() {
        return width * height;
    }
};
```

- **Protected**: Members are accessible from derived classes.

```cpp
class Shape {
protected:
    int width;
    int height;
public:
    int area() {
        return width * height;
    }
};

class Rectangle : public Shape {
public:
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
};
```

#### Getters and Setters

Getters and setters are methods used to access and modify the private data members of a class. They provide controlled access to the class attributes and allow for data validation and encapsulation.

- **Getters**: Methods used to access the value of a private data member.
- **Setters**: Methods used to modify the value of a private data member.

```cpp
class Rectangle {
private:
    int width;
    int height;
public:
    int getWidth() {
        return width;
    }
    void setWidth(int w) {
        width = w;
    }
    int getHeight() {
        return height;
    }
    void setHeight(int h) {
        height = h;
    }
    void calculateArea() {
        int area = width * height;
        std::cout << "Area: " << area << std::endl;
    }
};
```

```cpp
Rectangle rect;
rect.setWidth(5);
rect.setHeight(3);
int width = rect.getWidth();
int height = rect.getHeight();
rect.calculateArea();
```

#### Advantages of Encapsulation

- **Data Hiding**: Prevents direct access to class members, ensuring data integrity and security.
- **Abstraction**: Hides complex implementation details and exposes only the necessary features.
- **Modularity**: Encapsulated classes are modular and can be easily reused and maintained.
- **Flexibility**: Allows for easy modification of the class implementation without affecting the external code.

### Advanced Encapsulation Concepts

1. **Const Member Functions**: Methods that do not modify any member variables of the class should be declared as const.

```cpp
class MyClass {
private:
    int myAttribute;

public:
    int getMyAttribute() const {
        return myAttribute;
    }
};
```

2. **Immutable Classes**: Classes designed so that objects, once created, cannot be modified.

```cpp
class ImmutableClass {
private:
    const int myAttribute;

public:
    ImmutableClass(int value) : myAttribute(value) {}

    int getMyAttribute() const {
        return myAttribute;
    }
};
```

3. **Encapsulation in Inheritance**: Private members of a base class are not accessible directly in the derived class, promoting encapsulation.

```cpp
class Base {
private:
    int privateAttribute;

protected:
    int protectedAttribute;

public:
    int publicAttribute;
};

class Derived : public Base {
public:
    void accessAttributes() {
        // privateAttribute is not accessible
        // protectedAttribute and publicAttribute are accessible
        protectedAttribute = 10;
        publicAttribute = 20;
    }
};

```

### Inheritance

Inheritance is a mechanism in object-oriented programming that allows a class to inherit properties and behavior from another class. The class that inherits from another class is called a derived class, and the class that is inherited from is called a base class. In C++, you can use the `public`, `protected`, and `private` access specifiers to control the visibility of inherited members. Inheritance is achieved using the `class` keyword followed by a colon `:` and the access specifier.

#### Single Inheritance

Single inheritance is a type of inheritance in which a derived class inherits from a single base class.

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

Dog dog;
dog.eat();
dog.bark();
```

#### Multiple Inheritance

Multiple inheritance is a type of inheritance in which a derived class inherits from multiple base classes.

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Pet {
public:
    void play() {
        std::cout << "Playing..." << std::endl;
    }
};

class Dog : public Animal, public Pet {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

Dog dog;
dog.eat();
dog.play();
dog.bark();
```

#### Multilevel Inheritance

Multilevel inheritance is a type of inheritance in which a derived class inherits from another derived class.

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

class Labrador : public Dog {
public:
    void play() {
        std::cout << "Playing..." << std::endl;
    }
};

Labrador lab;
lab.eat();
lab.bark();
lab.play();
```

#### Hierarchical Inheritance

Hierarchical inheritance is a type of inheritance in which multiple derived classes inherit from a single base class.

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        std::cout << "Meowing..." << std::endl;
    }
};

Dog dog;
dog.eat();
dog.bark();
```

#### Hybrid Inheritance

Hybrid inheritance is a combination of multiple inheritance and hierarchical inheritance.

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Pet {
public:
    void play() {
        std::cout << "Playing..." << std::endl;
    }
};

class Dog : public Animal, public Pet {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

class Labrador : public Dog {
public:
    void swim() {
        std::cout << "Swimming..." << std::endl;
    }
};

Labrador lab;
lab.eat();
lab.play();
lab.bark();
```

#### Virtual Inheritance

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Pet : virtual public Animal {
public:
    void play() {
        std::cout << "Playing..." << std::endl;
    }
};

class Dog : virtual public Animal, public Pet {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

```

#### Aggregation

Aggregation is a type of association in which one class contains an object of another class. It represents a "has-a" relationship between classes, where one class has a member that is an object of another class. Aggregation is used to model relationships between classes that are not part of the same inheritance hierarchy.

- **Aggregation**: A class contains an object of another class.

```cpp
class Address {
public:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
};

class Person {
public:
    std::string name;
    Address address;
};
```

- **Composition**: A class contains an object of another class and is responsible for its creation and destruction.

```cpp
class Address {
public:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
};

class Person {
public:
    std::string name;
    Address* address;
    Person(Address* addr) : address(addr) {}
    ~Person() {
        delete address;
    }
};
```

- **Association**: A relationship between classes where one class is related to another class.

```cpp
class Person {
public:
    std::string name;
};

class Address {
public:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    Person* person;
};
```

- **Dependency**: A relationship between classes where one class depends on another class.

```cpp
class Logger {
public:
    void log(std::string message) {
        std::cout << message << std::endl;
    }
};

class Service {
public:
    void doSomething() {
        Logger logger;
        logger.log("Doing something...");
    }
};
```

### Polymorphism

Polymorphism is the ability of objects to take on different forms based on their data type or class. It allows you to process objects differently based on their class or data type. In C++, polymorphism is achieved through virtual functions, function overloading, and function overriding.

#### Function Overloading

Function overloading in C++ allows you to define multiple functions with the same name but different parameters. The compiler determines which function to call based on the number and types of arguments passed to the function.

```cpp
class Math {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
};
```

#### Function Overriding

Function overriding in C++ allows you to define a function in a derived class with the same name and signature as a function in the base class. The function in the derived class overrides the function in the base class.

```cpp
class Animal {
public:
    virtual void speak() {
        std::cout << "Animal speaks..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks..." << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Cat meows..." << std::endl;
    }
};

Animal* animal = new Dog();
animal->speak();

animal = new Cat();
animal->speak();
```

output:

```bash
Dog barks...
Cat meows...
```

#### Virtual Functions

Virtual functions in C++ are functions that are declared in a base class and can be overridden in derived classes. They allow you to achieve runtime polymorphism by calling the appropriate function based on the object's actual type.

```cpp
class Animal {
public:
    virtual void speak() {
        std::cout << "Animal speaks..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks..." << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Cat meows..." << std::endl;
    }
};

Animal* animal = new Dog();
animal->speak();

animal = new Cat();
animal->speak();
```

output:

```bash
Dog barks...
Cat meows...
```

#### Operator Overloading

Operator overloading in C++ allows you to define custom behavior for operators when they are used with user-defined types. It enables you to use operators such as `+`, `-`, `*`, `/`, `==`, `!=`, `<<`, `>>`, etc., with objects of your classes.

##### Overloading Binary Operators

Binary operators are operators that require two operands. You can overload binary operators by defining a member function or a global function that takes two arguments.

```cpp
class Complex {
public:
	double real;
	double imag;

	Complex operator+(const Complex& other) {
		Complex result;
		result.real = real + other.real;
		result.imag = imag + other.imag;
		return result;
	}
};

Complex a = {1.0, 2.0};
Complex b = {3.0, 4.0};
Complex c = a + b;
```

##### Overloading Unary Operators

Unary operators are operators that require only one operand. You can overload unary operators by defining a member function or a global function that takes one argument.

```cpp
class Complex {
public:
	double real;
	double imag;

	Complex operator-() {
		Complex result;
		result.real = -real;
		result.imag = -imag;
		return result;
	}
};

Complex a = {1.0, 2.0};
Complex b = -a;
```

##### Overloading Comparison Operators

Comparison operators are operators that compare two values. You can overload comparison operators by defining a member function or a global function that takes two arguments.

```cpp
class Complex {
public:
	double real;
	double imag;

	bool operator==(const Complex& other) {
		return real == other.real && imag == other.imag;
	}
};

Complex a = {1.0, 2.0};
Complex b = {1.0, 2.0};

if (a == b) {
	std::cout << "Equal" << std::endl;
}
```

##### Overloading Stream Operators

Stream operators are operators used for input and output operations. You can overload stream operators by defining a member function or a global function that takes a stream object as an argument.

```cpp
class Complex {
public:
	double real;
	double imag;

	friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
		os << c.real << " + " << c.imag << "i";
		return os;
	}
};

Complex c = {1.0, 2.0};
std::cout << c << std::endl;
```

### Polymorphism with Pointers and References

Polymorphism in C++ can be achieved using pointers and references to base class objects. This allows you to call virtual functions on objects of derived classes through pointers or references to the base class.

```cpp
class Animal {
public:
	virtual void speak() {
		std::cout << "Animal speaks..." << std::endl;
	}
};

class Dog : public Animal {
public:
	void speak() override {
		std::cout << "Dog barks..." << std::endl;
	}
};

class Cat : public Animal {

public:
	void speak() override {
		std::cout << "Cat meows..." << std::endl;
	}
};

Animal* animal = new Dog();
animal->speak();

animal = new Cat();
animal->speak();
```

output:

```bash
Dog barks...
Cat meows...
```



### Abstraction

Abstraction is the process of hiding complex implementation details and showing only the necessary features of an object. It allows you to focus on what an object does rather than how it does it. In C++, you can achieve abstraction through classes, access specifiers, and interfaces.

- **Abstract Class**: A class that cannot
be instantiated and is used as a base class for other classes.

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle..." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a rectangle..." << std::endl;
    }
};
```

- **Interface**: A class that contains only pure virtual functions and no data members.

```cpp
class Drawable {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Drawable {
public:
    void draw() override {
        std::cout << "Drawing a circle..." << std::endl;
    }
};

class Rectangle : public Drawable {
public:
    void draw() override {
        std::cout << "Drawing a rectangle..." << std::endl;
    }
};

void drawShapes(Drawable* shapes[], int count) {
    for (int i = 0; i < count; i++) {
        shapes[i]->draw();
    }
}

Circle circle;
Rectangle rectangle;

Drawable* shapes[] = {&circle, &rectangle};
drawShapes(shapes, 2);
```

output:

```bash
Drawing a circle...
Drawing a rectangle...
```

## Templates

Templates in C++ are a powerful feature that allows you to write generic code that works with any data type. They enable you to define functions, classes, and data structures that can operate on different data types without having to rewrite the code for each type. Templates are used to create generic algorithms and data structures that are type-independent.

### Function Templates

Function templates in C++ allow you to define functions that can operate on different data types. They are defined using the `template` keyword followed by the template parameter.

- **Function Template Definition**: `template <typename T> returnType functionName(T arg) { body }`

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

- **Function Template Call**: `functionName<dataType>(arguments)`

```cpp
int sum = add<int>(3, 5);
double total = add<double>(3.14, 2.71);
```

### Class Templates

Class templates in C++ allow you to define classes that can operate on different data types. They are defined using the `template` keyword followed by the template parameter.

- **Class Template Definition**: `template <typename T> class ClassName { members };`

```cpp
template <typename T>
class Pair {
public:
    T first;
    T second;
    Pair(T f, T s) : first(f), second(s) {}
};
```

- **Class Template Instantiation**: `ClassName<dataType> objectName(arguments)`

```cpp
Pair<int> p1(1, 2);
Pair<double> p2(3.14, 2.71);
```

### Template Specialization

Template specialization in C++ allows you to define a specialized version of a template for a specific data type. It enables you to provide custom behavior for a specific data type while using the generic template for other types.

- **Template Specialization**: `template <> class ClassName<dataType> { members };`

```cpp
template <typename T>
class Pair {
public:
    T first;
    T second;
    Pair(T f, T s) : first(f), second(s) {}
};

template <>
class Pair<std::string> {
public:
    std::string first;
    std::string second;
    Pair(std::string f, std::string s) : first(f), second(s) {}
};
```

- **Template Specialization Usage**: `ClassName<dataType> objectName(arguments)`

```cpp
Pair<int> p1(1, 2);
Pair<std::string> p2("Hello", "World");
```

### Template Constraints

Template constraints in C++ allow you to restrict the types that can be used with a template. They enable you to specify requirements for the template parameters, such as requiring the type to have certain member functions or properties.

- **Template Constraints**: `template <typename T> requires ConstraintType<T> returnType functionName(T arg) { body }`

```cpp
template <typename T> requires std::integral<T>
T add(T a, T b) {
    return a + b;
}
```

- **Concepts**: Concepts are a C++20 feature that provides a more readable and expressive way to define template constraints.

```cpp
template <typename T>
concept Integral = std::is_integral<T>::value;

template <Integral T>
T add(T a, T b) {
    return a + b;
}
```

### Variadic Templates

Variadic templates in C++ allow you to define functions and classes that can take a variable number of arguments. They enable you to create flexible and generic code that can operate on any number of arguments.

- **Variadic Function Templates**: `template <typename... Args> returnType functionName(Args... args) { body }`

```cpp
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;
}
```

- **Variadic Class Templates**: `template <typename... Args> class ClassName { members };`

```cpp
template <typename... Args>
class Tuple {
public:
    std::tuple<Args...> data;
    Tuple(Args... args) : data(args...) {}
};
```

- **Variadic Template Expansion**: `(expression op ...)` expands the expression for each argument.

```cpp
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;
}
```

### Template Meta-Programming

Template metaprogramming in C++ allows you to perform computations and generate code at compile time using templates. It enables you to write code that operates on types rather than values and can be used to optimize performance, reduce code duplication, and enable static polymorphism.



## Pointers and Reference

Pointers and references are used in C++ to store memory addresses and access data indirectly. They are essential for dynamic memory allocation, function calls, and efficient data manipulation.

**Pointers**: is a variable that stores the memory address of another variable. It allows direct access to the memory location of a variable.

**References**: is an alias for a variable that provides an alternative name for the same memory location. It allows indirect access to the variable.

### Basics

- **Declaration**: `type *ptr;`
- **Initialization**: `int *ptr = &variable;`
- **Dereferencing**: `*ptr` retrieves the value pointed to by `ptr`.
- **Address-of Operator**: `&variable` gets the memory address of `variable`.

### Pointer Arithmetic

- **Increment/Decrement**: `ptr++`, `ptr--`.
- **Arithmetic Operations**: `ptr + n`, `ptr - n`.

### Pointer and Arrays

- **Array Name as Pointer**: Arrays decay into pointers to their first element.
- **Accessing Array Elements**: `*(arr + i)` or `arr[i]`.

### Pointers and Functions

- **Passing Pointers to Functions**: `void foo(int *ptr)`.
- **Returning Pointers from Functions**: `int* foo()`.
- **Pointer to Functions**: `returnType (*ptrName)(parameters);`.

### Pointer and Classes

- **Pointer to Object**: `ClassName *ptr = new ClassName;`
- **Accessing Members**: `ptr->member` or `(*ptr).member`.

### Pointer to Pointer (Double Pointer)

- **Declaration**: `type **ptr;`
- **Initialization**: `type **ptr = &anotherPtr;`
- **Use**: `**ptr` retrieves the value pointed to by another pointer.

### Null Pointers

- **Null Pointer**: `nullptr`.
- **Checking Null Pointers**: `if (ptr == nullptr)`.

### Pointer Casting

- **Casting Pointers**: `type *ptr = reinterpret_cast<type*>(anotherPtr);`

### Pointer and Const

- **Constant Pointers**: `const type *ptr;` or `type *const ptr;`.
- **Pointer to Constant**: `const int *ptr;` (value is constant, pointer is not) or `int *const ptr;` (pointer is constant, value is not).

### References

- **Declaration**: `type &ref = variable;`
- **Initialization**: `int x = 42; int &ref = x;`
- **Use**: `ref` is an alias for `variable`.

### Reference vs. Pointer

- **Null References**: References cannot be null.
- **Reassignment**: References cannot be reassigned.
- **Dereferencing**: References do not need to be dereferenced.
- **Function Arguments**: References are used for passing arguments by reference.

### Reference to Pointer

- **Reference to Pointer**: `type *&ref = ptr;`
- **Initialization**: `type *ptr = &variable; type *&ref = ptr;`

### Reference to Const

- **Reference to Constant**: `const type &ref = variable;`
- **Constant Reference**: `const int &ref = x;`

## Memory Model

The memory model in C++ defines how the program stores and accesses data in computer memory. It consists of different segments, such as the Stack, Heap, Data and Code segments. Each of these segments is used to store different types of data and has specific characteristics.

### Stack Memory

- **LIFO Data Structure**: Last In, First Out.
- **Automatic Memory Management**: Memory is allocated and deallocated automatically.
- **Local Variables**: Function parameters and local variables are stored on the stack.
- **Fixed Size**: Stack size is limited and determined at compile time.
- **Faster Access**: Faster access compared to the heap.

```cpp
void foo() {
    int x = 42; // Stored on the stack
}
```

### Heap Memory

- **Dynamic Memory Allocation**: Memory is allocated and deallocated manually.
- **Unlimited Size**: Heap size is limited by available memory.
- **Slower Access**: Slower access compared to the stack.
- **Data Structures**: Objects, arrays, and data structures are stored on the heap.

```cpp
int *ptr = new int; // Allocated on the heap
delete ptr; // Deallocated manually
```

### Data Segment

- **Global and Static Variables**: Global variables and static variables are stored in the data segment.
- **Initialized Data**: Data with static or constant values is stored in this segment.
- **Read-Only Memory**: Data in this segment is read-only and cannot be modified.

```cpp
int globalVar = 42; // Stored in the data segment
static int staticVar = 42; // Stored in the data segment
```

### Code Segment

- **Executable Code**: Machine instructions and program code are stored in the code segment.
- **Read-Only Memory**: Code in this segment is read-only and cannot be modified.
- **Program Instructions**: Instructions for the program execution are stored in this segment.

```cpp
int main() {
    return 0; // Executable code in the code segment
}
```

## Memory Management

Memory management in C++ involves the allocation, use, and deallocation of memory during the execution of a program. Proper memory management is crucial to ensure efficient use of memory resources, prevent memory leaks, and avoid undefined behavior.

### Stack vs. Heap

- **Stack**: Stores local variables and function call information. Memory is automatically managed (allocated/deallocated).
- **Heap**: Used for dynamic memory allocation. Memory is manually managed using `new` and `delete`.

### Static Memory Allocation

Static memory allocation in C++ involves allocating memory at compile time for variables with fixed sizes. It is used for global variables, static variables, and arrays.

```cpp
int globalVar = 42; // Static memory allocation
static int staticVar = 42; // Static memory allocation
int arr[5]; // Static memory allocation
```

### Dynamic Memory Allocation

Dynamic memory allocation in C++ involves allocating memory at runtime for variables with varying sizes. It is used for objects, arrays, and data structures.

- **Allocation**: `type *ptr = new type;` or `type *arr = new type[size];`
- **Deallocation**: `delete ptr;` or `delete[] arr;`

```cpp
int *ptr = new int; // Dynamic memory allocation
*ptr = 42;
delete ptr; // Deallocate memory


int *arr = new int[5]; // Dynamic memory allocation for an array
arr[0] = 1;
delete[] arr; // Deallocate memory
```

**malloc() and free()**:

- **Allocation**: `type *ptr = (type*)malloc(sizeof(type));` or `type *arr = (type*)malloc(size * sizeof(type));`
- **Deallocation**: `free(ptr);` or `free(arr);`

```cpp
int *ptr = (int*)malloc(sizeof(int)); // Dynamic memory allocation using malloc
*ptr = 42;
free(ptr); // Deallocate memory

int *arr = (int*)malloc(5 * sizeof(int)); // Dynamic memory allocation for an array using malloc
arr[0] = 1;
free(arr); // Deallocate memory
```

### Memory Leaks

Memory leaks occur when memory is allocated but not deallocated, leading to memory wastage and potential performance issues. It is important to deallocate memory properly to avoid memory leaks.

```cpp
void foo() {
    int *ptr = new int; // Memory allocated
    // Code that does not deallocate memory
}
```

### Smart Pointers

Smart pointers in C++ are objects that manage memory automatically and ensure proper deallocation. They provide automatic memory management and help prevent memory leaks.

#### Unique Pointe

Unique pointers are smart pointers that ensure exclusive ownership of the allocated memory. They automatically deallocate memory when they go out of scope.

```cpp
#include <memory>

int main() {
    std::unique_ptr<int> ptr(new int); // Unique pointer
    *ptr = 42;
    // Memory deallocated automatically when ptr goes out of scope
    return 0;
}
```

#### Shared Pointer

Shared pointers are smart pointers that allow multiple pointers to share ownership of the allocated memory. They use reference counting to manage memory and deallocate it when the last pointer is destroyed.

```cpp
#include <memory>

int main() {
    std::shared_ptr<int> ptr1(new int); // Shared pointer
    std::shared_ptr<int> ptr2 = ptr1; // Shared ownership
    *ptr1 = 42;
    // Memory deallocated when both ptr1 and ptr2 go out of scope
    return 0;
}
```

#### Weak Pointer

Weak pointers are smart pointers that observe shared pointers without owning the memory. They are used to prevent circular references and avoid memory leaks in shared ownership scenarios.

```cpp
#include <memory>

int main() {
    std::shared_ptr<int> ptr1(new int); // Shared pointer
    std::weak_ptr<int> ptr2 = ptr1; // Weak pointer observing shared pointer
    std::shared_ptr<int> ptr3 = ptr2.lock(); // Convert weak pointer to shared pointer
    *ptr1 = 42;
    // Memory deallocated when ptr1 goes out of scope
    return 0;
}
```

### RAII (Resource Acquisition Is Initialization)

RAII is a programming idiom in C++ that ensures resources are acquired and released automatically. It is used to manage resources like memory, files, and locks by tying their lifetime to the lifetime of objects.

```cpp
class File {
private:
    FILE *file;
public:
    File(const char *filename) {
        file = fopen(filename, "r");
    }
    ~File() {
        if (file) {
            fclose(file);
        }
    }
};
```

## Standard Library

The C++ Standard Library is a collection of classes and functions that provide common programming tasks, such as input/output, strings, containers, algorithms, and utilities. It is part of the C++ language specification and is available in all compliant C++ compilers.

### Input and Output

Input and output operations in C++ are performed using the `iostream` library, which provides classes and objects for reading from and writing to the console, files, and other input/output devices.

#### Output (Printing)

- **Standard Output Stream**: `std::cout`
  - **Description**: Used for printing output to the console.
  - **Example**:

    ```cpp
    #include <iostream>
    int main() {
        std::cout << "Hello, world!" << std::endl;
        return 0;
    }
    ```

- **Standard Error Stream**: `std::cerr`
  - **Description**: Used for printing error messages to the console.
  - **Example**:

    ```cpp
    #include <iostream>
    int main() {
        std::cerr << "Error: File not found!" << std::endl;
        return 1;
    }
    ```

- **Standard Log Stream**: `std::clog`
  - **Description**: Used for printing log messages to the console.
  - **Example**:

    ```cpp
    #include <iostream>
    int main() {
        std::clog << "Log: Program started" << std::endl;
        return 0;
    }
    ```

- **Formatting Output**: `std::setw`, `std::setprecision`, `std::fixed`, `std::scientific`
  - **Description**: Used to format the output of numeric values.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <iomanip>
    int main() {
        double pi = 3.14159;
        std::cout << std::fixed << std::setprecision(2) << pi << std::endl;
        return 0;
    }
    ```

- **Output Manipulators**: `std::endl`, `std::setw`, `std::setfill`, `std::setprecision`
  - **Description**: Used to control the formatting of output.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <iomanip>
    int main() {
        int x = 42;
        std::cout << std::setw(10) << std::setfill('*') << x << std::endl;
        return 0;
    }
    ```

#### Input (Reading)

- **Standard Input Stream**: `std::cin`
  - **Description**: Used for reading input from the console.
  - **Example**:

    ```cpp
    #include <iostream>
    int main() {
        int number;
        std::cout << "Enter a number: ";
        std::cin >> number;
        std::cout << "You entered: " << number << std::endl;
        return 0;
    }
    ```

- **Reading Strings**: `std::getline`
  - **Description**: Used to read a line of text from the console.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <string>
    int main() {
        std::string name;
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
        std::cout << "Hello, " << name << "!" << std::endl;
        return 0;
    }
    ```

- **Input Validation**: `std::cin.fail()`, `std::cin.clear()`, `std::cin.ignore()`
  - **Description**: Used to handle input errors and clear the input buffer.
  - **Example**:

    ```cpp
    #include <iostream>
    int main() {
        int number;
        while (true) {
            std::cout << "Enter a number: ";
            std::cin >> number;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please try again." << std::endl;
            } else {
                std::cout << "You entered: " << number << std::endl;
                break;
            }
        }
        return 0;
    }
    ```

### File I/O

File input/output operations in C++ are performed using the `fstream` library, which provides classes and objects for reading from and writing to files.

#### Reading from Files

- **Reading from a File**: `std::ifstream`
  - **Description**: Used to read data from a file.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <fstream>
    int main() {
        std::ifstream file("data.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
        return 0;
    }
    ```

#### Writing to Files

- **Writing to a File**: `std::ofstream`
  - **Description**: Used to write data to a file.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <fstream>
    int main() {
        std::ofstream file("output.txt");
        if (file.is_open()) {
            file << "Hello, world!" << std::endl;
            file.close();
        } else {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
        return 0;
    }
    ```

#### Appending to Files

- **Appending to a File**: `std::ofstream` with `std::ios::app`
  - **Description**: Used to append data to an existing file.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <fstream>
    int main() {
        std::ofstream file("output.txt", std::ios::app);
        if (file.is_open()) {
            file << "Hello, world!" << std::endl;
            file.close();
        } else {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
        return 0;
    }
    ```

#### Binary Files

- **Reading/Writing Binary Files**: `std::ios::binary`
  - **Description**: Used to read/write binary data to/from a file.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <fstream>
    int main() {
        std::ofstream file("data.bin", std::ios::binary);
        if (file.is_open()) {
            int data[] = {1, 2, 3, 4, 5};
            file.write(reinterpret_cast<char*>(data), sizeof(data));
            file.close();
        } else {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
        return 0;
    }
    ```

#### File Status

- **Checking File Status**: `is_open()`, `good()`, `fail()`, `bad()`
  - **Description**: Used to check the status of file operations.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <fstream>
    int main() {
        std::ifstream file("data.txt");
        if (file.is_open()) {
            std::cout << "File opened successfully." << std::endl;
            file.close();
        } else {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
        return 0;
    }
    ```

#### File Positioning

- **Seeking in a File**: `seekg`, `seekp`, `tellg`, `tellp`
  - **Description**: Used to move the file pointer to a specific position.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <fstream>
    int main() {
        std::ifstream file("data.txt");
        if (file.is_open()) {
            file.seekg(5, std::ios::beg);
            std::string line;
            std::getline(file, line);
            std::cout << "Line: " << line << std::endl;
            file.close();
        } else {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
        return 0;
    }
    ```

#### File Streams

- **File Streams**: `std::ifstream`, `std::ofstream`, `std::fstream`
  - **Description**: Used for input, output, and input/output file operations.
  - **Example**:

    ```cpp
    #include <iostream>
    #include <fstream>
    int main() {
        std::fstream file("data.txt", std::ios::in | std::ios::out);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
        return 0;
    }
    ```

### Strings

The string class in C++ is provided by the `<string>` header and is used to manipulate sequences of characters. It includes functions for string creation, concatenation, comparison, and manipulation.

- **String Class**: `std::string`
- **String Operations**: `length()`, `find()`, `substr()`

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";
    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "Substring: " << str.substr(0, 5) << std::endl;
    return 0;
}
```

### Containers

Containers in C++ are data structures that store and organize data elements. They provide different ways to access, insert, and remove elements and are used to manage collections of objects efficiently.

#### Sequence Containers

Sequence containers in C++ are data structures that store elements in a linear sequence. They provide random access to elements and support efficient insertion and deletion operations.

##### Array

An array is a fixed-size collection of elements of the same data type. It provides random access to elements and is defined using a contiguous block of memory.

```cpp
int arr[5] = {1, 2, 3, 4, 5};
std::cout << "arr[0]: " << arr[0] << std::endl;
```

##### Vector

A vector is a dynamic array that can grow and shrink in size. It provides random access to elements and supports efficient insertion and deletion at the end. Vectors are part of the Standard Template Library (STL) and are defined in the `<vector>` header.

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort and std::reverse

int main() {
    // 1. Initialization
    std::vector<int> vec1;                          // Empty vector
    std::vector<int> vec2(5, 10);                   // Vector of size 5, all elements initialized to 10
    std::vector<int> vec3 = {1, 2, 3, 4, 5};        // List initialization

    // 2. Adding elements
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    // 3. Accessing elements
    std::cout << "vec1[0]: " << vec1[0] << std::endl;  // Using operator[]
    std::cout << "vec1 at index 1: " << vec1.at(1) << std::endl; // Using at() method

    // 4. Iterating through the vector
    std::cout << "Elements in vec1: ";
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements in vec2: ";
    for (const auto& elem : vec2) {  // Using range-based for loop
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 5. Common operations
    vec3.push_back(6); // Add element at the end
    vec3.pop_back();   // Remove last element
    vec3.insert(vec3.begin() + 2, 99); // Insert 99 at index 2
    vec3.erase(vec3.begin() + 2); // Erase element at index 2

    std::sort(vec3.begin(), vec3.end()); // Sort the vector
    std::reverse(vec3.begin(), vec3.end()); // Reverse the vector

    std::cout << "Elements in vec3 after operations: ";
    for (const auto& elem : vec3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 6. Clearing and resizing the vector
    vec3.clear(); // Remove all elements
    std::cout << "Size of vec3 after clear: " << vec3.size() << std::endl;

    vec3.resize(5, 7); // Resize to 5 elements, new elements initialized to 7
    std::cout << "Elements in vec3 after resize: ";
    for (const auto& elem : vec3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

##### deque

A deque (double-ended queue) is a sequence container that allows for efficient insertion and deletion of elements at both ends. It provides random access to elements and supports constant time insertion and deletion operations at the beginning and end. Deques are part of the Standard Template Library (STL) and are defined in the `<deque>` header.

```cpp
#include <iostream>
#include <deque>
#include <algorithm> // For std::sort and std::reverse

int main() {
    // 1. Initialization
    std::deque<int> deq1;                          // Empty deque
    std::deque<int> deq2(5, 10);                   // Deque of size 5, all elements initialized to 10
    std::deque<int> deq3 = {1, 2, 3, 4, 5};        // List initialization

    // 2. Adding elements
    deq1.push_back(1);
    deq1.push_back(2);
    deq1.push_back(3);
    deq1.push_front(0);                           // Adding element at the front

    // 3. Accessing elements
    std::cout << "deq1[0]: " << deq1[0] << std::endl;  // Using operator[]
    std::cout << "deq1 at index 1: " << deq1.at(1) << std::endl; // Using at() method
    std::cout << "First element in deq1: " << deq1.front() << std::endl;
    std::cout << "Last element in deq1: " << deq1.back() << std::endl;

    // 4. Iterating through the deque
    std::cout << "Elements in deq1: ";
    for (int i = 0; i < deq1.size(); ++i) {
        std::cout << deq1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements in deq2: ";
    for (const auto& elem : deq2) {  // Using range-based for loop
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 5. Common operations
    deq3.push_back(6); // Add element at the end
    deq3.pop_back();   // Remove last element
    deq3.push_front(0); // Add element at the front
    deq3.pop_front(); // Remove first element

    auto it = std::find(deq3.begin(), deq3.end(), 3);
    if (it != deq3.end()) {
        deq3.insert(it, 99); // Insert 99 before element 3
    }
    it = std::find(deq3.begin(), deq3.end(), 3);
    if (it != deq3.end()) {
        deq3.erase(it); // Erase element 3
    }

    std::sort(deq3.begin(), deq3.end()); // Sort the deque
    std::reverse(deq3.begin(), deq3.end()); // Reverse the deque

    std::cout << "Elements in deq3 after operations: ";
    for (const auto& elem : deq3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 6. Clearing and resizing the deque
    deq3.clear(); // Remove all elements
    std::cout << "Size of deq3 after clear: " << deq3.size() << std::endl;

    deq3.resize(5, 7); // Resize to 5 elements, new elements initialized to 7
    std::cout << "Elements in deq3 after resize: ";
    for (const auto& elem : deq3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

##### List

A list is a doubly linked list that allows for efficient insertion and deletion of elements at any position. It provides bidirectional iterators and supports constant time insertion and deletion operations. Lists are part of the Standard Template Library (STL) and are defined in the `<list>` header.

```cpp
#include <iostream>
#include <list>

int main() {
    // 1. Initialization
    std::list<int> list1;                          // Empty list
    std::list<int> list2(5, 10);                   // List of size 5, all elements initialized to 10
    std::list<int> list3 = {1, 2, 3, 4, 5};        // List initialization

    // 2. Adding elements
    list1.push_back(1);
    list1.push_front(2);
    list1.insert(list1.begin(), 3);

    // 3. Accessing elements
    std::cout << "list1 front: " << list1.front() << std::endl;
    std::cout << "list1 back: " << list1.back() << std::endl;

    // 4. Iterating through the list
    std::cout << "Elements in list1: ";
    for (const auto& elem : list1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 5. Common operations
    list1.pop_back(); // Remove last element
    list1.pop_front(); // Remove first element
    list1.erase(list1.begin()); // Erase element at the beginning

    list1.reverse(); // Reverse the list
    list1.sort(); // Sort the list

    std::cout << "Elements in list1 after operations: ";
    for (const auto& elem : list1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 6. Clearing the list
    list1.clear(); // Remove all elements
    std::cout << "Size of list1 after clear: " << list1.size() << std::endl;

    return 0;
}
```

##### Forward List

A forward list is a singly linked list that allows for efficient insertion and deletion of elements at the beginning and end. It provides forward iterators and supports constant time insertion and deletion operations. Forward lists are part of the Standard Template Library (STL) and are defined in the `<forward_list>` header.

```cpp
#include <iostream>
#include <forward_list>
#include <algorithm> // For std::find

int main() {
    // 1. Initialization
    std::forward_list<int> flist1;                          // Empty forward_list
    std::forward_list<int> flist2(5, 10);                   // Forward_list of size 5, all elements initialized to 10
    std::forward_list<int> flist3 = {1, 2, 3, 4, 5};        // List initialization

    // 2. Adding elements
    flist1.push_front(1);
    flist1.push_front(2);
    flist1.push_front(3);  // Elements are added to the front
    flist1.push_front(0);  // Adding element at the front

    // 3. Accessing elements
    std::cout << "First element in flist1: " << flist1.front() << std::endl;

    // 4. Iterating through the forward_list
    std::cout << "Elements in flist1: ";
    for (const auto& elem : flist1) {               // Using range-based for loop
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements in flist2: ";
    for (auto it = flist2.begin(); it != flist2.end(); ++it) { // Using iterator
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 5. Common operations
    flist3.push_front(0);                           // Add element at the front
    flist3.pop_front();                             // Remove first element

    auto it = std::find(flist3.begin(), flist3.end(), 3);
    if (it != flist3.end()) {
        flist3.insert_after(it, 99);                // Insert 99 after element 3
    }
    it = std::find(flist3.begin(), flist3.end(), 3);
    if (it != flist3.end()) {
        flist3.erase_after(it);                     // Erase element after 3
    }

    flist3.sort();                                  // Sort the forward_list
    flist3.reverse();                               // Reverse the forward_list

    std::cout << "Elements in flist3 after operations: ";
    for (const auto& elem : flist3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 6. Clearing and resizing the forward_list
    flist3.clear();                                 // Remove all elements
    std::cout << "Is flist3 empty after clear? " << (flist3.empty() ? "Yes" : "No") << std::endl;

    flist3.assign(5, 7);                            // Resize to 5 elements, all initialized to 7
    std::cout << "Elements in flist3 after assign: ";
    for (const auto& elem : flist3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### Associative Containers

Associative containers in C++ are data structures that store elements in a sorted order based on keys. They provide fast search, insertion, and deletion operations and are used to manage key-value pairs efficiently.

##### Set

A set is an associative container that stores unique elements in a sorted order. It provides fast search, insertion, and deletion operations and is implemented using a balanced binary search tree. Sets are part of the Standard Template Library (STL) and are defined in the `<set>` header.

```cpp
#include <iostream>
#include <set>
#include <algorithm> // For std::find

int main() {
    // 1. Initialization
    std::set<int> set1;                          // Empty set
    std::set<int> set2 = {5, 1, 3, 2, 4};        // Set initialization with elements

    // 2. Adding elements
    set1.insert(3);
    set1.insert(1);
    set1.insert(2);
    set1.insert(4);
    set1.insert(5); // Duplicates will be ignored automatically

    // 3. Accessing elements
    std::cout << "Set1 contains: ";
    for (const auto& elem : set1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 4. Iterating through the set
    std::cout << "Set2 contains: ";
    for (auto it = set2.begin(); it != set2.end(); ++it) { // Using iterator
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 5. Common operations
    auto it = set1.find(3); // Find element
    if (it != set1.end()) {
        std::cout << "Element 3 found in set1" << std::endl;
    } else {
        std::cout << "Element 3 not found in set1" << std::endl;
    }

    set1.erase(3); // Erase element
    it = set1.find(3);
    if (it == set1.end()) {
        std::cout << "Element 3 erased from set1" << std::endl;
    }

    std::cout << "Set1 contains after erase: ";
    for (const auto& elem : set1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 6. Clearing and checking size
    set1.clear(); // Remove all elements
    std::cout << "Is set1 empty after clear? " << (set1.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of set2: " << set2.size() << std::endl;

    return 0;
}
```

##### Map

A map is an associative container that stores key-value pairs in a sorted order based on the keys. It provides fast search, insertion, and deletion operations and is implemented using a balanced binary search tree. Maps are part of the Standard Template Library (STL) and are defined in the `<map>` header.

```cpp
#include <iostream>
#include <map>

int main() {
    // 1. Initialization
    std::map<char, int> myMap; // Empty map
    std::map<char, int> anotherMap = { {'a', 1}, {'b', 2}, {'c', 3} }; // Map initialization with elements

    // 2. Adding elements
    myMap['a'] = 10; // Inserting or updating value for key 'a'
    myMap.insert(std::make_pair('b', 20)); // Inserting using insert function
    myMap.emplace('c', 30); // Emplace: constructs element in-place

    // 3. Accessing elements
    std::cout << "Value of key 'a': " << myMap['a'] << std::endl;

    // 4. Iterating through the map
    std::cout << "Contents of myMap:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // 5. Common operations
    auto it = myMap.find('b'); // Find element by key
    if (it != myMap.end()) {
        std::cout << "Element with key 'b' found. Value: " << it->second << std::endl;
    }

    myMap.erase('c'); // Erase element by key

    std::cout << "Size of myMap after erasing 'c': " << myMap.size() << std::endl;

    // 6. Clearing and checking size
    myMap.clear(); // Clear all elements
    std::cout << "Is myMap empty after clear? " << (myMap.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of anotherMap: " << anotherMap.size() << std::endl;

    return 0;
}
```

##### Multiset

A multiset is an associative container that stores multiple elements with the same key in a sorted order. It provides fast search, insertion, and deletion operations and is implemented using a balanced binary search tree. Multisets are part of the Standard Template Library (STL) and are defined in the `<set>` header.

```cpp
#include <iostream>
#include <set>

int main() {
    // 1. Initialization
    std::multiset<int> multiSet; // Empty multiset
    std::multiset<int> anotherSet = {1, 2, 3, 4, 5}; // Multiset initialization with elements

    // 2. Adding elements
    multiSet.insert(10); // Inserting elements
    multiSet.insert(20);
    multiSet.insert(10); // Duplicates are allowed in multiset

    // 3. Accessing elements
    std::cout << "Contents of multiSet:" << std::endl;
    for (const auto& elem : multiSet) {
        std::cout << elem << std::endl;
    }

    // 4. Checking if an element exists
    int target = 20;
    if (multiSet.find(target) != multiSet.end()) {
        std::cout << target << " exists in the multiset." << std::endl;
    } else {
        std::cout << target << " does not exist in the multiset." << std::endl;
    }

    // 5. Removing elements
    multiSet.erase(20); // Removing element

    // 6. Clearing and checking size
    multiSet.clear(); // Clear all elements
    std::cout << "Is multiSet empty after clear? " << (multiSet.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of anotherSet: " << anotherSet.size() << std::endl;

    return 0;
}
```

##### Multimap

A multimap is an associative container that stores multiple key-value pairs with the same key in a sorted order. It provides fast search, insertion, and deletion operations and is implemented using a balanced binary search tree. Multimaps are part of the Standard Template Library (STL) and are defined in the `<map>` header.

```cpp
#include <iostream>
#include <map>

int main() {
    // 1. Initialization
    std::multimap<char, int> myMultiMap; // Empty multimap
    std::multimap<char, int> anotherMultiMap = { {'a', 1}, {'b', 2}, {'c', 3} }; // Multimap initialization with elements

    // 2. Adding elements
    myMultiMap.insert(std::make_pair('a', 10)); // Inserting elements
    myMultiMap.insert(std::make_pair('b', 20));
    myMultiMap.insert(std::make_pair('a', 30)); // Duplicates are allowed in multimap

    // 3. Accessing elements
    std::cout << "Contents of myMultiMap:" << std::endl;
    for (const auto& pair : myMultiMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // 4. Checking if a key exists
    char target = 'b';
    auto range = myMultiMap.equal_range(target);
    if (range.first != myMultiMap.end()) {
        std::cout << "Key '" << target << "' exists in the multimap." << std::endl;
    } else {
        std::cout << "Key '" << target << "' does not exist in the multimap." << std::endl;
    }

    // 5. Removing elements
    myMultiMap.erase('b'); // Removing element by key

    // 6. Clearing and checking size
    myMultiMap.clear(); // Clear all elements
    std::cout << "Is myMultiMap empty after clear? " << (myMultiMap.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of anotherMultiMap: " << anotherMultiMap.size() << std::endl;

    return 0;
}
```

#### Unordered Associative Containers

Unordered associative containers in C++ are data structures that store elements in an unordered manner based on keys. They provide fast search, insertion, and deletion operations and are implemented using a hash table.

##### Unordered Set

An unordered set is an associative container that stores unique elements in an unordered manner. It provides fast search, insertion, and deletion operations and is implemented using a hash table. Unordered sets are part of the Standard Template Library (STL) and are defined in the `<unordered_set>` header.

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    // 1. Initialization
    std::unordered_set<int> mySet; // Empty unordered_set
    std::unordered_set<int> anotherSet = {1, 2, 3, 4, 5}; // Set initialization with elements

    // 2. Adding elements
    mySet.insert(10); // Inserting elements
    mySet.insert(20);
    mySet.insert(30);

    // 3. Accessing elements
    std::cout << "Contents of mySet:" << std::endl;
    for (const auto& elem : mySet) {
        std::cout << elem << std::endl;
    }

    // 4. Checking if an element exists
    int target = 20;
    if (mySet.find(target) != mySet.end()) {
        std::cout << target << " exists in the set." << std::endl;
    } else {
        std::cout << target << " does not exist in the set." << std::endl;
    }

    // 5. Removing elements
    mySet.erase(20); // Removing element

    // 6. Clearing and checking size
    mySet.clear(); // Clear all elements
    std::cout << "Is mySet empty after clear? " << (mySet.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of anotherSet: " << anotherSet.size() << std::endl;

    return 0;
}
```

##### Unordered Map

An unordered map is an associative container that stores key-value pairs in an unordered manner. It provides fast search, insertion, and deletion operations and is implemented using a hash table. Unordered maps are part of the Standard Template Library (STL) and are defined in the `<unordered_map>` header.

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    // 1. Initialization
    std::unordered_map<std::string, int> myMap; // Empty unordered_map
    std::unordered_map<std::string, int> anotherMap = { {"one", 1}, {"two", 2}, {"three", 3} }; // Map initialization with elements

    // 2. Adding elements
    myMap["apple"] = 10; // Inserting or updating value for key "apple"
    myMap.insert(std::make_pair("banana", 20)); // Inserting using insert function
    myMap.emplace("orange", 30); // Emplace: constructs element in-place

    // 3. Accessing elements
    std::cout << "Value of key 'apple': " << myMap["apple"] << std::endl;

    // 4. Iterating through the map
    std::cout << "Contents of myMap:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // 5. Common operations
    auto it = myMap.find("banana"); // Find element by key
    if (it != myMap.end()) {
        std::cout << "Element with key 'banana' found. Value: " << it->second << std::endl;
    }

    myMap.erase("orange"); // Erase element by key

    std::cout << "Size of myMap after erasing 'orange': " << myMap.size() << std::endl;

    // 6. Clearing and checking size
    myMap.clear(); // Clear all elements
    std::cout << "Is myMap empty after clear? " << (myMap.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of anotherMap: " << anotherMap.size() << std::endl;

    return 0;
}
```

##### Unordered Multiset

An unordered multiset is an associative container that stores multiple elements with the same key in an unordered manner. It provides fast search, insertion, and deletion operations and is implemented using a hash table. Unordered multisets are part of the Standard Template Library (STL) and are defined in the `<unordered_set>` header.

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    // 1. Initialization
    std::unordered_multiset<int> multiSet; // Empty unordered_multiset
    std::unordered_multiset<int> anotherSet = {1, 2, 3, 4, 5}; // Multiset initialization with elements

    // 2. Adding elements
    multiSet.insert(10); // Inserting elements
    multiSet.insert(20);
    multiSet.insert(10); // Duplicates are allowed in unordered_multiset

    // 3. Accessing elements
    std::cout << "Contents of multiSet:" << std::endl;
    for (const auto& elem : multiSet) {
        std::cout << elem << std::endl;
    }

    // 4. Checking if an element exists
    int target = 20;
    if (multiSet.find(target) != multiSet.end()) {
        std::cout << target << " exists in the multiset." << std::endl;
    } else {
        std::cout << target << " does not exist in the multiset." << std::endl;
    }

    // 5. Removing elements
    multiSet.erase(20); // Removing element

    // 6. Clearing and checking size
    multiSet.clear(); // Clear all elements
    std::cout << "Is multiSet empty after clear? " << (multiSet.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of anotherSet: " << anotherSet.size() << std::endl;

    return 0;
}
```

##### Unordered Multimap

An unordered multimap is an associative container that stores multiple key-value pairs with the same key in an unordered manner. It provides fast search, insertion, and deletion operations and is implemented using a hash table. Unordered multimaps are part of the Standard Template Library (STL) and are defined in the `<unordered_map>` header.

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    // 1. Initialization
    std::unordered_multimap<char, int> myMultiMap; // Empty unordered_multimap
    std::unordered_multimap<char, int> anotherMultiMap = { {'a', 1}, {'b', 2}, {'c', 3} }; // Multimap initialization with elements

    // 2. Adding elements
    myMultiMap.insert(std::make_pair('a', 10)); // Inserting elements
    myMultiMap.insert(std::make_pair('b', 20));
    myMultiMap.insert(std::make_pair('a', 30)); // Duplicates are allowed in unordered_multimap

    // 3. Accessing elements
    std::cout << "Contents of myMultiMap:" << std::endl;
    for (const auto& pair : myMultiMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // 4. Checking if a key exists
    char target = 'b';
    auto range = myMultiMap.equal_range(target);
    if (range.first != myMultiMap.end()) {
        std::cout << "Key '" << target << "' exists in the multimap." << std::endl;
    } else {
        std::cout << "Key '" << target << "' does not exist in the multimap." << std::endl;
    }

    // 5. Removing elements
    myMultiMap.erase('b'); // Removing element by key

    // 6. Clearing and checking size
    myMultiMap.clear(); // Clear all elements
    std::cout << "Is myMultiMap empty after clear? " << (myMultiMap.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of anotherMultiMap: " << anotherMultiMap.size() << std::endl;

    return 0;
}
```

#### Container Adapters

Container adapters in C++ are data structures that provide a specific interface for accessing elements. They are implemented using other containers and provide a simplified way to work with data.

##### Stack

A stack is a container that provides LIFO (Last In, First Out) access to elements. It supports two main operations: push (insert element at the top) and pop (remove element from the top). Stacks are part of the Standard Template Library (STL) and are defined in the `<stack>` header.

```cpp
#include <iostream>
#include <stack>

int main() {
    // 1. Initialization
    std::stack<int> myStack;

    // 2. Pushing elements
    myStack.push(10); // Pushing elements onto the stack
    myStack.push(20);
    myStack.push(30);

    // 3. Accessing elements
    std::cout << "Top element of the stack: " << myStack.top() << std::endl;

    // 4. Popping elements
    myStack.pop(); // Popping the top element

    // 5. Checking if the stack is empty
    std::cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    // 6. Getting the size of the stack
    std::cout << "Size of the stack: " << myStack.size() << std::endl;

    return 0;
}
```

##### Queue

A queue is a container that provides FIFO (First In, First Out) access to elements. It supports two main operations: push (insert element at the back) and pop (remove element from the front). Queues are part of the Standard Template Library (STL) and are defined in the `<queue>` header.

```cpp
#include <iostream>
#include <queue>

int main() {
    // 1. Initialization
    std::queue<int> myQueue;

    // 2. Pushing elements
    myQueue.push(10); // Pushing elements into the queue
    myQueue.push(20);
    myQueue.push(30);

    // 3. Accessing elements
    std::cout << "Front element of the queue: " << myQueue.front() << std::endl;
    std::cout << "Back element of the queue: " << myQueue.back() << std::endl;

    // 4. Popping elements
    myQueue.pop(); // Popping the front element

    // 5. Checking if the queue is empty
    std::cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    // 6. Getting the size of the queue
    std::cout << "Size of the queue: " << myQueue.size() << std::endl;

    return 0;
}
```

##### Priority Queue

A priority queue is a container that provides access to elements based on their priority. It supports two main operations: push (insert element) and pop (remove element with the highest priority). Priority queues are part of the Standard Template Library (STL) and are defined in the `<queue>` header.

```cpp
#include <iostream>
#include <queue>

int main() {
    // 1. Initialization
    std::priority_queue<int> myPriorityQueue;

    // 2. Pushing elements
    myPriorityQueue.push(30); // Pushing elements into the priority queue
    myPriorityQueue.push(10);
    myPriorityQueue.push(20);

    // 3. Accessing elements
    std::cout << "Top element of the priority queue: " << myPriorityQueue.top() << std::endl;

    // 4. Popping elements
    myPriorityQueue.pop(); // Popping the top element

    // 5. Checking if the priority queue is empty
    std::cout << "Is the priority queue empty? " << (myPriorityQueue.empty() ? "Yes" : "No") << std::endl;

    // 6. Getting the size of the priority queue
    std::cout << "Size of the priority queue: " << myPriorityQueue.size() << std::endl;

    return 0;
}
```

### Iterators

Iterators are objects in the C++ Standard Library (STL) that help us traverse containers like arrays, lists, and vectors. Essentially, they act as a bridge between container classes and algorithms.Iterators behave similar to pointers but provide a more generalized and abstract way of accessing elements in a container.

There are five types of iterators in C++:

#### Input Iterators

Input iterators provide read-only access to elements in a single pass. They can be used to read elements from a container but cannot be used to modify the elements.

```cpp
std::istream_iterator<int> input(std::cin);
std::istream_iterator<int> eof;
while (input != eof) {
    std::cout << *input << std::endl;
    ++input;
}
```

#### Output Iterators

Output iterators provide write-only access to elements in a single pass. They can be used to write elements to a container but cannot be used to read the elements.

```cpp
std::ostream_iterator<int> output(std::cout, " ");
for (int i = 0; i < 5; ++i) {
    *output = i;
    ++output;
}
```

#### Forward Iterators

Forward iterators provide read and write access to elements in a single pass. They can be used to read and modify elements in a container in a forward direction.

```cpp
std::forward_list<int> flist = {1, 2, 3, 4, 5};
for (auto it = flist.begin(); it != flist.end(); ++it) {
    std::cout << *it << " ";
}
```

#### Bidirectional Iterators

Bidirectional iterators provide read and write access to elements in both forward and backward directions. They can be used to traverse elements in a container in both directions.

```cpp
std::list<int> list = {1, 2, 3, 4, 5};
for (auto it = list.rbegin(); it != list.rend(); ++it) {
    std::cout << *it << " ";
}
```

#### Random Access Iterators

Random access iterators provide read and write access to elements with random access. They can be used to access elements at any position in a container with constant time complexity.

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}
```

### Algorithms

Algorithms in C++ are reusable functions that operate on containers like arrays, lists, and vectors. They provide a way to perform common operations such as searching, sorting, and modifying elements in a container. Algorithms are part of the Standard Template Library (STL) and are defined in the `<algorithm>` header.

#### Non-modifying Algorithms

Non-modifying algorithms do not change the elements in the container. They are used to search, count, compare, and perform other operations without modifying the elements.

- `std::find`, `std::count`, `std::all_of`, `std::any_of`, `std::none_of`, `std::equal`, `std::mismatch`, `std::search`, `std::find_end`, `std::find_first_of`, `std::adjacent_find`, `std::count_if`, `std::find_if`, `std::find_if_not`, `std::search_n`, `std::for_each`, `std::none_of`, `std::is_permutation`, `std::lexicographical_compare`, `std::equal_range`, `std::lower_bound`, `std::upper_bound`, `std::binary_search`, `std::includes`, `std::set_difference`, `std::set_intersection`, `std::set_symmetric_difference`, `std::set_union`, `std::merge`, `std::min_element`, `std::max_element`, `std::minmax_element`, `std::is_sorted`, `std::is_sorted_until`, `std::is_partitioned`, `std::partition_point`, `std::adjacent_difference`, `std::inner_product`, `std::partial_sum`, `std::reduce`, `std::transform_reduce`, `std::exclusive_scan`, `std::inclusive_scan`, `std::transform_exclusive_scan`, `std::transform_inclusive_scan`, `std::sample`, `std::random_shuffle`, `std::shuffle`, `std::is_heap`, `std::is_heap_until`, `std::make_heap`, `std::push_heap`, `std::pop_heap`, `std::sort_heap`, `std::nth_element`, `std::partition`, `std::stable_partition`, `std::sort`, `std::stable_sort`, `std::partial_sort`, `std::partial_sort_copy`, `std::is_permutation`, `std::next_permutation`, `std::prev_permutation`, `std::rotate`, `std::rotate_copy`, `std::reverse`, `std::reverse_copy`, `std::copy`, `std::copy_if`, `std::copy_n`, `std::copy_backward`, `std::move`, `std::move_backward`, `std::fill`, `std::fill_n`, `std::generate`, `std::generate_n`, `std::replace`, `std::replace`, `std::replace_copy`, `std::replace_copy_if`, `std::replace_if`, `std::swap`, `std::swap_ranges`, `std::iter_swap`, `std::transform`, `std::unique`, `std::unique_copy`, `std::unique_copy`, `std::unique_copy_if`

##### Modifying Algorithms

Modifying algorithms change the elements in the container. They are used to sort, copy, replace, and perform other operations that modify the elements.

- `std::copy`, `std::copy_backward`, `std::move`, `std::move_backward`, `std::fill`, `std::fill_n`, `std::generate`, `std::generate_n`, `std::replace`, `std::replace_copy`, `std::replace_copy_if`, `std::replace_if`, `std::swap`, `std::swap_ranges`, `std::iter_swap`, `std::transform`, `std::unique`, `std::unique_copy`, `std::unique_copy`, `std::unique_copy_if`

##### Sorting Algorithms

Sorting algorithms are used to sort the elements in the container in a specific order. They are used to arrange the elements in ascending or descending order based on a comparison function.

- `std::is_sorted`, `std::is_sorted_until`, `std::is_partitioned`, `std::partition_point`, `std::adjacent_difference`, `std::inner_product`, `std::partial_sum`, `std::reduce`, `std::transform_reduce`, `std::exclusive_scan`, `std::inclusive_scan`, `std::transform_exclusive_scan`, `std::transform_inclusive_scan`, `std::sample`, `std::random_shuffle`, `std::shuffle`, `std::is_heap`, `std::is_heap_until`, `std::make_heap`, `std::push_heap`, `std::pop_heap`, `std::sort_heap`, `std::nth_element`, `std::partition`, `std::stable_partition`, `std::sort`, `std::stable_sort`, `std::partial_sort`, `std::partial_sort_copy`

##### Numeric Algorithms

Numeric algorithms are used to perform numeric operations on elements in the container. They are used to calculate the sum, product, difference, and other operations on numeric values.

- `std::adjacent_difference`, `std::inner_product`, `std::partial_sum`, `std::reduce`, `std::transform_reduce`, `std::exclusive_scan`, `std::inclusive_scan`, `std::transform_exclusive_scan`, `std::transform_inclusive_scan`

##### Heap Algorithms

Heap algorithms are used to perform heap operations on elements in the container. They are used to create, maintain, and manipulate heap data structures.

- `std::is_heap`, `std::is_heap_until`, `std::make_heap`, `std::push_heap`,
`std::pop_heap`, `std::sort_heap`

**Example:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like sort, find, etc.

int main() {
    // 1. Sorting
    std::vector<int> vec = {5, 3, 8, 6, 2};
    std::sort(vec.begin(), vec.end());
    std::cout << "Sorted vector: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 2. Reversing
    std::reverse(vec.begin(), vec.end());
    std::cout << "Reversed vector: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 3. Finding an element
    auto it = std::find(vec.begin(), vec.end(), 8);
    if (it != vec.end()) {
        std::cout << "Element 8 found at position: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Element 8 not found" << std::endl;
    }

    // 4. Counting occurrences
    int count = std::count(vec.begin(), vec.end(), 6);
    std::cout << "Element 6 appears " << count << " times" << std::endl;

    // 5. Removing elements
    vec.erase(std::remove(vec.begin(), vec.end(), 6), vec.end());
    std::cout << "Vector after removing 6: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 6. Replacing elements
    std::replace(vec.begin(), vec.end(), 8, 10);
    std::cout << "Vector after replacing 8 with 10: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 7. Accumulating values
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of elements in the vector: " << sum << std::endl;

    // 8. Unique elements
    vec = {1, 2, 2, 3, 3, 4, 4, 5};
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
    std::cout << "Vector after removing duplicates: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Math

Mathematical functions and constants in C++ are provided by the `<cmath>` header. It includes functions for common mathematical operations like trigonometry, logarithms, exponentiation, and rounding.

#### Math Functions

- **Trigonometric Functions**: `sin()`, `cos()`, `tan()`
- **Exponential and Logarithmic Functions**: `exp()`, `log()`, `pow()`
- **Rounding Functions**: `ceil()`, `floor()`, `round()`

#### Random Numbers

Random number generation in C++ is used to generate random numbers for various applications, such as simulations, games, and statistical analysis. The `<random>` header in C++ provides classes and functions for generating random numbers using different distributions and engines.

- **Random Number Engine**: A random number engine is a source of randomness that generates random numbers.
- **Random Number Distribution**: A random number distribution is a function that maps random numbers from an engine to a specific range or distribution.
- **Random Number Seed**: A seed is an initial value used to initialize the random number engine.
- **Random Number Generation**: The process of generating random numbers using an engine and a distribution.

```cpp
#include <iostream>
#include <random> // For random number generation

int main() {
    // 1. Random number engine
    std::random_device rd; // Random device for seeding
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // 2. Random number distribution
    std::uniform_int_distribution<int> dist(1, 6); // Uniform distribution for dice roll

    // 3. Generating random numbers
    for (int i = 0; i < 5; ++i) {
        int diceRoll = dist(gen); // Generate random number
        std::cout << "Dice roll: " << diceRoll << std::endl;
    }

    return 0;
}
```

### Time and Date

Time and date in C++ are managed using the `<chrono>` and `<ctime>` headers. The `<chrono>` header provides a high-precision clock and time duration, while the `<ctime>` header provides functions for working with time and date.

- **Clocks**: Represent time points and durations.
- **Time Points**: Specific points in time.
- **Time Durations**: Differences between time points.
- **Time Units**: Units of time, such as seconds, minutes, and hours.
- **Time Zones**: Regions with the same standard time.

```cpp
#include <iostream>
#include <chrono> // For time and date
#include <ctime> // For C-style time functions

int main() {
    // 1. Clocks and time points
    auto now = std::chrono::system_clock::now(); // Current time point
    auto epoch = std::chrono::system_clock::time_point(); // Epoch time point

    // 2. Time duration
    auto duration = now - epoch; // Time duration between now and epoch
    std::cout << "Duration since epoch: " << duration.count() << " ticks" << std::endl;

    // 3. Time units
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    std::cout << "Duration in seconds: " << seconds.count() << " seconds" << std::endl;

    // 4. Time zones
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current time: " << std::ctime(&currentTime);

    return 0;
}
```

### Error Handling

Error handling in C++ is performed using exceptions, which are used to handle runtime errors and exceptional conditions. The `<exception>` header provides classes and functions for working with exceptions.

#### Exceptions

Exceptions in C++ are used to handle runtime errors and exceptional conditions that occur during program execution. They allow you to separate error handling code from normal program flow and provide a mechanism for propagating errors up the call stack.

- **Throwing Exceptions**: `throw exception;`
- **Catching Exceptions**: `try { /* code */ } catch (ExceptionType e) { /* handler */ }`
- **Rethrowing Exceptions**: `throw;`

```cpp
#include <iostream>

int divide(int a, int b) {
    if (b == 0) {
        throw "Division by zero!";
    }
    return a / b;
}

int main() {
    int num1, num2;

    std::cout << "Enter two numbers for division: ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "The result is: " << result << std::endl;
    } catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}
```

#### Standard Exceptions

C++ provides a set of standard exceptions that can be used to handle common error conditions. These exceptions are defined in the `<stdexcept>` header.

- **std::exception**: Base class for all standard exceptions.
- **std::runtime_error**: Exception for runtime errors.
- **std::logic_error**: Exception for logical errors.
- **std::invalid_argument**: Exception for invalid arguments.
- **std::out_of_range**: Exception for out-of-range errors.

```cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    int num1, num2;

    std::cout << "Enter two numbers for division: ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "The result is: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

#### Custom Exceptions

You can define custom exception classes by deriving from `std::exception` or other standard exception classes.

```cpp
#include <iostream>

class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom exception occurred!";
    }
};

int divide(int a, int b) {
    if (b == 0) {
        throw CustomException();
    }
    return a / b;
}

int main() {
    int num1, num2;

    std::cout << "Enter two numbers for division: ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "The result is: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

#### Access Violations

Access violations, such as null pointer dereferences and out-of-bounds memory access, can lead to runtime errors and crashes. You can use exception handling to catch and handle access violations in C++.

- **Null Pointer Dereference**: Accessing a null pointer.
- **Out-of-Bounds Access**: Accessing memory outside the bounds of an array.
- **Reading/Writing to freed memory**: Accessing memory that has been deallocated.

```cpp
#include <iostream>

int main() {
    int* ptr = nullptr;

    try {
        *ptr = 42;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

### Utility Components

Utility components in C++ are header files that provide additional functionality for programming tasks. They include functions, classes, and templates that help in common programming tasks like pair creation, tuple manipulation, function objects, and memory management.

#### Pair and Tuple

Pairs and tuples in C++ are used to store multiple values together. They are commonly used to return multiple values from a function or store key-value pairs.

The `<utility>` header in C++ provides utility functions that are commonly used in programming. These functions include `std::pair`, `std::make_pair`, `std::swap`, and `std::move`.

- **Pair**: A pair is a simple data structure that holds two values together. It is commonly used to return multiple values from a function or store key-value pairs.
- **Make Pair**: A utility function that creates a pair from two values.
- **Swap**: A utility function that swaps the values of two variables.
- **Move**: A utility function that converts an lvalue to an rvalue reference.

```cpp
#include <iostream>
#include <utility> // For std::pair, std::make_pair, std::swap, std::move

int main() {
    // 1. Pair
    std::pair<int, std::string> myPair = std::make_pair(42, "Hello");
    std::cout << "Pair: (" << myPair.first << ", " << myPair.second << ")" << std::endl;

    // 2. Swap
    int a = 5, b = 10;
    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;
    std::swap(a, b);
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    // 3. Move
    std::string str = "Hello, world!";
    std::string str2 = std::move(str);
    std::cout << "After move: str = \"" << str << "\", str2 = \"" << str2 << "\"" << std::endl;

    return 0;
}
```

Tuples in C++ are used to store multiple values of different types in a single object. They are similar to pairs but can hold more than two values. Tuples are defined in the `<tuple>` header and provide functions for creating, accessing, and manipulating tuple elements.

- **Tuple**: A tuple is a data structure that holds multiple values of different types.
- **Make Tuple**: A utility function that creates a tuple from multiple values.
- **Get**: A utility function that retrieves the value at a specific index in the tuple.

```cpp
#include <iostream>
#include <tuple>

int main() {
    // 1. Creating a tuple
    std::tuple<int, double, std::string> myTuple(42, 3.14, "Hello");

    // 2. Accessing elements
    std::cout << "First element of the tuple: " << std::get<0>(myTuple) << std::endl;
    std::cout << "Second element of the tuple: " << std::get<1>(myTuple) << std::endl;
    std::cout << "Third element of the tuple: " << std::get<2>(myTuple) << std::endl;

    // 3. Modifying elements (Not directly possible as tuples are immutable)

    // 4. Tuple tie
    int a;
    double b;
    std::tie(a, b, std::ignore) = myTuple; // Use std::ignore to ignore a value
    std::cout << "a: " << a << ", b: " << b << std::endl;

    // 5. Tuple comparison
    std::tuple<int, double> tuple1(1, 3.14);
    std::tuple<int, double> tuple2(1, 3.14);
    std::tuple<int, double> tuple3(2, 3.14);

    if (tuple1 == tuple2) {
        std::cout << "tuple1 is equal to tuple2" << std::endl;
    } else {
        std::cout << "tuple1 is not equal to tuple2" << std::endl;
    }

    if (tuple1 == tuple3) {
        std::cout << "tuple1 is equal to tuple3" << std::endl;
    } else {
        std::cout << "tuple1 is not equal to tuple3" << std::endl;
    }

    return 0;
}
```

### Regular Expressions

Regular expressions (regex) in C++ provide a powerful way to search, match, and manipulate text using patterns. The `<regex>` header in C++ provides classes and functions for working with regular expressions.

- **Regex Pattern**: A sequence of characters that defines a search pattern.
- **Regex Match**: A successful match between a regex pattern and a text string.
- **Regex Search**: Searching for a regex pattern in a text string.
- **Regex Replace**: Replacing text based on a regex pattern.

## Structuring Codebase

Structuring the codebase in C++ involves organizing code into modules, files, and directories to improve readability, maintainability, and reusability. It includes using header files, namespaces, classes, and libraries effectively.

### Header Files

Separating declarations and definitions in C++ is a common practice to improve code organization and modularity. Header files contain declarations of classes, functions, and variables, while source files contain their definitions.

- **Declaration and Definition Separation**: Header files contain declarations, while source files contain definitions.
- **Include Guards**: Prevent multiple inclusions of the same header file.
- **Forward Declarations**: Declare classes and functions before using them.

```cpp
// header.h
#ifndef HEADER_H
#define HEADER_H

void foo(); // Function declaration

#endif
```

### Namespaces

Namespaces in C++ are used to group related code into a named scope. They help avoid naming conflicts and improve code organization by providing a hierarchical structure.

- **Namespace Declaration**: `namespace name { /* code */ }`
- **Namespace Usage**: `using namespace name;` or `name::identifier`

```cpp
namespace math {
    int add(int a, int b) { return a + b; }
}

int main() {
    int sum = math::add(5, 3);
    return 0;
}
```

`using namespace math;` allows using the `add` function without the `math::` prefix.

```cpp
using namespace math;
int sum = add(5, 3);
```

### Scope

Scope in C++ defines the visibility and lifetime of variables and functions in a program. It determines where a variable or function can be accessed and how long it exists during program execution.

- **Global Scope**: Variables declared outside functions have global scope.
- **Local Scope**: Variables declared inside functions have local scope.
- **Block Scope**: Variables declared inside blocks have block scope.
- **Namespace Scope**: Variables declared inside namespaces have namespace scope.
- **Class Scope**: Variables declared inside classes have class scope.

```cpp
int globalVar = 42; // Global scope

void foo() {
    int localVar = 42; // Local scope
    {
        int blockVar = 42; // Block scope
    }
}

namespace math {
    int pi = 3.14159; // Namespace scope
}

class Circle {
public:
    double radius; // Class scope
};
```

### Preprocessor Directives

Preprocessor directives in C++ are used to modify the source code before compilation. They are used to include header files, define constants, conditionally compile code, and perform other preprocessing tasks.

- **Include Directive**: `#include <header>` or `#include "header"`
- **Define Directive**: `#define NAME value`

### Forward Declarations

Forward declarations in C++ are used to declare classes, functions, and variables before they are defined. They allow using entities before their definitions are available.

- **Class Forward Declaration**: `class ClassName;`
- **Function Forward Declaration**: `returnType functionName(parameters);`

```cpp
class Circle; // Forward declaration of class Circle

void foo(); // Forward declaration of function foo

class Circle {
public:
    double radius;
    double area();
};

double Circle::area() {
    return 3.14159 * radius * radius;
}
```

## Dependency Management

Dependency management in C++ involves handling external libraries, packages, and dependencies required by a project. It includes downloading, installing, and linking libraries to build and run C++ programs.

- **Package Managers**: Tools that automate the process of downloading, installing, and managing dependencies.
- **Build Systems**: Tools that handle dependencies, build configurations, and target platforms.
- **Library Directories**: Locations where library files are stored.
- **Include Directories**: Locations where header files are stored.

### Package Managers

Package managers in C++ are tools that automate the process of downloading, installing, and managing dependencies for a project. They simplify the management of libraries, packages, and external resources required by a program.

- **vcpkg**: A cross-platform package manager for C++ libraries.
- **Conan**: A decentralized package manager for C and C++ libraries.
- **Hunter**: A CMake-driven package manager for C++ libraries.
- **Biicode**: A C++ dependency manager that integrates with CMake.

### Build Systems

Build systems are tools that automate the process of compiling, linking, and packaging software projects. They manage dependencies, build configurations, and target platforms to generate executable files from source code.

#### Build Tools

- **Make**: A build automation tool that uses Makefiles to specify build rules.
- **CMake**: A cross-platform build system generator that simplifies the process of building C++ projects.
- **Ninja**: A fast and lightweight build tool that can be used with CMake.
- **Bazel**: A build system from Google that supports large-scale projects and multiple languages.

#### GNU Make

A Makefile is a file that specifies build rules and dependencies for a project. It contains targets, dependencies, variables, and phony targets that define how to build specific files or executables.

- **Makefile**: A file that specifies build rules and dependencies for a project.
- **Targets**: Rules that define how to build specific files or executables.
- **Dependencies**: Files or targets that must be built before a target can be built.
- **Variables**: Values that can be used to customize the build process.
- **Phony Targets**: Targets that do not correspond to actual files but perform specific actions.

```makefile
# Variables
CXX = g++
CXXFLAGS = -Wall -Iinclude
SRC = src/main.cpp
OBJ = main.o
EXE = my_program

# Rules
$(EXE): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $(EXE) $(OBJ)

$(OBJ): $(SRC)
    $(CXX) $(CXXFLAGS) -c $(SRC)

# Phony targets
.PHONY: clean
clean:
    rm -f $(OBJ) $(EXE)
```

#### CMake

CMake is a cross-platform build system generator that uses CMakeLists.txt files to define build configurations and dependencies. It generates build files for various platforms and build tools, such as Makefiles, Visual Studio projects, and Xcode projects.

- **CMakeLists.txt**: A file that specifies build configurations and dependencies for a CMake project.
- **Targets**: Executables, libraries, and custom targets defined in CMakeLists.txt.
- **Variables**: CMake variables that control build settings and options.
- **Commands**: CMake commands that define build rules and actions.

```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(my_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_program src/main.cpp)
```

## Working with Libraries

Libraries in C++ are collections of precompiled functions, classes, and resources that can be used to extend the functionality of a program. They provide reusable code, encapsulation, and abstraction to simplify development and improve code quality.

### Static Libraries

Static libraries in C++ are collections of object files that are linked directly into an executable at compile time. They provide a way to package and distribute code as a single file that can be included in a project.

- **File Extension**: `.a` (Unix), `.lib` (Windows)
- **Compilation**: Compiled and linked at compile time.
- **Usage**: Linked directly into the executable.
- **Advantages**: Faster startup time, easier distribution.
- **Disadvantages**: Larger executable size, slower build times.

#### Creating a Static Library

```bash
# Create object files
g++ -c library.cpp -o library.o

# Create static library
ar rcs liblibrary.a library.o
```

##### Using a Static Library

```bash
# Compile with static library
g++ main.cpp -o main -L. -llibrary
```

### Dynamic Libraries

Dynamic libraries in C++ are collections of object files that are linked at runtime when an executable is loaded. They provide a way to share code among multiple executables and reduce memory usage by loading libraries only when needed.

- **File Extension**: `.so` (Unix), `.dll` (Windows)
- **Compilation**: Compiled at compile time, linked at runtime.
- **Usage**: Linked dynamically at runtime.

### Creating a Dynamic Library

```bash
# Create object files
g++ -c -fPIC library.cpp -o library.o

# Create dynamic library
g++ -shared -o liblibrary.so library.o
```

#### Using a Dynamic Library

```bash
# Compile with dynamic library
g++ main.cpp -o main -L. -llibrary
```

### Linking Libraries

Linking libraries in C++ involves specifying the location of library files and including them in the build process. Libraries can be linked statically or dynamically, depending on the type of library and the desired behavior.

- **Static Linking**: Linking library code directly into the executable.
- **Dynamic Linking**: Linking library code at runtime when the executable is loaded.

#### Linking Static Libraries

```bash
# Compile with static library
g++ main.cpp -o main -L. -llibrary
```

#### Linking Dynamic Libraries

```bash
# Compile with dynamic library
g++ main.cpp -o main -L. -llibrary
```

### Using Libraries

Using libraries in C++ involves including header files, linking library files, and calling functions or classes defined in the library. Libraries provide a way to reuse code, encapsulate functionality, and extend the capabilities of a program.

- **Include Header Files**: `#include <library.h>`
- **Link Library Files**: `-L<path> -llibrary`
- **Call Library Functions**: `library_function()`

```cpp
#include <iostream>
#include "library.h"

int main() {
    library_function();
    return 0;
}
```

### Library Directories

Library directories in C++ are locations where library files are stored. They can be system directories, user directories, or custom directories specified by the user. Library directories are used by the compiler and linker to locate library files during the build process.

- **System Directories**: Standard locations where system libraries are stored.
- **User Directories**: Custom locations where user libraries are stored.
- **Include Directories**: Directories where header files are stored.
- **Library Directories**: Directories where library files are stored.

```bash
# Include directory
g++ -Iinclude main.cpp -o main

# Library directory
g++ -Llib main.cpp -o main -llibrary
```

## Compilers

A compiler is a software tool that translates source code written in a high-level programming language into machine code that can be executed by a computer. C++ compilers are used to compile C++ programs and generate executable files that can run on various platforms.


### Popular C++ Compilers

- **GCC (GNU Compiler Collection)**: A free and open-source compiler that supports multiple programming languages, including C++.
- **Clang**: A compiler front end for the C, C++, and Objective-C programming languages.
- **Microsoft Visual C++**: A compiler provided by Microsoft for Windows development.
- **Intel C++ Compiler**: A commercial compiler from Intel that supports C++ and other languages.

### Compilation Process

- **Preprocessing**: The preprocessor processes the source code and handles directives such as `#include` and `#define`.
- **Compilation**: The compiler translates the preprocessed code into object code (machine code).
- **Linking**: The linker combines the object code with libraries to create an executable file.
- **Loading**: The operating system loads the executable file into memory and starts execution.

### Compiler Flags

- **Optimization Flags**: `-O0`, `-O1`, `-O2`, `-O3`
- **Debugging Flags**: `-g`, `-ggdb`, `-g3`
- **Warning Flags**: `-Wall`, `-Wextra`, `-Werror`
- **Include Directories**: `-I<path>`
- **Library Directories**: `-L<path>`
- **Linker Flags**: `-l<library>`
- **Preprocessor Definitions**: `-D<name>=<value>`
- **Output File**: `-o <output>`
- **Compile Only**: `-c`

### Online Compilers

- **[Compiler Explorer](https://www.godbolt.org/)**: An online tool that allows you to explore the assembly output of C++ code.
- **[repl.it](https://replit.com/)**: An online platform that provides a C++ compiler and editor for writing and running code.
- **[cppinsights](https://www.cppinsights.io/)**: An online tool that shows the transformation of C++ code to assembly code.

## Debugging

Debugging is the process of identifying and fixing errors in a program. C++ provides various tools and techniques for debugging code, including print statements, breakpoints, and debugging tools.

### Debugging Techniques

- **Print Statements**: Use `std::cout` to print debug messages to the console.
- **Assertions**: Use `assert` to check conditions and halt the program if they are false.
- **Logging**: Use logging libraries to record debug information to a file.
- **Debugging Tools**: Use IDEs and debuggers to set breakpoints, inspect variables, and step through code.

### Debugging Tools

- **GDB (GNU Debugger)**: A command-line debugger that supports various features for debugging C++ programs.
- **LLDB**: A debugger provided by LLVM that supports debugging C++ code on macOS and Linux.
- **Visual Studio Debugger**: A graphical debugger provided by Microsoft for debugging C++ programs on Windows.
- **Valgrind**: A memory debugging tool that helps identify memory leaks and other memory-related errors.

### Debugging Tips

- **Start Small**: Debug small sections of code at a time to isolate errors.
- **Use Breakpoints**: Set breakpoints to pause execution and inspect variables.
- **Check Inputs**: Verify input data and function parameters for correctness.
- **Review Code**: Review code for logical errors and common mistakes.
- **Use Version Control**: Use version control systems to track changes and revert to previous versions.

## Standard Versions

C++ is an evolving language with new features and improvements introduced in each standard version. The C++ standard is maintained by the International Organization for Standardization (ISO) and is updated periodically to add new functionality, improve performance, and fix issues.

### C++ Standards

- **C++98**: The original C++ standard published in 1998.
- **C++03**: A minor revision of the C++98 standard published in 2003.
- **C++11**: The first major update to the C++ language published in 2011.
- **C++14**: A minor update to the C++11 standard published in 2014.
- **C++17**: The next major update to the C++ language published in 2017.
- **C++20**: The latest version of the C++ standard published in 2020.

### C++98 Features

- **Standard Template Library (STL)**: Containers, algorithms, iterators, and function objects.
- **Templates**: Generic programming constructs for creating reusable code.
- **Exceptions**: Mechanism for handling runtime errors and abnormal conditions.
- **Namespaces**: Logical grouping of code to prevent naming conflicts.
- **Standard Input/Output**: `std::cin`, `std::cout`, `std::cerr`, `std::clog`.
- **Dynamic Memory Allocation**: `new`, `delete`, `malloc`, `free`.
- **Function Overloading**: Defining multiple functions with the same name but different parameters.
- **Operator Overloading**: Defining custom behavior for operators.
- **Inheritance**: Mechanism for creating new classes based on existing classes.
- **Polymorphism**: Ability to process objects differently based on their data types.
- **Virtual Functions**: Functions that can be overridden in derived classes.
- **Friend Functions**: Functions that have access to private and protected members of a class.
- **References**: Alias to an existing variable.
- **Const Qualifier**: Indicates that an object is read-only.
- **Static Keyword**: Indicates that a variable or function is shared among all instances of a class.
- **Type Casting**: Converting one data type to another.
- **Preprocessor Directives**: `#include`, `#define`, `#ifdef`, `#endif`.

### C++11 Features

- **Auto**: Automatic type deduction using the `auto` keyword.
- **Range-based For Loop**: Simplified loop for iterating over elements.
- **Lambda Expressions**: Inline anonymous functions.
- **Smart Pointers**: `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`.
- **Move Semantics**: Efficient transfer of resources between objects.
- **Rvalue References**: References that can bind to temporary objects.
- **constexpr**: Compile-time evaluation of expressions.
- **nullptr**: Null pointer constant.
- **Variadic Templates**: Templates that accept a variable number of arguments.
- **Static Assertions**: Compile-time assertions using `static_assert`.
- **Threading Support**: `std::thread`, `std::mutex`, `std::condition_variable`.

### C++14 Features

- **Generic Lambdas**: Lambda functions with auto-typed parameters.
- **Binary Literals**: Binary integer literals.
- **decltype(auto)**: Automatic type deduction using decltype.
- **Variable Templates**: Templates that define variables.
- **Relaxed `constexpr`**: More flexibility in using `constexpr`.
- **`std::make_unique`**: Helper function for creating `std::unique_ptr`.
- **`std::integer_sequence`**: Utility for manipulating sequences of integers.
- **`std::quoted`**: I/O manipulator for quoted strings.
- **`std::exchange`**: Atomic exchange operation.
- **`std::shared_timed_mutex`**: Shared mutex with timed lock operations.

### C++17 Features

- **`if` with Initialization**: Initialization in `if` statements.
- **`constexpr` Lambda Expressions**: `constexpr` lambdas.
- **`std::optional`**: Nullable object wrapper.
- **`std::variant`**: Type-safe union.
- **`std::any`**: Type-safe container for single values of any type.
- **`std::string_view`**: Non-owning view of a string.
- **`std::filesystem`**: Filesystem library.
- **`std::invoke`**: Invoke callable objects.
- **`std::apply`**: Invoke a function with a tuple of arguments.

### C++20 Features

- **Concepts**: Constraints on template parameters.
- **Ranges**: Range-based algorithms and views.
- **Coroutines**: Lightweight concurrency.
- **Modules**: Modular programming.
- **`std::format`**: String formatting.
- **`std::span`**: Non-owning view of a contiguous sequence.
- **`std::jthread`**: Joinable thread.
- **`std::stop_token`**: Token for stopping asynchronous operations.
- **`std::chrono` Improvements**: Additional features for the chrono library.

## languge Concepts

### auto (Automatic Type Deduction)

The `auto` keyword in C++ is used for automatic type deduction. It allows the compiler to determine the type of a variable based on its initializer. This feature was introduced in C++11 to simplify code and improve readability.

#### Syntax

```cpp
auto variable = value;
```

#### Example

```cpp

#include <iostream>

int main() {
    auto x = 42; // x is of type int
    auto y = 3.14; // y is of type double
    auto z = "Hello"; // z is of type const char*
    std::cout << x << " " << y << " " << z << std::endl;
    return 0;
}
```

### Range-based For Loop

The range-based for loop in C++ is a convenient way to iterate over elements in a container, such as an array, vector, or string. It simplifies the process of iterating over elements and accessing them without using iterators or indices.

- **Syntax**

    ```cpp
    for (auto& element : container) {
        // Process element
    }
    ```

- **Example**

    ```cpp
    #include <iostream>
    #include <vector>

    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        for (auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    ```

### Undefine Behaviour

Undefined behavior in C++ refers to code constructs and operations that do not have well-defined semantics according to the C++ standard. It can lead to unpredictable program behavior, crashes, and security vulnerabilities. Avoiding undefined behavior is essential for writing safe and reliable code.

#### Examples of Undefined Behavior

- **Null Pointer Dereference**: Accessing or dereferencing a null pointer.
- **Buffer Overflow**: Writing to or reading from memory outside the bounds of an array.
- **Uninitialized Variables**: Using variables before they are initialized.
- **Signed Integer Overflow**: Overflowing a signed integer value.
- **Division by Zero**: Dividing an integer by zero.

#### Handling Undefined Behavior

- **Avoid Undefined Behavior**: Write safe and well-defined code to prevent undefined behavior.
- **Use Static Analysis Tools**: Use tools that analyze code for potential undefined behavior.
- **Compiler Warnings**: Enable compiler warnings to catch potential issues at compile time.
- **Testing and Debugging**: Test code thoroughly and use debugging tools to identify issues.

### Argument Dependent Lookup (ADL)

Argument-dependent lookup (ADL) in C++ is a mechanism that allows functions and operators to be found by the compiler based on the types of arguments passed to them. It is also known as Koenig lookup after its creator Andrew Koenig.

#### Example of ADL

```cpp
#include <iostream>

namespace my_namespace {
    struct MyType {};
    void foo(MyType) {
        std::cout << "ADL: foo(MyType)" << std::endl;
    }
}

int main() {
    my_namespace::MyType obj;
    foo(obj); // ADL: foo(MyType)
    return 0;
}
```

## References

- [cppreference](www.cppreference.com)
- [learncpp](https://www.learncpp.com/)
- [cplusplus](http://www.cplusplus.com/)
- [cpp-cheat-sheet](https://github.com/gibsjose/cpp-cheat-sheet)
- [Modern-CPP-Programming](https://github.com/federico-busato/Modern-CPP-Programming)
