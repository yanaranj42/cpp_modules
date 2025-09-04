/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:31 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/04 17:12:08 by yanaranj         ###   ########.fr       */
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

std::vector<int> &PmergeMe::getVector() { return (this->_vector); }
std::vector<int> &PmergeMe::getOrgVector() { return (this->_OrgVector); }
std::deque<int> &PmergeMe::getDeque() { return (this->_deque); }
std::deque<int> &PmergeMe::getOrgDeque() { return (this->_OrgDeque); }

/*
	 *-------------------------*
	|			PARSING			|
	 *-------------------------*
*/

void PmergeMe::check_dups(const std::vector<int> &vector){
	std::set<int> uniqueElem;
	std::vector<int> tmp;
	std::vector<int>::const_iterator it = vector.begin();

	for(; it != vector.end(); it++){
		if (uniqueElem.insert(*it).second)
			tmp.push_back(*it);
		else{
			std::cout << *it << " ";//number duplicated
			throw std::runtime_error("Duplicated Vector value found ");
		}
	}
	_vector.swap(tmp);
	std::cout << GREEN << "vectors are ok\n";
}
void PmergeMe::check_dups(const std::deque<int> &deque){
	std::set<int> uniqueElem;
	std::deque<int> tmp;
	std::deque<int>::const_iterator it = deque.begin();

	for(; it != deque.end(); it++){
		if (uniqueElem.insert(*it).second)
			tmp.push_back(*it);
		else{
			std::cout << *it << ": ";	
			throw std::runtime_error("Duplicated Deque value found");
		}
	}
	_deque.swap(tmp);
	std::cout << MAGENTA << "deques are ok\n";
}

void PmergeMe::check_token(const std::string &token){
	if (!isdigit(token.at(0))){
		std::cout << RED << token << ": ";
		throw std::runtime_error("A valid value should have digits only");//?
	}
	long long int num = 0;
	std::stringstream ss(token);
	ss >> num;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Invalid number format");
	if (token.size() > 10){
		std::cout << YELLOW << token << ": ";
		throw std::runtime_error("Cannot process this value");
	}
	if (num > 0 && num <= INT_MAX){
		_vector.push_back(num);
		_deque.push_back(num);
	}
	else if (num == 0)
		throw std::runtime_error("Zero is an invalid value");
	else
		throw std::runtime_error("Value overflow");
}

void PmergeMe::parse_input(int ac, char **av){
	if (ac == 2){
		std::stringstream ss(av[1]);
		std::string token;
		while (ss >> token)
			check_token(token);
		if (token.length() == 0)//we check before because we assign the token value in the while loop
			throw std::runtime_error("Empty Argument");
	}
	else{
		std::cout << "here_2\n";
		for (int i = 0; i < ac; i++)
			check_token(av[i]);
	}
	check_dups(_vector);
	check_dups(_deque);
	_OrgVector = _vector;
	_OrgDeque = _deque;
}

/*
	 *------------------------*
	|			SORTING			|
	 *------------------------*
*/

void PmergeMe::insertionSort(const std::vector<int> &lst){
	//we'll be sorting the vector STL
}

void PmergeMe::insertionSort(const std::deque<int> &lst){
	//we'll be sorting the deque STL
}