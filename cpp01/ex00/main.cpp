/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:17:20 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/01 18:50:52 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main()
{
	{
		Zombie zombie_s("Stack_Zombie");
		zombie_s.announce();
		std::cout << std::endl;
		Zombie *zombie_h = new Zombie("Heap_Zombie");
		zombie_h->announce();
		std::cout << std::endl;
		delete zombie_h;
	}
	std::cout << std::endl;
	{
		randomChump("Boo_Zombie");
		std::cout << std::endl;
		//Zombie *zombie_re = new Zombie("Re_Zombie");
		//zombie_re->announce();
		//delete zombie_re;
	}
	return (0);
}