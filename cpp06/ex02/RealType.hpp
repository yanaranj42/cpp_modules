/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:02:44 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/21 12:27:09 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_TYPE_H
# define REAL_TYPE_H

#include <iostream>
#include <string>
#include <cstdlib>

//subject sais no need canonical form
class Base{
	public:
		virtual ~Base();
};

class A : public Base{};

class B : public Base{};

class C : public Base{};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif