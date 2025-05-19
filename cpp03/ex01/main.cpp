/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:11 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/19 13:26:05 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	alice_rundown(void)
{
	ScavTrap alice("Alice");

	while (alice.getEnergy())
	{
		alice.attack("Target");
	}
	alice.guardGate();
}

void	bob_rundown(void)
{
	ScavTrap	bob("Bob");

	while (bob.getHealth())
	{
		bob.takeDamage(20);
		bob.beRepaired(10);
	}
	bob.takeDamage(1);
	bob.guardGate();
}

int	main(void)
{
	std::cout << std::endl << std::endl << "\033[34mPerforming Alice's rundown...\033[0m" << std::endl << std::endl;
	alice_rundown();
	std::cout << std::endl << std::endl << "\033[34mPerforming Bob's rundown...\033[0m" << std::endl << std::endl;
	bob_rundown();
}