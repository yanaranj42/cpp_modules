/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:43:41 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/05 13:34:22 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
}
Zombie::~Zombie()
{
	std::cout << "It will be better if we send " << this->name << " back to sleep" << std::endl;
	return ;
}
Zombie::Zombie()
{
	std::cout << "Oh! A zombie is coming to the living world" << std::endl;
}
void Zombie::setName(std::string name)
{
	this->name = name;
}
void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}