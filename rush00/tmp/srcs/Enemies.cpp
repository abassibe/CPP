/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemies.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <abassibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:41:25 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 23:21:29 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemies.hpp"
#include "Square.hpp"
#include "Vector.hpp"
#include "unistd.h"

Vector<Enemies> 	Enemies::enemies;

Enemies::Enemies(void)
{
	return;
}

Enemies::Enemies(Square *sq, std::string type, clock_t t) :
    _sq(sq),
	_type(type),
	_hp(1),
	_shape("#"),
	_t(t)
{
	return;
}

Enemies::Enemies(Square *sq, std::string type, Weapon *weapon) :
    _sq(sq),
	_type(type),
	_hp(1),
	_weapon(weapon),
	_shape("#")
{
	return;
}

Enemies::Enemies(Enemies const& copy) :
	_type(copy._type),
	_hp(copy._hp),
	_weapon(copy._weapon),
	_shape("#")
{
	return;
}

Enemies::~Enemies()
{
	delete (_weapon);
}

Enemies			&Enemies::operator=(Enemies const& copy)
{
	_type = copy._type;
	_hp = copy._hp;
	_weapon = new Weapon(*copy._weapon);
	return (*this);
}

const char	              *Enemies::getShape() const
{
	return (_shape);
}

Square			*Enemies::getSq(void) const
{
	return (_sq);
}

void             Enemies::move(Win body)
{
	if (clock() - _t > 20000)
	{
		body.drawAbsolute(getSq(), " ");
		_sq->setX(_sq->getX() - 1);
		body.drawAbsolute(getSq(), getShape());
		_t = clock();
	}
}


void 			Enemies::drawEnemies(Win &body)
{
	for (size_t i = 0; i < Enemies::enemies.getSize(); i++)
		Enemies::enemies[i]->move(body);
}
