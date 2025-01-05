/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:38:28 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/05 20:07:53 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i);

    std::cout << "Vector test:" << std::endl;
    try
    {
        easyfind(vec, 3);
        easyfind(vec, 6);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst;
    for (int i = 10; i <= 50; i += 10)
        lst.push_back(i);
    
    std::cout << "\n List test:" << std::endl;
    try {
        easyfind(lst, 20);
        easyfind(lst, 25);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}