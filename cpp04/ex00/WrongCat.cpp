/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:24:33 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/23 15:33:50 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void){
	_type = "Cat";
	_type.append("_wrong");
	std::cout << _type << " default Wrong_Cat class is constructed" << std::endl;
}
WrongCat::WrongCat(const std::string name) : WrongAnimal(name){
	_type = name;
	std::cout << _type << "assigned Wrong_Cat class is constructed" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy){
	*this = copy;
	std::cout << _type << " copy Wrong_Cat class is constructed" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &op){
	if (this != &op)
		_type = op.getType();
	_type.append("_copy");
	std::cout << "hola!!!!!!!!!!!!!" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void){
	std::cout << _type << " Cat class deconstruction in progress..." << std::endl;
}

std::string WrongCat::getType(void) const{
	return (_type);
}
void WrongCat::makeSound(void) const {
	std::cout  << BLUE << _type << " miauuuuuu" << END << std::endl;
}