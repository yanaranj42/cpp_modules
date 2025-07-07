/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:50:31 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/07 13:08:22 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _signGrade;
		const int _execGrade;
	public:
	/*const/des-tructors*/
		AForm();
		AForm(const std::string name, int sign, int exec);
		AForm(const AForm &cp);
		AForm &operator=(const AForm &op);
		virtual ~AForm();

		/*METHODS*/
		const std::string getName() const;
		const int getSignGrade() const;
		const int getExecGrade() const;
		const bool getIsSigned() const;

		void beSigned(const Bureaucrat &signer);
		void execute(Bureaucrat const &executor) const;
		virtual void execAction() const = 0;//to execute the action in Request & Pardon Form?

		/*EXCEPTIONS*/

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormAlreadySigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif