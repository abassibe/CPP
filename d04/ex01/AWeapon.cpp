/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:39:16 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 15:47:49 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(AWeapon const& copy)
{
	_name = copy._name;
	_apCost = copy._apCost;
	_damage = copy._damage;
}

AWeapon::AWeapon(std::string const& name, int apCost, int damage) : _name(name),
	_apCost(apCost), _damage(damage)
{
}

AWeapon::~AWeapon()
{
}

AWeapon		&AWeapon::operator=(AWeapon const& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_apCost = copy._apCost;
		_damage = copy._damage;
	}
	return (*this);
}

std::string		AWeapon::getName() const
{
	return (_name);
}

int				AWeapon::getAPCost() const
{
	return (_apCost);
}

int				AWeapon::getDamage() const
{
	return (_damage);
}
