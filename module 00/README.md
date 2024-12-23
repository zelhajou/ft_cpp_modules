# Module 00

This module introduces the basics of C++ programming. You'll learn about the syntax, data types, and control structures in C++. You'll also get familiar with the standard library and how to use it in your programs.

## Summary of Concepts

- **Namespaces**: Organizing code into logical groups to prevent naming conflicts.
- **Command-line arguments**: Handling input given when the program is executed.
- **Basic I/O**: Using streams for input and output operations.
- **String manipulation**: Modifying strings using functions like `toupper`.
- **File Structure**: Organizing code into header and source files.
- **Classes and objects**: Defining classes to encapsulate data and functions.
- **Constructors and destructors**: Special functions for initializing and cleaning up objects.
- **Member functions and variables**: Functions and variables inside a class.
- **`this` pointer**: Special pointer that points to the object itself.
- **Initialization list**: Efficient way to initialize member variables in constructors.
- **`const` member functions**: Functions that do not modify the object's state.
- **Visibility modes**: Control access levels of class members.
- **Class vs. Struct**: Differences between classes and structs in C++.
- **Accessors and Mutators**: Getters and setters for private member variables.
- **Comparisons between objects**: Comparing objects using operators.
- **Non-member attributes and functions**: Variables and functions not part of a class.
- **Pointers to members**: Storing the address of a member variable or function.

## Exercise 00: Megaphone

**Topic**: Command-line arguments, basic input/output, string manipulation

**Explanation**:

This exercise focuses on understanding how to handle command-line arguments in C++. You'll write a simple program that converts all input characters to uppercase and prints them to the console. It introduces:

- **Command-line arguments**: Handling input given when the program is executed.
- **String manipulation**: Using functions like `toupper` to modify strings.
- **Basic I/O**: Using `std::cout` and `std::endl` for output.

## Exercise 01: My Awesome PhoneBook

**Topic**: Classes and objects, arrays, user input, basic data management

**Explanation**:

This exercise is about creating a simple phone book application using classes. You'll learn about:

- **Classes and objects**: Defining and using classes (`PhoneBook` and `Contact`).
- **Member functions and variables**: Implementing functions to add and search contacts.
- **Arrays**: Storing multiple contacts in an array.
- **User input**: Getting input from the user to interact with the phone book.

## Exercise 02: Account

**Topic**: Constructors, destructors, member functions, visibility modes

## Detailed Explanation of Each Topic

