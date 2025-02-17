#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (numbers.size() >= N)
        throw std::runtime_error("Span is full");
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const 
{
    if (numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to find span");
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int span = static
    }
}