/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:03:34 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/08 16:25:32 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my " << std::endl;
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout <<  "I cannot believe adding extra bacon costs more money." <<std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*ptr_complain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; 
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
		{
			(this->*ptr_complain[i])();
			return ;
		}
	}
	std::cout << "I only accept: ";
	std::cout << "DEBUG || INFO || WARNING || ERROR" << std::endl;
}