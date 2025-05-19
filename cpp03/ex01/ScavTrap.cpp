/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:47:47 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/19 13:23:50 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default ScavTrap")
{
	ClapTrap("Default ScavTrap");
	_name = "Default ST";
	_pHealth = 100;
	_pEnergy = 50;
	_pDamage = 20;
	std::cout << "> " << _name << " has been constructed..." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
	_name = name;
	_pHealth = 100;
	_pEnergy = 50;
	_pDamage = 20;
	std::cout << "> " << _name << " ScavTrap has been constructed..." << std::endl;
}
ScavTrap &ScavTrap::operator=(ScavTrap const &op){
	if (this != &op)
	{
		_name = op.getName();
		_pHealth = op.getHealth();
		_pDamage = op.getDamage();
		_pEnergy = op.getEnergy();
	}
	return (*this);
}
ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other){
	*this = other;
	std::cout << "ST copy created "<< std::endl;
}
ScavTrap::~ScavTrap(){
	std::cout << "Deconstructing ScavTrap..." << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper Mode." << std::endl;
}
void ScavTrap::attack(const std::string &target){
	if (_pEnergy > 0 && _pHealth > 0)
	{
		_pEnergy--;
		std::cout << _name << " st, attacks " << target << " with " << _pDamage;
		std::cout << " point(s) of damage." << std::endl;
	}
	if (_pEnergy <= 0)
		std::cout << ">" << _name << " has low Level of energy for attack right now." << std::endl;
	if (_pHealth <= 0)
		std::cout << ">" << _name << " is near to death" << std::endl;
}
