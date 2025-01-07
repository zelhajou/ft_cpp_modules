/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:14:53 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/06 18:15:59 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <iterator>

class Span {
private:
    unsigned int _N;              // Maximum capacity
    std::vector<int> _numbers;    // Container for numbers

public:
    // Orthodox Canonical Form
    Span();                              // Default constructor
    explicit Span(unsigned int N);       // Parameterized constructor
    Span(const Span& other);            // Copy constructor
    ~Span();                            // Destructor
    Span& operator=(const Span& other); // Assignment operator

    // Member functions
    void addNumber(int num);            // Add a single number
    unsigned int shortestSpan() const;   // Find shortest span
    unsigned int longestSpan() const;    // Find longest span

    // Template function for range addition
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        // Calculate distance to check capacity
        typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
        if (distance > static_cast<long>(_N - _numbers.size()))
            throw std::out_of_range("Not enough capacity for range");

        // Add numbers from range
        _numbers.insert(_numbers.end(), begin, end);
    }

    // Utility functions
    size_t size() const { return _numbers.size(); }
    size_t capacity() const { return _N; }
};

#endif