/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:28:53 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/07 14:18:23 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



//🔩🤖✅❌

int main(void)
{
	std::srand(std::time(0));

	std::cout << BLUE << "------TEST 1------" << std::endl;//creation file
	try 
	{
		Bureaucrat				Bc1("Gardener", 50);
		ShrubberyCreationForm	S1("Garden");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << S1 << "\n" << std::endl;
		S1.beSigned(Bc1);
		std::cout << std::endl;
		Bc1.executeForm(S1);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << YELLOW<<  std::endl;
	}
	std::cout << YELLOW << "\n------TEST 2------" << std::endl;//Richard grade too low to sign
	try 
	{
		Bureaucrat				Bc1("Richard", 149);
		ShrubberyCreationForm	S1("Garden");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << S1 << "\n" << std::endl;
		S1.beSigned(Bc1);
		Bc1.executeForm(S1);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED;
		std::cerr << "Test 2. Caught an exception: " << e.what() << GREEN <<  std::endl;
	}
	std::cout << GREEN << "\n------TEST 3------" << std::endl;//form signed ok but fail robotomy
	try 
	{
		Bureaucrat	Bc1("Sarah Connor", 40);
		RobotomyRequestForm R1("Terminator");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << R1 << "\n" << std::endl;
		R1.beSigned(Bc1);
		Bc1.executeForm(R1);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << YELLOW <<  std::endl;
	}
	std::cout << YELLOW << "\n------TEST 3.1------" << std::endl;//
	try 
	{
		Bureaucrat Bc1("Will Smith", 45);
		RobotomyRequestForm R1("I robot");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << R1 << "\n" << std::endl;
		R1.beSigned(Bc1);
		Bc1.executeForm(R1);
	}
	catch(const std::exception &e)
	{
		std::cerr << BLUE;
		std::cerr << "Caught an exception: " << e.what() << RED <<  std::endl;
	}
	{
		std::cout << RED << "\n------TEST 4------" << std::endl;
		Bureaucrat Bc1("Mariano Rajoy", 20);
		PresidentialPardonForm P1("Mr. Smith");
		try{
			std::cout << Bc1 << "\n" << std::endl;
			std::cout << P1 << "\n" << std::endl;
			P1.beSigned(Bc1);
			Bc1.executeForm(P1);//problems executing the form
		}
		catch(const std::exception &e){
			std::cerr << BLUE << "Caught an exception: " << e.what() << RESET <<  std::endl;
		}
		std::cout << RED << "\n------TEST 4.1------" << std::endl;//double signed
		try{
			std::cout << Bc1 << "\n" << std::endl;
			std::cout << P1 << "\n" << std::endl;
			P1.beSigned(Bc1);
			Bc1.executeForm(P1);
		}
		catch(const std::exception &e){
			std::cerr << BLUE << "Caught an exception: " << e.what() << RED <<  std::endl;
		}
	}
	std::cout << BLUE << "\n------TEST 5------" << std::endl;
	try 
	{
		Bureaucrat Bc1("🐱 Beerus-sama", 1);
		PresidentialPardonForm P1("Nameless");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << P1 << "\n" << std::endl;
		P1.beSigned(Bc1);
		P1.execute(Bc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
}