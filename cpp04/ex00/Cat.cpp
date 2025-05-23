/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:24:33 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/23 16:09:53 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	_type = "Cat";
	std::cout << _type << " default Cat class is constructed" << std::endl;
}
Cat::Cat(const std::string name) : Animal(name){
	_type = name;
	std::cout << _type << " assigned Cat class constructed" << std::endl;
}
Cat::Cat(const Cat &copy){
	*this = copy;
	std::cout << _type << " copy Cat class constructed" << std::endl;
}
Cat &Cat::operator=(const Cat &op){
	if (this != &op)
		_type = op.getType();
	return (*this);
}
Cat::~Cat(void){
	std::cout << _type << " Cat class deconstructor in progress" << std::endl;
}
void Cat::makeSound(void) const{
	std::cout  << YELLOW << _type << ": meeooowww" << END << std::endl;
}
std::string Cat::getType(void) const{
	return (_type);
}