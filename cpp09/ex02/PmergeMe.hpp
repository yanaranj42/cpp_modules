/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:36 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/04 16:54:22 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"

#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <ctime>
#include <sstream>
#include <exception>
#include <climits>


class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::vector<int> _OrgVector;
		std::deque<int> _deque;
		std::deque<int> _OrgDeque;

		//std::vector<int> jacobsthalGenerator(int i);

		void check_dups(const std::vector<int> &vector);
		void check_dups(const std::deque<int> &deque);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &op);

		std::vector<int> &getVector();
		std::vector<int> &getOrgVector();
		std::deque<int> &getDeque();
		std::deque<int> &getOrgDeque();

		void parse_input(int ac, char **av);
		void check_token(const std::string &token);
		void insertionSort(const std::vector<int> &lst);
		void insertionSort(const std::deque<int> &lst);
};


#endif
