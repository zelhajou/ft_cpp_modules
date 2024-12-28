/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:12:22 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/27 17:15:40 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::FormType Intern::formTypes[3] = {
    {"shrubbery creation", &Intern::createShrubberyForm},
    {"robotomy request", &Intern::createRobotomyForm},
    {"presidential pardon", &Intern::createPresidentialForm}};

Intern::Intern() {}
Intern::Intern(const Intern &src) { (void)src; }
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

AForm *Intern::createShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formTypes[i].creator)(target);
        }
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form type not found";
}