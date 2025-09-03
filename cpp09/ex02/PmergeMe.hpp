#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <climits>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::vector<int> _OrgVector;
		std::deque<int> _deque;
		std::deque<int> _OrgDeque;

		std::vector<int> jacobsthalGenerator(int i);


	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &op);

		void parse_input(int ac, char **av);
		void check_token(const std::string &token);
};


#endif
