/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:05:30 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/25 15:52:11 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sys/stat.h>
#include <cerrno>
#include <cstring>
#include <sstream> //stringstream
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _btcDB;//key-value STL
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cp);
		BitcoinExchange &operator=(const BitcoinExchange &op);
		~BitcoinExchange();

		//Methods
		bool loadDataBase(const std::string &file);
		void btcExchange(const std::string &file);
		
		int checkDir(const char *path);//avoiding directorys
		bool isValidFile(const std::string &filename);
		bool opening_file(const std::string &filename);
		
		/*parsing lines*/
		bool validDate(std::string &date);
		float validRate(std::string &rate);
		float validAmount(std::string &amount);
		/*Exchange operations && final resultt*/
		float doOperations(std::string &date, float op);
		void printFinal(std::string &date, float op, float res) const;
};


#endif