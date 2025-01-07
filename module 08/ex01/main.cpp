/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:15:46 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/06 18:18:23 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void testBasicFunctionality() {
    std::cout << "\n=== Testing Basic Functionality ===\n";
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testLargeNumbers() {
    std::cout << "\n=== Testing with 10,000 Numbers ===\n";
    try {
        Span sp(10000);
        std::vector<int> numbers;
        std::srand(std::time(NULL));

        // Generate random numbers
        for (int i = 0; i < 10000; i++) {
            numbers.push_back(rand());
        }

        // Add using range
        sp.addRange(numbers.begin(), numbers.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testExceptions() {
    std::cout << "\n=== Testing Exceptions ===\n";
    
    // Test adding to full span
    try {
        Span sp(1);
        sp.addNumber(5);
        sp.addNumber(10); // Should throw
    }
    catch (const std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }
}

int main() {
    testBasicFunctionality();
    testLargeNumbers();
    testExceptions();
    return 0;
}