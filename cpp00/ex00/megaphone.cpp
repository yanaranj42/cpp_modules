/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:04:57 by yanaranj          #+#    #+#             */
/*   Updated: 2025/04/22 13:24:41 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	int	i = 1;
	int	j;
	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= 'a' && av[i][j] <= 'z') || (av[i][j] >= 'A' && av[i][j] <= 'Z'))
				std::cout << (char)std::toupper(av[i][j]);
			else
				std::cout << av[i][j];
			j++;
		}
		if (av[i] && av[i + 1])
			std::cout << ' ';
		i++;
	}
	std::cout << std::endl;
	return (0);
}
