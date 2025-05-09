/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:03:34 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/09 15:57:04 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Action {DEBUG, INFO, WARNING, ERROR, UNK};

void	Harl::debug(void)
{
	std::cout << GRN"[DEBUG]" << std::endl;
	std::cout << reset"I love having extra bacon for my " << std::endl;
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}
void	Harl::info(void)
{
	std::cout << BLU"[INFO]" << std::endl;
	std::cout << reset"I cannot believe adding extra bacon costs more money." <<std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}
void	Harl::warning(void)
{
	std::cout << YEL"[WARNING]" << std::endl;
	std::cout << reset"I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}
void	Harl::error(void)
{
	std::cout << RED"[ERROR]" << std::endl;
	std::cout << reset"This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

Action	lvl_complain(const std::string &str)
{
	if (str == "DEBUG")
		return (DEBUG);
	if (str == "INFO")
		return (INFO);
	if (str == "WARNING")
		return (WARNING);
	if (str == "ERROR")
		return (ERROR);
		
	return (UNK);
}

void	Harl::complain(std::string level)
{
	int i;
	void (Harl::*ptr_complain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; 
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		
	switch (lvl_complain(level))
	{
		case DEBUG:
			(this->*ptr_complain[0])();
		case INFO:
			(this->*ptr_complain[1])();
		case WARNING:
			(this->*ptr_complain[2])();
		case ERROR:
			(this->*ptr_complain[3])();
		default:
			return ;
	}
	std::cout << "I only accept: ";
	std::cout << "DEBUG || INFO || WARNING || ERROR" << std::endl;
}