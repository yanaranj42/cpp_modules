/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:51:02 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/07 17:06:47 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern{
	public:
		Intern();
		Intern(const Intern &cp);
		Intern &operator=(const Intern &op);
		~Intern();
	
		AForm *makeForm(std::string formName, std::string formTarget);
		class noFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif