#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <string>

// Custom class for demonstration
class Person {
public:
    std::string name;
    int age;

    Person(const std::string& n, int a) : name(n), age(a) {}

    // Operator overloading for sorting
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

// Function to print any container
template<typename Container>
void printContainer(const Container& c, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& element : c) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int main() {
    // ===== SEQUENCE CONTAINERS =====
    std::cout << "===== SEQUENCE CONTAINERS =====\n";

    // Vector
    std::cout << "\n--- Vector ---\n";
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);                    // Add element at end
    vec.insert(vec.begin() + 2, 10);     // Insert at position
    printContainer(vec, "Vector");

    // List (doubly-linked list)
    std::cout << "\n--- List ---\n";
    std::list<int> lst = {1, 2, 3, 4, 5};
    lst.push_front(0);                   // Add at beginning
    lst.push_back(6);                    // Add at end
    printContainer(lst, "List");

    // Deque (double-ended queue)
    std::cout << "\n--- Deque ---\n";
    std::deque<int> deq = {1, 2, 3, 4, 5};
    deq.push_front(0);                   // Add at beginning
    deq.push_back(6);                    // Add at end
    printContainer(deq, "Deque");

    // ===== ASSOCIATIVE CONTAINERS =====
    std::cout << "\n===== ASSOCIATIVE CONTAINERS =====\n";

    // Set
    std::cout << "\n--- Set ---\n";
    std::set<int> set = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    printContainer(set, "Set (automatically sorted and unique)");

    // Multiset (allows duplicates)
    std::cout << "\n--- Multiset ---\n";
    std::multiset<int> mset = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    printContainer(mset, "Multiset (sorted with duplicates)");

    // Map
    std::cout << "\n--- Map ---\n";
    std::map<std::string, int> map;
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;
    std::cout << "Map contents:\n";
    for (const auto& pair : map) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    // ===== CONTAINER ADAPTERS =====
    std::cout << "\n===== CONTAINER ADAPTERS =====\n";

    // Stack
    std::cout << "\n--- Stack ---\n";
    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Stack top: " << stack.top() << "\n";

    // Queue
    std::cout << "\n--- Queue ---\n";
    std::queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    std::cout << "Queue front: " << queue.front() << "\n";
    std::cout << "Queue back: " << queue.back() << "\n";

    // Priority Queue
    std::cout << "\n--- Priority Queue ---\n";
    std::priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    std::cout << "Priority Queue top: " << pq.top() << "\n";

    // ===== ALGORITHMS =====
    std::cout << "\n===== ALGORITHMS =====\n";

    std::vector<int> algo_vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // Sorting
    std::cout << "\n--- Sorting ---\n";
    std::sort(algo_vec.begin(), algo_vec.end());
    printContainer(algo_vec, "Sorted vector");

    // Finding
    std::cout << "\n--- Finding ---\n";
    auto it = std::find(algo_vec.begin(), algo_vec.end(), 5);
    if (it != algo_vec.end()) {
        std::cout << "Found 5 at position: " 
                  << std::distance(algo_vec.begin(), it) << "\n";
    }

    // Counting
    std::cout << "\n--- Counting ---\n";
    int count = std::count(algo_vec.begin(), algo_vec.end(), 1);
    std::cout << "Number of 1s: " << count << "\n";

    // Min/Max
    std::cout << "\n--- Min/Max ---\n";
    auto [min_it, max_it] = std::minmax_element(algo_vec.begin(), algo_vec.end());
    std::cout << "Min element: " << *min_it << "\n";
    std::cout << "Max element: " << *max_it << "\n";

    // Accumulate
    std::cout << "\n--- Accumulate ---\n";
    int sum = std::accumulate(algo_vec.begin(), algo_vec.end(), 0);
    std::cout << "Sum of elements: " << sum << "\n";

    // Transform
    std::cout << "\n--- Transform ---\n";
    std::vector<int> transformed_vec(algo_vec.size());
    std::transform(algo_vec.begin(), algo_vec.end(), transformed_vec.begin(),
                  [](int x) { return x * 2; });
    printContainer(transformed_vec, "Doubled vector");

    // ===== CUSTOM OBJECTS IN CONTAINERS =====
    std::cout << "\n===== CUSTOM OBJECTS IN CONTAINERS =====\n";
    std::vector<Person> people = {
        Person("Alice", 30),
        Person("Bob", 25),
        Person("Charlie", 35)
    };

    // Sort people by age
    std::sort(people.begin(), people.end());
    std::cout << "Sorted people by age:\n";
    for (const auto& person : people) {
        std::cout << person.name << ": " << person.age << "\n";
    }

    return 0;
}
