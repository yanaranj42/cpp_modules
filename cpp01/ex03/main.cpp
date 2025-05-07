/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:06:01 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/07 19:48:57 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
/* 
int main()
{
	{
		Weapon weapon = Weapon("shield");
		HumanA capitanAmerica("Capitan America", weapon);
		capitanAmerica.attack();
		weapon.setType("knife");
		capitanAmerica.attack();
	}
	std::cout << std::endl;
	{
		Weapon metal = Weapon("Sword Arm");
		HumanB soldier("Winter Soldier");
		soldier.setWeapon(metal);
		soldier.attack();
		metal.setType("Vibranium Arm");
		soldier.attack();
	}
	return 0;
} */

int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
return 0;
}