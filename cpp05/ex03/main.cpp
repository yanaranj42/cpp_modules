/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:28:53 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/07 17:56:56 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main(void)
{
	Bureaucrat cat("Kili", 1);
	Intern n1;
	AForm *random;

	std::srand(std::time(0));
	try{
		random = n1.makeForm("shrubbery creation", "Yaja");
		delete random;
		random = n1.makeForm("robotomy request", "Bender");
		delete random;
		random = n1.makeForm("presidential pardon", "Lincon");
		delete random;
		random = n1.makeForm("Feed me", "Yaja");
		delete random;
	}
	catch(std::exception &ex){
		std::cerr << RED << "Exception was found " << ex.what() << RESET << std::endl;
	}
	std::cout << BLUE << "\n----------------TEST 1--------------------" << std::endl;
	try{
		random = n1.makeForm("shrubbery creation", "Kili");
		random->beSigned(cat);
		cat.executeForm(*random);
		delete random;
	}
	catch(std::exception &ex){
		std::cout << "Exception found: " << ex.what() << std::endl;
	}
	std::cout << GREEN << "\n----------------TEST 2--------------------" << std::endl;
	try{
		random = n1.makeForm("presidential pardon", "Lincon");
		cat.signForm(*random);
		cat.executeForm(*random);
		delete random;
	}
	catch(std::exception &ex){
		std::cout << "Exception found: " << ex.what() << std::endl;
	}
	std::cout << YELLOW << "\n----------------TEST 3--------------------" << std::endl;
	try{
		random = n1.makeForm("Feed M", "Baymax");
		cat.signForm(*random);
		cat.executeForm(*random);
		delete random;
	}
	catch(std::exception &ex){
		std::cout << "Exception found: " << ex.what() << std::endl;
	}
	return (0);
}