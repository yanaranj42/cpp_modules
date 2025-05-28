/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:58:10 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/23 16:17:11 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Pepe el pollo") {
	_type.append("_wrong");
	std::cout << _type << " default Wrong Animal class has been constructed" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string name) : _type(name){
	_type.append("_wrong");
	std::cout << _type << " assigned Wrong Animal class has been constructed" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &cp){
	*this = cp;
	std::cout << _type << " copy WrongAnimal class constructed" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &op){
	if (this != &op)
		_type = op.getType();
	_type.append("_BOOO");
	std::cout << "hola!!!!!!!!!!!!!" << std::endl;
	return (*this);
}
std::string WrongAnimal::getType(void) const{
	return (_type);
}
WrongAnimal::~WrongAnimal(void){
	std::cout << _type << " Animal class deconstruction in progress" << std::endl;
}
void WrongAnimal::makeSound(void) const{
	std::cout << BLUE << _type << " Which animal am I?" << END << std::endl;
}