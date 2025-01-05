/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:46:55 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/03 17:20:49 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "Testing empty array:" << std::endl;
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        std::cout << "\nTesting array with size:" << std::endl;
        Array<int> numbers(5);
        std::cout << "Array size: " << numbers.size() << std::endl;

        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            numbers[i] = i * 2;
        }

        std::cout << "Array contents: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\nTesting copy constructor:" << std::endl;
        Array<int> copy(numbers);
        std::cout << "Copy array size: " << copy.size() << std::endl;
        std::cout << "Copy array contents: ";
        for (unsigned int i = 0; i < copy.size(); i++)
        {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;

        numbers[0] = 100;
        std::cout << "\nAfter modifying original array:" << std::endl;
        std::cout << "Original array: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Copy array: ";
        for (unsigned int i = 0; i < copy.size(); i++)
        {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\nTesting assignment operator:" << std::endl;
        Array<int> assigned = numbers;
        std::cout << "Assigned array size: " << assigned.size() << std::endl;
        std::cout << "Assigned array contents: ";
        for (unsigned int i = 0; i < assigned.size(); i++)
        {
            std::cout << assigned[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\nTesting out of bounds exception:" << std::endl;
        try
        {
            numbers[10] = 0;
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << "\nTesting with string type:" << std::endl;
        Array<std::string> strings(3);
        strings[0] = "Hello";
        strings[1] = "World";
        strings[2] = "!";
        for (unsigned int i = 0; i < strings.size(); i++)
        {
            std::cout << strings[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}