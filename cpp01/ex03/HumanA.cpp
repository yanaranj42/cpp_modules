/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:11:11 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/07 19:59:50 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weaponType): name(name), weaponType(weaponType)
{
	if (this->weaponType.getType() == "")
	{
		std::cout << "> Impossible! " << name << " must wear a weapon." << std::endl;
		exit(1);
	}
	else
	{
		std::cout << "> " << name << " return after 70 years..." << std::endl;
		std::cout << "and now is armed with his " << this->weaponType.getType() << std::endl; 
	}
}
HumanA::~HumanA()
{
	std::cout << std::endl;
	std::cout << "Unnecessary Violence. Time to throw the " << this->weaponType.getType() << " away." <<std::endl;
}
void HumanA::attack()
{
	std::cout <<"> " << this->name << " attacks with his " << this->weaponType.getType()<<std::endl;
}