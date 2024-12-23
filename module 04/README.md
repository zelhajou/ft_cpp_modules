
# Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces

This module focuses on key object-oriented programming concepts in C++: polymorphism, abstract classes, and interfaces. These concepts are fundamental to creating flexible and maintainable code.

## Table of Contents

1. [Exercise 00: Polymorphism](#exercise-00-polymorphism)
2. [Exercise 01: I don't want to set the world on fire](#exercise-01-i-dont-want-to-set-the-world-on-fire)
3. [Exercise 02: Abstract class](#exercise-02-abstract-class)
4. [Exercise 03: Interface & recap](#exercise-03-interface--recap)

## Summary of Concepts

- **Polymorphism**: Runtime behavior selection through virtual functions
- **Abstract Classes**: Base classes with pure virtual functions
- **Interfaces**: Abstract classes with only pure virtual functions
- **Virtual Functions**: Functions that can be overridden by derived classes
- **Memory Management**: Proper handling of dynamic memory in class hierarchies
- **Deep Copy**: Creating independent copies of objects

## Detailed Explanation of Topics

### Polymorphism

Polymorphism allows objects of different classes to be treated as objects of a common base class, with the appropriate member functions being called based on the actual object type.

```cpp
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal sound" << std::endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->makeSound(); // Outputs: Woof!
    delete animal;
}
```

### Virtual Functions

Virtual functions enable runtime polymorphism by allowing derived classes to override base class functions. The `virtual` keyword indicates that a function can be overridden.

Key points:
- Virtual functions must be declared in the base class
- Derived classes use `override` keyword for clarity
- Virtual destructors are crucial for proper cleanup

```cpp
class Base {
public:
    virtual void function() = 0;  // Pure virtual function
    virtual ~Base() {}           // Virtual destructor
};

class Derived : public Base {
public:
    void function() override {
        // Implementation
    }
};
```

### Abstract Classes

Abstract classes are classes that have at least one pure virtual function. They cannot be instantiated and serve as interfaces that derived classes must implement.

```cpp
class AAnimal {
protected:
    std::string type;
public:
    virtual void makeSound() const = 0; // Pure virtual function
    virtual ~AAnimal() {}
    std::string getType() const { return type; }
};
```

### Memory Management in Class Hierarchies

Proper memory management is crucial when dealing with inheritance and polymorphism:

1. **Virtual Destructors**:
```cpp
class Base {
public:
    virtual ~Base() {} // Virtual destructor for proper cleanup
};
```

2. **Deep Copy**:
```cpp
class Dog : public Animal {
private:
    Brain* brain;
public:
    Dog(const Dog& other) : Animal(other) {
        brain = new Brain(*other.brain); // Deep copy
    }
    Dog& operator=(const Dog& other) {
        if (this != &other) {
            Animal::operator=(other);
            delete brain;
            brain = new Brain(*other.brain);
        }
        return *this;
    }
    ~Dog() {
        delete brain;
    }
};
```

### Brain Class Implementation

The Brain class demonstrates proper resource management and deep copying:

```cpp
class Brain {
private:
    std::string ideas[100];
public:
    Brain() {}
    Brain(const Brain& other) {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    Brain& operator=(const Brain& other) {
        if (this != &other) {
            for (int i = 0; i < 100; i++)
                ideas[i] = other.ideas[i];
        }
        return *this;
    }
};
```

## Exercise Details

### Exercise 00: Polymorphism
- Implement basic animal classes with polymorphic behavior
- Demonstrate the difference between virtual and non-virtual functions
- Show proper inheritance and method overriding

### Exercise 01: Memory Management
- Add a Brain class with dynamic memory allocation
- Implement deep copying for derived classes
- Handle memory management properly in constructors and destructors

### Exercise 02: Abstract Classes
- Convert Animal to an abstract class (AAnimal)
- Prevent instantiation of the base class
- Maintain functionality through derived classes

### Exercise 03: Interfaces
- Implement pure abstract classes as interfaces
- Create a material system with cloning capabilities
- Manage complex object relationships and memory

## Resources

- [Polymorphism in C++](https://www.cplusplus.com/doc/tutorial/polymorphism/)
- [Abstract Classes in C++](https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/)
- [Memory Management in C++](https://www.learncpp.com/cpp-tutorial/15-1-intro-to-smart-pointers-move-semantics/)
- [Deep Copy in C++](https://www.cplusplus.com/articles/y8hv0pDG/)
- [Virtual Destructors](https://www.geeksforgeeks.org/virtual-destructor/)
- [Interfaces in C++](https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm)
- [C++ Smart Pointers](https://www.learncpp.com/cpp-tutorial/15-1-intro-to-smart-pointers-move-semantics/)
