/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:12:22 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/30 13:38:09 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    const std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    int j = -1;
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            j = i;
            break;
        }
    }

    AForm *form = NULL;
    switch (j)
    {
    case 0:
        form = new ShrubberyCreationForm(target);
        break;
    case 1:
        form = new RobotomyRequestForm(target);
        break;
    case 2:
        form = new PresidentialPardonForm(target);
        break;
    default:
        throw FormNotFoundException();
    }

    std::cout << "Intern creates " << formName << std::endl;
    return form;
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Error: Form type not found";
}