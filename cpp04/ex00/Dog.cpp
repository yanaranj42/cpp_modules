/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:24:35 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/23 16:10:08 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	_type = "Dog";
	std::cout << _type << " default Dog class is constructed" << std::endl;
}
Dog::Dog(std::string name) : Animal(name){
	std::cout << _type << " assigned Dog class is been constructed" << std::endl;
}
Dog::Dog(const Dog &copy){
	*this = copy;
	std::cout << _type << " copy Dog class is been constructed" << std::endl;
}
Dog &Dog::operator=(const Dog &op){
	if (this != &op)
		_type = op.getType();
	return (*this);
}
Dog::~Dog(void){
	std::cout << _type << " Dog class deconstructor in progress" << std::endl;
}
void Dog::makeSound(void) const{
	std::cout << YELLOW << _type << ": wuaf wuaf" << END << std::endl;
}
std::string Dog::getType(void) const{
	return (_type);
}