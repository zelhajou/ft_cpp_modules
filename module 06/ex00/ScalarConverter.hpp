/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:09:48 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/01 17:45:29 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &copy);
    ScalarConverter &operator=(const ScalarConverter &src);

public:
    ~ScalarConverter();
    static void convert(const std::string &literal);

private:
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);

    static void convertChar(const std::string &literal);
    static void convertInt(const std::string &literal);
    static void convertFloat(const std::string &literal);
    static void convertDouble(const std::string &literal);

    static void printChar(char value);
    static void printInt(int value);
    static void printFloat(float value);
    static void printDouble(double value);
};

#endif