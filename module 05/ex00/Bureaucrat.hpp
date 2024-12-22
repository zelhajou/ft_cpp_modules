/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:23:38 by zelhajou          #+#    #+#             */
/*   Updated: 2024/12/22 13:53:38 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claude <claude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:03:31 by claude            #+#    #+#             */
/*   Updated: 2024/01/11 09:03:31 by claude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;

    public:
        // Orthodox Canonical Form
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& src);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& src);

        // Getters
        const std::string&  getName() const;
        int                 getGrade() const;

        // Member functions
        void incrementGrade();
        void decrementGrade();

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

// Stream operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif