/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:21:29 by zelhajou          #+#    #+#             */
/*   Updated: 2025/02/19 00:52:09 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
    // Test 1
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Test 1" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Test 2
    {
        Span bigSp = Span(10000);
        std::vector<int> numbers;

        std::srand(std::time(0));
        for (int i = 0; i < 10000; i++)
            numbers.push_back(std::rand());

        try
        {
            bigSp.addNumber(numbers.begin(), numbers.end());
            std::cout << "Test 2" << std::endl;
            std::cout << "Shortest span: " << bigSp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << bigSp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    // Test 3
    {
        Span empty = Span(5);
        try
        {
            empty.shortestSpan();
        }
        catch (const std::exception &e)
        {
            std::cout << "Test 3" << std::endl;
            std::cout << e.what() << std::endl;
        }

        Span full(2);
        try
        {
            full.addNumber(1);
            full.addNumber(2);
            full.addNumber(3);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}