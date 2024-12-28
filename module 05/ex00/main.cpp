/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:57:31 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/27 17:16:29 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n-------- Test 1: Valid Bureaucrat --------\n";
    try
    {
        Bureaucrat sherif("Sherif", 75);
        std::cout << sherif << std::endl;
        std::cout << "Incrementing grade..." << std::endl;
        sherif.incrementGrade();
        std::cout << sherif << std::endl;
        std::cout << "Decrementing grade..." << std::endl;
        sherif.decrementGrade();
        std::cout << sherif << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------- Test 2: Grade Too High --------\n";
    try
    {
        Bureaucrat sherifa("Sherifa", 0);
        std::cout << sherifa << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------- Test 3: Grade Too Low --------\n";
    try
    {
        Bureaucrat sara("Sara", 151);
        std::cout << sara << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------- Test 4: Increment at Maximum Grade --------\n";
    try
    {
        Bureaucrat max("Max", 1);
        std::cout << max << std::endl;
        max.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------- Test 5: Decrement at Minimum Grade --------\n";
    try
    {
        Bureaucrat min("Min", 150);
        std::cout << min << std::endl;
        min.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}