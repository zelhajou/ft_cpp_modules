#include <iostream>
#include <memory>           // For smart pointers
#include <thread>          // For std::thread
#include <mutex>           // For std::mutex, std::lock_guard
#include <future>          // For std::async, std::promise, std::future
#include <functional>      // For std::function
#include <chrono>          // For time utilities
#include <array>           // For std::array
#include <tuple>          // For std::tuple
#include <type_traits>    // For type traits

// Class for demonstrating smart pointers
class Resource {
public:
    Resource(const std::string& name) : name_(name) {
        std::cout << "Resource " << name_ << " created\n";
    }
    ~Resource() {
        std::cout << "Resource " << name_ << " destroyed\n";
    }
    void use() const {
        std::cout << "Using resource " << name_ << "\n";
    }
private:
    std::string name_;
};

// Mutex for thread synchronization
std::mutex print_mutex;

// Function to demonstrate thread-safe printing
template<typename T>
void thread_safe_print(const T& message) {
    std::lock_guard<std::mutex> lock(print_mutex);
    std::cout << message << std::endl;
}

int main() {
    // ===== SMART POINTERS =====
    std::cout << "===== SMART POINTERS =====\n\n";

    // unique_ptr - exclusive ownership
    std::cout << "--- unique_ptr ---\n";
    {
        std::unique_ptr<Resource> uniq1 = std::make_unique<Resource>("Unique1");
        uniq1->use();

        // Transfer ownership
        std::unique_ptr<Resource> uniq2 = std::move(uniq1);
        // uniq1 is now nullptr
        if (!uniq1) {
            std::cout << "uniq1 is null after move\n";
        }
    } // Resource automatically destroyed here

    // shared_ptr - shared ownership
    std::cout << "\n--- shared_ptr ---\n";
    {
        std::shared_ptr<Resource> shared1 = std::make_shared<Resource>("Shared1");
        {
            std::shared_ptr<Resource> shared2 = shared1; // Reference count = 2
            std::cout << "Shared count: " << shared1.use_count() << "\n";
        } // Reference count = 1
        std::cout << "Shared count: " << shared1.use_count() << "\n";
    } // Reference count = 0, Resource destroyed

    // weak_ptr - non-owning reference
    std::cout << "\n--- weak_ptr ---\n";
    {
        std::weak_ptr<Resource> weak;
        {
            std::shared_ptr<Resource> shared = std::make_shared<Resource>("WeakShared");
            weak = shared;
            if (auto locked = weak.lock()) {
                locked->use();
            }
        }
        // shared_ptr destroyed, weak_ptr expired
        if (weak.expired()) {
            std::cout << "Weak pointer expired\n";
        }
    }

    // ===== LAMBDA EXPRESSIONS =====
    std::cout << "\n===== LAMBDA EXPRESSIONS =====\n";

    // Basic lambda
    auto add = [](int a, int b) { return a + b; };
    std::cout << "Lambda add(2, 3): " << add(2, 3) << "\n";

    // Lambda with capture
    int multiplier = 10;
    auto multiply = [multiplier](int x) { return x * multiplier; };
    std::cout << "Lambda multiply(5): " << multiply(5) << "\n";

    // Mutable lambda
    auto counter = [count = 0]() mutable { return ++count; };
    std::cout << "Counter: " << counter() << ", " << counter() << "\n";

    // Generic lambda (C++14)
    auto generic = [](auto x, auto y) { return x + y; };
    std::cout << "Generic lambda: " << generic(2, 3) << ", " 
              << generic(std::string("Hello "), "World") << "\n";

    // ===== CONCURRENCY =====
    std::cout << "\n===== CONCURRENCY =====\n";

    // Basic thread
    std::cout << "\n--- Basic Threading ---\n";
    std::thread t1([]() {
        thread_safe_print("Hello from thread 1");
    });
    t1.join();

    // Thread with parameters
    std::thread t2([](int x) {
        thread_safe_print("Thread 2 parameter: " + std::to_string(x));
    }, 42);
    t2.join();

    // async and futures
    std::cout << "\n--- Async and Futures ---\n";
    auto future1 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return 42;
    });
    std::cout << "Async result: " << future1.get() << "\n";

    // Promise and future
    std::cout << "\n--- Promise and Future ---\n";
    std::promise<std::string> promise;
    std::future<std::string> future = promise.get_future();
    
    std::thread t3([](std::promise<std::string> p) {
        p.set_value("Hello from promise");
    }, std::move(promise));
    
    std::cout << "Promise result: " << future.get() << "\n";
    t3.join();

    // ===== OTHER MODERN C++ FEATURES =====
    std::cout << "\n===== OTHER MODERN C++ FEATURES =====\n";

    // auto type deduction
    auto x = 42;
    auto y = 3.14;
    
    // Range-based for loop
    std::array<int, 3> arr = {1, 2, 3};
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // Tuple
    auto tuple = std::make_tuple(1, "Hello", 3.14);
    std::cout << "Tuple: " << std::get<0>(tuple) << ", " 
              << std::get<1>(tuple) << ", " 
              << std::get<2>(tuple) << "\n";

    // Structured bindings (C++17)
    auto [a, b, c] = tuple;
    std::cout << "Structured binding: " << a << ", " << b << ", " << c << "\n";

    // Type traits
    std::cout << "is_integral<int>: " 
              << std::is_integral<int>::value << "\n";
    std::cout << "is_floating_point<double>: " 
              << std::is_floating_point<double>::value << "\n";

    // constexpr
    constexpr int square(int x) { return x * x; }
    constexpr int sq = square(5);
    std::cout << "Constexpr square(5): " << sq << "\n";

    // std::optional (C++17)
    std::optional<int> opt = 42;
    if (opt.has_value()) {
        std::cout << "Optional value: " << *opt << "\n";
    }

    return 0;
}
