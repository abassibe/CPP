/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:02:35 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 15:54:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const& copy) : AWeapon(copy)
{
	_name = copy._name;
	_apCost = copy._apCost;
	_damage = copy._damage;
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle		&PlasmaRifle::operator=(PlasmaRifle const& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_apCost = copy._apCost;
		_damage = copy._damage;
	}
	return (*this);
}

void		PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
