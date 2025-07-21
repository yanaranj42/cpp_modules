/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:59:04 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/17 16:23:31 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//random = 42;//change value if we want to fail;
int main(void)
{
	Data employee;
	employee.id = 20;
	employee._name = "yanaranj";
	
	uintptr_t random = Serializer::serialize(&employee);
	Data *employee2 = Serializer::deserialize(random);
	
	if (&employee == employee2)
	{
		std::cout << "Both results matches\n";
		std::cout << "Original info: " << employee.id << ", " << employee._name << std::endl;
		std::cout << "New info: " << employee2->id << ", " << employee2->_name << std::endl;
	}
	else{
		std::cout << "Both results are different\n";
		std::cout << &employee << std::endl;
		std::cout << &employee2 << std::endl;
	}
	return (0);
}