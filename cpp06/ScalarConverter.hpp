/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:14:55 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/14 16:10:18 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARLARCONVERTER_H
# define SCARLARCONVERTER_H

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <limits>
enum dataType{
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NOTYPE
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cp);
		ScalarConverter &operator=(const ScalarConverter &op);
		~ScalarConverter();
	public:
		static void convert(std::string &param);
};

class wrongInputException : public std::exception{
	const char *what() const throw();
};

dataType sortType(const std::string &param, int len);
void msgPrint(const std::string &param);
void printInfo(dataType data, const std::string &param);

#endif