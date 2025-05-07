/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:10:34 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/07 19:07:30 by yanaranj         ###   ########.fr       */
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

/* Weapon &Weapon::operator=(const Weapon &other)
{
	this->type = other.type;
	return (*this);
} */
const	std::string& Weapon::getType() const
{
	return (this->type);
}
void	Weapon::setType(std::string weaponType)
{
	this->type = weaponType;
	std::cout <<"> Now he has taken his " << this->type << std::endl;
}