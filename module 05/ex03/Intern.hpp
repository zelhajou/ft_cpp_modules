/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:12:08 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/27 17:15:27 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        typedef AForm *(Intern::*FormCreator)(const std::string &);
        struct FormType
        {
            std::string name;
            FormCreator creator;
        };

        AForm *createShrubberyForm(const std::string &target);
        AForm *createRobotomyForm(const std::string &target);
        AForm *createPresidentialForm(const std::string &target);

        static FormType formTypes[3];

    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);

        AForm *makeForm(const std::string &formName, const std::string &target);

        class FormNotFoundException : public std::exception
        {
        public:
            const char *what() const throw();
        };
};

#endif