/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:15:54 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/23 16:10:55 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << BLUE << "-----Animal Clas-----" << END << std::endl << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "[" << meta->getType() << "]" << std::endl;
		std::cout << "[" << j->getType() << "]" << std::endl;
		std::cout << "[" << i->getType() << "]" << std::endl;

		meta->makeSound();
		j->makeSound();
		i->makeSound();

		delete i;
		delete j;
		delete meta;
		std::cout << std::endl;
	}
	{
		std::cout << BLUE << "-----Wrong Animal Clas-----" << END << std::endl << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		
		std::cout << "[" << meta->getType() << "]" << std::endl;
		std::cout << "[" << cat->getType() << "]" << std::endl;
		
		meta->makeSound();
		cat->makeSound();

		delete cat;
		delete meta;
	}
	return (0);
}
