/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:50:18 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/11 13:28:10 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

#include <iostream>
#include <cstdlib>
#include <exception>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v1;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &cp);
		Span &operator=(const Span &op);
		~Span();

		template<typename Iterator>
		void addNumber(Iterator i1, Iterator i2);

		void addNumber(unsigned int num);
		int shortestSpan();
		int longestSpan();
};

template <typename Iterator>//add multiple nums in the vector with a single call(specific range)
void Span::addNumber(Iterator i1, Iterator i2){
	if (std::distance(i1, i2) + _v1.size() > _n)
		throw std::runtime_error("❌ No more space to add number available\n");
	_v1.insert(_v1.end(), i1, i2);
}


#endif