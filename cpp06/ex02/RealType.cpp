/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:08:51 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/21 12:55:03 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"

Base::~Base(){}

Base *generate(void){
	int choice = std::rand() % 3;

	switch (choice)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	default:
		return NULL;
	}
}

void identify(Base* p){
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "p: points to 'A'\n";
	else if(b)
		std::cout << "p: points to 'B'\n";
	else if(c)
		std::cout << "p: points to 'C'\n";
	else
		std::cerr << "Something went wrong\n";
}

void identify(Base& p){
	try{
		(void)dynamic_cast<A &>(p);
		std::cout << "p: reference to A\n";
		return ;
	}
	catch(std::exception &ex){}
	try{
		(void)dynamic_cast<B &>(p);
		std::cout << "p: reference to B\n";
		return ;
	}
	catch(std::exception &ex){}
	try{
		(void)dynamic_cast<C &>(p);
		std::cout << "p: reference to C\n";
		return ;
	}
	catch(std::exception &ex){}
	return;
}
