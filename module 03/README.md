# Module 03: Inheritance

This module focuses on inheritance in C++, a fundamental concept in object-oriented programming that allows classes to inherit properties and methods from other classes.

## Table of Contents

1. [Exercise 00: ClapTrap](#exercise-00-claptrap)
2. [Exercise 01: ScavTrap](#exercise-01-scavtrap)
3. [Exercise 02: FragTrap](#exercise-02-fragtrap)
4. [Exercise 03: DiamondTrap](#exercise-03-diamondtrap)

## Summary of Concepts

- **Inheritance**: Creating new classes based on existing ones
- **Base and Derived Classes**: Understanding parent-child class relationships
- **Access Specifiers**: Managing member visibility in inheritance
- **Virtual Functions**: Implementing polymorphic behavior
- **Constructor and Destructor Chaining**: Managing object lifecycle in inheritance
- **Diamond Problem**: Handling multiple inheritance issues
- **Protected Members**: Understanding intermediate access level
- **Function Overriding**: Customizing inherited behavior

## Detailed Explanation of Topics

### Inheritance Basics

Inheritance is a mechanism that allows a class (derived class) to inherit properties and methods from another class (base class). It promotes code reuse and establishes relationships between classes.

Example:
```cpp
class Base {
protected:
    int value;
public:
    Base(int v) : value(v) {}
    virtual void display() {
        std::cout << "Value: " << value << std::endl;
    }
};

class Derived : public Base {
public:
    Derived(int v) : Base(v) {}
    void display() override {
        std::cout << "Derived value: " << value << std::endl;
    }
};
```

### Access Specifiers in Inheritance

C++ provides three access specifiers for inheritance:

1. **public**: Base class's public and protected members remain public and protected in derived class
2. **protected**: Base class's public and protected members become protected in derived class
3. **private**: Base class's public and protected members become private in derived class

Example:
```cpp
class Base {
private:
    int private_value;
protected:
    int protected_value;
public:
    int public_value;
};

class Derived : public Base {
    // Can access protected_value and public_value
    // Cannot access private_value
};
```

### Constructor and Destructor Chaining

When creating derived class objects, constructors are called in this order:
1. Base class constructor
2. Derived class constructor

Destructors are called in reverse order:
1. Derived class destructor
2. Base class destructor

Example:
```cpp
class Base {
public:
    Base() { std::cout << "Base constructor\n"; }
    ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor\n"; }
    ~Derived() { std::cout << "Derived destructor\n"; }
};
```

### Function Overriding

Derived classes can override functions from the base class to provide specialized behavior.

Example:
```cpp
class ClapTrap {
public:
    virtual void attack(const std::string& target) {
        std::cout << "ClapTrap attacks " << target << std::endl;
    }
};

class ScavTrap : public ClapTrap {
public:
    void attack(const std::string& target) override {
        std::cout << "ScavTrap fiercely attacks " << target << std::endl;
    }
};
```

### Protected Members

Protected members are accessible by:
- The class that defines them
- Classes that inherit from that class
- Friends of the class

Example:
```cpp
class ClapTrap {
protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
public:
    ClapTrap(std::string n) : name(n) {}
};

class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string n) : ClapTrap(n) {
        // Can access protected members
        hitPoints = 100;
        energyPoints = 50;
        attackDamage = 20;
    }
};
```

### Virtual Functions and Polymorphism

Virtual functions enable runtime polymorphism, allowing derived class implementations to be called through base class pointers.

Example:
```cpp
class ClapTrap {
public:
    virtual void makeSound() {
        std::cout << "ClapTrap sound" << std::endl;
    }
    virtual ~ClapTrap() {} // Virtual destructor
};

class ScavTrap : public ClapTrap {
public:
    void makeSound() override {
        std::cout << "ScavTrap sound" << std::endl;
    }
};

int main() {
    ClapTrap* trap = new ScavTrap();
    trap->makeSound(); // Calls ScavTrap's makeSound
    delete trap;
}
```

### The Diamond Problem

The diamond problem occurs in multiple inheritance when a class inherits from two classes that have a common base class.

```cpp
class A {
protected:
    int value;
};

class B : public A {};
class C : public A {};

// Diamond Problem
class D : public B, public C {
    // Has two copies of 'value'
};

// Solution using virtual inheritance
class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {
    // Now has only one copy of 'value'
};
```

## Exercise Details

### Exercise 00: ClapTrap
- Implement a base class with basic attributes and methods
- Learn about constructors, destructors, and member functions
- Handle object state management

### Exercise 01: ScavTrap
- Create a derived class from ClapTrap
- Implement constructor and destructor chaining
- Override base class methods
- Add new functionality

### Exercise 02: FragTrap
- Create another derived class with different attributes
- Practice inheritance and method overriding
- Implement unique special abilities

### Exercise 03: DiamondTrap
- Handle multiple inheritance
- Solve the diamond problem using virtual inheritance
- Manage complex constructor chains
- Implement name conflict resolution

## Resources

- [C++ Inheritance](https://www.geeksforgeeks.org/inheritance-in-c/)
- [Virtual Functions in C++](https://www.geeksforgeeks.org/virtual-function-cpp/)
- [Multiple Inheritance and Diamond Problem](https://www.geeksforgeeks.org/multiple-inheritance-in-c/)
- [Access Specifiers in C++](https://www.geeksforgeeks.org/access-modifiers-in-c/)
- [Constructor and Destructor Chaining](https://www.geeksforgeeks.org/constructors-c/)
- [Function Overriding in C++](https://www.geeksforgeeks.org/function-overriding-in-cpp/)
