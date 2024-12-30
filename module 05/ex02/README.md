# Exercise 02: Abstract Classes in C++

## Core Concepts

### 1. Abstract Classes
A class with at least one pure virtual function. Cannot be instantiated directly.
```cpp
class AForm {
    virtual void execute() = 0;  // Pure virtual function
};
```

### 2. Pure Virtual Functions 
- Declared using `= 0` syntax
- Must be implemented by derived classes
- Makes class abstract
- Defines interface for derived classes

### 3. Virtual Destructor
```cpp
virtual ~AForm();  // Required for proper cleanup of inheritance hierarchies
```

### 4. Class Hierarchy
```
AForm (Abstract Base)
   ├── ShrubberyCreationForm
   ├── RobotomyRequestForm
   └── PresidentialPardonForm
```

### 5. Implementation Requirements

Each concrete form has:
- Specific grade requirements
- Unique execution behavior 
- Name and target handling
- Input validation
- Exception handling

### 6. Key Differences from Base Form

1. ShrubberyCreationForm:
   - Creates ASCII tree file
   - Grades: Sign 145, Execute 137
   - File I/O operations

2. RobotomyRequestForm:
   - 50% success rate
   - Drilling noises
   - Grades: Sign 72, Execute 45

3. PresidentialPardonForm:
   - Simplest execution
   - Highest grade requirements
   - Grades: Sign 25, Execute 5


