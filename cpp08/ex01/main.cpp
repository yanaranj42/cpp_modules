/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:32:09 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/11 13:28:00 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <list>


static int generate_random(){
	int random = 0;
	random += std::rand() + 42 % 5;
	return (random);
}

//We can use this functions to see the original and sorted list
/* static void sort_vec(std::vector<int> original){
	std::vector<int> tmp = original;
	std::sort(tmp.begin(), tmp.end());
	std::cout << "\tOriginal\t|\tTemporal" << std::endl;
	for(unsigned long i = 0; i < tmp.size() - 1; i++){
		std::cout << "[" << i << "]\t";
		std::cout << original[i] << "\t\t";
		std::cout << tmp[i] << "\n";
	}
} */
/* static void sort_lst(std::list<int> original){
	std::list<int> tmp = original;
	tmp.sort();
	std::cout << "\tOriginal\t|\tTemporal" << std::endl;
	std::list<int>::iterator org1 = original.begin();
	std::list<int>::iterator temp1 = tmp.begin();
	int i = 0;
	while(org1 != original.end() && temp1 != tmp.end()){
		std::cout << "[" << i << "]\t";
		std::cout << *org1++ << "\t\t";
		std::cout << *temp1++ << "\n";
		i++;
	}
//	std::cout << "first: " << tmp.front() << "\n";
} */

int main()
{
	std::srand(time(NULL));
	std::cout << BLUE << "- 1. Testing single addNumber call -" << std::endl;
	{
		Span sp = Span(5);
		
		sp.addNumber(1);
		sp.addNumber(30);
		sp.addNumber(20);
		sp.addNumber(9);
		sp.addNumber(3);
		
		std::cout << RESET << "\t✅ Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "\t✅ Longest: " << sp.longestSpan() << std::endl;
		try{
			std::cout << BLUE << " -1.1 Adding extra number -\n";
			sp.addNumber(214748364);
			std::cout << RESET << "\t✅ Shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "\t✅ Longest: " << sp.longestSpan() << std::endl;

		}
		catch(std::exception &ex){
			std::cerr << RED << "\tError Found: " << ex.what();
		}
	}	
	std::cout << BLUE << "\n- 2. Testing multiple addNumber call with Vectors-" << std::endl;
	try{
		Span sp2 = Span(50);
		std::vector<int> vec(50);
		for (int i = 0; i < 50; i++){
			vec[i] = generate_random();
			//std::cout << "[" << i << "] " << vec[i] << RESET <<  std::endl;
		}
		//sort_vec(vec);//if we want to see the stl sorted
		sp2.addNumber(vec.begin(), vec.end());
		std::cout << RESET << "\t✅ Shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "\t✅ Longest: " << sp2.longestSpan() << std::endl;
	}
	catch(std::exception &ex){
		std::cerr << RED << "\tError Found: " << ex.what() << RESET << std::endl;
	}
	{
		std::cout << BLUE << "\n- 3. Testing multiple addNumber call with lists -" << std::endl;
		Span sp3 = Span(80);
		std::list<int> lst;
		try{ 
			for (int i = 0; i < 79; i++){
				lst.push_back(generate_random());
				//std::cout << "[" << i << "] " <<  lst.back() << "\n";
			}
			sp3.addNumber(lst.begin(), lst.end());
			std::cout << RESET << "\t✅ Shortest: " << sp3.shortestSpan() << std::endl;
			std::cout << "\t✅ Longest: " << sp3.longestSpan() << std::endl;
		}
		catch(std::exception &ex){
			std::cerr << RED << "Error Found: " << ex.what() << RESET << std::endl;
		}
		std::cout << BLUE << "\n- 3.1 Adding a new value with single call -" << std::endl;
		try{
			sp3.addNumber(546);
			std::cout << RESET << "\t✅ Shortest: " << sp3.shortestSpan() << std::endl;
			std::cout << "\t✅ Longest: " << sp3.longestSpan() << std::endl;
		}
		catch(std::exception &ex){
			std::cerr << RED << "\tError Found: " << ex.what() << std::endl;
		}
		std::cout << BLUE << "\n- 3.2 Adding a new range of values with multiple call -" << std::endl;
		try{
			for (int i = 0; i < 10; i++){
				lst.push_back(generate_random());
				//std::cout << "[" << i << "] " <<  lst.back() << "\n";
			}
			sp3.addNumber(lst.begin(), lst.end());
			std::cout << RESET << "\t✅ Shortest: " << sp3.shortestSpan() << std::endl;
			std::cout << "\t✅ Longest: " << sp3.longestSpan() << std::endl;
		}
		catch(std::exception &ex){
			std::cerr << RED << "\tError Found: " << ex.what() << std::endl;
		}
	}
	{
		std::cout << BLUE << "- 4 Adding 10000 numbers into a list -" << std::endl;
		Span sp4 = Span(10000);
		std::list<int> big;
		try{
			for (int i = 0; i < 10000; i++){
				big.push_back(generate_random());
				//std::cout << "[" << i << "] " << big.back() << "\n";
			}
			sp4.addNumber(big.begin(), big.end());
			std::cout << RESET << "\t✅ Shortest: " << sp4.shortestSpan() << std::endl;
			std::cout << "\t✅ Longest: " << sp4.longestSpan() << std::endl;
		}
		catch(std::exception &ex){
			std::cerr << RED << "\tError Found: " << ex.what() << std::endl;
		}
		try{
			std::cout << BLUE << "- 4.1 Adding one more into the list -" << std::endl;
			sp4.addNumber(1955);
		}
		catch(std::exception &ex){
			std::cerr << RED << "\tError Found: " << ex.what() << std::endl;
		}
	}
	return 0;
}