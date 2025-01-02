/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:22:51 by zelhajou          #+#    #+#             */
/*   Updated: 2025/01/02 18:33:05 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    if (isChar(literal))
        convertChar(literal);
    else if (isInt(literal))
        convertInt(literal);
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal))
        convertDouble(literal);
    else
        std::cout << "Error: Invalid input" << std::endl;
}

bool ScalarConverter::isChar(const std::string &literal)
{
    return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal)
{
    char *ptr;

    strtol(literal.c_str(), &ptr, 10);
    return (*ptr == '\0' && literal.find('.') == std::string::npos);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    char *ptr;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;

    strtof(literal.c_str(), &ptr);
    return (*ptr == 'f' && *(ptr + 1) == '\0');
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    char *ptr;

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;

    strtod(literal.c_str(), &ptr);
    return (*ptr == '\0');
}

void ScalarConverter::convertChar(const std::string &literal)
{
    char c = literal[0];

    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::convertInt(const std::string &literal)
{
    long value = strtol(literal.c_str(), NULL, 10);

    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    int i = static_cast<int>(value);
    printChar(static_cast<char>(i));
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFloat(const std::string &literal)
{
    float f = 0.0f;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
    }
    else
        f = strtof(literal.c_str(), NULL);

    {
        if (std::isnan(f) || std::isinf(f))
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(f));
    }

    {
        if (std::isnan(f) || std::isinf(f) || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            printInt(static_cast<int>(f));
    }
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::convertDouble(const std::string &literal)
{
    double d = 0.0;

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
    }
    else
        d = strtod(literal.c_str(), NULL);

    {
        if (std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(d));
    }

    {
        if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            printInt(static_cast<int>(d));
    }
    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::printChar(char value)
{
    std::cout << "char: ";
    if (std::isprint(value))
        std::cout << "'" << value << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(int value)
{
    std::cout << "int: " << value << std::endl;
}

void ScalarConverter::printFloat(float value)
{
    std::cout << "float: " << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: " << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << std::endl;
}
