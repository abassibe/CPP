/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <abassibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:54:56 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/30 21:20:32 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return;
}

Weapon::Weapon(std::string type, int damage, float fireRate) :
	_type(type),
	_damage(damage),
	_firingRate(fireRate)
{
}

Weapon::Weapon(Weapon const& copy) :
	_type(copy._type),
	_damage(copy._damage),
	_firingRate(copy._firingRate)
{
}

Weapon::~Weapon(void)
{
	return;
}

Weapon		&Weapon::operator=(Weapon const& copy)
{
	_type = copy._type;
	_damage = copy._damage;
	_firingRate = copy._firingRate;
	return (*this);
}

int			Weapon::use() const
{
	return (_damage);
}
