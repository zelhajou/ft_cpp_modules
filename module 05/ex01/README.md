# Exercise 01: Forms and Advanced C++ Concepts

## Core Concepts

### 1. Forward Declarations and Header Dependencies
Forward declarations help manage circular dependencies between classes:
```cpp
// In Form.hpp
class Bureaucrat;  // Forward declaration

// In Bureaucrat.hpp
class Form;        // Forward declaration
```
- Allows header files to reference each other
- Reduces compilation dependencies
- Helps prevent circular inclusion issues

### 2. Circular Dependencies
When two classes need to know about each other:
```cpp
// Class A needs Class B
class A {
    B* b;  // Needs forward declaration of B
};

// Class B needs Class A
class B {
    A* a;  // Needs forward declaration of A
};
```
Solutions:
- Forward declarations
- Proper header organization
- Minimal includes in header files

### 3. Const Correctness
Using const correctly in class design:
```cpp
class Form {
private:
    const std::string   _name;          // Constant member
    const int          _gradeToSign;    // Constant member
public:
    std::string getName() const;        // Const member function
};
```
Benefits:
- Prevents accidental modifications
- Clarifies intent
- Enables optimization

### 4. Member Initialization Lists
Proper initialization of constant members:
```cpp
Form::Form(const std::string& name, int grade)
    : _name(name),         // Initialize const member
      _gradeToSign(grade)  // Initialize const member
{
    // Constructor body
}
```
Importance:
- Required for const members
- More efficient than assignment
- Guarantees initialization order

### 5. Access Control in Class Design
Three levels of access:
```cpp
class Form {
private:
    // Internal implementation details
    const std::string _name;

protected:
    // Available to derived classes
    bool _isSigned;

public:
    // Public interface
    void beSigned(const Bureaucrat& b);
};
```

### 6. Exception Safety
Different levels of guarantee:
1. Basic Guarantee:
   - No resource leaks
   - Program in valid state
   
2. Strong Guarantee:
   - Operation succeeds or no effect
   - No side effects if exception thrown

3. No-throw Guarantee:
   - Operation never fails
   - Used in destructors

### 7. Design Patterns
Common patterns used in this exercise:

1. **RAII (Resource Acquisition Is Initialization)**:
   - Resources managed through object lifetime
   - Automatic cleanup in destructors

2. **Delegation Pattern**:
   - Bureaucrat delegates form signing to Form class
   - Clear separation of responsibilities

### 8. Class Relationships
Different types of relationships:

1. **Association**:
   - Bureaucrat uses Form
   - Loose coupling between classes

2. **Dependency**:
   - Form depends on Bureaucrat for signing
   - One-way relationship

### 9. Immutable Objects
Implementing immutable attributes:
```cpp
class Form {
private:
    const std::string _name;          // Immutable
    const int _gradeToSign;          // Immutable
    bool _isSigned;                  // Mutable state
};
```
Benefits:
- Thread safety
- Predictable behavior
- Easier to reason about

### 10. Stream Output Formatting
Custom output formatting:
```cpp
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
       << "\nStatus: " << (form.getIsSigned() ? "Signed" : "Unsigned");
    return os;
}
```
Features:
- Chainable operations
- Consistent formatting
- Readable output

### 11. Code Organization Principles

1. **Separation of Concerns**:
   - Each class has distinct responsibility
   - Clear boundaries between functionality

2. **Single Responsibility Principle**:
   - Form handles form-related operations
   - Bureaucrat handles bureaucrat operations

3. **Interface Segregation**:
   - Minimal public interfaces
   - Only necessary operations exposed

### 12. Error Handling Strategies

1. **Exception Classes**:
```cpp
class GradeTooHighException : public std::exception {
    const char* what() const throw() {
        return "Grade too high";
    }
};
```

2. **Error Checking**:
```cpp
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}
```


