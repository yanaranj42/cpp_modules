/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:53:38 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/07 14:15:36 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(_target, 25, 5), _target("Default") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(target, 25, 5), _target(target){
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cp){
	*this = cp;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &op){
	if (this != &op){
		AForm::operator=(op);
		_target = op.getTarget();
	}
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm(){}


std::string PresidentialPardonForm::getTarget() const{
	return (this->_target);
}

void PresidentialPardonForm::execAction() const{
	std::cout << this->_target << ", you have been pardoned by Zaphod Beeblebrox 😇." << std::endl;
}