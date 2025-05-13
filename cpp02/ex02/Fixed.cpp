/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:24:54 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/13 18:59:25 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num) : raw(num << bitsValue)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float fval) : raw(roundf(fval*(1 << bitsValue)))
{
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &cp)
{
	std::cout << "Copy constructor called" << std::endl;	
	this->raw = cp.raw;
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called "	<<std::endl;
	if (this != &other)
		this->raw = other.getRawBits();
	return (*this);
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
	return (this->raw);
}
void Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}
float Fixed::toFloat(void)const
{
	return (float(this->raw) / (1 << bitsValue));
}
int Fixed::toInt(void)const
{
	return (this->raw >> bitsValue);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fp)
{
	os << fp.toFloat();
	return (os);
}