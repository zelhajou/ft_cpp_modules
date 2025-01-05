/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:30:24 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/03 17:06:24 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void printElement(const T& x)
{
    std::cout << x << " ";
}

template<typename T>
void incrementElement(T& x)
{
    x += 1;
}

int main()
{
    std::cout << "Testing with integers:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(int);
    
    std::cout << "Original array: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intLength, incrementElement<int>);
    
    std::cout << "After increment: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl << std::endl;


    std::cout << "Testing with doubles:" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleLength = sizeof(doubleArray) / sizeof(double);
    
    std::cout << "Original array: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl;
    
    iter(doubleArray, doubleLength, incrementElement<double>);
    
    std::cout << "After increment: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl << std::endl;

    std::cout << "Testing with strings:" << std::endl;
    std::string strArray[] = {"Hello", "World", "!"};
    size_t strLength = sizeof(strArray) / sizeof(std::string);
    
    std::cout << "String array: ";
    iter(strArray, strLength, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "\nTesting with const array:" << std::endl;
    const int constArray[] = {10, 20, 30, 40, 50};
    size_t constLength = sizeof(constArray) / sizeof(int);
    
    std::cout << "Const array: ";
    iter(constArray, constLength, printElement<const int>);
    std::cout << std::endl;

    return 0;
}