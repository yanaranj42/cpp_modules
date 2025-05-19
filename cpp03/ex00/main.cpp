/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:11 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/19 11:39:47 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a("Boo");
		ClapTrap b;
		ClapTrap c(a);

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("-some other robot-");
		c.attack("-Shi-");
		a.takeDamage(5);
		a.takeDamage(15);
		a.beRepaired(2);
		a.attack("-some other other robot-");
		b.beRepaired(3);
		b.attack("-Boo-clone-");
		for (int i = 0; i < 10; i++)
			b.beRepaired(1);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}