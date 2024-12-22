# Exercise 00: Exception Handling in C++

## Core Concepts

### 1. Exception Handling
Exception handling is a programming language construct that helps manage runtime errors by:
- Separating error handling code from normal code
- Allowing errors to be propagated up the call stack
- Providing a structured way to detect and handle runtime errors

### 2. Try-Catch Blocks
```cpp
try {
    // Code that might throw an exception
} catch (const std::exception& e) {
    // Code to handle the exception
}
```
- `try`: Contains code that might throw an exception
- `catch`: Handles specific types of exceptions
- Multiple catch blocks can handle different exception types

### 3. Exception Class Hierarchy
- `std::exception`: Base class for all standard exceptions
- Custom exceptions should inherit from std::exception
- Virtual `what()` function provides error description

### 4. Custom Exception Classes
Custom exceptions allow for:
- Domain-specific error handling
- Meaningful error messages
- Type-based exception handling

Basic structure:
```cpp
class MyException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "My error message";
    }
};
```

### 5. Orthodox Canonical Form (OCF)
A class must provide four essential functions:
1. Default constructor
2. Copy constructor
3. Copy assignment operator
4. Destructor

Purpose:
- Ensures proper object creation, copying, and cleanup
- Prevents memory leaks
- Enables proper object management

### 6. Constant Member Functions
- Functions marked with `const` after parameter list
- Promise not to modify object's state
- Can be called on const objects
- Example: `int getValue() const;`

### 7. Constant Members
- Members declared with `const` cannot be modified
- Must be initialized in constructor initialization list
- Common for immutable properties of a class

### 8. Access Specifiers
Three levels of access:
- `public`: Accessible from anywhere
- `private`: Only accessible within the class
- `protected`: Accessible in class and derived classes

### 9. Stream Operator Overloading
- Allows custom output formatting for objects
- Usually implemented as a non-member function
- Takes stream and object as parameters
```cpp
std::ostream& operator<<(std::ostream& os, const Class& obj);
```