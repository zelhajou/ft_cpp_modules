/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:12:35 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/30 16:45:01 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        std::cout << "\n----- Test 1: Create and execute Shrubbery Creation Form -----\n";
        {
            AForm *form = intern.makeForm("shrubbery creation", "home");
            if (form)
            {
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
        }

        std::cout << "\n----- Test 2: Create and execute Robotomy Request Form -----\n";
        {
            AForm *form = intern.makeForm("robotomy request", "moulinex");
            if (form)
            {
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
        }

        std::cout << "\n----- Test 3: Create and execute Presidential Pardon Form -----\n";
        {
            AForm *form = intern.makeForm("presidential pardon", "prisoner");
            if (form)
            {
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
        }

        std::cout << "\n----- Test 4: Try to create an invalid form -----\n";
        {
            try
            {
                AForm *form = intern.makeForm("invalid form", "target");
                if (form)
                    delete form;
            }
            catch (std::exception &e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}