/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:28:53 by yanaranj          #+#    #+#             */
/*   Updated: 2025/06/20 18:52:34 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bob;
	Bureaucrat richard("Richard", 2);//valid grade
	
	//std::cout << richard << std::endl;
//grade too low
	try{
		richard.decrementGrade(149);
	}
	catch (const std::exception &ex){
		std::cout << richard.getName() << ": " << ex.what() << std::endl;
	}
//grade too high
	Bureaucrat pop("Jane", 12);
	try{
	//	std::cout << pop << std::endl;
		pop.incrementGrade(148);		
	}
	catch(const std::exception &ex){
		std::cout << pop.getName() << ": " << ex.what() << std::endl;
	}

	Bureaucrat cp(pop);
	std::cout << cp << std::endl;
}