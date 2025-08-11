/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:57:42 by yanaranj          #+#    #+#             */
/*   Updated: 2025/08/06 14:02:34 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RESET "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>

template <typename T>
int easyfind(const T& c, int occ){
	typename T::const_iterator it = std::find(c.begin(), c.end(), occ);
	if (it != c.end())
		return (std::distance(c.begin(), it));
	throw std::runtime_error("Value not found");
}
#endif