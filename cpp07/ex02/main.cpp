/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:50:56 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/28 13:45:05 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 42

/* const nums is an existing array, but as long is const, we cannot modify the
	elements, thats why is set to zero.
*/
int main(void)
{
	Array<int> table(MAX_VAL);
	const Array<int> nums(MAX_VAL);
	
    srand(time(NULL));
	std::cout << YELLOW << nums << std::endl;
	for (int i = 0; i < MAX_VAL; i++){
		const int value = rand();
		table[i] = value;
		//nums[i] = number;//must be non const;
	}
	//Have the same address, so they have the same values.
	{
		Array<int> tmp = table;
		Array<int> test(tmp);
	}
	try{
		std::cout << BLUE << "Original "<< table << std::endl << RESET;
		table[5]  = 25;
		std::cout << YELLOW << "Modified " << table << std::endl << RESET;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	try{
		std::cout << "Access to 45 table position...\n";
		table[45] = 23;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
    return 0;
}