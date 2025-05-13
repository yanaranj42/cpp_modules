/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:24:56 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/13 14:01:19 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int bitsValue = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &cp);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif