# Module 05: Exception Handling

This module focuses on exception handling in C++, teaching how to handle errors and exceptional situations in your code properly.

## Table of Contents

1. [Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!](#exercise-00-bureaucrat)
2. [Exercise 01: Form up, maggots!](#exercise-01-form)
3. [Exercise 02: No, you need form 28B, not 28C...](#exercise-02-specific-forms)
4. [Exercise 03: At least this beats coffee-making](#exercise-03-intern)

## Summary of Concepts

- **Exception Handling**: Using try-catch blocks to handle errors
- **Custom Exceptions**: Creating and using user-defined exception classes
- **Exception Hierarchies**: Organizing exceptions in an inheritance structure
- **Exception Safety**: Ensuring proper resource management during exceptions
- **Orthodox Canonical Form**: Implementing classes with proper constructors and operators

## Detailed Explanation of Topics

### Exception Handling Basics

Exception handling in C++ uses try-catch blocks to manage error conditions:

```cpp
try {
    // Code that might throw an exception
    if (something_wrong)
        throw std::exception();
}
catch (const std::exception& e) {
    // Handle the exception
    std::cout << e.what() << std::endl;
}
```

### Custom Exception Classes

Creating custom exception classes by inheriting from std::exception:

```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade is too high";
    }
};

class GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade is too low";
    }
};
```

### Exception Safety Guarantees

Different levels of exception safety:

1. **Basic Guarantee**: No resource leaks or corrupted data
2. **Strong Guarantee**: Operation either succeeds completely or has no effect
3. **No-throw Guarantee**: Operation never throws exceptions

Example:
```cpp
class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Strong guarantee - either succeeds or throws
    Bureaucrat(const std::string& name, int grade) : name(name) {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
        this->grade = grade;
    }
};

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;

public:
    // Basic guarantee - no resource leaks
    void beSigned(const Bureaucrat& bureaucrat) {
        if (bureaucrat.getGrade() > gradeToSign)
            throw GradeTooLowException();
        isSigned = true;
    }
};

class Intern {
public:
    // No-throw guarantee - never throws exceptions
    Form* makeForm(const std::string& formName, const std::string& target) {
        if (formName == "Robotomy Request")
            return new RobotomyRequestForm(target);
        if (formName == "Presidential Pardon")
            return new PresidentialPardonForm(target);
        if (formName == "Shrubbery Creation")
            return new ShrubberyCreationForm(target);
        return NULL;
    }
};
```

### Resource Management in Exceptions

Using RAII (Resource Acquisition Is Initialization) to manage resources:

```cpp
class Form {
private:
    bool* signed_;
    
public:
    Form() : signed_(new bool(false)) {}
    ~Form() { delete signed_; }
    
    Form(const Form& other) : signed_(new bool(*other.signed_)) {}
    
    Form& operator=(const Form& other) {
        if (this != &other) {
            bool* temp = new bool(*other.signed_);
            delete signed_;
            signed_ = temp;
        }
        return *this;
    }
};
```

### Exception Hierarchies

Creating a hierarchy of related exceptions:

```cpp
class FormException : public std::exception {
protected:
    std::string message;
public:
    FormException(const std::string& msg) : message(msg) {}
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

class GradeTooLowException : public FormException {
public:
    GradeTooLowException() 
        : FormException("Grade is too low for this operation") {}
};

class GradeTooHighException : public FormException {
public:
    GradeTooHighException()
        : FormException("Grade is too high for this operation") {}
};
```

## Exercise Details

### Exercise 00: Bureaucrat
- Implement a Bureaucrat class with grade limitations
- Create custom exceptions for grade validation
- Practice basic exception handling

Key Implementation:
```cpp
class Bureaucrat {
private:
    const std::string name;
    int grade;  // 1 to 150

public:
    Bureaucrat(const std::string& name, int grade);
    void incrementGrade();
    void decrementGrade();
    // ... other methods
};
```

### Exercise 01: Form
- Create a Form class with signing requirements
- Implement grade checks for signing and executing
- Practice exception handling with multiple conditions

Key Features:
```cpp
class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    void beSigned(const Bureaucrat& bureaucrat);
    // ... other methods
};
```

### Exercise 02: Specific Forms
- Implement different types of forms
- Create concrete form classes with specific actions
- Practice inheritance and polymorphism with exceptions

### Exercise 03: Intern
- Create an Intern class that creates forms
- Implement form creation based on form names
- Practice factory pattern and error handling

## Resources

- [C++ Exceptions](https://en.cppreference.com/w/cpp/language/exceptions)
- [RAII](https://en.cppreference.com/w/cpp/language/raii)
- [Exception Safety](https://en.wikipedia.org/wiki/Exception_safety)
- [Orthodox Canonical Form](https://en.cppreference.com/w/cpp/language/rule_of_three)
```