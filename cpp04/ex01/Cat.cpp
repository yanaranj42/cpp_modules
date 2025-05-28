/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:24:33 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/28 13:10:09 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	_type = "Cat";
	_brain = new Brain();
	_brain->_createIdeas(5, "Pfff, an annoying dog...");
	_brain->_createIdeas(10, "I'm hungy. Feed me b***h");
	std::cout << _type << " default Cat class is constructed" << std::endl;
}
Cat::Cat(const std::string name) : Animal(name){
	_type = name;
	std::cout << _type << " assigned Cat class constructed" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy){
	_type = copy._type;
	_brain = new Brain(*copy._brain);
	std::cout << _type << " copy Cat class constructed" << std::endl;
}
Cat &Cat::operator=(const Cat &op){
	if (this != &op){
		delete (_brain);
		_brain = new Brain(*op._brain);
		_type = op._type;
	}
	return (*this);
}
Cat::~Cat(void){
	delete (_brain);
	std::cout << _type << " Cat class deconstructor in progress" << std::endl;
}
void Cat::makeSound(void) const{
	std::cout  << YELLOW << _type << ": meeooowww" << END << std::endl;
}

void Cat::getIdeas() const{
	_brain->printIdeas();
}

/* std::ostream &operator<<(std::ostream &oss, const Cat &cat)//
{
	oss << "cat thinks: " << cat.getIdeas();
	return (oss);
} */