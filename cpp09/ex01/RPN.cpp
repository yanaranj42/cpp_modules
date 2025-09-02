/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:08:47 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/02 15:53:30 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &cp){
	*this = cp;
}

RPN &RPN::operator=(const RPN &op){
	if (this != &op)
		this->_rpnStack = op._rpnStack;
	return *this;
}

RPN::~RPN(){}

bool RPN::isOperand(char op){
	if (op != '+' && op != '-' && op != '*' && op != '/')
		return false;
	return true;
}

bool RPN::parse_input(const std::string &input){
	if (input.empty())
		return false;
	for (unsigned int i = 0; i < input.size(); i++){
		if (!isdigit(input[i])){
			if (!isOperand(input[i]) && !isspace(input[i])){
				throw std::runtime_error ("Error");
				return false;
			}
		}
	}
	return true;
}

bool RPN::num_conversion(const std::string &token, long long int &num){
	
	std::stringstream ss(token);
	ss >> num;
	if (ss.fail() || !ss.eof())
		return false;
	if (num < 0 || num > 9)
		return false;
	return true;

}

void  RPN::doRPN(const std::string &input){
	std::stringstream ss(input);
	std::string token;
	
	while (ss >> token){
		long long int num = 0;
		long long op_a = 0;
		long long op_b = 0;
		if ((token[0] == '-' || token[0] == '+') && token[1] != '\0'){
			throw std::runtime_error ("No need to use signs");
			return;
		}
		if (isdigit(token.at(0))){
			if (!num_conversion(token, num)){
				throw std::runtime_error("Introduce values from 0 to 9");
				return;
			}
			_rpnStack.push(num);
		}
		else if (isOperand(token.at(0))){
			if (_rpnStack.size() >= 2){
				if (token.at(0) == '+'){
					op_a = _rpnStack.top();
					_rpnStack.pop();
					op_b = _rpnStack.top();
					_rpnStack.pop();
					op_a += op_b;
					if (op_a > INT_MIN && op_a < INT_MAX)
						_rpnStack.push(op_a);
					else
						throw std::range_error ("Operation out of INT limits\n");
				}
				if (token.at(0) == '-'){
					op_a = _rpnStack.top();
					_rpnStack.pop();
					op_b = _rpnStack.top();
					_rpnStack.pop();
					op_a = op_b - op_a;
					if (op_a > INT_MIN && op_a < INT_MAX)
						_rpnStack.push(op_a);
					else
						throw std::range_error ("Operation out of INT limits\n");
				}
				if (token.at(0) == '*'){
					op_a = _rpnStack.top();
					_rpnStack.pop();
					op_b = _rpnStack.top();
					_rpnStack.pop();
					op_a *= op_b;
					if (op_a > INT_MIN && op_a < INT_MAX)
						_rpnStack.push(op_a);
					else
						throw std::range_error ("Operation out of INT limits\n");
				}
				if (token.at(0) == '/'){
					op_a = _rpnStack.top();
					_rpnStack.pop();
					op_b = _rpnStack.top();
					_rpnStack.pop();
					if (op_a != 0){
						op_a = op_b / op_a;
						_rpnStack.push(op_a);
					}
					else
						throw std::runtime_error("Division by 0");
				}
			}
			else
				throw std::runtime_error("Not enough operators");
		}
	}
	if (_rpnStack.size() == 1)
		std::cout << GREEN << _rpnStack.top() << "\n";
	else
		throw std::runtime_error("Not enough operands");
	return;
}