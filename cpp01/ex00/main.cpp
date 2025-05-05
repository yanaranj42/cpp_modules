/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:17:20 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/05 12:23:49 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

/*	the stacked zombie will call Z constructor, that displays the name and msg
	in the *Z we use 'new' in order to allocate memory for this zombie. And the
	delete operator frees the memory that was used in *Z.

	Random has the same process as constructor, the difference is that this one
	announce itself
	Whe use brackets 'cause we want to star and end one process each time
*/

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
		Zombie *newZ = newZombie("New_Zombie");
		newZ->announce();
		delete newZ;
		std::cout << std::endl;	
	}
	return (0);
}