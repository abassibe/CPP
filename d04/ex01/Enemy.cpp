/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:41:19 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 15:08:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
}

Enemy::Enemy(Enemy const& copy)
{
	_type = copy._type;
	_hp = copy._hp;
}

Enemy::Enemy(int hp, std::string const& type) : _type(type), _hp(hp)
{
}

Enemy::~Enemy()
{
}

Enemy	&Enemy::operator=(Enemy const& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		_hp = copy._hp;
	}
	return (*this);
}

std::string		Enemy::getType() const
{
	return (_type);
}

int				Enemy::getHP() const
{
	return (_hp);
}

void			Enemy::takeDamage(int amount)
{
	_hp -= amount;
	if (_hp < 0)
		_hp = 0;
}
