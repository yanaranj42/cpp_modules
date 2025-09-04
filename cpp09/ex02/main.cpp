/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:38 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/04 16:59:46 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pg;

	if (ac > 1){
		try{
			struct timeval start, end;
			gettimeofday(&start, NULL);
			pg.parse_input(ac, av);
			gettimeofday(&end, NULL);
			//start time in order to get the final time of the STL used to be sorted
			double time = (end.tv_sec = start.tv_sec) + (end.tv_usec - start.tv_usec); 
			std::cout << "Before: ";
			int limit = std::min(20, static_cast<int>(pg.getVector().size()));
			for (int i = 0; i < limit; i++)
				std::cout << pg.getVector()[i] << " ";
			std::cout << std::endl;

			/* Vectors*/
			struct timeval vecStart, vecEnd;
			gettimeofday(&vecStart, NULL);
			pg.insertionSort(pg.getVector());//this is the one that can modify
			gettimeofday(&vecEnd, NULL);
			double vecTime = (vecStart.tv_sec - vecEnd.tv_sec) * 100000.0 + (vecStart.tv_usec - vecStart.tv_usec) + time/100000;
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
