/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:24:15 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/28 13:03:50 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <sstream>
#include <string>

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(const std::string name);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &op);
		~Cat(void);
		
		void makeSound(void) const;
		void getIdeas(void) const;
};

//std::ostream &operator<<(std::ostream &oss, const Cat &cat);//if we want to do a request
#endif