/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:58:33 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/06 12:49:32 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string init = "HI THIS IS BRAIN";
	std::string *stringPTR = &init;
	std::string &stringREF = init;

	std::cout << "String address:\t\t" << &init << std::endl;
	std::cout << "Pointer address:\t" << stringPTR << std::endl;
	std::cout << "Reference address:\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "String value:\t\t" << init << std::endl;
	std::cout << "Pointer value:\t\t" << *stringPTR << std::endl;
	std::cout << "Reference value:\t" << stringREF << std::endl;
	return (0);
}