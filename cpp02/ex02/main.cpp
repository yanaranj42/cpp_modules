/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:15:00 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/14 14:30:51 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout <<"[1]\t" << a << std::endl;
	std::cout <<"[2]\t" << ++a << std::endl;
	std::cout <<"[3]\t" << a << std::endl;
	std::cout <<"[4]\t" << a++ << std::endl;
	std::cout <<"[5]\t" << a << std::endl;
	std::cout <<"[6]\t" << b << std::endl;
	std::cout <<"[7]\t" << Fixed::max( a, b ) << std::endl;
	return 0;
}
