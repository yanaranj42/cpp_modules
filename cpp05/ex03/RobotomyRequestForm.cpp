/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:53:38 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/03 18:26:08 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cp){
	*this = cp;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &op){
	if (this != &op){
		AForm::operator=(op);
		_target = op.getTarget();
	}
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(){}


std::string RobotomyRequestForm::getTarget() const{
	return (_target);
}

void RobotomyRequestForm::execAction() const{
	std::cout << "🔩 Drilling noises... 🔩" << std::endl;
	if (std::rand() % 2)
		std::cerr << "❌ Oh no! Robotomy process failed... ❌" << std::endl;
	else
		std::cout << "Hehe!😼 Robotomy process was a success🤖 " << std::endl;
}
