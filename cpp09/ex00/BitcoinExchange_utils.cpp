/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_utils.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:05:45 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/23 16:23:58 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::validDate(std::string &date){
	if (date.length() != 10)
		return false;
	if (date.at(4) != '-' || date.at(7) != '-')	
		return false;
	for (int i = 0; i < 10; i++){
		if (i == 4 ||  i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	int year, month, day;
	try{
		year = atoi((date.substr(0, 4)).c_str());
		month = atoi((date.substr(5, 7)).c_str());
		day = atoi((date.substr(8,10)).c_str());
		if (year < 0 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
			return false;
	}
	catch(std::exception &ex){
		std::cerr << RED  << "Exception: " << ex.what() << "\n";
	}
	return true;
}

float BitcoinExchange::validRate(std::string &rate){
	int dot = 0;
	if (rate[0] == '-')
		return -1;
	for(unsigned long i = 0; i < rate.size(); i++){
		if (rate[i] == '.'){
			dot++;
			if (dot > 1 || rate.at(rate.size() - 1) == '.')
				return -1;
	
		}
		else if(!isdigit(rate[i]))
			return -1;

	}
	std::stringstream rateF(rate);
	float op = 0;
	rateF >> op;
	if (rateF.fail()){
		std::cerr << RED << "Invalid Rate float value\n";
		return (-1);
	}
	return (op);
}

float BitcoinExchange::validAmount(std::string &amount){
	int dot = 0;
	if  (amount[0] == '-'){
		std:: cerr << RED << "Error: not a positive amount: " << amount  << "\n" << RESET;
		return (-1);
	}
	for (unsigned int i = 0; i < amount.size(); i++){
		if (amount[i] == '.'){
			dot++;
			if (dot > 1 || amount.at(amount.size() - 1) == '.'){
				std::cerr << RED << "Amount bad formated: " << amount  << "\n"  << RESET;
				return (-1);
			}
		}
		else if (!isdigit(amount[i])){
			std::cerr << RED << "This amount is not a digit: " << amount  << "\n"  << RESET;
			return (-1);
		}
	}
	std::stringstream amountF(amount);
	float op = 0;
	amountF >> op;
	if (amountF.fail()){
		std::cerr << RED << "Invalid float value\n" << RESET;
		return (-1);
	}
	if (op > 1000 || op == 0){	
		std::cerr << RED << "Ivalid amout value: " << amount << "\n" << RESET;
		return (-1);
	}
	return (op);
}

bool BitcoinExchange::isValidFile(const std::string &filename){
	if (filename.length() >= 4)
		return (filename.substr(filename.length() - 4) == ".txt" \
		|| filename.substr(filename.length() - 4) == ".csv");
	return false;
}

int BitcoinExchange::checkDir(const char *path){
	struct stat pathStat;
    if (stat(path, &pathStat) != 0){
        std::cerr << "Error: " << strerror(errno) << "\n";
        return 1;
    }
    if (S_ISDIR(pathStat.st_mode)){
        std::cerr << RED << "Directorys are not allowed. ";
		return (1);
	}
	return (0);
}

void BitcoinExchange::printFinal(std::string &date, float op, float res) const {
	std::cout << date << " => " << op << " = " << (date < "2010-08-20" ? 0 : res) << "\n";
}