/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:02:01 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 15:13:01 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const& copy) : Enemy(copy)
{
	_type = copy._type;
	_hp = copy._hp;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant		&SuperMutant::operator=(SuperMutant const& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		_hp = copy._hp;
	}
	return (*this);
}

void			SuperMutant::takeDamage(int amount)
{
	if (amount > 3)
		_hp -= (amount - 3);
	if (_hp < 0)
		_hp = 0;
}
