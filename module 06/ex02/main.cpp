/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:37:50 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/01 18:37:58 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main()
{
    Base *base = generate();

    std::cout << "Identifying using pointer: ";
    identify(base);

    std::cout << "Identifying using reference: ";
    identify(*base);

    delete base;

    // Test with explicit types
    std::cout << "\nTesting explicit types:" << std::endl;

    Base *a = new A();
    std::cout << "Type A - Pointer identification: ";
    identify(a);
    std::cout << "Type A - Reference identification: ";
    identify(*a);
    delete a;

    Base *b = new B();
    std::cout << "Type B - Pointer identification: ";
    identify(b);
    std::cout << "Type B - Reference identification: ";
    identify(*b);
    delete b;

    Base *c = new C();
    std::cout << "Type C - Pointer identification: ";
    identify(c);
    std::cout << "Type C - Reference identification: ";
    identify(*c);
    delete c;

    return 0;
}