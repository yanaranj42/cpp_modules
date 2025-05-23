/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:10:34 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/07 19:51:45 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}
Weapon::~Weapon()
{
}
const	std::string& Weapon::getType() const
{
	return (this->type);
}
void	Weapon::setType(std::string weaponType)
{
	this->type = weaponType;
	std::cout <<"> Now he has taken his " << this->type << std::endl;
}