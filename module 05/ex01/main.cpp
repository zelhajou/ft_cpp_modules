/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:31:49 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/22 16:34:04 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        std::cout << "\n-------- Test 1: Valid Form Creation --------\n";
        Form form1("Tax Form", 50, 30);
        std::cout << form1 << std::endl;

        std::cout << "\n-------- Test 2: Invalid Grade (Too High) --------\n";
        try {
            Form form2("Invalid Form", 0, 30);
        }
        catch(const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n-------- Test 3: Invalid Grade (Too Low) --------\n";
        try {
            Form form3("Invalid Form", 50, 151);
        }
        catch(const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n-------- Test 4: Form Signing (Success) --------\n";
        Bureaucrat bob("Bob", 40);
        Form form4("Contract", 50, 30);
        std::cout << "Before signing:\n" << form4 << std::endl;
        bob.signForm(form4);
        std::cout << "After signing:\n" << form4 << std::endl;

        std::cout << "\n-------- Test 5: Form Signing (Failure) --------\n";
        Bureaucrat jim("Jim", 100);
        Form form5("Classified Document", 20, 10);
        std::cout << "Before signing:\n" << form5 << std::endl;
        jim.signForm(form5);
        std::cout << "After signing attempt:\n" << form5 << std::endl;

        std::cout << "\n-------- Test 6: Form Copy --------\n";
        Form form6(form4);  // Copy constructor
        std::cout << "Copied form:\n" << form6 << std::endl;

        std::cout << "\n-------- Test 7: Form Assignment --------\n";
        Form form7("Empty Form", 100, 100);
        form7 = form4;  // Assignment operator
        std::cout << "Assigned form:\n" << form7 << std::endl;

    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}