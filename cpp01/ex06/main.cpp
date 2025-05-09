/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:27:05 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/08 18:49:39 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac != 2)
	{
		std::cout << "I need a level order like:" << std::endl;
		std::cout << "DEBUG || INFO || WARNING || ERROR" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}