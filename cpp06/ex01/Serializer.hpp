/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:59:05 by yanaranj          #+#    #+#             */
/*   Updated: 2025/07/17 16:23:00 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>
#include <stdint.h>

typedef struct sdata
{
	int id;
	std::string _name;
} Data;


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &cp);
		Serializer &operator=(const Serializer &cp);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

std::ostream &operator>>(std::ostream &oss, const Data &data);

#endif