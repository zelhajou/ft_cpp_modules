### EX00

This exercise aims to teach and demonstrate the concept of polymorphism in C++, which is a fundamental principle of object-oriented programming (OOP). Polymorphism allows objects of different classes to be treated as objects of a common base class.
The exercise focuses on creating a base class `Animal` and derived classes `Dog` and `Cat` to illustrate how polymorphism works. Additionally, it introduces the concept of method overriding and the use of virtual functions.

## 1. Polymorphism

Polymorphism in C++ allows you to call derived class methods through a base class pointer or reference. It is mainly achieved through:

- **Function Overloading**: Multiple functions with the same name but different parameters.
- **Operator Overloading**: Defining custom behavior for operators for user-defined types.
- **Virtual Functions**: Functions in a base class that can be overridden in derived classes to provide specific behavior.

## 2. Virtual Functions
A virtual function is a member function in the base class that you expect to override in derived classes.
When you refer to a derived class object using a base class pointer or reference, you can call a virtual function for that object and execute the derived class's version of the function.

## 3. Base and Derived Classes
In this exercise, we create a base class `Animal` and two derived classes `Dog` and `Cat`.

**Base Class `Animal`**

The Animal class has a protected attribute type and a virtual function makeSound:

```cpp
class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;
};
```

- **Protected Attribute**: Allows derived classes to access type.
- **Virtual Destructor**: Ensures the correct destructor is called for derived classes.
- **Virtual Function**: `makeSound` allows derived classes to provide their specific implementation.

**Derived Classes `Dog` and `Cat`**

These classes inherit from `Animal` and override the `makeSound` function:

```cpp
class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    void makeSound() const;
};

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;
};
```

- **Constructor**: Sets the type to "Dog" or "Cat" and prints a creation message.
- **Destructor**: Prints a destruction message.
- **Overridden Function**: Provides specific behavior for `makeSound`.

**Implementation**

The implementation of the `Animal`, `Dog`, and `Cat` classes is separated into `.cpp` files:

`Animal.cpp`

```cpp
#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal created.\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copied.\n";
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal assigned.\n";
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed.\n";
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound.\n";
}

std::string Animal::getType() const {
    return type;
}
```

`Dog.cpp`

```
#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created.\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copied.\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog assigned.\n";
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed.\n";
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}
```

`Cat.cpp`

```cpp

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created.\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copied.\n";
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat assigned.\n";
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed.\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}
```

## 4. Main Function

The main function demonstrates polymorphism by creating instances of `Animal`, `Dog`, and `Cat` and calling their functions through base class pointers:

```cpp
int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!
    meta->makeSound(); // will output the generic animal sound!

    delete meta;
    delete j;
    delete i;

    return 0;
}
```

- **Base Class Pointers**: `meta`, `j`, and `i` are pointers to `Animal`, but point to `Animal`, `Dog`, and `Cat` objects, respectively.
- **Polymorphic Behavior**: Calls to `makeSound` on these pointers result in the derived class versions being executed.
- **Destructor Calls**: Ensures proper cleanup by calling `delete` on each pointer.

## 5. WrongAnimal and WrongCat

These classes illustrate what happens if polymorphism is not correctly implemented:

```cpp
class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal() : type("WrongAnimal") { std::cout << "WrongAnimal created.\n"; }
    virtual ~WrongAnimal() { std::cout << "WrongAnimal destroyed.\n"; }
    void makeSound() const { std::cout << "Some wrong animal sound.\n"; }
};

class WrongCat : public WrongAnimal {
public:
    WrongCat() { type = "WrongCat"; std::cout << "WrongCat created.\n"; }
    ~WrongCat() { std::cout << "WrongCat destroyed.\n"; }
    void makeSound() const { std::cout << "Wrong meow!\n"; }
};
```

In these classes, `WrongAnimal` and `WrongCat` illustrate what happens when polymorphism is not implemented correctly. `WrongAnimal` does not use virtual functions for its `makeSound`, which means that it will not exhibit polymorphic behavior when used in a base class pointer context. This demonstrates the importance of using virtual functions to achieve polymorphism in C++.

