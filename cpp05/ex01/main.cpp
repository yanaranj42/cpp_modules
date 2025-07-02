/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:28:53 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/02 17:22:57 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

# define END "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"


int main()
{
	//Bureaucrat grade too low
	try{
		std::cout << BLUE << "------TEST 1------" << std::endl;
		Bureaucrat richard("Richard", 12);
		Form taxes("Taxes", 1, 4);
		std::cout << richard << std::endl;
		std::cout << taxes << std::endl;
		richard.signForm(taxes);
	}
	catch(std::exception &ex){
		std::cout << "An exception was found: " << ex.what() << std::endl;
	}
	//Invalid form sign/exec grade
	std::cout << YELLOW << "\n------TEST 2------" << std::endl;
	try{
		Form taxes("Taxes", 0, 4);
		std::cout << taxes << std::endl;
	}
	catch(std::exception &ex){
		std::cout << "An exception was found: " << ex.what() << std::endl;
	}
	//Bureaucrat can sign
	std::cout << RED << "\n------TEST 3------" << std::endl;
	Bureaucrat a;
	Form docs("docs", 81, 5);
	try{
		std::cout << a << std::endl;
		std::cout << docs << std::endl;
		a.signForm(docs);
	}
	catch(std::exception &ex){
		std::cout << "An exception was found: " << ex.what() << std::endl;
	}
	//double signed, an exception we don't have to control it
	std::cout << GREEN << "\n------TEST 4------" << std::endl;
	try{
		a.signForm(docs);
	}
	catch(std::exception &ex){
		std::cout << "An exception was found: " << ex.what() << std::endl;
	}
	return (0);
}