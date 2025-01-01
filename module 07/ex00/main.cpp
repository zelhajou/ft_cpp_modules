/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:21:25 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/01 21:21:33 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void)
{
    // Test with integers
    int a = 2;
    int b = 3;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << "\n";

    // Test with strings
    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    std::cout << "\n";

    // Test with floating point numbers
    float e = 42.42f;
    float f = 42.43f;

    std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

    return 0;
}