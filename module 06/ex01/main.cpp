/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:20:49 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/02 19:25:38 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->name = "test";
    data->value = 42;

    std::cout << "Original data - Address: " << data << ", Name: " << data->name << ", Value: " << data->value << std::endl;

    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized: " << serialized << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized data - Address: " << deserialized << ", Name: " << deserialized->name << ", Value: " << deserialized->value << std::endl;

    std::cout << "Pointers are equal: " << (data == deserialized ? "true" : "false") << std::endl;

    delete data;
    return 0;
}