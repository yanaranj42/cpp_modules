/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:59:38 by yanaranj          #+#    #+#             */
/*   Updated: 2025/06/03 11:37:11 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
# define END "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE "\033[34m"

/* We cannot use "virtual" in constructor 'cause when the obj constructor starts,
 * the derived object does not exists already.
 * > Virtual on destructor makes sure that we are cleaning up the methods of 
 * derived classes and avoiding leaks or crashes.
 */

class Test{
	protected:
		std::string _type;
		std::string _word;
	public:
		Test();
		Test(const std::string name);
		Test(const Test &copy);
		Test &operator=(const Test &op);
		virtual ~Test();

		std::string getType() const;
		virtual std::string getWord() const;
};

/*to print info*/
//std::ostream &operator<<(std::ostream &oss, const Cat &cat);
#endif
