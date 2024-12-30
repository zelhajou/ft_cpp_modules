/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:15:21 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/29 19:52:06 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);

    std::string filename = _target + "_shrubbery";
    std::ofstream outFile(filename.c_str());

    if (!outFile.is_open())
        throw FileOpenException();

    outFile << "         v" << std::endl;
    outFile << "        >X<" << std::endl;
    outFile << "         A" << std::endl;
    outFile << "        d$b" << std::endl;
    outFile << "      .d\\$$b." << std::endl;
    outFile << "    .d$i$$\\$$b." << std::endl;
    outFile << "       d$$@b" << std::endl;
    outFile << "      d\\$$$ib" << std::endl;
    outFile << "    .d$$$\\$$$b" << std::endl;
    outFile << "  .d$$@$$$$\\$$ib." << std::endl;
    outFile << "      d$$i$$b" << std::endl;
    outFile << "     d\\$$$$@$b" << std::endl;
    outFile << "  .d$@$$\\$$$$$@b." << std::endl;
    outFile << ".d$$$$i$$$\\$$$$$$b." << std::endl;
    outFile << "        ###" << std::endl;
    outFile << "        ###" << std::endl;
    outFile << "        ###" << std::endl;

    outFile.close();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "Could not open file for writing";
}
