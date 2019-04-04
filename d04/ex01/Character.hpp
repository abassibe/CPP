/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:17:12 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 15:42:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character
{
	public:
		Character(Character const& copy);
		Character(std::string const & name);
		~Character();
		Character	&operator=(Character const& copy);
		void		recoverAP();
		void		equip(AWeapon*);
		void		attack(Enemy*);
		std::string	getName() const;
		std::string	getWeaponName() const;
		int			getAP() const;

	private:
		Character();
		std::string		_name;
		AWeapon			*_weapon;
		int				_ap;
};

std::ostream	&operator<<(std::ostream &o, Character const& character);

#endif
