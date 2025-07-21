/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:39:36 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/17 12:50:36 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &cp){
	(void) cp;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &op){
	(void)op;
	return(*this);
}
ScalarConverter::~ScalarConverter(){}

void printInfo(dataType data, const std::string &param){

	char *end = 0;
	std::cout << std::fixed << std::setprecision(3);
	if (data == CHAR){
		std::cout << RED;
		std::cout << "char: '" << param << "'\n";
		std::cout << "int: " << static_cast<int>(param.at(0)) << "\n";
		std::cout << "float: " << static_cast<float>(param.at(0)) << "f\n";
		std::cout << "double: " << static_cast<double>(param.at(0)) << "\n";
	}
	if (data == INT){
		std::cout << BLUE;
		int num = atoi(param.c_str());
		if (num >= 32 && num <= 126)
			std::cout << "char: '" <<  static_cast<char>(num) << "'\n";
		else
			std::cout << "char: Impossible\n";
		std::cout << "int: " << num << "\n";
		std::cout << "float: " << static_cast<float>(num) << "f\n";
		std::cout << "double: " << static_cast<double>(num) << "\n";
	}
	if (data == FLOAT){
		std::cout << GREEN;	
		float num = std::strtof(param.c_str(), &end);
		if (num >= 32.0 && num <= 126.0)
			std::cout << "char: '" <<  static_cast<char>(num) << "'\n";
		else
			std::cout << "char: Impossible\n";
		if (num < INT_MIN || num > INT_MAX)
			std::cout << "int: Impossible\n";
		else
			std::cout << "int: " << static_cast<int>(num) << "\n";
		std::cout << "float: " << static_cast<float>(num) << "f\n";
		std::cout << "double: " << static_cast<double>(num) << "\n";
	}
	if (data == DOUBLE){
		std::cout << YELLOW;
		double num = std::strtod(param.c_str(), &end);
		if (num >= 32.0 && num <= 126.0)
			std::cout << "char: '" << static_cast<char>(num) << "'\n";
		else
			std::cout << "char: Impossible\n";
		if (num < INT_MIN || num > INT_MAX)
			std::cout << "int: Impossible\n";
		else
			std::cout << "int: " << static_cast<int>(num) << "\n";
		if (num < -FLT_MAX || num > FLT_MAX)
			std::cout << "float: Impossible\n";
		else
			std::cout << "float: " << static_cast<float>(num) << "f\n";
		std::cout << "double: " << static_cast<double>(num) << "\n";
	}
}

void ScalarConverter::convert(std::string &param){

	dataType data= sortType(param, param.length());
	switch (data)
	{
	case SPECIAL:
		msgPrint(param);
		break;
	case NOTYPE:
		throw wrongInputException();
		break;
	default:
		printInfo(data, param);
		break;
	}
}

const char *wrongInputException::what() const throw(){
	return ("Invalid Input");
}

void msgPrint(const std::string &param){
	if (param == "nan" || param == "nanf"){
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if(param == "-inff" || param == "-inf"){
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
	else if(param == "+inff" || param == "+inf"){
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else if(param[0] == '0'){
		std::cout << "char: Non displayable\n";
		std::cout << "int: 0\n";
		std::cout << "float: 0.0f\n";
		std::cout << "double: 0.0\n";
	}
}
