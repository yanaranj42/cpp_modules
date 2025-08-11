/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:29:51 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/08 15:39:22 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _n(0), _v1(0){}
Span::Span(unsigned int n) : _n(n), _v1(0){}
Span::Span(const Span &cp) : _n(cp._n), _v1(cp._v1){}

Span &Span::operator=(const Span &op){
	if (this != &op){
		_n = op._n;
		_v1 = op._v1;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(unsigned int num){
	if (_v1.size() >= _n){
		throw std::runtime_error("❌ The container reached his max size\n");
	}
	_v1.push_back(num);
}

int Span::shortestSpan(){
	if (_v1.size() <= 1)
		throw std::runtime_error("❌ Not enough numbers stored.\n");
	int min = INT_MAX;
	std::vector<int> sorted = _v1;
	std::sort(sorted.begin(), sorted.end());	
	for (unsigned int i = 0; i < sorted.size() - 1; i++){
		if (min > sorted[i + 1] - sorted[i])
			min = sorted[i + 1] - sorted[i];
	}
	return (min);
}

int Span::longestSpan(){
	if (_v1.size() <= 1)
		throw std::runtime_error("❌ Not enough numbers stored.\n");
	std::vector<int>::iterator minIt = std::min_element(_v1.begin(), _v1.end());
	std::vector<int>::iterator maxIt = std::max_element(_v1.begin(), _v1.end());
	return (*maxIt - *minIt);

}