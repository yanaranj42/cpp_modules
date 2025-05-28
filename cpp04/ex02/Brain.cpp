/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:45:07 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/28 16:14:52 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) : size(0) {
	std::cout << "> Brain Constructed" << std::endl;
}
Brain::Brain(const Brain &cp){
	for (int i = 0; i < 100; i++)
		_ideas[i] = cp._ideas[i];
	std::cout << GREEN"> copy Brain Constructed" << END << std::endl;
}
Brain &Brain::operator=(const Brain &op){
	if (this != &op){
		for (int i = 0; i < 100; i++)
			_ideas[i] = op._ideas[i];
	}
	std::cout << "> we are done assigning ideas" << std::endl;
	return (*this);
}
Brain::~Brain(){
	std::cout << ">Brain will die soon..." << std::endl;
}
void Brain::_createIdeas(std::string idea){
	if (size == 100)
		return ;
	_ideas[size++] = idea;
}
void Brain::printIdeas() const{
	for(int i = 0; i < 100; i++)
	{
		if (!_ideas[i].empty())
			std::cout << BLUE << "[" << i << "]\t" << _ideas[i] << END << std::endl;
	}
}