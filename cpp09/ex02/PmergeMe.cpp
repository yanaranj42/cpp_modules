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
	|		SORTING	VECTOR		|
	 *------------------------*
*/


//this will seach in wich part of the vector the number is. If is in the first or second part, and then will insert the number in the correct postion

std::vector<int> PmergeMe::jacobsthalGenerator(int size){
	std::vector<int> jSequence;
	jSequence.push_back(0);
	jSequence.push_back(1);

	//std::cout << BLUE << jSequence.size() << "\n";
	while(jSquence.back() <= size){
		int n = jSequence[jSquence.size()-1] + 2 * jSequence[jSequence.size() - 2];
		jSequence.push_back(n); 
	}
	return (jSequence);
}


void PmergeMe::insertLater(std::vector<int> &now, std::vector<int> &later){
	if (later.size() <= 1)
		return ;
	std::vector<int> jS = jacobsthalGenerator(later.size());//generate JS numbers
	std::vector<bool> inserted(later.size(), false);//check if that nbr has been inserted in now vector
	//vv insertion according JS pattern. The loop goes backward through the nbrs in an optimal form
	for (size_t n = jS.size() - 1; n >= 1 && n < jS.size(); --n){
	//vv for the given n, we insert the nbr in the step-1 position, then we check
	//if they have been inserted or not
		int step = jS[n];
		for(int i = step - 1; i < static_cast<int>(later.size()); i += step){
			if (!inserted[i]){
				binaryInsert(now, later[i]);
				inserted[i] = true;
			}
		}
	}
	//If some nbr of the later STL remains, we make sure the insert it on now STL
	for (size_t i = 0; i < later.size(); ++i){
		if (!inserted[i])
			binaryInsert(now, later[i]);
	}
}

void PmergeMe::binaryInsert(std::vector<int> &lst, int num){
	int begin = 0;
	int end = lst.size() - 1;
	while (begin <= end){
		int mid = left + (right - left) / 2;
		if (lst[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	lst.insert(lst.begin + left, num);
}

void PmergeMe::pairSort(const std::vector<int> &lst){
	//we'll be sorting the vector STL
	if (lst.size() < 2) //the list must contain at least 2 values
		return ;
	int odd,
	if (lst.size() % 2 != 0){//we need to make pairs, so we save the last numbr in the odd variable
		odd = lst.back();
		lst.pop_back();
	}
	std::vector<std::pair<int, int>> pairs;//now we can make pairs until the list arrives to the end 
	for (size_t i = 0; i < lst.size(); i += 2){
		if (i + 1 < lst.size())
			pairs.push_back(std::make_pair<lst[i], lst[i + 1]>);
	}
	//std::cout << MAGENTA << pairs.size() << "\n";
	std::vector<int>now;
	std::vector<int>later;
	for (size_t i = 0; i < pairs.size(); i++){//we save the bigger number on the now vector, and the smallest on the later vector
		if (pairs[i].first < pairs[i].second){
			now.push_back(pair[i].second);
			later.push_back(pair[i].first);
		}
		else{
			now.push_back(pairs[i].first);
			later.push_back(pairs[i].second);
		}
	}
	pairSort(now);
	if (!later.empty() && now.size() < 2)
		binaryInsert(now, later[0]);//insert the first numb of the later vector into now vector
	insetLater(now, later);//we'll use Jacobsthal in here!!!
	if (odd != -1)
		binaryInsert(now, odd);
	lst = now;

}

void PmergeMe::pairSort(const std::deque<int> &lst){
	//we'll be sorting the deque STL
}
//}
