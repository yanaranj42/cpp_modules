/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:36 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/03 17:40:14 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <climits>
#include <sstream>


class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::vector<int> _OrgVector;
		std::deque<int> _deque;
		std::deque<int> _OrgDeque;

		//std::vector<int> jacobsthalGenerator(int i);


	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &op);

		void parse_input(int ac, char **av);
		void check_token(const std::string &token);
};


#endif
