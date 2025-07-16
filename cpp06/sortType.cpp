/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:42:25 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/16 13:24:40 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string &param, int len){
	if ( len > 1 || isdigit(param.c_str()[0]))
		return (false);
	if (param[0] < 32 && param[0] > 126)
		return (false);
	return (true);
}

static bool isInt(const std::string &param, int len){
	char *endc;

	double num = strtod(param.c_str(), &endc);
	if (num < INT_MIN || num > INT_MAX){
		std::cout << "out of int limits\n";
		return (false);
	}
	if ((param[0] == '0' && len == 1) || param[len] == 'f')
		return (false);
	int i = 0;
	if (param[0] == '-' || param[0] == '+')
		i = 1;
	for (; i < len; i++){
		if (!isdigit(param.c_str()[i]))
			return (false);
	}
	return (true);
}

static bool isSpecial(const std::string &param, int len){
	if (param == "nan" || param == "nanf" || param == "-inff" || param == "-inf" \
	|| param == "+inff" || param == "+inf")
		return (true);
	if (param[0] == '0' && len == 1)
		return (true);
	if (param == "inff"){
		std::cout << RED << "You may want to add a sign first (+ || -)\n";
		return (false);
	}
	return (false);
}

static bool isFloat(const std::string &param, int len){
	char *end;
	errno = 0;
	std::cout << YELLOW << std::strtof(param.c_str(), &end) << std::endl;
	if (errno == ERANGE){
		return (false);
		std::cout << "FLOAT out of range\n";
	}
	if (*end != 'f' && *end + 1 != '\0' || param.size() <= 1)
		return (false);
	return (true);
}

static bool isDouble(const std::string &param, int len){
	char *end;
	errno = 0;
	
	std::strtod(param.c_str(), &end);
	//std::cout << GREEN << std::strtof(param.c_str(), &end) << std::endl;
	if (errno == ERANGE){
		std::cout << "double out of limit\n";
		return (false);
	}
	if ((*end != '\0' && len > 1))
	{
		std::cout << "not a digit\n";
		return (false);
	}
	return (true);
}

dataType sortType(const std::string &param, int len){
	if (isChar(param, len))
		return (CHAR);
	if (isInt(param, len))
		return (INT);
	if (isSpecial(param, len))
		return (SPECIAL);
	if (isFloat(param, len))
		return (FLOAT);
	if (isDouble(param, len))
		return (DOUBLE);
	return (NOTYPE);
	//if char: *
	/*int:42. float: 42.0f double: 42.0*/
}