/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:44:33 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/28 16:12:11 by yanaranj         ###   ########.fr       */
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
		unsigned int size;
	public:
		Brain(void);
		Brain(const Brain &cp);
		Brain &operator=(const Brain &op);
		virtual ~Brain();
		
		void _createIdeas(std::string idea);
		void printIdeas() const;
};

#endif