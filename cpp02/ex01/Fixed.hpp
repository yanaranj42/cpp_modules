/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:24:56 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/13 16:49:49 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
	private:
		int raw;
		static const int bitsValue = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &cp);
		Fixed &operator=(const Fixed &other);
		Fixed(const int num);
		Fixed(const float fval);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void)const;
		int toInt(void)const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fp);

#endif