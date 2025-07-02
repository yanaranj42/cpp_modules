/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:10:14 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/02 17:21:37 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _is_signed(false),_signGrade(2), _execGrade(4){}

Form::Form(const std::string name, const int sign, const int exec) : _name(name), _is_signed(false), _signGrade(sign), _execGrade(exec){
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}
Form::Form(const Form &cp) : _name(cp.getName()), _is_signed(false), _signGrade(cp.getSignGrade()), _execGrade(cp.getExecGrade()){
	*this = cp;
}
Form &Form::operator=(const Form &op){
	//a constant object cannot be modified
	if (this != &op)
		return (*this);
	return (*this);
}

Form::~Form(){
	std::cout << _name << ": Form Destructor Called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Form &form){
	std::cout << form.getName() << ":\t -sign grade: " << form.getSignGrade();
	std::cout << "\n\t -is signed?: " << form.getIsSigned();
	std::cout << "\n\t -exec grade: " << form.getExecGrade() << std::endl;
	return (out);
}

const std::string Form::getName() const{
	return (_name);
}
const int Form::getSignGrade() const{
	return (_signGrade);
}
const int Form::getExecGrade() const{
	return (_execGrade);
}
const bool Form::getIsSigned() const{
	return (_is_signed);
}

void Form::beSigned(const Bureaucrat &signer){ //cannot be const because we want to change the boolean value
	if (signer.getGrade() > _signGrade){
		throw Bureaucrat::GradeTooLowException();
	}
	else if (_is_signed == true)
		std::cout << _name << ": has already been signed" << std::endl;
	else
	{
		_is_signed = true;
		std::cout << _name << ": has succesfully sign by " << signer.getName() << std::endl;
	}
}
const char *Form::GradeTooLowException::what() const throw(){
	return ("Form Grade too low!");
}
const char *Form::GradeTooHighException::what()const throw(){
	return ("Form Grade to high!");
}