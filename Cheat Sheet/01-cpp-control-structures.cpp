#include <iostream>

// Function declarations
int add(int a, int b);                     // Basic function
int multiply(int a, int b = 1);            // Function with default parameter
void swap(int& a, int& b);                 // Function using references
inline int square(int x) { return x * x; } // Inline function

int main() {
    // Operators
    int a = 10, b = 3;
    
    // Arithmetic operators
    std::cout << "Arithmetic Operators:\n";
    std::cout << "a + b = " << (a + b) << '\n';  // Addition
    std::cout << "a - b = " << (a - b) << '\n';  // Subtraction
    std::cout << "a * b = " << (a * b) << '\n';  // Multiplication
    std::cout << "a / b = " << (a / b) << '\n';  // Division
    std::cout << "a % b = " << (a % b) << '\n';  // Modulus
    
    // Increment/Decrement
    int x = 5;
    std::cout << "\nIncrement/Decrement:\n";
    std::cout << "x++ = " << x++ << '\n';  // Post-increment
    std::cout << "++x = " << ++x << '\n';  // Pre-increment
    std::cout << "x-- = " << x-- << '\n';  // Post-decrement
    std::cout << "--x = " << --x << '\n';  // Pre-decrement

    // Comparison operators
    std::cout << "\nComparison Operators:\n";
    std::cout << "a == b: " << (a == b) << '\n';  // Equal to
    std::cout << "a != b: " << (a != b) << '\n';  // Not equal to
    std::cout << "a > b: " << (a > b) << '\n';    // Greater than
    std::cout << "a < b: " << (a < b) << '\n';    // Less than
    std::cout << "a >= b: " << (a >= b) << '\n';  // Greater than or equal
    std::cout << "a <= b: " << (a <= b) << '\n';  // Less than or equal

    // Logical operators
    bool condition1 = true, condition2 = false;
    std::cout << "\nLogical Operators:\n";
    std::cout << "AND: " << (condition1 && condition2) << '\n';  // Logical AND
    std::cout << "OR: " << (condition1 || condition2) << '\n';   // Logical OR
    std::cout << "NOT: " << (!condition1) << '\n';              // Logical NOT

    // Control Structures
    // If-else statement
    std::cout << "\nIf-else statement:\n";
    if (a > b) {
        std::cout << "a is greater than b\n";
    } else if (a < b) {
        std::cout << "a is less than b\n";
    } else {
        std::cout << "a is equal to b\n";
    }

    // Switch statement
    std::cout << "\nSwitch statement:\n";
    int choice = 2;
    switch (choice) {
        case 1:
            std::cout << "Choice is 1\n";
            break;
        case 2:
            std::cout << "Choice is 2\n";
            break;
        default:
            std::cout << "Choice is neither 1 nor 2\n";
    }

    // Loops
    // For loop
    std::cout << "\nFor loop:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "Iteration " << i << '\n';
    }

    // Range-based for loop (C++11)
    std::cout << "\nRange-based for loop:\n";
    int array[] = {1, 2, 3};
    for (const int& num : array) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    // While loop
    std::cout << "\nWhile loop:\n";
    int count = 0;
    while (count < 3) {
        std::cout << "Count: " << count << '\n';
        count++;
    }

    // Do-while loop
    std::cout << "\nDo-while loop:\n";
    int j = 0;
    do {
        std::cout << "j = " << j << '\n';
        j++;
    } while (j < 2);

    // Function calls
    std::cout << "\nFunction calls:\n";
    std::cout << "add(5, 3) = " << add(5, 3) << '\n';
    std::cout << "multiply(4) = " << multiply(4) << '\n';
    std::cout << "square(5) = " << square(5) << '\n';

    int num1 = 10, num2 = 20;
    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << '\n';
    swap(num1, num2);
    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << '\n';

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {  // b has default value of 1
    return a * b;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
