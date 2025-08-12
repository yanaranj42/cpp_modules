/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:05:01 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/12 14:02:44 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <list>
#include <iostream>


int main()
{
	{
		std::cout << BLUE << "- 0. Subject test - " << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << GREEN << "Last added element: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << YELLOW << "- Iterating the stack -" << RESET << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "\t" << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << BLUE << "- 0.1 Same test, but with lists - "<< std::endl;
		std::list<int> mylst;
		mylst.push_back(5);
		mylst.push_back(17);
    	std::cout << GREEN << "Last added element: " << mylst.back() << std::endl;
		mylst.pop_back();
		std::cout << "size: " << mylst.size() << std::endl;
		mylst.push_back(3);
		mylst.push_back(5);
		mylst.push_back(737);
		mylst.push_back(0);
		std::cout << YELLOW << "- Iterating the list -\n" << RESET;
		std::list<int>::iterator it = mylst.begin();
		std::list<int>::iterator ite = mylst.end();
		++it;
		--it;
		while (it != ite){
			std::cout << "\t" << *it << std::endl;
			++it;
		}
		std::list<int> l(mylst);
	}
	{
		std::cout << BLUE << "- 1. Testing different iterators with other data type -" << std::endl;
		MutantStack<char> new_stack;
		new_stack.push('y');
		new_stack.push('z');
		new_stack.push('j');
		std::cout << GREEN << "Last added element: '" << new_stack.top() << "'" << std::endl;
		new_stack.pop();
		std::cout << "New last element: '" << new_stack.top() << "'" << std::endl;
		new_stack.push('H');
		new_stack.push('E');
		new_stack.push('L');
		new_stack.push('L');
		new_stack.push('O');
		std::cout << YELLOW << "- Iterating the stack -\n" << RESET;
		MutantStack<char>::iterator it = new_stack.begin();
		MutantStack<char>::iterator ite = new_stack.end();
		++it;
		--it;
		while(it != ite)
		{
			std::cout << "\t" << *it << std::endl;
			it++;
		}
		
		std::cout << YELLOW << "- Reverse iterating the stack -\n" << RESET;
		MutantStack<char>::reverse_iterator rit = new_stack.rbegin();
		MutantStack<char>::reverse_iterator itre = new_stack.rend();
		++rit;
		--rit;
		while(rit != itre)
		{
			std::cout << "\t" << *rit << std::endl;
			rit++;
		}
		std::stack<char> s(new_stack);
	}
	return 0;
}