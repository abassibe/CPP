/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:32:07 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 14:01:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
	public:
		AWeapon(AWeapon const& copy);
		AWeapon(std::string const& name, int apCost, int damage);
		virtual ~AWeapon();
		AWeapon			&operator=(AWeapon const& copy);
		std::string		getName() const;
		int				getAPCost() const;
		int				getDamage() const;
		virtual void	attack() const = 0;

	protected:
		AWeapon();
		std::string		_name;
		int				_apCost;
		int				_damage;
};

#endif
