/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:29:00 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/25 15:54:57 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/*	Brief:
		First we check if we have all the arguments. If it's the case, we check
		if it's a directory or regular file.
*/
int main(int ac, char **av)
{
	BitcoinExchange mybtc;
	
	if (ac != 2){
		std::cerr << RED << "First, we will need an input.txt file.\n";
		std::cerr << "Try:" << RESET << "./btc whatever.txt\n";
		return (1);
	}
	if (!mybtc.isValidFile(av[1]))
		return (1);
	if (!mybtc.opening_file(av[1]) || mybtc.checkDir(av[1]))
		return (1);	
	try{
		mybtc.loadDataBase("data.csv");
		std::cout << YELLOW << "\n ----------------------------\n";
		std::cout << "| Ready to do the Exchange✅ |\n";
		std::cout << " ----------------------------\n\n" << RESET;
		mybtc.btcExchange(av[1]);
	}
	catch(std::exception &ex){
		std::cerr << RED << "Exception Found: " << ex.what();
	}
	return (0);
	
}