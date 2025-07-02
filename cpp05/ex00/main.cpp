/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:28:53 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/01 15:16:22 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bob;
	Bureaucrat richard("Richard", 150);
	
	std::cout << richard << std::endl;
	try{
//grade too low = 150
		richard.decrementGrade();
	}
	catch (const std::exception &ex){
		std::cerr << richard.getName() << ": " << ex.what() << std::endl;
	}
//grade too high = 0
	Bureaucrat pop("Jane", 1);
	std::cout << pop << std::endl;
	try{
		pop.incrementGrade();
	}
	catch(const std::exception &ex){
		std::cerr << pop.getName() << ": " << ex.what() << std::endl;
	}
//copy class
	Bureaucrat cp(pop);
	std::cout << cp << std::endl;
	try{
		cp.incrementGrade();
	}
	catch(const std::exception &ex){
		std::cerr << cp.getName() << ": " << ex.what() << std::endl;
	}
//default class, no exceptions
	Bureaucrat anonim;
	//Bureaucrat anonim("", 80);
	std::cout << anonim << std::endl;
	try{
		anonim.incrementGrade();
	}
	catch(const std::exception &ex){
		std::cerr << anonim.getName() << ": " << ex.what() << std::endl;
	}
	std::cout << anonim << std::endl;
	try{
		anonim.decrementGrade();
	}
	catch(const std::exception &ex){
		std::cerr << anonim.getName() << ": " << ex.what() << '\n';
	}
	return (0);
}