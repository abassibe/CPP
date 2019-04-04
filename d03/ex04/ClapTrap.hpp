/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:12:30 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 13:06:29 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& copy);
		~ClapTrap();
		ClapTrap	&operator=(ClapTrap const&copy);
		void		rangedAttack(std::string const& target) const;
		void		meleeAttack(std::string const& target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		printStatus() const;
		std::string	getName() const;

	protected:
		ClapTrap();
		unsigned int	_hitPoints;
		unsigned int	_maxHitPoints;
		unsigned int	_energyPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_level;
		std::string		_name;
		unsigned int	_meleeAttackDamage;
		unsigned int	_rangedAttackDamage;
		unsigned int	_armorDamageReduction;
};

#endif
