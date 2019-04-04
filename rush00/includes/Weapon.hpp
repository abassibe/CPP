/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:48:24 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/30 11:55:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type, int damage, float fireRate);;
		Weapon(Weapon const& copy);
		~Weapon();
		Weapon	&operator=(Weapon const& copy);
		int		use() const;

	protected:
		Weapon();
		std::string		_type;
		int				_damage;
		float			_firingRate;
};

#endif
