/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:47:00 by yanaranj          #+#    #+#             */
/*   Updated: 2025/06/20 16:52:34 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &cp);
		Bureaucrat &operator=(const Bureaucrat &op);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade(int i);
		void decrementGrade(int i);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw(){
					return ("Grade too high!");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw(){
					return ("Grade too low!");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
