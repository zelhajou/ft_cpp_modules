/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:38:58 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/01 21:48:24 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
    T *_elements;
    unsigned int _size;

public:
    // Default constructor
    Array() : _elements(NULL), _size(0) {}

    // Constructor with size
    Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array &other) : _elements(new T[other._size]), _size(other._size)
    {
        for (unsigned int i = 0; i < _size; i++)
            _elements[i] = other._elements[i];
    }

    // Destructor
    ~Array()
    {
        delete[] _elements;
    }

    // Assignment operator
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _elements;
            _size = other._size;
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _elements[i] = other._elements[i];
        }
        return *this;
    }

    // Subscript operator
    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _elements[index];
    }

    // Const subscript operator
    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _elements[index];
    }

    // Size getter
    unsigned int size() const
    {
        return _size;
    }
};

#endif