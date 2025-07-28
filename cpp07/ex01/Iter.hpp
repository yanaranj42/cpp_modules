/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:54:49 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/28 15:34:09 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cstring>

template <typename T>
void value(const T &s){
	std::cout << "content: " << s << std::endl;
}
template <typename T>
void iter(T *array, size_t len, void(*f)(const T &)){
	for (size_t i = 0; i < len; i++){
		f(array[i]);
	}
}
template <typename T>
void iter(T *array, size_t len, void(*f)(T &)){
	for (size_t i = 0; i < len; i++){
		f(array[i]);
	}
}
#endif