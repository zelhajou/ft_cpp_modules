# Module 07: C++ Templates

## Table of Contents
1. [Templates Overview](#templates-overview)
2. [Function Templates](#function-templates)
3. [Class Templates](#class-templates)
4. [Template Parameter Types](#template-parameter-types)
5. [Exercise Implementations](#exercise-implementations)

## Templates Overview

### What are Templates?
Templates are a feature in C++ that allows writing code that can work with any data type. They provide:
- Generic programming capabilities
- Type-safe code reuse
- Compile-time polymorphism

### Key Concepts
1. Template Parameters
2. Template Instantiation
3. Template Specialization
4. Template Resolution

## Function Templates

### Basic Syntax
```cpp
template<typename T>
T functionName(T parameter) {
    // Function body
}
```

### Important Features
1. Type Deduction
   - Compiler automatically determines type
   - Must be unambiguous

2. Explicit Specialization
   ```cpp
   template<>
   void function<int>(int x) {
       // Specialized implementation for int
   }
   ```

3. Function Overloading
   - Templates can be overloaded
   - Most specific version is chosen

### Best Practices
1. Keep templates in header files
2. Use meaningful parameter names
3. Document type requirements
4. Handle edge cases

## Class Templates

### Basic Syntax
```cpp
template<typename T>
class ClassName {
private:
    T member;
public:
    T getMember() const { return member; }
};
```

### Key Features
1. Member Functions
   - Can be defined inside or outside class
   - Must include template parameters

2. Static Members
   - Each instantiation has its own set
   - Must be declared and defined

3. Template Parameters
   - Can have default values
   - Can be types or non-types

### Memory Management
1. Construction
   ```cpp
   T* array = new T[size]();  // Default initialization
   ```

2. Destruction
   ```cpp
   delete[] array;  // Proper array cleanup
   ```

3. Copy Semantics
   - Deep copy required for pointers
   - Handle self-assignment

## Template Parameter Types

### Type Parameters
```cpp
template<typename T, typename U>
T convert(U value);
```

### Non-Type Parameters
```cpp
template<typename T, int Size>
class Array {
    T data[Size];
};
```

### Template Template Parameters
```cpp
template<template<typename> class Container>
class Wrapper;
```

## Exercise Implementations

### Exercise 00: Function Templates
Implementation of basic utility functions:
```cpp
template<typename T>
void swap(T& a, T& b);

template<typename T>
const T& min(const T& a, const T& b);

template<typename T>
const T& max(const T& a, const T& b);
```

Key Points:
- Work with any comparable type
- Return consistent values (second when equal)
- Maintain const correctness

### Exercise 01: Iter Function
A template function for array iteration:
```cpp
template<typename T>
void iter(T* array, size_t length, void (*func)(T&));
```

Features:
1. Generic Array Processing
   - Works with any array type
   - Supports any function type
   - Handles const correctly

2. Function Application
   - Applies function to each element
   - Maintains type safety
   - Supports function templates

### Exercise 02: Array Class
Template array class implementation:
```cpp
template<typename T>
class Array {
private:
    T* elements;
    unsigned int _size;
public:
    // ... member functions
};
```

## References

- [C++ Templates](https://en.cppreference.com/w/cpp/language/templates)
- [Template Specialization](https://www.geeksforgeeks.org/template-specialization-c/)
