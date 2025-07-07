/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:01:15 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/07 17:53:05 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

enum Action {SCF, RRF, PPF, UNK};

Intern::Intern(){}
Intern::Intern(const Intern &cp){
	*this = cp;		
}
Intern &Intern::operator=(const Intern &op){
	(void)op;
	return (*this);
}
Intern::~Intern(){}

Action formLvl(std::string formName){

	if (formName == "shrubbery creation")
		return SCF;
	else if (formName == "robotomy request")
		return RRF;
	else if (formName == "presidential pardon")
		return PPF;
	std::cout << "No matches found!" << std::endl;
	return (UNK);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget){
	AForm *form = NULL;
	switch (formLvl(formName))
	{
	case SCF:
		form = new ShrubberyCreationForm(formTarget);
		break;
	case RRF:
		form = new RobotomyRequestForm(formTarget);
		break;
	case PPF:
		form = new PresidentialPardonForm(formTarget);
		break;
	default:
		throw noFormException();
	}
	std::cout << "Intern creates " << formName << " form." << std::endl;
	return (form);
}
const char *Intern::noFormException::what() const throw(){
	return ("This form does not exist.");
}