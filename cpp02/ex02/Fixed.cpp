/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:24:54 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/14 14:30:41 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*CONSTRUCTORS*/
Fixed::Fixed(void)
{
	this->raw = 0;
}
Fixed::Fixed(const int num) : raw(num << bitsValue) {}
Fixed::Fixed(const float fval) : raw(roundf(fval*(1 << bitsValue))) {}
Fixed::Fixed(const Fixed &cp)
{
	this->raw = cp.raw;
}

/*FIXED POINT*/
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->raw = other.getRawBits();
	return (*this);
}

/*DESTRUCTOR*/
Fixed::~Fixed(){}

/*MEMBER FUNCTIONS*/
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

/*INSERTION FLOATING POINT OF FIXED-POINT*/
std::ostream &operator<<(std::ostream &os, const Fixed &fp)
{
	os << fp.toFloat();
	return (os);
}

/*COMPARISION OPERATORS*/
bool Fixed::operator>(const Fixed &other) const
{
	return (this->raw > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->raw < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->raw >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->raw <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->raw == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->raw != other.getRawBits());
}

/*ARITHMETIC OPERATORS*/
Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
}
Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
}
Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}
Fixed Fixed::operator/(const Fixed &other)
{
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

/*INCREMENT && DECREMENT*/
Fixed Fixed::operator++()
{
	raw++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	raw++;
	return (tmp);
}
Fixed Fixed::operator--()
{
	raw--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	raw--;
	return (tmp);
}

/*MIN && MAX*/
Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	return ((num1 < num2) ? num1:num2);
}
const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	return ((num1 < num2) ? num1:num2);
}
Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	return ((num1 > num2) ? num1:num2);
}
const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	return ((num1 > num2) ? num1:num2);
}
