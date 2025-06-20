/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:10:14 by yanaranj          #+#    #+#             */
/*   Updated: 2025/06/20 18:52:10 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(5){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){//what if does not have a name
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
	//std::cout << _name << ": Base Destructor Called" << std::endl;
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

void Bureaucrat::incrementGrade(int i){
	if (_grade - i < 1)
		throw GradeTooHighException();
	else
		_grade -= i;
}

void Bureaucrat::decrementGrade(int i){
	if (_grade + i > 150)
		throw GradeTooLowException();
	else
		_grade += i;
}
