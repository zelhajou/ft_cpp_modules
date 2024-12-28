/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:12:35 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/27 17:12:37 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try {
        Intern intern;
        Bureaucrat bureaucrat("John", 1);

        std::cout << "\n-------- Test Valid Form Creation --------\n";
        {
            AForm* form = intern.makeForm("robotomy request", "Bender");
            if (form) {
                bureaucrat.signForm(*form);
                bureaucrat.executeForm(*form);
                delete form;
            }
        }

        std::cout << "\n-------- Test All Form Types --------\n";
        {
            AForm* shrub = intern.makeForm("shrubbery creation", "Garden");
            AForm* pres = intern.makeForm("presidential pardon", "Criminal");
            
            bureaucrat.signForm(*shrub);
            bureaucrat.executeForm(*shrub);
            
            bureaucrat.signForm(*pres);
            bureaucrat.executeForm(*pres);
            
            delete shrub;
            delete pres;
        }

        std::cout << "\n-------- Test Invalid Form Name --------\n";
        try {
            AForm* form = intern.makeForm("invalid form", "Target");
            if (form) {
                delete form;
            }
        }
        catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}