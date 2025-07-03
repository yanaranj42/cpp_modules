/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:53:38 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/03 19:19:45 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cp){
	*this = cp;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op){
	if (this != &op){
		AForm::operator=(op);
		_target = op.getTarget();
	}
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}


std::string ShrubberyCreationForm::getTarget() const{
	return (_target);
}

void ShrubberyCreationForm::execAction() const{
	std::string fileName = this->getTarget();
	fileName.append("_shrubbery");
	
	std::ofstream outfile(fileName.c_str());
	if (!outfile.is_open()){
		throw std::runtime_error("Cannot open this file");
	}

	outfile << "    /\\   " << std::endl
			<< "   /**\\  " << std::endl
			<< "  /****\\ " << std::endl
			<< " /******\\" << std::endl
			<< "/********\\" << std::endl
			<< "    ||   " << std::endl
			<< "    ||   " << std::endl;

	outfile.close();
	
	std::cout << "Shrubbery created at file: " << fileName << std::endl;
}