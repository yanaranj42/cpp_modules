/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:42:25 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/14 16:11:41 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool check_limits(const std::string &param, int len, int flag){
	std::istringstream iss(param);
	if (flag == 1){//limits de INT
		int value = 0;
		iss >> value;
		//std::cout << value << "\n";
		return !iss.fail();
	}
	if (flag == 2){//limits double
		double value = 0;
		iss >> value;
	    //std::cout << "Maximum double value: " << std::numeric_limits<double>::max() << std::endl;
	    //std::cout << "Minimum double value: " << std::numeric_limits<double>::min() << std::endl;
		return !iss.fail();
	}
	if (flag == 3){//limits floats
		float value = 0;
		iss >> value;
		//std::cout << value << "\n";
		return !iss.fail();
	}
	return (true);
}

static bool isChar(const std::string &param, int len){
	if ( len > 1 || isdigit(param.c_str()[0]))
		return (false);
	if (param[0] < 32 && param[0] > 126)
		return (false);
	return (true);
}

static bool isInt(const std::string &param, int len){
	if (( param[0] == '0' && len == 1) || param[len] == 'f')
		return (false);
	int i = 0;
	if (param[0] == '-' || param[0] == '+')
		i = 1;
	for (; i < len; i++){
		if (!isdigit(param.c_str()[i]))
			return (false);
	}
	if (!check_limits(param, len, 1))
		return (false);
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
	if (param[len - 1] != 'f')
		return (false);
	int counter = 0;
	int i = 0;
	if (param[0] == '-' || param[0] == '+')
		i = 1;
	for (; i < len; i++){
		if (!isdigit(param.c_str()[i])){
			if (param[i] == '.')
				counter++;
			else if (param[i] != 'f')
				return (false);
			else if(param[i] == 'f' && i != len - 1)
				return (false);
		}
	}
	if (counter != 1)
		return (false);
	if (!check_limits(param, len, 3))
		return (false);
	return (true);
}

static bool isDouble(const std::string &param, int len){
	if (param[len - 1] == 'f')
		return (false);
	int counter = 0;
	int i = 0;
	if (param[0] == '-' || param[0] == '+')
		i = 1;
	for (; i < len; i++){
		if (!isdigit(param.c_str()[i])){
			if (param[i] == '.')
				counter++;
			else
				return (false);
		}
	}
	if (counter != 1)
		return (false);
	if (!check_limits(param, len, 2))
		return (false);
	//std::cout << "Is Double!\n";
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