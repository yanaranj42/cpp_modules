/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:10:14 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/03 19:35:10 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _is_signed(false),_signGrade(2), _execGrade(4){}

AForm::AForm(const std::string name, const int sign, const int exec) : _name(name), _is_signed(false), _signGrade(sign), _execGrade(exec){
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm &cp) : _name(cp.getName()), _is_signed(false), _signGrade(cp.getSignGrade()), _execGrade(cp.getExecGrade()){
	*this = cp;
}
AForm &AForm::operator=(const AForm &op){
	if (this != &op)
		return (*this);
	return (*this);
}

AForm::~AForm(){
	std::cout << _name << ": AForm Destructor Called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const AForm &form){
	std::cout << form.getName() << ":\t -sign grade: " << form.getSignGrade();
	std::cout << "\n\t -is signed?: " << form.getIsSigned();
	std::cout << "\n\t -exec grade: " << form.getExecGrade() << std::endl;
	return (out);
}

const std::string AForm::getName() const{
	return (_name);
}
const int AForm::getSignGrade() const{
	return (_signGrade);
}
const int AForm::getExecGrade() const{
	return (_execGrade);
}
const bool AForm::getIsSigned() const{
	return (_is_signed);
}

void AForm::beSigned(const Bureaucrat &signer){ //cannot be const because we want to change the boolean value
	if (signer.getGrade() > _signGrade){
		throw Bureaucrat::GradeTooLowException();
	}
	else if (_is_signed == true)
		throw FormAlreadySigned();
	else
	{
		_is_signed = true;
		std::cout << _name << ": has succesfully sign by " << signer.getName() << std::endl;
	}
}

void AForm::execute(Bureaucrat const &executor) const{

	(void)executor;
	if (!_is_signed)
		throw FormNotSigned();
	if (_execGrade < executor.getGrade())
		throw GradeTooLowException();
	this->execAction();
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("AForm Grade too low!");
}
const char *AForm::GradeTooHighException::what()const throw(){
	return ("AForm Grade to high!");
}
const char *AForm::FormAlreadySigned::what() const throw(){
	return ("This form has already been signed");
}
const char *AForm::FormNotSigned::what() const throw(){
	return ("Form has not been signed yet");
}