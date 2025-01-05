/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:30:11 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/03 17:07:24 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

template<typename T>
void iter(const T* array, size_t length, void (*func)(const T&))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif