/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:54:46 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/24 13:24:18 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _element(NULL), _len(0){}

template<typename T>
Array<T>::Array(unsigned int n) : _element(new T[n]()) , _len(n){}

template<typename T>
Array<T>::~Array(){
	delete[] _elements;
}
//when we copy the data, first we need to create an array whit the cp len
template<typename T>
Array<T>::Array(const Array &cp) : _elements(new T[cp._len]),  _len(cp._len){
	for (size_t i = 0; i < _len; i++){
		_elements[i] = cp._elements[i];
	}
}
template<typename T>
Array<T> &Array<T>::operator=(const Array &op){
	if (*this == op)
		return (*this);
	delete[] _elements;//deleting old data
	_len = op._len;
	_elements = new T[_len];
	for (size_t i = 0; i < _len; i++){
		_elements[i] = op._elements[i];
	}
	return (*this);
}
//template<typename T>
//template<typename T>