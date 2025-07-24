/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:50:04 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/23 12:30:14 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T> 
void swap (T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T min(const T &a, const T &b){
	return (b <= a ? b : a);
}
template <typename T>
const T max(const T &a, const T &b){
	return (b >= a ? b : a);
}

#endif