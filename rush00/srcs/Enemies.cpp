/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemies.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:41:25 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:02:01 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "../includes/Enemies.hpp"

Enemies::Enemies()
{
	y = 50;
	x = 200;
}

Enemies::Enemies(std::string type, Weapon *weapon) : _type(type), _hp(1), _weapon(weapon)
{
}

Enemies::Enemies(Enemies const& copy) : _type(copy._type), _hp(copy._hp), _weapon(copy._weapon)
{
}

Enemies::~Enemies()
{
	delete (_weapon);
}

Enemies		&Enemies::operator=(Enemies const& copy)
{
	_type = copy._type;
	_hp = copy._hp;
	_weapon = new Weapon(*copy._weapon);
	return (*this);
}
