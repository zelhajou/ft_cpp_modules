#include <iostream>
#include <string>

// Basic Class Definition
class Animal {
private:
    std::string name;
    int age;

protected:
    bool isHealthy;

public:
    // Constructors
    Animal() : name("Unknown"), age(0), isHealthy(true) {
        std::cout << "Animal default constructor called\n";
    }
    
    Animal(const std::string& n, int a) : name(n), age(a), isHealthy(true) {
        std::cout << "Animal parameterized constructor called\n";
    }
    
    // Copy constructor
    Animal(const Animal& other) : name(other.name), age(other.age), isHealthy(other.isHealthy) {
        std::cout << "Animal copy constructor called\n";
    }
    
    // Destructor
    virtual ~Animal() {
        std::cout << "Animal destructor called\n";
    }

    // Getters and Setters
    std::string getName() const { return name; }
    void setName(const std::string& n) { name = n; }
    int getAge() const { return age; }
    void setAge(int a) { age = a; }

    // Virtual function for polymorphism
    virtual void makeSound() const {
        std::cout << "Some generic animal sound\n";
    }

    // Pure virtual function (makes Animal an abstract class)
    virtual void move() const = 0;

    // Static member
    static int animalCount;
    static int getAnimalCount() { return animalCount; }
};

// Initialize static member
int Animal::animalCount = 0;

// Derived class (inheritance)
class Dog : public Animal {
private:
    std::string breed;

public:
    // Constructor with initialization list
    Dog(const std::string& name, int age, const std::string& b) 
        : Animal(name, age), breed(b) {
        animalCount++;
        std::cout << "Dog constructor called\n";
    }

    // Destructor
    ~Dog() override {
        animalCount--;
        std::cout << "Dog destructor called\n";
    }

    // Override virtual functions
    void makeSound() const override {
        std::cout << "Woof!\n";
    }

    void move() const override {
        std::cout << "Dog is running on four legs\n";
    }

    // Additional methods
    std::string getBreed() const { return breed; }
};

// Multiple inheritance example
class Flyable {
public:
    virtual void fly() const {
        std::cout << "Flying...\n";
    }
    virtual ~Flyable() = default;
};

class Bird : public Animal, public Flyable {
public:
    Bird(const std::string& name, int age) : Animal(name, age) {
        animalCount++;
        std::cout << "Bird constructor called\n";
    }

    ~Bird() override {
        animalCount--;
        std::cout << "Bird destructor called\n";
    }

    void makeSound() const override {
        std::cout << "Chirp!\n";
    }

    void move() const override {
        std::cout << "Bird is hopping\n";
    }

    void fly() const override {
        std::cout << "Bird is flying\n";
    }
};

// Friend function example
class Box {
private:
    double width, height, depth;

public:
    Box(double w, double h, double d) : width(w), height(h), depth(d) {}
    friend double getVolume(const Box& box);
};

// Friend function definition
double getVolume(const Box& box) {
    return box.width * box.height * box.depth;
}

// Template class example
template<typename T>
class Container {
private:
    T data;

public:
    Container(T value) : data(value) {}
    T getValue() const { return data; }
    void setValue(T value) { data = value; }
};

int main() {
    std::cout << "=== Class and Object Basics ===\n";
    
    // Cannot create Animal object directly (abstract class)
    Dog dog("Rex", 3, "German Shepherd");
    std::cout << "Dog name: " << dog.getName() << "\n";
    std::cout << "Dog breed: " << dog.getBreed() << "\n";
    dog.makeSound();
    dog.move();

    std::cout << "\n=== Polymorphism ===\n";
    Animal* animal_ptr = &dog;
    animal_ptr->makeSound();  // Calls Dog's makeSound()

    std::cout << "\n=== Multiple Inheritance ===\n";
    Bird bird("Tweety", 1);
    bird.makeSound();
    bird.move();
    bird.fly();

    std::cout << "\n=== Friend Function ===\n";
    Box box(2.0, 3.0, 4.0);
    std::cout << "Box volume: " << getVolume(box) << "\n";

    std::cout << "\n=== Template Class ===\n";
    Container<int> intContainer(42);
    Container<std::string> strContainer("Hello");
    std::cout << "Int container value: " << intContainer.getValue() << "\n";
    std::cout << "String container value: " << strContainer.getValue() << "\n";

    std::cout << "\n=== Static Members ===\n";
    std::cout << "Total animals: " << Animal::getAnimalCount() << "\n";

    return 0;
}
