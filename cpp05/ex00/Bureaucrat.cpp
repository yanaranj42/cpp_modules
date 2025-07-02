/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:10:14 by yanaranj          #+#    #+#             */
/*   Updated: 2025/06/30 18:27:39 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(80){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (name.empty())
		_name = "John Doe";
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &cp){
	*this = cp;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &op){
	if (this != &op)
	{
		_name = op.getName();
		_name.append("_copy");
		_grade = op.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "\n" << _name << ": Base Destructor Called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

std::string Bureaucrat::getName() const{
	return (_name);
}
int Bureaucrat::getGrade() const{
	return (_grade);
}

void Bureaucrat::incrementGrade(){
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		--_grade;
	std::cout << _name <<  ": downgraded to: [" << _grade << "]" << std::endl;
}

void Bureaucrat::decrementGrade(){
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		++_grade;
	std::cout << _name << ": upgraded to: " << _grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too low!");
}