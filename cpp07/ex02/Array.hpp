/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:06:45 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/24 12:56:21 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
template <typename T> class Array
{
	private:
		T* _element;
		unsigned int _len;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &cp);
		Array &operator=(const Array &op);
		//methods

		T &operator[](unsigned int n);
		const T &operator[](unsigned int idx) const;
		
		unsigned int size() const;
		//exception
		class ArrBoundException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

template<typename T>
std::ostream &operator<<(std::ostream &oss, const Array<T> &array);

#endif