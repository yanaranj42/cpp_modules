/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:53:35 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/02 15:46:12 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av){
	
	RPN myRPN;
	if (ac != 2){
		std::cerr << RED << "Please introduce an input like:\n";
		std::cerr << BLUE << "$> ./RPN \"1 2 * 2 / 2 * 2 4 - +\" \n";
		return 1;
	}
	try{
		if (myRPN.parse_input(av[1]))
			myRPN.doRPN(av[1]);
		else{
			std::cerr << RED << "Invalid input\n";
			return 1;
		}
	}
	catch(std::exception &ex){
		std::cerr << RED << "Exception Caught: " << ex.what() << "\n";
		std::cerr << BLUE << "Input example: ";
		std::cerr << "$> ./RPN \"1 2 * 2 / 2 * 2 4 - +\" \n" << RESET;
		return 1;
	}
	return 0;
}