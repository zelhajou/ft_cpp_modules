/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:22:51 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/31 19:50:13 by zelhajou         ###   ########.fr       */
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