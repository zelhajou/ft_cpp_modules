/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:45:35 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/22 13:46:37 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n-------- Test 1: Valid Bureaucrat --------\n";
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        
        std::cout << "Incrementing grade..." << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        
        std::cout << "Decrementing grade..." << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------- Test 2: Grade Too High --------\n";
    try {
        Bureaucrat john("John", 0);
        std::cout << john << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------- Test 3: Grade Too Low --------\n";
    try {
        Bureaucrat alice("Alice", 151);
        std::cout << alice << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------- Test 4: Increment at Maximum Grade --------\n";
    try {
        Bureaucrat max("Max", 1);
        std::cout << max << std::endl;
        max.incrementGrade();
    }
    catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------- Test 5: Decrement at Minimum Grade --------\n";
    try {
        Bureaucrat min("Min", 150);
        std::cout << min << std::endl;
        min.decrementGrade();
    }
    catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}