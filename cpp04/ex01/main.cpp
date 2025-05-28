/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:15:54 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/28 13:14:39 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define SIZE 6

int main()
{
	{
		std::cout << BLUE << "-----Array of Animals-----" << END << std::endl << std::endl;
		Animal *anim[SIZE];
		for (int i = 0; i < SIZE; i++){
			std::cout << GREEN << "[" << i << "] " << END;
			if (i % 2 == 0)
				anim[i] = new Dog();
			else
				anim[i] = new Cat();
			anim[i]->makeSound();
			std::cout << std::endl;
		}
		std::cout << BLUE << "-----Let's delete everything-----" << END << std::endl << std::endl;
		for (int i = 0; i < SIZE; i++){
			std::cout << GREEN << "[" << i << "] " << END;
			delete anim[i];
		}
		std::cout << std::endl;
	}
	{
		std::cout << BLUE << "-----Deep Animal copy-----" << END << std::endl << std::endl;
		Cat *a = new Cat();
		Cat *gat = new Cat(*static_cast<const Cat*>(a));
		a->getIdeas();
		a->makeSound();
		gat->makeSound();
		
		std::cout << std::endl;
		
		Dog *b = new Dog();
		Dog *gos = new Dog (*static_cast<const Dog*>(b));
		b->getIdeas();
		b->makeSound();
		gos->makeSound();
		
		std::cout << std::endl;
		
		delete a;
		delete gat;
		delete b;
		delete gos;
	}
	return (0);
}
