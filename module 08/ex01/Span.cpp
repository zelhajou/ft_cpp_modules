/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:02:48 by zelhajou          #+#    #+#             */
/*   Updated: 2025/02/16 21:36:18 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Orthodox Canonical Form Implementation
Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N)
{
    // Reserve capacity to avoid reallocations
    _numbers.reserve(N);
}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

// Member Functions Implementation
void Span::addNumber(int num)
{
    if (_numbers.size() >= _N)
        throw std::out_of_range("Span is full");
    _numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to find span");

    // Create a sorted copy for easier span calculation
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    // Find minimum difference between adjacent elements
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        minSpan = std::min(minSpan, span);
    }

    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to find span");

    // Find min and max elements
    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> result =
        std::minmax_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(*result.second - *result.first);
}