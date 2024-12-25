#include <iostream>
#include <cstring> // for C-style string functions

void printArray(int arr[], int size);  // Array parameter
void printPointer(int* arr, int size); // Pointer parameter

int main() {
    // Arrays
    std::cout << "=== Arrays ===\n";
    
    // Fixed-size array
    int numbers[5] = {1, 2, 3, 4, 5};
    std::cout << "Array elements: ";
    for(int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    // 2D Array
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::cout << "\n2D Array elements:\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Pointers
    std::cout << "\n=== Pointers ===\n";
    
    // Basic pointer
    int value = 42;
    int* ptr = &value;  // Pointer initialization
    std::cout << "Value: " << value << "\n";
    std::cout << "Address: " << ptr << "\n";
    std::cout << "Dereferenced value: " << *ptr << "\n";

    // Pointer arithmetic
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;  // Points to first element
    
    std::cout << "\nPointer arithmetic:\n";
    std::cout << "First element: " << *p << "\n";
    p++;  // Move to next element
    std::cout << "Second element: " << *p << "\n";
    p += 2;  // Skip two elements
    std::cout << "Fourth element: " << *p << "\n";

    // Null pointer
    int* nullPtr = nullptr;
    std::cout << "\nNull pointer: " << nullPtr << "\n";

    // References
    std::cout << "\n=== References ===\n";
    
    int original = 100;
    int& ref = original;  // Reference must be initialized when declared
    
    std::cout << "Original value: " << original << "\n";
    std::cout << "Reference value: " << ref << "\n";
    
    ref = 200;  // Modifying through reference
    std::cout << "After modification through reference:\n";
    std::cout << "Original value: " << original << "\n";
    std::cout << "Reference value: " << ref << "\n";

    // Dynamic Memory Allocation
    std::cout << "\n=== Dynamic Memory ===\n";
    
    // Single element
    int* dynamicInt = new int(42);
    std::cout << "Dynamic int: " << *dynamicInt << "\n";
    delete dynamicInt;  // Free the memory

    // Dynamic array
    int size = 5;
    int* dynamicArray = new int[size];
    
    // Initialize array
    for(int i = 0; i < size; i++) {
        dynamicArray[i] = i * 10;
    }
    
    std::cout << "Dynamic array elements: ";
    for(int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << "\n";
    
    delete[] dynamicArray;  // Free the array memory

    // C-style strings vs C++ strings
    std::cout << "\n=== String Handling ===\n";
    
    // C-style string
    char str1[20] = "Hello";
    char str2[20] = " World";
    char result[40];
    
    std::strcpy(result, str1);      // Copy str1 to result
    std::strcat(result, str2);      // Concatenate str2 to result
    std::cout << "C-style concat: " << result << "\n";
    std::cout << "String length: " << std::strlen(result) << "\n";

    // Smart Pointers (C++11)
    std::cout << "\n=== Smart Pointers ===\n";
    std::cout << "Note: Smart pointers (unique_ptr, shared_ptr, weak_ptr)\n";
    std::cout << "are available in C++11 and later versions.\n";
    std::cout << "They provide automatic memory management.\n";

    // Memory safety tips
    std::cout << "\n=== Memory Safety Tips ===\n";
    std::cout << "1. Always initialize pointers\n";
    std::cout << "2. Check for nullptr before dereferencing\n";
    std::cout << "3. Delete dynamically allocated memory\n";
    std::cout << "4. Use smart pointers when possible\n";
    std::cout << "5. Avoid dangling pointers\n";

    return 0;
}

// Function to demonstrate array parameter
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Function to demonstrate pointer parameter
void printPointer(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
