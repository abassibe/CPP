/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:54:56 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/30 13:31:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type, int damage, float fireRate) : _type(type),
	_damage(damage), _firingRate(fireRate)
{
}

Weapon::Weapon(Weapon const& copy) : _type(copy._type), _damage(copy._damage),
	_firingRate(copy._firingRate)
{
}

Weapon::~Weapon()
{
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
