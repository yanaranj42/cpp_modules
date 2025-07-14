/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:43:02 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/14 16:15:43 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **argv)
{

	/*check double and float conversion. Noot sure if is the way*/
	if (ac != 2)
	{
		std::cout << RED <<"Expected: "<< RESET << "./conversion 'argv'" << std::endl;
		return (1);
	}
	std::string data = argv[1];
	try{
		ScalarConverter::convert(data);
	}
	catch(std::exception &ex){
		std::cout << RED"FOUND: " << ex.what() << "!" << RESET << std::endl;
	}
	return (0);
}