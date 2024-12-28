/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:37:19 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/27 16:45:10 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat highGrade("HighGrade", 1);
        Bureaucrat midGrade("MidGrade", 50);
        Bureaucrat lowGrade("LowGrade", 150);

        std::cout << "\n-------- Test ShrubberyCreationForm --------\n";
        {
            ShrubberyCreationForm shrub("garden");
            std::cout << shrub << std::endl;

            std::cout << "\nTesting with low grade bureaucrat:\n";
            lowGrade.signForm(shrub);
            lowGrade.executeForm(shrub);

            std::cout << "\nTesting with mid grade bureaucrat:\n";
            midGrade.signForm(shrub);
            midGrade.executeForm(shrub);
        }

        std::cout << "\n-------- Test RobotomyRequestForm --------\n";
        {
            RobotomyRequestForm robotomy("Target1");
            std::cout << robotomy << std::endl;

            // Test with mid grade bureaucrat (should partially succeed)
            std::cout << "\nTesting with mid grade bureaucrat:\n";
            midGrade.signForm(robotomy);
            midGrade.executeForm(robotomy);  // Should fail - grade too low

            // Test with high grade bureaucrat (should succeed)
            std::cout << "\nTesting with high grade bureaucrat:\n";
            highGrade.executeForm(robotomy);
        }

        std::cout << "\n-------- Test PresidentialPardonForm --------\n";
        {
            PresidentialPardonForm pardon("Criminal1");
            std::cout << pardon << std::endl;

            // Test without signing first (should fail)
            std::cout << "\nTesting execution without signature:\n";
            highGrade.executeForm(pardon);

            // Test complete process with high grade bureaucrat
            std::cout << "\nTesting complete process with high grade bureaucrat:\n";
            highGrade.signForm(pardon);
            highGrade.executeForm(pardon);
        }

        std::cout << "\n-------- Test Invalid Grade Creation --------\n";
        try {
            Bureaucrat tooHigh("TooHigh", 0);
        }
        catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Bureaucrat tooLow("TooLow", 151);
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