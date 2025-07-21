/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:18:54 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/17 16:21:47 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(const Serializer &cp){
	*this = cp;
}
Serializer &Serializer::operator=(const Serializer &op){
	(void)op;
	return (*this);
}
Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}

std::ostream &operator>>(std::ostream &oss, const Data &data){
	return (oss << "Original data:\n\tid: " << data.id << "\n\tname: " << data._name << std::endl);
}