/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:05:15 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/05 21:03:16 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

template <typename T>
void easyfind(T& container, int value)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
        std::cout << "Element " << value << " found in container" << std::endl;
    else
        throw std::runtime_error("Element not found in container");
}

#endif

