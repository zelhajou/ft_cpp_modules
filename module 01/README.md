# Module 01

This module covers various aspects of C++ including memory allocation, pointers to members, references, and the switch statement.

## Table of Contents

1. [Exercise 00: BraiiiiiiinnnzzzZ](#exercise-00-braiiiiiiinnnzzzz)
2. [Exercise 01: Moar brainz!](#exercise-01-moar-brainz)
3. [Exercise 02: HI THIS IS BRAIN](#exercise-02-hi-this-is-brain)
4. [Exercise 03: Unnecessary violence](#exercise-03-unnecessary-violence)
5. [Exercise 04: Sed is for losers](#exercise-04-sed-is-for-losers)
6. [Exercise 05: Harl 2.0](#exercise-05-harl-20)
7. [Exercise 06: Harl filter](#exercise-06-harl-filter)

## Summary of Concepts

- **Classes and Objects**: Creating and using classes to encapsulate data and functions.
- **Dynamic Memory Allocation**: Allocating and deallocating memory on the heap using new and delete.
- **Pointers and References**: Understanding how to use pointers and references to manipulate data and functions.
- **File I/O**: Reading from and writing to files using C++ file streams.
- **String Manipulation**: Using C++ string functions to manipulate strings.
- **Switch Statement**: Using switch statements for multi-way branching based on different conditions.
- **Memory Management**: Ensuring proper memory allocation and deallocation to avoid memory leaks.

## Exercise 00: BraiiiiiiinnnzzzZ

**Topic**: Classes, dynamic memory allocation, destructor

**Explanation**:

- **Classes**: Implement a Zombie class with a private attribute name and a member function announce() that prints the zombie’s name followed by "BraiiiiiiinnnzzzZ...".
- **Dynamic Memory Allocation**: Implement functions newZombie() to create and return a zombie on the heap, and randomChump() to create and announce a zombie on the stack.
- **Destructor**: Ensure the destructor prints a message when a zombie is destroyed.

## Exercise 01: Moar brainz!

**Topic**: Arrays, dynamic memory allocation

**Explanation**:

- **Arrays**: Implement a function zombieHorde(int N, std::string name) that creates an array of N zombies, each named name.
- **Dynamic Memory Allocation**: Allocate memory for the zombies in one go and ensure proper cleanup to avoid memory leaks.

## Exercise 02: HI THIS IS BRAIN

**Topic**: Pointers, references

**Explanation**:

- **Pointers**: Create a pointer stringPTR pointing to a string.
- **References**: Create a reference stringREF to the same string.
Output: Print the memory addresses and values of the string variable, pointer, and reference to understand the differences between them.

## Exercise 03: Unnecessary violence

**Topic**: Class composition, pointers vs references

**Explanation**:

- **Class Composition**: Implement classes Weapon, HumanA, and HumanB.
        - `Weapon` has a private string attribute `type`, and functions `getType()` and `setType()`.
        - `HumanA` and `HumanB` both have a `Weapon` and a `name`, and an `attack()` function that prints an attack message.
- **Pointers vs References**: `HumanA` initializes its weapon in the constructor (using a reference), while `HumanB` can change its weapon dynamically (using a pointer).

## Exercise 04: Sed is for losers

**Topic**: File I/O, string manipulation

**Explanation**:

- **File I/O**: Write a program that reads from a file, replaces occurrences of a string `s1` with `s2`, and writes the result to a new file `<filename>.replace`.
- **String Manipulation**: Use C++ string functions (except `std::string::replace`) to perform the replacement.

## Exercise 05: Harl 2.0

**Topic**: Pointers to member functions

**Explanation**:

- **Pointers to Member Functions**: Implement a class Harl with functions `debug()`, `info()`, `warning()`, and `error()`.
- **Complain Function**: Create a `complain(std::string level)` function that calls the appropriate member function based on the level, using pointers to member functions to avoid multiple `if/else` statements.

## Exercise 06: Harl filter

**Topic**: Switch statement

**Explanation**:

- Switch Statement: Implement a program that filters Harl’s complaints based on a given level, displaying messages from the specified level and higher.
- Log Levels: Use a switch statement to handle different levels and ensure the program responds appropriately to each.


## Detailed Explanation of Each Topic

### Classes and Objects

Classes are user-defined data types that encapsulate data and functions into a single unit. They provide a blueprint for creating objects, which are instances of the class. Classes can have attributes (data members) and methods (member functions) that operate on the data.

In the Zombie class example, the class has a private attribute `name` and a member function `announce()` that prints the zombie’s name followed by "BraiiiiiiinnnzzzZ...

```cpp
class Zombie {
private:
	std::string name;
public:
	void announce() {
		std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
	}
};
```

### Dynamic Memory Allocation

Dynamic memory allocation allows programs to allocate memory at runtime, rather than at compile time. In C++, the `new` operator is used to allocate memory on the heap, and the `delete` operator is used to deallocate it.

In the `newZombie()` function, memory is allocated for a new Zombie object on the heap, and the address of the object is returned.

```cpp
Zombie* newZombie() {
	Zombie* zombie = new Zombie();
	return zombie;
}
```

### Pointers and References

Pointers and references are used to store memory addresses and access data indirectly. Pointers store the address of a variable, while references provide an alias for a variable.

In the `HI THIS IS BRAIN` example, a pointer `stringPTR` and a reference `stringREF` are created to point to the same string variable.

```cpp

std::string str = "HI THIS IS BRAIN";

std::string* stringPTR = &str;
std::string& stringREF = str;

std::cout << "Address of string: " << &str << std::endl;
std::cout << "Address of pointer: " << stringPTR << std::endl;
std::cout << "Address of reference: " << &stringREF << std::endl;

std::cout << "Value of string: " << str << std::endl;
std::cout << "Value of pointer: " << *stringPTR << std::endl;
std::cout << "Value of reference: " << stringREF << std::endl;
```

### File I/O

File I/O in C++ involves reading from and writing to files using file streams. The `ifstream` class is used for reading from files, and the `ofstream` class is used for writing to files.

In the `Sed is for losers` example, a program reads from a file, replaces occurrences of a string `s1` with `s2`, and writes the result to a new file.


```cpp
#include <fstream> 
#include <iostream> 
#include <string> 

std::ifstream input("input.txt");
std::ofstream output("output.txt");

std::string line;
while (std::getline(input, line)) {
	output << line << std::endl;
}
```

### String Manipulation

String manipulation involves modifying strings using various operations such as concatenation, substring extraction, and search and replace. C++ provides a rich set of string functions to perform these operations.

In the `Sed is for losers` example, the `replace_string()` function replaces occurrences of a substring `s1` with another substring `s2` in a given string.

```cpp
void replace_string(std::string &str, const std::string &s1, const std::string &s2) {
	size_t start_pos = 0;
	while ((start_pos = str.find(s1, start_pos)) != std::string::npos) {
		str.erase(start_pos, s1.length());
		str.insert(start_pos, s2);
		start_pos += s2.length();
	}
}
```

### Switch Statement

The switch statement in C++ is used for multi-way branching based on the value of an expression. It provides an alternative to using multiple if-else statements for handling different cases.

In the `Harl filter` example, a switch statement is used to filter Harl’s complaints based on a given level, displaying messages from the specified level and higher.

```cpp
std::string level = "INFO";
switch (level) {
	case "DEBUG":
		std::cout << "DEBUG: This is a debug message." << std::endl;
	case "INFO":
		std::cout << "INFO: This is an info message." << std::endl;
	case "WARNING":
		std::cout << "WARNING: This is a warning message." << std::endl;
	case "ERROR":
		std::cout << "ERROR: This is an error message." << std::endl;
	default:
		std::cout << "Invalid level." << std::endl;
}
```


## Resources

- [C++ Classes and Objects](https://www.geeksforgeeks.org/c-classes-and-objects/)
- [Dynamic Memory Allocation in C++](https://www.cplusplus.com/doc/tutorial/dynamic/)
- [Pointers and References in C++](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)
- [File I/O in C++](https://www.geeksforgeeks.org/file-handling-c-classes/)
- [String Manipulation in C++](https://www.cplusplus.com/reference/string/string/)
- [Switch Statement in C++](https://www.geeksforgeeks.org/switch-statement-cc/)
