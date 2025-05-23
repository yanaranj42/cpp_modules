/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:11 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/22 17:21:33 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


void	winterSoldier(void)
{
	FragTrap soldier("Winter Soldier");
	ScavTrap capi("Captain America");
	ClapTrap copy = soldier;
	FragTrap none;
	std::cout <<std::endl;
	
	none.attack(copy.getName());
	while (none.getEnergy())
	{
		none.attack(soldier.getName());
		if (copy.getHealth() > 0)
		{
			copy.takeDamage(none.getDamage());
			copy.beRepaired(15);
		}
	}
	FragTrap loki("Loki");
	std::cout << END << "OMG! That was only a clone...";
	std::cout << "The whole time, the realone was... " << loki.getName() << std::endl;
	std::cout << capi.getName() << " just wants to say Hi!" << std::endl;
	loki.highFivesGuys();
}


void	captainAmerica(void)
{
	FragTrap capi("Captain America");
	ScavTrap soldier("Winter Soldier");
	ClapTrap copy = soldier;
	std::cout << std::endl;
	capi.attack(soldier.getName());
	soldier.takeDamage(capi.getDamage());
	soldier.attack(capi.getName());
	capi.takeDamage(soldier.getDamage());
	std::cout << capi.getName() << " prevent the attack with his shield" << std::endl;
	capi.beRepaired(10);
	std::cout << capi.getName() << " still has [" << capi.getHealth() << "] point of health" <<std::endl;
	std::cout << std::endl;
	std::cout << copy.getName() << "_copy seams to be preparing something..." << std::endl << std::endl;
	while (capi.getHealth())
	{
		soldier.attack(capi.getName());
		capi.takeDamage(20);
	}
	soldier.guardGate();
	std::cout << END << std::endl;
}



int	main(void)
{
	std::cout << std::endl <<  "\033[34mCaptain America's Performance...\033[0m" << std::endl;
	captainAmerica();
	std::cout << std::endl <<  "\033[34mWinter Soldier's Performance...\033[0m" << std::endl;
	winterSoldier();
}