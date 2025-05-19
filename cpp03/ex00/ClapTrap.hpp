/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:03 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/15 16:43:17 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# define END "\x1b[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define YELLOW "\e[1;93m"

#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int _pHealth;
		int _pEnergy;
		int	_pDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap(void);
		
		ClapTrap &operator=(ClapTrap const &op);
		
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		/*getters*/
		const std::string& getName(void) const;
		const int &getHealth(void) const;
		const int &getEnergy(void)const;
		const int &getDamage(void) const;
		void setName(std::string const name);
		void setHealth(int &value);
		void setEnergy(int &value);
		void setDamage(int &value);
};

#endif