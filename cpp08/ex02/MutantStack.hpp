/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:53:25 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/12 14:03:07 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack &cp) : std::stack<T>(cp){}
		MutantStack &operator=(const MutantStack &op){
			if (this != &op){
				this->std::stack<T>::operator = (op);	
			}
			return (*this);
		}
		
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		const_iterator begin() const {return this->c.begin();}
		const_iterator end() const {return this->c.end();}
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
		const_reverse_iterator rbegin() const {return this->c.rbegin();}
		const_reverse_iterator rend() const {return this->c.rend();}

};

#endif