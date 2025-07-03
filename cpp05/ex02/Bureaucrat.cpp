/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:10:14 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/03 19:31:45 by yanaranj         ###   ########.fr       */
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
	std::cout << _name << ": Base Destructor Called" << std::endl;
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
	return ("Bureaucrat Grade too high!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Bureaucrat Grade too low!");
}

void Bureaucrat::signForm(AForm &form) const{
	try{
		form.beSigned(*this);
		std::cout << _name << " signed form: " << form.getName() << "!" << std::endl;
	}
	catch(std::exception &ex){
		std::cerr << _name << " couldn't sign " << form.getName() << " beause " << ex.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const{
	try{
		form.execute(*this);
		std::cout << form.getName() << " has been executed successfully! ✅" << std::endl;
	}
	catch(std::exception &ex){
		std::cout << _name << " cannot executed " << form.getName() << std::endl;
	}
}
