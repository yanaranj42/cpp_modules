/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:17:37 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/23 16:08:52 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Paco el Pato"){
	std::cout << _type << " default Animal class is been constructed" << std::endl;
}
Animal::Animal(const std::string type) : _type(type){
	std::cout << _type << " assigned Animal class is been constructed" << std::endl;
}
Animal::Animal(const Animal &copy){
	*this = copy;
	std::cout << _type << " copy Animal class is been constructed" << std::endl;
}
Animal &Animal::operator=(const Animal &op){
	if (this != &op)
		_type = op.getType();
	//std::cout << "holaaaaaaaaaaa" << std::endl;
	return (*this);
}
Animal::~Animal(void){
	std::cout << _type << " is calling deconstructor..." << std::endl;
}
void Animal::makeSound(void) const{
	std::cout << YELLOW << "Who am I?" << END << std::endl;
}
std::string Animal::getType(void) const{
	return (_type);
}