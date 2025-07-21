/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:27:53 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/21 13:44:50 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"
#include <ctime>

# define RESET "\x1b[0m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

int main(void){
	std::srand(time(NULL));
	std::cout << YELLOW;
	{
		Base *base;
		base = generate();
		identify(base);
		delete base;
	}
	std::cout << BLUE;
	{
		Base *base;
		base = generate();
		Base &ref_base = *base;
		identify(ref_base);
		delete base;
	}
	return (0);
}