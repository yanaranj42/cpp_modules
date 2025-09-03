/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:38 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/03 17:44:21 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pg;

	if (ac > 1){
		try{
			pg.parse_input(ac, av);
		}
		catch (std::exception &ex){
			std::cout << RED << "Exception: " << ex.what() << "\n";
			return 0;
		}
	}
	else
		std::cout << "Please introduce values\n";
	return (0);
}
