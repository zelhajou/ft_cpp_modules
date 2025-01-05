/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:14:53 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/05 21:06:52 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _numbers;
         
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        ~Span();
        Span &operator=(const Span &other);

        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif