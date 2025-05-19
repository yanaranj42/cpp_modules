/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:24:54 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/13 14:01:13 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &cp)
{
	std::cout << "Copy constructor called" << std::endl;	
	this->value = cp.value;
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called "	<<std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}
Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}


int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return (this->value);
}
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
