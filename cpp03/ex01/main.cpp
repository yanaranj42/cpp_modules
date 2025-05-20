/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:11 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/20 18:38:05 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	winterSoldier(void)
{
	ScavTrap soldier("Winter Soldier");
	ScavTrap copy = soldier;
	ClapTrap none;
	
	std::cout << std::endl;
	none.attack("target");
	while (soldier.getHealth())
	{
		soldier.takeDamage(20);
		soldier.beRepaired(2);
		std::cout << GREEN"Now " << soldier.getName() << " has [" << soldier.getHealth() << "] points of health" << std::endl;
		std::cout << END;
	}
	std::cout << END <<std::endl;
}


void	captainAmerica(void)
{
	ScavTrap capi("Captain America");
	ScavTrap soldier("Winter Soldier");
	ClapTrap copy = soldier;

	std::cout << std::endl;
	capi.attack("Winter Soldier");
	soldier.takeDamage(capi.getDamage());
	copy.beRepaired(1);
	while (capi.getEnergy())
	{
		capi.attack("Winter Soldier");
		if (soldier.getHealth() > 0)
		{	
			soldier.takeDamage(capi.getDamage());
			soldier.beRepaired(4);
			std::cout << YELLOW"Now " << soldier.getName() << " it has [" << soldier.getHealth() << "] points of health" << std::endl;
			std::cout << END;
		}
	}
	std::cout << END << std::endl;
}


int	main(void)
{
	std::cout << std::endl <<  "\033[34mCaptain America's Performance...\033[0m" << std::endl;
	captainAmerica();
	std::cout << std::endl <<  "\033[34mWinter Soldier's Performance...\033[0m" << std::endl;
	winterSoldier();
}