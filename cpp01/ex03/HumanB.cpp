/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:11:37 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/07 19:39:17 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weaponType(NULL)
{
	//this->name = name;
	std::cout << "> " << name << " appears in misteriuos circumstances" << std::endl;
}
HumanB::~HumanB()
{
	std::cout << std::endl;
	std::cout << "Unnecessary Violence. Hydra will be destroyed." << std::endl;
}
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weaponType = &weapon;
	if (this->weaponType->getType() == "")
		std::cout << "> " << this->name << " is not wearing a weapon." << std::endl;
	else
		std::cout << "> " << this->name << " has armed an " << this->weaponType->getType() << std::endl;
}
void HumanB::attack()
{
	if (this->weaponType->getType() == "")
		std::cout << "> He cannot attack." << std::endl;
	else
		std::cout <<"> " << this->name << " attacks with his " << this->weaponType->getType() <<std::endl;
}