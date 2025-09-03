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
	if (!isdigit(token.at(0))
		throw std::runtime_error("All input should be a digit");
	std::stringstream ss(token)
	long long int num = 0;
	ss >> num;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Value overflow");
	if (toke.size() > 10)
		throw std::runtime_error("Invalid number format");
	if (num > 0 && num <= INT_MAX){
		_vector.push_back(num);
		_deque.push_back(num);
	}
	else
		throw std::runtime_error("Something went wrong");
}

void PmergeMe::parse_input(int ac, char **av){
	if (ac < 2)
		throw std::runtime_error ("No arguments");
	if (ac == 2){
		std::stringstream ss(av[1]);
		std::string token;
		while (ss >> token)
			check_token(token);
	}
	else{
		for (int i = 0; i < ac; i++)
			check_token(av[i]);
	}
	//time to check duplicates values, maybe we can do it with a template, insted to duplicate ft for each container.
}

