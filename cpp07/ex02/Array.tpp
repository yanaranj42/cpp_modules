/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:54:46 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/28 13:44:26 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* @brief
	- First we have the constructors, one for void Array and the second for an
	Array with 'n' _elements.
	- Destructor using delete[] 'cause we have an array.
	- For copy operator, we need to create a new array, and this one will have
	the copied elements in it.
	- For assignment operator,first we compare if the addresses matches, if not
	then we delete everything, then create a new array[_len]
	and assign each array position the op.elements and return the new array.
	- Finally we have the exception. In case there's some element out of range.
*/
template<typename T>
Array<T>::Array() : _element(NULL), _len(0){}

template<typename T>
Array<T>::Array(unsigned int n) : _element(new T[n]()) , _len(n){}

template<typename T>
Array<T>::~Array(){
	delete[] _element;
}
template<typename T>
Array<T>::Array(const Array &cp) : _element(new T[cp._len]),  _len(cp._len){
	for (unsigned int i = 0; i < _len; i++){
		_element[i] = cp._element[i];
	}
}
template<typename T>
Array<T> &Array<T>::operator=(const Array &op){
	if (this == op)
		return (*this);
	delete[] _element;
	_len = op._len;
	_element = new T[_len]();
	for (unsigned int i = 0; i < _len; i++)
		_element[i] = op._element[i];
	return (*this);
}

template<typename T>
const char* Array<T>::ArrBoundException::what() const throw(){
	return ("Index out of range\n");
}

/* @brief
	We have two versions of operators, just to have control over const and
	non-const objects.
	non-const:
	It returns the T&(reference) that allow us to modify an element of the array
	const:
	Returns the T&(reference to a const),that allow us to read the element but
	we cant modify it
	@param
		unsigned int idx: 
	
*/
template<typename T>
T& Array<T>::operator[](unsigned int idx){
	if (idx >= _len)
		throw ArrBoundException();
	return (_element[idx]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int idx) const{
	if (idx >= _len)
		throw ArrBoundException();
	return (_element[idx]);
}

template<typename T>
unsigned int Array<T>::size() const{
	return (_len);
}

/* @brief
	We also have an ostream operator, as a way to get the information of the
	object while we control the array to avoid any leaks
*/

template<typename T>
std::ostream &operator<<(std::ostream &oss, const Array<T> &array){
	T *tmp = new T[array.size()];
	for(unsigned int n = 0; n < array.size();n++)
		tmp[n] = array[n];
	oss << "Array:\n[";
	for(unsigned int idx = 0; idx < array.size(); idx++){
		oss << tmp[idx];
		if (idx != array.size() - 1)
			oss << ", ";
	}
	oss << "]\n";
	delete[] tmp;
	return (oss);
}
