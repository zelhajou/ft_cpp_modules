/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:02:48 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/05 22:41:14 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <numeric>
#include <climits>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

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

