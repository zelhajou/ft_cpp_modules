#include <iostream>
#include <stdexcept>
#include <string>

// ===== Template Functions =====
// Basic function template
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Template with multiple types
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Template specialization
template<typename T>
void printType(T value) {
    std::cout << "Generic type\n";
}

template<>
void printType<int>(int value) {
    std::cout << "Integer type\n";
}

// ===== Complex Number Class with Operator Overloading =====
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Operator overloading
    // Addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                      real * other.imag + imag * other.real);
    }

    // Assignment
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    // Compound assignment
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Increment operators
    Complex& operator++() {    // Pre-increment
        ++real;
        return *this;
    }

    Complex operator++(int) {  // Post-increment
        Complex temp = *this;
        ++real;
        return temp;
    }

    // Comparison operators
    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) os << "+";
    os << c.imag << "i";
    return os;
}

// Input stream operator
std::istream& operator>>(std::istream& is, Complex& c) {
    std::cout << "Enter real part: ";
    is >> c.real;
    std::cout << "Enter imaginary part: ";
    is >> c.imag;
    return is;
}

// ===== Custom Exception Classes =====
class DivisionByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Division by zero attempted!";
    }
};

class InvalidAgeException : public std::exception {
private:
    std::string message;
public:
    InvalidAgeException(int age) : message("Invalid age: " + std::to_string(age)) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Function that might throw exceptions
int divide(int a, int b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

void setAge(int age) {
    if (age < 0 || age > 150) {
        throw InvalidAgeException(age);
    }
    std::cout << "Age set to: " << age << std::endl;
}

// ===== Template Class with Multiple Parameters =====
template<typename T, typename U, int Size>
class Container {
private:
    T first;
    U second;
    T array[Size];

public:
    Container(T f, U s) : first(f), second(s) {
        for (int i = 0; i < Size; i++) {
            array[i] = T();
        }
    }

    void print() const {
        std::cout << "First: " << first << ", Second: " << second << std::endl;
        std::cout << "Array: ";
        for (int i = 0; i < Size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "===== Template Functions =====\n";
    std::cout << "Maximum of 10 and 20: " << maximum(10, 20) << std::endl;
    std::cout << "Maximum of 3.14 and 2.72: " << maximum(3.14, 2.72) << std::endl;
    std::cout << "Sum of int and double: " << add(5, 3.14) << std::endl;

    std::cout << "\n===== Template Specialization =====\n";
    printType(42);        // Uses specialized version
    printType(3.14);      // Uses generic version
    printType("Hello");   // Uses generic version

    std::cout << "\n===== Operator Overloading =====\n";
    Complex c1(3, 4);
    Complex c2(1, 2);
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c1 + c2 = " << c1 + c2 << std::endl;
    std::cout << "c1 * c2 = " << c1 * c2 << std::endl;
    
    Complex c3;
    c3 = c1;             // Assignment operator
    std::cout << "c3 = " << c3 << std::endl;
    
    ++c3;                // Pre-increment
    std::cout << "After ++c3: " << c3 << std::endl;

    std::cout << "\n===== Exception Handling =====\n";
    // Example 1: Division by zero
    try {
        std::cout << divide(10, 2) << std::endl;
        std::cout << divide(10, 0) << std::endl;  // This will throw
    } catch (const DivisionByZeroException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Example 2: Invalid age
    try {
        setAge(25);     // Valid age
        setAge(200);    // This will throw
    } catch (const InvalidAgeException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Example 3: Multiple catch blocks and catch-all
    try {
        // Some operations that might throw different exceptions
        throw std::runtime_error("Runtime error occurred");
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Runtime error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception caught" << std::endl;
    }

    std::cout << "\n===== Template Class =====\n";
    Container<int, std::string, 5> container(42, "Hello");
    container.print();

    return 0;
}
