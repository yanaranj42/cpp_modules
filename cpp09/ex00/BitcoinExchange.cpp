/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:05:28 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/25 12:14:23 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp){
	*this = cp;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &op){
	if (this != &op)
		this->_btcDB = op._btcDB;
	return (*this);
}
BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::opening_file(const std::string &filename){
	
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()){
		std::cerr << RED << "Error opening " << filename << "\n";
		return false;
	}
	return (true);
}

bool BitcoinExchange::loadDataBase(const std::string &file){

	std::string line;
	std::ifstream db_file(file.c_str());
	if(!opening_file(file)){
		throw std::runtime_error("Error opening Data Base file\n");
	}
	bool first_line = true;
	
	while (std::getline(db_file, line)){
		if (first_line){
			if (line != "date,exchange_rate")
				throw std::runtime_error("Data Base first line in a bad format\n");
			first_line = false;
			continue;
		}
		std::stringstream ss(line);
		std::string date;
		std::string rate;
		if (line.empty()){
			std::cerr  << RED << "Bad data base format: Empty line\n";
			continue;
		}
		if (!std::getline(ss, date, ',') || !validDate(date)){
			std::cerr << RED << "Bad date format: " << date << "\n";
			continue;
		}
		if (!std::getline(ss, rate)){
			std::cerr << RED << "Bad rate Format: " << rate << "\n";
			continue;
		}
		float rateStr = validRate(rate);
		if (rateStr == -1){
			std::cerr << RED << "Invalid Rate Format: " << line << RESET << "\n";
			continue;
		}
		else{
			std::pair<std::string, float> dataRate = std::make_pair(date, rateStr);
			_btcDB.insert(dataRate);
		}		
	}
	return (true);
}

float BitcoinExchange::doOperations(std::string &date, float op)
{
	std::map<std::string, float>::iterator it = _btcDB.begin();
	
	for (; it != _btcDB.end() && it->first <= date; ++it){
		if (it->first == date)
			return it->second * op;
	}
	if (it == _btcDB.begin()){
		std::cerr << RED << "No data available before " << date << "\n" << RESET;
		return -1;
	}
	if (it == _btcDB.end()){
		--it;
		return it->second * op;
	}
	if (it->first > date){
		--it;
		return it->second * op;
	}
	return -1;
}

void BitcoinExchange::btcExchange(const std::string &file){
	std::ifstream input_file(file.c_str());
	
	std::string str;
	bool first_line = true;
	while (std::getline(input_file, str)){
		std::string line(str);
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		if (first_line){
			if (line != "date|value")
				throw std::runtime_error("Input file: first line in a bad format\n");
			first_line = false;
			continue;
		}
		std::stringstream ss(line);
		std::string date;
		std::string amount;
		if(line.empty()){
			std::cerr << RED << "Bad format input: Empty line\n" << RESET;
			continue;
		}
		if (!std::getline(ss, date, '|') || !validDate(date)){
			std::cerr << RED << "Wrong Date format: " << date << "\n" << RESET;
			continue;
		}
		if (!std::getline(ss, amount) || amount.empty()){
			std::cerr << RED << "Is necessary to introduce an amout\n";
			continue;
		}
		float op = validAmount(amount);
		if (op == -1)
			continue;
		float result = doOperations(date, op);
		if (result == -1)
			continue;
		printFinal(date, op, result);
	}
}