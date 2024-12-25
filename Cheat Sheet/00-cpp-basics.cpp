#include <iostream>
#include <string>

// Part 1: Basic Data Types and Variables
int main() {
    // Basic Data Types
    int integer = 42;                    // Integer
    double decimal = 3.14;               // Double precision floating point
    float smaller_decimal = 3.14f;       // Single precision floating point
    char character = 'A';                // Single character
    bool boolean = true;                 // Boolean
    std::string text = "Hello World";    // String (requires <string>)

    // Constants
    const int CONSTANT = 100;            // Constant value that cannot be changed
    
    // Type information and size
    std::cout << "Size of int: " << sizeof(integer) << " bytes\n";
    std::cout << "Size of double: " << sizeof(decimal) << " bytes\n";
    std::cout << "Size of float: " << sizeof(smaller_decimal) << " bytes\n";
    std::cout << "Size of char: " << sizeof(character) << " bytes\n";
    std::cout << "Size of bool: " << sizeof(boolean) << " bytes\n";

    // Basic Input/Output
    std::cout << "Basic output with cout\n";          // Output with newline
    std::cout << "Number: " << integer << std::endl;  // Output with endl

    int input_number;
    std::cout << "Enter a number: ";
    std::cin >> input_number;                         // Basic input
    
    // Multiple variables input/output
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    std::cout << "Sum: " << x + y << '\n';

    // String input (with spaces)
    std::string full_name;
    std::cout << "Enter your full name: ";
    std::cin.ignore();                               // Clear buffer
    std::getline(std::cin, full_name);              // Read entire line
    std::cout << "Hello, " << full_name << "!\n";

    return 0;
}
