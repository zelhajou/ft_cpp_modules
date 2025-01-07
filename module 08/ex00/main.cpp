/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:38:28 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/06 19:58:43 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void printContainer(T &container, const std::string &name)
{
    std::cout << name << " contents: ";
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "\n=== Testing with vector ===" << std::endl;
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i * 10);

    printContainer(vec, "Vector");

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found value " << *it << " at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        easyfind(vec, 42);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing with list ===" << std::endl;
    std::list<int> lst;
    for (int i = 1; i <= 5; i++)
        lst.push_back(i * -5);

    printContainer(lst, "List");

    try
    {
        std::list<int>::iterator it = easyfind(lst, -15);
        std::cout << "Found value " << *it << " at position: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}