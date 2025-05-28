/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:17:39 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/27 15:08:22 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

# define END "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(const std::string type);
		Animal(const Animal &copy);
		virtual ~Animal(void);

		Animal &operator=(const Animal &op);
		
		virtual std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif