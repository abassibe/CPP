/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:11:43 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 15:55:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const& copy) : AWeapon(copy)
{
	_name = copy._name;
	_apCost = copy._apCost;
	_damage = copy._damage;
}

PowerFist::~PowerFist()
{
}

PowerFist		&PowerFist::operator=(PowerFist const& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_apCost = copy._apCost;
		_damage = copy._damage;
	}
	return (*this);
}

void		PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
