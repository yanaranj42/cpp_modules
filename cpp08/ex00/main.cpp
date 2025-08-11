/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:32:18 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/11 12:10:54 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <list>
#include <stack>

static int generate_random(){
	int random = 0;
	for (int i = 0; i < 30; i++)
		random = 0 + std::rand() % 15;
	return (random);
}

int main(){
	int random = 0;
	std::srand(std::time(0));
	std::cout << BLUE;
	try{
		std::vector<int> v1;
		for(int i = 0; i < 10; i++){
			random = generate_random();
			v1.push_back(random);
			std::cout << "[" << i << "]" << random << "\n";
		}
		int pos = easyfind(v1, 4);
		std::cout << GREEN << "\nNo 4 Found on: " << pos << " position" << std::endl;
	}
	catch(std::exception &ex){
		std::cerr << RED << "\nException found: " << ex.what() << std::endl;
	}
	std::cout << YELLOW;
	try{
		std::deque<int> dq;
		for (int i = 0; i < 20; i++){
			random = generate_random();
			dq.push_back(random);
			std::cout << "[" << i << "]" << random << "\n";
		}
		int pos = easyfind(dq, 8);
		std::cout << GREEN << "\nNo 8 Found on: " << pos << " position\n";
	}
	catch(std::exception &ex){
		std::cerr << RED << "\nExecption found: " << ex.what() << std::endl;
	}
	std::cout << RESET;
	try{
		std::list<int> lst;
		for(int i = 0; i < 10; i++){
			random = (generate_random() * 2);
			lst.push_back(random);
			std::cout << "[" << i << "]" << random << "\n";
		}
		int pos = easyfind(lst, 16);
		std::cout << GREEN << "\nNo 5 Found on: " << pos << " position" << std::endl;
	}
	catch(std::exception &ex){
		std::cerr << RED << "\nException found: " << ex.what() << std::endl;
	}
	return (0);
}