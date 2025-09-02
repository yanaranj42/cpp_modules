/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:54:04 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/02 15:56:21 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

#include <iostream>
#include <stack>
#include <exception>
#include <sstream>
#include <climits>

class RPN
{
	private:
		std::stack<long long int> _rpnStack;
	public:
		RPN();
		RPN(const RPN &cp);
		RPN &operator=(const RPN &op);
		~RPN();

		/*methods*/
		bool isOperand(char op);
		bool parse_input(const std::string &input);
		void doRPN(const std::string &input);

		bool num_conversion(const std::string &token, long long int &num);

};

#endif