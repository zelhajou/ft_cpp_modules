#include <iostream>

// Simple array container with iterator
template<typename T>
class Array {
private:
    T* array;
    int size;

public:
    // Basic iterator class
    class Iterator {
    private:
        T* ptr;  // Pointer to current element
    
    public:
        // Constructor
        Iterator(T* p = 0) : ptr(p) {}

        // Dereference operator - get value
        T& operator*() {
            return *ptr;
        }

        // Increment operator (prefix)
        Iterator& operator++() {
            ptr++;
            return *this;
        }

        // Comparison operators
        bool operator!=(const Iterator& other) {
            return ptr != other.ptr;
        }
        bool operator==(const Iterator& other) {
            return ptr == other.ptr;
        }
    };

    // Constructor
    Array(int s = 10) : size(s) {
        array = new T[size];
    }

    // Destructor
    ~Array() {
        delete[] array;
    }

    // Get element at index
    T& operator[](int index) {
        return array[index];
    }

    // Iterator methods
    Iterator begin() {
        return Iterator(array);
    }

    Iterator end() {
        return Iterator(array + size);
    }
};

int main() {
    Array<int> arr(5);

    // Fill array with values
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    // Use iterator to print values
    Array<int>::Iterator it;
    for (it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}