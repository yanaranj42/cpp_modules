/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:28:53 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/03 19:25:32 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"
//🔩🤖✅❌

int main(void)
{
	std::cout << "\nTEST Num 1.0" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Gardener", 50);
		ShrubberyCreationForm	S1("Garden");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << S1 << "\n" << std::endl;
		S1.beSigned(Bc1);
		std::cout << S1 << "\n" << std::endl;
		S1.execute(Bc1);
		Bc1.executeForm(S1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
	std::cout << "\nTEST Num 1.1" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Janitor", 149);
		ShrubberyCreationForm	S1("Garden");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << S1 << "\n" << std::endl;
		S1.beSigned(Bc1);
		std::cout << S1 << "\n" << std::endl;
		S1.execute(Bc1);
		Bc1.executeForm(S1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}

	std::cout << "\nTEST Num 2.0" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Sarah Connor", 40);
		std::cout << Bc1 << "\n" << std::endl;
		RobotomyRequestForm R1("Terminator");
		std::cout << R1 << "\n" << std::endl;
		R1.beSigned(Bc1);
		std::cout << R1 << "\n" << std::endl;
		R1.execute(Bc1);
		Bc1.executeForm(R1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
		std::cout << "\nTEST Num 2.1" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Torrente", 45);
		std::cout << Bc1 << "\n" << std::endl;
		RobotomyRequestForm R1("Trashinator");
		std::cout << R1 << "\n" << std::endl;
		R1.execute(Bc1);
		Bc1.executeForm(R1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
	std::cout << "\nTEST Num 3.0" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Mariano Rajoy", 66);
		std::cout << Bc1 << "\n" << std::endl;
		PresidentialPardonForm P1("Mr. Smith");
		std::cout << P1 << "\n" << std::endl;
		P1.execute(Bc1);
		Bc1.executeForm(P1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
		std::cout << "\nTEST Num 3.1" << std::endl;
	try 
	{
		Bureaucrat				Bc1("🐱 Beerus-sama", 1);
		std::cout << Bc1 << "\n" << std::endl;
		PresidentialPardonForm P1("Mr. Smith");
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