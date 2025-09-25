/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:38 by yanaranj          #+#    #+#             */
/*   Updated: 2025/09/23 16:30:54 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pg;

	if (ac > 1){
		try{
			pg.parse_input(ac, av);
			int limit = std::min(300, static_cast<int>(pg.getVector().size()));
			std::cout << "Before Input: ";
			for (int i = 0; i < limit; ++i)
				std::cout << pg.getVector()[i] << " ";
			std::cout << std::endl;

		/*
				 *-------------------------*
				|			VECTOR			|
				 *-------------------------*
		*/
			struct timeval vecStart, vecEnd;
			gettimeofday(&vecStart, NULL);
			pg.pairSort(pg.getVector());
			gettimeofday(&vecEnd, NULL);
			double vecTime = (vecEnd.tv_sec - vecStart.tv_sec ) * 1000000.0 + (vecEnd.tv_usec - vecStart.tv_usec);

		/*
				 *-------------------------*
				|			DEQUE			|
				 *-------------------------*
		*/
			struct timeval deqStart, deqEnd;
			gettimeofday(&deqStart, NULL);
			pg.pairSort(pg.getDeque());
			gettimeofday(&deqEnd, NULL);
			double deqTime = (deqEnd.tv_sec - deqStart.tv_sec) * 1000000.0 + (deqEnd.tv_usec - deqStart.tv_usec);

			std::cout  << BLUE << "After Vector: ";
			for (int i = 0; i < limit; ++i)
				std::cout << pg.getVector()[i] << " ";
			std::cout << std::endl;
			std::cout << MAGENTA <<  "After Deque: ";
			for (int i = 0; i < limit; ++i)
				std::cout << pg.getDeque()[i] << " ";
			std::cout << RESET << std::endl;
			
			/*PRINTING TIMES*/
			std::cout << BLUE << "\nTime to process a range of " << pg.getOrgVector().size() << " elements with std::vector: " \
			<< std::fixed << std::setprecision(3) << vecTime/1000 << " ms" << std::endl;
			std::cout << MAGENTA << "Time to process a range of " << pg.getOrgDeque().size() << " elements with std::deque: " \
			 << std::fixed << std::setprecision(3) << deqTime/1000 << " ms" << std::endl;
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
