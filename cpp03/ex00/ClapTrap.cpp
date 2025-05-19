/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:01 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/19 11:37:13 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*CONSTRUCTORS*/
ClapTrap::ClapTrap(void) : _name("Default"), _pHealth(10), _pEnergy(10), _pDamage(0){
	std::cout << _name << " ClapTrap has been constructed" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _pHealth(10), _pEnergy(10), _pDamage(0){
	std::cout << _name << " ClapTrap has been constructed" << std::endl;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &op){
	if (this != &op)
	{
		_name = op.getName();
		_pHealth = op.getHealth();
		_pDamage = op.getDamage();
		_pEnergy = op.getEnergy();
	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const &copy){
	std::cout << "Copia creada " << std::endl;
	*this = copy;//este llamara al operador de cp que tiene los valores de los atributos iniciados
}

ClapTrap::~ClapTrap(){
	std::cout << "Calling ClapTrap Destructor" << std::endl;
}

/*FUNCTIONS*/
void ClapTrap::attack(const std::string &target)
{
	if (_pEnergy > 0 && _pHealth > 0)
	{
		_pEnergy--;
		std::cout << YELLOW"CT " << _name << " attacks " << target << " causing ";
		std::cout << _pDamage << " point of damage." << std::endl;
		std::cout << END;
	}
	if (_pEnergy <= 0)
		std::cout << "No Energy Points left" << std::endl;
	if (_pHealth <= 0)
		std::cout << _name << " can't attack from the tomb." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_pHealth > 0)
	{
		std::cout << RED"CT " << _name << " has been attacked and gets ";
		std::cout << amount << " points of damage." << std::endl;
		_pHealth -= amount;
		std::cout << END;
	}
	else
		std::cout << RED"CT " << _name << " is not longer with us." << END << std::endl;
	if (_pHealth < 0)
		_pHealth = 0;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_pEnergy > 0 && _pHealth > 0)
	{
		std::cout << GREEN"CT " << _name << " wants to rapair " << amount;
		std::cout << " point(s) of health" << std::endl;
		std::cout << END;
		_pHealth += amount;
		_pEnergy--;
	}
	if (_pEnergy <= 0)
	{
		std::cout << "CT " << _name << " has no energy to do a repair" << std::endl;
		_pEnergy = 0;
	}
	else if (_pHealth == 0)
		std::cout << "Ghosts cannot Repair from the tomb." << std::endl;
}

/*GETTER && SETTERS*/

void ClapTrap::setName(std::string const name){
	this->_name = name;	
}
void	ClapTrap::setHealth(int &value){
	this->_pHealth = value;
}
void	ClapTrap::setEnergy(int &value){
	this->_pEnergy = value;
}
void	ClapTrap::setDamage(int &value){
	this->_pDamage = value;
}

const std::string &ClapTrap::getName(void) const{
	return (this->_name);
}
const int &ClapTrap::getHealth(void) const{
	return (this->_pHealth);
}
const int &ClapTrap::getEnergy(void) const{
	return (this->_pEnergy);
}
const int &ClapTrap::getDamage(void) const{
	return (this->_pDamage);
}