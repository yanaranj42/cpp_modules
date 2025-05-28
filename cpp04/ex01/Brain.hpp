/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:44:33 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/27 15:23:42 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "Animal.hpp"

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(const Brain &cp);
		Brain &operator=(const Brain &op);
		virtual ~Brain();//del an instancee of derived class(ptr)
		
		void _createIdeas(int idx, std::string idea);
		void printIdeas() const;
};

#endif