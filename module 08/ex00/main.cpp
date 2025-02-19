/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:25:45 by zelhajou          #+#    #+#             */
/*   Updated: 2025/02/18 20:39:10 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

template <typename T>
void printContainer(T &container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec;
	std::list<int> lst;

	for (int i = 1; i <= 10; i++)
	{
		vec.push_back(i * 10);
		lst.push_back(i * 5);
	}

	printContainer(vec);
	printContainer(lst);

	try
	{
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found: " << *it << std::endl;
        std::list<int>::iterator it2 = easyfind(lst, 50);
        std::cout << "Found: " << *it2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    try
	{
        std::vector<int>::iterator it = easyfind(vec, 500);
        std::cout << "Found: " << *it << std::endl;
	}
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}