- [Namespaces](#namespaces)
- [Command-line arguments](#command-line-arguments)
- [Basic I/O](#basic-io)
- [String manipulation](#string-manipulation)
- [File Structure](#file-structure)
- [Classes and objects](#classes-and-objects)
- [Constructors and destructors](#constructors-and-destructors)
- [Member functions and variables](#member-functions-and-variables)
- [`this` pointer](#this-pointer)
- [Initialization list](#initialization-list)
- [`const` member functions](#const-member-functions)
- [Visibility modes](#visibility-modes)
- [Class vs. Struct](#class-vs-struct)
- [Accessors and Mutators](#accessors-and-mutators)
- [Comparisons between objects](#comparisons-between-objects)
- [Non-member attributes and Non-member functions](#non-member-attributes-and-non-member-functions)
- [Pointers to members](#pointers-to-members)

### Namespaces

Namespaces are used to organize code into logical groups and prevent naming conflicts. The `std` namespace is the standard namespace for C++ standard library functions and objects.

For example:

```cpp
#include <iostream>

int value = 42;

namespace my_namespace {
 int value = 100;
}

namespace my_namespace {
 void my_function() {
  std::cout << "Hello, world!" << std::endl;
 }
}

int main() {
 std::cout << "Global value: " << value << std::endl;
 std::cout << "Namespace value: " << my_namespace::value << std::endl;
 my_namespace::my_function();
 return 0;
}
```

### Command-line arguments

In C++, command-line arguments are handled using the parameters `argc` (argument count) and `argv` (argument vector) in the main function. `argc` indicates the number of arguments, and `argv` is an array of C-strings representing the arguments.

For example:

```cpp
int main(int argc, char* argv[]) {
 // Check the number of arguments
 if (argc < 2) {
  std::cout << "Usage: " << argv[0] << " <name1> <name2> ..." << std::endl;
  return 1;
 }

 // Process the arguments
 for (int i = 1; i < argc; ++i) {
  std::cout << "Argument " << i << ": " << argv[i] << std::endl;
 }

 return 0;
}
```

### Basic I/O

Input and output in C++ are handled using streams. std::cout is used for output, and `std::cin` for input. The `std::endl` manipulator is used to insert a newline character and flush the stream.

For example:

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

- [C++ I/O](https://www.geeksforgeeks.org/basic-input-output-c/)
- [Stream IO and File IO](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp10_IO.html)

### String manipulation

C++ provides functions for manipulating strings, such as `toupper` to convert characters to uppercase, which is available in the `<cctype>` library.

For example:

```cpp
#include <iostream>
#include <cctype>

int main() {
 std::string input = "hello, world!";
 for (char& c : input) {
  c = std::toupper(c);
 }
 std::cout << input << std::endl;
 return 0;
}
```

- [string C++ examples](http://anaturb.net/C/string_exapm.htm)
- [strings in C++](https://beginnersbook.com/2017/08/strings-in-c/)

### File Structure

Organizing code into multiple files helps manage large projects. Header files (.hpp) declare the interface of classes, while source files (.cpp) contain the implementation.

#### Header file (example.hpp)

Header files, typically with a .hpp or .h extension, contain declarations of classes, functions, variables, and other constructs. They serve as the interface to your code, providing the necessary information for other code files to use the declared functionalities without revealing the actual implementation details.

### Classes and objects

A class is a blueprint for creating objects, encapsulating data, and functions that operate on that data. Objects are instances of classes.

For example:

```cpp
class MyClass {
public:
 int my_variable;
 void my_function() {
  std::cout << "Hello, world!" << std::endl;
 }
};

int main() {
 MyClass obj;
 obj.my_variable = 42;
 obj.my_function();
 return 0;
}
```

### Constructors and destructors

Constructors are special functions called when an object is instantiated, initializing the object. Destructors are called when an object is destroyed, performing any necessary cleanup.



For example:

```cpp
class MyClass {
public:
 MyClass() {
  std::cout << "Constructor called" << std::endl;
 }
 ~MyClass() {
  std::cout << "Destructor called" << std::endl;
 }
};

int main() {
 MyClass obj;
 return 0;
}
```

### Member functions and variables

Member functions are functions defined inside a class that operate on the class's data. Member variables are variables declared inside a class.

For example:

```cpp
class MyClass {
public:
 int my_variable;
 void my_function() {
  std::cout << "My variable: " << my_variable << std::endl;
 }
};

int main() {
 MyClass obj;
 obj.my_variable = 42;
 obj.my_function();
 return 0;
}
```

### `this` pointer

The `this` pointer is a special pointer that points to the object itself. It is used to access the object's member variables and functions within member functions.

For example:

```cpp
class MyClass {
public:
 int my_variable;
 void set_variable(int value) {
  this->my_variable = value;
 }
};

int main() {
 MyClass obj;
 obj.set_variable(42);
 std::cout << "My variable: " << obj.my_variable << std::endl;
 return 0;
}
```

- Using `this` is useful when parameter names are the same as member variable names.
- Omitting `this` works when there’s no naming conflict.
- `this` ensures clarity and is necessary for certain tasks like returning the current object and avoiding naming conflicts.

### Initialization list

The initialization list is used to initialize member variables of a class in the constructor. It is more efficient than assigning values in the constructor body.

For example:

```cpp
class MyClass {
public:
 int my_variable;
 MyClass(int value) : my_variable(value) {
 std::cout << "Constructor called" << std::endl;
 std::cout << "My variable: " << my_variable << std::endl;
 }
};

int main() {
 MyClass obj(42);
 std::cout << "My variable: " << obj.my_variable << std::endl; 
 return 0;
}

```

### `const` member functions

`const` member functions are functions that do not modify the object's state. They are declared using the `const` keyword after the function declaration.

For example:

```cpp
class MyClass {
public:
 int my_variable; 
 void my_function() const {
  my_variable = 42; // Error: Cannot modify member variable in const function
  std::cout << "My variable: " << my_variable << std::endl;
 }
};

int main() {
 const MyClass obj;
 obj.my_variable = 42; // Error: Cannot modify const object
 obj.my_function();
 return 0;
}
```

### Visibility modes

Visibility modes in C++ classes control the access level of class members. The three visibility modes are:

- `public`: Members are accessible from outside the class.
- `protected`: Members are accessible from derived classes.
- `private`: Members are only accessible from within the class.

For example:

```cpp
class MyClass {

public:
 int public_variable;

protected:
 int protected_variable;

private:
 int private_variable;
};

int main() {
 MyClass obj;
 obj.public_variable = 42; // OK
 obj.protected_variable = 42; // Error: Cannot access protected member
 obj.private_variable = 42; // Error: Cannot access private member
 return 0;
}
```

### Class vs. Struct

In C++, classes and structs are almost identical, with the only difference being the default access level. In classes, members are private by default, while in structs, members are public by default.

For example:

```cpp
class MyClass {
 int private_variable;
public:
 int public_variable;
};

struct MyStruct {
 int private_variable;
 int public_variable;
};

int main() {
 MyClass obj1;
 MyStruct obj2;
 obj1.private_variable = 42; // Error: Cannot access private member
 obj2.private_variable = 42; // OK
 return 0;
}
```

### Accessors and Mutators

Accessors (getters) and mutators (setters) are member functions used to access and modify private member variables, respectively. They provide controlled access to the class's data.

For example:

```cpp
class MyClass {
 int private_variable;
public:
 int get_variable() const {
  return private_variable;
 }
 void set_variable(int value) {
  private_variable = value;
 }
};

int main() {
 MyClass obj;
 obj.set_variable(42);
 std::cout << "My variable: " << obj.get_variable() << std::endl;
 return 0;
}
```

### Comparisons between objects

In C++, you can compare objects using the `==` and `!=` operators. By default, these operators compare the memory addresses of the objects. To compare the contents of objects, you need to overload these operators.

For example:

```cpp
class MyClass {
 int value;
public:
 MyClass(int v) : value(v) {}
 int compare(MyClass * other) {
 if (this->value < other->value) {
  return -1;
 }
 else if (this->value > other->value) {
  return 1;
 }
 return 0;
 }
};

int main() {
 MyClass instance1(42);
 MyClass instance2(24);

if (&instance1 == &instance1)
	std::cout << "instance1 and instance1 are the same object" << std::endl;
else
	std::cout << "instance1 and instance1 are different objects" << std::endl;

if (&instance1 == &instance2)
	std::cout << "instance1 and instance2 are the same object" << std::endl;
else
	std::cout << "instance1 and instance2 are different objects" << std::endl;

if (instance1.compare(&instance1) == 0)
	std::cout << "instance1 is equal to instance1" << std::endl;
else
	std::cout << "instance1 is not equal to instance1" << std::endl;

if (instance1.compare(&instance2) == 0)
	std::cout << "instance1 and instance2 are equal" << std::endl;
else
	std::cout << "instance1 and instance2 are not equal" << std::endl;
 return 0;
}

```

### Non-member attributes and Non-member functions

Non-member attributes and functions are variables and functions that are not part of a class but are related to it. They can be used to store or manipulate data that is not specific to a single object.

```cpp
class MyClass {

public:
 MyClass(void);
 ~MyClass(void);
 static int getNbInstances();
private:
 static int nbInstances;
};

int MyClass::nbInstances = 0;

MyClass::MyClass(void) {
std::cout << "Constructor called" << std::endl;
 MyClass::nbInstances++;
 return;
}

MyClass::~MyClass(void) {
std::cout << "Destructor called" << std::endl;
 MyClass::nbInstances--;
 return;
}

int MyClass::getNbInstances() {
 return MyClass::nbInstances;
}


int main() {
 MyClass instance1;
 MyClass instance2;
 std::cout << "Number of instances: " << MyClass::getNbInstances() << std::endl;
 return 0;
}
```

### Pointers to members

Pointers to members are used to store the address of a member variable or function of a class. They can be used to access or call the member through the pointer.

```cpp
class MyClass {
public:
 int my_variable;
 void my_function() {
  std::cout << "Hello, world!" << std::endl;
 }
};

int main() {
 int MyClass::* ptr_variable = &MyClass::my_variable;
 void (MyClass::* ptr_function)() = &MyClass::my_function;

 MyClass obj;
 obj.*ptr_variable = 42;
 std::cout << "My variable: " << obj.*ptr_variable << std::endl;
 (obj.*ptr_function)();
 return 0;
}
```

## Resources

- [C++ Reference](https://en.cppreference.com/w/)
- [C++ Tutorial](https://www.cplusplus.com/doc/tutorial/)
- [C++ Programming](https://www.geeksforgeeks.org/c-plus-plus/)
- [C++ Standard Library](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)

