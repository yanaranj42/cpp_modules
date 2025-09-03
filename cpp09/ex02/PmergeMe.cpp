/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:31 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/03 17:51:47 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cp) {
	*this = cp;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &op){
	if (this != &op)
		;
	return *this;
}

void PmergeMe::check_token(const std::string &token){
	if (!isdigit(token.at(0))){
		std::cout << RED << token << ": ";
		throw std::runtime_error("The input should be a positive number");
	}
	long long int num = 0;
	std::stringstream ss(token);
	ss >> num;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Value overflow");
	if (token.size() > 10){
		std::cout << RED << token << ": ";
		throw std::runtime_error("Invalid number format");
	}
	if (num > 0 && num <= INT_MAX){
		_vector.push_back(num);
		_deque.push_back(num);
	}
	else
		throw std::runtime_error("Something went wrong");
}

void PmergeMe::parse_input(int ac, char **av){
	if (ac == 2){
		std::stringstream ss(av[1]);
		std::string token;
		while (ss >> token)
			check_token(token);
	}
	else{
		std::cout << "here_2\n";
		for (int i = 0; i < ac; i++)
			check_token(av[i]);
	}
	std::cout << "here_3\n";
	//time to check duplicates values, maybe we can do it with a template, insted to duplicate ft for each container.
}

