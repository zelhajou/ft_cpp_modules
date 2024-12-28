/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:33:32 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/25 16:54:32 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <vector>

int main()
{
    try
    {
        std::cout << "\n-------- Test 1: Valid Form Creation --------\n";
        Form form1("Tax Form", 50, 30);
        std::cout << form1 << std::endl;

        std::cout << "\n-------- Test 2: Invalid Grade (Too High) --------\n";
        try
        {
            Form form2("Invalid Form", 0, 30);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n-------- Test 3: Invalid Grade (Too Low) --------\n";
        try
        {
            Form form3("Invalid Form", 50, 151);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n-------- Test 4: Form Signing (Success) --------\n";
        Bureaucrat sherif("Sherif", 40);
        Form form4("Contract", 50, 30);
        std::cout << "Before signing:\n"
                  << form4 << std::endl;
        sherif.signForm(form4);
        std::cout << "After signing:\n"
                  << form4 << std::endl;

        std::cout << "\n-------- Test 5: Form Signing (Failure) --------\n";
        Bureaucrat sherifa("Sherifa", 100);
        Form form5("Classified Document", 20, 10);
        std::cout << "Before signing:\n"
                  << form5 << std::endl;
        sherifa.signForm(form5);
        std::cout << "After signing attempt:\n"
                  << form5 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}