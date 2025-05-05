/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:17:20 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/05 13:33:47 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	We have to create a dinamyc horde. First we secure that we recieve a name as
	param. Then, create as many zombies as we want. Callinf *ZH: we allocate
	the N zombies and we give them the same name. We have an array, that we will
	announce with a for and delete when we are done
*/

Zombie* zombieHorde( int N, std::string name);

int main(int ac, char **av)
{
	int	N = 7;
	Zombie *horde;
	if (ac < 2)
		std::cout << "A name is needed 👀" << std::endl;
	else
	{
		horde = zombieHorde(N, av[1]);
		for (int i = 0; i < N; i++)
		{
			std::cout << "[" << i << "]";
			horde[i].announce();
		}
		delete[] horde;
	}
	return (0);
}