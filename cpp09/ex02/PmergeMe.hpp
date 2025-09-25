/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:36 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/10 15:30:53 by yanaranj         ###   ########.fr       */
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
#include <iomanip>


class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::vector<int> _OrgVector;
		std::deque<int> _deque;
		std::deque<int> _OrgDeque;

		std::vector<int> jacobsthalGenerator(int i);

		void check_dups(const std::vector<int> &vector);
		void check_dups(const std::deque<int> &deque);
		void binaryInsert(std::vector<int> &lst, int num);
		void binaryInsert(std::deque<int> &lst, int num);
		void insertLater(std::vector<int> &now, std::vector<int> &later);
		void insertLater(std::deque<int> &now, std::deque<int> &later);

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
		void pairSort(std::vector<int> &lst);
		void pairSort(std::deque<int> &lst);
};


#endif
