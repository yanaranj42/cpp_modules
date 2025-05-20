/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:06:56 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/20 18:34:55 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default FragTrap"){
	_name = "Default FragTrap";
	_pHealth = 100;
	_pEnergy = 100;
	_pDamage = 30;
	std::cout << _name << " FragTrap has been constructed" << std::endl;
}
FragTrap::FragTrap(const std::string name) : ClapTrap(name){
	_name = name;
	_pHealth = 100;
	_pEnergy = 100;
	_pDamage = 30;
	std::cout << _name << " FragTrap has been constructed" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &op){
	if (this != &op)
	{
		_name = op.getName();
		_pHealth = op.getHealth();
		_pDamage = op.getDamage();
		_pEnergy = op.getEnergy();
	}
	return (*this);
}
FragTrap::FragTrap(const FragTrap &copy){
	*this = copy;
	std::cout << _name << "_copy FragTrap has been created..." << std::endl;
}
FragTrap::~FragTrap(){
	std::cout << _name << " FlagTrap destruction is coming..." << std::endl;
}


void FragTrap::highFivesGuys(void){
	std::cout << GREEN"> FragTrap " << _name << " raises his hand cause wants to do a HighFive with you!" << std::endl;
	std::cout << END;
}