# Module 06: C++ Type Casting

## Table of Contents
1. [Type Casting in C++](#type-casting-in-cpp)
2. [Static Cast](#static-cast)
3. [Reinterpret Cast](#reinterpret-cast)
4. [Dynamic Cast](#dynamic-cast)
5. [Const Cast](#const-cast)
6. [Exercise Breakdown](#exercise-breakdown)

## Type Casting in C++

### Overview
C++ provides four different types of casting operators:
- static_cast
- reinterpret_cast
- dynamic_cast
- const_cast

Each has its specific use case and level of safety.

### Why Different Casts?
Unlike C-style casts, C++ casts are:
- More visible in code
- More specific in purpose
- Easier to search for
- Safer to use

## Static Cast

### Purpose
- Most common type conversion
- Performs compile-time type checking
- Used for converting between related types

### Usage
```cpp
double d = 3.14;
int i = static_cast<int>(d);    // Convert double to int
```

### Best For
1. Numeric conversions
2. Pointer conversions up inheritance hierarchies
3. void* to typed pointer conversions
4. Base to derived class pointers (when you're sure it's safe)

### Limitations
- No runtime type checking
- Can't remove const
- Can't handle unrelated types

## Reinterpret Cast

### Purpose
- Low-level reinterpreting of bit patterns
- Used for pointer/reference conversions between unrelated types

### Usage
```cpp
int* p = new int(42);
long addr = reinterpret_cast<long>(p);    // Convert pointer to integer
```

### Best For
1. Converting between pointer types
2. Converting pointer to integral type
3. Converting integral type to pointer

### Cautions
- Very dangerous if misused
- Implementation-dependent
- Should be used rarely

## Dynamic Cast

### Purpose
- Safe downcasting in inheritance hierarchies
- Runtime type checking
- Works with polymorphic classes

### Usage
```cpp
Base* base = new Derived();
Derived* derived = dynamic_cast<Derived*>(base);
```

### Key Features
1. Runtime Type Information (RTTI)
2. Returns nullptr for invalid pointer casts
3. Throws std::bad_cast for invalid reference casts

### Requirements
- Base class must be polymorphic (have virtual functions)
- RTTI must be enabled

## Const Cast

### Purpose
- Remove or add const qualifier
- Should be used very rarely
- Often indicates design problems

### Usage
```cpp
const int constant = 21;
const_cast<int&>(constant) = 42;    // Remove const (dangerous!)
```

### Warning
- Modifying a const object is undefined behavior
- Should only be used when dealing with poorly designed APIs

## Exercise Breakdown

### Exercise 00: Scalar Conversion
- Convert between scalar types
- Handle edge cases and special values
- Use appropriate type casting
```cpp
static void convert(const std::string& literal);
```

Key Concepts:
1. Type detection
2. Safe conversion
3. Special value handling
4. Output formatting

### Exercise 01: Serialization
- Convert pointer to integer and back
- Use reinterpret_cast for pointer conversions
```cpp
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
```

Key Concepts:
1. Pointer serialization
2. Data integrity
3. Memory safety
4. Type safety

### Exercise 02: Type Identification
- Identify real type of objects
- Use dynamic_cast for type checking
```cpp
Base* generate(void);
void identify(Base* p);
void identify(Base& p);
```

Key Concepts:
1. Polymorphic classes
2. Runtime type identification
3. Type safety with inheritance
4. Dynamic casting

## Best Practices

### When to Use Each Cast
1. static_cast:
   - General-purpose conversions
   - Numeric type conversions
   - When type safety is known at compile time

2. reinterpret_cast:
   - Low-level bit manipulation
   - System-level programming
   - When you need to break type safety

3. dynamic_cast:
   - Safe downcasting
   - When you need runtime type checking
   - Working with polymorphic types

4. const_cast:
   - Last resort
   - When working with legacy APIs
   - When const-correctness is broken


## Resources

- [Type Casting and Type Conversion in Cpp](https://www.naukri.com/code360/library/type-casting-and-type-conversion-in-cpp)