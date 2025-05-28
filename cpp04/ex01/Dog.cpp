/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:24:35 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/28 13:12:10 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	_type = "Dog";
	_brain = new Brain();
	_brain->_createIdeas(5, "Sometimes, cats hates me :(");
	_brain->_createIdeas(10, "Look! Is a ball!!!!");
	std::cout << _type << " default Dog class is constructed" << std::endl;
}
Dog::Dog(const std::string name) : Animal(name){
	_type = name;
	std::cout << _type << " assigned Dog class is been constructed" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal (copy){
	_type = copy._type;
	_brain = new Brain(*copy._brain);
	std::cout << _type << " copy Dog class is been constructed" << std::endl;
}
Dog &Dog::operator=(const Dog &op){
	if (this != &op){
		delete (_brain);
		_brain = new Brain(*op._brain);
		_type = op._type;
	}
	return (*this);
}
Dog::~Dog(void){
	delete (_brain);
	std::cout << _type << " Dog class deconstructor in progress" << std::endl;
}
void Dog::makeSound(void) const{
	std::cout << YELLOW << _type << ": wuaf wuaf" << END << std::endl;
}
void Dog::getIdeas() const{
	_brain->printIdeas();
}