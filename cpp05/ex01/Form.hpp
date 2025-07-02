/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:50:31 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/01 12:04:36 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>


class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _signGrade;
		const int _execGrade;
	public:
	/*const/des-tructors*/
		Form();
		Form(const std::string name, int sign, int exec);
		Form(const Form &cp);
		Form &operator=(const Form &op);
		~Form();

		/*METHODS*/
		const std::string getName() const;
		const int getSignGrade() const;
		const int getExecGrade() const;
		const bool getIsSigned() const;

		void beSigned(const Bureaucrat &signer);

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
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif