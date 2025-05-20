/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:11 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/20 15:26:30 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	winterSoldier(void)
{
	ClapTrap soldier("Winter Soldier");
	ClapTrap copy = soldier;
	ClapTrap none;
	
	std::cout << std::endl;
	none.attack("target");
	while (soldier.getHealth())
	{
		soldier.takeDamage(3);
		soldier.beRepaired(2);
		std::cout << GREEN"Now " << soldier.getName() << " has [" << soldier.getHealth() << "] points of health" << std::endl;
		std::cout << END;
	}
	std::cout << std::endl;
}


void	captainAmerica(void)
{
	ClapTrap capi("Captain America");
	ClapTrap copy = capi;
	ClapTrap soldier("Winter Soldier");

	std::cout << std::endl;
	capi.attack("Winter Soldier");
	soldier.takeDamage(capi.getDamage());
	copy.beRepaired(7);
	std::cout << GREEN"Now " << copy.getName() << " it has [" << copy.getHealth() << "] points of health" << std::endl;
	while (capi.getEnergy())
		capi.attack("Winter Soldier");
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << std::endl <<  "\033[34mCaptain America's Performance...\033[0m" << std::endl;
	captainAmerica();
	std::cout << std::endl <<  "\033[34mWinter Soldier's Performance...\033[0m" << std::endl;
	winterSoldier();
}