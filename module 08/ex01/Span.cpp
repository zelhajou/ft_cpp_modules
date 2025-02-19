#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other) : N(other.N), _numbers(other._numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= N)
        throw std::runtime_error("Span is full");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to calculate span");
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = UINT_MAX;

    for (size_t i = 1; i < sorted.size(); i++)
    {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;

}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to calculate span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    return static_cast<unsigned int>(sorted.back() - sorted.front());
}