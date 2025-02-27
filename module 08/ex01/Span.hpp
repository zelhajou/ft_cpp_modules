#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
private:
    unsigned int N;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();
    Span &operator=(const Span &other);

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            addNumber(*begin);
            begin++;
        }
    }
};

#endif