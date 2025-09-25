/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:31 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/23 16:08:21 by yanaranj         ###   ########.fr       */
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

	for(; it != vector.end(); ++it){
		if (uniqueElem.insert(*it).second)
			tmp.push_back(*it);
		else{
			std::cout << *it << " ";
			throw std::runtime_error("Duplicated Vector value found ");
		}
	}
	_vector.swap(tmp);
}
void PmergeMe::check_dups(const std::deque<int> &deque){
	std::set<int> uniqueElem;
	std::deque<int> tmp;
	std::deque<int>::const_iterator it = deque.begin();

	for(; it != deque.end(); ++it){
		if (uniqueElem.insert(*it).second)
			tmp.push_back(*it);
		else{
			std::cout << *it << ": ";	
			throw std::runtime_error("Duplicated Deque value found");
		}
	}
	_deque.swap(tmp);
}

void PmergeMe::check_token(const std::string &token){
	if (!isdigit(token.at(0))){
		std::cout << RED << token << ": ";
		throw std::runtime_error("A valid value should have digits only");
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
		if (token.length() == 0)
			throw std::runtime_error("Empty Argument");
	}
	else{
		for (int i = 1; i < ac; i++)
			check_token(av[i]);
	}
	check_dups(_vector);
	check_dups(_deque);
	_OrgVector = _vector;
	_OrgDeque = _deque;
}

std::vector<int> PmergeMe::jacobsthalGenerator(int size){
	std::vector<int> jSequence;
	jSequence.push_back(0);
	jSequence.push_back(1);

	while(jSequence.back() <= size){
		int n = jSequence[jSequence.size()-1] + 2 * jSequence[jSequence.size() - 2];
		jSequence.push_back(n); 
	}
	return (jSequence);
}

/*
	 *------------------------*
	|		SORTING	VECTOR		|
	 *------------------------*
*/

void PmergeMe::insertLater(std::vector<int> &now, std::vector<int> &later){
	if (later.size() <= 1)
		return ;
	std::vector<int> jS = jacobsthalGenerator(later.size());
	std::vector<bool> inserted(later.size(), false);
	for (size_t n = jS.size() - 1; n >= 1 && n < jS.size(); --n){
		int step = jS[n];
		for(size_t i = step - 1; i < later.size(); i += step){
			if (!inserted[i]){
				binaryInsert(now, later[i]);
				inserted[i] = true;
			}
		}
	}
	for (size_t i = 0; i < later.size(); ++i){
		if (!inserted[i])
			binaryInsert(now, later[i]);
	}
}

void PmergeMe::binaryInsert(std::vector<int> &lst, int num){
	int begin = 0;
	int end = lst.size() - 1;
	while (begin <= end){
		int mid = begin + (end - begin) / 2;
		if (lst[mid] < num)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	lst.insert(lst.begin() + begin, num);
}

void PmergeMe::pairSort(std::vector<int> &lst){
	if (lst.size() < 2)
		return ;
	int odd = -1;
	if (lst.size() % 2 != 0){
		odd = lst.back();
		lst.pop_back();
	}
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < lst.size(); i += 2){
		if (i + 1 < lst.size())
			pairs.push_back(std::make_pair(lst[i], lst[i + 1]));
	}
	std::vector<int>now;
	std::vector<int>later;
	for (size_t i = 0; i < pairs.size(); ++i){
		if (pairs[i].first < pairs[i].second){
			now.push_back(pairs[i].second);
			later.push_back(pairs[i].first);
		}
		else{
			now.push_back(pairs[i].first);
			later.push_back(pairs[i].second);
		}
	}
	pairSort(now);
	if (!later.empty() && now.size() < 2)
		binaryInsert(now, later[0]);
	insertLater(now, later);
	if (odd != -1)
		binaryInsert(now, odd);
	lst = now;
}

/*
	 *------------------------*
	|		SORTING	DEQUE	   |
	 *------------------------*
*/

void PmergeMe::binaryInsert(std::deque<int> &lst, int num){
	int begin = 0;
	int end = lst.size() - 1;
	while (begin <= end){
		int mid = begin + (end - begin) / 2;
		if (lst[mid] < num)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	lst.insert(lst.begin() + begin, num);
}

void PmergeMe::insertLater(std::deque<int> &now, std::deque<int> &later){
	if (later.size() <= 1)
		return ;
	std::vector<int> jS = jacobsthalGenerator(later.size());
	std::vector<bool> inserted(later.size(), false);
	for (size_t n = jS.size() - 1; n >= 1 && n < jS.size(); --n){
		int step = jS[n];
		for(size_t i = step - 1; i < later.size(); i += step){
			if (!inserted[i]){
				binaryInsert(now, later[i]);
				inserted[i] = true;
			}
		}
	}
	for (size_t i = 0; i < later.size(); ++i){
		if (!inserted[i])
			binaryInsert(now, later[i]);
	}
}

void PmergeMe::pairSort(std::deque<int> &lst){
	if (lst.size() < 2)
		return ;
	int odd = -1;
	if (lst.size() % 2 != 0){
		odd = lst.back();
		lst.pop_back();
	}
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < lst.size(); i += 2){
		if (i + 1 < lst.size())
			pairs.push_back(std::make_pair(lst[i], lst[i + 1]));
	}
	std::deque<int>now;
	std::deque<int>later;
	for (size_t i = 0; i < pairs.size(); ++i){
		if (pairs[i].first < pairs[i].second){
			now.push_back(pairs[i].second);
			later.push_back(pairs[i].first);
		}
		else{
			now.push_back(pairs[i].first);
			later.push_back(pairs[i].second);
		}
	}
	pairSort(now);
	if (!later.empty() && now.size() < 2)
		binaryInsert(now, later[0]);
	insertLater(now, later);
	if (odd != -1)
		binaryInsert(now, odd);
	lst = now;
}